#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 1; j < n; ++j) {
            if(s[i] == '*' && s[i + j] == '*' && s[i + 2*j] == '*' && s[i + 3*j] == '*' && s[i + 4*j] == '*') {
                printf("yes\n");
                return 0;
            }
        }
    }

    printf("no\n");

    return 0;
}