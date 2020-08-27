#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, p[200007], sum;
vector<ll> pos;

const ll mod = 998244353;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &p[i]);
        if(p[i] >= n - k + 1) { 
            pos.push_back(i);
            sum += p[i];
        }
    }

    ll ans = 1;

    for(ll i = 1; i < pos.size(); ++i) {
        ans *= (pos[i] - pos[i - 1])%mod;
        ans %= mod;
    }

    printf("%lld %lld", sum, ans);


}