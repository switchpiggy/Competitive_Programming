#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r;

int main() {
    ll maxn = 0, minn = 0;
    cin >> n >> l >> r;

    ll dist = 0, cur = 1;
    for(ll i = 0; i < n; ++i) {
        if(dist >= r) maxn += cur/2;
        else {
            dist++;
            maxn += cur;
            cur *= 2;
        }
    }

    minn = (ll)pow(2, min(l, n)) - 1 + max(0ll, n - l);

    cout << minn << ' ' << maxn << '\n';
    return 0;
}