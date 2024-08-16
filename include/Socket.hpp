//
// Created by 김세진 on 8/14/24.
//

#ifndef FT_IRC_SOCKET_HPP
#define FT_IRC_SOCKET_HPP

#include <iostream>
#include <stdexcept>
#include <sys/socket.h> // socket, bind, open, recv
#include <unistd.h> // socket close
#include <fcntl.h> // non-blocking
#include <netinet/in.h> // struct sockaddr_in
#include <cstring> // memset
#include <arpa/inet.h> // inet_ntoa, htons
#include <algorithm> // remove
#include <sstream>

#define CR '\r'
#define LF '\n'

class Session;

class Socket {
public:
    typedef int fd_t;

    Socket();
    Socket(fd_t fd);
    virtual ~Socket();
    Socket(const Socket &other);

    const fd_t &getFd() const;
    void setNonBlocking();
    void allowReusePort();
    void bind(int port);
    void open();
    Session *accept();
    virtual Socket &read();
    void operator>>(std::stringstream &stream);

private:
    const fd_t fd;
    std::stringstream readData;
};

#endif //FT_IRC_SOCKET_HPP
