#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int A[20], Q[200];
bool solved;

void solve(int n, int m, int currM, int aIdx) {
	if (solved) {
		return;
	}
	if (m == currM) {
		solved = true;
		return;
	}
	if (aIdx >= n) {
		return;
	}
	solve(n, m, currM + A[aIdx], aIdx + 1);
	solve(n, m, currM, aIdx + 1);
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	for (register int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int q;
	cin >> q;
	for (register int i = 0; i < q; ++i) {
		solved = false;
		cin >> Q[i];
		solve(n, Q[i], 0, 0);
		if (solved) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}