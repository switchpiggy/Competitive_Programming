#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n, add = 1, sub;
vector<char> ops;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
    ops.push_back('+');
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == ' ' || s[i] == '?' || s[i] == '=') continue;
        if(isdigit(s[i])) {
            n = (n * 10) + (s[i] - '0');
            continue;
        }

        if(s[i] == '+') add++;
        else sub++;
        ops.push_back(s[i]);
    }

    ll maxnet = n * add - sub, minet = add - n * sub;
    if(n > maxnet || n < minet) {
        cout << "Impossible\n";
        return 0;
    }

    vector<ll> res;
    ll cur = 0;
    for(ll i = 0; i < (ll)ops.size(); ++i) {
        if(ops[i] == '+') add--;
        else sub--;

        ll dir = ((ops[i] == '+') ? 1 : -1);
        for(ll j = 1; j <= n; ++j) {
            ll maxn = cur + (j * dir) + add * n - sub, minn = cur + (j * dir) + add - sub * n;
            if(minn <= n && n <= maxn) {
                res.push_back(j);
                cur += dir * j;
                break;
            }
        }
    }

    cout << "Possible\n";
    for(ll i = 0; i < (ll)res.size(); ++i) {
        cout << res[i] << ' ';
        if(i < (ll)ops.size() - 1) cout << ops[i + 1] << ' ';
    }
    cout << "= ";
    cout << n << '\n';
    return 0;
}