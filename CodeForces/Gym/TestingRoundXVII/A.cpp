#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, cnt[20007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= sqrt(n); ++i) {
        for(ll j = i; j <= n/i + 1; ++j) {
            for(ll k = j; k <= n/(j * i) + 1; ++k) {
                if(i * j * k <= n) cnt[i * j * k]++;
            }
        }
    }

    for(ll i = 1; i <= n; ++i) cout << cnt[i] << '\n';
    return 0;
}