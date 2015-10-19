#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > Compute_LCS_Table(string X, string Y);

string Assemble_LCS(string X, string Y, vector<vector<int> > &l, int i, int j);

int main()
{
	string X("CATCGA");
	string Y("GTACCGTCA");
	vector<vector<int> > l;
	vector<int> inner(Y.size()+1);
	for(int i=0; i<=X.size(); i++) {
		l.push_back(inner);
	}
	inner.clear();
	l = Compute_LCS_Table(X, Y);
	string lcs = Assemble_LCS(X, Y, l, X.size(), Y.size());
	cout << lcs;
	return 0;
}

vector<vector<int> > Compute_LCS_Table(string X, string Y) {
	int m = X.size()+1;
	int n = Y.size()+1;
	vector<vector<int> > l;
	vector<int> inner(n);
	for(int i=0; i<m; i++) {
		l.push_back(inner);
	}
	inner.clear();
	
	for(int i=0; i<m; i++) l[i][0] = 0;
	for(int j=0; j<n; j++) l[0][j] = 0;
	
	for(int i=1; i<m; i++) {
		for(int j=1; j<n; j++) {
			if(X[i-1] == Y[j-1]) l[i][j] = l[i-1][j-1]+1;
			else {
				if(l[i][j-1] > l[i-1][j]) l[i][j] = l[i][j-1];
				else l[i][j] = l[i-1][j];
			}
		}
	}
	
	return l;
}

string Assemble_LCS(string X, string Y, vector<vector<int> > &l, int i, int j) {
	if(l[i][j] == 0) return "";
	else {
		if(X[i-1] == Y[j-1]) return (Assemble_LCS(X, Y, l, i-1, j-1)+X[i-1]);
		else {
			if(l[i][j-1] > l[i-1][j]) return Assemble_LCS(X, Y, l, i, j-1);
			else return Assemble_LCS(X, Y, l, i-1, j);
		}
	}
}
