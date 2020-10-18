#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    ll curOdd = 1;
    for(ll i = 0; i < n/2; ++i) {
        for(ll j = 0; j < n/2 - i; ++j) {
            ll x1 = i, x2 = n - 1 - i;
            ll y1 = j, y2 = n - 1 - j;
            ans[x1][y1] = ans[x1][y2] = ans[x2][y1] = ans[x2][y2] = 1;
        }
    }

    ll odd = 1, even = 2;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(ans[i][j]) {
                cout << even << ' ';
                even += 2;
            } else {
                cout << odd << ' ';
                odd += 2;
            }
        }

        cout << '\n';
    }

    return 0;
}