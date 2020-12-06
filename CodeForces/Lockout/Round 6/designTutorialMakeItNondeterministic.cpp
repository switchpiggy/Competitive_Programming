#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<pair<string, string>> v;
ll n, a[100007];
string s, t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t;
        v.push_back({s, t});
    }

    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    string prev = min(v[a[0]].first, v[a[0]].second);
    for(ll i = 0; i < n; ++i) {
        if(v[a[i]].first < prev && v[a[i]].second < prev) {
            cout << "NO\n";
            return 0;
        }

        if(v[a[i]].first >= prev && v[a[i]].second >= prev) prev = min(v[a[i]].first, v[a[i]].second);
        else prev = max(v[a[i]].first, v[a[i]].second);
    }

    cout << "YES\n";
    return 0;
}