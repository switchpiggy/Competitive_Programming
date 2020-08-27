#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll  p, d;

ll nines(ll x) {
    string s = to_string(x);
    ll cnt = 0;
    for(ll i = s.length() - 1; i >= 0; --i) {
        if(s[i] != '9') break;
        cnt++;
    }

    return cnt;
}

int main() {
    cin >> p >> d;
    ll ans = nines(p), cur = 10, res = p;
    while(1) {
        ll diff = p%cur + 1;
        if(diff > d || p - diff < 0) break;
        if(nines(p - diff) > ans) {
            ans = nines(p - diff);
            res = p - diff;
        }
        cur *= 10;
    }

    cout << res << endl;
    return 0;
}