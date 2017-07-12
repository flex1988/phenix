#include <types.h>

#include "multiboot.h"
#include "print/printk.h"
#include "mm/frame.h"
#include "mm/mmu.h"
#include "vga/vga.h"
#include "hal/hal.h"

void kmain(unsigned long addr) {
    vga_init();
    clear_screen();
    printk("vga mode init...");

    hal_init();
    printk("interrupt init...");

    frame_init((struct multiboot_info *)addr);

    mmu_init();

    while (1)
        ;
}
