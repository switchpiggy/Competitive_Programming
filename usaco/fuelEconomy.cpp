
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, g, b, d, x, y, ngs[50001];
vector<pair<ll, ll>> v;

void no() {
    printf("-1\n");
    exit(0);
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &g, &b, &d);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());
    stack<ll> s;

    s.push(0ll);
    cout << s.top() << endl;

    for(ll i = 1; i < n; ++i) {
        ll cur = i;
        if(s.empty()) {
        	s.push(cur);
        	continue;
        }
        while(!s.empty() && v[s.top()].second >= v[cur].second) {
            ngs[s.top()] = cur;
            s.pop();
        }

        s.push(cur);
    }

    while(!s.empty()) {
        ngs[s.top()] = -1;
        s.pop();
    }

    ll gas = b - v[0].first, sum = 0;

    for(ll i = 0; i < n; ++i) {
        if(gas < 0) no();
        ll needed;
        if(ngs[i] == -1) needed = d - v[i].first;
        else needed = v[ngs[i]].first - v[i].first;
        needed = min(g, needed);

        if(needed > gas) {
        	sum += v[i].second * (needed - gas);
        	gas = needed;
        }

        if(i == n - 1) gas -= d - v[i].first;
        else gas -= v[i + 1].first - v[i].first;
    }

    if(gas < 0) no();
    else printf("%lld\n", sum);

    return 0;
}