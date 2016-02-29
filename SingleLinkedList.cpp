#include <iostream>
#define NODATA -1
#define NONEXT NULL

using namespace std;

class SingleLinkedListNode{
	public:
	int data;
	SingleLinkedListNode *next;

	SingleLinkedListNode(void){
		this->data = NODATA;
		this->next = NONEXT;
	}

	int getData(){
		return data;
	}

	bool setData(int input){
		if (input > 0){
			this->data = input;
			return true;
		}
		else
			cout<<"Input value "<<input<<" is negative"<<endl;
		return false;
	}

	bool deleteNode(int input){
		// If the current node has the element
		if (this->data == input){
			cout<<"The number is found on the current node";
			return false;
		}
		//If next node has the input
		if (this->next->getData() == input){
			if (this->next->next !=NONEXT){
				this->next = this->next->next;
				return true;
			}
			else{
				this->next = NONEXT;
				return true;
			}
		}
		else{
			SingleLinkedListNode *prev = this->next;
			SingleLinkedListNode *cur = prev->next;
			while(cur!=NULL){
				if (cur->data == input){
					prev->next = cur->next;
					return true;
				}
				prev = cur;
				cur = prev->next;
			}
			return false;
		}

	}

	bool printNodes(){
		cout<<"Data = "<<this->data<<endl;
		SingleLinkedListNode *cur = this->next;
		while(cur != NONEXT){
			cout<<"Data = "<<cur->data<<endl;
			cur = cur->next;
		}
		return true;
	}

	bool insertAtEnd(int input){
		SingleLinkedListNode *newNode = new SingleLinkedListNode();
		newNode->data = input;
		if(this->next==NONEXT){
			this->next = newNode;
			return true;
		}
		else{
			SingleLinkedListNode *cur;
			cur = this->next;
			while(cur->next!=NONEXT){
				cur = cur->next;
			}
			cur->next = newNode;
			return true;
		}
	}
};

SingleLinkedListNode *head = new SingleLinkedListNode();

void reverseList(SingleLinkedListNode* current){
	if(current->next == NULL){
		return;
	}
	reverseList(current->next);

	SingleLinkedListNode *q;
	q->next = current;
	current->next = NULL;
}

int main(int argc, char* argv[]){
	head = new SingleLinkedListNode();
	head->setData(1);
	for(int i=2;i<=20;i++){
		head->insertAtEnd(i);
	}

	return 1;
}
