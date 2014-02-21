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

#include "proxy_comm.h"

namespace csu {
    namespace base {
        namespace comm {
            namespace imps{


                ProxyComm::ProxyComm(CommListener* listener) :
                        Comm(false, "localhost",0, listener)
                {
                }

                ProxyComm::~ProxyComm()
                {
                }

                ///
                /// disconnects the server/client to the other
                /// side
                ///
                void ProxyComm::disconnect()
                {
                    cli_listener_->clientDisconnected_CLI();
                }

                ///
                /// writes a message in the socket
                /// (implements the Comm virtual method)
                ///
                bool ProxyComm::writeMessage(const std::string& message)
                {
                    cli_listener_->newMessage_CLI(message);
                }

            }//imps
        }//comm
    }//lib
}//csu
