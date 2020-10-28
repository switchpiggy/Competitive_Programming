#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    bool ok = 0;
    bool cur = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(i + 2 < (ll)s.length() && s.substr(i, 3) == "WUB") {
            if(ok && !cur) cout << ' ';
            i += 2;
            cur = 1;
        } else {
            ok = 1;
            cur = 0;
            cout << s[i];
        }
    }

    return 0;
}