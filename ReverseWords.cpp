#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
 * Function Name: 	IsWhiteSpace
 * Description:		Returns true if the input character is whitespace
 */
bool IsWhiteSpace(char c)
{
	bool isWhiteSpace = false;
	
	if(c == ' ' 
	   || c == '\n'
	   || c == '\t'
	   || c == '\v'
	   || c == '\f'
	   || c == '\r')
		isWhiteSpace = true;
	
	return isWhiteSpace;
}

/*
 * Function Name: 	IsStringWhiteSpace
 * Description:		Returns false if any whitespace character is found.
 */
bool IsStringWhiteSpace(string s)
{
	unsigned int index = 0;
	
	bool isStringWhiteSpace = true;
	
	while(index < s.size() && isStringWhiteSpace == true)
	{
		if(IsWhiteSpace(s[index]) == false )
		{
			isStringWhiteSpace = false;
		}
		
		++index;
	}
	
	return isStringWhiteSpace;
}

/*
 * Function Name:	ParseWord
 * Description:		finds a single word in a string. a word is separated by whitespace
 */
string ParseWord(string s, unsigned int &lineIndex)
{
	unsigned int wordIndex = lineIndex;
	string word;
	
	while(wordIndex < s.size()  
		  && IsWhiteSpace(s[wordIndex]) == false)
	{
		++wordIndex;
	}
	
	word = s.substr(lineIndex, wordIndex-lineIndex);
	
	lineIndex = lineIndex + word.size();
	
	return word;
}

/*
 * Function Name:	ParseString
 * Description:		finds all the words in a string. a word is separated by whitespace
 */
vector<string> ParseString(string s)
{
	unsigned int index = 0;
	
	vector<string> w;
	
	while(index < s.size())
	{
		if(IsWhiteSpace(s[index]) == false)
		{
			w.push_back(ParseWord(s,index));
		}
		
		++index;
	}
	
	return w;
}

/*
 * Function Name:	ReverseString
 * Description:		reverses the order of words in the string
 */
string ReverseString(vector<string> vs)
{
	int index = 0;
	string stringReverse = "";

	for(index = vs.size()-1; index >= 0; --index)
	{
		stringReverse.append(vs[index]);
		
		if(index > 0)
		{
			stringReverse.append(" ");
		}		
	}
	
	return stringReverse;
}

int main(int argc,char *argv[])
{
	string inputString;
	string stringInput = "";
	vector<string> vInputString;
	
	ifstream inputFile(argv[1]);
	
	if(inputFile.is_open() == false)
	{
		cout << "Error with input file" << endl;
	}
	else
	{
		while(getline(inputFile,inputString))
		{
			if(IsStringWhiteSpace(inputString) == false)
			{
				vInputString = ParseString(inputString);
				stringInput = ReverseString(vInputString);
				cout << stringInput << endl;
			}
		}
		
		inputFile.close();
	}

	return 0;
}