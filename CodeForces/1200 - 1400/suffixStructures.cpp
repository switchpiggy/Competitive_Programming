#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;

    ll j = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == t[j]) j++;
        if(j == t.length()) break;
    }

    if(j == t.length()) {
        printf("automaton\n");
        return 0;
    }

    string ss = s, tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());

    if(ss == tt) {
        printf("array");
        return 0;
    }

    j = 0;
    for(ll i = 0; i < ss.length(); ++i) {
        if(ss[i] == tt[j]) j++;
        if(j == tt.length()) break;
    }

    if(j == tt.length()) {
        printf("both");
        return 0;
    }

    printf("need tree");
    return 0;
}