#ifndef INNODB_FORMAT_H
#define INNODB_FORMAT_H

#include <stdint.h>
#include <iostream>
using std::ostream;

struct file_header {
    uint32_t page_checksum;
    uint32_t page_offset;
    uint32_t page_prev;
    uint32_t page_next;
    uint64_t page_lsn;
    uint16_t page_type;
    uint64_t page_file_flush_lsn;
    uint32_t page_arch_log_no;

    void decode(void *buf);
};

ostream& operator<<(ostream& out, const file_header &h);

#endif
