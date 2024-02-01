#include <iostream>

using namespace std;

int board[8];
int num[8];
bool row_pin[8];
bool num_pin[8];

void print_board() {
	for (register int i = 0; i < 8; ++i) {
		cout << board[i] << " ";
	}
	cout << endl;
}

void print_board_pretty() {
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			if (board[i] == j) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int get_next_blank_row() {
	for (register int i = 0; i < 8; ++i) {
		if (row_pin[i]) {
			continue;
		}
		if (board[i] == -1) {
			return i;
		}
	}
	return -1;
}

int get_next_unused_num() {
	for (register int i = 0; i < 8; ++i) {
		if (num_pin[i]) {
			continue;
		}
		if (num[i] == -1) {
			return i;
		}
	}
	return -1;
}

void solve() {
	print_board();
	for (register int i = 0; i < 8; ++i) {
		if (board[i] != -1) {
			continue;
		}
		for (register int j = 0; j < 8; ++j) {
			if (num[j] != -1) {
				continue;
			}
			board[i] = j;
			num[j] = i;
			solve();
			board[i] = -1;
			num[j] = -1;
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (register int i = 0; i < 8; ++i) {
		board[i] = -1;
		num[i] = -1;
		row_pin[i] = false;
		num_pin[i] = false;
	}
	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		board[i - 1] = j - 1;
		num[j - 1] = i - 1;
		row_pin[i - 1] = true;
		num_pin[j - 1] = true;
	}

	solve();

	return 0;
}