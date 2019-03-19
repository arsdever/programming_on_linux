#ifndef SOCKET_H
#define SOCKET_H

#include "iobase.h"

class Socket : IOBase
{
  Socket(int descriptor);

private:
  Socket();

public:
  ~Socket();
  IOBase *waitForClient();
  static Socket *create(short port);
};

#endif