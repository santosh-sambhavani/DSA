#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int totalCows, int mid) {
    int lastPosition = stalls[0], allotedCows = 1;
    for (int i = 0; i < stalls.size(); i++) {
        // cout << "\n lastPos: " << lastPosition << " || "<< stalls[i] << " || " <<  mid;
        if(stalls[i] - lastPosition >= mid) {
            allotedCows++;
            if(allotedCows == totalCows) 
                return true;
            lastPosition = stalls[i];
        }
    }
    return false;
}


int findLargestMinDistance(vector<int> &stalls, int totalCows, int start, int end, int ans) {
    // cout << "\n s: " << start << " e: " << end << " ans: " << ans;
    if (start > end) return ans;
    
    int mid = start + (end - start) / 2;
    // cout << "\n mid: " << mid;
    if(isPossible(stalls, totalCows, mid)) {
        return findLargestMinDistance(stalls, totalCows, mid + 1, end, mid);
    } else {
        return findLargestMinDistance(stalls, totalCows, start, mid - 1, ans);
    }
}

int main() {
    int totalStalls, totalCows;
    cin >> totalStalls >> totalCows;
    vector<int> stalls(totalStalls);
    for(int i = 0; i < totalStalls; i++) {
        cin>>stalls[i];
    }
    int end = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end());
    int ans = findLargestMinDistance(stalls, totalCows, 0, end, -1);
    cout << "\nLargest Min distance is: " << ans;
}

/*
5 3
10 1 2 7 5


*/
