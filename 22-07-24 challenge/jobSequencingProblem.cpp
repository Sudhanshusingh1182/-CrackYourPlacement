class Solution 
{   
    private:
    static bool comp(Job a , Job b){
        return a.profit > b.profit;
    } 
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr,arr+n, comp);
        //sorted according to profit
        
        vector<bool>vis(n,0);
        
        int jobcnt=0,maxprofit=0;
       for (int i=0; i< n; i++){
       for (int j=arr[i].dead-1; j>= 0; j--){
         if (vis[j]) continue;
         else{
         vis[j]= true;
         maxprofit+= arr[i].profit;
         jobcnt++;
         break;
        
          }        
         }
       } 
       
       return {jobcnt,maxprofit};
        
        
    } 
};