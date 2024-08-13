//
// Created by 김세진 on 8/13/24.
//

#include "User.hpp"

User::User(fd_t fd, struct sockaddr_in const &addr) : fd(fd) {
    std::string ip = std::string(inet_ntoa(addr.sin_addr));
    int port = ntohs(addr.sin_port);
    std::cout << "New connection from " << ip << ":" << port << std::endl;
}

User::~User() {
    close(fd);
}