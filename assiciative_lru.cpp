#include<iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <regex>
using namespace std;
int misscount = 0;
int hitcount = 0;

class cache_node {
public:
    bool valid;
    int tag;
    int data;
    cache_node() {
        valid = false;
        tag = 0;
        data = 0;
    }
};

class cache {
public:
    int size;
    int capacity;
    vector< cache_node> cache_map;
    cache() {
        size = 0;
        capacity = 4;
        cache_node c1;
        cache_node c2;
        cache_node c3;
        cache_node c4;
        cache_map.push_back(c1);
        cache_map.push_back(c2);
        cache_map.push_back(c3);
        cache_map.push_back(c4);
    }
    void insert(int address) {
        int tag = address >> 3;
        if (size == capacity)
        {
            for (int i = 0; i < size; i++)
            {
                if (cache_map[i].tag == tag)
                {              
                    swap(cache_map[i], cache_map[3]);
                    
                    hitcount += 1;
                    return;
                }
            }                                                 
                    vector< cache_node> ::iterator iterator0 = cache_map.begin();
                    cache_map.erase(iterator0);          
                    size--;
                    cache_node new_node ;
                    new_node.valid = true;
                    new_node.tag = tag;
                    cache_map.push_back(new_node);
                    size++;
                    misscount += 1;             
        }
        else {
            for (int i = 0; i < size; i++)
            {
                if (cache_map[i].tag == tag)
                {
                    swap(cache_map[i], cache_map[3]);

                    hitcount += 1;
                    return;
                }
            }
            cache_node new_node ;
            new_node.valid = true;
            new_node.tag = tag;
            cache_map[size]=new_node;
            size++;
            misscount += 1;
        }
    }
};

int main()
{
    cache cacheTable;
    
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
            cacheTable.insert(address);
            
        }
    }
    file.close();

    cout <<"misscount"<< misscount << endl;
    cout<< "hitcount" << hitcount << endl;
    return 0;
}