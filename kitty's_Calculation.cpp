#include <cmath>
#include <cstdio>
#include<bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int dist(int u,int v,vector<int> adj[],int nodes)
{   
//    cout<<u<<" "<<v<<" "<<endl;
    int distance[nodes];
    queue<int> q;
    vector<bool> visited(nodes,false);
    visited[u]=true;
    distance[u]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();q.pop();
//        cout<<u<<" "<<endl;
//        cout<<"adj[u].size() "<<adj[u].size()<<endl;
        for(int i=0;i<adj[u].size();i++)
        {
//            cout<<adj[u][i]<<endl;
            if(visited[adj[u][i]]==false)
            {
                visited[adj[u][i]]=true;
                distance[adj[u][i]]=distance[u]+1;
                q.push(adj[u][i]);
                if(adj[u][i]==v)
                {
//                    cout<<"distance is "<<distance[v]<<endl;
                    return distance[v];
                }
            }
        }
    }
    return 0;
}

int main() {
    long int calculated=pow(10,9)+7;
    int nodes,qry,a,b;
    cin>>nodes;
    cin>>qry;
    vector<int> adj[nodes+1];
    for(int i=0;i<nodes-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<long int> ans;
    for(int i=0;i<qry;i++)
    {
        int k;
        cin>>k;
        vector<int> v;
        for(int j=0;j<k;j++)
        {
            cin>>a;
            v.push_back(a);
        }
        long int sum=0;
        if(k==1)
            ans.push_back(0);
        else
        {
            for(int j=0;j<k;j++)
                for(int p=j+1;p<k;p++)
                    sum+=v[j]*v[p]*dist(v[j],v[p],adj,nodes);
            ans.push_back(sum % calculated);
        }
    }
    for(auto it=ans.begin();it!=ans.end();it++)
        cout<<*it<<endl;
    return 0;
}
