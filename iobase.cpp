#include "iobase.h"
#include <unistd.h>

IOBase::IOBase(int descriptor)
    : __descriptor(descriptor)
{
}

IOBase::~IOBase()
{
    close();
}

IOBase *IOBase::create(int descriptor)
{
    return new IOBase(descriptor);
}

bool IOBase::close()
{
    if (__descriptor == -1)
    {
        return -1;
    }
    else
    {
        bool closed = !::close(__descriptor);
        __descriptor = -1;
        return closed;
    }
}

void IOBase::write(std::string const &data)
{
    const char *buffer = data.c_str();
    int size = data.size();
    while (size)
    {
        int written = ::write(__descriptor, buffer, size);
        size -= written;
        buffer += written;
    }
}

std::string IOBase::read() const
{
    const int buf_size = 255;
    std::string result;
    char *buffer = new char[buf_size + 1];
    buffer[buf_size] = 0;
    while (::read(__descriptor, buffer, buf_size))
    {
        result += std::string(buffer);
    }
    return result;
}