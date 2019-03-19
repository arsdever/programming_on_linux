#ifndef SOCKET_H
#define SOCKET_H

#include "iobase.h"
static const int DEFAULT_PORT = 5000;

class Socket : IOBase
{
  Socket(int descriptor);

private:
  Socket();

public:
  ~Socket();
  IOBase *waitForClient();
  static Socket *create(short port);
  static IOBase *createClient(std::string const &ip, short port);
};

#endif