//
// Created by 김세진 on 8/14/24.
//

#ifndef FT_IRC_SESSIONMANAGER_HPP
#define FT_IRC_SESSIONMANAGER_HPP

#include <map>
#include "Session.hpp"

class SessionManager {
public:
    SessionManager();
    ~SessionManager();

    void add(Session *session);
    Session *get(Socket::fd_t sessionFd);

private:
    std::map<Socket::fd_t, Session *> sessions;

    typedef std::map<Socket::fd_t, Session *>::iterator iterator;
};

#endif //FT_IRC_SESSIONMANAGER_HPP
