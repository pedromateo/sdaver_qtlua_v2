// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
 *   This program is free software; you can redistribute it and/or
 *   modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation; either version 3.0 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *   02111-1307 USA
 *
 *   This file is part of the OHTu-Open Usability Evaluation Framework,
 *   http://sourceforge.net/projects/ohtu/
 *
 */

#include <csu/base/comm/comm.h>

using namespace csu::base::debug;

namespace csu {
   namespace base {
      namespace comm {
         namespace imps{


            /// TCP SERVER ///___________________________________________________________________///

            TcpServer::TcpServer(const std::string& ip, int port, TcpCommListener* listener)
                  : TcpBase::TcpBase(ip, port, listener)
            {
               DEBUG(D_COMM,"(TcpServer::TcpServer) ");
            }

            TcpServer::~TcpServer()
            {
               if (thrd_)
               {
                  // TODO: Threads must be set to terminate somehow
                  thrd_->join();
               }
            }

            ///
            /// launches the server
            ///
            void TcpServer::launchServer()
            {
               DEBUG(D_COMM,"(TcpServer::launchServer) Starting server...");
               //start server
               thrd_.reset(new boost::thread(boost::ref (*this)));
            }

            ///
            /// disconnects the server
            ///
            void TcpServer::disconnect()
            {
               //disconnect all sockets
               boost::ptr_list<tcp::socket>::iterator it;
               it = socketList_.begin();
               while (it != socketList_.end())
               {
                  //close the socket
                  it->close();
                  //notify the listener
                  listener_->clientDisconnected(&(*it));
                  //go with the next socket
                  it++;
               }
            }

            ///
            /// boost thread operator
            ///
            void TcpServer::operator()()
            {
               DEBUG(D_COMM,"(TcpServer::operator()) ");
               listenForClients(port_,listener_);
            }

            ///
            /// thread listening for the incoming clients
            ///
            bool TcpServer::listenForClients(int port,
                                             TcpCommListener* listener)
            {
               try
               {
                  boost::asio::io_service io_service;

                  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));

                  for (;;)
                  {
                     DEBUG(D_COMM,"(TcpServer::listenForClients) Waiting "
                           "for new incomming clients...");
                     ///wait for clients
                     tcp::socket* s = new tcp::socket(io_service);
                     acceptor.accept(*s);
                     //sleep(1);

                     ///check if the socket is ok
                     //TODO

                     ///if everything is ok...
                     ///notify the listerner
                     listener->clientConnected(s);
                     ///add the socket to the pointer list
                     socketList_.push_back(s);

                     DEBUG(D_COMM, "(TcpServer::listenForClients) "
                           "New client connected. Notified.");
                  }
               }
               catch (std::exception& e)
               {
                  DEBUG(D_ERROR, e.what());
                  assert(0);
               }

               return 0;
            }


            /// TCP CLIENT ///___________________________________________________________________///

            TcpClient::TcpClient(const std::string& ip,
                                 int port, TcpCommListener* listener)
            : TcpBase(ip, port, listener)
            {
               DEBUG(D_COMM,"(TcpClient::TcpClient) ");
            }

            TcpClient::~TcpClient()
            {
            }

            ///
            /// launches the client
            ///
            void TcpClient::launchClient()
            {
               DEBUG(D_COMM,"(TcpClient::launchClient) Trying to connect to server...");
               ///init connection
               connectToServer(port_,ip_);
            }

            ///
            /// connects to the server
            ///
            bool TcpClient::connectToServer(int port, std::string& ip)
            {
               try
               {
                  DEBUG(D_COMM,"(TcpClient::connectToServer) Trying "
                        "to connect to " << ip << ":" << port);

                  ///endpoint data
                  //boost::asio::ip::address addr =
                  //boost::asio::ip::address::from_string (ip);
                  //boost::asio::ip::basic_endpoint<tcp> endpoint(addr, port);

                  //resolv the host name
                  boost::asio::io_service io_service;
                  tcp::resolver resolver(io_service);
                  tcp::resolver::query query(tcp::v4(), ip, boost::lexical_cast<std::string>(port));
                  tcp::resolver::iterator iterator = resolver.resolve(query);
                  boost::asio::ip::tcp::endpoint endpoint = *iterator;
                  //std::cout << iterator->endpoint() << std::endl;
                  //std::cout << iterator->host_name() << std::endl;
                  //std::cout << iterator->service_name() << std::endl;

                  DEBUG(D_COMM,"(TcpClient::connectToServer) Creating socket.");
                  ///socket
                  toServer_socket_.reset(new tcp::socket(io_service));

                  DEBUG(D_COMM,"(TcpClient::connectToServer) Connecting to the server...");
                  ///connect to the client
                  boost::system::error_code error =
                        boost::asio::error::host_not_found;
                  toServer_socket_->connect(endpoint, error);
                  if (error)
                  {
                     throw boost::system::system_error(error);
                  }
                  DEBUG(D_COMM,"(TcpClient::connectToServer) Client successfully "
                        "connected to " << ip << ":" << port);

                  ///notify the connection
                  DEBUG(D_COMM,"(TcpClient::connectToServer) Notifying listener.");
                  listener_->clientConnected(toServer_socket_.get());

                  return true;
               }
               catch (std::exception& e)
               {
                  DEBUG(D_ERROR, "(TcpClient::connectToServer) ERROR: " << e.what());
                  assert(0);
               }
            }

