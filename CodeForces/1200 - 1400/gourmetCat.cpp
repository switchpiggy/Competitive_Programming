#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, week[3], res = 0, days[7] = {0, 1, 2, 0, 2, 1, 0};

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    week[0] = a/3, week[1] = b/2, week[2] = c/2;

    ll minwk = min(week[0], min(week[1], week[2]));
    a -= minwk * 3, b -= minwk * 2, c -= minwk * 2;
    
    vector<ll> f(3);
    f[0] = a, f[1] = b, f[2] = c;

    for(ll s = 0; s < 7; ++s) {
        ll day = s, cnt = 0;
        vector<ll> d = f;

        while(d[days[day]]) {
            --d[days[day]];
            ++cnt;
            day = (day + 1)%7;
        }
        res = max(7 * minwk + cnt, res);
    }

    printf("%lld\n", res);
    return 0;
}