    //Topological sorting 
    //only Directed Acyclic Graph(DAG) has a valid topological ordering.
    //Algorithm : begin with any node exploring only unvisited nodes....on recursive callback of the DFS add current node to the topological ordering in reverse order
     
    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back 
    #define MAX 100001
     
    bool visited[MAX];
    vector<int> G[MAX];
    vector<int> topological;
     
    void dfs(int node){
     
    	visited[node] = true;
     
    	for(int i=0 ; i<G[node].size() ; i++){
     
    		int current = G[node][i];
    		if(!visited[current])
    			dfs(current);
     
    	}
     
    	topological.pb(node);
     
    }
     
     
    int main() {
     
    	int edges,nodes;
    	cin>>nodes>>edges;
     
    	memset(visited,false,sizeof(visited));
     
    	for(int i=0 ; i<edges ; i++){
    		int u,v;
    		cin>>u>>v;
    		G[u].pb(v);
    	}
     
     
    	for(int i=0 ; i<nodes ; i++){
    		if(!visited[i])
    			dfs(i);
    	}
     
    	reverse(topological.begin(), topological.end());
    	for(int i=0 ; i<topological.size() ; i++){
    		cout<<topological[i]<<" ";
    	}
     
    	return 0;
    }

