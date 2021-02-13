// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class Graph {
	int V;
	list<int> *adj;
	// map<T,list<T>> adj;

public:

	Graph(int v) {
		V = v;
		adj = new list<int>[V];

	}

	void addEdge(int u,int v, bool bidir=true){
		adj[u].push_back(v);
		if(bidir)
			adj[v].push_back(u);
	}

	// void printAdj() {
		
	// 	for(auto p: adj) {
	// 		int city = p.first;
	// 		// T d = p.second;
	// 		cout<<city<<"->";

	// 		for(auto l: p.second){
	// 			cout<<l<<",";
	// 		}
	// 		cout<<endl;
	// 	}
	// }

	void bfs(int src,int dest) {
		queue<int> q;
		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V];

		q.push(src);
		visited[src] = true;

		for(int i=0;i<V;i++){
			parent[i] = -1;
		}

		while(!q.empty()) {
			int node = q.front();
			q.pop();
			cout<<node<<"->";
			for(auto nbr: adj[node]) {
				if(!visited[nbr]) {
					visited[nbr] = true;
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}
		cout<<endl;

		for(int i=0;i<V;i++) {
			// cout<<i<<" node having distance "<<dist[i]<<endl;
		}

		cout<<"Shortest dist is "<<dist[dest]<<endl;
		cout<<"Shortest path is ";

		int temp = dest;
		while(temp!=-1) {
			cout<<temp<<"<--";
			temp = parent[temp];
		}
	}

};

				// 1------0
				// |	  |
				// |	  |
				// 2------4
				// \	  /
				//  \	 /
				//     3
				//   /
				//  /
				// 5
int main() {
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(4,3);
	g.addEdge(3,5);
	// g.addEdge("Delhi","Amritsar");
	// g.addEdge("Delhi","Jaipur");
	// g.addEdge("Delhi","Banglore");
	// g.addEdge("Amritsar","Siachen");
	// g.addEdge("Delhi","Lucknow");
	// g.addEdge("Amritsar","Delhi");
	g.bfs(0,5);
	// g.printAdj();

	return 0;

}

