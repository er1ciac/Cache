#include<iostream>
using namespace std;
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
//暂时不用继承的方法写代码了
class size_Cache{
public:
	bool valid;
	int tag;
	int data;
	size_Cache* pointer;
	size_Cache(){
		valid = false;
		tag = -1;
		data = -1;
	}
	size_Cache(int size) {
		valid = false;
		tag = -1;
		data = -1;
		for(int i=0;i<size-1;i++){
			size_Cache * tool=pointer;
			pointer=new size_Cache();
			tool=tool.pointer;
		}
		//内部set用链表，因为要遍历比较组内每一个元素
	}
};
//具体地址格式等着跑出来数据再说
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
void Direst_Cache(Cache * Pointer,int size){
	Cache * Pointer=new Cache[size];
	for(int i=0;i<size;i++){
		Pointer[i]=new Cache();
	}
}


//set 


int main() {
	return 0;
}