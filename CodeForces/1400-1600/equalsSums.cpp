#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll k;
	vector<pair<ll, pair<ll, ll>>> a;
	
    scanf("%lld", &k);
    for(ll i = 0; i < k; ++i) {
        ll n;
        scanf("%lld", &n);

        vector<ll> v(n);
        for(ll j = 0; j < n; ++j) scanf("%lld", &v[j]);

        ll sum = accumulate(v.begin(), v.end(), 0);

        for(ll j = 0; j < n; ++j) {
            a.push_back(make_pair(sum - v[j], make_pair(i, j)));
        }
        
    }

    stable_sort(a.begin(), a.end());

    for(int i = 0; i < int(a.size()) - 1; ++i) {
        if(a[i].first == a[i + 1].first && (a[i].second.first != a[i + 1].second.first)) {
            printf("YES\n");
            printf("%lld %lld\n", a[i + 1].second.first + 1, a[i + 1].second.second + 1);
            printf("%lld %lld\n", a[i].second.first + 1, a[i].second.second + 1);
            return 0;
        }
    }

    printf("NO\n");
}