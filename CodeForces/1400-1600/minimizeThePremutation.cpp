#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1256/B

/* We can take a greedy approach to solving this problem. In every step, we find the minimum element past the leftmost move that we can make, and swap it to the leftmost position possible.
   Then, we update the position of the leftmost element to the current position of the leftmost swap commited.
*/

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int t;

    s(t);

    while(t--) {

        int n;

        s(n);

        vector<int> arr(n);

        for(int i = 0; i < n; ++i) s(arr[i]);

        int pos = 0;

        while(pos < n) {

            int curr = min_element(arr.begin() + pos, arr.end()) - arr.begin();

            int cur = arr[curr];

            arr.erase(arr.begin() + curr);

            arr.insert(arr.begin() + pos, cur);

            if(pos == curr) pos = curr + 1;

            else pos = curr;

        }

        for(int i = 0; i < n; ++i) printf("%d ", arr[i]);
        
        printf("\n");


    }





}