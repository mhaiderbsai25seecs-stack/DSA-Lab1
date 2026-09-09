#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascalsTriangle(int n) {
	vector<vector<int>> triangle;

	for (int i = 0; i < n; ++i) {
		vector<int> row(i + 1, 1); 
		for (int j = 1; j < i; ++j) {
			row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}

		triangle.push_back(row);
	}

	return triangle;
}

void printPascalsTriangle(const vector<vector<int>>& triangle) {
	for (const auto& row : triangle) {
		for (int num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the number of rows for Pascal's Triangle: ";
	cin >> n;

	vector<vector<int>> triangle = generatePascalsTriangle(n);

	cout << "Pascal's Triangle with " << n << " rows:";
		printPascalsTriangle(triangle);

		int x;
		cin >> x;
	return 0;
}
