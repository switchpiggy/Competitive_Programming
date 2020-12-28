#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s >> v;
        ll a = 0, b = 0, c = 0;
        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(s[i] == v[i]) {
                c++;
                continue;
            }
            ok = 0;
            if(s[i] - '0' > v[i] - '0') a++;
            else b++;
        }

        if(ok || a == b) cout << "EQUAL\n";
        else if(a > b) cout << "RED\n";
        else cout << "BLUE\n";
        //cout << a << ' ' << b << '\n';
    }
}