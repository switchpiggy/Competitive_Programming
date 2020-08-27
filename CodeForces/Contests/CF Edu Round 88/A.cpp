#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, l, r;

int main() {
    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(l * 2 > r) {
            cout << "-1 -1\n";
            continue;
        }
        cout << l << ' ' << 2 * l << endl;
    }

    return 0;
}