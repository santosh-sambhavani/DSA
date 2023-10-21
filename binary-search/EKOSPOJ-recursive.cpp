#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &trees, int m, int mid) {
    int sum = trees[0] - mid > 0 ? trees[0] - mid : 0;
    for (int i = 1; i < trees.size(); i++) {
        if (trees[i] - mid > 0) {
            if((sum >= m) || (sum + trees[i] - mid >= m)) {
                return true;
            }
            sum += trees[i] - mid;
        }
    }
    return false;
}


int findMinHight(vector<int> &trees, int m, int start, int end, int ans) {
    // cout << "\n s: " << start << " e: " << end << " ans: " << ans;
    if (start > end) return ans;
    
    int mid = start + (end - start) / 2;
    // cout << "\n mid: " << mid;
    if(isPossible(trees, m, mid)) {
        return findMinHight(trees, m, mid + 1, end, mid);
    } else {
        return findMinHight(trees, m, start, mid - 1, ans);
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> trees(n);
    for(int i = 0; i < n; i++) {
        cin>>trees[i];
    }
    int end = *max_element(trees.begin(), trees.end());
    int ans = findMinHight(trees, m, 0, end, -1);
    cout << "\nMin tree hight is: " << ans;
}

/*
4 7 
20 15 10 17

5 20
4 42 40 26 46
*/
