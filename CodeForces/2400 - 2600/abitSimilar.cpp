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
ll q, n, k, r[1000007];
bool cnt[2000007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--) {
        m0(cnt);

        cin >> n >> k >> s;
        ll a = min(k, (ll)ceil(log2(n - k + 2)));

        r[n] = INF;

        for(ll i = n - 1; i >= 0; --i) if(s[i] == '0') r[i] = i;
        else r[i] = r[i + 1];
        
        for(ll i = k - a; i < n - a + 1; ++i) {
            if(r[i - k + a] < i) continue;
            ll cur = 0;
            for(ll j = 0; j < a; ++j) cur = 2 * cur + (1 - (s[j + i] - '0'));
            cnt[cur] = 1;
        }

        string ans;
        for(ll i = 0; i < (1 << a); ++i) {
            if(cnt[i]) continue;
            for(ll j = 0; j < a; ++j) if(i & (1 << j)) ans += '1';
            else ans += '0';
            reverse(all(ans));
            break;
        }

        if(ans.empty()) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        //cout << a << '\n';
        cout << string(k - a, '0') + ans << "\n";
    }

    return 0;
}