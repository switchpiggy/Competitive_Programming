#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    ll res = 0;

    for(ll i = n; i < s.length(); i += n) {
        if(s[i - 1] == s[i - 2] && s[i - 3] == s[i - 2]) res++;
    }

    printf("%lld\n", res);

    return 0;
}