#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z){
	return min(min(x,y) , z);
}

map< pair<int,int>, int > memo;

int editDistance(string str1, string str2, int len1, int len2){
	pair<int,int> lengthPair = make_pair(len1,len2);
	
	if(memo.find(lengthPair) != memo.end()){
		return memo[lengthPair];
	}
	
	if (len1 == 0) return len2;
	if (len2 == 0) return len1;
	
	if( str1[len1-1] == str2[len2-1] ){
		memo[lengthPair] = editDistance(str1, str2, len1-1, len2-1);
		return editDistance(str1, str2, len1-1, len2-1);
	}
		
	
	int ans = 1 + min(editDistance(str1, str2, len1-1, len2-1),      //replace a character from str1 to make it same as str2...... (match happened so decrease both strings by one)
                   editDistance(str1, str2, len1-1, len2),          //delete one character from str1 and then compare upcoming characters to match with same charter of str2 (no match happened in this case thats why only str1 is decreased).
				   editDistance(str1, str2, len1, len2-1));        //adding a new character to str1 to match the character of str2 and after matching the str1 will remain of same size and str2 decrease by 1
	
	memo[lengthPair] = ans;
	return ans;
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		memo.clear();
		string str1,str2;
		cin>>str1>>str2;
		
		cout<<editDistance( str1, str2, str1.length(), str2.length() )<<endl;
	}
}
