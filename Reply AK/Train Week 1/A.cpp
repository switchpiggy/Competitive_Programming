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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.txt", "w", stdout);
    freopen("input-party-2b0e.txt", "r", stdin);
    int t;
    cin >> t;
    for (int l = 1; l <= t; l ++) {
        cout << "Case #" << l << ":" << " ";
        int n;
        cin >> n;
        int maxn = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a > 0) {
                maxn += a;
            }
        }
        cout << maxn << endl;

    }
}