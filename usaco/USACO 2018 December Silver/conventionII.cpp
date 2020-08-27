#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, t;
vector<pair<ll, pair<ll, ll>>> v;
priority_queue<pair<ll, ll>> wait;

int main() {
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld %lld", &a, &t);
        v.push_back(make_pair(a, make_pair(i, t)));
    }

    sort(v.begin(), v.end());

    ll cur = 1, prev = v[0].first + v[0].second.second, ans = 0;
    while(cur < n || !wait.empty()) {
        while(cur < n && v[cur].first <= prev) {
            wait.push(make_pair(v[cur].second.first, cur));
            cur++;
        }

        if(wait.empty() && cur < n) {
            prev = v[cur].first + v[cur].second.second;
            cur++;
        } else if(!wait.empty()) {
            pair<ll, ll> p = wait.top();
            wait.pop();

            ans = max(ans, prev - v[p.second].first);
            prev += v[p.second].second.second;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}