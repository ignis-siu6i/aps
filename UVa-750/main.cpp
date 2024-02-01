#include <iostream>

using namespace std;

int board[8];
bool pin[8];

void print_board(int board[8][8]) {
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void check(int a, int b, int c, int d, int e, int f, int g, int h) {
	int in_check[8] = { a, b, c, d, e, f, g, h };
	for (register int i = 0; i < 8; ++i) {
		if (pin[i]) {
			if (board[i] != in_check[i]) {
				return;
			}
		}
	}
	int real_board[8][8];
	for (register int i = 0; i < 8; ++i) {
		for (register int j = 0; j < 8; ++j) {
			if (in_check[i] == j) {
				real_board[i][j] = 1;
			}
			else {
				real_board[i][j] = 0;
			}
		}
	}
	print_board(real_board);
}

int main(void)
{
	int N;
	cin >> N;
	for (register int i = 0; i < 8; ++i) {
		board[8] = -1;
		pin[8] = false;
	}
	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		board[i - 1] = j - 1;
		pin[i - 1] = true;
	}

	for (register int a = 0; a < 8; ++a) {
		for (register int b = 0; b < 8; ++b) {
			if (b == a) continue;
			for (register int c = 0; c < 8; ++c) {
				if (c == a || c == b) continue;
				for (register int d = 0; d < 8; ++d) {
					if (d == a || d == b || d == c) continue;
					for (register int e = 0; e < 8; ++e) {
						if (e == a || e == b || e == c || e == d) continue;
						for (register int f = 0; f < 8; ++f) {
							if (f == a || f == b || f == c || f == d || f == e) continue;
							for (register int g = 0; g < 8; ++g) {
								if (g == a || g == b || g == c || g == d || g == e || g == f) continue;
								for (register int h = 0; h < 8; ++h) {
									if (h == a || h == b || h == c || h == d || h == e || h == f || h == g) continue;
									check(a, b, c, d, e, f, g, h);
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}