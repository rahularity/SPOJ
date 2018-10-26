    //finding shortest path in an undirected graph using BFS
    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back 
    #define MAX 100001
     
    vector<int> G[MAX];
    int parent[MAX];
    bool visited[MAX];
     
     
    void bfs(int s){
     
    	queue<int> q;
    	q.push(s);
    	visited[s] = true;
     
    	while(!q.empty()){
    		int node = q.front();
    		q.pop();
     
    		for(int i=0 ; i<G[node].size() ; i++){
    			int curr = G[node][i];
     
    			if(!visited[curr]){
    				parent[curr] = node;
    				visited[curr] = true;
    				q.push(curr);
    			}
     
    		}
    	}
    } 
     
     
    void construct_shortest_path(int s, int e){
     
    	vector<int> ans;
    	for(int i=e ; i!=-1 ; ){
    		ans.pb(i);
    		i = parent[i];
    	}
     
    	reverse(ans.begin(), ans.end());
     
    	int i;
    	for(i=0 ; i<ans.size()-1 ; i++){
    		cout<<ans[i]<<" -> ";
    	}
    	cout<<ans[i];
     
    }
     
     
    void shortest_path(int s, int e){
     
    	bfs(s);
    	construct_shortest_path(s,e);
     
    }
     
     
     
    int main() {
     
    	memset(visited, false, sizeof(visited));
    	memset(parent, -1, sizeof(parent));
     
    	int nodes, edges;
    	cin>>nodes>>edges;
     
    	for(int i=0; i <edges ; i++){
    		int u,v;
    		cin>>u>>v;
     
    		G[u].pb(v);
    		G[v].pb(u);
     
    	}
     
    	int start,end;
    	cin>>start>>end;
     
    	shortest_path(start,end);
     
    	return 0;
    }
     
     
