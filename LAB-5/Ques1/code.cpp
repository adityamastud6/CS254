#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m,vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    void numIslandRec(int i, int j, int n, int m,vector<vector<int>>& grid, int & ans){
          ans++;
          grid[i][j]=0;
          if(isValid(i+1,j,n,m,grid))  numIslandRec(i+1,j,n,m,grid, ans);
          
          if(isValid(i-1,j,n,m,grid))  numIslandRec(i-1,j,n,m,grid, ans);
          
          if(isValid(i,j+1,n,m,grid)) numIslandRec(i,j+1,n,m,grid, ans);
        
          if(isValid(i,j-1,n,m,grid)) numIslandRec(i,j-1,n,m,grid, ans);
         
          if(isValid(i-1,j-1,n,m,grid)) numIslandRec(i-1,j-1,n,m,grid, ans);
          
          if(isValid(i+1,j-1,n,m,grid)) numIslandRec(i+1,j-1,n,m,grid, ans);
          
          if(isValid(i-1,j+1,n,m,grid)) numIslandRec(i-1,j+1,n,m,grid, ans);
          
          if(isValid(i+1,j+1,n,m,grid)) numIslandRec(i+1,j+1,n,m,grid, ans);
          
    }
    
int main(){
     int n,m ; cin>>n>>m; 
     vector<vector<int>>grid(n, vector<int>(m));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
     }
     int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                int maxi=0;
                numIslandRec(i,j,n,m,grid,maxi);
                ans=max(maxi,ans);
            }
        }
    }
     cout<<ans<<endl;
    return 0;
}