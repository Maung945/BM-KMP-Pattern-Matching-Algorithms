#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "BoyerMooreAlgorithm.h"
#include "Knuth-Morris-PrattAlgorithm.h"
#include "BruteForce.h"

using namespace std;
using namespace std::chrono;
void testingKMP(string txt, string pat) {
	auto start = high_resolution_clock::now();
	cout << "Knuth-Morris-Pratt Pattern Matching Algorithm: " << KMPmatch(txt,
		pat) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time Taken for Knuth-Morris-Pratt Pattern Matching Algorithm: " <<
		duration.count() << " microseconds\n";
}

void testingBoyerMoore(string txt, string pat) {
	auto start = high_resolution_clock::now();
	cout << "The Boyer-Moore Pattern Matching Algorithm: " << BMmatch(txt, pat)
		<< endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time Taken for Boyer-Moore Pattern Matching Algorithm: " <<
		duration.count() << " microseconds\n";
}

void testingBruteForce(string txt, string pat) {
	auto start = high_resolution_clock::now();
	cout << "Brute Force Pattern Matching Algorithm: " << bruteForceSearch(txt,
		pat) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time Taken for Brute Force Pattern Matching Algorithm: " <<
		duration.count() << " microseconds\n";
	cout << endl;
}

int main() {
	/*
	string txt = "here is a simple example";
	string pat = "example";
	cout << "Knuth-Morris-Pratt Pattern Matching Algorithm: " << KMPmatch(txt,
	pat) << endl;
	cout << "The Boyer-Moore Pattern Matching Algorithm: " << BMmatch(txt, pat)
	<< endl;
	cout << "Brute Force Pattern Matching Algorithm: " << bruteForceSearch(txt,
	pat) << endl;
	*/
	fstream file("Examples.txt", ios::in);
	string txt, pat, txt2, pat2, txt3, pat3, txt4, pat4, txt5, pat5, txt6, pat6;
	getline(file, txt);
	cout << txt << endl;
	getline(file, pat);
	cout << pat << endl;
	testingKMP(txt, pat);
	testingBoyerMoore(txt, pat);
	testingBruteForce(txt, pat);
	getline(file, txt2);
	cout << txt2 << endl;
	getline(file, pat2);
	cout << pat2 << endl;
	testingKMP(txt2, pat2);
	testingBoyerMoore(txt2, pat2);
	testingBruteForce(txt2, pat2);
	getline(file, txt3);
	cout << txt3 << endl;
	getline(file, pat3);
	cout << pat3 << endl;
	testingKMP(txt3, pat3);
	testingBoyerMoore(txt3, pat3);
	testingBruteForce(txt3, pat3);
	getline(file, txt4);
	cout << txt4 << endl;
	getline(file, pat4);
	cout << pat4 << endl;
	testingKMP(txt4, pat4);
	testingBoyerMoore(txt4, pat4);
	testingBruteForce(txt4, pat4);
	getline(file, txt5);
	cout << txt5 << endl;
	getline(file, pat5);
	cout << pat5 << endl;
	testingKMP(txt5, pat5);
	testingBoyerMoore(txt5, pat5);
	testingBruteForce(txt5, pat5);
	getline(file, txt6);
	cout << txt6 << endl;
	getline(file, pat6);
	cout << pat6 << endl;
	testingKMP(txt6, pat6);
	testingBoyerMoore(txt6, pat6);
	testingBruteForce(txt6, pat6);
	return 0;
}