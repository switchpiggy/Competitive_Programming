#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    while(n--) {

        int str, inte, exp;

        scanf("%d %d %d", &str, &inte, &exp);

        int minAdd = max(0, (inte + exp - str + 2)/2);

        printf("%d\n", max(0, exp - minAdd + 1));

    }

}