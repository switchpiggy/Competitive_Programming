#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll cnt = 1, cnt2 = 1;
    for(ll i = 1; i < n; ++i) {
        if(a[i] >= a[i - 1]) cnt++;
        else break;
    }

    for(ll i = n - 2; i >= 0; --i) {
        if(a[i] >= a[i + 1]) cnt2++;
        else break;
    }

    cout << min(n, cnt + cnt2) << '\n';
    return 0;
}