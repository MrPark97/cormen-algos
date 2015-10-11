#include <iostream>
#include <vector>
using namespace std;

void Bubble_Sort(vector<int> &A);

int main()
{
	vector<int> A(8);
	A[0] = 35;
	A[1] = 34;
	A[2] = 3;
	A[3] = 21;		
	A[4] = 123;
	A[5] = 1235;
	A[6] = 0;
	A[7] = -1;
	
	Bubble_Sort(A);
	
	for(int i=0; i<A.size(); i++) cout << A[i] << " ";
	
	return 0;
}

void Bubble_Sort(vector<int> &A) {
	int temp;
	for(int i=0; i<A.size()-1; i++) {
		for(int j=A.size()-1; j>i; j--) {
			if(A[j] < A[j-1]) {
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
}
