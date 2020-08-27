#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int s;

    scanf("%lld", &s);

    if(s%2 == 0) printf("%lld", s/2);

    else printf("%lld", s/2 - s);

}