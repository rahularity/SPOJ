    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back 
    #define MAX 100001
    #define INF (1<<20)
    #define pii pair<int, int> 
    vector<pii> G[MAX];
     
    struct comp{
    	bool operator()(pii &p1, pii &p2){
    		return p1.second > p2.second;
    	}	
    };
     
     
     
     
    priority_queue<pii, vector<pii>, comp> Q;
    int D[MAX];
    bool visited[MAX];
     
    void relax(int u, int v, int w){
    	if(D[v]>D[u]+w){
    		D[v] = D[u]+w;
    	}	
    }
     
    int main() {
     
    	int nodes, edges;
    	cin>>nodes>>edges;
     
    	for(int i=0; i <edges ; i++){
    		int u,v,w;
    		cin>>u>>v>>w;
     
    		G[u].pb(pii(v,w));
    		G[v].pb(pii(u,w));
     
    	}
     
    	int start;
    	cin>>start;
     
    	for(int i=1 ; i<=nodes ; i++)
    		D[i] = INF;
    	D[start] = 0;
     
    	Q.push(pii(start,D[start]));
     
    	while(!Q.empty()){
    		int u = Q.top().first;
    		Q.pop();
    		visited[u] = true;
     
    		int size = G[u].size();
     
    		for(int i=0 ; i<size; i++){
     
    			int v = G[u][i].first;
    			int w = G[u][i].second;
     
    			if(!visited[v]){
    				relax(u,v,w);
    				Q.push(pii(v , D[v]));		
    			}
     
     
    		}
    	}
     
     
     
    	for(int i=1 ; i<nodes+1 ; i++){
    		cout<<"Node "<<i<<" has minimum weight equal to "<<D[i]<<endl;
    	}
     
     
     
     
     
    }
