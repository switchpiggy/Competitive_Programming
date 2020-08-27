#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    ll fst = 0, lst = n - 1;

    while(s[lst] == '.') lst--;
    while(s[fst] == '.') fst++;

    if(s[lst] == 'R') lst++;
    else {
        while(s[lst] == 'L') lst--;
    }

    printf("%lld %lld\n", fst + 1, lst + 1);

    return 0;
}