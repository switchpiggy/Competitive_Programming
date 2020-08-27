#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, n;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    scanf("%lld %lld", &l, &n);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        q.push(temp);
    }

    ll cnt = 0;

    while(q.size() > 1) {
        ll f = q.top();
        q.pop();

        ll e = q.top();
        q.pop();

        cnt += e + f;

        q.push(e + f);
    }

    printf("%lld\n", cnt);

    return 0;
}