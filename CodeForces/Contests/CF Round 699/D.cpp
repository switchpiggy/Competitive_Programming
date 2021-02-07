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
ll t, n, m, in[1007][2], out[1007][2];
char adj[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(in);
        m0(out);
        cin >> n >> m;

        for(ll i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for(ll j = 1; j <= n; ++j) {
                adj[i][j] = s[j - 1];
            }
        }

        bool ok = 0;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(adj[i][j] != '*' && adj[i][j] == adj[j][i]) {
                    cout << "YES\n";
                    for(ll k = 0; k <= m; ++k) {
                        if(k%2 == 0) cout << i << ' ';
                        else cout << j << ' ';
                    }

                    cout << '\n';
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        if(ok) continue;

        if(m%2 == 1) {
            cout << "YES\n";
            for(ll k = 0; k <= m; ++k) {
                if(k%2 == 0) cout << 1 << ' ';
                else cout << 2 << ' ';
                
            }   
            
            cout << '\n';
            continue;
        }

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                if(adj[i][j] == 'a') {
                    out[i][0] = j;
                    in[j][0] = i;
                } else if(adj[i][j] == 'b') {
                    out[i][1] = j;
                    in[j][1] = i;
                }
            }
        }

        for(ll i = 1; i <= n; ++i) {
            if(in[i][0] && out[i][0]) {
                //ll cur = in[i][0];
                cout << "YES\n";
                if(m%4 == 0) {
                    for(ll k = 0; k <= m; ++k) {
                       if(k%4 == 0 || k%4 == 2) cout << i << ' ';
                       else if(k%4 == 1) cout << out[i][0] << ' ';
                       else cout << in[i][0] << ' ';
                    }
                } else {
                    for(ll k = 0; k <= m; ++k) {
                       if(k%4 == 0) cout << in[i][0] << ' ';
                       else if(k%4 == 1 || k%4 == 3) cout << i << ' ';
                       else cout << out[i][0] << ' ';
                    }
                }

                cout << '\n';
                ok = 1;
                break;
            } else if(in[i][1] && out[i][1]) {
                //ll cur = in[i][0];
                cout << "YES\n";
                if(m%4 == 0) {
                    for(ll k = 0; k <= m; ++k) {
                       if(k%4 == 0 || k%4 == 2) cout << i << ' ';
                       else if(k%4 == 1) cout << out[i][1] << ' ';
                       else cout << in[i][1] << ' ';
                    }
                } else {
                    for(ll k = 0; k <= m; ++k) {
                       if(k%4 == 0) cout << in[i][1] << ' ';
                       else if(k%4 == 1 || k%4 == 3) cout << i << ' ';
                       else cout << out[i][1] << ' ';
                    }
                }

                cout << '\n';
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "NO\n";
    }

    return 0;
}