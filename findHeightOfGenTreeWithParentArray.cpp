#include<bits/stdc++.h>
using namespace std;
void findheight(int p[],int n)
{
    int maxh=-1,currh,j;
    for(int i=0;i<n;i++)
    {
        currh=0;j=i;            
        while(p[j]!=-1)
        {
            currh++;
            j=p[j];
        }
        if(currh > maxh)
            maxh=currh;
    }
    cout<<maxh<<endl;
}
int main()
{
    int p[]={-1,0,1,6,6,0,0,2,7};
    findheight(p,sizeof(p)/sizeof(p[0]));
    return 0;
}