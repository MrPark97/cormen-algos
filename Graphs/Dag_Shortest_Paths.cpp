#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INFINITY = 1000000;
const int NIL = 0;

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred);

vector<int> Topological_Sort(vector<vector<int> > &G);

void Dag_Shortest_Paths(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred);

int main()
{
	vector<string> Gnames(20);
	Gnames[0] = "Start";
	Gnames[1] = "Porezat kuryatinu";
	Gnames[2] = "Smeshat marinad";
	Gnames[3] = "Zamarinovat kuryatinu";
	Gnames[4] = "Privarit kuryatinu";
	Gnames[5] = "Narezat chesnok";
	Gnames[6] = "Narezat imbir'";
	Gnames[7] = "Dobavit chesnok, imbir";
	Gnames[8] = "Zakonchit gotovku kurizy";
	Gnames[9] = "Ubrat kurizu";
	Gnames[10] = "Narezat morkov";
	Gnames[11] = "Narezat selderey";
	Gnames[12] = "Promit arahis";
	Gnames[13] = "Tushit morkov, selderey, araxis";
	Gnames[14] = "Vernut kuryatinu";
	Gnames[15] = "Smeshat sous";
	Gnames[16] = "Dobavit sous";
	Gnames[17] = "Tushit poka sous ne zagusteyet";
	Gnames[18] = "Podat gotovoye blyudo";
	Gnames[19] = "Finish";
	
	vector<vector<int> > G;
	vector<int> inner;
	
	inner.push_back(1);
	inner.push_back(2);
	inner.push_back(6);
	inner.push_back(5);
	inner.push_back(10);
	inner.push_back(11);
	inner.push_back(12);
	inner.push_back(15);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(7);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(7);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(7);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(8);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(9);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(13);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(13);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(13);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(13);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(14);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(16);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(16);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(17);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(18);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(19);
	G.push_back(inner);
	inner.clear();
	
	G.push_back(inner);
	inner.clear();
	
	vector<vector<int> > Gp;
	vector<int> Gpin(G.size());
	for(int i=0; i<G.size(); i++) {
		Gp.push_back(Gpin);
	}
	Gpin.clear();
	
	Gp[0][1] = -6;
	Gp[0][2] = -2;
	Gp[0][5] = -4;
	Gp[0][6] = -3;
	Gp[0][10] = -4;
	Gp[0][11] = -3;
	Gp[0][12] = -2;
	Gp[0][15] = -3;
	Gp[1][3] = -15;
	Gp[2][3] = -15;
	Gp[3][4] = -4;
	Gp[4][7] = -1;
	Gp[5][7] = -1;
	Gp[6][7] = -1;
	Gp[7][8] = -2;
	Gp[8][9] = -1;
	Gp[9][13] = -4;
	Gp[10][13] = -4;
	Gp[11][13] = -4;
	Gp[12][13] = -4;
	Gp[13][14] = -1;
	Gp[14][16] = -1;
	Gp[15][16] = -1;
	Gp[16][17] = -3;
	Gp[17][18] = -1;
	Gp[18][19] = 0;
	
	vector<int> shortest(G.size());
	vector<int> pred(G.size());
	Dag_Shortest_Paths(G, 0, Gp, shortest, pred);
	cout << "time is " << -shortest[G.size()-1] << "\n";
	int current = pred[G.size()-1];
	vector<int> path;
	while(pred[current]) {
		path.push_back(current);
		current = pred[current];
	}
	for(int i=path.size()-1; i>=0; i--) {
		cout << Gnames[path[i]] << "\n";
	}
	return 0;
}

void Dag_Shortest_Paths(vector<vector<int> > &G, int s, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	vector<int> linear(G.size());
	linear = Topological_Sort(G);
	for(int i=0; i<G.size(); i++) {
		if(i!=s) shortest[i] = INFINITY;
		else shortest[i] = 0;
		pred[i] = NIL;
	}
	for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G[linear[i]].size(); j++) {
			Relax(linear[i], G[linear[i]][j], Gp, shortest, pred);
		}
	}
}

void Relax(int u, int v, vector<vector<int> > &Gp, vector<int> &shortest, vector<int> &pred) {
	if(shortest[u]+Gp[u][v] < shortest[v]) {
		shortest[v] = shortest[u]+Gp[u][v];
		pred[v] = u;
	}
}

vector<int> Topological_Sort(vector<vector<int> > &G) {
	vector<int> in_degree(G.size());
	vector<int> linear;
	
	for(int i=0; i<in_degree.size(); i++) {
		in_degree[i] = 0;
	}
	
	for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G[i].size(); j++) {
			if(G[i][j] >=0) in_degree[G[i][j]]++;
		}
	}
	
	vector<int> next;
	for(int i=0; i<in_degree.size(); i++) {
		if(in_degree[i] == 0) next.push_back(i);
	}
	while(next.size() > 0) {
		int u = next[0];
		linear.push_back(u);
		next.erase(next.begin());
		for(int i=0; i<G[u].size(); i++) {
			in_degree[G[u][i]]--;
			if(in_degree[G[u][i]] == 0) next.push_back(G[u][i]);
		}
	}
	return linear;
}
