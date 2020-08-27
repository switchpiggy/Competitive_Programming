#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;

int main() {
    scanf("%lld", &t);

    while(t--) {
    	string s;
    	ll n, m;
        scanf("%lld %lld", &n, &m);
        cin >> s;

        ll pr[n];
		memset(pr, 0, sizeof(pr));
		
        for(ll i = 0; i < m; ++i) {
            ll p;
            scanf("%lld", &p);

            ++pr[p - 1];
        }

        for(ll i = n - 1; i > 0; --i) {
            pr[i - 1] += pr[i];
        }

        ll ans[26];
        memset(ans, 0, sizeof(ans));

        for(ll i = 0; i < n; ++i) {
            ans[s[i] - 'a'] += pr[i] + 1;
        }

        for(ll i = 0; i < 26; ++i) printf("%lld ", ans[i]);
        printf("\n");
    }
}