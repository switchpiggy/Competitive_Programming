#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans[3] = {0, 0, 0};
    for(ll i = 0; i < n; ++i) {
        ans[i%3] += a[i];
    }

    ll maxn = *max_element(ans, ans + 3);
    if(ans[0] == maxn) cout << "chest\n";
    else if(ans[1] == maxn) cout << "biceps\n";
    else cout << "back\n";
    return 0;
}