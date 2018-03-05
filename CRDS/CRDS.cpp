// Link to the problem statement => http://www.spoj.com/problems/CRDS/
// #arithmatic progression
// CRDS - Cards PROBLEM FROM SPOJ (Simple AP)

//if we look at the sequence we will find a very easy pattern
// for first level cards required = 2  (with no card on the base)
// for second level cards required = (2 + 1) + 4   (1 is the base card for level 1)
// for third level cards required =  (2 + 1) + (4 + 2) + 6  => also written as 1+2 + 2+4+6 => n(n-1)/2 + n/2(2 + 2n)


#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int test_cases;
	cin>>test_cases;
	
	while(test_cases--){
		
		ll n;
		cin>>n;
		
		cout<<((3*n*n + n)/2)%1000007<<endl;  //output is in modulo of 1000007
		return 0;
	}
}
