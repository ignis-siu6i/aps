#include <iostream>

using namespace std;

#define NOT_SET_YET (-1)
#define SET 1
#define NOT_SET 0

int k = -1;
int A[13];
int selected[13];

bool allSelected() {
    int count = 0;
    for (register int i = 0; i < 13; ++i) {
        if (selected[i]) {
            ++count;
        }
    }
    return count == k;
}

void solve(int i) {
    if (allSelected()) {
        bool isFirstItem = true;
        for (register int i = 0; i < k; ++i) {
            if (selected[i]) {
                if (!isFirstItem) {
                    cout << " ";
                } else {
                    isFirstItem = false;
                }
                cout << A[i];
            }
        }
        cout << endl;
    }
    A[i] = NOT_SET;
    solve(i + 1);
    A[i] = SET;
    solve(i + 1);
}

int main(void)
{
    do {
        cin >> k;
        for (register int i = 0; i < k; ++i) {
            cin >> A[i];
        }
        for (register int i = 0; i < k; ++i) {
            selected[k] = NOT_SET_YET;
        }
        solve(0);
    } while (k != 0);

    return 0;
}