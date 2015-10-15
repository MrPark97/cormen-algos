#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INFINITY = 1000000;
const int NIL = 0;

void Find_Negative_Weight_Cycle(vector<vector<int> > &G, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred, vector<int> &negative_cycle);

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred);

void Bellman_Ford(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred);

int main()
{
	vector<string> Gnames(5);
	Gnames[0] = "s";
	Gnames[1] = "y";
	Gnames[2] = "t";
	Gnames[3] = "z";
	Gnames[4] = "x";
	
	vector<vector<int> > G;
	vector<int> inner;
	
	inner.push_back(1);
	inner.push_back(2);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	inner.push_back(4);	
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(1);
	inner.push_back(3);	
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(0);	
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(2);
	G.push_back(inner);
	inner.clear();
	
	vector<vector<int> > Gp;
	vector<int> Gpin(G.size());
	for(int i=0; i<G.size(); i++) {
		Gp.push_back(Gpin);
	}
	Gpin.clear();
	
	Gp[0][1] = 7;
	Gp[0][2] = 6;
	Gp[1][3] = 9;
	Gp[1][4] = -3;
	Gp[2][1] = 8;
	Gp[2][3] = -4;
	Gp[2][4] = -1;
	Gp[3][0] = 2;
	Gp[3][4] = 7;
	Gp[4][2] = -2;
	
	vector<int> shortest(G.size());
	vector<int> pred(G.size());
	Bellman_Ford(G, 0, Gp, shortest, pred);
	cout << "time is " << shortest[G.size()-1] << "\n";
	int current = G.size()-1;
	vector<int> path;
	while(pred[current]>0 && pred[current] != G.size()-1) {
		path.push_back(current);
		current = pred[current];
	}
	if(pred[current] == 0) path.push_back(current);
	for(int i=path.size()-1; i>=0; i--) {
		cout << Gnames[path[i]] << "\n";
	}
	
	vector<int> cycle;
	Find_Negative_Weight_Cycle(G, Gp, shortest, pred, cycle);
	if(cycle.size() > 0) {
		cout << "have negative cycle:";
		for(int i=0; i<cycle.size(); i++) {
			cout << cycle[i] << "\n";
		}
	} else {
		cout << "have no cycle";
	}
	return 0;
}

void Bellman_Ford(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	for(int i=0; i<G.size(); i++) {
		if(i!=s) {
			shortest[i] = INFINITY;
		} else {
			shortest[i] = 0;
		}
		pred[i] = NIL;
	}
	
	for(int i=0; i<G.size()-1; i++) {
		for(int k=0; k<G.size(); k++) {
			for(int j=0; j<G[k].size(); j++) {
				Relax(k, G[k][j], Gp, shortest, pred);
			}
		}
	}
}

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	if(shortest[u]+Gp[u][v] < shortest[v]) {
		shortest[v] = shortest[u]+Gp[u][v];
		pred[v] = u;
	}
}

void Find_Negative_Weight_Cycle(vector<vector<int> > &G, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred, vector<int> &negative_cycle) {
	bool negative_have = false;
	int x, v;
	for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G[i].size(); j++) {
			if(shortest[i]+Gp[i][G[i][j]] < shortest[G[i][j]]) {
				x = G[i][j];
				negative_have = true;
			}
			if(negative_have) break;
		}
		if(negative_have) break;
	}
	if(!negative_have) return;
	vector<bool> visited(G.size());
	for(int i=0; i<G.size(); i++) visited[i] = false;
	
	while(!visited[x]) {
		visited[x] = true;
		x = pred[x];
	}
	v = pred[x];
	negative_cycle.push_back(x);
	while(v!=x) {
		negative_cycle.insert(negative_cycle.begin(), v);
		v = pred[v];
	}
	return;
}
