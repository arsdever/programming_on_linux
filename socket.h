#ifndef SOCKET_H
#define SOCKET_H

#include "iobase.h"

class Socket : IOBase
{
  private:
    Socket();

  public:
    static IOBase *create(std::string const &filename, int flags, int mode);
};

#endif