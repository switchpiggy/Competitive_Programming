#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    scanf("%lld", &n);
    printf("%lld\n", 1000 - (n%1000));
}