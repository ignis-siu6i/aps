#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int A[20], Q[200];
bool solved;

void solve(int m, int currM, int aIdx) {
	if (solved) {
		return;
	}
	if (m == currM) {
		solved = true;
		return;
	}
	if (aIdx >= N) {
		return;
	}
	solve(m, currM + A[aIdx], aIdx + 1);
	solve(m, currM, aIdx + 1);
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
		solved = false;
		cin >> Q[i];
		solve(Q[i], 0, 0);
		if (solved) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}