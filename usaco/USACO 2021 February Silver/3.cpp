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
ll n, occ[507][507][3], a;

auto start = std::chrono::high_resolution_clock::now(); 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            a = 2;
            ll x;
            if(a < 100) x = 0;
            else if(a == 100) x = 1;
            else x = 2;
        }
    }


    ll ans = 0;
    for(ll l = 0; l < n; ++l) {
        for(ll r = l; r < n; ++ r) {
        }
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << duration.count() << '\n';
    cout << ans << '\n';
    return 0;
}