#include "socket.h"
#include <fcntl.h>
#include <iostream>

int main(int argc, char **argv)
{
    IOBase *iodevice = Socket::create();
    delete iodevice;
    return 0;
}