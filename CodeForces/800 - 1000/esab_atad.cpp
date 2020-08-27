#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, b;
    scanf("%d %d", &t, &b);
    vector<int> bit_array;
    bit_array.resize(b);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 150; j++) {
            cout << j+1 << endl << flush;
            int digit;
            scanf("%d", &digit);
            bit_array[j % 10] = digit;
        }
        for (int k = 0; k < b; k++) {
            cout << bit_array[k];
        }
        cout << endl << flush;
        string ans;
        scanf("%s", ans);
        if (ans.compare("N") == 0) {
            return 1;
        }
    }
    return 0;
}