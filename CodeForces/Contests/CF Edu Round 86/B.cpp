#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s;

        bool ok = 0;
        for(ll i = 0; i < (ll)s.length() - 1; ++i) {
            if(s[i] != s[i + 1]) ok = 1;
        }

        if(!ok) {
            cout << s << '\n';
            continue;
        }

        for(ll i = 0; i < (ll)s.length(); ++i) {
            cout << "10";
        }

        cout << '\n';
    }

    return 0;
}