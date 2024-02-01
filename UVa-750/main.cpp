#include <iostream>

using namespace std;

int board[8];

void check(int a, int b, int c, int d, int e, int f, int g, int h) {

}

int main(void)
{
	int N;
	cin >> N;

	for (register int n = 0; n < N; ++n) {
		int i, j;
		cin >> i >> j;
		board[i - 1] = j - 1;
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