#include <iostream>

using namespace std;

#define PIN (2)
#define SET (1)
#define NOT_SET (0)

#define D

int N;
int board[8][8];

bool has_queen(int i) {
#ifdef D
	//cout << "has_queen(" << i << ")" << endl;
#endif
	for (register int j = 0; j < 8; ++j) {
		if (board[i][j]) {
#ifdef D
			//cout << " return true" << endl;
#endif
			return true;
		}
	}
	return false;
}

bool scan_near_8(int i, int j) {
	for (register int di = -1; di <= 1; ++di) {
		for (register int dj = -1; dj <= 1; ++dj) {
			int ni = i + di;
			int nj = j + dj;
			if (ni >= 0 && nj >= 0 && ni < 8 && nj < 8) {
				if (ni == 0 && nj == 0) {
					continue;
				}
				if (board[ni][nj]) {
					return true;
				}
			}
		}
	}
	return false;
}

bool does_meet() {
#ifdef D
	//cout << "does_meet()" << endl;
#endif
	int queen_count = 0;
	// rows
	for (register int i = 0; i < 8; ++i) {
		int count = 0;
		for (register int j = 0; j < 8; ++j) {
			if (board[i][j]) {
				++count;
				++queen_count;
			}
		}
		if (count > 1) {
#ifdef D
			//cout << "return false: queens in a row > 1" << endl;
#endif
			return false;
		}
	}
	if (queen_count != 8) {
#ifdef D
		//cout << "return false: number of queens is lesser then 8 as " << queen_count << endl;
#endif
		return false;
	}

	// columns
	for (register int j = 0; j < 8; ++j) {
		int count = 0;
		for (register int i = 0; i < 8; ++i) {
			if (board[i][j]) {
				++count;
			}
		}
		if (count > 1) {
#ifdef D
			//cout << "return false: queens in a column > 1" << endl;
#endif
			return false;
		}
	}

	// /
	int count_by_part[15];
	for (register int i = 0; i < 15; ++i) {
		count_by_part[i] = 0;
	}
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			if (board[i][j]) {
				++count_by_part[i + j];
			}
		}
	}
	for (register int i = 0; i < 15; ++i) {
		if (count_by_part[i] > 1) {
#ifdef D
			//cout << "return false: queens in / > 1" << endl;
#endif
			return false;
		}
	}

	// \ 
	for (register int i = 0; i < 15; ++i) {
		count_by_part[i] = 0;
	}
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			if (board[i][j]) {
				++count_by_part[i - j + 7];
			}
		}
	}
	for (register int i = 0; i < 15; ++i) {
		if (count_by_part[i] > 1) {
#ifdef D
			//cout << "return false: queens in a \ > 1" << endl;
#endif
			return false;
		}
	}

	return true;
}

void print_board() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {
#ifdef D
	//cout << "solve()" << endl;
#endif

#ifdef D
	print_board();
#endif
	if (does_meet()) {
		for (register int i = 0; i < 8; ++i) {
			for (register int j = 0; j < 8; ++j) {
				if (j) {
					cout << j << " ";
				}
			}
		}
		cout << endl;
		return;
	}
	for (register int i = 0; i < 8; ++i) {
		if (!has_queen(i)) {
			for (register int j = 0; j < 8; ++j) {
				if (scan_near_8(i, j)) {
					continue;
				}
				board[i][j] = SET;
#ifdef D
				//cout << "(" << i << "," << j << ") is SET" << endl;
#endif
				solve();
				board[i][j] = NOT_SET;
#ifdef D
				//cout << "(" << i << "," << j << ") is UNSET" << endl;
#endif
			}
		}
	}
}

int main(void)
{
	cin >> N;
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			board[j][i] = NOT_SET;
		}
	}
	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		board[j - 1][i - 1] = PIN;
	}

	solve();

	return 0;
}