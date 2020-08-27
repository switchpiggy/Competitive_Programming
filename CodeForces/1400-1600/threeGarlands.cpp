#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a == 1 || b == 1 || c == 1) printf("YES\n");
    else if((a == 2 && b == 2) || (a == 2 && c == 2) || (b == 2 && c == 2)) printf("YES\n");
    else if(a == 3 && b == 3 && c == 3) printf("YES\n");
    else if((a == 2 && b == 4 && c == 4) || (a == 4 && b == 2 && c == 4) || (a == 4 && b == 4 && c == 2)) printf("YES\n");
    else printf("NO\n");

    return 0;
}