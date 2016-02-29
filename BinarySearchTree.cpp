#include <iostream>
#define NODATA -1

using namespace std;

class Node{
	public:
	Node* left;
	Node* right;
	int data;

	Node(){
		this->left = NULL;
		this->right = NULL;
		this->data = NODATA;
	}
};

class BinaryTree{
	public:
	BinaryTree(void){
		this->root = NULL;
	}
	~BinaryTree(){}

	Node* root;

	void insertElement(int input){
		root = insert(input, this->root);
	}

	Node* searchElement(int input){
		return search(input, this->root);
	}

	void destroyElement(){
		deleteTree(this->root);
	}

	void printTree(){
		printTreeInorder(this->root);
	}

	void deleteElement(int input){
		this->root = deleteElementRecursively(input, this->root);
		return;
	}

	Node* returnMin(Node* n){
		while(n->left!=NULL) n = n->left;
		return n;
	}

	Node* deleteElementRecursively(int input, Node* n){
		if(n == NULL)	return n;
		else if (input > n->data) n->right = deleteElementRecursively(input, n->right);
		else if (input< n->data) n->left = deleteElementRecursively(input, n->left);
		else{
			if(n->left == NULL && n->right == NULL){
				delete n;
				n = NULL;
			}
			else if(n->left == NULL){
				Node* temp = n;
				n = n->right;
				delete temp;
			}
			else if(n->right == NULL){
				Node* temp = n;
				n = n->left;
				delete temp;
			}
			else{
				Node* temp = returnMin(n->right);
				n->data = temp->data;
				n->right = deleteElementRecursively(temp->data, n->right);
			}
		}
		return n;
	}

	Node* insert(int input, Node* n){
		if(n==NULL){
			n = new Node();
			n->data = input;
			return n;
		}
		else if(n->data>input) n->left = insert(input, n->left);
		else if(n->data<input) n->right = insert(input, n->right);
		else cout<<"Redundant Input"<<endl;
		return n;
	}

	Node* search(int input, Node *n){
		if(n->data == input){
			return n;
		}
		else{
			if(input>n->data)
				return search(input, n->right);
			else
				return search(input, n->left);
		}
		if(n->data == NODATA){
			cout<<"Element not found"<<endl;
			return NULL;
		}

	}

	void printTreeInorder(Node* n){
		if(n == NULL) return;
		printTreeInorder(n->left);
		cout<<n->data<<endl;
		printTreeInorder(n->right);
	}

	void deleteTree(Node* n){
		deleteTree(n->left);
		deleteTree(n->right);
		cout<<"Deleting node with data "<<n->data<<endl;
	}
};


int main(int argc, char* argv[]){
	BinaryTree* b = new BinaryTree();
	for(int i=0; i<10; i++){
		b->insertElement(i);
	}

	cout<<"Tree Constructed"<<endl;
	b->printTree();
	cout<<"Deleting element 5"<<endl;
	b->deleteElement(5);
	b->printTree();

	return 1;
}
