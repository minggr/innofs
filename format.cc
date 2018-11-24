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
    return out << "page_checksum: 0x" << std::hex << h.page_checksum << "\n"
               << "page_offset: 0x" << h.page_offset << "\n"
               << "page_prev: 0x" << h.page_prev << "\n"
               << "page_next: 0x" << h.page_next << "\n"
               << "page_lsn: 0x" << h.page_lsn << "\n"
               << "page_type: 0x" << h.page_type << "\n"
               << "page_file_flush_lsn: 0x" << h.page_file_flush_lsn << "\n"
               << "page_arch_log_no: 0x" << h.page_arch_log_no
               << std::dec;
}
