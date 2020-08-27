#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<pair<ll, ll>> v;

void no() {
    cout << "ugly" << endl;
    exit(0);
}

int main() {
    for(ll i = 0; i < 8; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    if(v[0].first == v[1].first && v[1].first == v[2].first && v[2].first != v[3].first && v[3].first == v[4].first && v[4].first != v[5].first && v[5].first == v[6].first && v[6].first == v[7].first && v[0].second == v[3].second && v[3].second == v[5].second && v[0].second != v[1].second && v[1].second == v[6].second && v[6].second != v[2].second && v[2].second == v[4].second && v[4].second == v[7].second) {
        cout << "respectable" << endl;
        return 0;
    }

    no();
}