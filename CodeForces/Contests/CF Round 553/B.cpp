#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n,i,j,k,t,m;
    scanf("%d%d",&n,&m);
    int nobz[n],nobo[n];
    int a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        nobz[i]=-1;
        nobo[i]=-1;
    }
    int ans=-1;
    vector<int> v;
    for(i=0;i<=10;i++)
    {
        int z=0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                int s=1<<i;
               //  cout<<s<<endl;
                  int l=(a[j][k]&s);
             //     cout<<l<<endl;
                  if(l==0)
                  nobz[j]=k+1;
                  else if(l>0)
                  {
                      nobo[j]=k+1;
                      z=1;
                  }
                  if(nobo[j]!=-1&&nobz[j]!=-1)
                  break;
            }
        }
   //   for(k=0;k<n;k++)
    //    cout<<nobz[k]<<" "<<nobo[k]<<endl;
        if(z==1)
        {
           //cout<<"HELLO"<<endl;
            z=-1;
            int count=0;
            for(k=0;k<n;k++)
            {
                if((nobz[k]!=-1)&&(nobo[k]!=-1))
                z=k;
                if(nobo[k]!=-1)
                count++;
                //nobo[k]=0;
                //nobz[k]=0;
            }
            //cout<<count<<" "<<z<<endl;
            if(count%2)
            {ans=i;
              for(k=0;k<n;k++)
              {
                  if(nobo[k]!=-1)
                  v.push_back(nobo[k]);
                  else
                  v.push_back(nobz[k]);
              }//cout<<ans<<endl;
            }
            else
            {
             if(z!=-1)
             {
                 ans=i;
            //   cout<<z<<endl;
                 for(k=0;k<n;k++)
                 {
                     if(k==z)
                     v.push_back(nobz[k]);
                     else if(nobo[k]!=-1)
                      v.push_back(nobo[k]);
                     else
                     v.push_back(nobz[k]);
                  }
             }
            }
        }
        for(k=0;k<n;k++)
        {
            nobz[k]=-1;
            nobo[k]=-1;
        }
        if(ans!=-1)
        break;
    }
    if(ans==-1)
    cout<<"NIE";
    else
    {
        cout<<"TAK"<<endl;
        for(auto x: v)
        cout<<x<<" ";
    }
    
}