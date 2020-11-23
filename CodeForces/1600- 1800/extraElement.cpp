#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
pair<ll, ll> a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    set<ll> t;
    for(ll i = 2; i < n; ++i) {
        t.insert(a[i].first - a[i - 1].first);
    }

    if((ll)t.size() <= 1) {
        cout << a[0].second + 1 << '\n';
        return 0;
    }

    t.clear();

    for(ll i = 2; i < n; ++i) {
        //if(i == 1) continue;
        if(i == 2) t.insert(a[i].first - a[i - 2].first);
        else t.insert(a[i].first - a[i - 1].first);
    }

    if((ll)t.size() <= 1) {
        cout << a[1].second + 1 << '\n';
        return 0;
    }

    ll cnt = 0;
    ll diff = a[1].first - a[0].first;
    for(ll i = 1; i < n; ++i) {
        if(a[i].first - a[i - 1].first != diff) {
            if((i < n - 1 && a[i + 1].first - a[i - 1].first != diff) || cnt) {
                cout << "-1\n";
                return 0;
            }

            cnt++;
            i++;
        }
    }

    for(ll i = 1; i < n; ++i) {
        if(a[i].first - a[i - 1].first != diff) {
            cout << a[i].second + 1 << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}