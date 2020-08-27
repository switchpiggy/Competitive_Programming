#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char a[200007];

int main() {
    ll res = 0, r = 0, w = 0;

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] == 'R') r++;
        else w++;
    }

    if(!w || !r) {
        printf("0\n");
        return 0;
    }

    for(ll i = n - 1; i >= n - w; --i) {
        if(a[i] == 'R') res++;
    }

    printf("%lld\n", res);
    return 0;

}