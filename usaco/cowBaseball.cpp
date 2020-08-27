#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans;
vector<ll> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            ll l = lower_bound(v.begin(), v.end(), v[j] + (v[j] - v[i])) - v.begin(), r = lower_bound(v.begin(), v.end(), v[j] + 2 * (v[j] - v[i]) + 1) - v.begin();
            	ans += r - l;
    	}
    }

    printf("%lld\n", ans);

    return 0;
}