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
ll n, q, p[100007];
set<ll> s;
multiset<ll> diff;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;

    for(ll i = 1; i <= n; ++i) cin >> p[i];

    sort(p + 1, p + n + 1);
    for(ll i = 1; i <= n; ++i) {
        s.insert(p[i]);
        if(i - 1) diff.insert(p[i] - p[i - 1]);
    }

    if(sz(s) < 2) cout << "0\n";
    else cout << *s.rbegin() - *s.begin() - *diff.rbegin() << '\n';

    while(q--) {
        ll t, x;
        cin >> t >> x;
        if(!t) {
            if(x != *s.rbegin()) diff.erase(diff.find(*s.upper_bound(x) - x));
            if(x != *s.begin()) diff.erase(diff.find(x - *prev(s.lower_bound(x))));
            if(x != *s.begin() && x != *s.rbegin()) diff.insert(*s.upper_bound(x) - *prev(s.lower_bound(x)));
            s.erase(x);
        } else {
            if(sz(s) && x < *s.begin()) diff.insert(*s.begin() - x);
            else if(sz(s) && x > *s.rbegin()) diff.insert(x - *s.rbegin());
            else if(sz(s)) {
                diff.insert(*s.upper_bound(x) - x);
                diff.insert(x - *prev(s.upper_bound(x)));
                diff.erase(diff.find(*s.upper_bound(x) - *prev(s.upper_bound(x))));
            }

            s.insert(x);
        }

        if(sz(s) < 2) cout << "0\n";
        else cout << *s.rbegin() - *s.begin() - *diff.rbegin() << '\n';
    }

    return 0;
}