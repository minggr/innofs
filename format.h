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

struct page_header {
    uint16_t page_n_dir_slots;
    uint16_t page_heap_top;
    uint16_t page_n_heap;
    uint16_t page_free;
    uint16_t page_garbage;
    uint16_t page_last_insert;
    uint16_t page_direction;
    uint16_t page_n_direction;
    uint16_t page_n_recs;
    uint64_t page_max_trx_id;
    uint16_t page_level;
    uint64_t page_index_id;
    uint8_t page_btr_seg_leaf[10];
    uint8_t page_btr_seg_top[10];

    void decode(void *buf);
};

ostream& operator<<(ostream& out, const page_header &h);

#endif
