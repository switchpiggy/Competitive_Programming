#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<string, int> &x, const pair<string, int> &y) {

    return x.second > y.second;

}

int main() {

    int n, m, price[105];

    map<string, int> fruits;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i) scanf("%d", &price[i]);

    for(int i = 0; i < m; ++i) {

        string s;

        cin >> s;

        fruits[s]++;

    }

    sort(price, price + n);

    vector<pair<string, int>> v(fruits.begin(), fruits.end());
    
    sort(v.begin(), v.end(), comp);

    int ans = 0, max = 0;
    
    int i = 0;

    for(auto itr = v.begin(); itr != v.end(); ++itr) {
    	
    	int cur = i;

        ans += itr->second * price[cur];

        ++i;

    }
    
    int j = n - 1;
    
    for(auto itr = v.begin(); itr != v.end(); ++itr) {
    	
    	max += itr->second * price[j];
    	
    	--j;
    	
    }

    printf("%d %d", ans, max);


}