#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;
vector<ll> v;

ll sigFig(ll z) {
    for(ll i = 20; i >= 0; i--) {
        if((z >> i) & 1) return i;
    }

    return -1;
}

bool done(ll z) {
    ll bv = 0;
    z++; 
    while(z%2 == 0) {z/=2; bv++;}
    return (z == 1);
}

int main() {
    scanf("%lld", &x);
    ll i = 0;

    while(!done(x)) {
        i++;
        if(i%2 == 0) {x++; continue;}

        ll r = sigFig(x);
        if((1 << r) != x) r++;  

        x = (x ^ ((1 << r) - 1));
        v.push_back(r);
    }

    printf("%lld\n", i);
    for(auto i : v) printf("%lld ", i);   
}