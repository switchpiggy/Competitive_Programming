#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n, a, b, t[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    t[0] = 1;
    ll sum = 1;
    for(ll i = 1; i < n; ++i) {
        if(!a && !b) {
            t[i] = 1;
        }else if(b) {
            t[i] = sum + 1; 
            sum += t[i];
            b--;
        } else if(a) {
            if(sum < t[i - 1] + 1) {
                t[i] = sum;
                sum += t[i];
            } else {
                t[i] = t[i - 1] + 1;
                sum += t[i];
                a--;
            }
        }
    }

    if(a || b) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) cout << t[i] << ' ';
    cout << '\n';
    return 0;
}