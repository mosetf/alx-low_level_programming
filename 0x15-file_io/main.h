#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

#define BUFSIZE 1024
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void check_elf(unsigned char *e_ident);
void printf_magic(unsigned char *e_ident);
void printf_class(unsigned char *e_ident);
void printf_data(unsigned char *e_ident);
void printf_version(unsigned char *e_ident);
void printf_abi(unsigned char *e_ident);
void printf_osabi(unsigned char *e_ident);
void printf_type(unsigned int e_type, unsigned char *e_ident);
void printf_input(unsigned long int e_entry, unsigned char *e_ident);
void end_elf(int elf);

#endif
