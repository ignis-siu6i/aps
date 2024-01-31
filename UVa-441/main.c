#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NOT_SELECTED (0)
#define SELECTED (1)

int k = -1;
int A[13];
int selected[13];
int isFirstAnswer = 1;

int allSelected() {
    int count = 0;
    for (register int i = 0; i < 13; ++i) {
        if (selected[i]) {
            ++count;
        }
    }
    return count == 6;
}

void solve(int i) {
    if (i > k) {
        return;
    }
    if (allSelected()) {
        int isFirstItem = 1;
		if (isFirstAnswer) {
			isFirstAnswer = 0;
		}
		else {
			printf("\n");
		}
        for (register int i = 0; i < k; ++i) {
            if (selected[i]) {
                if (!isFirstItem) {
					printf(" ");
                } else {
                    isFirstItem = 0;
                }
				printf("%d", A[i]);
            }
        }
        return;
    }
    if (!allSelected()) {
        selected[i] = SELECTED;
        solve(i + 1);
    }
    selected[i] = NOT_SELECTED;
    solve(i + 1);
}

int main(void)
{
    do {
		scanf("%d", &k);
        for (register int i = 0; i < k; ++i) {
			scanf("%d", &A[i]);
        }
        for (register int i = 0; i < k; ++i) {
            selected[i] = NOT_SELECTED;
        }
        if (k != 0) {
			solve(0);
			printf("\n");
        }
    } while (k != 0);

    return 0;
}