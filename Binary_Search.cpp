#include <iostream>
#include <vector>
using namespace std;

// Applies only to a sorted array!!!
int Binary_Search(vector<int> &A, int low, int high, int v);

int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(2);
	A.push_back(4);
	A.push_back(4);
	A.push_back(5);
	
	int i = Binary_Search(A, 0, A.size(), 2);
	
	if(i>=0) cout << "i=" << i << "v=" << A[i];
		
	return 0;
}

int Binary_Search(vector<int> &A, int low, int high, int v) {
	if(low == high-1 && v != A[low]) return -1;
	int current = (low+high)/2;
	if(v == A[current]) return current;
	if(v > A[current]) return Binary_Search(A, current, high, v);
	else return Binary_Search(A, low, current, v);
}
