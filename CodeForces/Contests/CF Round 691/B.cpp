#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool v[2007][2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll ans = 0;
    if(n%2 == 0) {
        for(ll i = 0; i <= n/2; ++i) {
            for(ll j = 0; j <= n/2; ++j) {
                ll ii = n/2 - i, jj = n/2 - j;
                if(!v[i - ii + 1000][j - jj + 1000]) {
                    ans++;
                    v[i - ii + 1000][j - jj + 1000] = 1;
                }
            }
        }
    } else {
        for(ll i = 0; i <= n/2 + 1; ++i) {
            for(ll j = 0; j <= n/2; ++j) {
                ll ii = n/2 - i + 1, jj = n/2 - j;
                if(!v[i - ii + 1000][j - jj + 1000]) {
                    ans++;
                    v[i - ii + 1000][j - jj + 1000] = 1;
                }

                if(!v[j - jj + 1000][i - ii + 1000]) {
                    ans++;
                    v[j - jj + 1000][i - ii + 1000] = 1;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}