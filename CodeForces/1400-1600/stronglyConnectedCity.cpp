#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
string s, p;

int main() {
    scanf("%lld %lld", &n, &m);
    cin >> s >> p;

    if((p[0] == '^' && s[0] == '>' && p[m - 1] == 'v' && s[n - 1] == '<') || (p[0] == 'v' && s[0] == '<' && p[m - 1] == '^' && s[n - 1] == '>')) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}

