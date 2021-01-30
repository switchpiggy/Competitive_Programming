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
ll t, n, l[300007], r[300007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        for(ll i = 0; i <= n; ++i) {
            r[i] = 0, l[i] = 0;
        }

        for(ll i = n - 1; i >= 0; --i) {
            if(s[i] == 'R' && (i == n - 1 || s[i + 1] == 'R')) {
                r[i] = 1;
            } else if(s[i] == 'R' && s[i + 1] == 'L') {
                r[i] = r[i + 1] + 1;
            } else if(s[i] == 'L' && i < n - 1 && s[i + 1] == 'R') {
                r[i] = r[i + 1] + 1;
            } else if(s[i] == 'L' && i && s[i - 1] == 'R') {
                r[i] = 1;
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(s[i] == 'L' && (!i || s[i - 1] == 'L')) {
                l[i] = 1;
            } else if(s[i] == 'L' && s[i - 1] == 'R') {
                l[i] = l[i - 1] + 1;
            } else if(s[i] == 'R' && i && s[i - 1] == 'L') {
                l[i] = l[i - 1]  + 1;
            } else if(s[i] == 'R' && i < n - 1 && s[i + 1] == 'L') {
                l[i] = 1;
            }
        }

        for(ll i = 0; i <= n; ++i) {
            cout << 1 + (i && s[i - 1] == 'L' ? l[i - 1] : 0) + (s[i] == 'R' ? r[i] : 0) << ' ';
        }

        cout << '\n';
    }

    return 0;
}