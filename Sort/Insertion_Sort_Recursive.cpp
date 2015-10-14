#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort_Recursive(vector<int> &A, int border);

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);
	
	Insertion_Sort_Recursive(A, A.size());
	
	for(int i=0; i<A.size(); i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void Insertion_Sort_Recursive(vector<int> &A, int border) {
	if(border > 1) {
		Insertion_Sort_Recursive(A, border-1);
		int key = A[border-1];
		int i = border-2;
		while(i>=0 && A[i]>key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}
