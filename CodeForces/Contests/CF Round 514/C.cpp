#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[1000007], cnt = 0, a[1000007];

void solve(ll x, ll y) {
    if(x == 1) {
        ans[cnt++] = y;
        return;
    } 
    if(x == 2) {
        ans[cnt++] = y;
        ans[cnt++] = y * 2;
        return;
    }
    if(x == 3) {
        ans[cnt++] = y;
        ans[cnt++] = y;
        ans[cnt++] = y *3;
        return;
    }

    for(ll i = 0; i < x; ++i) if(a[i]%2 == 1) ans[cnt++] = y;
    for(ll i = 0; i < x/2; ++i) a[i] = a[2 * i + 1]/2;
    solve(x/2, y * 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) a[i] = i + 1;
    solve(n, 1);

    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    return 0;
}