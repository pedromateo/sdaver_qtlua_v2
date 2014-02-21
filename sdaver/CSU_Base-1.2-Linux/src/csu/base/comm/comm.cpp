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
#include <iostream>
#include <cassert>

#include <csu/base/conf/log/log_config.h>

namespace csu {
   namespace base {
      namespace comm {

         /// //////////////////////
         /// COMM MANAGER OBJECT
         /// //////////////////////

         Comm::Comm(bool isServer, std::string ip, int port, CommListener* listener )
         {
            cli_listener_ = listener;
            isServer_ = isServer;
            clientConnected_ = false;

            _log::comm << "(Comm::Comm) Variables initialized." << std::endl;
         }

         Comm::~Comm()
         {
            _log::comm << "(Comm::~Comm)" << std::endl;
         }

         ///
         /// interface
         ///

         ///new incomming connection
         void Comm::clientConnected()
         {
            if (clientConnected_)
            {
               _log::error << "(Comm::clientConnected) Client already connected." << std::endl;
               return;
            }

            _log::comm << "(Comm::clientConnected)" << std::endl;
            clientConnected_ = true;

            _log::comm << "(Comm::clientConnected) Notifying listener." << std::endl;
            assert(cli_listener_);
            cli_listener_->clientConnected_CLI();
         }

         ///client disconnected
         void Comm::clientDisconnected()
         {
            if (!clientConnected_)
            {
               _log::error << "(Comm::clientDisconnected) Client already disconnected." << std::endl;
               return;
            }

            _log::comm << "(Comm::clientDisconnected)" << std::endl;
            //reset comm state for the next client
            clientConnected_ = false;

            _log::comm << "(Comm::clientDisconnected) Notifying listener." << std::endl;
            assert(cli_listener_);
            cli_listener_->clientDisconnected_CLI();
            _log::comm << "(Comm::clientDisconnected) Done." << std::endl;
         }

         ///error notification
         void Comm::errorNotification(const std::string& s)
         {
            _log::comm << "(Comm::handleError) ERROR: " + s +"." << std::endl;
            assert(cli_listener_);
            cli_listener_->errorNotification_CLI(s);
         }

         ///new received message notification
         void Comm::newReceivedMessage(std::string s)
         {
            //_log::comm <<  "(Comm::newReceivedMessage) --" << s << "--" << std::endl;
            _log::comm <<  "(Comm::handleReceivedMessage) Emiting new received message." << std::endl;

            //notify new received Test Item
            assert(cli_listener_);
            cli_listener_->newMessage_CLI(s);
         }

         /// //////////////////////////////////
         /// services for clients
         /// //////////////////////////////////

         void Comm::sendMessage ( const std::string& s)
         {
            // If i am a server and the client is not connected yet
            if (isServer_ && !clientConnected_)
            {
               _log::comm << "(Comm::sendMessage) WARNING: client not connected yet." << std::endl;
            }

            //send message
            writeMessage(s);
            _log::comm << "(Comm::sendMessage) Message sent." << std::endl;
         }

         bool Comm::connectionStatus()
         {
            return clientConnected_;
         }

      }//comm
   }//lib
}//csu
