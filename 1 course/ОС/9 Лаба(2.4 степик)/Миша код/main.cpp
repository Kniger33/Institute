#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <algorithm>


struct phys_line {
    uint64_t phys_addr;
    uint64_t value;
};

using namespace std;

uint64_t phys_addr;
int size_table;
phys_line *phys_table;

void val_to_phys(bitset<64> &value) {
    value &= 0xFFFFFFFFFF000UL;
}

uint64_t find_in_phys_table(uint64_t paddr) {
    for (int i = 0; i < size_table; i++) {
        if (phys_table[i].phys_addr == paddr) {
            return phys_table[i].value;
        }
    }
    return 0;
}

string to_string(int param)
{
    string str = "";
    for (str = ""; param ; param /= 10)
    {
        str += (char)('0' + param % 10);
    }
    reverse(str.begin(), str.end());
    return str;
}

string log_to_value(uint64_t log_addr) {
    bitset<64> bit_log_addr(log_addr);

    bitset<9> bit_pml4(0);
    bitset<9> bit_directory_ptr(0);
    bitset<9> bit_directory(0);
    bitset<9> bit_table(0);
    bitset<11> bit_offset(0);

    int pos = 39;
    for (int i = 0; i < 9; i++) {
        bit_pml4[i] = bit_log_addr[pos++];
    }
    pos = 30;
    for (int i = 0; i < 9; i++) {
        bit_directory_ptr[i] = bit_log_addr[pos++];
    }
    pos = 21;
    for (int i = 0; i < 9; i++) {
        bit_directory[i] = bit_log_addr[pos++];
    }
    pos = 12;
    for (int i = 0; i < 9; i++) {
        bit_table[i] = bit_log_addr[pos++];
    }
    pos = 0;
    for (int i = 0; i < 12; i++) {
        bit_offset[i] = bit_log_addr[pos++];
    }

    uint64_t paddr = (uint64_t) phys_addr + (bit_pml4.to_ullong() * 8ll);
    uint64_t value = (uint64_t) find_in_phys_table(paddr);
    bitset<64> bit_value(value);

    if (bit_value[0] == 0) {
        return "fault";
    }

    val_to_phys(bit_value);
    paddr = (uint64_t) bit_value.to_ullong() + (bit_directory_ptr.to_ullong() * 8ll);
    value = (uint64_t) find_in_phys_table(paddr);
    bit_value = (bitset<64>) value;

    if (bit_value[0] == 0) {
        return "fault";
    }

    val_to_phys(bit_value);
    paddr = (uint64_t) bit_value.to_ullong() + (bit_directory.to_ullong() * 8ll);
    value = (uint64_t) find_in_phys_table(paddr);
    bit_value = (bitset<64>) value;

    if (bit_value[0] == 0) {
        return "fault";
    }

    val_to_phys(bit_value);
    paddr = (uint64_t) bit_value.to_ullong() + (bit_table.to_ullong() * 8ll);
    value = (uint64_t) find_in_phys_table(paddr);
    bit_value = (bitset<64>) value;

    if (bit_value[0] == 0) {
        return "fault";
    }

    val_to_phys(bit_value);
    paddr = (uint64_t) bit_value.to_ullong() + bit_offset.to_ullong();
    return to_string(paddr);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    uint64_t num_request;
    uint64_t log_addr;

    fin >> size_table >> num_request >> phys_addr;

    phys_table = new phys_line[size_table];

    for (int i = 0; i < size_table; i++) {
        fin >> phys_table[i].phys_addr >> phys_table[i].value;
    }

    for (int i = 0; i < num_request; i++) {
        fin >> log_addr;
        fout << log_to_value(log_addr) << endl;
    }

    delete[] phys_table;
    fin.close();

    return 0;
}
