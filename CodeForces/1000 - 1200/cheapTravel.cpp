#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, a, b;

    scanf("%d %d %d %d", &n, &m, &a, &b);

    if(m * a <= b) printf("%d\n", n * a);

    else printf("%d\n", min((n%m) * a, b) + (n - n%m)/m * b);

    return 0;

}