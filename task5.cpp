
#include <iostream>
#include <string>

using namespace std;
int naiveStringSearch(const string &text, const string &pattern) {
	int n = text.length();
	int m = pattern.length();

	if (m == 0) {
		return 0;
	}

	for (int i = 0; i <= n - m; i++) {
		int j = 0;

		while (j < m && text[i + j] == pattern[j]) {
			j++;
		}

		if (j == m) {
			return i;
		}
	}

	return -1;
}

int main() {
	string text1 = "hello world";
	cout << "text:" << text1<<endl;

	string pattern1 = "hello";
	cout << "Pattern '" << pattern1 << "' found at index: "
		<< naiveStringSearch(text1, pattern1) << endl;

	string pattern2 = "world";
	cout << "Pattern '" << pattern2 << "' found at index: "
		<< naiveStringSearch(text1, pattern2) << endl;

	string pattern3 = "abc";
	cout << "Pattern '" << pattern3 << "' found at index: "
		<< naiveStringSearch(text1, pattern3) << endl;

	string pattern4 = "";
	cout << "Pattern '" << pattern4 << "' found at index: "
		<< naiveStringSearch(text1, pattern4) << endl;

	int x;
	cin >> x;

	return 0;
}