#include <vector>
#include <iostream>

using namespace std;

class MinHeap{
	public:
		MinHeap();
		MinHeap(const vector<int>& vector);
		MinHeap(int* array, int length);

		void insert(int newValue);
		int getMin();
		void deleteMin();

	private:
		vector<int> _vector;
		void bubbleDown(int index);
		void bubbleUp(int index);
		void heapify();
}

MinHeap::MinHeap(int* array, int length) : _vector(length)
{
	for(int i=0; i < length; ++i)
		_vector[i] = array[i];

	heapify();
}

MinHeap::MinHeap(const vector<int>& vector) : _vector(length)
{
	heapify();
}

MinHeap::MinHeap()
{
}



int main(int argc, char* argv[]){
	return 1;
}
