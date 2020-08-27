#include <bits/stdc++.h>

using namespace std;

int main() {
	
	const int max = 1e6;

    int n;

    cin >> n;

    vector<int> a(n);
    
    vector<int> cunt(max + 1);

    for(int i = 0; i < n; ++i) {

        scanf("%d", &a[i]);

        cunt[a[i]]++;

    }

    long long int sum = accumulate(a.begin(), a.end(), 0ll);

    vector<int> ans;

    int count = 0;

    for(int i = 0; i < n; ++i) {

        sum -= a[i];

        cunt[a[i]]--;

        if(sum % 2 == 0 && sum / 2 <= max && cunt[sum/2] > 0) {

            ans.push_back(i + 1);

            count++;

        }
        
        sum += a[i];
        
        cunt[a[i]]++;

    }

    printf("%d\n", count);

    for(int i = 0; i < count; ++i) printf("%d ", ans[i]);


}