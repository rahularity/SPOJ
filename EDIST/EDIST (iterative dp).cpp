#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z){
	return min(min(x,y) , z);
}

int editDistance(string str1, string str2, int len1, int len2){
	
	int arr[len1+1][len2+1];
	
	for(int i = 0 ; i<=len1 ; i++){
		for(int j = 0 ; j<=len2 ; j++){
			if(i==0) arr[i][j] = j;
			
			else if(j==0) arr[i][j] = i;
			
			else if(str1[i-1] == str2[j-1])
			    	arr[i][j] = arr[i-1][j-1];
				
			else{
				arr[i][j] = 1 + min(arr[i-1][j-1],
									arr[i-1][j],
									arr[i][j-1]);
			}	
		}
	}
	return arr[len1][len2];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		
		string str1, str2;
		cin>>str1>>str2;
		
		cout<<editDistance(str1, str2, str1.length(), str2.length())<<endl;
		
	}
}
