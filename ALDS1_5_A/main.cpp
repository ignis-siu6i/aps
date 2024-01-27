#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int A[20], Q[200];
int memo[20][2000];

bool solve(int i, int m) {
	if (memo[i][m] != 0) {
		cout << "hit!!" << endl;
		return true;
	}
	if (m == 0) {
		++memo[i][m];
		return true;
	}
	if (i >= N) {
		return false;
	}
	bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	if (res) {
		++memo[i][m];
	}
	return res;
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (register int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int q;
	cin >> q;
	for (register int i = 0; i < q; ++i) {
		for (register int i = 0; i < 20; ++i) {
			for (register int j = 0; j < 2000; ++j) {
				memo[i][j] = 0;
			}
		}
		int m;
		cin >> m;
		if (solve(0, m)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}