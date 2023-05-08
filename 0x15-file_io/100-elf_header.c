#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
* print_elf_header - Prints the information contained in an ELF header
* @ehdr: Pointer to the ELF header structure
*/
void print_elf_header(Elf64_Ehdr *ehdr)
{
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", ehdr->e_ident[i]);
printf("\n");
printf("  Class:                             %s\n",
ehdr->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
ehdr->e_ident[EI_CLASS] == ELFCLASSNONE ? "none" :
"unknown");
printf("  Data:                              %s\n",
ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
ehdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
ehdr->e_ident[EI_DATA] == ELFDATANONE ? "none" :
"unknown");
printf("  Version:                           %d (%s)\n",
ehdr->e_ident[EI_VERSION],
ehdr->e_ident[EI_VERSION] == EV_CURRENT ? "current" :
ehdr->e_ident[EI_VERSION] == EV_NONE ? "none" :
"unknown");
printf("  OS/ABI:                            %s\n",
ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "Solaris ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_AIX ? "AIX ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "IRIX ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "FreeBSD ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "Tru64 UNIX ABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI ? "ARM EABI" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM ABI (obsolete)" :
ehdr->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone (embedded) ABI" :
"unknown");
printf("  ABI Version:                       %d\n",
ehdr->e_ident[EI_ABIVERSION]);
printf("  Type:                              %s\n",
ehdr->e_type == ET_NONE ? "NONE (None)" :
ehdr->e_type == ET_REL ? "REL (Relocatable file)" :
ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
ehdr->e_type == ET_DYN ? "DYN (Shared object file)" :
ehdr->e_type == ET_CORE ? "CORE (Core file)" :
"unknown");
printf("  Entry point address:               %lx\n",(unsigned long) ehdr->e_entry);
printf("\n");
}

/**
* main - Entry point
* @argc: Argument count
* @argv: Argument vector
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr ehdr;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
exit(98);
}

if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
{
fprintf(stderr, "Error: Cannot read ELF header from %s\n", argv[1]);
exit(98);
}

if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
ehdr.e_ident[EI_MAG3] != ELFMAG3)
{
fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
exit(98);
}

print_elf_header(&ehdr);

close(fd);
return (0);
}


