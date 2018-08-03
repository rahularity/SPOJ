// The problem is to find the longest consecutive sub-string of a given string which is palindrome.
// example =>  string is - "aabaabababaabbab" 
//			   answer is - "baabababaab"	


#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	
	while(t--){
	    
	    string s;
	    cin>>s;
	    
	    int n = s.length(),x=0,y=0;
	    
	    bool dp[n][n];
	    
	    for(int i=0; i<n ; i++){
	    	for(int j=0 ; j<n ; j++)
	    		if(i==j) dp[i][j] = true;
	    		else dp[i][j] = false;
		}
	        
		int longest_length=0,j;
		
		for(int i=0 ; i<n ; i++){
			j = i+1;
			if(s[i] == s[j]){
					dp[i][j] = true;
					if(j-i > longest_length){
					    longest_length = j-i;
					    x=i;y=j;
					}
		}
	}
	
	for(int k=2 ; k<n ; k++){
		for(int i=0 ; i<n-k ; i++){
			
			j = i+k;
				if(s[i] == s[j] && dp[i+1][j-1] == true){
					dp[i][j] = true;
					
					if(j-i > longest_length){
					    longest_length = j-i;
					    x=i;y=j;
					}	
				}	
		}
		k++;	
	}
	
// 	for(int i=0; i<n ; i++){
// 		for(int j=0 ; j<n ; j++){
// 		cout<<dp[i][j]<<" ";
// 	}cout<<endl;
// 	}
	
	cout<<"length of the longest palindromic sub-string is => "<<longest_length+1<<endl;
	cout<<"longest palindromic sub-string is => "<<s.substr(x,y-x+1)<<endl;
	
	}
	return 0;
}
