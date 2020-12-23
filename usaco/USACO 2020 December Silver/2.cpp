#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //GOOD LUCK
    int n;
    cin >> n;
    set<set<int> > fdsa;
    pair<int, int> ar[n];
    for (int i = 0; i < n; i ++) {
        cin >> ar[i].first >> ar[i].second;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                for (int l = 0; l < n; l ++) {
                    int maxx = max(ar[i].first, ar[j].first);
                    int minx = min(ar[i].first, ar[j].first);
                    int maxy = max(ar[k].second, ar[l].second);
                    int miny = min(ar[k].second, ar[l].second);
                    set<int> yes;
                    for (int m = 0; m < n; m ++) {
                        if (ar[m].first <= maxx && ar[m].first >= minx && ar[m].second <= maxy && ar[m].second >= miny) {
                            yes.insert(m);
                        }
                    }
                    fdsa.insert(yes);
                }
            }
        }
    }
    cout << fdsa.size() << endl;
}