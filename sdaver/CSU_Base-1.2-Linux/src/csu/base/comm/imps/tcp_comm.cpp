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

#include "tcp_comm.h"
#include <csu/base/conf/log/log_config.h>

#include <boost/lexical_cast.hpp>

namespace csu {
namespace base {
namespace comm {
namespace imps{


    /// TCP SERVER ///___________________________________________________________________///

    TcpServer::TcpServer(const std::string& ip, int port, TcpCommListener* listener)
            : TcpBase::TcpBase(ip, port, listener)
    {
        _log::comm << "(TcpServer::TcpServer) " << std::endl;
        assert(listener);
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
        _log::comm << "(TcpServer::launchServer) Starting server..." << std::endl;
        //start server
        thrd_.reset(new boost::thread(boost::ref (*this)));
    }

    ///
    /// boost thread operator
    ///
    void TcpServer::operator()()
    {
        _log::comm << "(TcpServer::operator()) " << std::endl;
        listenForClients(port_);
    }

    ///
    /// thread listening for the incoming clients
    ///
    bool TcpServer::listenForClients(int port)
    {
        try
        {
            boost::asio::io_service io_service;

            tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));

            for (;;)
            {
                _log::comm << "(TcpServer::listenForClients) Waiting for new incomming clients..." << std::endl;
                ///wait for clients
                tcp::socket* s = new tcp::socket(io_service);
                assert(s);
                acceptor.accept(*s);
                //sleep(1);

                ///check if the socket is ok
                //TODO

                ///if everything is ok...
                ///notify the listerner
                assert(listener_);
                listener_->clientConnected(s);
                ///add the socket to the pointer list
                socketList_.push_back(s);

                _log::comm <<  "(TcpServer::listenForClients) New client connected. Notified." << std::endl;
            }
        }
        catch (std::exception& e)
        {
            _log::error <<  e.what() << std::endl;
            assert(0);
        }

        return 0;
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


    /// TCP CLIENT ///___________________________________________________________________///

    TcpClient::TcpClient(const std::string& ip,
                         int port, TcpCommListener* listener)
    : TcpBase(ip, port, listener)
    {
        _log::comm << "(TcpClient::TcpClient) " << std::endl;
    }

    TcpClient::~TcpClient()
    {
    }

    ///
    /// launches the client
    ///
    void TcpClient::launchClient()
    {
        _log::comm << "(TcpClient::launchClient) Trying to connect to server..." << std::endl;
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
            _log::comm << "(TcpClient::connectToServer) Trying to connect to " << ip << ":" << port << std::endl;

            // FIXME
            // Do the following:
            // - if ip is an ip address, use it directly
            // - if not, use resolver

            ///endpoint data
            boost::asio::ip::address addr =
            boost::asio::ip::address::from_string (ip);
            boost::asio::ip::basic_endpoint<tcp> endpoint(addr, port);

            //resolv the host name
            boost::asio::io_service io_service;
            /*tcp::resolver resolver(io_service);
            tcp::resolver::query query(tcp::v4(), ip,
                                       boost::lexical_cast<std::string>(port));
            tcp::resolver::iterator iterator = resolver.resolve(query);
            boost::asio::ip::tcp::endpoint endpoint = *iterator;*/
            //std::cout << iterator->endpoint() << std::endl;
            //std::cout << iterator->host_name() << std::endl;
            //std::cout << iterator->service_name() << std::endl;

            _log::comm << "(TcpClient::connectToServer) Creating socket." << std::endl;
            ///socket
            toServer_socket_.reset(new tcp::socket(io_service));

            _log::comm << "(TcpClient::connectToServer) Connecting to the server..." << std::endl;
            ///connect to the client
            boost::system::error_code error =
                    boost::asio::error::host_not_found;
            toServer_socket_->connect(endpoint, error);
            if (error)
            {
                throw boost::system::system_error(error);
            }
            _log::comm << "(TcpClient::connectToServer) Client successfully connected to " << ip << ":" << port << std::endl;

            ///notify the connection
            _log::comm << "(TcpClient::connectToServer) Notifying listener." << std::endl;
            listener_->clientConnected(toServer_socket_.get());

            return true;
        }
        catch (std::exception& e)
        {
            _log::error <<  "(TcpClient::connectToServer) ERROR: " << e.what() << std::endl;
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
        _log::comm << "(TcpComm::TcpComm) Comm constructor called." << std::endl;
        _log::comm << "(TcpComm::TcpComm) Constructor." << std::endl;

        /// initialize variables
        msgQueue_.clear();

        /// start server or client behavior
        if (isServer_)
        {
            _log::comm << "(TcpComm::TcpComm) Starting Server." << std::endl;
            server_ = new TcpServer(ip, port, this);
            server_->launchServer();
            client_ = NULL;
            _log::comm << "(TcpComm::TcpComm) Created new message server on port " << port << std::endl;
        }
        else
        {
            _log::comm << "(TcpComm::TcpComm) Starting Client." << std::endl;
            client_ = new TcpClient(ip, port, this);
            client_->launchClient();
            server_ = NULL;
            _log::comm << "(TcpComm::TcpComm) Created new client on port " << port << std::endl;
        }
    }

