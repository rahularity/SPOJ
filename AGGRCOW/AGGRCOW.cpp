   // Link to the problem statement =>  http://www.spoj.com/problems/AGGRCOW/
   // AGGRESSIVE COWS PROBLEM FROM SPOJ (Implementation using binary search technique)
    #include<bits/stdc++.h>
    using namespace std;
    
    //This function is greedy approach to check weather mid can be a possible answer or not 
    bool check(int cows,long long positions[],int n,long long mid){
    	int count = 1;
    	long long last_position = positions[0];    // putting first cow in the zeroth index and then checking to settle other cows
     
    	for(int i=1;i<n;i++){
    		if(positions[i] - last_position >= mid){
    			last_position = positions[i];
    			count++;
    		}
     
    		if(count == cows){                    // when count is equal to number of cows then all cows can be settled at a distance of at least mid
    			return true;
    		}
    	}
    	return false;
    }
     
    int main(){
    	int t;
    	cin >> t;
    	while(t--){
    		int n,c;
    		cin >> n >> c;
     
    		long long positions[n];
    		for(int i=0;i<n;i++){
    			cin >> positions[i];
    		}
    		sort(positions,positions+n);
    		
    		//we know the possible distance between any two cows can be a max of 'far most positions' and minimum of 'first two consecutive' 
    		long long start = positions[1] - positions[0];
    		long long end = positions[n-1] - positions[0];
     
    		long long ans = -1;
     
     		//applying binary search to find the correct answer between two boundary options (i.e., start and end)
    		while(start<=end){
    			long long mid = start + (end-start)/2;
    			if(check(c,positions,n,mid)){
    				ans = mid;
    				start = mid+1;
    			}else{
    				end = mid-1;
    			}
    		}
    		cout << ans <<endl;
    	}
     
    	return 0;
    }
