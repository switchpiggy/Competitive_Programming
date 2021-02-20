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
vector<ll> x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        x.clear();
        y.clear();
        for(ll i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }

        sort(all(x));
        sort(all(y));

        ll cx = 0, cy = 0;
        for(ll i = 0; i < sz(x); ++i) {
            if(sz(x)%2 == 1 && x[i] == x[sz(x)/2]) cx++;
            else if(sz(x)%2 == 0 && (x[i] == x[sz(x)/2] || x[i] == x[sz(x)/2 - 1])) cx++;
        }

        for(ll i = 0; i < sz(y); ++i) {
            if(sz(y)%2 == 1 && y[i] == y[sz(y)/2]) cy++;
            else if(sz(y)%2 == 0 && (y[i] == y[sz(y)/2] || y[i] == y[sz(y)/2 - 1])) cy++;
        }

        if(sz(x)%2 == 1) cx = 1;
        else cx = x[sz(x)/2] - x[sz(x)/2 - 1] + 1;

        if(sz(y)%2 == 1) cy = 1;
        else cy = y[sz(y)/2] - y[sz(y)/2 - 1] + 1;

        cout << cx * cy << '\n';
    }

    return 0;
}