#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define endl '\n'
#define N 200005
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int vis[1005][1005];
int n,m;
char a[1005][1005];
void bfs (int x,int y)
{
	vis[x][y] = 1;
	for(int i=0;i<4;i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>=n || tx<0 || ty<0 || ty>=m || vis[tx][ty] || a[tx][ty]=='#')
		continue;
		bfs(tx,ty);
	}
}
int main()
{	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	for(int j = 1;j<=m;j++)
    	cin>>a[i][j];
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(vis[i][j]==0 && a[i][j]=='.'){
    			bfs(i,j);
    			ans++;
    		}
    	}
    }
    cout<<ans<<endl;
}
