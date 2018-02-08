//Link to the problem statement => [visit here](http://www.spoj.com/problems/AP2/)
// AP2 - AP - Complete The Series (Easy) PROBLEM FROM SPOJ (Simple Maths)
#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		ll third, thirdLast, sum;
		cin>>third>>thirdLast>>sum;
		
		/* third is (a + 2d)
		   thirdLast is (a + (n-3)d)
		   sum is n/2(2a + (n-1)d)
		   where a = first_element, n = total elements in the sequence, d = difference between two consecutive elements of the sequence */ 
		
		ll n;
		n = (sum*2)/(third+thirdLast);      //Formula after manupulating sum of an AP formula i.e., S = n/2(2a + (n-1)d)
		cout<<n<<endl;
		
		ll d = (thirdLast - third)/(n-5);
		ll first = third - 2*d;
		
		for(ll i = 1 ; i<=n ; i++){
			cout<<(first + (i-1)*d)<<" ";
		}
		cout<<endl;
	}
}
