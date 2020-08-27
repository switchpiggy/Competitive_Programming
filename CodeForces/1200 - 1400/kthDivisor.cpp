#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<ll> f;

int main() {
    scanf("%lld %lld", &n, &k);

    ll cnt = 0;
    for(ll i = 1; i <= sqrt(n); ++i) {
        if(n%i == 0) {
            cnt++;
            if(n/i != i) f.push_back(n/i);
            if(cnt == k) {
                printf("%lld\n", i);
                return 0;
            }
        }
    }

    sort(f.begin(), f.end());

    for(ll i = 0; i < f.size(); ++i) {
        cnt++;
        if(cnt == k) {
            printf("%lld\n", f[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}