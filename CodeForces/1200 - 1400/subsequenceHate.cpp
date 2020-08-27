#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    scanf("%lld", &t);
    
    while(t--) {
        ll zeros = 0, ones = 0, curZ = 0, curOne = 0, res = INT_MAX;
        cin >> s;

        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '1') ones++;
            else zeros++;
        }

        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '0') curZ++;
            else curOne++;

            res = min(res, min(curZ + ones - curOne, curOne + zeros - curZ));
        }

        printf("%lld\n", res);
    }

    return 0;
}