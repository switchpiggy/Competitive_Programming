#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
const int N = 100100;
 
int n, k;
char s[N];
 
inline bool read() {
    if (!(cin >> n >> k)) return false;
    assert(gets(s));
    assert(gets(s));
    return true;
}
 
char t[N];
 
inline void solve() {
    forn(i, n) {
        int d1 = int(s[i] - 'a');
        int d2 = 25 - d1;
        if (d1 > d2) {
            int v = min(d1, k);
            t[i] = char(s[i] - v);
            k -= v;
        } else {
            int v = min(d2, k);
            t[i] = char(s[i] + v);
            k -= v;
        }
    }
    if (k) {
        puts("-1");
        return;
    }
    t[n] = 0;
    puts(t);
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
   
    return 0;
}