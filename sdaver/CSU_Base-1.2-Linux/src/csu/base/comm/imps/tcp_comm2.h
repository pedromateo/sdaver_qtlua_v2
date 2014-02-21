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
 *   This file is part of the Open-HMI Tester,
 *   http://openhmitester.sourceforge.net
 *
 */
#ifndef TCP_COMM_H
#define TCP_COMM_H


#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <memory>

namespace csu {
namespace base {
namespace comm {
namespace imps {


/// ///////////////////
/// SERVER AND CLIENT BASE
/// ///////////////////

class tcp_client
{
public:
    tcp_client(const std::string& ip, int port);
    ~tcp_client();

    void connect();

    ///
    /// boost thread operator
    ///
    void operator()();

    std::ostream& ostream();
    std::istream& istream();

protected:
    std::string remote_ip_;
    int remote_port_;

private:

    // This functions will be called whenever anything from the socket
    // is ready to be read or written. We always have one async
    // operation ready so that we can use the streams to treat the
    // required data
    void handle_read(const boost::system::error_code& error, size_t);
    void handle_write(const boost::system::error_code& error, size_t);

    void _send_async();
    void _read_async();

    boost::asio::io_service io_;
    boost::thread comm_thread_;
    std::auto_ptr<boost::asio::tcp::iostream> iostream_;
};


}//imps
}//comm
}//lib
}//csu



#endif // COMM_H
