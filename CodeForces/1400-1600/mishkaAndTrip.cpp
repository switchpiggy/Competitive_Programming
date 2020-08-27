#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, c[100007];
bool capital[100007];
ll res = 0, sum = 0;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &c[i]);
        sum += c[i];
    }

    for(ll i = 0; i < k; ++i) {
        ll temp;
        scanf("%lld", &temp);
        temp--;
        capital[temp] = 1;
    }

    for(ll i = 0; i < n; ++i) {
        //cout << c[i] <<  ' ' << c[(i + 1)%n] << endl;
        if(!capital[i] && !capital[(i + 1)%n]) res += c[i] * c[(i + 1)%n];
    }

    for(ll i = 0; i < n; ++i) {
        if(!capital[i]) continue;
        res += c[i] * (sum - c[i]);
        sum -= c[i];
    }

    printf("%lld\n", res);
    return 0;
}