#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    scanf("%lld" ,&t);
    
    while(t--) {
        scanf("%lld", &n);
        if(n <= 30) printf("NO\n");
        else if(n == 36 || n == 40 || n == 44) printf("YES\n6 10 15 %lld\n", n - 31);
        else printf("YES\n6 10 14 %lld\n", n - 30);
    }

    return 0;
}