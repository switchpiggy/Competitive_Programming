#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> res;
    if(n%4 == 0) cout << 0 << '\n';
    else if(n%4 == 3) {
        cout << 0 << '\n';
        res.push_back(1);
        res.push_back(2);
    }
    else if(n%4 == 2) {
        cout << 1 << '\n';
        res.push_back(1);
    }
    else cout << 1 << '\n';

    for(ll i = n%4 + 1; i <= n; i += 4) {
        res.push_back(i);
        res.push_back(i + 3);
    }

    cout << (ll)res.size() << ' ';
    for(ll i : res) cout << i << ' ';

    return 0;
}