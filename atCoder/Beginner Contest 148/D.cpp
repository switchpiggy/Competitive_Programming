#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll cur = 1, ans = n;
    for(ll i = 0; i < n; ++i) {
        if(a[i] == cur) {
            ans--;
            cur++;
        }
    }

    if(ans == n) cout << "-1\n";
    else cout << min(n - 1, ans) << '\n';
    return 0;
}