#include <bits/stdc++.h>

//First, we make an array denoting the number of moves needed for each monster. We know that the in the last move, the monster will have h%(a + b) health left. Then, if h%(a + b) == 0,
//we roll the game back one move by adding a + b to the health, and then use our secret move. The number of times would be the minimum number of extra attacks needed to kill the monster, aka
// ceil(h/a) - 1. Lastly, we sort the array by the least to most needed moves, and iterate until k is less than the amount of moves needed.
using namespace std;

int n, a, b, k, ar[200005];

int main() {

    scanf("%d %d %d %d", &n, &a, &b, &k);

    int c = 0;

    for(int i = 0; i < n; ++i) {

        scanf("%d", &ar[i]);

        ar[i] %= a + b;

        if(ar[i] == 0) ar[i] += a + b;

        ar[i] = (ar[i] + a - 1)/a - 1;

    }

    sort(ar, ar + n);

    for(int i = 0; i < n; ++i) {

        if(k - ar[i] < 0) break;

        k -= ar[i];

        c++;

    }

    printf("%d", c);
}