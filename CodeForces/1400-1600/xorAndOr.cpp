#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;
    if((ll)s.length() != (ll)t.length()) {
        cout << "NO\n";
        return 0;
    }

    bool ok = 0, ok1 = 0;
    for(ll i = 0; i < s.length(); ++i) if(s[i] == '1') ok = 1;
    for(ll i = 0; i < t.length(); ++i) if(t[i] == '1') ok1 = 1;

    if((ok && ok1) || (!ok1 && !ok)) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}