#include "file.h"
#include <fcntl.h>
#include <exception>

IOBase *File::create(std::string const &filename, int flags, int mode)
{
    int descriptor = open(filename.c_str(), flags, mode);
    if (descriptor == -1)
    {
        throw IOBase::IOException();
    }

    return IOBase::create(descriptor);
}