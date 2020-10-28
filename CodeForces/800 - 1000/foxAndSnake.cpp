#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll dir = 1;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            if(i%2 == 1) cout << '#';
            else {
                if((dir && j == m) || (!dir && j == 1)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
        }

        if(i%2 == 0) dir = 1 - dir;

        cout << '\n';
    }

    return 0;
}