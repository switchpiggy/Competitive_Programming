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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
string s, t = "Bulbasaur";
map<char, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(char i : s) {
        occ[i]++;
    }

    ll ans = LLONG_MAX;
    for(char i : t) {
        ans = min(ans, occ[i]);
    }    

    ans = min(ans, occ['a']/2);
    ans = min(ans, occ['u']/2);
    cout << ans << '\n';
    return 0;
}