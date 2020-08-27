#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
char c;
ll n, s, a[400007];

int main() {
    scanf("%lld", &n);
    ll l = 200000, r = 200001;
    for(ll i = 0; i < n; ++i) {
        cin >> c >> s;
        if(c == 'L') {
            a[s] = l--;
        } else if(c == 'R') {
            a[s] = r++;
        } else {
            printf("%lld\n", min(a[s] - l - 1, r - a[s] - 1));
        }
    }

    return 0;
}