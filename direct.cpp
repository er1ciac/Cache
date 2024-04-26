#include<iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <sstream>
using namespace std;
int misscount = 0;
int hitcount = 0;
//direct mapped
class Cache {
public:
    bool valid;
    int tag;
    int data;

    Cache() {
        valid = false;
        tag = -1;
        data = -1;
    }

};

void exchage_into_cache(int address, Cache &c)
{
    int ntag = address >> 5;
    c.tag = ntag;
}
void move_into_cache(int address, Cache &c)
{
    int ntag = address >> 5;
    c.tag = ntag;
    c.valid = 1;
}
int search(vector<Cache>& cacheTable, int address) {
    int ntag = address >> 5;
    uint64_t address_uint64 = static_cast<uint64_t>(address);
    uint64_t shifted = address >> 3;
    uint64_t last_two_bits = shifted & 0b11;
    int index = static_cast<int>(last_two_bits);

    if (cacheTable[index].tag == ntag && cacheTable[index].valid == true)
    {

        hitcount += 1;
        return index;
    }
    else if (cacheTable[index].tag != ntag && cacheTable[index].valid == true)
    {
        exchage_into_cache(address, cacheTable[index]);
        misscount += 1;

        return -1;
    }
    else
    {
        move_into_cache(address, cacheTable[index]);
        misscount += 1;

        return -1;
    }
}


int main()
{
    vector<Cache> cacheTable;
    Cache c1;
    Cache c2;
    Cache c3;
    Cache c4;
    cacheTable.push_back(c1);
    cacheTable.push_back(c2);
    cacheTable.push_back(c3);
    cacheTable.push_back(c4);
    int address1 = 0x16588;
    int address2 = 0x3f9d8;
    int address3 = 0x16588;
    int address4 = 0x16588;
    int address5 = 0x56b78;
    int address6 = 0x16590;
    int address7 = 0x16590;
    int address8 = 0x16590;
    int address9 = 0x16598;
    int address10 = 0x3f9f8;
    search(cacheTable, address1);
    search(cacheTable, address2);
    search(cacheTable, address3);
    search(cacheTable, address4);
    search(cacheTable, address5);
    search(cacheTable, address6);
    search(cacheTable, address7);
    search(cacheTable, address8);
    search(cacheTable, address9);
    search(cacheTable, address10);
    cout << misscount << hitcount;
    return 0;
}
