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
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(n == 2) cout << "6\n";
    else if(k == 1) cout << 6 + 2 * (n - 2) + n - 2 << '\n';
    else if(k == n) cout << 6 + 2 * (n - 2) + n - 2 << '\n';
    else cout << 6 + 2 * (n - 2) + min(max(0ll, k - 2), max(0ll, n - (k + 1))) + n - 1 << '\n';
    return 0;
}