#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
map<char, ll> occ;
ll d = 0;

int main() {
    cin >> s;
    for(ll i = 0; i < s.length(); ++i) {
        occ[s[i]]++;
        if(occ[s[i]] == 1) d++;
    }

    if(d%2 == 1) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
} 