#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, ans[107][107];
bool composite[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 2; i <= 1000; ++i) {
        if(composite[i]) continue;
        for(ll j = i * 2; j <= 1000; j += i) composite[j] = 1;
    }

    cin >> t;
    while(t--) {
        cin >> n;

        if(n == 1) {
            cout << 2 << '\n';
            continue;
        }

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(n%2 == 0) {
                    if(i == j || i == n - j + 1) cout << 1 << ' ';
                    else cout << 0 << ' ';
                } else {
                    if(i == n/2 + 1 || j == n/2 + 1 || i == j || i == n - j + 1) cout << 1 << ' ';
                    else cout << 0 << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}