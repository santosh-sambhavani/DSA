/*
   https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

   Notes: 
   Approach #1: TC = O(N^2)
    - try from every point if possible till end than return perticular point else return -1

    Approach #2: Using two pointer 
      - use read & front and use logic to reduce traversal of unnecessary starts
        int balance = 0, front = 0, rear = 0;
        
        while(front < n) {
            balance += p[rear].petrol - p[rear].distance;
            
            if(balance < 0) {
                front = rear + 1;
                balance = 0;
                rear++;
            } else {
                if (rear == n-1)
                    rear = 0;
                else 
                    rear++;
                if (front == rear) return rear;
            }
        }

    Approach #3: implemented in this file
      - it note down the total deficiancy and test at the end with total distance (distance in positive)
*/

#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
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
  
    int tour(petrolPump p[],int n)
    {
        int balance = 0;
        int deficite = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            balance += (p[i].petrol - p[i].distance);
            if (balance < 0) {
                deficite += balance;
                balance = 0;
                start = i+1;
            }
        }
        
        if(balance + deficite > 0) return start;
        return -1;
    }
};

int main()
{
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].petrol>>p[i].distance;
    Solution obj;
    cout<<obj.tour(p,n)<<endl;
}

/*
4
4 6 6 5 7 3 4 5 
*/
