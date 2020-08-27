#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int numCoins, coins[105], sum = 0, total = 0, count = 0;
 
    scanf("%d", &numCoins);
 
    for(int i = 0; i < numCoins; ++i) {
 
        scanf("%d", &coins[i]);
 
        sum += coins[i];
 
    }
 
    sort(coins, coins + numCoins);
 
    for(int i = numCoins - 1; i >= 0; --i) {
 
        total += coins[i];
 
        sum -= coins[i];
 
        count++;
 
        if(total > sum) break;
 
    }
 
    printf("%d\n", count);
 
 
 
}