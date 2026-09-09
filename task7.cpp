#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		C[i][j] = A[i][j] + B[i][j];

	return C;
}

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		C[i][j] = A[i][j] - B[i][j];

	return C;
}

vector<vector<int>> naive(vector<vector<int>> A, vector<vector<int>> B) {
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	for (int k = 0; k < n; k++)
		C[i][j] += A[i][k] * B[k][j];

	return C;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
	int n = A.size();

	if (n == 1)
		return{ { A[0][0] * B[0][0] } };

	int k = n / 2;

	vector<vector<int>> A11(k, vector<int>(k));
	vector<vector<int>> A12(k, vector<int>(k));
	vector<vector<int>> A21(k, vector<int>(k));
	vector<vector<int>> A22(k, vector<int>(k));

	vector<vector<int>> B11(k, vector<int>(k));
	vector<vector<int>> B12(k, vector<int>(k));
	vector<vector<int>> B21(k, vector<int>(k));
	vector<vector<int>> B22(k, vector<int>(k));

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + k];
			A21[i][j] = A[i + k][j];
			A22[i][j] = A[i + k][j + k];

			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + k];
			B21[i][j] = B[i + k][j];
			B22[i][j] = B[i + k][j + k];
		}
	}

	vector<vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));
	vector<vector<int>> M2 = strassen(add(A21, A22), B11);
	vector<vector<int>> M3 = strassen(A11, subtract(B12, B22));
	vector<vector<int>> M4 = strassen(A22, subtract(B21, B11));
	vector<vector<int>> M5 = strassen(add(A11, A12), B22);
	vector<vector<int>> M6 = strassen(subtract(A21, A11), add(B11, B12));
	vector<vector<int>> M7 = strassen(subtract(A12, A22), add(B21, B22));

	vector<vector<int>> C11 = add(subtract(add(M1, M4), M5), M7);
	vector<vector<int>> C12 = add(M3, M5);
	vector<vector<int>> C21 = add(M2, M4);
	vector<vector<int>> C22 = add(subtract(add(M1, M3), M2), M6);

	vector<vector<int>> C(n, vector<int>(n));

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			C[i][j] = C11[i][j];
			C[i][j + k] = C12[i][j];
			C[i + k][j] = C21[i][j];
			C[i + k][j + k] = C22[i][j];
		}
	}

	return C;
}

void print(vector<vector<int>> A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void test(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> result1 = naive(A, B);
	vector<vector<int>> result2 = strassen(A, B);

	cout << "Naive:\n";
	print(result1);

	cout << "\nStrassen:\n";
	print(result2);

	if (result1 == result2)
		cout << "\nResults Match: YES\n";
	else
		cout << "\nResults Match: NO\n";
}

int main() {

	cout << "2x2 Test\n";

	vector<vector<int>> A2 = {
		{ 1, 2 },
		{ 3, 4 }
	};

	vector<vector<int>> B2 = {
		{ 5, 6 },
		{ 7, 8 }
	};

	test(A2, B2);

	cout << "\n4x4 Test\n";

	vector<vector<int>> A4 = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	vector<vector<int>> B4 = {
		{ 16, 15, 14, 13 },
		{ 12, 11, 10, 9 },
		{ 8, 7, 6, 5 },
		{ 4, 3, 2, 1 }
	};

	test(A4, B4);

	cout << "\nRandom 4x4 Test\n";

	vector<vector<int>> R1(4, vector<int>(4));
	vector<vector<int>> R2(4, vector<int>(4));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			R1[i][j] = rand() % 10;
			R2[i][j] = rand() % 10;
		}
	}

	test(R1, R2);

	int x;
	cin >> x;

	return 0;
}