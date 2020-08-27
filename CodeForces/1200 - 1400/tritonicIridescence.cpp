#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;   
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    for(ll i = 0; i < n - 1; ++i) {
        if(s[i] != '?' && s[i] == s[i + 1]) {
            printf("NO\n");
            return 0;
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(s[i] == '?') {
            if(i == 0 || i == n - 1) {
                printf("YES\n");
                return 0;
            } 
            if(s[i] == s[i + 1]) {
                printf("YES\n");
                return 0;
            }
            if(s[i - 1] == s[i + 1]) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}