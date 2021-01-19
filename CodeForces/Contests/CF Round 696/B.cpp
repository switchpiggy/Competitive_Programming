#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll t, d;
vector<ll> p;
bool composite[100007];

void sieve() {
    for(ll i = 2; i <= 100000; ++i) {
        if(composite[i]) continue;
        for(ll j = i * 2; j <= 100000; j += i) composite[j] = 1;
    }

    for(ll i = 2; i <= 100000; ++i) if(!composite[i]) p.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    sieve();
    sort(p.begin(), p.end());

    while(t--) {
        cin >> d;
        ll last = 1, cntp = 0, ans = 1;
        //cout << (ll)p.size() << '\n';
        for(ll i = 0; i < (ll)p.size(); ++i) {
            if(p[i] >= last + d) {
                cntp++;
                last = p[i];
                ans *= p[i];
            } 

            if(cntp >= 2) break;
        }

        cout << ans << '\n';
    }

    return 0;
}