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
ll cnt[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(char i : s) {
        cnt[i - 'A']++;
    }

    ll cur = 0;
    for(ll i = 0; i < 26; ++i) {
        if(cnt[i]%2 == 1) cur++;
    }

    if(cur > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string res;
    for(ll i = 0; i < 26; ++i) {
        if(cnt[i]%2) continue;
        for(ll j = 0; j < cnt[i]/2; ++j) res += char(i + 'A');
    }

    cout << res;
    if(cur) {
        for(ll i  =0; i < 26; ++i) {
            if(cnt[i]%2 == 1) {
                for(ll j = 0; j < cnt[i]; ++j) cout << char(i + 'A');
                break;
            }
        }
    }

    reverse(all(res));
    cout << res << '\n';
    return 0;
}