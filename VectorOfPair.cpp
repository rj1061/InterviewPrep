#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	vector<pair<int, int> > a;
	a.push_back(make_pair(1, 2));
        cout<<a[0].first<<a[0].second;
	return 0;
}
