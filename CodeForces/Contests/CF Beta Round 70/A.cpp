#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t, u;

bool isvowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
    getline(cin, t);
    getline(cin, u);
    ll a = 0, b = 0, c = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(isvowel(s[i])) a++;
    }

    for(ll i = 0; i < (ll)t.length(); ++i) {
        if(isvowel(t[i])) b++;
    }

    for(ll i = 0; i < (ll)u.length(); ++i) if(isvowel(u[i])) c++;

    cout << ((a == 5 && b == 7 && c == 5) ? "YES\n" : "NO\n");
}