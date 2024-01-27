#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int A[20], Q[200];

bool solve(int i, int m) {
	if (m == 0) {
		return true;
	}
	if (i >= N) {
		return false;
	}
	bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}

int main(void)
{
	cin >> N;
	for (register int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int q;
	cin >> q;
	for (register int i = 0; i < q; ++i) {
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