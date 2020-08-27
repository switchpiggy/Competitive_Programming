#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, q, x, y, t[505][505], r[505];

void getOnes(ll i)
{
	r[i] = 0;
	ll cnt = 0;
	for (ll j = 1; j <= m + 1; j++) {
        if (t[i][j])
			cnt++;
		else
		{
			r[i] = max(r[i], cnt);
			cnt = 0;
		}
    }
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &q);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) scanf("%lld", &t[i][j]);
        getOnes(i);
    }

    while(q--) {
    	//cout << i << endl;
        scanf("%lld %lld", &x, &y);
        t[x][y] ^= 1;

        getOnes(x);
        ll maxs = 0;
        for(ll j = 1; j <= n; ++j) maxs = max(maxs, r[j]);

        printf("%lld\n", maxs);
    }
}