class Solution {
  public:
	void shortest_distance(vector<vector<int>>&grid){
	     
	     int n= grid.size();
	     
	     //convert -1 wale edges to 10000
	     for(int i=0;i<n;i++){
	         for(int j=0;j<n;j++){
	             if(grid[i][j]==-1) grid[i][j]=10000;
	         }
	     }
	     
	     //apply the algo
	     for(int via=0;via<n; via++){
	         for(int i=0;i<n;i++){
	             for(int j=0;j<n;j++){
	                 grid[i][j]= min(grid[i][j], grid[i][via]+grid[via][j]);
	             }
	         }
	     }
	     
	     //convert 10000 wale edges to -1
	     for(int i=0;i<n;i++){
	         for(int j=0;j<n;j++){
	             if(grid[i][j]==10000) grid[i][j]=-1;
	         }
	     }
	}
};