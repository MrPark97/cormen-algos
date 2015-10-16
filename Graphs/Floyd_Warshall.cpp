#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INFINITY = 1000000;

const int NIL = -1;

void Floyd_Warshall(vector<vector<int> > &G, vector<vector<vector<int> > > &shortest, vector<vector<vector<int> > > &pred);

int main()
{
	vector<vector<int> > G;
	vector<int> inner(4, INFINITY);
	for(int i=0; i<inner.size(); i++) {
		G.push_back(inner); 
	}
	
	vector<vector<vector<int> > > shortest, pred;
	vector<vector<int> > inner_matrix;
	vector<int> inner_inner(inner.size()+1);
	for(int i=0; i<inner.size(); i++) {
		inner_matrix.push_back(inner_inner);
	}
	for(int i=0; i<inner.size(); i++) {
		shortest.push_back(inner_matrix);
		pred.push_back(inner_matrix);
	}
	inner.clear();
	inner_matrix.clear();
	inner_inner.clear();
	
	G[0][0] = 0;
	G[0][1] = 3;
	G[0][2] = 8;
	G[1][1] = 0;
	G[1][3] = 1;
	G[2][1] = 4;
	G[2][2] = 0;
	G[3][0] = 2;
	G[3][2] = -5;
	G[3][3] = 0;
	
	Floyd_Warshall(G, shortest, pred);
	for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G.size(); j++) {
			cout << pred[i][j][4] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void Floyd_Warshall(vector<vector<int> > &G, vector<vector<vector<int> > > &shortest, vector<vector<vector<int> > > &pred) {
	for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G.size(); j++) {
			shortest[i][j][0] = G[i][j];
			if(G[i][j] < INFINITY && i!=j) pred[i][j][0] = i;
			else pred[i][j][0] = NIL;
		}
	}
	for(int x=1; x<G.size()+1; x++) {
		for(int u=0; u<G.size(); u++) {
			for(int v=0; v<G.size(); v++) {
				if(shortest[u][v][x-1] > (shortest[u][x-1][x-1]+shortest[x-1][v][x-1])) {
					shortest[u][v][x] = shortest[u][x-1][x-1] + shortest[x-1][v][x-1];
					pred[u][v][x] = pred[x-1][v][x-1];
				} else {
					shortest[u][v][x] = shortest[u][v][x-1];
					pred[u][v][x] = pred[u][v][x-1];
				}
			}
		}
	}
}
