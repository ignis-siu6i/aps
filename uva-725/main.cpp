#include <iostream>

using namespace std;

int main(void)
{
	int input;

	do {
		cin >> input;
		int count = 0;
		for (int a = 0; a < 10; ++a) {
			for (int b = 0; b < 10; ++b) {
				if (a == b) {
					continue;
				}
				for (int c = 0; c < 10; ++c) {
					if (a == c || b == c) {
						continue;
					}
					for (int d = 0; d < 10; ++d) {
						if (a == d || b == d || c == d) {
							continue;
						}
						for (int e = 0; e < 10; ++e) {
							if (a == e || b == e || c == e || d == e) {
								continue;
							}
							for (int f = 0; f < 10; ++f) {
								if (f > a) {
									continue;
								}
								if (a == f || b == f || c == f || d == f || e == f) {
									continue;
								}
								for (int g = 0; g < 10; ++g) {
									if (a == g || b == g || c == g || d == g || e == g || f == g) {
										continue;
									}
									for (int h = 0; h < 10; ++h) {
										if (a == h || b == h || c == h || d == h || e == h || f == h || g == h) {
											continue;
										}
										for (int i = 0; i < 10; ++i) {
											if (a == i || b == i || c == i || d == i || e == i || f == i || g == i || h == i) {
												continue;
											}
											for (int j = 0; j < 10; ++j) {
												if (a == j || b == j || c == j || d == j || e == j || f == j || g == j || h == j || i == j) {
													continue;
												}
												int x = (a * 10000 + b * 1000 + c * 100 + d * 10 + e);
												int y = (f * 10000 + g * 1000 + h * 100 + i * 10 + j);
												if (y > x) {
													continue;
												}
												if ((x / y) == input && ((x % y) == 0)) {
													cout << a << b << c << d << e << " / " << f << g << h << i << j << " = " << input << endl;
													++count;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (count == 0) {
			cout << "There are no solutions for " << input << "." << endl;
		}
	} while (input != 0);

	return 0;
}