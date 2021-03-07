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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll t, h, m;
string k;

bool a(char a) {
    if(a == '0' || a == '2' || a == '5' || a == '8' || a == '1') return 1;
    return 0;
}

ll ref(string x) {
    string res;
    for(ll i = sz(x) - 1; i >= 0; --i) {
        if(x[i] == '5') res += '2';
        else if(x[i] == '2') res += '5';
        else res += x[i];
    }

    if(res[0] == '0') res.erase(0, 1);
    return stoll(res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> h >> m >> k;
        ll nh = (10 * (k[0] - '0') + (k[1] - '0')), nm = (10 * (k[3] - '0') + (k[4] - '0'));
        bool ok = 0;
        for(ll i = 0; i <= h; ++i) {
            string s = to_string((nh + i)%h);
            if(sz(s) == 1) s = '0' + s;
            // cout << s << '\n';
            if(!a(s[0]) || !a(s[1])) continue;

            ll q = ref(s);
            if(q >= m) continue;

            ll curm = (i ? 0 : nm);
            while(curm < m) {
                s = to_string(curm);
                if(sz(s) == 1) s = '0' + s;
                if(!a(s[0]) || !a(s[1])) {
                    curm++;
                    continue;
                }

                q = ref(s);

                if(q < h && q >= 0) {
                    if((nh + i)%h < 10) cout << '0';
                    cout << (nh + i)%h << ':';
                    if(curm < 10) cout << '0';
                    cout << curm << '\n';
                    ok = 1;
                    break;
                }

                curm++;
            }

            if(ok) break;
        }
    }

    return 0;
}