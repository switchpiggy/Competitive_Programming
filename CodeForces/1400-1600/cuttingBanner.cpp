#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    string s;
    string c = "CODEFORCES";
    cin >> s;

    ll prefix = 0, suffix = 0;
    for(ll i = 0; i < s.length() && i < 10; ++i) {
        if(s[i] != c[i]) break;
        prefix++;
    }
    for(ll i = 0; i < s.length() && i < 10; ++i) {
        if(s[s.length() - i - 1] != c[10 - i - 1]) break;
        else suffix++;
    }

    if(prefix + suffix < 10) printf("NO\n");
    else printf("YES\n");

    return 0;
}