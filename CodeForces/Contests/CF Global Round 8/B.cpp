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
ll n, cnt[10];
string s = "codeforces";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i < 10; ++i) cnt[i] = 1;
    cin >> n;

    ll p = 1;
    while(p < n) {
        for(ll i = 0; i < 10; ++i) {
            if(p >= n) break;
            p /= cnt[i];
            cnt[i]++;
            p *= cnt[i];
        }
    }

    for(ll i = 0; i < 10; ++i) cout << string(cnt[i], s[i]);
    return 0;
}