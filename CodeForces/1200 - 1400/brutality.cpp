#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007];
string s;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    cin >> s;

    ll sum = 0;

    for(ll i = 0, j = 0; i < n; i = j) {
        while(j < n && s[i] == s[j]) j++;
        sort(a + i, a + j);
        reverse(a + i, a + j);

        for(ll q = i; q < min(i + k, j); ++q) {
            sum += a[q];
        }
    }

    printf("%lld\n", sum);

    return 0;
}