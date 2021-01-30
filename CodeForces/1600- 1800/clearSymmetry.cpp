#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    if(x == 1) cout << "1\n";
    else if(x == 2) cout << "3\n";
    else if(x == 3) cout << "5\n";
    else if(x <= 5) cout << "3\n";
    else {
        for(ll i = 1; i <= 1000000; i += 2) {
            if((i * i + 1)/2 >= x) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}