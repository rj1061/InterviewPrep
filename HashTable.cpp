#include <iostream>
#include <string>

#define HASHLENGTH 10
#define NODATA -1

using namespace std;

class Node{
	public:
		int data;
		Node* next;

		Node(void){
			data = NODATA;
			next = NULL;
		}
};

class HashMap{
	public:
		Node* HTable[HASHLENGTH];
	
		HashMap(void){
			for (int i=0; i< HASHLENGTH;i++){
				HTable[i] = new Node();
				HTable[i]->data = NODATA;
			}
		}
		
		int returnHash(int input){
			return input % HASHLENGTH;
		}
		
		// Add
		void insertElement(int input){
			int index = returnHash(input);
			Node *temp = new Node();
			temp->data = input;
			Node* cur = HTable[index];
			while(cur->next!=NULL)
				cur = cur->next;
			cur->next = temp;
		}

		// Delete
		void deleteElement(int input){
			int index = returnHash(input);
			Node* cur = HTable[index];
			while(cur->next->data!= input || cur != NULL)
				cur = cur->next;
			if(cur==NULL){
				cout<<"Element not found"<<endl;
			}
			else{
				Node* temp = new Node;
				temp->data = input;
				temp->next = cur->next;
				cur->next = temp;
			}
			return;
		}

		// Member
		void memberDisplay(){
			for(int i=0;i<HASHLENGTH;i++){
				cout<<"For entry in element "<<i<<" the elements are ";
				Node*cur = HTable[i]->next;
				while(cur!=NULL){
					cout<<cur->data<<"  ";
					cur = cur->next;
				}
				cout<<endl;
			}
			return;
		}
};

int main(int argc, char* argv[]){
	HashMap *hash = new HashMap();

	for(int i=1;i<=20;i++){
		hash->insertElement(i);
	}
	hash->memberDisplay();
	return 1;
}
