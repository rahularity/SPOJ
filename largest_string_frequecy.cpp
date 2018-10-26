    #include <bits/stdc++.h>
    using namespace std;
     
    #define pii pair<string,int>
     
     
    bool sort_by_second(pii &p1, pii &p2){
    	return p1.second > p2.second;
    }
     
     
    map<string, int> p;
     
     
    int main() {
     
    	int t;
    	cin>>t;
     
    	while(t--){
     
    		p.clear();
    		int n;
    		cin>>n;
    		string s;
     
    		int max = 1; 
     
    		pii pp[n];
     
    		for(int i=0 ; i<n ; i++){
    			cin>>s;
     
    			if(p.find(s)!=p.end()){
    				p[s]++;
    				if(max<p[s]) max = p[s];
    			}else{
    				p[s] = 1;
    				// if(max<p[s]) max = p[s];
    			}
    		}
     
    		auto itr = p.begin();
    		while(itr != p.end()){
    			if(itr->second == max){
    				cout<<itr->first<<endl;
    				break;
    			}
    			itr++;
    		}
     
    		// sort(pp, pp+n, sort_by_second);
    		// cout<<pp[0].first<<endl;
     
    	}
    	return 0;
    }
