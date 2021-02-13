#include<bits/stdc++.h>
using namespace std; 

template <typename T>
class Graph {
	map<T,list<T> > adj;

public:
	void addEdge(T u,T v, bool bidir) {
		adj[u].push_back(v);
		if(bidir) {
			adj[v].push_back(u);
		}
	}

	int bfs(T src, T dest) {
		queue<T> q;
		map<int,T> dist;
		map<T,T> parent;

		for(auto i: adj) {
			dist[i.first] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()) {
			T node = q.front();
			q.pop();

			for(int nbr: adj[node]) {
				if(dist[nbr]==INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

		T temp = dest;
		while(temp!=src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;
		return dist[dest];

	}
};

int main() {
	Graph<int> g;

	int board[50] = {0};
	board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for(int u=0;u<=36;u++) {
    	for(int dice=1;dice<=6;dice++) {
    		int v = u + dice + board[u+dice];
    		g.addEdge(u,v,false);
    	}
    }
    cout<<"The shortest dist is "<<g.bfs(1,36)<<endl;
    return 0;
}