#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, pref[200007], ans = 0;
char c;
vector<pair<ll, char>> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> d >> c;
        v.push_back(make_pair(d, c));
    }

    v.push_back(make_pair(1000000007, '.'));

    sort(v.begin(), v.end());

    for(ll i = 0; i < n; ) {
        ll cur = 1;
        while(i + cur < n && v[i].second == v[i + cur].second) ++cur;
        ans = max(ans, v[i + cur - 1].first - v[i].first);
        i += cur;
    }

    ll p = 0;
    
    memset(pref, 63, sizeof(pref));

    for(ll i = 0; i < n; ++i) {
        pref[n + p] = min(pref[n + p], v[i].first);
        if(v[i].second == 'G') p++;
        else p--;
        ans = max(ans, v[i].first - pref[n + p]);
    }
    
	printf("%lld\n", ans);

    return 0;
}