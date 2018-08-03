// rain water trapping between a number of towers of different heights placed consecutively
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0 ; i<n ; i++){
	        cin>>a[i];
	    }
	    
	    int l=a[0], r=a[n-1];
	    
	    int i=0,j=n-1,ans=0;
	    int max_left = l, max_right = r;
	    
	    while(i<j){
	        l = a[i]; r=a[j];
	        
	        if(l>r){
	            j--;
	            if(a[j]<max_right){
	                ans += max_right-a[j];
	            }else{
	                max_right = a[j];
	            }
	            
	        }else{
	            
	            i++;
	            if(a[i]<max_left){
	                ans += max_left-a[i];
	            }else{
	                max_left = a[i];
	            }
	            
	        }
	        
	    }
	    
	    cout<<ans<<endl;
	    
	}
	
	
	return 0;
}
