/*
ID: alanxia1
PROG: hamming
LANG: C++
*/



#include <bits/stdc++.h>
#define MAX (1 << 8 + 1)
#define NMAX 65
#define BMAX 10
#define DMAX 10

int nums[NMAX], dist[MAX][MAX];
int N, B, D, maxval;

void findgroups(int cur, int start) {
    int a, b, canuse;
    char ch;
    if (cur == N) {
        for (a = 0; a < cur; a++) {
            if (a % 10)
                printf(" ");
            printf("%d", nums[a]);
            if (a % 10 == 9 || a == cur-1)
                printf("\n");
        }
        exit(0);
    }
    for (a = start; a < maxval; a++) {
        canuse = 1;
        for (b = 0; b < cur; b++)
            if (dist[nums[b]][a] < D) {
                canuse = 0;
                break;
            }
        if (canuse) {
            nums[cur] = a;
            findgroups(cur+1, a+1);
        }
    }
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    int a, b, c;
    scanf("%d%d%d", &N, &B, &D);
    maxval = (1 << B);
    for (a = 0; a < maxval; a++)
        for (b = 0; b < maxval; b++) {
            dist[a][b] = 0;
            for (c = 0; c < B; c++) 
                if (((1 << c) & a) != ((1 << c) & b))
                    dist[a][b]++;
        }
    nums[0] = 0;
    findgroups(1, 1);
    return 0;
}