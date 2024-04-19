#include<iostream>
using namespace std;
//direct mapped
class Direct_Cache {
public:
	bool valid;
	int tag;
	int data;
	Direct_Cache() {
		valid = false;
		tag = -1;
		data = -1;
	}
};
int search(Direct_Cache *cache, int address) {
	int tag=address / 16;
	for (int i = 0; i < 4; i++) {
		if (cache[i].tag == tag) {
			return i;
		}
	}
	return -1;
}
//



//set 


int main() {
	return 0;
}