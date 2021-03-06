// SimpleSorts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//C:\Users\codym\OneDrive\Desktop\data_10.txt


#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
#include "iomanip"

using namespace std;

int numExchanges, numComparisons;

bool compare(int a, int b);
void exchange(int & a, int & b);
void displayArray(const int * theArray, int size);
void reverseArray(int * theArray, int theSize);
void exchangeSort(int * theArray, int theSize);
void selectionSort(int * theArray, int theSize);
void insertionSort(int * theArray, int theSize);

int main()
{
	cout << "Welcome to the simple sort demo. \n\n";

	cout << "Enter file name. \n";
	string fileName;
	getline(cin, fileName);

	ifstream fin;
	fin.open(fileName);
	// if not opened returns false
	if (!fin) {
		cout << "Error opening file " << fileName << "!!" << endl;
		exit(0);
	}

	int size;
	fin >> size;
	int * theArray = new int[size];
	for (int i = 0; i < size; i++) {
		fin >> theArray[i];
		
	}

	numComparisons = 0;
	numExchanges = 0;

	cout << "The array: " << endl;
	displayArray(theArray, size);
	insertionSort(theArray, size);
	//selectionSort(theArray, size);

	cout << "\n The insertion sort: " << endl;
	displayArray(theArray, size);

	cout << "\n Comparisons : " << numComparisons << "\t Exchanges : " << numExchanges << "\n\n";

	numComparisons = 0;
	numExchanges = 0;
	
	cout << "The sort reversed: " << endl;
	reverseArray(theArray, size);
	displayArray(theArray, size);

	cout << "\nInsertion sorted: " << endl;
	insertionSort(theArray, size);
	//selectionSort(theArray, size);
	displayArray(theArray, size);
	cout << "\n Comparisons : " << numComparisons << "\t Exchanges : " << numExchanges << "\n\n";

}

bool compare(int a, int b)
{
	numComparisons++;
	return a <= b;
}

void exchange(int & a, int & b)
{
	int t = a; 
	a = b;
	b = t;
	++numExchanges;
}

void displayArray(const int * theArray, int size)
{
	int theSize = size;
	if (theSize <= 200) {
		for (int i = 0; i < theSize; ++i) {
			if (i % 10 == 0) {
				cout << endl;

			}
			cout << setw(7) << theArray[i];
		}
	}
	else {
		for (int i = 0; i < 100; ++i) {
			if (i % 10 == 0) {
				cout << endl;

			}
			cout << setw(7) << theArray[i];
		}

		for (int i = theSize-100; i < theSize; ++i) {
			if (i % 10 == 0) {
				cout << endl;

			}
			cout << setw(7) << theArray[i];
		}
	}

}

void exchangeSort(int * theArray, int theSize)
{
	// aka exchangeSort
	for (int k = 1; k < theSize; k++) {
		for (int i = 0; i < theSize-k; i++) {
			if (!compare(theArray[i], theArray[i + 1])) {
				exchange(theArray[i], theArray[i + 1]);
			}
		}
	}
}

void selectionSort(int * theArray, int theSize) {
	for(int i = 0; i < theSize; i++) {
		int small = theArray[i];
		int pos = i;
		int temp;
		for (int j = i + 1; j < theSize; j++) {
			if (theArray[j] < small) {
				if (theArray[i] > theArray[j]) {
					temp = theArray[i];
					theArray[i] = theArray[j];
					theArray[j] = temp;
				}

			}
			if (!compare(theArray[i], theArray[i + 1])) {
				exchange(theArray[i], theArray[i + 1]);
			}
		}
		//cout << "\n After pass " << i << " : ";
		//displayArray(theArray, theSize);
	}
}

void insertionSort(int * theArray, int theSize) {
	//insertionSort(theArray, 0, theSize - 1);
	int i, j, tmp;

	for (i = 1; i < theSize; i++) {
		j = i-1;
		tmp = theArray[i];
		numComparisons++;
		while (j >= 0 && tmp <theArray[j]) {
			theArray[j + 1] = theArray[j];
			numExchanges++;
			j--;
		}
		theArray[j + 1] = tmp;
	}
}

//void insertionSort(int * theArray, int i, int theSize) {
//	int k, j, tmp;
//
//	for (k = 1; i < theSize; i++) {
//		j = k;
//		while (j > 0 && theArray[j - 1] > theArray[j]) {
//
//			tmp = theArray[j];
//			theArray[j] = theArray[j - 1];
//			theArray[j - 1] = tmp;
//			j--;
//
//			if (!compare(theArray[j], theArray[j + 1])) {
//				exchange(theArray[j], theArray[j + 1]);
//			}
//		}
//
//	}
//}

void reverseArray(int * theArray, int theSize) {
	int temp;
	int last = theSize-1;
	for (int i = 0; i < theSize / 2; i++) {
		temp = theArray[i];
		theArray[i] = theArray[last];
		theArray[last] = temp;
		--last;
	}
}
