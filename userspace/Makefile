CC := /root/opt/cross/bin/i686-elf-gcc

bin_dir := ../build/bin

obj_dir := ../build/objs

libc := ../build/libc.a

target := $(bin_dir)/init

all: $(target)

CFLAGS := -m32 -nostdlib -nostdinc -fno-builtin -I ../include/libc

LDFLAGS := -melf_i386 -T link.ld

$(bin_dir)/init: $(obj_dir)/init.o
	$(LD) $(LDFLAGS) -o $(bin_dir)/init $(obj_dir)/init.o $(libc)

$(obj_dir)/%.o: %.c
	$(CC) $(CFLAGS) -m32 -g -I../include/libc -c -o $@ $<