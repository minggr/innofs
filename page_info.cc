#define NDEBUG
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <iostream>

#include "format.h"
using namespace std;

#define SIZE (1024*1024)

int main(int argc, char **argv)
{
    char *ibd;
    int fd;
    char *buf;
    file_header f_header;
    page_header p_header;

    if (argc < 2) {
        printf("%s [innodb_ibd_file]\n", argv[0]);
        return 0;
    }

    ibd = argv[1];
    fd = open(ibd, O_RDONLY);
    assert(fd > 0);
    buf = (char *)mmap(NULL, SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    assert(buf);

    f_header.decode(buf);
    p_header.decode(buf + sizeof(file_header)); 

    cout << f_header << endl;
    cout << endl;
    cout << p_header << endl;

    munmap(buf, SIZE);
    close(fd);

    return 0;
}
