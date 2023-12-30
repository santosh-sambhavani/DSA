//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool compare (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    bool isOverlapped(vector<int> a, vector<int> b) {
        return (b[0] >= a[0] && b[0] <= a[1]) || (b[1] >= a[0] && b[1] <= a[1]);
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), compare);
        
        ans.push_back(intervals[0]);
        for(int ele = 1; ele < intervals.size(); ele++) {
            if (isOverlapped(ans.back(), intervals[ele])) {
                ans.back() = { 
                    min(ans.back()[0], intervals[ele][0]), 
                    max(ans.back()[1], intervals[ele][1])
                };
            } else {
                ans.push_back(intervals[ele]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
}
// } Driver Code Ends

/*
4
1 4 6 8 2 4 9 10
*/
