#ifndef IO_BASE
#define IO_BASE

#include <string>
#include <exception>

class IOBase
{
  public:
    enum Flags
    {
        O_ACCMODE = 00000003,
        O_RDONLY = 00000000,
        O_WRONLY = 00000001,
        O_RDWR = 00000002,
        O_CREAT = 00000100,
        O_EXCL = 00000200,
        O_NOCTTY = 00000400,
        O_TRUNC = 00001000,
        O_APPEND = 00002000,
        O_NONBLOCK = 00004000,
        O_DSYNC = 00010000,
        O_DIRECT = 00040000,
        O_LARGEFILE = 00100000,
        O_DIRECTORY = 00200000,
        O_NOFOLLOW = 00400000,
        O_NOATIME = 01000000,
        O_CLOEXEC = 02000000,
        __O_SYNC = 04000000,
        __O_TMPFILE = 020000000,
        O_SYNC = (__O_SYNC | O_DSYNC),
        O_PATH = 010000000,
        O_TMPFILE = (__O_TMPFILE | O_DIRECTORY),
        O_TMPFILE_MASK = (__O_TMPFILE | O_DIRECTORY | O_CREAT),
        O_NDELAY = O_NONBLOCK,
    };

  private:
    IOBase(int descriptor);

  protected:
    static IOBase *create(int descriptor);

  public:
    ~IOBase();
    bool close();
    void write(std::string const &data);
    std::string read() const;

  private:
    int __descriptor;

  public:
    class IOException : public std::exception
    {
        const char *what() const noexcept override { return "Unknown IOBase exception"; }
    };
};

#endif