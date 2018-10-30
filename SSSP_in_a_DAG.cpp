    //All trees with directed edges are automatically DAGs as they do not contains any cycle.
    //Single Source Shortest Path(SSSP) can be solved efficiently on DAG in O(V+E).
    //SSSP on DAG
     
    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back 
    #define MAX 100001
    #define INF (1<<20)
    #define pii pair<int, int>
     
    bool visited[MAX];
    vector<pii> G[MAX];
    vector<int> topological;
    int D[MAX];
     
    void dfs(int node){
     
    	visited[node] = true;
     
    	for(int i=0 ; i<G[node].size() ; i++){
     
    		int current = G[node][i].first;
    		if(!visited[current])
    			dfs(current);
     
    	}
     
    	topological.pb(node);
     
    }
     
     
    void relax(int u, int v, int w){
    	if(D[v] > D[u] + w){
    		D[v] = D[u] + w;
    	}
    }
     
    int main() {
     
    	int edges,nodes;
    	cin>>nodes>>edges;
     
    	memset(visited,false,sizeof(visited));
    	//memset(D,INF,sizeof(D));
    	for(int i=0 ; i<nodes ; i++)
    		D[i] = INF;
     
    	for(int i=0 ; i<edges ; i++){
    		int u,v,w;
    		cin>>u>>v>>w;
    		G[u].pb(pii(v,w));
    	}
     
     
    	for(int i=0 ; i<nodes ; i++){
    		if(!visited[i])
    			dfs(i);
    	}
     
    	reverse(topological.begin(), topological.end());
     
    	for(int i=0 ; i<topological.size() ; i++){
    		cout<<topological[i]<<" ";
    	}
    	cout<<endl;
     
    	D[0] = 0;
    	for(int i=0 ; i<topological.size() ; i++){
    		int u = topological[i];
    		for(int j=0 ; j<G[u].size() ; j++){
    			int v = G[u][j].first;
    			int w = G[u][j].second;
    			relax(u, v, w);
    		}
    	}
     
    	//distance of all nodes from node 0.
    	for(int i=0 ; i<nodes ; i++){
    		cout<<D[i]<<" ";
    	}
     
    	return 0;
    }
