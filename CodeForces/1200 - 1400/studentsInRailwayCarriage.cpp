#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
string s;

int main() {
    scanf("%lld %lld %lld", &n, &a, &b);
    cin >> s;

    char prev = '0';
    ll count = 0;

    for(ll i = 0; i < s.size(); ++i) {
        if(s[i] == '*') prev = '0';
        else if(prev == '0' && s[i] == '.') {
            if(a >= b && a) {
                a--;
                count++;
                prev = 'a';
            } else if(b > a && b) {
                b--;
                count++;
                prev = 'b';
            }
        } else {
            if(prev == 'a' && b) {
                b--;
                count++;
                prev = 'b';
            } else if(prev == 'b' && a) {
                a--;
                count++;
                prev = 'a';
            } else prev = '0';
        }
    }

    printf("%lld\n", count);

    return 0;
}