#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<long double, long double>> v;

long double fact(ll x) {
    long double ans = 1;
    for(long double i = 1; i <= x; i += 1.0) ans *= i;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        long double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    long double sum = 0;

    //for(ll i = 0; i < n - 1; ++i) sum += sqrt((v[i].first - v[i + 1].first) * (v[i].first - v[i + 1].first) + (v[i].second - v[i + 1].second) * (v[i].second - v[i + 1].second));
    sort(v.begin(), v.end());

    //ll cnt = 0;
    do {
        //long double cur = 0;
        for(ll i = 0; i < n - 1; ++i) {
            //cout << v[i].first << ' ' << v[i].second << '\n';
            sum += sqrt((v[i].first - v[i + 1].first) * (v[i].first - v[i + 1].first) + (v[i].second - v[i + 1].second) * (v[i].second - v[i + 1].second));
        }
        //cnt++;
    } while(next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(12) << sum/fact(n) << '\n';
    //cout << cnt << '\n';
}