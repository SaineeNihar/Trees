#include<bits/stdc++.h>
using namespace std;
long int countTrees(int n)
{
    if(n<=1)
        return 1;
    else
    {
        long int sum=0,left,right;
        for(int i=1;i<=n;i++)
        {
            left=countTrees(i-1);
            right=countTrees(n-i);
            sum+=left*right;
        }
    return sum;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"Total number of trees possible with "<<n<<" numbers are: "<<countTrees(n);
    return 0;
}