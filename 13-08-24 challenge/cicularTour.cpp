/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int diff =0;
        int s=0;
        int balance =0;
        
        for(int i=0;i<n;i++){
            balance += p[i].petrol- p[i].distance;
            if(balance<0){
                s=i+1;
                diff+=balance;
                balance=0;
            }
        }
        
        if(balance+ diff >=0) return s;
        
        return -1;
    }
};