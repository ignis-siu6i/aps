#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define NOT_SET (-1)

int queen[8];
int cnt;

inline bool queenExistsInRow(int row) {
	return queen[row] != NOT_SET;
}

inline void print() {
	for (register int i = 0; i < 8; ++i) {
		cout << queen[i] + 1;
		if (i != 7) {
			cout << " ";
		}
	}
	cout << endl;
}

inline bool available(int i, int j) {
	if (queen[i] != NOT_SET) {
		return false;
	}
	for (register int k = 0; k < 8; ++k) {
		if (queen[k] != NOT_SET && queen[k] == j) {
			return false;
		}
	}
	for (register int k = 0; k < 8; ++k) {
		if (queen[k] != NOT_SET && k + queen[k] == i + j) {
			return false;
		}
	}
	for (register int k = 0; k < 8; ++k) {
		if (queen[k] != NOT_SET && k - queen[k] == i - j) {
			return false;
		}
	}
	return true;
}

void solve(int i) {
	if (i > 7) {
		if (cnt + 1 < 10) {
			cout << " " << ++cnt << "      ";
		}
		else {
			cout << ++cnt << "      ";
		}
		print();
		return;
	}
	if (queenExistsInRow(i)) {
		solve(i + 1);
	}
	else {
		for (register int j = 0; j < 8; ++j) {
			if (!available(i, j)) {
				continue;
			}
			queen[i] = j;
			solve(i + 1);
			queen[i] = NOT_SET;
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	for (register int n = 0; n < N; ++n) {
		cnt = 0;
		for (register int i = 0; i < 8; ++i) {
			queen[i] = NOT_SET;
		}
		int i, j;
		cin >> i >> j;
		queen[j - 1] = i - 1;

		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		solve(0);
		if (n != N - 1) {
			cout << endl;
		}
	}

	return 0;
}