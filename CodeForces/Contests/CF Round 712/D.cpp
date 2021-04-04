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
ll n, a, r1, c1, c2, r2;

void place(ll b, ll i, ll j) {
    cout << b << ' ' << i + 1 << ' ' << j + 1 << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    c2 = 1;

    for(ll q = 0; q < n * n; ++q) {
        cin >> a;
        if(a != 1 && r1 < n) {
            place(1, r1, c1);
            c1 += 2;
            if(c1 >= n) {
                r1++;
                if(r1%2) c1 = 1;
                else c1 = 0;
            }
        } else if(a != 2 && r2 < n) {
            place(2, r2, c2);
            c2 += 2;
            if(c2 >= n) {
                r2++;
                if(r2%2) c2 = 0;
                else c2 = 1;
            }
        } else {
            if(r2 == n) {
                if(a != 1) place(1, r1, c1);
                else place(3, r1, c1);
                c1 += 2;
                if(c1 >= n) {
                    r1++;
                    if(r1%2) c1 = 1;
                    else c1 = 0;
                }
            } else {
                if(a != 2) place(2, r2, c2);
                else place(3, r2, c2);
                c2 += 2;
                if(c2 >= n) {
                    r2++;
                    if(r2%2) c2 = 0;
                    else c2 = 1;
                }
            }
        }
    }

    return 0;
}