            ///
            /// disconnects the client
            ///
            void TcpClient::disconnect()
            {
               //disconnect the socket
               toServer_socket_->close();
               //notify the listener
               listener_->clientDisconnected(toServer_socket_.get());
            }

            /// TCP COMM ///_____________________________________________///


            TcpComm::TcpComm(bool isServer,
                             std::string ip,
                             int port,
                             CommListener* listener)
            : csu::base::comm::Comm(isServer, ip, port, listener)
            {
               /// Call the Comm constructor
               DEBUG(D_COMM,"(TcpComm::TcpComm) Comm constructor called.");
               DEBUG(D_COMM,"(TcpComm::TcpComm) Constructor.");
               thrd_ = 0;

               /// initialize variables
               msgQueue_.clear();

               /// start server or client behavior
               if (isServer_)
               {
                  DEBUG(D_COMM,"(TcpComm::TcpComm) Starting Server.");
                  server_ = new TcpServer(ip, port, this);
                  server_->launchServer();
                  client_ = NULL;
                  DEBUG(D_COMM,"(TcpComm::TcpComm) Created new message server on port " << port);
               }
               else
               {
                  DEBUG(D_COMM,"(TcpComm::TcpComm) Starting Client.");
                  client_ = new TcpClient(ip, port, this);
                  client_->launchClient();
                  server_ = NULL;
                  DEBUG(D_COMM,"(TcpComm::TcpComm) Created new client on port " << port);
               }
            }

            TcpComm::~TcpComm()
            {
               DEBUG(D_COMM,"(TcpComm::~TcpComm)");
               if (thrd_)
               {
                  // TODO: Threads must be set to terminate somehow
                  thrd_->join();
                  delete thrd_;
               }
            }

            ///
            /// disconnects the server/client to the other
            /// side
            ///
            void TcpComm::disconnect()
            {
               if (isServer_)
               {
                  assert(server_);
                  server_->disconnect();
               }
               else
               {
                  assert(client_);
                  client_->disconnect();
               }
            }


            ///
            /// writes a message in the socket
            ///
            bool TcpComm::writeMessage(const std::string& message)
            {
               /// if client is connected, write the message
               if (clientConnected_)
               {
                  //DEBUG(D_COMM,"(TcpComm::writeMessage) --" << message << "--");
                  boost::system::error_code error;
                  boost::asio::write(*socket_,
                                     boost::asio::buffer(
                                           message.c_str(),
                                           1 + message.size()), // string+'\0'
                                     boost::asio::transfer_all(),
                                     error);
                  // TODO check for error
                  DEBUG(D_COMM,"(TcpComm::writeMessage) Message written.");
               }
               /// if not, store the message in a message queue
               else
               {
                  msgQueue_.push_back(message);
               }

               return true;
            }

            ///
            /// launches the socket reader
            ///
            void TcpComm::startListeningSocket()
            {
               DEBUG(D_COMM,"(TcpComm::startListeningSocket)");
               //launch socket reader
               assert(socket_);
               DEBUG(D_COMM,"(TcpComm::startListeningSocket) Creating thread...");
               thrd_ = new boost::thread(boost::ref(*this));

               DEBUG(D_COMM,"(TcpComm::startListeningSocket) SocketListener launched...");

            }

            ///
            /// boost thread operator
            ///
            void TcpComm::operator()()
            {
               DEBUG(D_COMM,"(TcpComm::operator) Launching socket listener...");
               listenSocket(socket_);

               //notify here that the client is disconnected
               clientDisconnected(socket_);
            }

