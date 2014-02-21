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
#ifndef SK_COMM_H
#define SK_COMM_H

#include <csu/base/util/circ_buffer/circ_buffer.h>
#include <csu/base/comm/comm.h>

//#include <boost/thread/xtime.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/thread.hpp>

#include <skstream/skstream.h>


namespace csu {
namespace base {
namespace comm {
namespace imps {

///some constants
const int WAIT_FOR_HOOKING = 1;

///______________________________________________________________///

/// ///////////////////
/// LISTENER INTERFACE
/// ///////////////////

class SkCommListener
{
public:
    ///new incomming connection
    virtual void clientConnected(tcp_socket_stream*) = 0;

    ///client disconnected
    virtual void clientDisconnected(tcp_socket_stream*) = 0;

    /*
   ///error notification
   virtual void errorNotification(const std::string&) = 0;

   ///new received message notification
   virtual void newReceivedMessage(std::string) = 0;
    */
};

///______________________________________________________________///

/// ///////////////////
/// SERVER AND CLIENT BASE
/// ///////////////////

class SkBase
{
public:
    SkBase(const std::string& ip, int port, SkCommListener* listener)
        : ip_(ip), port_(port), listener_(listener)
    {}

    ~SkBase(){}

    ///
    /// disconnects the client or the server
    ///
    virtual void disconnect() = 0;

protected:
    std::string ip_;
    int port_;
    SkCommListener* listener_;
};

///______________________________________________________________///

/// ///////////////////
/// SERVER BEHAVIOR
/// ///////////////////

class SkServer : public SkBase
{
public:
    SkServer(const std::string& ip, int port, SkCommListener* listener);
    virtual ~SkServer();

    ///
    /// launches the server
    ///
    void launchServer();

    ///
    /// disconnects the server
    ///
    virtual void disconnect();

    ///
    /// thread listening for the incoming clients
    ///
    bool listenForClients(int port);

    ///
    /// boost thread operator
    ///
    void operator()();

private:
    boost::shared_ptr<boost::thread> thrd_;
    boost::ptr_list<tcp_socket_stream> socketList_;
};

///______________________________________________________________///

/// ///////////////////
/// CLIENT BEHAVIOR
/// ///////////////////

class SkClient : public SkBase
{
public:
    SkClient(const std::string& ip, int port, SkCommListener* listener);
    ~SkClient();

    ///
    /// launches the client
    ///
    void launchClient();

    ///
    /// connects to the server
    ///
    bool connectToServer(int port, std::string& ip);

    ///
    /// disconnects the client
    ///
    virtual void disconnect();

private:
    boost::shared_ptr<tcp_socket_stream> toServer_socket_;
};

///______________________________________________________________///

/// ///////////////////
/// TCP COMM (SERVER AND CLIENT) BEHAVIOR
/// ///////////////////
class SkComm : public SkCommListener, public Comm
{
    boost::thread* thrd_;

public:
    SkComm(bool isServer,
           std::string ip,
           int port,
           CommListener* listener);

    virtual ~SkComm();

    ///
    /// disconnects the server/client to the other
    /// side
    ///
    virtual void disconnect();

    ///
    /// writes a message in the socket
    /// (implements the Comm virtual method)
    ///
    virtual bool writeMessage(const std::string& message);

    ///
    /// launches the socket reader
    ///
    void startListeningSocket();

    ///
    /// boost thread operator
    ///
    void operator()();

    ///
    /// thread listening incoming messages
    ///
    void listenSocket(tcp_socket_stream* socket);

    ///
    /// stops the socket reading
    ///
    void stopListeningSocket();

    /// //////////////
    /// listener implementation
    /// //////////////

    ///new incomming connection
    virtual void clientConnected(tcp_socket_stream*);

    ///client disconnected
    virtual void clientDisconnected(tcp_socket_stream*);

    /*
   ///error notification
   virtual void errorNotification(const std::string&);

   ///new received message notification
   virtual void newReceivedMessage(std::string);
    */

private:
    tcp_socket_stream* socket_;
    SkServer* server_;
    SkClient* client_;

    csu::base::util::circ_buffer::circ_buffer buffer_;
    std::list<std::string> msgQueue_;
};

}//imps
}//comm
}//lib
}//csu



#endif // SK_COMM_H
