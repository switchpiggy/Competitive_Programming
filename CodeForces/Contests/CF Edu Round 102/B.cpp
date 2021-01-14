#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll q;
string s, t;

ll lcm(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--) {
        bool ok = 0;
        cin >> s >> t;
        ll len = lcm((ll)s.length(), (ll)t.length());
        string a = "", b = "";
        for(ll i = 0; i < len/(ll)s.length(); ++i) a += s;
        for(ll i = 0; i < len/(ll)t.length(); ++i) b += t;

        if(a == b) cout << a << '\n';
        else cout << "-1\n";
    }

    return 0;
}