#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, t, temp;

int main() {
    scanf("%lld", &t);
    for(ll tc = 1; tc <= t; ++tc) {
    	vector<set<ll>> col(105);
		vector<set<ll>> row(105);
        ll trace = 0, c = 0, r = 0;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                scanf("%lld", &temp);
                col[j].insert(temp);
                row[i].insert(temp);
                if(i == j) trace += temp;
            }
        }
        for(ll i = 1; i <= n; ++i) {
            if(col[i].size() < n) c++;
            if(row[i].size() < n) r++;
        }
        printf("Case #%lld: %lld %lld %lld\n", tc, trace, r, c);
    }
}