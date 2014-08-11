
#include <iostream>
#include <fstream>
using namespace std;

//declaring functions
void readFile(int nums[], int size);
void selectionSort(int array[], int size);
int maxNumber(int array[], int size);
int minNumber(int array[], int size);
void removeDuplicates(int array[], int newArray[], int size);

int main()
{
  //declare our arrays and array size
  const int ARRAY_SIZE = 1024;
  int numbers[ARRAY_SIZE];
  int newNumbers[ARRAY_SIZE];

  //open file, store values into number array
  readFile(numbers, ARRAY_SIZE);
  
  //Use a selection sort to sort the array
  selectionSort(numbers, ARRAY_SIZE);

  //Find the maximum number
  int maximumNumber = maxNumber(numbers, ARRAY_SIZE);
  cout << "The maximum number is: " << maximumNumber << endl;
  
  //Find the minimum number
  int minimumNumber = minNumber(numbers, ARRAY_SIZE);
  cout << "The minimum number is: " << minimumNumber << endl;
  
  //Remove the duplicates from the array
  removeDuplicates(numbers, newNumbers, ARRAY_SIZE);
  
  //Output the sorted, non-duplicated array
  cout << "The numbers are (in order, without duplicates): ";
  for (int count = 0; count < ARRAY_SIZE; count++)
  {
    if (newNumbers[count]!=NULL)
    {
      cout << newNumbers[count] << " ";
    }
  }
    cout << endl;
	return 0;
  
}

void readFile(int nums[], int size)
{
  ifstream inputFile;
  inputFile.open("numbers.txt");
  int count = 0;
  
  while (count < size && inputFile >> nums[count])
  {
    count++;	
  }	
  
  inputFile.close();


}

void selectionSort(int array[], int size)
{
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size-1); startScan++)
  {
    minIndex = startScan;
	minValue = array[startScan];
	for(int index = startScan + 1; index < size; index++)
	{
	  if (array[index] < minValue)
	  {
	    minValue = array[index];
		minIndex = index;
	  }
	}
	array[minIndex] = array[startScan];
	array[startScan] = minValue;
  }
}

int maxNumber(int array[], int size)
{
  int count;
  int highest = array[0];
  for (count = 1; count < size; count++)
  {
    if (array[count] > highest)
	  highest = array[count];
  }
  
return highest;
}

int minNumber(int array[], int size)
{
  int count;
  int lowest = array[0];
  for (count = 1; count < size; count++)
  {
    if (array[count] < lowest)
	  lowest = array[count];
  }
  return lowest;
}


void removeDuplicates(int array[], int newArray[], int size)
{
  int j = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] != array[i+1])
	{
	  newArray[j] = array[i];
	  j++;
    }
   }
}
