/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std;

#define GARAGE_FULL 10

typedef struct 
{ 
    int id;         // id starts at 1
    string lp;      // license plate of car
    int no_mv;      // number times the car has been moved
}CAR;

//Extracts individual components from the input line
void get_input_vals(const string &line, char &act, string &lp)
{
  char s = ':';
  act = line.substr(0, line.find(s))[0]; // finding ":" on the beginning of the line for the action
  lp = line.substr(line.find(s) + 1, line.rfind(s) - 2); // finding ":" on the end of the line for the license plate
}

//Prints a message stating that a car is arrived
void arrival(const CAR &car, deque<CAR> &D)
{
  cout << "Car " << car.id << " with license plate " << "\"" << car.lp << "\"" << " has arrived." << "\n";
  if(D.size() == GARAGE_FULL) // checking deque size to see if the garage is full
    cout << "    But the garage has full!" << "\n\n";
  else
    {
      D.push_back(car);
      cout << "\n";
    }
}

//Prints a message stating that the car with the license plate number lp is departed
void departure(const string &lp, deque<CAR> &D, stack<CAR> &S)
{
  bool inGarage = false; // to check to see if the car is found in the garage

  for(auto it = D.begin(); it != D.end(); it++)
      {
	if(it -> lp == lp)
	  {
	    inGarage = true;
            break;
	  }
      }

  // If the car is not in the garage print out the message
    if(inGarage == false)
      {
        cout << "No car with license plate " << "\"" << lp << "\"" << " is in the garage." << "\n";
	return;
      }
    
    for(auto it = D.begin(); it != D.end(); it++) // increase the number of times the car was moved ahead of departing cars
      {
        it -> no_mv++;

	string p = "";
	if(it -> lp == lp)
	  {
	    if(it -> no_mv > 1)
	      {
		p = "s"; // if the car is moved more than 1 times, make it plural in the output
	      }
	    cout << "Car " << it -> id << " with license plate " << "\"" << it -> lp << "\"" << " has departed," << "\n";
	    cout << "    car was moved " << it -> no_mv << " time" << p << " in the garage." << "\n\n";
	    D.erase(it);

	    while(!S.empty()) // Pushing cars back into the deque
	      {
		D.push_front(S.top());
		S.pop();
	      }
	    break;
	  }
	else
	  {
	    S.push(*it);
	    D.pop_front();
	  }
      }	  
}

int main()
{
  deque<CAR> D; // tracking all the cars that are there and in the deque
  stack<CAR> S; // tracking all the cars that are moved

  string line, lp;
  char act;

  int n = 1;
  
  while(getline(cin, line)) // while there is input
    {
      get_input_vals(line, act, lp);

      // If the car did not arrive or departure display a message of an invalid action
      if(act != 'A' && act != 'D')
	{
	  cerr << "\'" << act << "\'" << ": " << "invalid action!" << "\n\n";
	  continue;
	}
      
      CAR car;
      car.id = n;
      car.lp = lp;
      car.no_mv = 0;

      bool inGarage = false;

      for(auto it = D.begin(); it != D.end(); it++) // to check to see if the lp is already in the garage
	{
	  if(it -> lp == lp)
	    {
	      inGarage = true;
	      break;
	    }
	}

      if(inGarage == false)
	n++;

      // Calling the arrival function
      if(act == 'A')
	arrival(car, D);

      // Calling the departure function
      else
	departure(car.lp, D, S);
    }
  
  return 0;
}
