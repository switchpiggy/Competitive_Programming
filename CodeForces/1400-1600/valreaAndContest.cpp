#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, l, r, total, sk;

int main() {
    cin >> n >> k >> l >> r >> total >> sk;
    ll mod = sk%k;
    for(ll i = 1; i <= k; ++i) {
        if(k - mod < i) cout << sk/k + 1 << ' ';
        else cout << sk/k << ' ';
    }
    if(n - k == 0) return 0;

    ll mod2 = (total - sk)%(n - k);
    for(ll i = 1; i <= n - k; ++i) {
        if((n - k) - mod2 < i) cout << (total - sk)/(n - k) + 1 << ' ';
        else cout << (total - sk)/(n - k) << ' ';
    }

    return 0;
}