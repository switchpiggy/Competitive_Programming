#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        if(i%2) printf("1");
        else printf("0");
    }
}