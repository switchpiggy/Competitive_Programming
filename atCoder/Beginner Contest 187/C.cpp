#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<string, bool> occ;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        occ[s] = 1;
        if(s[0] != '!') v.push_back(s);
    }

    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(occ["!" + v[i]]) {
            cout << v[i] << '\n';
            return 0;
        }
    }   

    cout << "satisfiable\n";
    return 0; 
}