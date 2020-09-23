#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

static vector<int> numbers;
static int size;

void fillVector();
void printVector();
int binarySearch(int);
void displayElements();
void displaySubElements(int, int);
	
int main()
{
	cout << endl << setw(50) << "Binary Search ~@mateusvictor" << endl << endl;
	
	cout << "Enter a the size's vector: ";
	cin >> size;

	fillVector();

	displayElements();

	int searchInt, position;
	
	do {
		cout << "Type a value to search (-1 to exit): ";
		cin >> searchInt;

		if (searchInt == -1)  break;
		
		position = binarySearch(searchInt);
		cout << endl;

		if (position == -1)
			cout << "The integer " << searchInt <<  " was not found!.\n";
		else 
			cout << "The integer " << searchInt << " was found int position " << position << ".\n";
		cout << endl;
		
	} while (1);

	return 0;
}


int binarySearch(int searchInt)
{

	int low = 0;
	int high = size - 1;
	int middle = (low + high + 1) / 2;

	int location = -1;
	do
	{
		displaySubElements(low, high);
		
		for (int i = 0; i < middle; i++)
			cout << "    ";
		
		cout << " * ";

		if (searchInt == numbers[middle])
			location = middle;
		else if (searchInt < numbers[middle])
			high = middle -1;
		else 
			low = middle + 1;
	
		middle = (float)(low + high + 1) / 2;

	} while ((low <= high) && (location == -1));

	return location;
}


void displayElements()
{
	displaySubElements(0, size -1);
	cout << endl;
}

void displaySubElements(int low, int high)
{
	cout << endl;
	for (int i = 0; i < low; i++)
		cout << "    ";

	for (int i = low; i <= high; i++)
		cout << numbers[ i ] << "  ";

	cout << endl;
}


void fillVector()
{
	srand(time(0));

	for (int i = 0; i < size; i++)
		numbers.push_back(10 + rand() % 90);

	sort(numbers.begin(), numbers.end());
}

void printVector()
{
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << numbers[i] << "  ";
	cout << endl;
}