#include<iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <sstream>
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
    cacheTable.insert( address1);
    cacheTable.insert(address2);
    cacheTable.insert(address3);
    cacheTable.insert(address4);
    cacheTable.insert(address5);
    cacheTable.insert(address6);
    cacheTable.insert(address7);
    cacheTable.insert(address8);
    cacheTable.insert(address9);
    cacheTable.insert(address10);
    cout << misscount << " "<<hitcount;
    return 0;
}
