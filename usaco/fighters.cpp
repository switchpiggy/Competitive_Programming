#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);

        q.push(temp);
    }

    ll ans = 0;

    while(q.size() > 1) {
        ll t = q.top();
        q.pop();

        ll v = q.top();
        q.pop();

        q.push(t + v);

        ans += t + v;
    }

    printf("%lld\n", ans);

    return 0;
}