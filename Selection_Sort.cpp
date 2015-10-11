#include <iostream>
#include <vector>
using namespace std;

void Selection_Sort(vector<int> &A);

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);
	
	Selection_Sort(A);
	
	for(int i=0; i<A.size(); i++) {
		cout << A[i] << " ";
	}

	return 0;
}

void Selection_Sort(vector<int> &A) {
	int min, mini, temp;
	for(int i=0; i<A.size()-1; i++) {
		min = A[i];
		for(int j=i+1; j<A.size(); j++) {
			if(A[j] < min) {min = A[j]; mini = j;}
		}
		temp = A[i];
		A[i] = min;
		A[mini] = temp;
	}
}
