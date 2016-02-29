#include <iostream>
#define NODATA -1
#define NULLPTR NULL

using namespace std;

class DoubleLinkedListNode{
	public:
		int data;
		DoubleLinkedListNode* prev;
		DoubleLinkedListNode* next;

		DoubleLinkedListNode(void){
			this->data = NODATA;
			this->prev = NULLPTR;
			this->next = NULLPTR;
		}
}


int main(int argc, char* argv[]){
	return 1;
}
