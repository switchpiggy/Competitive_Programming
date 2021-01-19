#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, p, w, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> w >> d;
    for(ll i = 0; i <= w && i * d <= p; ++i) {
        if((p - i * d)%w == 0 && (p - i * d)/w + i <= n) {
            cout << (p - i * d)/w << ' ' << i << ' ' << n - (i + (p - i * d)/w) << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}