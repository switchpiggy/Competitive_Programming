#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    freopen("input.txt", "r", stdin);
    freopen("cloud.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++) {
        cout << "Case #" << i << ": ";
    
    int N, P;
    cin >> N >> P;
    int start = 0, end = 0;
    int cp[N];
    int pre[N];
    for (int i = 0; i < N; i ++) {
        cin >> cp[i];
    }
    int cur_sum = cp[0];
    int min = 1000000000;
    int min_diff = 1000000000;
    int anss = 0;
    int anse = 0;
    while (start != N && end != N) {

        if (start > end) {
            end = start;
            cur_sum += cp[end];
        }
        while (cur_sum < P && end != N-1) {
            end ++;
            cur_sum += cp[end];
        }
        //cout << start << " " << end << " " << cur_sum << endl;
        if (cur_sum >= P && cur_sum-P <= min_diff) {
            if (cur_sum-P < min_diff) {
                min_diff = cur_sum - P;
                anss = start;
                anse = end;
            }
            else {
                if (start < anss) {
                    anss = start;
                    anse = end;
                }
                if (start == anss) {
                    if (end < anse) {
                        anss = start;
                        anse = end;
                    }
                }
            }
        }
        cur_sum -= cp[start];
        start ++;
    }
    cout << anss << " " << anse << endl;
    }

    return 0;
}