#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> res;
bool composite[1007];

int main() {
    cin >> n;
    for(ll i = 2; i <= n; ++i) {
        if(composite[i]) continue;
        for(ll j = i; j <= n; j *= i) {
            if(composite[j]) continue;
            res.push_back(j);
        }

        for(ll j = i; j <= n; j += i) {
            composite[j] = 1;
        }
    }

    cout << res.size() << endl;
    for(ll i = 0; i < res.size(); ++i) cout << res[i] << ' ';
    cout << endl;

    return 0;
}