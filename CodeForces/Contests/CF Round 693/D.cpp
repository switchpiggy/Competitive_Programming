#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, t;
pbenqueue<ll> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            ben.push(a);
        }

        ll turn = 0, a = 0,b = 0;
        while(!ben.empty()) {
            ll f = ben.top();
            //cout << f << '\n';
            ben.pop();
            if(turn%2 == 0) {
                if(f%2 == 0) a += f;
            } else {
                if(f%2 == 1) b += f;
            }
            turn++;
        }

        if(a > b) cout << "Alice\n";
        else if(a == b) cout << "Tie\n";
        else cout << "Bob\n";
    }

    return 0;
}