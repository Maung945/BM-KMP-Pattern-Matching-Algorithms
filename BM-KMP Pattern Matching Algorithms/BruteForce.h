#include <iostream>
#include <string>
using namespace std;
int bruteForceSearch(string txt, string pat) {
	int M = pat.length();
	int N = txt.length();
	for (int i = 0; i <= N - M; i++) {          // A loop to slide pat[] one by one
		int j;
		for (j = 0; j < M; j++) {               // For current index i, check for pattern match* /
			if (txt[i + j] != pat[j])
				break;
		}
		if (j == M) {                           // if pat[0...M-1] = txt[i, i + 1, ...i + M - 1]
			return i;
		}
	}
	return -1;
}
