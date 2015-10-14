#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Topological_Sort(vector<vector<int> > &G);

int main()
{
	vector<string> Gnames(14);
	Gnames[0] = "Trusy";
	Gnames[1] = "Noski";
	Gnames[2] = "Shorty";
	Gnames[3] = "Reitusy";
	Gnames[4] = "Pakhovaya Zashita";
	Gnames[5] = "Shtany";
	Gnames[6] = "Kon'ki'";
	Gnames[7] = "Shitki dlya nog";
	Gnames[8] = "Futbolka";
	Gnames[9] = "Nagrudnik";
	Gnames[10] = "Sviter";
	Gnames[11] = "Maska";
	Gnames[12] = "Lovushka";
	Gnames[13] = "Shitok";
	
	vector<vector<int> > G;
	vector<int> inner;
	
	inner.push_back(2);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(3);
	inner.push_back(4);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(5);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(5);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(6);
	inner.push_back(10);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(7);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(12);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(9);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(10);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(11);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(12);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(13);
	G.push_back(inner);
	inner.clear();
	
	inner.push_back(-1);
	G.push_back(inner);
	inner.clear();
	
	vector<int> linear(G.size());
	linear = Topological_Sort(G);
	
	for(int i=0; i<linear.size(); i++) cout << Gnames[i] << " ";
	return 0;
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
