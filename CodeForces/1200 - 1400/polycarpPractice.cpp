#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[2007], s[2007];
map<ll, ll> largest;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = a[i];
    }

    sort(s, s + n);

    ll ans = 0;
    for(ll i = 0; i < k; ++i) {
        largest[s[n - 1 - i]]++;
        ans += s[n - 1 - i];
    }

    cout << ans << '\n';
    ll prev = 0, cnt = 0;
    for(ll i = 0; i < n; ++i) {
        if(largest[a[i]]) {
            largest[a[i]]--;
            if(cnt == k - 1) {
                cout << n - prev << '\n';
                return 0;
            }
            cout << i - prev + 1 << ' ';
            prev = i + 1;
            cnt++;
        }
    }

    return 0;
}