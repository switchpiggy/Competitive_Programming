#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, r, p, s;
string st;

int main() {
    scanf("%lld", &t);
    while(t--) {
        cin >> st;
        r = 0, p = 0, s = 0;

        for(ll i = 0; i < st.length(); ++i) {
            if(st[i] == 'R') r++;
            else if(st[i] == 'P') p++;
            else s++;
        }

        ll maxn = max(r, max(p, s));
        char mxchar;

        if(r == maxn) mxchar = 'P';
        else if(s == maxn) mxchar = 'R';
        else mxchar = 'S';

        for(ll i = 0; i < st.length(); ++i) cout << mxchar;
        cout << '\n';
    }

    return 0;
}