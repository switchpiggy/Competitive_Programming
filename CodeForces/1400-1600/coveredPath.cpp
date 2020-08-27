#include <bits/stdc++.h>

using namespace std;

int main() {

    int vi, vf, t, d;

    scanf("%d %d %d %d", &vi, &vf, &t, &d);

    int total = 0;

    for(int i = 0; i <= t - 1; ++i) {

        total += min(vi + d * i, vf + d * (t - 1 - i));

    }

    printf("%d", total);

}