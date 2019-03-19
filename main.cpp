#include "socket.h"
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <list>

int main(int argc, char **argv)
{
    Socket *socket = Socket::create(5000);
    std::list<IOBase *> clients;
    while (1)
    {
        try
        {
            clients.push_back(socket->waitForClient());
            for (IOBase *client : clients)
                client->write("New client connected\n");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    delete socket;
    return 0;
}