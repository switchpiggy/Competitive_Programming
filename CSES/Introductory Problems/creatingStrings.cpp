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
string s;
set<string> st;
ll fact[10], occ[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    sort(all(s));
    for(char i : s) {
        occ[i - 'a']++;
    }

    fact[0] = 1;
    for(ll i = 1; i <= 10; ++i) fact[i] = fact[i - 1] * i;

    ll ans = fact[sz(s)];
    for(ll i = 0; i < 26; ++i) {
        ans /= fact[occ[i]];
    }

    cout << ans << '\n';

    do {
        st.insert(s);
    } while(next_permutation(all(s)));

    for(auto i = st.begin(); i != st.end(); ++i) {
        cout << *i << '\n';
    }

    return 0;
}