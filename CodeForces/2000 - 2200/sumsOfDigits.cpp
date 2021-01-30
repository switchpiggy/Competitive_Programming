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
ll n, b[307];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> b[i];

    string last;
    ll c = b[0];
    while(c) {
        if(c >= 9) {
            last += '9';
            c -= 9;
        } else {
            last += char(c + '0');
            c = 0;
        }
    }

    cout << last << '\n';
    for(ll i = 1; i < n; ++i) {
        string mins = to_string(b[i]%9) + string(b[i]/9, '9');
        if(sz(mins) > sz(last) || mins > last) {
            if(mins[0] == '0') mins.erase(0, 1);
            cout << mins << "\n";
            //cout << last << '\n';
            last = mins;
            continue;
        }

        ll sum = 0;
        for(ll j = sz(last) - 1; j >= 0; --j) {
            sum += (last[j] - '0');
        }

        while(sz(last) < 340) last = "0" + last;

        for(ll j = 339; j >= 0; --j) {
            if(last[j] == '9') {
                sum -= 9;
                continue;
            }

            if(sum + 1 + 9 * (sz(last) - j - 1) >= b[i] && sum + 1 <= b[i]) {
                //cout << "ejsiof\n";
                string t(last.substr(0, j + 1));
                //cout << t << '\n';
                t.back()++;
                ll cur = b[i] - sum - 1;
                string tt;
                while(sz(tt) < sz(last) - j - 1) {
                    if(cur >= 9) {
                        cur -= 9;
                        tt += '9';
                    } else {
                        tt += to_string(cur);
                        //cout << cur << '\n';
                        cur = 0;
                    }
                }

                reverse(tt.begin(), tt.end());
                while(!t.empty() && t[0] == '0') {
                    t.erase(0, 1);
                }

                cout << t + tt << '\n';
                last = t + tt;
                break;
            }

            sum -= (last[j] - '0');
        }
    }

    return 0;
}