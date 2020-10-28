#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k;

    ll n = 0, snow = 0, candy = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] != '*' &&  s[i] != '?') n++;
        if(s[i] == '*') snow++;
        if(s[i] == '?') candy++;
    }

    if(n == k) {
        for(ll i = 0; i < (ll)s.length(); ++i) if(s[i] != '*' && s[i] != '?') cout << s[i];
        return 0;
    }

    if((n < k && !snow) || (n > k && n - k > snow + candy)) {
        cout << "Impossible\n";
        return 0;
    }

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '*') {
            if(n < k) {
                n++;
                s.insert(s.begin() + i, s[i]);
            } else if(n > k) {
                n--;
                s[i - 1] = '-';
            }
        }

        if(s[i] == '?') {
            if(n > k) {
                n--;
                s[i - 1] = '-';
            }
        }

        if(n == k) {
            for(ll i = 0; i < (ll)s.length(); ++i) {
                if(s[i] != '*' && s[i] != '?' && s[i] != '-') cout << s[i]; 
            }
            return 0;
        }
    }

    cout << "Impossible\n";
    return 0;
}