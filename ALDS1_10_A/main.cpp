#include <iostream>

using namespace std;

int memo[44];

int fibonacci(int n) {
	if (memo[n]) {
		return memo[n];
	}
	if (n == 0 || n == 1) {
		return 1;
	}
	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return memo[n];
}

int main(void)
{
	int n;
	cin >> n;

	for (register int i = 0; i < 44; ++i) {
		memo[i] = 0;
	}

	cout << fibonacci(n) << endl;

	return 0;
}