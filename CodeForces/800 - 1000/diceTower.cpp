#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool check(ll x) {
    ll t = x%14;
    ll d = x - x%14;
    if(t >= 1 && t <= 6 && d >= 1) return true;
    return false;
}

int main() {
    ll t, temp;
    scanf("%lld", &t);

    while(t--) {

        scanf("%lld", &temp);
        if(check(temp)) printf("YES\n");
        else printf("NO\n");
    }
}