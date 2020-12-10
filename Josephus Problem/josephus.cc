/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include "josephus.h"

using namespace std;

void init_vals(list<string> &L, args &in)
{
  cin >> in.N >> in.M >> in.K;
  cout << "Number of people? " << in.N << "\n";
  cout << "Index for elimination? " << in.M << "\n";
  cout << "Index for printing? " << in.K << "\n";

  L.resize(in.N);
  generate(L.begin(), L.end(), SEQ(in.N));
}

void print_list(const list<string> &L, const unsigned &cnt)
{
  int line = 0;
  
  if(cnt == 0)
    {
      cout << "\nInitial group of people" << "\n";
      cout << "-----------------------" << "\n";
    }
  else if(cnt == 7)
    {
      cout << "\nAfter eliminating " << cnt << "th person" << "\n";
      cout << "----------------------------" << "\n";
    }
  else
    {
      cout << "\nAfter eliminating " << cnt << "th person" << "\n";
      cout << "-----------------------------" << "\n";
    }

  //Printing
  for(auto it = L.begin(); it != L.end(); ++it)
    {
      cout << *it << " ";
      line++;
      if(line == NO_ITEMS) // printing 12 per line
	{
	  cout << "\n";
          line = 0;
	}
    }
  cout << "\n";
}
  
int main()
{
  unsigned int cnt = 0;
  list<string> L; // list for names of people
  args in; // input arguments
  int j, i = 0;

  // Calling the init_vals function
  init_vals(L, in);

  //Calling the print_list
  print_list(L, cnt);

  while(L.size() != 1)
    {
      j = (i + (in.M - 1)) % L.size(); // to find the person that needs to be removed
      i = j; // to start counting from the last position

      auto p = L.begin(); // beginning of the cycle
      advance(p, j); // incrementing iterator
      p = L.erase(p);// deleting element from the list
      cnt++; // incrementing the count of people

      if(cnt % in.K == 0 || L.size() == 1)
	print_list(L, cnt);
    }

  return 0;
}
