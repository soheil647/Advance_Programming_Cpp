#include<iostream>
#include<vector>
using namespace std;
int func(vector<vector<int>>a,int p,int q,int n,int m,int ans)
{
    if(q==m-1)
    {
        return ans;
    }
    if(p==0)
    {
        return max(func(a,p,q+1,n,m,ans+a[p][q+1]),func(a,p+1,q+1,n,m,ans+a[p+1][q+1]));
    }
    else if(p==n-1)
    {
        return max(func(a,p,q+1,n,m,ans+a[p][q+1]),func(a,p-1,q+1,n,m,ans+a[p-1][q+1]));
    }
    else
    {
        return max(func(a,p,q+1,n,m,ans+a[p][q+1]),
                   max(func(a,p-1,q+1,n,m,ans+a[p-1][q+1]),func(a,p+1,q+1,n,m,ans+a[p+1][q+1])));
    }
}
int main()
{
    //code
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp;
                cin>>temp;
                a[i].push_back(temp);
            }
        }
        int p=0;
        int q=0;
        int ans=0;
        cout<<func(a,p,q,n,m,ans+a[0][0])<<endl;
    }
    return 0;
}