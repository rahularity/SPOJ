// splitting a given string by a delimeter

#include<bits/stdc++.h>
using namespace std;

//funtion which splits the sentence by a delimiter
std::vector<std::string> split_the_sentence(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main(){
	
	string text = "Let,me,split,you,from,middle,and,taste,you";
	vector<string> results = split_the_sentence(text,',');
	
	
	for(int i =0 ; i<results.size(); i++)
	cout<<results[i]<<endl;
	
}
