#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort(vector<int> &A);

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);
	
	Insertion_Sort(A);
	
	for(int i=0; i<A.size(); i++) {
		cout << A[i] << " ";
	}
	
	return 0;
}

void Insertion_Sort(vector<int> &A) {
	for(int j=1; j<A.size(); j++) {
		int key = A[j];
		int i = j-1;
		while(i>=0 && A[i]>key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}
