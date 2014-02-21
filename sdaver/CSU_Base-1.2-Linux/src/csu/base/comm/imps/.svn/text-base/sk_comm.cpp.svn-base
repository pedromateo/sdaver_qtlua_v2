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

#include <csu/base/comm/imps/sk_comm.h>
#include <csu/base/conf/log/log_config.h>
#include <cstdio>
#include <skstream/skserver.h>

namespace csu {
namespace base {
namespace comm {
namespace imps{


/// TCP SERVER ///___________________________________________________________________///

SkServer::SkServer(const std::string& ip, int port, SkCommListener* listener)
    : SkBase::SkBase(ip, port, listener)
{
    _log::comm << "(SkServer::SkServer)" << std::endl;
}

SkServer::~SkServer()
{
    if (thrd_)
    {
        // TODO: Threads must be set to terminate somehow
        //thrd_->join();
    }
}

///
/// launches the server
///
void SkServer::launchServer()
{
    _log::comm << "(SkServer::launchServer) Starting server..." << std::endl;
    //start server
    thrd_.reset(new boost::thread(boost::ref (*this)));
}

///
/// boost thread operator
///
void SkServer::operator()()
{
    _log::comm << "(SkServer::operator()) " << std::endl;
    listenForClients(port_);
}

///
/// thread listening for the incoming clients
///
bool SkServer::listenForClients(int port)
{
    try
    {
        tcp_socket_server acceptor;

        //open acceptor
        const unsigned int W_PORT = port;
        if (!acceptor.open(W_PORT))
        {
            _log::comm << "(SkServer::listenForClients) The socket "
                "has not been properly opened." << std::endl;
            assert(0);
        }
        else
        {
            //set SO_REUSEADDR socket option
            int iOptval = 1;
            if(::setsockopt(acceptor.getSocket(),
                            SOL_SOCKET,
                            SO_REUSEADDR,
                            /*(void *)*/ &iOptval,
                            sizeof(iOptval)) < 0)
            {
                // Error -> call ::WSAGetLastError()
                ::perror("setsockopt");
                assert(0);
            }
        }

        _log::comm << "(SkServer::listenForClients) Waiting "
              "for new incomming clients on port "
              << port << "." << std::endl;

        int client;
        while (client = acceptor.accept())
        {
            tcp_socket_stream* client_s = new tcp_socket_stream();
            client_s->setSocket(client);

            _log::comm <<  "(SkServer::listenForClients) "
                "New client Accepted -> " << client <<std::endl;

            ///notify the listerner (Comm)
            listener_->clientConnected(client_s);
            ///add the socket to the pointer list
            socketList_.push_back(client_s);

            _log::comm <<  "(SkServer::listenForClients) "
                  "New client connected. Notified." << std::endl;
        }

        std::cout << "end?" << std::endl;
        acceptor.close();
    }
    catch (std::exception& e)
    {
        _log::comm << e.what() << std::endl;
        assert(0);
    }

    return 0;
}

///
/// disconnects the server
///
void SkServer::disconnect()
{
    //disconnect all sockets
    boost::ptr_list<tcp_socket_stream>::iterator it;
    it = socketList_.begin();
    while (it != socketList_.end())
    {
        tcp_socket_stream* csocket = &(*it);
        //notify the listener (Comm)
        listener_->clientDisconnected(csocket);

        //disconnect the socket
        if (csocket && csocket->is_open())
        {
            csocket->close();
        }

        //go with the next socket
        it++;
    }

    //clear list
    socketList_.clear();

    //TODO stop the listening thread here?
    //TODO close the acceptor socket here?
}

/// TCP CLIENT ///___________________________________________________________________///

SkClient::SkClient(const std::string& ip,
                   int port, SkCommListener* listener)
    : SkBase(ip, port, listener)
{
    _log::comm << "(SkClient::SkClient) " << std::endl;
}

SkClient::~SkClient()
{
}

///
/// launches the client
///
void SkClient::launchClient()
{
    _log::comm << "(SkClient::launchClient) Trying to connect to server..." << std::endl;
    ///init connection
    connectToServer(port_,ip_);
}

///
/// connects to the server
///
bool SkClient::connectToServer(int port, std::string& ip)
{
    try
    {
        _log::comm << "(SkClient::connectToServer) Trying "
            "to connect to " << ip << ":" << port << std::endl;

        toServer_socket_.reset(new tcp_socket_stream());


        toServer_socket_->open(ip, port, false/*nonblock*/);
        if(!toServer_socket_->is_open())
        {
            _log::comm << "(SkClient::connectToServer) ERROR: "
                       << toServer_socket_->is_open() << std::endl;
            assert(0);
        }
        else
        {
            _log::comm << "(SkClient::connectToServer) Client successfully "
                "connected to " << ip << ":" << port << std::endl;
        }

        ///notify the connection to the listener (Comm)
        _log::comm << "(SkClient::connectToServer) Notifying listener." << std::endl;
        listener_->clientConnected(toServer_socket_.get());

        return true;
    }
    catch (std::exception& e)
    {
        _log::comm << "(SkClient::connectToServer) ERROR: "
                   << e.what() << std::endl;
        assert(0);
    }
}

///
/// disconnects the client
///
void SkClient::disconnect()
{
    _log::comm << "(SkClient::disconnect)" << std::endl;
    //disconnect the socket
    if (toServer_socket_.get() && toServer_socket_->is_open())
    {
        toServer_socket_->close();
    }
    //notify the listener
    listener_->clientDisconnected(toServer_socket_.get());
    _log::comm << "(SkClient::disconnect) Done" << std::endl;
}

/// ////////////////////////////////////////////////////////////
/// TCP COMM ///_____________________________________________///
/// ////////////////////////////////////////////////////////////


SkComm::SkComm(bool isServer,
               std::string ip,
               int port,
               CommListener* listener)
    : csu::base::comm::Comm(isServer, ip, port, listener)
{
    /// Call the Comm constructor
    _log::comm << "(SkComm::SkComm) Comm constructor called." << std::endl;
    _log::comm << "(SkComm::SkComm) Constructor." << std::endl;
    thrd_ = 0;

    /// initialize variables
    msgQueue_.clear();

    /// start server or client behavior
    if (isServer_)
    {
        _log::comm << "(SkComm::SkComm) Starting Server." << std::endl;
        server_ = new SkServer(ip, port, this);
        server_->launchServer();
        client_ = NULL;
        _log::comm << "(SkComm::SkComm) Created new message server on port "
                   << port << std::endl;
    }
    else
    {
        _log::comm << "(SkComm::SkComm) Starting Client." << std::endl;
        client_ = new SkClient(ip, port, this);
        client_->launchClient();
        server_ = NULL;
        _log::comm << "(SkComm::SkComm) Created new client on port "
                   << port << std::endl;
    }
}

SkComm::~SkComm()
{
    _log::comm << "(SkComm::~SkComm)" << std::endl;
    if (thrd_)
    {
        // TODO: Threads must be set to terminate somehow
        //thrd_->join(); it blocks when exiting
        delete thrd_;
    }
}

///
/// disconnects the server/client to the other
/// side
///
void SkComm::disconnect()
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
bool SkComm::writeMessage(const std::string& message)
{
    /// if client is connected, write the message
    if (clientConnected_)
    {
        try
        {
            _log::comm << "(SkComm::writeMessage)" << std::endl;
            //FIXME quit this comment
            //_log::comm << "(SkComm::writeMessage) --" << message << "--" << std::endl;
            assert(socket_);
            *socket_ << message << '\0' << std::flush;
        }
        catch (std::exception& e)
        {
            _log::comm << e.what() << std::endl;
            assert(0);
        }

        _log::comm << "(SkComm::writeMessage) Message written." << std::endl;
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
void SkComm::startListeningSocket()
{
    _log::comm << "(SkComm::startListeningSocket) Creating thread..." << std::endl;
    //launch socket reader
    assert(socket_);
    thrd_ = new boost::thread(boost::ref(*this));

    _log::comm << "(SkComm::startListeningSocket) SocketListener launched..." << std::endl;
}

///
/// boost thread operator
///
void SkComm::operator()()
{
    _log::comm << "(SkComm::operator) Launching socket listener..." << std::endl;
    listenSocket(socket_);
}

///
/// thread listening incoming messages
///
void SkComm::listenSocket(tcp_socket_stream* socket)
{
    _log::comm << "(SkComm::listenSocket) socket = " << socket << std::endl;

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
            _log::comm << "(SkComm::listenSocket) Buffer acquired." << std::endl;

            //read from the socket
            assert(socket);
            assert(current_buffer);
            size_t len;

            try
            {
                // Read till \0, at most BUFFER_SIZE chars. Ignores
                // the '\0'
                socket->getline(current_buffer, BUFFER_SIZE, '\0');
                len = socket->gcount();

                // FIXME revisar esta decisión
                // If no data received -> link error
                if (len == 0)
                    throw "(SkComm::listenSocket) No data received. Link disconnected.";

                // Advance the buffer by len.
                buffer_.add (len);
            }
            catch (char const* msg)
            {
                _log::comm << msg << std::endl;

                //disconnect
                clientDisconnected(socket_);
                //disconnect the socket
                if (socket_ && socket_->is_open())
                {
                    socket_->close();
                }
                return;

                //assert(0);
            }
            catch (std::exception& e)
            {
                _log::comm << e.what() << std::endl;

                //disconnect
                clientDisconnected(socket_);
                //disconnect the socket
                if (socket_ && socket_->is_open())
                {
                    socket_->close();
                }
                return;

                //assert(0);
            }

            ///handle received data
            _log::comm << "(SkComm::listenSocket) Handling received data." << std::endl;

            // A message is read if it contains a '\0'
            // *within* its data. That is, the first '\0'
            // found must be in a position <= len - 1

            ///get strings from the buffer
            // the string starts in the buffer.
            char* cur_string = buffer_.pos();
            std::string message(cur_string);

            Comm::newReceivedMessage(message);
            _log::comm <<  "(SkComm::listenSocket) Message emitted." << std::endl;

            // Advance processed bytes.
            buffer_.read (message.size() + 1);
            _log::comm << "(SkComm::listenSocket) End of iteration." << std::endl;
        }

        //notify here that the client is disconnected
        clientDisconnected(socket_);
        //disconnect the socket
        if (socket_ && socket_->is_open())
        {
            socket_->close();
        }
    }
    catch (std::exception& e)
    {
        _log::comm << "(SkComm::listenSocket) ERROR: " << e.what() << std::endl;
        assert(0);
    }
}

///
/// stops the socket reading
///
void SkComm::stopListeningSocket()
{
    _log::comm << "(SkComm::stopListeningSocket)" << std::endl;
    _log::comm << "(SkComm::stopListeningSocket) Deleting thread." << std::endl;
    if (thrd_) delete thrd_;
    thrd_ = NULL;
    _log::comm << "(SkComm::stopListeningSocket) Done" << std::endl;
}

/// //////////////
/// Tcp CS listener implementation
/// //////////////
///new incomming connection
void SkComm::clientConnected(tcp_socket_stream* s)
{
    _log::comm << "(SkComm::clientConnected)" << std::endl;
    /// store a copy of the socket
    socket_ = s;
    /// start reading from the socket
    startListeningSocket();
    /// notify the Comm
    Comm::clientConnected();

    /// send all the messages stored in the queue
    while (msgQueue_.size() > 0)
    {
        writeMessage(msgQueue_.front());
        msgQueue_.pop_front();
    }
    assert(msgQueue_.size() == 0);

    _log::comm << "(SkComm::clientConnected) New client connected." << std::endl;
}

///client disconnected
void SkComm::clientDisconnected(tcp_socket_stream* s)
{
    if (!clientConnected_)
    {
        _log::comm <<
              "(SkComm::clientDisconnected) Client already disconnected." << std::endl;
        return;
    }

    _log::comm << "(SkComm::clientDisconnected) " << std::endl;
    //stop listening
    stopListeningSocket();
    //reset the own socket reference
    socket_ = NULL;

    //notify the Comm
    _log::comm << "(SkComm::clientDisconnected) Notifying Comm." << std::endl;
    Comm::clientDisconnected();

    _log::comm << "(SkComm::clientDisconnected) Client disconnected." << std::endl;
}

/*
///error notification
void SkComm::errorNotification(const std::string& s)
{
DEBUG(D_ERROR,"(SkComm::errorNotification) " << s);
errorNotification(s);
}

///new received message notification
void SkComm::newReceivedMessage(std::string s)
{
newReceivedMessage(s);
}
*/



}//imps
}//comm
}//lib
}//csu
