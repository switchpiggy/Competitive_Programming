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
ll y, k, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> y >> k >> n;

    ll cur = (y + k - 1)/k * k;

    bool ok = 0;
    for(ll i = cur; i <= n; i += k) if(i > y) cout << i - y << ' ', ok = 1;
    if(!ok) {
        cout << "-1\n";
    }
    cout << '\n';
    return 0;
}