#include<iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <regex>
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
    ifstream file("MemoryAccess.out");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    regex address_regex("address\\s(0x[0-9a-fA-F]+)");
    string line;

    while (getline(file, line)) {
        smatch match;
        if (regex_search(line, match, address_regex)) {
            string address_str = match[1];
            int address = stoi(address_str, nullptr, 16);
            search(cacheTable,address);
            
        }
    }
    file.close();

    cout <<"misscount"<< misscount << endl;
    cout<< "hitcount" << hitcount << endl;
    return 0;
}
