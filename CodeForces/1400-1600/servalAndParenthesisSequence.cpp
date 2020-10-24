#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    ll f = 0, b = 0, m = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '?') m++;
        else if(s[i] == '(') f++;
        else b++;
    }

    if(abs(f - b) > m || (m - abs(f - b))%2 != 0) {
        cout << ":(\n";
        return 0;
    }

    ll a = (m - abs(f - b))/2, c = (m -  abs(f - b))/2;
    if(f > b) c += abs(f - b);
    else a += abs(f - b);

    //cout << a << ' ' << c << '\n';

    ll cur = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] != '?') continue;
        if(cur < a) {
            s[i] = '(';
        } else {
            s[i] = ')';
        }
        cur++;
    }

    if(s[0] == ')' || s.back() == '(') {
        cout << ":(\n";
        return 0;
    }

    //cout << s << '\n';

    ll pref = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '(') pref++;
        else pref--;

        if(i != n - 1 && pref == 0) {
            cout << ":(\n";
            return 0;
        }
    }

    if(pref != 0) {
        cout << ":(\n";
        return 0;
    }

    cout << s << '\n';
    return 0;
}