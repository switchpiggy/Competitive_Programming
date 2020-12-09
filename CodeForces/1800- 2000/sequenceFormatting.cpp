#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == ',') {
            if((ll)s.length() == i + 1) cout << ',';
            else cout << ", ";
        } else if(s[i] == '.') {
            ll j = i - 1;
            while(j >= 0 && s[j] == ' ') j--;
            if(i && s[j] != ',') cout << " ...";
            else cout << "...";
            i += 2;
        } else if(s[i] != ' ') {
            ll j = i + 1;
            while(j < (ll)s.length() && s[j] == ' ') j++;
            if(isdigit(s[j]) && j > i + 1) cout << s[i] << ' ', i = j - 1;
            else cout << s[i];
        }
    }

    return 0;
}