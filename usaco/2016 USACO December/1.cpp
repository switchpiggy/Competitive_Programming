#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a, b, arr[100007];

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(ll i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    for(ll i = 0; i < q; ++i) {
        cin >> a >> b;

        ll l = lower_bound(arr, arr + n, a) - arr, r = lower_bound(arr, arr + n, b) - arr;
        if(arr[r] > b || r >= n) r--;
        //cout << l << ' ' << r << '\n';

        cout << r - l + 1 << '\n';
    }

    return 0;
}