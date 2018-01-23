//Implementation using BREADTH-FIRST-SEARCH (i.e using QUEUE)
#include<bits/stdc++.h>
using namespace std; 

bool bfs(vector<int> g[] , int start , int n){
	int parent[n+1] = {0};               //parent array to keep track of the parent node 
	bool visited[n+1];                   //visited array for keeping track if the current node under consideration is already visited or not. 
	memset(visited,0,sizeof(visited));   //for instantiating each element of visited array as false initially
	
	queue<int> q;
	q.push(start);
	int count=0;                         //count is for counting how many nodes we have seen so far as we have to make sure that we should consider all the nodes
	
	while(!q.empty()){
		int w = q.front();
		q.pop();
		visited[w] = true;
		
		for(int i=0 ; i<g[w].size() ; i++){
			parent[g[w][i]] = w;
			if(visited[g[w][i]]){
				//check if this node is visited by its only child 
				if(parent[w] != g[w][i]) return false; 
				// example 1->2 and 2->1 is given, when 1->2 is detected we say 1 is parent of 2 and set 1 as visited but when 2->1 is detected then we have to make sure that 1 is only visited by 2.
			}else 
				q.push(g[w][i]);
		}
		count++;
	}
	
	if(count!=n)
		return false;
	else 
		return true;
	
}
 
int main()
{
	int n,e;
	cin>>n>>e;
	
	vector<int>  g[n+1];
	
	int start,end;
	for(int i=0 ; i<e ; i++){
		cin>>start>>end;
		g[start].push_back(end);
		g[end].push_back(start);          //As we're asked to implement undirected graph.
	}

	if(bfs(g , 1 , n)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
	
	return 0;
}
