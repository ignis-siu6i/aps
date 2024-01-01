#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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

		for (int divisor = 1234; divisor < 100000; ++divisor) {
			int dividend = divisor * N;
			if (dividend < 100000) {
				if (!hasSameNumber2(dividend, divisor)) {
					printf("%05d / %05d = %d\n", dividend, divisor, N);
					++count;
				}
			}
		}

		if (count == 0) {
			printf("There are no solutions for %d.\n", N);
		}
		printf("\n");
	} while (N != 0);

	return 0;
}
