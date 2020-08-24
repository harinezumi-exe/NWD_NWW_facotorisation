// NWD_NWW_Factorisation.cpp
// NWD - najwiekszy wspolny dzielnik
// NWW - najmniejsza wspolna wielokrotnosc
// Program is meant to calculate the greatest common divisor (NWD)
// and lowest common multiple (NWW) of two numbers provided by the user.
// The idea was to emulate traditional, mathematical approach to this task
// by calculating numbers' factors first and then using them to get NWD and NWW.


#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include<limits>

using namespace std;

vector<int> factorisation(int numberInput);
bool isPrime(int n);


// Entering numbers for the operations

int main()
{
	cout << "Hello, I'll calculate for you the greatest common divisor and lowest common multiple" << endl;
	cout << "of numbers of your choice by using the mighty factorisation." << endl;
	cout << "Enter first number: ";

	int number1;
	cin >> number1;

	while (cin.fail() == true || number1 <= 1) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Input error: enter a number greater than 1." << endl;

		cin >> number1;
	}

	cout << "Enter second number: ";

	int number2;
	cin >> number2;

	while (cin.fail() == true || number2 <=1) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Input error: enter a number greater than 1." << endl;

		cin >> number2;
	}

	vector<int> factorsOfFirstNumber = factorisation(number1);
	vector<int> factorsOfSecondNumber = factorisation(number2);

	int elementsOfValueInFirst;
	int elementsOfValueInSecond;
	int commonValue;
	vector<int>::iterator index;

	vector<int> commonElements;

	for (int mainIterator = 0; mainIterator < factorsOfFirstNumber.size(); mainIterator++)
	{
		if (find(factorsOfSecondNumber.begin(), factorsOfSecondNumber.end(), factorsOfFirstNumber.at(mainIterator)) != factorsOfSecondNumber.end())
		{
			elementsOfValueInFirst = count(factorsOfFirstNumber.begin(), factorsOfFirstNumber.end(), factorsOfFirstNumber.at(mainIterator));
			elementsOfValueInSecond = count(factorsOfSecondNumber.begin(), factorsOfSecondNumber.end(), factorsOfFirstNumber.at(mainIterator));

			commonValue = factorsOfFirstNumber.at(mainIterator);

			if (elementsOfValueInFirst == elementsOfValueInSecond)
			{
				for (int i = 0; i < elementsOfValueInFirst; i++)
				{
					commonElements.push_back(commonValue);
				}

				index = find(factorsOfFirstNumber.begin(), factorsOfFirstNumber.end(), commonValue);
				factorsOfFirstNumber.erase(index);

				index = find(factorsOfSecondNumber.begin(), factorsOfSecondNumber.end(), commonValue);
				factorsOfSecondNumber.erase(index);
			}
			else if (elementsOfValueInFirst > elementsOfValueInSecond)
			{

				for (int i = 0; i < elementsOfValueInSecond; i++)
				{
					commonElements.push_back(commonValue);
				}

				for (int i = 0; i < elementsOfValueInSecond; i++) {

					index = find(factorsOfFirstNumber.begin(), factorsOfFirstNumber.end(), commonValue);
					factorsOfFirstNumber.erase(index);

					index = find(factorsOfSecondNumber.begin(), factorsOfSecondNumber.end(), commonValue);
					factorsOfSecondNumber.erase(index);
				}

			}
			else 
			{

				for (int i = 0; i < elementsOfValueInFirst; i++)
				{
					commonElements.push_back(commonValue);
				}

				for (int i = 0; i < elementsOfValueInFirst; i++) {

					index = find(factorsOfFirstNumber.begin(), factorsOfFirstNumber.end(), commonValue);
					factorsOfFirstNumber.erase(index);

					index = find(factorsOfSecondNumber.begin(), factorsOfSecondNumber.end(), commonValue);
					factorsOfSecondNumber.erase(index);
				}

			}
		}
	}

	int NWD = 1;

	for (int i = 0; i < commonElements.size(); i++)
	{
		NWD *= commonElements.at(i);
	}

	cout << "The greatest common divider of numbers " << number1 << " and " << number2 << " is equal to " << NWD << endl;

	int NWW = number1;

	for (int i = 0; i < factorsOfSecondNumber.size(); i++)
	{
		NWW *= factorsOfSecondNumber.at(i);
	}

	cout << "The lowest common multiple of said numbers is equal to " << NWW << endl;


	return 0;
}


// Factorising the number and saving its factors to a vector

vector<int> factorisation(int numberInput) {

	int divisor = 2;
	int divModulo;
	vector<int> factors;

	while (numberInput != 1)
	{
		divModulo = numberInput % divisor;

		if (divModulo == 0) {

			// The number is dividable by divisor
			// So the value of the divisor is one of the number's factor

			numberInput = numberInput / divisor;
			factors.push_back(divisor);

		}
		else {

			// The number is not dividable by the divisor
			// Increase the divisor by one and check
			// If it is a prime number
			// If not find the next closest prime number

			divisor++;

			while (isPrime(divisor) == false) {

				divisor++;

			}
		}

	}

	return factors;
}


// Checks if a given number is a prime number

bool isPrime(int n) {

	for (int i = 2; i < n; i++)

		if (n % i == 0)
			return false;

	return true;
}