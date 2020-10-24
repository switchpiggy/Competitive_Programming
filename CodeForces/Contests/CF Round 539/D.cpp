#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll occ[26];

bool isPal(string x) {

    for(ll i = 0; i < (ll)x.length()/2; ++i) {
        if(x[i] != x[(ll)x.length() - 1 - i]) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    ll n = (ll)s.length();

    for(ll i = 0; i < (ll)s.length(); ++i) occ[s[i] - 'a']++;

    for(ll i = 0; i < 26; ++i) {
        if(occ[i] == n || (occ[i] == n - 1 && n%2 == 1)) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for(ll i = 1; i < n; ++i) {
        string t = s.substr(i) + s.substr(0, i);
        if(isPal(t) && t != s) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 2 << '\n';
    return 0;
}