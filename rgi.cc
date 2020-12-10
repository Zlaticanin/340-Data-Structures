/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include "rgi.h"

// Constants
int VEC_SIZE = 200;
int LOW = 1;
int HIGH = 10000;
int SEED = 1;
int NO_ITEMS = 12;
int ITEM_W = 5;

// Code for genRndNum
void genRndNum(vector<int> &v)
 {
  srand(SEED);
  for (int i=0; i < VEC_SIZE; ++i)
    {
    v.push_back(LOW + (rand() % (HIGH-LOW+1)));
    }
 }

// Code for printVec
void printVec(const vector<int> &v)
 {
  srand(SEED);
  for (int i=0; i < VEC_SIZE; ++i)
    {
      cout << setw(ITEM_W) << v[i];
      if ((i+1) % NO_ITEMS == 0)
	{
	  cout << endl;
	}
    }
 }

int 
main() 
{
// Declare vector v
  vector<int> v;
// Generate random numbers to fill vector v	
  genRndNum(v);
// Using STL sort sort v
  sort(v.begin(),v.end());
// Print vector of sorted random numbers
  cout << endl << endl << "Vector of sorted random numbers is: " << endl;
  printVec(v);
  cout << endl;
  
    return 1;
}


