#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, t,a ,b;
vector<pair<ll, ll>> w;

int main() {
    cin >> n >> m >> k >> t;
    for(ll i = 0; i < k; ++i) {
        cin >> a >> b;
        w.push_back(make_pair(a, b));
    }

    sort(w.begin(), w.end());

    for(ll i = 0; i < t; ++i) {
        cin >> a >> b;
        auto itr = lower_bound(w.begin(), w.end(), make_pair(a, b));
        if(*itr == make_pair(a, b)) cout << "Waste" << endl;
        else {
            itr--;
            ll c = (itr - w.begin());
            ll d = ((a - 1) * m) + b - c;
            if(d%3 == 0) cout << "Kiwis" << endl;
            else if(d%3 == 1) cout << "Grapes" << endl;
            else cout << "Carrots" << endl;
        }
    }

    return 0;
}