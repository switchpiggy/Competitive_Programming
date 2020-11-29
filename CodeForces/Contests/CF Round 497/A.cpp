#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

bool isvowel(char x) {
    if(x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    bool ok = 1;
    for(ll i = 0; i < (ll)s.length() - 1; ++i) {
        if(s[i] == 'n') continue;
        if(!isvowel(s[i + 1]) && !isvowel(s[i])) {
            ok = 0;
            break;
        }
    }

    if(!isvowel(s.back()) && s.back() != 'n') ok = 0;

    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}