#ifndef __KHEAP_H__
#define __KHEAP_H__

#include "lib/ordered_array.h"

#define HEAP_INDEX_SIZE 0x40000
#define HEAP_MAGIC 0x12345678

typedef struct {
    uint32_t magic;
    uint8_t hole;
    uint32_t size;
} header_t;

typedef struct {
    uint32_t magic;
    header_t *header;
} footer_t;

typedef struct {
    ordered_array_t index;
    uint32_t start;
    uint32_t end;
    uint32_t max;
    uint8_t supervisor;
    uint8_t readonly;
} heap_t;

heap_t *create_heap(uint32_t start, uint32_t end, uint32_t max, uint8_t supervisor, uint8_t readonly);

void *alloc(uint32_t size, uint8_t page_align, heap_t *heap);

uint32_t kmalloc_i(uint32_t size, int align, uint32_t *phys);
uint32_t kmalloc(uint32_t size);
void kfree(void *p);
#endif
