#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll v, a[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for(ll i = 1; i <= 9; ++i) cin >> a[i];

    ll minn = INT_MAX, maxn = 0;
    for(ll i = 1; i <= 9; ++i) {
        if(a[i] <= minn) {
            maxn = i;
            minn = a[i];
        }
    }

    if(minn > v) {
        cout << "-1\n";
        return 0;
    }

    ll cur = v/minn;
    string ans = "";
    while(1) {
        bool ok = 0;
        for(ll i = 9; i >= 1; --i) {
            if(v >= a[i] && (v - a[i]) >= (cur - 1) * minn) {
                v -= a[i];
                ans += i + '0';
                cur--;
                ok = 1;
                break;
            }
        }

        if(!ok) break;
    }

    cout << ans << '\n';
    return 0;
}