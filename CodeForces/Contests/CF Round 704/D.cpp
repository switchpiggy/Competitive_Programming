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
ll a, b, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> k;
    if(!k) {
        string res = string(b, '1') + string(a, '0');
        cout << "Yes\n" << res << '\n' << res << '\n';
        return 0;
    }

    if(k > a + b - 2 || b == 1 || !a) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    string s = string(b, '1') + string(a, '0'), t = string(b - 1, '1') + string(min(a, k), '0') + "1" + string(a - min(a, k), '0');
    ll cur = b - 1;
    k -= min(a, k);

    while(k--) {
        t[cur] = '1';
        t[cur - 1] = '0';
        cur--;
    }

    cout << s << '\n' << t << '\n';
    return 0;
}