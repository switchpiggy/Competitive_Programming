#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<ll> x, y;
bool s[100007], t[100007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }

    ll i = 0, j = 0;
    while(i < x.size() && j < y.size() && i + j < n) {
        if(x[i] <= y[j]) {
            s[i] = 1;
            i++;
        } else {
            t[j] = 1;
            j++;
        }
    }

    while(j < y.size() && i + j < n) {
        t[j] = 1;
        j++;
    }

    while(i < x.size() && i + j < n) {
        s[i] = 1;
        i++;
    }

    for(ll i = 0; i < n/2; ++i) {
        s[i] = t[i] = 1;
    }

    if(n%2 == 1) {
        if(x[n/2] < y[n/2]) s[n/2] = 1;
        else t[n/2] = 1;
    }

    for(ll i = 0; i < n; ++i) printf("%d", s[i]);
    printf("\n");
    for(ll i = 0; i < n; ++i) printf("%d", t[i]);

    return 0;
}