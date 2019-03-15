#ifndef FILE_H
#define FILE_H

#include "iobase.h"

class File : IOBase
{
  private:
    File();

  protected:
    File(int);

  public:
    static IOBase *create(std::string const &filename, int flags, int mode);
};

#endif