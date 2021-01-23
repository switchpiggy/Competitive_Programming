#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll x1, x2, x3, x4, x5, x6, y11, y2, y3, y4, y5, y6;
pair<ll, ll> x[1000007][2];

void no() {
    cout << "YES\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >>x6 >> y6;
    for(ll i = x3; i < x4; ++i) {
        x[i][0].first = y3, x[i][0].second = y4;
    }

    for(ll i = x5; i < x6; ++i) {
        x[i][1].first = y5, x[i][1].second = y6;
    }

    for(ll i = x1; i < x2; ++i) {
        sort(x[i], x[i] + 2);
        if(x[i][0].first <= y11 && x[i][0].second >= y2) continue;
        if(x[i][1].first <= y11 && x[i][1].second >= y2) continue;

        if(x[i][0].second < y11 || x[i][1].first > y2) no();
        if(x[i][0].first > y11 || x[i][1].second < y2) no();
        if(x[i][0].second < x[i][1].first) no();
        //cout << x[i][0].second << ' ' << x[i][1].first << '\n';
    }

    cout << "NO\n";
    return 0;
}