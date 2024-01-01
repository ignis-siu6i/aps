#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int hasSameNumber(int num) {
	int nums[5];

	for (int i = 0; i < 5; ++i) {
		nums[i] = num % 10;
		num /= 10;
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i == j) {
				continue;
			}
			if (nums[i] == nums[j]) {
				return 1;
			}
		}
	}

	return 0;
}

int hasSameNumber2(int num, int num2) {
	int nums[10];

	for (int i = 0; i < 5; ++i) {
		nums[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < 5; ++i) {
		nums[i + 5] = num2 % 10;
		num2 /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i == j) {
				continue;
			}
			if (nums[i] == nums[j]) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void)
{
	int N;

	do {
		scanf("%d", &N);
		int count = 0;

		int dividend_min = N * 1234;

		for (int dividend = dividend_min; dividend < 100000; ++dividend) {
			if (hasSameNumber(dividend)) {
				continue;
			}
			int divisor_min = dividend / (N + 1);
			if (divisor_min < 1234) {
				divisor_min = 1234;
			}
			int divisor_max = dividend / (N - 1);
			if (divisor_max > dividend) {
				divisor_max = dividend;
			}
			for (int divisor = divisor_min + 1; divisor < divisor_max; ++divisor) {
				if (hasSameNumber2(dividend, divisor)) {
					continue;
				}
				int quotient = dividend / divisor;
				int remainder = dividend - quotient * divisor;
				if (remainder == 0 && quotient == N) {
					++count;
					printf("%05d / %05d = %d\n", dividend, divisor, N);
				}
				//else {
				//	printf("%d / %d = %d ... %d\n", dividend, divisor, quotient, remainder);
				//}
			}
		}

		if (count == 0) {
			printf("There are no solutions for %d.\n", N);
		}
		printf("\n");
	} while (N != 0);

	return 0;
}
