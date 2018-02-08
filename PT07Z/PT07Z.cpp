//Link to the problem statement => http://www.spoj.com/problems/PT07Z/
// PT07Z - Longest path in a tree PROBLEM FROM SPOJ (Implementating using DEPTH-FIRST-SEARCH (i.e using stack))
#include<bits/stdc++.h>
#define all(c) (c).begin(),(c).end() 
using namespace std;

pair<int,int> dfs(vector< vector<int> > &tree , int start, int n){

	stack<int> s;
	vector<int> level(n+1);                              // to keep track of level of each node
	bool visited[n+1]= {0};
	int parent[n+1] = {0};
	
	s.push(start);
	
	level[0] = level[start] = 0;                        // level of the starting node is zero.
	
	while(!s.empty()){
		int m = s.top();
		s.pop();
		visited[m] = true;
		
		for(int i=0 ; i<tree[m].size() ; i++){
			int node = tree[m][i];                     //current node under consideration
			if(!visited[node]){
				parent[node] = m;
				s.push(node);
				level[node] = level[parent[node]]+1;  // level of current node is 1 more than the level of it's parent node.
			}
		}
		
	}
	return make_pair(distance(level.begin(),max_element(all(level))), *max_element(all(level)));
}

int main(){
	int n,u,v;
	cin>>n;
	vector< vector<int> > tree(n+1);
	
	for(int i=1 ; i<n; i++){
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	
	pair<int,int> pair1 = dfs(tree,1,n);                  //getting index and value of one of the farthest node when choosing node 1 as starting node.
	pair<int,int> pair2 = dfs(tree,pair1.first,n);        //getting index and value of the second farthest node which was farthest from the node we get from first dfs
	cout<<pair2.second<<endl;
	
	return 0;
}
