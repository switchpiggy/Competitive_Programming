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

    ll l = 1, r = n, prev;
    q(1, n);
    cin >> prev;

    while(l < r) {
        if(r - l < 3) break;
        ll mid = (l + r)/2;
        ll lx, rx;
        q(l, mid);
        cin >> lx;
        q(mid + 1, r);
        cin >> rx;
        if(prev == lx) {
            r = mid;
            prev = lx;
        } else if(prev == rx) {
            l = mid + 1;
            prev = rx;
        } else {
            if(prev <= mid) {
                l = mid + 1;
                prev = rx;
            } else {
                r = mid;
                prev = lx;
            }
        }
    }

    if(l == r) {
        a(l);
    } else if(r - l == 1) {
        q(l, r);
        ll x;
        cin >> x;        
        if(x == l) a(r);
        else a(l);
    } else if(r - l == 2) {
        q(l, r);
        ll x;
        cin >> x;
        if(x == r) {
            ll y;
            q(l + 1, r);
            cin >> y;
            if(y == x) a(l + 1);
            else a(l);
        } else if(x == l) {
            ll y;
            q(l, l + 1);
            cin >> y;
            if(y == x) a(l + 1);
            else a(r);
        } else {
            ll y;
            q(l, l + 1);
            cin >> y;
            if(y == x) a(l);
            else a(r);
        }
    }

    return 0;
}