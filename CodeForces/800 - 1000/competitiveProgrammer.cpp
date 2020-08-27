#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    string s;
    scanf("%lld", &t);

    while(t--) {
        ll z = 0;
        ll sum = 0;
        bool even = 0, zero = 0;
        cin >> s;
        for(auto i : s) {
            if(((i - '0')%2 == 0 && (i - '0') != 0) || z >= 1 && (i - '0')%2 == 0) {
                even = 1;
            }
            if((i - '0') == 0 && z == 0) {
                zero = 1;
                z++;
            }
            sum += i - '0';
        }
        if(sum%3 == 0 && even && zero) printf("red\n");
        else printf("cyan\n");
    }
}