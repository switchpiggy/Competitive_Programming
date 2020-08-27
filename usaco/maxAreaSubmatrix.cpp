#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll r, c, a[5007][507];


int main() {
    ll res = 0;

    scanf("%lld %lld", &r, &c);
    for(ll i = 0; i < r; ++i) {
        for(ll j = 0; j < c; ++j) {
            scanf("%lld", &a[i][j]);
            if(i && a[i][j]) a[i][j] += a[i - 1][j];
        }
            stack<ll> s;
            ll maxn = 0, area = 0;

            ll k = 0;
            while(k < c) {
                if(s.empty() || a[i][s.top()] <= a[i][k]) {
                    s.push(k++);
                } else {
                    ll t = s.top();
                    s.pop();
                    area = a[i][t] * k;

                    if(!s.empty()) area = a[i][t] * (k - s.top() - 1);
                }

                maxn = max(maxn, area);
            }

            while(!s.empty()) {
                ll t = s.top();
                s.pop();
                area = a[i][t] * k;
                if(!s.empty()) area = a[i][t] * (k - s.top() - 1);

                maxn = max(maxn, area);
            }

            res = max(res, maxn);
    }

    printf("%lld\n", res);

    return 0;
}