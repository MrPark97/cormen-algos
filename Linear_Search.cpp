#include <iostream>
#include <vector>
using namespace std;

int Linear_Search(vector<int> &A, int v);

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);
	
	int i = Linear_Search(A, 2);
	
	if(i>=0) cout << "i=" << i << "v=" << A[i];
		
	return 0;
}

int Linear_Search(vector<int> &A, int v) {
	for(int i=0; i<A.size(); i++) {
		if(v == A[i]) return i;
	}
	return -1;
}
