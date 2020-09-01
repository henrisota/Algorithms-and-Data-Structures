/*
	CH-231-A
	hw13_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <string>

void rabinKarpMatcher(std::string T, std::string P, int d, int q);

int main() {
	std::string text, pattern;
	int d = 256;
	int q = 1619;	// 256th prime number

	text = "saaberaaberaab";
	pattern = "aab";

	// Uncomment line to receive input from stdin
	// std::cin >> text >> pattern;

	// Find pattern in text if possible with Rabin-Karp algorithm
    rabinKarpMatcher(text, pattern, d, q);

	// Expecting match at position 1, 6 and 11 for example given above

    return 0;
}

void rabinKarpMatcher(std::string T, std::string P, int d, int q) {
	int n = T.length();
	int m = P.length();
	
	int h = 1;
	// Calculate h to the value of the high-order digit position of an m-digit
	// window
	for (int i = 0; i < m - 1; ++i)
		h = (h * d) % q;

	int p = 0;
	int t = 0;

	// Iterate through the length of the patter and the first substring from
	// text, T[0 ... m - 1]
	for (int i = 0; i < m; ++i) {
		// Calculate hash value for the pattern and the first substring
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}

	// Iterate through all possible contiguous substring from starting position
	// 0 to n - m
	for (int s = 0; s <= (n - m); ++s) {
		// Check if hash values match for the pattern and substring
		if (p == t) {
			int j;
			// Check character-by-character match of pattern and substring
			for (j = 0; j < m; ++j)
				// Stop checking in case mismatch occurs
				if (T[s + j] != P[j])
					break;
			// Check if mismatch occured on the m + 1th character (beyond size)
			if (j == m)
				// Meaning check went through and no mismatch occured
				// Therefore pattern and substring match
				std::cout << "Pattern occurs with shift " << s << std::endl;
		}
		// Calculate new hash based on the old hash
		if (s < (n - m)) {
			t = (d * (t - (T[s] * h)) + T[s + m]) % q;
			// Check if new hash value became negative
			if (t < 0)
				// Add a number equal to modulo q to make it positive and 
				// maintain remainder value
				t += q;
		}
	}
}