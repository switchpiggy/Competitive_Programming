#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> result;
    int a,b;
    cin>>a>>b;
    while(b>a)
    {
        result.push_back(b);
        if(b%2==0 and (b/2>=a)) b/=2;
        else
        {
            if(b%10==1 and (b/10)>=a) b/=10;
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    result.push_back(b);
    cout<<"YES"<<endl;
    cout<<result.size()<<endl;
    for(int i=result.size()-1;i>=0;i--) cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}