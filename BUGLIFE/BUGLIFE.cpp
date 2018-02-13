//Link to the problem statement => http://www.spoj.com/problems/BUGLIFE/
// BUGLIFE - A Bug’s Life PROBLEM FROM SPOJ (Detection Of Bipartite Graph)
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool bugLife2(ll g[][2001], ll s, int color[], ll bugs){    //function to check if adjacent nodes has different color or not (BFS)
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		ll w = q.front();
		q.pop();

		for(ll i=0 ; i<=bugs ; i++){
			if(g[w][i] && color[i]==-1){
				color[i] = !color[w];                            // if adjacent node is not colored yet then color it with opposite color to that of it's parent node
				q.push(i);
			}
			else if(g[w][i] && color[i]==color[w])             //if adjacent nodes has same color then return false
			return false;
		}
	}

	return true;
}

bool bugLife(ll g[][2001], ll bugs){
	int color[bugs+1];                                     //array to store the color of each node
	for(ll i = 0 ; i<=bugs ; i++)
	color[i] = -1;

	for(ll i = 1 ; i<=bugs ; i++){
		if(color[i] == -1){
			if(bugLife2(g,i,color,bugs) == false)             //if adjacent nodes has same color then return false
				return false;
		}
	}

	return true;
}

int main(){
	int scenarios;
	cin>>scenarios;

	for(ll k = 1 ; k<=scenarios ; k++){
		ll bugs,interactions;
		cin>>bugs>>interactions;

		ll g[bugs+1][2001] = {0};


		ll bug1,bug2;
		for(ll i=0 ; i<interactions ; i++){                //using adjacency matrix to store the graph
			cin>>bug1>>bug2;
			g[bug1][bug2] = 1;
			g[bug2][bug1] = 1;                               //because it is a undirected graph
		}

		if(bugLife(g,bugs)){
			cout<<"Scenario #"<<k<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}else{
			cout<<"Scenario #"<<k<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
	}
}
