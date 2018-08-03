/*
	find(“string”): Searches the string for the first occurrence of the substring specified in arguments. It returns the position of the first occurrence of substring.

	find_first_of(“string”): Searches the string for the first character that matches any of the characters specified in its arguments. It returns the position of the first character that matches.

	find_last_of(“string”): Searches the string for the last character that matches any of the characters specified in its arguments. It returns the position of the last character that matches.

	rfind(“string”): Searches the string for the last occurrence of the substring specified in arguments. It returns the position of the last occurrence of substring
	
	insert(pos_to_begin,string_to_insert): This function inserts the given substring in the string. It takes two arguments, first the position from which you want to insert the substring and second the substring.
	
	clear(): This function clears all the characters from the string. The string becomes empty (length becomes 0) after this operation.

	empty(): Tests whether the string is empty. This function return a Boolean value.
	
	
*/






// C++ program to demonstrate various function string class
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // various constructor of string class
 
    // initialization by raw string
    string str1("first string");			// str1 = "first string" 
    // initialization by another string
    string str2(str1);						// str2 = "first string"
 
    // initialization by character with number of occurence
    string str3(5, '#');					// str3 = "#####"
 
    // initialization by part of another string
    string str4(str1, 6, 6); //    from 6th index (second parameter)	// str4 = "string"
                             // 6 characters (third parameter)
 
    // initialization by part of another string : iteartor version
    string str5(str2.begin(), str2.begin() + 5);			//str5 = "first"
 
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
 
    //  assignment operator
    string str6 = str4;				// str6 = "string"
 
    // clear function deletes all character from string
    str4.clear();					//str4 = ""    1467000109133432
 
    //  both size() and length() return length of string and
    //  they work as synonyms
    int len = str6.length(); // Same as "len = str6.size();"
 
    cout << "Length of string is : " << len << endl;
 
    // a particular character can be accessed using at /
    // [] operator
    char ch = str6.at(2); //  Same as "ch = str6[2];"
 
 
    cout << "third character of string is : " << ch << endl;
 
    //  front return first character and back returns last charcter
    //  of string
 
    char ch_f = str6.front();  // Same as "ch_f = str6[0];"
    char ch_b = str6.back();   // Same as below
                               // "ch_b = str6[str6.length() - 1];"
 
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl;
 
    // c_str returns null terminated char array version of string
    const char* charstr = str6.c_str();
    printf("%s\n", charstr);
 
    // append add the argument string at the end
    str6.append(" extension");
    //  same as str6 += " extension"
 
    // another version of appends, which appends part of other
    // string
    str4.append(str6, 0, 6);  // at 0th position 6 character
 
    cout << str6 << endl;
    cout << str4 << endl;
 
    //  find returns index where pattern is found.
    //  If pattern is not there it returns predefined
    //  constant npos whose value is -1
 
    if (str6.find(str4) != string::npos)
        cout << "str4 found in str6 at " << str6.find(str4)
             << " pos" << endl;
    else
        cout << "str4 not found in str6" << endl;
 
    //  substr(a, b) function returns a substring of b length
    //  starting from index a
    cout << str6.substr(7, 3) << endl;
 
    //  if second argument is not passed, string till end is
    // taken as substring
    cout << str6.substr(7) << endl;
 
    //  erase(a, b) deletes b character at index a
    str6.erase(7, 4);
    cout << str6 << endl;
 
    //  iterator version of erase
    str6.erase(str6.begin() + 5, str6.end() - 3);
    cout << str6 << endl;
 
    str6 = "This is a examples";
 
    //  replace(a, b, str)  replaces b character from a index by str
    str6.replace(2, 7, "ese are test");
 
    cout << str6 << endl;
 
    return 0;
}

