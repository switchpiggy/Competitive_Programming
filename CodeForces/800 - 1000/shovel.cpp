#include <bits/stdc++.h>

using namespace std;

int main() {

    int price, coin;

    scanf("%d %d", &price, &coin);

    for(int i = 1; i < INT_MAX; ++i) {

        if(price * i % 10 == 0 || price * i % 10 == coin) {

            printf("%d\n", i);

            break;

        }

    }

    return 0;

}