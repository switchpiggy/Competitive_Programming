#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll dollar = 0, cent = 0;
    string cur;
    cin >> s;
    for(ll i = 0; i < sz(s); ++i) {
        if('a' <= s[i] && s[i] <= 'z') {
            if(sz(cur)) {
                ll dot = sz(cur);
                for(ll j = 0; j < sz(cur); ++j) {
                    if(cur[j] == '.') {
                        dot = j;
                    }
                }

                string d, c;
                for(ll j = 0; j < sz(cur); ++j) {
                    if(cur[j] == '.') continue;
                    if(j < dot || dot != sz(cur) - 3) d += cur[j];
                    else if(dot == sz(cur) - 3) c += cur[j];
                }

                dollar += stoll(d);
                if(!c.empty()) cent += stoll(c);
            }

            cur = "";
        } else cur.push_back(s[i]);
    }

    if(sz(cur)) {
            ll dot = sz(cur);
            for(ll j = 0; j < sz(cur); ++j) {
                if(cur[j] == '.') {
                    dot = j;
                }
            }

            string d, c;
            for(ll j = 0; j < sz(cur); ++j) {
                if(cur[j] == '.') continue;
                if(j < dot || dot != sz(cur) - 3) d += cur[j];
                else if(dot == sz(cur) - 3) c += cur[j];
            }

            dollar += stoll(d);
            if(!c.empty()) cent += stoll(c);
    }

    dollar += cent/100;
    cent %= 100;

    string res = to_string(dollar);
    for(ll i = 0; i < sz(res); ++i) {
        cout << res[i];
        if((sz(res) - i - 1)%3 == 0 && i < sz(res) - 1) {
            cout << '.';
        }
    }

    if(!cent) return 0;
    cout << '.';
    if(cent < 10) cout << '0';
    cout << cent << '\n';
    //cout << stoll("09") << '\n';
    return 0;
}