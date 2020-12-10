/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip> // in order to use setw function
#include <set>

using std::set;

#define NO_ITEMS 16 // primes per line
#define ITEM_W 5 // spaces allocated for each prime

void sieve(set<int>& s, int n)
{
   for(int m = 2; m*m <= n; m++) // iterating an element that's m <= sqrt(n)
     {     
     for(int j = 2; j*m < n; j++) // storing the multiples of m < n
      s.erase(j*m); // erasing j*m from the set
     }
}

void print_primes(const set<int>& s)
{
  int  rowCount = 0; // setting the current row count to be 0
  for(std::set<int>::iterator it = s.begin(); it != s.end(); it++){
    rowCount++;
    std::cout << std::setw(ITEM_W) << *it;
    if(rowCount == NO_ITEMS){ // when the row count reaches 16, create a new line
    std::cout << "\n";
    rowCount = 0;
    }
  }
  std::cout << "\n";
}

int
main()
{
  set<int>s;
  int n; 

  std::cin >> n; // entering the upper limit
  std::cout << "Upper limit for the set of primes: " << n << "\n";

  for(int k = 2; k < n; k++)
    s.insert(k); // inserting all numbers that start at 2 to n-1
  std::cout << "\n";

  sieve(s,n); // calling the sieve function
  print_primes(s); // calling the print_primes function

  return 0;
}
