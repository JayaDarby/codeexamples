#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int row = (rand() % 16) + 5;
const int col = (rand() % 16) + 5;
const int NUM_ELEM = 20;

int getTotal(int array [ ][NUM_ELEM], int, int);
double getAverage(int array[][NUM_ELEM], int, int);
int getRowTotal(int array[][NUM_ELEM], int, int);
int getColTotal(int array[][NUM_ELEM], int, int);
int getHighestInRow(int array[][NUM_ELEM], int, int);
int getLowestInRow(int array[][NUM_ELEM], int, int);

int main()
{ 
  //declaration of variables

  int table[NUM_ELEM][NUM_ELEM];
  double totalTable;
  int userRow;
  int userCol;
  int highestRow;
  int lowestRow;
  
  cout << "The number of rows: " << row << endl;
  cout << "The number of columns: " << col << endl << endl;
   
  
  //fill up the table with random numbers using generated rows and columns
  cout << "Table: " << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
	{
	  table[i][j] = (rand() % 50) -25;
	  cout << table[i][j] << " "; //output the table for the user to see
	}
	cout << endl;
  }
  cout << endl;
  
  //writing # of rows, # of columns, and table to file out.txt
  ofstream outputFile;
  outputFile.open("out.txt");
  
  outputFile << "The number of rows: " << row << endl;
  outputFile << "The number of columns: " << col << endl << endl;
  
  outputFile << "Table: " << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
	{
	  outputFile << table[i][j] << " ";
	}
	outputFile << cout << endl;
  }
  
  //Close the file
  outputFile.close();
   
  
  //Finding the sum of all elements in array
  cout << "The total is " << getTotal(table, row, col) << endl;
  cout << endl;
  
  //Finding the average of all elements in array
  cout << "The average is " << getAverage(table, row, col) << endl; 
  cout << endl;
  
  //finding the sum of each row in array
  for (int i = 0; i < row; i++)
  {
    cout << "The sum of row " << (i+1) << " is " << getRowTotal(table, i, col) << "." << endl;
  }
  cout << endl;
  
  //finding the sum of each column in array
  for (int i = 0; i < col; i++)
  {
    cout << "The sum of col " << (i+1) << " is " << getColTotal(table, i, row) << "." << endl;
  }
  cout << endl;

  //finding the highest value of each row in array
  for (int i = 0; i < row; i++)
  {
     cout << "The highest value in row " << (i+1) << " is " <<  getHighestInRow(table, i, col) << endl;
  }
  cout << endl;
  
  //finding the lowest value or each row in array
  for (int i = 0; i < row; i++)
  {
    cout << "The lowest value in row " << (i+1) << " is " << getLowestInRow(table, i, col) << endl; 
  }
  cout << endl;
  
}

int getTotal(int array[ ][NUM_ELEM], int, int)
{
  int sum = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
	{
	  sum += array[i][j];
	}
  }
  return sum;
}

double getAverage(int array[][NUM_ELEM], int, int)
{
  int sum = 0;
  int count = 0;
  double average = 0;
  for (int i = 0; i < row; i++)
  { 
    for (int j = 0; j < col; j++)
	{
	  sum += array[i][j];
	  count++;
	}
	count++;
  } 
  average = (sum/count);
  return average;
}

int getRowTotal(int array[][NUM_ELEM], int Jaya, int)
{
  int sum = 0;
  for (int i = 0; i < col; i++)
  {
    sum+= array[Jaya][i];
  }
  return sum;
}

int getColTotal(int array[][NUM_ELEM], int Jaya, int)
{
  int sum = 0;
  for (int i = 0; i < row; i++)
  {
    sum+= array[i][Jaya];
  }
  return sum;
}

int getHighestInRow(int array[][NUM_ELEM], int Jaya, int)
{
  int highestEl = array[Jaya][0];
  for (int i = 1; i < col; i++)
  {
      if (array[Jaya][i] > highestEl)
      {
  	    highestEl = array[Jaya][i];
	  }
  }
  return highestEl;
}

int getLowestInRow(int array[][NUM_ELEM], int Jaya, int)
{
  int lowestEl = array[Jaya][0];
  for (int i = 1; i < col; i++)
  {
      if (array[Jaya][i] < lowestEl)
      {
  	    lowestEl = array[Jaya][i];
	  }
  }
  return lowestEl;
}	  