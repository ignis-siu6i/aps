#include <iostream>

using namespace std;

bool row_pin[8];

#define NOT_SET (-1)
int rows[8];
bool row_map[8] = { false, };
bool col_map[8] = { false, };
bool diag_map[8] = { false, };
bool rdiag_map[8] = { false, };

void print() {
	for (register int i = 0; i < 8; ++i) {
		cout << rows[i];
		if (i != 7) {
			cout << " ";
		}
	}
	cout << endl;
}

void update_maps(int i, int j) {
	row_map[i] = true;
	col_map[j] = true;
	diag_map[i + j] = true;
	rdiag_map[i - j + 7] = true;
}

void revert_maps(int i, int j) {
	row_map[i] = false;
	col_map[j] = false;
	diag_map[i + j] = false;
	rdiag_map[i - j + 7] = false;
}

bool check_available(int i, int j) {
	if (row_map[i]) {
		return false;
	}
	if (col_map[j]) {
		return false;
	}
	if (diag_map[i + j]) {
		return false;
	}
	if (rdiag_map[i - j + 7]) {
		return false;
	}
	return true;
}

void solve(int i) {
	if (i >= 8) {
		print();
		return;
	}
	if (row_pin[i]) {
		solve(i + 1);
		return;
	}
	for (register int j = 0; j < 8; ++j) {
		if (check_available(i, j)) {
			rows[i] = j;
			update_maps(i, j);
			solve(i + 1);
			rows[i] = NOT_SET;
			revert_maps(i, j);
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (register int i = 0; i < 8; ++i) {
		rows[i] = NOT_SET;
	}
	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		row_pin[i - 1] = true;
		rows[i - 1] = j - 1;
		update_maps(i - 1, j - 1);
	}

	solve(0);

	return 0;
}