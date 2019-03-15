#include "file.h"
#include <fcntl.h>
#include <iostream>

int main(int argc, char **argv)
{
    IOBase *iodevice = File::create("my_file.txt", O_RDWR | O_CREAT | O_APPEND, (S_IRWXU | S_IRWXO | S_IRWXG) & ~S_IXUSR & ~S_IXOTH & ~S_IXGRP);
    iodevice->write("Hello world");
    iodevice->write("New text");
    delete iodevice;
    IOBase *newIODevice = File::create("my_file.txt", O_RDWR | O_CREAT | O_APPEND, (S_IRWXU | S_IRWXO | S_IRWXG) & ~S_IXUSR & ~S_IXOTH & ~S_IXGRP);
    std::cout << newIODevice->read();
    return 0;
}