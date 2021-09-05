# include<bits/stdc++.h>
 using namespace std;
 # include<vector>
 #define vi vector<int>
 const int N=1e5+2;
 vi adjl[N];
 int main()
 {
     int n,m;
     cin>>n>>m;
     int indeg[n];
     for(int i=1;i<n+1;i++)
     {
        indeg[i]=0;
     }
     for(int i=0;i<m;i++)
     {
         int x,y;
         cin>>x>>y;
         adjl[x].push_back(y);
         indeg[y]++;
     }
     cout<<"The Indegree Array"<<endl;
     for(int i=1;i<n+1;i++)
     {
         cout<<indeg[i]<<" ";
     }
     queue<int> q;
     for(int i=1;i<n+1;i++)
     {
        if(indeg[i]==0)
        {
            q.push(i);
        }
     }
     cout<<endl<<endl;
     cout<<"Topological Sort "<<endl;
     while(!q.empty())
     {
         int node = q.front();
         q.pop();
         cout<<node<<" ";
         vector <int> ::iterator it;
         for(it=adjl[node].begin();it!=adjl[node].end();it++)
         {
             indeg[*it]--;
             if(indeg[*it]==0)
             {
                 q.push(*it);
             }
         }
     }

 }

