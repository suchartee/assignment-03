#ifndef functions_H
#define functions_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using std::vector;
using std::map;
using std::set;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Devided function for part 1 (exceptions)
double divided(double a, double b) {
	if (b == 0)
		throw 0;
	else return a / b;
}

//Template part 2
template <typename W>
W wordCombine(W a, W b) {

	return a + " " + b;
}

//AddWord function for part 3 (STL)
void addWord(vector<string>* v) {
	int number;
	string newWord;
	cout << endl;
	cout << "How many word would you like to add: ";
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cout << "Please enter a preferrable word: ";
		cin >> newWord;
		v->push_back(newWord);
	}
	cout << endl;
}

//DeleteWord function for part 3 (STL)
void deleteWord(vector<string>* v) {
	string eraseWord;
	cout << endl;
	cout << "What word do you want to delete: ";
	cin >> eraseWord;

	vector<string>::iterator newEraseWord = find(v->begin(), v->end(), eraseWord);
	v->erase(newEraseWord);

	cout << "Now, you have " << v->size() << " word(s) available" << endl << endl;
}

//Greatest common divisor part 4
int gcd(int a, int b) {
	//Making negative number be positive number
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;

	//Base case
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	//Recusive case
	if (a > b)
		return gcd(a - b, b);
	else
		return gcd(a, b - a);
}

//Fibonacci part 4
int fib(int n) {
	//Error check
	if (n < 1) throw "ERROR: Invalid number";

	//Base case
	if (n == 1 || n == 2) return 1;

	//Recursive case
	return fib(n - 1) + fib(n - 2);
}

//Power part 4
int pow(int a, int b) {
	//Error check
	if (b < 0) throw "ERROR: Invalid exponent";

	//Base case
	if (b == 0) return 1;

	//Recursive case
	return a * pow(a, b - 1);
}

//Triangular part 4
int tri(int n) {
	//Error check
	if (n <= 0) throw "ERROR: Invalid number";

	//Base case
	if (n == 1) return 1;

	//Recursive case
	return n + tri(n - 1);
}

//Greatest common divisor part 5
int gcd_iter(int a, int b) {
	if (a == b)
		return a;
	else {
		int gcd = 0;
		while (b != 0) {
			int temp = a%b;
			if (temp == 0)
				gcd = b;
				a = b;
				b = temp;
		}
		return gcd;
	}
}

//Fibonacci part 5
int fib_iter(int n) {
	//Error check
	if (n < 1) throw "ERROR: Invalid number";
	
	if (n == 1 || n == 2) return 1;
	else {
		int n1 = 1, n2 = 1, fib = 0;
		for (int i = 3; i <= n; i++) {
			fib = n1 + n2;
			n1 = n2;
			n2 = fib;
		}
		return fib;
	}
}

//Power part 5
int pow_iter(int a, int b) {
	//Error check
	if (b < 0) throw "ERROR: Invalid exponent";

	int pow = 1;
	for (int i = 0; i < b; i++) {
		pow *= a;
	}
	return pow;
}

//Triangular part 5
int tri_iter(int n) {
	//Error check
	if (n <= 0) throw "ERROR: Invalid number";

	int tri = 0;
	for (int i = 1; i <= n; i++) {
		tri += i;
	}
	return tri;
}

#endif