            ///
            /// thread listening incoming messages
            ///
            void TcpComm::listenSocket(tcp::socket* socket)
            {
               DEBUG(D_COMM,"(TcpComm::listenSocket) socket = " << socket);

               const int BUFFER_SIZE = 1024;

               try
               {
                  //sleep while the hooking is completed
                  boost::xtime xt;
                  //boost::xtime_get( &xt, boost::TIME_UTC );
                  //xt.sec += WAIT_FOR_HOOKING;
                  //boost::thread::sleep(xt);

                  for (;;)
                  {
                     //sleep a little
                     boost::xtime_get( &xt, boost::TIME_UTC );
                     xt.nsec += 10000000; // 10 msec
                     boost::thread::sleep(xt);

                     //get a buffer
                     char* current_buffer =
                           buffer_.buffer_ensure (BUFFER_SIZE);
                     DEBUG(D_COMM,"(TcpComm::listenSocket) Buffer acquired.");

                     //read from the socket
                     assert(socket);
                     assert(current_buffer);
                     boost::system::error_code error;
                     size_t len =
                           socket->read_some(
                                 boost::asio::buffer(current_buffer, BUFFER_SIZE), error);
                     DEBUG(D_COMM,"(TcpComm::listenSocket) Socket read ("
                           << len << ")");

                     // Advance the buffer by len.
                     buffer_.add (len);

                     ///if the connection is closed by the server
                     if (error == boost::asio::error::eof)
                     {
                        DEBUG(D_ERROR, "(SocketListener::listenSocket) "
                              "Connection closed cleanly by peer.");
                        return;
                        assert(0);
                     }
                     ///some other error...
                     else if (error)
                     {
                        throw boost::system::system_error(error);
                     }

                     ///handle received data
                     DEBUG(D_COMM,"(TcpComm::listenSocket) Handling received data.");

                     ///get strings from the buffer
                     // the string starts in the buffer.
                     char* cur_string = buffer_.pos();
                     // find the end of the string.
                     char* last_pos = std::find (cur_string,
                                                 cur_string + buffer_.size(),
                                                 '\0');

                     // empty string? or search reached the end of the buffer?
                     while  ((last_pos - cur_string != 0)
                        && (last_pos != cur_string + buffer_.size()))
                        {
                        DEBUG(D_COMM,"(TcpComm::listenSocket) One message received:");
                        DEBUG(D_COMM, "(TcpComm::listenSocket)  - size = "
                              << last_pos - cur_string);
                        DEBUG(D_COMM, "(TcpComm::listenSocket) --" << cur_string << "--");

                        //notifying message to Comm
                        DEBUG(D_COMM, "(TcpComm::listenSocket) a.");
                        std::string message(cur_string);
                        //DEBUG(D_COMM, "(TcpComm::listenSocket) --" << message << "--");
                        //DEBUG(D_COMM, "(TcpComm::listenSocket) b.");
                        DEBUG(D_COMM, "(TcpComm::listenSocket) Emitting message using Comm.");
                        Comm::newReceivedMessage(message);
                        DEBUG(D_COMM, "(TcpComm::listenSocket) Message emitted.");

                        // Advance the buffer with the processed string. Remove
                        // also the final '\0' by adding 1.
                        buffer_.read (last_pos - cur_string + 1);

                        //reading the next message (if it exists)
                        cur_string = buffer_.pos();
                        // find the end of the string.
                        last_pos = std::find (cur_string,
                                              cur_string + buffer_.size(),
                                              '\0');
                     }

                     //std::cout.write(buf.data(), len);
                     DEBUG(D_COMM,"(TcpComm::listenSocket) End of iteration.");
                  }
               }
               catch (std::exception& e)
               {
                  DEBUG(D_ERROR,"(TcpComm::listenSocket) ERROR: " << e.what());
                  assert(0);
               }
            }

            /// //////////////
            /// Tcp CS listener implementation
            /// //////////////
            ///new incomming connection
            void TcpComm::clientConnected(tcp::socket* s)
            {
               DEBUG(D_COMM,"(TcpComm::clientConnected)");
               /// store a copy of the socket
               socket_ = s;
               /// start reading from the socket
               startListeningSocket();
               /// notify the Comm
               Comm::clientConnected(/*s*/);

               /// send all the messages stored in the queue
               while (msgQueue_.size() > 0)
               {
                  writeMessage(msgQueue_.front());
                  msgQueue_.pop_front();
               }
               assert(msgQueue_.size() == 0);

               DEBUG(D_COMM,"(TcpComm::clientConnected) New client connected.");
            }

            ///client disconnected
            void TcpComm::clientDisconnected(tcp::socket* s)
            {
               DEBUG(D_COMM,"(TcpComm::clientDisconnected) ");
               //reset the socket reference
               if (s == socket_) socket_ = NULL;
               //top listening
               //TODO
               //notify the Comm
               Comm::clientDisconnected(/*s*/);
               DEBUG(D_COMM,"(TcpComm::clientDisconnected) Client disconnected.");
            }

            /*
///error notification
void TcpComm::errorNotification(const std::string& s)
{
DEBUG(D_ERROR,"(TcpComm::errorNotification) " << s);
errorNotification(s);
}

///new received message notification
void TcpComm::newReceivedMessage(std::string s)
{
newReceivedMessage(s);
}
*/



         }//imps
      }//comm
   }//lib
}//csu
