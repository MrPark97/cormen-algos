#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 1000000;
const int NIL = 0;

int Extract_Min(vector<int> &Q, vector<int> &shortest);

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &p);

void Dijkstra(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred);

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
	
	inner.push_back(2);
	inner.push_back(3);
	inner.push_back(4);	
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(1);	
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(0);	
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	G.push_back(inner);
	inner.clear();
	
	vector<vector<int> > Gp;
	vector<int> Gpin(G.size());
	for(int i=0; i<G.size(); i++) {
		Gp.push_back(Gpin);
	}
	Gpin.clear();
	
	Gp[0][1] = 4;
	Gp[0][2] = 6;
	Gp[1][2] = 1;
	Gp[1][3] = 3;
	Gp[1][4] = 9;
	Gp[2][1] = 2;
	Gp[2][4] = 3;
	Gp[3][0] = 7;
	Gp[3][4] = 5;
	Gp[4][3] = 4;
	
	vector<int> shortest(G.size());
	vector<int> pred(G.size());
	Dijkstra(G, 0, Gp, shortest, pred);
	cout << "time is " << shortest[G.size()-1] << "\n";
	int current = G.size()-1;
	vector<int> path;
	while(pred[current]>0) {
		path.push_back(current);
		current = pred[current];
	}
	if(pred[current] == 0) path.push_back(current);
	for(int i=path.size()-1; i>=0; i--) {
		cout << Gnames[path[i]] << "\n";
	}
	return 0;
}

int Extract_Min(vector<int> &Q, vector<int> &shortest) {
	int mini = 0;
	for(int i=0; i<Q.size(); i++) {
		if(shortest[Q[i]] < shortest[Q[mini]]) mini = i;
	}
	return mini;
}

void Dijkstra(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	vector<int> Q(G.size());
	for(int i=0; i<G.size(); i++) {
		if(i!=s) shortest[i] = INFINITY;
		else shortest[i] = 0;
		pred[i] = NIL;
		
		Q[i] = i;
	}
	vector<int>::iterator p = Q.begin();
	int u, i;
	while(Q.size() > 0) {
		i = Extract_Min(Q, shortest);
		u = Q[i];
		Q.erase(p+i);
		
		for(int j=0; j<G[u].size(); j++) {
			Relax(u, G[u][j], Gp, shortest, pred);
		}
	}
}

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	if(shortest[u]+Gp[u][v] < shortest[v]) {
		shortest[v] = shortest[u]+Gp[u][v];
		pred[v] = u;
	}
}
