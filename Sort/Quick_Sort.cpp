#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &A, int p, int r);

void Quick_Sort(vector<int> &A, int p, int r);

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
	Quick_Sort(A, 0, A.size()-1);
	
	for(int i=0; i<A.size(); i++) cout << A[i] << " ";
	return 0;
}

void Quick_Sort(vector<int> &A, int p, int r) {
	if(p>=r) return;
	else {
		int q = Partition(A, p, r);
		Quick_Sort(A, p, q-1);
		Quick_Sort(A, q+1, r);
	}
}

int Partition(vector<int> &A, int p, int r) {
	int q = p;
	int temp;
	for(int u=p; u<r; u++) {
		if(A[u] <= A[r]) {
			temp = A[q];
			A[q] = A[u];
			A[u] = temp;
			q++;	
		}
	}
	temp = A[r];
	A[r] = A[q];
	A[q] = temp;
	return q;
}
