#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll q, t, f;
char c;

int main() {
    cin >> s >> q;
    string pref = "", suff = "";
    bool reversed = 0;
    for(ll i = 0; i < q; ++i) {
        cin >> t;
        if(t == 1) {
            reversed = 1 - reversed;
        } else {
            cin >> f >> c;
            if(f == 1) {
                if(reversed) suff += c;
                else pref += c;
            } else {
                if(reversed) pref += c;
                else suff += c;
            }
        }
    }

    reverse(pref.begin(), pref.end());

    s = pref + s + suff;

    if(reversed) reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}