#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findModes(const vector<int>& arr) {
	vector<int> modes;

	if (arr.empty()) {
		return modes;
	}

	unordered_map<int, int> frequency;

	for (int num : arr) {
		frequency[num]++;
	}

	int maxFrequency = 0;
	for (auto& pair : frequency) {
		maxFrequency = max(maxFrequency, pair.second);
	}

	for (auto& pair : frequency) {
		if (pair.second == maxFrequency) {
			modes.push_back(pair.first);
		}
	}

	return modes;
}

void printResult(const vector<int>& modes) {
	if (modes.empty()) {
		cout << "Array is empty. No mode." << endl;
		return;
	}

	if (modes.size() == 1) {
		cout << "Mode: " << modes[0] << endl;
	}
	else {
		cout << "Multiple modes: ";
		for (int mode : modes) {
			cout << mode << " ";
		}
		cout << endl;
	}
}

int main() {

	vector<int> arr1 = { 1, 2, 2, 3, 4 };
	cout << "Test Case 1: ";
	printResult(findModes(arr1));

	vector<int> arr2 = { 1, 1, 2, 2, 3 };
	cout << "Test Case 2: ";
	printResult(findModes(arr2));

	vector<int> arr3 = {};
	cout << "Test Case 3: ";
	printResult(findModes(arr3));

	int x;
	cin >> x;

	return 0;
}
