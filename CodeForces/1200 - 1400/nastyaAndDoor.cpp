#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    scanf("%lld", &t);

    while(t--) {
    	ll pr[200007], a[200007];
        scanf("%lld %lld", &n, &k);
        for(ll i = 0; i < n; ++i) {
        	scanf("%lld", &a[i]);
        	pr[i] = 0;
        }

        for(ll i = 1; i < n - 1; ++i) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) pr[i] = 1;
        }

        for(ll i = 1; i < n; ++i) pr[i] = pr[i] + pr[i - 1];

        ll maxn = 0, l = 0;
        for(ll i = 0; i < n - k + 1; ++i) {
        	//cout << maxn << endl;
        	if(pr[i + k - 2] - pr[i] > maxn) l = i;
            maxn = max(maxn, pr[i + k - 2] - pr[i]);
        }

        printf("%lld %lld\n", maxn + 1, l + 1);
    }
}