#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &ranks, int k, int sol) {
    int dishes = 0;
    for(int i = 0; i < ranks.size(); i++) {
        int N = 1, R = ranks[i], minsTaken = 0;
        while(minsTaken + (N * R) <= sol) {
            minsTaken += (N * R);
            dishes++;
            if(dishes == k) {
                return true;
            }
            N++;
        }
    }
    return false;
}


int findMinTime(vector<int> &cooks, int m, int start, int end, int ans) {
    // cout << "\n s: " << start << " e: " << end << " ans: " << ans;
    if (start > end) return ans;
    
    int mid = start + (end - start) / 2;
    // cout << "\n mid: " << mid;
    if(isPossible(cooks, m, mid)) {
        return findMinTime(cooks, m, start, mid - 1, mid);
    } else {
        return findMinTime(cooks, m, mid + 1, end, ans);
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> cooks(n);
    for(int i = 0; i < n; i++) {
        cin>>cooks[i];
    }
    int start = *min_element(cooks.begin(), cooks.end());
    int end = start * ((m * (m + 1)) / 2);
    int ans = findMinTime(cooks, m, start, end, -1);
    cout << "\nMin Time is: " << ans;
}

/*
4 11
1 2 3 4

8 8
1 1 1 1 1 1 1 1 
*/
