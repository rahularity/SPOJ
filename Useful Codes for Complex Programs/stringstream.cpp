// CPP program to count words in a string
// using stringstream.
#include <bits/stdc++.h>
using namespace std;
 
int countWords(string str)
{
    // breaking input into word using string stream
    stringstream s(str); // Used for breaking words
    string word; // to store individual words
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}


void printFrequency(string st)
{
    // each word it mapped to it's frequency
    map<string, int> FW;
    stringstream ss(st); // Used for breaking words
    string Word; // To store individual words
 
    while (ss >> Word)
        FW[Word]++;
 
    map<string, int>::iterator m;
    for (m = FW.begin(); m != FW.end(); m++)
        cout << m->first << " -> "
             << m->second << "\n";
}
 
// Driver code
int main()
{
    string s = "geeks for geeks geeks " 
               "contribution placements "
			   "rahul pandey";
    cout << " Number of words are: " << countWords(s);
    
    
    string s1 = "Geeks For Geeks Ide";
    printFrequency(s1);
    return 0;
}

