#include <string.h>
#include "format.h"

void file_header::decode(void *buf)
{
    file_header *h = (file_header *)buf;

    page_checksum = h->page_checksum;
    page_offset = h->page_offset;
    page_prev = h->page_prev;
    page_next = h->page_next;
    page_lsn = h->page_lsn;
    page_type = h->page_type;
    page_file_flush_lsn = h->page_file_flush_lsn;
    page_arch_log_no = h->page_arch_log_no;
}

ostream& operator<<(ostream& out, const file_header &h)
{
    return out << "[file header]\n"
               << "page_checksum: 0x" << std::hex << h.page_checksum << "\n"
               << "page_offset: 0x" << h.page_offset << "\n"
               << "page_prev: 0x" << h.page_prev << "\n"
               << "page_next: 0x" << h.page_next << "\n"
               << "page_lsn: 0x" << h.page_lsn << "\n"
               << "page_type: 0x" << h.page_type << "\n"
               << "page_file_flush_lsn: 0x" << h.page_file_flush_lsn << "\n"
               << "page_arch_log_no: 0x" << h.page_arch_log_no
               << std::dec;
}

void page_header::decode(void *buf)
{
    page_header *h = (page_header *)buf;

    page_n_dir_slots = h->page_n_dir_slots;
    page_heap_top = h->page_heap_top;
    page_n_heap = h->page_n_heap;
    page_free = h->page_free;
    page_garbage = h->page_garbage;
    page_last_insert = h->page_last_insert;
    page_direction = h->page_direction;
    page_n_direction = h->page_n_direction;
    page_n_recs = h->page_n_recs;
    page_max_trx_id = h->page_max_trx_id;
    page_level = h->page_level;
    page_index_id = h->page_index_id;
    memcpy(page_btr_seg_leaf, h->page_btr_seg_leaf, 10);
    memcpy(page_btr_seg_top, h->page_btr_seg_top, 10);
}

ostream& operator<<(ostream& out, const page_header &h)
{
    return out << "[page header]\n"
               << "page_n_dir_slots: " << h.page_n_dir_slots << "\n"
               << "page_heap_top: " << h.page_heap_top << "\n"
               << "page_n_heap: " << h.page_n_heap << "\n"
               << "page_free: " << h.page_free << "\n"
               << "page_garbage: " << h.page_garbage << "\n"
               << "page_last_insert: " << h.page_last_insert << "\n"
               << "page_direction: " << h.page_direction << "\n"
               << "page_n_direction: " << h.page_n_direction << "\n"
               << "page_n_recs: " << h.page_n_recs << "\n"
               << "page_max_trx_id: " << h.page_max_trx_id << "\n"
               << "page_level: " << h.page_level << "\n"
               << "page_index_id: " << h.page_index_id;
}
