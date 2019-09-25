#define ELF_NIDENT	16

// program header-ы такого типа нужно загрузить в
// память при загрузке приложения
#define PT_LOAD		1

using namespace std;

// структура заголовка ELF файла
struct elf_hdr {
	uint8_t e_ident[ELF_NIDENT];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} __attribute__((packed));

// структура записи в таблице program header-ов
struct elf_phdr {
	uint32_t p_type;
	uint32_t p_flags;
	uint64_t p_offset;
	uint64_t p_vaddr;
	uint64_t p_paddr;
	uint64_t p_filesz;
	uint64_t p_memsz;
	uint64_t p_align;
} __attribute__((packed));

#include <fstream>
#include <iostream>

size_t space(const char *name)
{
    size_t size = 0;

    elf_hdr elfHdr;
    elf_phdr elfPhdr;

    ifstream fin(name);

    fin.read((char*)&elfHdr, sizeof(elf_hdr));

    for (int i = 0; i < elfHdr.e_phoff; i++){
        fin.read((char*)&elfPhdr, sizeof(elf_phdr));
        if (elfPhdr.p_type == PT_LOAD){
            size = size + elfPhdr.p_memsz;
        }
    }

    return size;
}
