#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[107];

int main() {
    cin >> n >> m;

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n, greater<ll>());

    ll cnt = 0;
    for(ll i = 0; i < m; ++i) {
        if(a[i] * 4 * m >= sum) cnt++;
        else break;
    }

    if(cnt == m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}