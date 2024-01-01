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

int main(void)
{
	int input;

	do {
		scanf("%d", &input);
		int count = 0;

		int dividend = 1235;
		int divisor = 1234;

		while (dividend < 100000) {
			if (hasSameNumber(dividend)) {
				divisor = 1234;
				++dividend;
				continue;
			}
			while (divisor < dividend) {
				if (hasSameNumber(divisor)) {
					++divisor;
					continue;
				}
				int quotient = dividend / divisor;
				int remainder = dividend - quotient * divisor;
				if (remainder == 0 && quotient == input) {
					++count;
					printf("%d / %d = %d\n", dividend, divisor, input);
				}
				//else {
				//	printf("%d / %d = %d ... %d\n", dividend, divisor, quotient, remainder);
				//}
				++divisor;
			}
			divisor = 1234;
			++dividend;
		}

		if (count == 0) {
			printf("There are no solutions for %d.\n", input);
		}
		printf("\n");
	} while (input != 0);

	return 0;
}
