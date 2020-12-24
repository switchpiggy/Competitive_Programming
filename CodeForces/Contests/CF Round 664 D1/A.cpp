#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, m;
vector<ll> les, more;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> m;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if(a > m) more.push_back(a);
        else les.push_back(a);
    }

    if(!more.size()) {
        ll sum = 0;
        for(ll i : les) sum += i;
        cout << sum << '\n';
        return 0;
    }
    
    sort(more.begin(), more.end());
    sort(les.begin(), les.end());
    les.push_back(0);
    more.push_back(0);
    reverse(more.begin(), more.end());
    reverse(les.begin(), les.end());

    for(ll i = 1; i < (ll)more.size(); ++i) more[i] += more[i - 1];
    for(ll i = 1; i < (ll)les.size(); ++i) les[i] += les[i - 1];
    //cout << more.back() << ' ' << les.back() << '\n';

    ll c = les.back();
    for(ll i = (ll)les.size(); i <= n; ++i) les.push_back(c);

    ll ans = 0;
    for(ll i = ((ll)more.size() + d)/(d + 1); i <= (ll)more.size(); ++i) {
        if((i - 1) * (d + 1) + 1 <= n) ans = max(ans, more[i] + les[n - (i - 1) * (d + 1) - 1]);
    }

    cout << ans << '\n';
    return 0;
}