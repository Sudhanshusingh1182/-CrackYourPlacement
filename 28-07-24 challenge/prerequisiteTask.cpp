class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    //detect whether a cycle is present , if so , return false
	    
	    vector<int>adj[V];
	    
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    int indegree[V]={0};
	    queue<int> q;
	    vector<int> ans;
	    
	    //updating the indegree of all the elements
	    
	    for(int i=0;i<V;i++){
	        
	        for(auto nbr : adj[i]){
	            
	            indegree[nbr]++;
	        }
	    }
	    
	    //push all the elements with indegree 0 into the queue
	    
	    for(int i=0;i<V;i++){
	        
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty()){
	        
	        int front = q.front();
	        q.pop();
	        
	        ans.push_back(front);
	        
	        for(auto nbr : adj[front]){
	            indegree[nbr]--;
	            
	            if(indegree[nbr]==0)
	            q.push(nbr);
	        }
	    }
	    
	    return (ans.size()==V);
	    
	}
};