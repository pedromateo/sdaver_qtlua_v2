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

#ifndef COMM_H
#define COMM_H


#include <iostream>

///
/// debug
///

///


namespace csu {
   namespace base {
      namespace comm {

         /// //////////////////////
         /// CommMANAGER OBJECT
         /// //////////////////////

         class CommListener
         {
         public:
            //new Received Test Item notification
            virtual void newMessage_CLI ( const std::string& ) = 0;
            //error notification
            virtual void errorNotification_CLI ( const std::string& ) = 0;
            ///client connected or new incomming connection
            virtual void clientConnected_CLI() = 0;
            ///client disconnected
            virtual void clientDisconnected_CLI() = 0;
         };

         class Comm
         {
         public:
            ///
            /// constructors
            ///
            Comm(bool, std::string, int, CommListener*);
            virtual ~Comm();

         public:
            /// //////////////////////////////////
            /// services for adapting-classes
            /// //////////////////////////////////

            ///new incomming connection
            void clientConnected(/*tcp::socket**/);
            ///client disconnected
            void clientDisconnected(/*tcp::socket**/);
            ///error notification
            void errorNotification(const std::string&);
            ///new received message notification
            void newReceivedMessage(std::string);

         public:
            /// //////////////////////////////////
            /// services for clients
            /// //////////////////////////////////

            void sendMessage ( const std::string& );
            bool connectionStatus();

            /// //////////////////////////////////
            /// services and methods to be implemented
            /// by adapting classes
            /// //////////////////////////////////
         public:
            virtual void disconnect() = 0;

         protected:
            virtual bool writeMessage ( const std::string& ) = 0;


         protected:
            bool isServer_;
            bool clientConnected_;

         protected:
            //listener
            CommListener* cli_listener_;
         };

      }//comm
   }//base
}//csu



#endif // COMM_H
