#include <iostream>

using namespace std;

#define NOT_SELECTED (0)
#define SELECTED (1)

int k = -1;
int A[13];
int selected[13];

bool allSelected() {
    // cout << "allSelected()" << endl;
    int count = 0;
    for (register int i = 0; i < 13; ++i) {
        if (selected[i]) {
            ++count;
        }
    }
    // cout << (count == 6) << endl;
    return count == 6;
}

void solve(int i) {
    // cout << "solve(" << i << ")" << endl;
    // for (register int i = 0; i < 13; ++i) {
    //     if (selected[i]) {
    //         cout << "_" << A[i];
    //     }
    // }
    // cout << endl;
    if (i > k) {
        return;
    }
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
        cin >> k;
        for (register int i = 0; i < k; ++i) {
            cin >> A[i];
        }
        for (register int i = 0; i < k; ++i) {
            selected[i] = NOT_SELECTED;
        }
        solve(0);
        cout << endl;
    } while (k != 0);

    return 0;
}