#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, ans[100005];
vector<ll> v[100005];

int main() {
    scanf("%lld", &n);
    for(ll i = 1; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
        ans[i] = -1;
    }

    pair<ll, ll> maxn(0, 0);
    for(ll i = 1; i <= n; ++i) {
        maxn = max(maxn, make_pair((ll)v[i].size(), i));
    }

    ll cur = 0;

    for(ll i: v[maxn.second]) {
        ans[i] = cur++;
    }
    
    for(int i = 1; i < n; ++i) {
        if(ans[i] == -1) {
            ans[i] = cur++;
        }
        printf("%lld\n", ans[i]);
    }
}