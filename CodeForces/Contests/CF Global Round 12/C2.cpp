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
ll t, n;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        ll cnt[3][2] = {{0, 0}, {0, 0}, {0, 0}}, x = 0;

        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v.push_back(s);
            for(ll j = 0; j < n; ++j) {
                ll k = (i + j)%3;
                if(v[i][j] == 'O') cnt[k][0]++, x++;
                else if(v[i][j] == 'X') cnt[k][1]++, x++;
            }
        }

        bool ok = 0;
        for(ll i = 0; i < 3; ++i) {
            for(ll j = 0; j < 3; ++j) {
                if(i == j) continue;
                if(cnt[i][0] + cnt[j][1] > x/3) continue;
                for(ll a = 0; a < n; ++a) {
                    for(ll b = 0; b < n; ++b) {
                        ll k = (a + b)%3;
                        if(k == i && v[a][b] == 'O') v[a][b] = 'X';
                        if(k == j && v[a][b] == 'X') v[a][b] = 'O';
                    }

                    cout << v[a] << '\n';
                }

                ok = 1;
                break;
            }

            if(ok) break;
        }
    }

    return 0;
}