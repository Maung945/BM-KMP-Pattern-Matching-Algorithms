#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> buildLastFunction(const string& pattern) {
	const int N_ASCII = 128;				// number of ASCII characters
	int i;
	vector<int> last(N_ASCII);				// assume ASCII character set
	for (i = 0; i < N_ASCII; i++)			// initialize array
		last[i] = -1;
	for (i = 0; i < pattern.size(); i++) {
		last[pattern[i]] = i;				// (implicit cast to ASCII code)
	}
	return last;
}

int BMmatch(const string& text, const string& pattern) {
	vector<int> last = buildLastFunction(pattern);
	int n = text.size();
	int m = pattern.size();
	int i = m - 1;								// set i from the right end of pattern
	if (i > n - 1)								// pattern longer than text?
		return -1;								// ...then no match
	int j = m - 1;
	do {
												//cout << "Pattern: " << pattern[j] << " text: " << text[i] << endl;
		if (pattern[j] == text[i]) {
			if (j == 0)
				return i;						// found a match
			else {								// looking-glass heuristic
				i--; j--;						// proceed right-to-left
			}
		}
		else {									// character-jump heuristic
			i = i + m - min(j, 1 + last[text[i]]);
			j = m - 1;
		}
	} while (i <= n - 1);
	return -1;										// no match
}

//  abbca
//  last[97]=4
//  last[98]=2
//  last[99]=3
//  last[100]=-1
//  last could go from 32 to 126 for usable ASCII characters
// O(n+m+sigma)
