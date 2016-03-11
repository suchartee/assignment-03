/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/*
* A series of programs including exceptions, template, STL (Vector, Set, Map) and recursive/iterative functions
*/

/*
References:
http://stackoverflow.com/questions/8777603/what-is-the-simplest-way-to-convert-array-to-vector
http://stackoverflow.com/questions/5333113/how-to-pass-a-vector-to-a-function
http://www.cplusplus.com/forum/beginner/99524/
http://www.cplusplus.com/forum/beginner/25649/
*/

#include <string>
#include <random>
#include <time.h>
#include <array>
#include <algorithm>
#include "functions.h"

int main() {

	//Declarations
	bool isYes = true;
	double a = 0, b = 0;
	const int SIZE = 5;
	string word[5]{};
	int rand1, rand2;
	int choice;
	string yourFruit;
	string monthInsert;

	cout << "Assignment 3: Suchartee Kitisopakul" << endl;

/*------------------------------------------------------------------- Part 1 - Exceptions*/
	cout << endl;
	cout << "------------" << endl;
	cout << "--Division--" << endl;
	cout << "------------" << endl;

	do {
		cout << "Please enter the first number: ";
		cin >> a;
		cout << "Please enter the second number: ";
		cin >> b;

		try
		{
			cout << "Your answer is " << divided(a, b) << endl;
		}		
		catch (int b)
			{
					cout << "You cannot have 0 as a denominator. Please try again" << endl << endl;
					continue;
			}
		cout << endl << "Do you want to do it again? (1 = yes, 0 = no): ";
		cin >> isYes;
	} while (isYes);
/*------------------------------------------------------------------- End of part 1 - Exceptions*/

/*------------------------------------------------------------------- Part 2 - Template*/
	cout << endl;
	cout << "------------------" << endl;
	cout << "--Name Generator--" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Please enter a preferrable word #" << i + 1 << " : ";
		cin >> word[i];
	}

	do {
		srand(time(0));
		rand1 = rand() % 5;
		rand2 = rand() % 5;
		cout << endl << "This is the random name from your entered words: ";
		cout << wordCombine(word[rand1], word[rand2]) << endl;
		cout << endl << "Do you want to generate again? (1 = yes, 0 = no): ";
		cin >> isYes;
	} while (isYes);
/*------------------------------------------------------------------- End of Part 2 - Template*/

/*------------------------------------------------------------------- Part 3 - STL (vector)*/
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "--Vector : Word management (vector)--" << endl;
	cout << "-------------------------------------" << endl;

	//Copy word[] to vector
	vector<string> v(std::begin(word), std::end(word));

	do {
		isYes = true;
		cout << "==Menu==" << endl;
		cout << "1.) Add more word" << endl;
		cout << "2.) Delete unpreferrable word" << endl;
		cout << "3.) Show all words you have" << endl;
		cout << "4.) Exit" << endl << endl;
		cout << "Please select your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: addWord(&v);
			break;
		case 2: deleteWord(&v);
			break;
		case 3:
			cout << endl << "Your word(s): ";
			for (string name : v) {
				cout << name << " ";
			}
			cout << endl << endl;
			break;
		default: isYes = false;
			break;
		}
	} while (isYes);

/*------------------------------------------------------------------- End of Part 3 - STL (vector)*/

/*------------------------------------------------------------------- Part 3 - STL (set)*/
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "--Vector : Fruit list (set)--" << endl;
	cout << "-----------------------------" << endl;
	
	isYes = true;
	std::set<string> fruit{ "banana", "orange", "pineapple", "grape", "cherry" };
		
		do {
			cout << endl << "We have a list of fruits, please enter any fruit name: ";
			cin >> yourFruit;

			auto search = fruit.find(yourFruit);

			if (search != fruit.end()) {
				cout << endl;
				cout << (*search) << " is already in the list! Please try again" << endl;
			}
			else {
				cout << endl;
				cout << yourFruit << " is not found in the list and I just added ";
				fruit.insert(yourFruit);
				cout << yourFruit << " into the list!" << endl << endl;
				cout << "Would you like to do another? (1 = yes, 0 = no): ";
				cin >> isYes;
			}
		} while (isYes);
		
		cout << endl << "Here is all the fruits we have in the list: ";
		cout << endl;
		for (string fruitList : fruit) {
			cout << fruitList << " ";
		}
		cout << endl << endl;

/*------------------------------------------------------------------- End of Part 3 - STL (set)*/

/*------------------------------------------------------------------- Part 3 - STL (map)*/
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "--Vector : Months (map)--" << endl;
	cout << "-----------------------------" << endl;
	
	isYes = true;
	std::map<string, int> month = { {"january", 31}, {"february", 28}, {"march", 31}, {"april", 30}, {"may", 31}, {"june", 30}, {"july", 31}, {"august", 31}, {"september", 30}, {"october", 31}, {"november", 30}, {"november", 31} };

	do {
		cout << "Please enter a month name: ";
		cin >> monthInsert;
		
		//Convert to all lowercase
		for (int i = 0; i < monthInsert.length(); i++) {
			monthInsert[i] = tolower(monthInsert[i]);
		}

		auto find = month.find(monthInsert);

		if (find != month.end()) {
			cout << find->first << " has " << find->second << " days." << endl << endl;
			cout << "Would you like to check other month? (1 = yes, 0 = no): ";
			cin >> isYes;
		}
		else {
			cout << "Please try again." << endl;
		}
	} while (isYes);
	
/*------------------------------------------------------------------- End of Part 3 - STL (map)*/
	
/*------------------------------------------------------------------- Part 4 & 5 - Recursive/Iterative*/
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "--Part 4 & 5 : Recursive/Iterative--" << endl;
	cout << "------------------------------------" << endl;

	isYes = true;
	rand1 = rand() % 5 + 1;
	rand2 = rand() % 5 + 1;

	cout << endl;
	do {
		try {
			cout << "(Recursive) Greatest Common Divisor for number " << rand1 << " and " << rand2 << " is " << gcd(rand1, rand2) << endl;
			cout << "(Iterative) Greatest Common Divisor for number " << rand1 << " and " << rand2 << " is " << gcd_iter(rand1, rand2) << endl << endl;
			cout << "(Recursive) Fibonacci number for index number " << rand1 << " is " << fib(rand1) << endl;
			cout << "(Iterative) Fibonacci number for index number " << rand1 << " is " << fib_iter(rand1) << endl << endl;
			cout << "(Recursive) Power for base " << rand1 << " and exponent " << rand2 << " is " << pow(rand1, rand2) << endl;
			cout << "(Iterative) Power for base " << rand1 << " and exponent " << rand2 << " is " << pow_iter(rand1, rand2) << endl << endl;
			cout << "(Recursive) Triangular number for number " << rand1 << " is " << tri(rand1) << endl;
			cout << "(Iterative) Triangular number for number " << rand1 << " is " << tri_iter(rand1) << endl << endl;
		}
		catch (char * err) {
			cout << err;
		}

		cout << "Would you like to do one more time? (1 = yes, 0 = no): ";
		cin >> isYes;
	
	} while (isYes);

/*------------------------------------------------------------------- End of Part 4 & 5 - Recursive/Iterative*/


	
	system("pause");
	return 0;
}
