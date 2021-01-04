#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define pbenqueue priority_queue
ll n, m;

pbenqueue<ll> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ben.push(a);
    }

    for(ll i = 0; i < m; ++i) {
        ll t = ben.top();
        ben.pop();
        ben.push((t/2));
    }

    ll ans = 0;
    while(!ben.empty()) {
        //cout << ben.top() << '\n';
        ans += ben.top();
        ben.pop();
    }

    cout << ans << '\n';
}