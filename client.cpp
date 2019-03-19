#include "socket.h"
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <list>

int main(int argc, char **argv)
{
    IOBase *client = Socket::createClient("127.0.0.1", DEFAULT_PORT);

    std::cout << client->read() << std::endl;

    delete client;
    return 0;
}