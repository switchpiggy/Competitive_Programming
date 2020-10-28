#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(r >= l * 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }

    return 0;
}