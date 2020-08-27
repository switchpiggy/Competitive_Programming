#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[807];
vector<pair<ll, pair<ll, ll>>> v;
bool used[807];

bool cmp(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
	if(x.first == y.first) {
		return x.second.first < y.second.first;
	}
	
	return x.first > y.first;
}

int main() {
    scanf("%lld", &n);

    for(ll i = 1; i <= 2 * n; ++i) {
        for(ll j = 1; j < i; ++j) {
            ll temp;
            scanf("%lld", &temp);
            v.push_back(make_pair(temp, make_pair(i, j)));
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(ll i = 0; i < v.size(); ++i) {
        if(!used[v[i].second.second] && !used[v[i].second.first]) {
            used[v[i].second.second] = used[v[i].second.first] = 1;
            ans[v[i].second.second] = v[i].second.first;
            ans[v[i].second.first] = v[i].second.second;
        }
    }

    for(ll i = 1; i <= 2 * n; ++i) printf("%lld ", ans[i]);

    return 0;
}