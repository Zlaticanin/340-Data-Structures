/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <map>
#include <algorithm>

using namespace std;

#define NO_ITEMS 3 // words per line
#define ITEM_W 16 // number of spaces

// functions
void get_words (map <string, int>&);
void print_words (const map <string, int>&);
void clean_entry (const string&, string&);
void to_lower(char&);

int main()
{
  map<string, int> cleanedWords; // map to store cleaned words
  get_words(cleanedWords); // calling the get_words function
  print_words(cleanedWords); // caling the print_words cuntion

  return 0;
}

// gets a word from the input stream and removes its punctuation marks
void get_words(map<string, int> &m)
{
  string nonClean;
  string clean;
  
  while(cin) // while there is input
    {
      cin >> nonClean; // read one word at the time
      clean_entry(nonClean, clean); // call the clean method
      if(clean.size() > 0)
	m[clean]++;
    }
}

// prints the final list of words and their frequencies, it also prints the number of nonempty words and the number of distinct words in the input stream  
void print_words(const map<string, int> &m)
{
  map<string, int>::const_iterator it;

  int inputCount = 0;
  int cleanedWords = 0;

  for(it = m.begin(); it != m.end(); it++)
    {
      cout << setw(ITEM_W) << left << it->first << " : "  << setw(2) <<  it->second << "\t"; // to format the correct output of map
      inputCount++;
      cleanedWords = cleanedWords + it->second;

      if (inputCount % NO_ITEMS == 0 && inputCount != 0) // to start a new line after NO_ITEMS has been reached
	cout << "\n";

    }
  cout << "\n";
  cout << "no of words in input stream  : " << cleanedWords << "\n";
  cout << "no of words in output stream : " << m.size() << "\n";
}

// to set letters to be lowercase
void to_lower(char &k)
{
  k = tolower(k);
}

// cleans a word from its punctuation marks, the first argument is the original word in the input stream and the second argument contains the same word after cleaning  
void clean_entry(const string &s1, string &s2)
{
  bool startToRead = false;
  unsigned int beginning = 0;
  unsigned int end = 0;

  for(unsigned int j = 0; j < s1.size(); j++)
    {
      end++;
      if(isalnum(s1[j]) > 0) // checking to see if it's alphanumeric
	startToRead = true;
      if(startToRead)
	{
	  if(isalnum(s1[j]) <= 0) // checking to see if it's not alphanumeric
	    {
	      end--;
	      break;
	    }
	}
      else
	beginning++;
    }
  s2 = s1.substr(beginning, end - beginning); // return cleaned word
  for_each(s2.begin(), s2.end(), to_lower); // set letters to be lowercase
} 
