//Link to the problem statement => http://www.spoj.com/problems/INVCNT/
//INVERSION COUNT PROBLEM FROM SPOJ (MERGE-SORT tecnique)  
#include<bits/stdc++.h>
#define ll long long                            //macro for long long
using namespace std;

//merging two sorted arrays
ll merge(ll arr[], ll start, ll mid,  ll end){
	ll inv_count = 0;
	ll len1 = mid-start+1;
	ll len2 = end-mid;
	ll first[len1];
	ll second[len2];

	for(ll i = 0 ; i<len1 ; i++){
		first[i] = arr[start+i];
	}
	for(ll i = 0 ; i<len2 ; i++){
		second[i] = arr[mid+1+i];
	}
	
	ll i=0, j=0, k=start;
	while(i<len1 && j<len2){
		if(first[i] > second[j]) {
			arr[k] = second[j];
			j++;
			k++;
			//the line below counts the number of inversions.....logic is--if an element of left array is greater than an element of right array then it is definite that rest of the elements from the left array are also greater than right array.
			inv_count = inv_count + (len1-i);	
			}
		
		else{
			arr[k] = first[i];
			i++;
			k++;
		}
		
	}
	
	while(i<len1){
			arr[k] = first[i];
			i++;
			k++;
	}
	
	while(j<len2){
			arr[k] = second[j];
			j++;
			k++;
		}
		
	return inv_count;
}


ll mergeSort(ll arr[], ll start , ll end){
	ll inv_count = 0;
	if(start<end){
		ll mid = start + (end-start)/2;
		inv_count = mergeSort(arr,start,mid);			//counting number of inversions at each step and summing them up.
		inv_count += mergeSort(arr,mid+1,end);
		inv_count += merge(arr,start,mid,end);
	}
	return inv_count;
}

int main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;

		ll arr[n];
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}
		cout<<mergeSort(arr, 0, n-1)<<endl;
	}	

	return 0;
}
