#include <iostream>

using namespace std;

bool row_pin[8];
bool col_pin[8];

#define NOT_SET (-1)
int rows[8];

void print() {
	for (register int i = 0; i < 8; ++i) {
		cout << rows[i];
		if (i != 7) {
			cout << " ";
		}
	}
	cout << endl;
}

int get_next_col_num() {
	for (register int j = 0; j < 8; ++j) {
		bool used = false;
		for (register int i = 0; i < 8; ++i) {
			if (rows[i] == j) {
				used = true;
				break;
			}
		}
		if (!used) {
			return j;
		}
	}
	return -1;
}

void solve(int row_num, int col_num) {
	cout << "solve(" << row_num << ", " << col_num << ")" << endl;
	if (row_num >= 8) {
		return;
	}
	if (col_num >= 8) {
		solve(row_num + 1, 0);
		return;
	}
	solve(row_num, col_num + 1);
}

int main(void)
{
	int N;
	cin >> N;
	for (register int i = 0; i < 8; ++i) {
		row_pin[i] = col_pin[i] = false;
		rows[i] = NOT_SET;
	}
	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		row_pin[i - 1] = true;
		col_pin[j - 1] = true;
		rows[i - 1] = j - 1;
	}

	solve(0, 0);

	return 0;
}