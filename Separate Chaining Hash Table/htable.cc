/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
HT::HT(const unsigned &hs) {
  hTable.resize(hs);
  hsize = hs; // initializing the size of the hTable
}

HT::~HT() {
  hTable.clear(); // frees the memory for the vector containers for the hash table
  pTable.clear(); // frees the memory for the vector containers for the pointer table
}

// This public function inserts the record of the item e:(key, desc, num) in the hash table. 
void HT::insert(const Entry &e) {
  int j = hash(e.key);
  list<Entry> &l = hTable[j]; // to compare the key of the record e with the keys of the elements in the list container in hash table position j

  auto success = find_if(l.begin(), l.end(), [e](const Entry& e2) {
					       return e2.key == e.key;});

  if(success != l.cend()) // checking to see if the key is duplicate
    cout << " not inserted - duplicate key!!!" << "\n";
  else
    {
      cout << " entry = " << setw(2) << right << j << "\n";
      hTable[j].push_front(e);
      pTable.push_back(&hTable[j].front());
    }
}

// This public function searches the hash table for a record with key s
void HT::search(const string &s) {
  int j = hash(s);
  list<Entry> &l = hTable[j];

  auto success = find_if(l.begin(), l.end(), [s](const Entry& e3) {
					       return e3.key == s;});

  if(success != l.cend()) // printing the info for the record
    cout << " ==> number: " << setw(4) << right << success->num << " - item: " << success->desc << "\n";
  else
    cout << " not in table!!" << "\n"; // print an error message
}

// This public function prints the subscript and the contents of all (and only) the active records in the hash table
void HT::hTable_print() {
  int count = 0;
  bool first = true; // to check the first line
  for(unsigned j = 0; j < hTable.size(); j++)
    {
      count++;
      if(hTable[j].empty())
	 {
           count++;
           if(count - j == 1)
             cout << "\n";
	   if(first) // to print a new line for the first
	     cout << "\n";
	 }
      else
	{
	  count = j;
	  for( auto it = hTable[j].begin(); it != hTable[j].end(); it++)
	    {
	      cout << setw(4) << right << j << setw(1) << ": "
		   << setw(4) << it->key << "  -  "
		   << setw(4) << right << it->num << "  -  "
		   << setw(4) << it->desc << "\n";
	    }
        }
      first = false; // if the first is not found don't print a new line return false
    }
}

// component for sorting
bool cmp(Entry *p, Entry *q) {
  return(p->key.compare(q->key) < 0);
}

// This public function prints the contents of all (and only) the active records in the hash table
void HT::pTable_print() {
  sort(pTable.begin(), pTable.end(), cmp); // sorting the table using component cmp

  for(unsigned j = 0; j < pTable.size(); j++)
    {
      cout << setw(6) << right << pTable[j]->key << "  - "
	   << setw(5) << right << pTable[j]->num << "  -  "
	   << pTable[j]->desc << "\n";
    }
}
