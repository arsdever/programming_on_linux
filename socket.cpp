#include "socket.h"

#include <sys/types.h>
#include <sys/socket.h>

IOBase *Socket::create()
{
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (descriptor == -1)
    {
        throw IOBase::IOException();
    }

    return IOBase::create(descriptor);
}