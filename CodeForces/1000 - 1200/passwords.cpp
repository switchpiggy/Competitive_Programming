#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, occ[107];
string p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector<string> v;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        occ[(ll)s.length()]++;
    }
    cin >> p;

    for(ll i = 1; i <= 100; ++i) occ[i] += occ[i - 1];
    cout << (occ[(ll)p.length() - 1] + 1) + (occ[(ll)p.length() - 1])/k * 5 << ' ' << occ[(ll)p.length()] + (occ[(ll)p.length()] - 1)/k * 5 << '\n';
    
    return 0;
}