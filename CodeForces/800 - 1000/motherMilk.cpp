/*
ID: alanxia1
PROG: milk3
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;



typedef struct State State;

struct State {

    int a[3];

};

bool can[25];

bool visited[25][25][25];

int cap[3];

State create(int a, int b, int c) {

    State s;

    s.a[0] = a;

    s.a[1] = b;

    s.a[2] = c;

    return s;

}

State pour(State s, int start, int end) {

    int trans;

    trans = s.a[start];

    if(s.a[end] + trans > cap[end]) trans = cap[end] - s.a[end];

    s.a[start] -= trans;

    s.a[end] += trans;

    return s;

}

void dfs(State s) {

    int i, j;

    if(visited[s.a[0]][s.a[1]][s.a[2]]) return;

    visited[s.a[0]][s.a[1]][s.a[2]] = true;

    if(s.a[0] == 0) can[s.a[2]] = 1;

    for(i = 0; i < 3; ++i) 
        for(j = 0; j < 3; ++j) dfs(pour(s, i, j));

    return;

}

int main() {

    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);

    dfs(create(0, 0, cap[2]));

    for(int i = 0; i <= cap[2]; ++i) {

        if(can[i]) printf("%d", i);

        if(i < cap[2] && can[i]) printf(" ");

    }

    printf("\n");

    return 0;

}