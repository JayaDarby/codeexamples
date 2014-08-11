
// This program will ask the user to enter a name or partial name to search for
// in the array. Any entries in the array that match the string are displayed.


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{

  // declare the array
  const int NUM_CONTACTS = 11;
  const int LENGTH = 30;
  char contacts[NUM_CONTACTS][LENGTH] =
               {"Becky Warren, 555-1223", "Joe Looney, 555-0097", "Geri Palmer, 555-8787",
                "Lynn Presnell, 555-1212", "Holly Gaddis, 555-8878", "Sam Wiggins, 555-0998",
				"Bob Kain, 555-8712", "Tim Haynes, 555-7676", "Warren Gaddis, 555-9037",
                "Jean James, 555-4939", "Ron Palmer, 555-2783" };
  
  // declare searching variables and get value from the user
  char lookup[LENGTH]; // to hold user's input
  char *strPtr = NULL; // to point to the found phone number
  int i; //loop counter
  int isZero;
  bool found = false;
  
  cout << "This program allows you to search through 11 different contacts. ";
  
  while (true)
  {
    //Give user the option to exit program
    cout << "If you wish to exit this program, please enter 0 now. To do a search, enter 1: ";
	cin >> isZero;
	cout << endl;
	if (isZero == 0)
	  break;
	else if (isZero != 1 && isZero != 0)
	  cout << "That is an invalid input. Please try again." << endl;
	else if (isZero == 1)
	{
      cout << "Please enter the name or partial name that you wish to search for: ";
	  cin.ignore();
      cin.getline(lookup, LENGTH);
  
      //Search the array for matching substring
      for (i = 0; i < NUM_CONTACTS; i++)
      {
        strPtr = strstr(contacts[i], lookup);
	    if (strPtr != NULL)
	    {
	      cout << contacts[i] << endl;
  	      found = true;
        }	  
      }
        if (found == false)
	      cout << "No matching contact found." << endl << endl;
	    else if (found == true)
	      cout << endl;
	}
  }  
	  
}


