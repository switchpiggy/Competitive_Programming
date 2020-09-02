#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        pq.push(temp);
    }

    ll ans = 0;
    while(pq.size() >= 2) {
        ll t = pq.top();
        pq.pop();
        ll u = pq.top();
        pq.pop();

        ans += t + u;
        pq.push(t + u);
    }

    cout << ans << endl;
    return 0;
}