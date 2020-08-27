#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[107];
vector<pair<ll, ll>> v;
ll w;

void no() {
    cout << "-1" << endl;
    exit(0);
}

int main() {
    cin >> n >> w;
    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end());

    for(ll i = n - 1; i >= 0; --i) {
        if(!w) no();
        ans[v[i].second] = min(w, (v[i].first + 1)/2);
        w -= ans[v[i].second];
    }

    for(ll i = n - 1; i >= 0; --i) {
        if(!w) break;
        ll cur = min(w, v[i].first - ans[v[i].second]);
        ans[v[i].second] += cur;
        w -= cur;
    }

    if(w) no();

    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    return 0;

}