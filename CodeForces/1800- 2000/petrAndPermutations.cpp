#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll par = 0;
    for(ll i = 1; i <= n; ++i) {
        if(a[i] == -1) continue;
        ll cur = i;
        while(cur != -1) {
            ll nxt = a[cur];
            a[cur] = -1;
            cur = nxt;
        }

        par = 1 - par;
    }

    cout << ((!par) ? "Petr\n" : "Um_nik\n");
    return 0;
}