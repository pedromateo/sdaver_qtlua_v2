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
#include <csu/base/comm/imps/tcp_comm2.h>
#include <boost/bind.hpp>

using namespace boost::asio;

namespace csu {
namespace base {
namespace comm {
namespace imps{

tcp_client::tcp_client(const std::string& ip, int port)
    : remote_ip_(ip), remote_port_(port)
{}

tcp_client::~tcp_client()
{
    io_.stop();
    comm_thread_.join();
}

///
/// start connects to the server and if it is a server, starts the
/// server loop.
///
void tcp_client::connect()
{
    ///endpoint data
    ip::address addr = ip::address::from_string(remote_ip_);
    ip::basic_endpoint<ip::tcp> endpoint(addr, remote_port_);

    c_socket_.reset (new ip::tcp::socket (io_));

    // connect to the client
    boost::system::error_code error = error::host_not_found;
    c_socket_->close();
    c_socket_->connect(endpoint, error);
    if (error)
        throw boost::system::system_error(error);

    o_stream_.reset (new std::ostream (&request_));
    i_stream_.reset (new std::istream (&response_));

    // Prepare the handler for reading
    // boost::asio::async_read (*c_socket_,response_,
    //                          boost::asio::transfer_at_least(1),
    //                          boost::bind(&tcp_client::handle_read, this,
    //                                      boost::asio::placeholders::error,
    //                                      boost::asio::placeholders::bytes_transferred));

    // // Prepare the handler for writing
    // boost::asio::async_write (*c_socket_, request_,
    //                           boost::asio::transfer_at_least(1),
    //                           boost::bind (&tcp_client::handle_write, this,
    //                                        boost::asio::placeholders::error,
    //                                        boost::asio::placeholders::bytes_transferred));

    // start the IO thread
    comm_thread_ = boost::thread (boost::ref (*this));
}

///
/// boost thread operator
///
void
tcp_client::operator()()
{
    std::cout << "thread running" << std::endl;
    io_.run();
    std::cout << "thread fini" << std::endl;
}

std::ostream&
tcp_client::ostream()
{
    return *o_stream_.get();
}

std::istream&
tcp_client::istream()
{
    return *i_stream_.get();
}

void
tcp_client::handle_read(const boost::system::error_code& error, size_t bt)
{
    std::cout << "handle_read " << bt << " (" << error << ")"  << std::endl;

    // The read data already populates the response_ rdbuf, so the
    // istream can be read with the needed data. boost::serialization
    // hopefully reds just the needed bytes.
    if (error)
        return;

//    if (response_.size())
        _read_async();
}

void
tcp_client::_send_async()
{
    boost::asio::async_write (*c_socket_, request_,
                              boost::asio::transfer_at_least(1),
                              boost::bind (&tcp_client::handle_write, this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
}

void
tcp_client::_read_async()
{
    boost::asio::async_read (*c_socket_,response_,
                             boost::asio::transfer_at_least(1),
                             boost::bind(&tcp_client::handle_read, this,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void
tcp_client::handle_write(const boost::system::error_code& error, size_t bt)
{
    std::cout << "handle_write" << bt << "(" << error << ")"  << std::endl;

    // if (error)
    //     return;

    // // Reissue the
    // if (request_.size())
    //     _send_async();
}


}//imps
}//comm
}//lib
}//csu
