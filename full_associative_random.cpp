#include<iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <sstream>
#include <random>
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
    void initialize(bool new_valid, int new_tag, int new_data) {
        valid = new_valid;
        tag = new_tag;
        data = new_data;
    }
};

int search(vector<Cache>& cacheTable, int address) {
    int ntag = address / 4;
    for (int i =0;i<4;i++)
    {
        if(cacheTable[i].tag==ntag&&cacheTable[i].valid==1)
        {
            hitcount+=1;
            return 1;
        }
    }
    misscount+=1;
     for (int i =0;i<4;i++)
     {
        if(cacheTable[i].valid==0)
        {
            move_into_cache(address,cacheTable[i]);
            return -1;
        }
     }
     exchage_into_cache_random(address,cacheTable);
     return -1;
}

void exchage_into_cache_random(int address,vector<Cache>& c)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3);
    int random_number = dis(gen);
    int ntag = address / 4;
    c[random_number].tag=ntag;
}


void move_into_cache(int address,Cache c)
{
    int ntag = address / 4;
    c.tag=ntag;
    c.valid=1;
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

    ifstream file("mmu.out");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string part;
            while (iss >> part) {
        if (part == "address") {
            iss >> part; // Skip "address"
            int address;
            if (iss >> hex >> address) {
                
                    search(cacheTable,address);
                }
            } else {
                cerr << "Failed to read address from line: " << line << std::endl;
            }
            break;
        }
        }
        file.close();
    } else {
        cerr << "Unable to open file\n";
        return 1;
    }
return 0;
}
