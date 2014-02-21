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
#ifndef QT_TCP_COMM_H
#define QT_TCP_COMM_H

#include <csu/base/debug/debug.h>
#include <csu/base/util/circ_buffer/circ_buffer.h>
#include <csu/base/comm/comm.h>

//#include <boost/thread/xtime.hpp>
//#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/thread.hpp>


//#include <boost/asio.hpp>
//using boost::asio::ip::tcp;

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

            class TcpCommListener
            {
            public:
               ///new incomming connection
               virtual void clientConnected(tcp::socket*) = 0;

               ///client disconnected
               virtual void clientDisconnected(tcp::socket*) = 0;

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

            class TcpBase
            {
            public:
               TcpBase(const std::string& ip, int port, TcpCommListener* listener)
                     : ip_(ip), port_(port), listener_(listener)
               {}

               ~TcpBase(){}

               ///
               /// disconnects the client or the server
               ///
               virtual void disconnect() = 0;

            protected:
               std::string ip_;
               int port_;
               TcpCommListener* listener_;
            };

            ///______________________________________________________________///

            /// ///////////////////
            /// SERVER BEHAVIOR
            /// ///////////////////

            class TcpServer : public TcpBase
            {
            public:
               TcpServer(const std::string& ip, int port, TcpCommListener* listener);
               virtual ~TcpServer();

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
               bool listenForClients(int port, TcpCommListener* l);

               ///
               /// boost thread operator
               ///
               void operator()();

            private:
               boost::shared_ptr<boost::thread> thrd_;
               boost::ptr_list<tcp::socket> socketList_;
            };

            ///______________________________________________________________///

            /// ///////////////////
            /// CLIENT BEHAVIOR
            /// ///////////////////

            class TcpClient : public TcpBase
            {
            public:
               TcpClient(const std::string& ip, int port, TcpCommListener* listener);
               ~TcpClient();

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
               boost::shared_ptr<tcp::socket> toServer_socket_;
            };

            ///______________________________________________________________///

            /// ///////////////////
            /// TCP COMM (SERVER AND CLIENT) BEHAVIOR
            /// ///////////////////
            class TcpComm : public TcpCommListener, public Comm
            {
               boost::thread* thrd_;

            public:
               TcpComm(bool isServer,
                       std::string ip,
                       int port,
                       CommListener* listener);

               virtual ~TcpComm();

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
               void listenSocket(tcp::socket* socket);

               /// //////////////
               /// listener implementation
               /// //////////////

               ///new incomming connection
               virtual void clientConnected(tcp::socket*);

               ///client disconnected
               virtual void clientDisconnected(tcp::socket*);

               /*
               ///error notification
               virtual void errorNotification(const std::string&);

               ///new received message notification
               virtual void newReceivedMessage(std::string);
               */

            private:
               tcp::socket* socket_;
               TcpServer* server_;
               TcpClient* client_;

               csu::base::util::circ_buffer buffer_;
               std::list<std::string> msgQueue_;
            };

         }//imps
      }//comm
   }//lib
}//csu



#endif // QT_COMM_H
