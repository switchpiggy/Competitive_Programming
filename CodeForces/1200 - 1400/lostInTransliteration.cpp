#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
set<string> st;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> s;
        for(ll j = 0; j < s.length(); ++j) {
            if(s[j] == 'u') {
                s[j] = 'o';
                s.insert(s.begin() + j, 'o');
            } else if(s[j] == 'k') {
                ll k = j;
                while(k < s.length() && s[k] == 'k') {
                	//cout << k << s[k] << endl;
                	k++;
                }
                if(k < s.length() && s[k] == 'h') s.erase(j, k - j);
            }
        }
        
        //cout << s << endl;
        st.insert(s);
    }
    

    printf("%lld\n", (ll)st.size());

    return 0;
}