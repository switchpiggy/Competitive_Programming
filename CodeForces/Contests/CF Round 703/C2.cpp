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
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    auto q = [](ll x, ll y) {
        cout << "? " << x << ' ' << y << '\n';
        cout.flush();
        return 0;
    };

    auto a = [](ll x) {
        cout << "! " << x << '\n';
        exit(0);
    };

    ll prev, c, l, r, ans;
    q(1, n);
    cin >> prev;

    if(prev > 1) {
        q(1, prev);
        cin >> c;
    }

    if(prev > 1 && c == prev) {
        l = ans = 1;
        r = prev;
    } else {
        l = ans = prev + 1;
        r = n + 1;
    }

    while(l < r) {
        ll mid = (l + r)/2, x;
        if(!(prev > 1 && c == prev)) {
            q(prev, mid);
            cin >> x;
            if(x == prev) {
                ans = mid;
                r = mid;
            } else l = mid + 1;
        } else {
            q(mid, prev);
            cin >> x;
            if(x == prev) {
                ans = mid;
                l = mid + 1;
            } else r = mid;
        }
    }

    a(ans);
    return 0;
}