#include <bits/stdc++.h>

using namespace std;

int main() {

    int gl, gr, br, bl;

    scanf("%d %d %d %d", &gl, &gr, &bl, &br);

    if((gl - br <= 1 && gl * 2 + 2 >= br) || (gr - bl <= 1 && gr * 2 + 2 >= bl)) {

        printf("YES");

        return 0;

    }

    printf("NO");



}