//Link to the problem statement => http://www.spoj.com/problems/EDIST/
//EDIT DISTANCE PROBLEM FROM SPOJ (Top-Down iterative DP approach)  
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
			    	arr[i][j] = arr[i-1][j-1];           //when characters are equal then copy diagonal up value from the table
				
			else{
				arr[i][j] = 1 + min(arr[i-1][j-1],       //when characters are not equal then add one to the minimum of top,left or diagonal values
									arr[i-1][j],
									arr[i][j-1]);
			}	
		}
	}
	return arr[len1][len2];                             //the answer is the value of the last element of the table as every character is now compared. 
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
