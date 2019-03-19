#include "socket.h"

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

Socket::Socket(int descriptor)
    : IOBase(descriptor)
{
}

Socket *Socket::create(short port)
{
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (descriptor == -1)
    {
        throw IOBase::IOException();
    }

    sockaddr_in sockaddress;
    memset(&sockaddress, 0, sizeof(sockaddr_in));

    sockaddress.sin_family = AF_INET;
    sockaddress.sin_addr.s_addr = INADDR_ANY;
    sockaddress.sin_port = htons(port);

    if (bind(descriptor, (const sockaddr *)&sockaddress, sizeof(sockaddr_in)))
    {
        std::cerr << "bind: " << strerror(errno) << std::endl;
        throw IOBase::IOException();
    }

    if (listen(descriptor, 3))
    {
        std::cerr << "listen " << strerror(errno) << std::endl;
        throw IOBase::IOException();
    }
    std::cout << "Started listening on port " << port << std::endl;

    return new Socket(descriptor);
}

IOBase *Socket::waitForClient()
{
    sockaddr_in client;
    memset(&client, 0, sizeof(sockaddr_in));
    socklen_t size;

    int client_descriptor = accept(get_descriptor(), (sockaddr *)&client, &size);
    if (client_descriptor == -1)
    {
        std::cerr << "accept " << strerror(errno) << std::endl;
        throw IOBase::IOException();
    }

    return IOBase::create(client_descriptor);
}

IOBase *Socket::createClient(std::string const &ip, short port)
{
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (descriptor == -1)
    {
        throw IOBase::IOException();
    }

    sockaddr_in sockaddress;
    memset(&sockaddress, 0, sizeof(sockaddr_in));

    sockaddress.sin_family = AF_INET;
    sockaddress.sin_port = htons(port);

    inet_pton(sockaddress.sin_family, ip.c_str(), &sockaddress.sin_addr);

    if (connect(descriptor, (const sockaddr *)&sockaddress, sizeof(sockaddr_in)))
    {
        std::cerr << "connect " << strerror(errno) << std::endl;
        throw IOBase::IOException();
    }
    std::cout << "Connected to ip " << ip << " port " << port << std::endl;

    return IOBase::create(descriptor);
}