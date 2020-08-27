#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    getline(cin, s);

    for(ll i = 0; i < s.length(); ++i) {
    	if(s[i] == '0') continue;
        if(s[i] == ' ') {
            ll j = i + 1;
            while(j < s.length() && (s[j] == ' ' || s[j] == '0')) {
                s[j] = '0';
                j++;
            }
        } else if(s[i] == '.' || s[i] == ',' || s[i] == '?' || s[i] == '!') {
            ll j = i - 1;
            while(j >= 0 && (s[j] == '0' || s[j] == ' ')) {
                s[j] = '0';
                j--;
            }
            j = i + 1;
            while(j < s.length() && (s[j] == ' ' || s[j] == '0')) {
                s[j] = '0';
                j++;
            }
        }
    }

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] != '0') cout << s[i];
        if((s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') && i != s.length() - 1) cout << ' ';
    }

    return 0;
}