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
ll h, w;
char a[17][17];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) cin >> a[i][j];
    }

    ll ans = 0;
    for(ll i = 1; i < h - 1; ++i) {
        for(ll j = 1; j < w - 1; ++j) {
            if(a[i - 1][j] == '.' && (a[i][j - 1] == '.' || a[i - 1][j - 1] == '#') && a[i][j] == '#') ans++;
            if(a[i + 1][j] == '.' && (a[i][j - 1] == '.' || a[i + 1][j - 1] == '#') && a[i][j] == '#') ans++;
            if(a[i][j - 1] == '.' && a[i][j] == '#' && (a[i - 1][j] == '.' || a[i - 1][j - 1] == '#')) ans++;
            if(a[i][j + 1] == '.' && a[i][j] == '#' && (a[i - 1][j] == '.' || a[i - 1][j + 1] == '#')) ans++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}