    TcpComm::~TcpComm()
    {
        _log::comm << "(TcpComm::~TcpComm)" << std::endl;
        if (thrd_.get())
        {
            // TODO: Threads must be set to terminate somehow
            thrd_->join();
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
        _log::comm << "(TcpComm::writeMessage)" << std::endl;

        /// if client is connected, write the message
        if (clientConnected_)
        {
            _log::comm << "(TcpComm::writeMessage) Client connected." << std::endl;
            //_log::comm << "(TcpComm::writeMessage) --" << message << "--" << std::endl;
            assert(socket_);
            boost::system::error_code error;
            boost::asio::write(*socket_,
                               boost::asio::buffer(
                                       message.c_str(),
                                       1 + message.size()), // string+'\0'
                               boost::asio::transfer_all(),
                               error);
            // TODO check for error
            _log::comm << "(TcpComm::writeMessage) Message written." << std::endl;
        }
        /// if not, store the message in a message queue
        else
        {
            _log::comm << "(TcpComm::writeMessage) Client disconnected. Storing message." << std::endl;
            msgQueue_.push_back(message);
        }

        return true;
    }

    ///
    /// launches the socket reader
    ///
    void TcpComm::startListeningSocket()
    {
        _log::comm << "(TcpComm::startListeningSocket)" << std::endl;
        //launch socket reader
        assert(socket_);
        _log::comm << "(TcpComm::startListeningSocket) Creating thread..." << std::endl;
        thrd_.reset(new boost::thread(boost::ref(*this)));

        _log::comm << "(TcpComm::startListeningSocket) SocketListener launched..." << std::endl;

    }

    ///
    /// boost thread operator
    ///
    void TcpComm::operator()()
    {
        _log::comm << "(TcpComm::operator) Launching socket listener..." << std::endl;
        listenSocket(socket_);

        //notify here that the client is disconnected
        clientDisconnected(socket_);
    }

    ///
    /// thread listening incoming messages
    ///
    void TcpComm::listenSocket(tcp::socket* socket)
    {
        assert(socket);
        _log::comm << "(TcpComm::listenSocket) socket = " << socket << std::endl;

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
                _log::comm << "(TcpComm::listenSocket) Buffer acquired." << std::endl;

                //read from the socket
                assert(socket);
                assert(current_buffer);
                boost::system::error_code error;
                size_t len =
                        socket->read_some(
                                boost::asio::buffer(current_buffer, BUFFER_SIZE), error);
                _log::comm << "(TcpComm::listenSocket) Socket read (" << len << ")" << std::endl;

                // Advance the buffer by len.
                buffer_.add (len);

                ///if the connection is closed by the server
                if (error == boost::asio::error::eof)
                {
                    _log::error <<  "(SocketListener::listenSocket) Connection closed cleanly by peer." << std::endl;
                    //notify here that the client is disconnected
                    clientDisconnected(socket_);
                    return;
                    assert(0);
                }
                ///some other error...
                else if (error)
                {

                    _log::error << "(TcpComm::listenSocket) ERROR: Error while reading. Throwing exception."<< std::endl;
                    throw boost::system::system_error(error);
                }

                ///handle received data
                _log::comm << "(TcpComm::listenSocket) Handling received data." << std::endl;

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
                    _log::comm << "(TcpComm::listenSocket) One message received:" << std::endl;
                    _log::comm <<  "(TcpComm::listenSocket)  - size = " << last_pos - cur_string << std::endl;
                    _log::comm <<  "(TcpComm::listenSocket) --" << cur_string << "--" << std::endl;

                    //notifying message to Comm
                    _log::comm <<  "(TcpComm::listenSocket) a." << std::endl;
                    std::string message(cur_string);
                    //_log::comm <<  "(TcpComm::listenSocket) --" << message << "--" << std::endl;
                    //_log::comm <<  "(TcpComm::listenSocket) b." << std::endl;
                    _log::comm <<  "(TcpComm::listenSocket) Emitting message using Comm." << std::endl;
                    Comm::newReceivedMessage(message);
                    _log::comm <<  "(TcpComm::listenSocket) Message emitted." << std::endl;

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
                _log::comm << "(TcpComm::listenSocket) End of iteration." << std::endl;
            }
            //notify here that the client is disconnected
            clientDisconnected(socket_);
        }
        catch (std::exception& e)
        {
            _log::error << "(TcpComm::listenSocket) ERROR: " << e.what() << std::endl;
            assert(0);
        }
    }

    /// //////////////
    /// Tcp CS listener implementation
    /// //////////////
    ///new incomming connection
    void TcpComm::clientConnected(tcp::socket* s)
    {
        _log::comm << "(TcpComm::clientConnected)" << std::endl;
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

        _log::comm << "(TcpComm::clientConnected) New client connected." << std::endl;
    }

    ///client disconnected
    void TcpComm::clientDisconnected(tcp::socket* s)
    {
        _log::comm << "(TcpComm::clientDisconnected) " << std::endl;
        //reset the socket reference
        if (s == socket_) socket_ = NULL;
        //top listening
        //TODO
        //notify the Comm
        Comm::clientDisconnected(/*s*/);
        _log::comm << "(TcpComm::clientDisconnected) Client disconnected." << std::endl;
    }

    /*
///error notification
void TcpComm::errorNotification(const std::string& s)
{
_log::error << "(TcpComm::errorNotification) " << s << std::endl;
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
