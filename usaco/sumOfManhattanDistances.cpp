#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long int ll;
ll x, y, n, a[100007], b[100007], sumx[100007], sumy[100007];

const ll MOD = 1000000007;
 
int main() {
    //freopen("sumdist.in", "r", stdin);
    //freopen("sumdist.out", "w", stdout);
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a[i], &b[i]);
    }
 
    ll res1 = 0, res2 = 0;
    sort(a, a + n);
    sort(b, b + n);

    for(ll i = 1; i < n; ++i) {
        sumx[i] = sumx[i - 1]%MOD + (i * (a[i] - a[i - 1]))%MOD;
        res1 += sumx[i]%MOD;
        res1 %= MOD;
    }
    for(ll i = 1; i < n; ++i) {
        sumy[i] = sumy[i - 1]%MOD + (i * (b[i] - b[i - 1]))%MOD;
        res2 += sumy[i]%MOD;
        res2 %= MOD;
    }
 
    printf("%lld\n", (res1 + res2)%MOD);
 
    return 0;
}