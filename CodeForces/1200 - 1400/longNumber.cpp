#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
char s[200007];

int main() {
    scanf("%lld %s", &n, s);
    for(ll i = 1; i <= 9; ++i) scanf("%lld", &a[i]);

    for(ll i = 0; i < n; ++i) {
        if(a[s[i] - '0'] > s[i] - '0') {
            ll j = i;
            while(a[s[j] - '0'] >= s[j] - '0' && j < n) {
                s[j] = a[s[j] - '0'] + '0';
                j++;
            }
            break;
        }
    }

    printf("%s\n", s);
    return 0;
}