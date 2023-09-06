/*
Given that there are N books and M students. Also given are the number of pages in each book in ascending order. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, 
with the condition that every student is assigned to read some consecutive books. Print that minimum number of pages.
*/

class Solution 
{
    public:
    bool isPossibleSolution(int arr[], int N, int M, int sol) {
        int sum = 0, students = 1;
        for(int i = 0; i < N; i++) {
            if(arr[i] > sol) return false;
            if(sum + arr[i] <= sol) {
                sum += arr[i];
            } else {
                students++;
                if(students > M) {
                    return false;
                }
                sum = arr[i];
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        if(N < M) return -1;
        int start = INT_MIN, end = 0, ans = 0;
        for(int i = 0; i < N; i++) {
            start = max(start, arr[i]);
            end += arr[i];
        }
        while(start <= end) {
            int mid = (start + end) / 2;
            if(isPossibleSolution(arr, N, M, mid)) {
                // higher values would be definitely possible that's why
                // if the case when lower values would be definitely possible than in nest line we should put start = mid + 1 & vice versa in else 
                end = mid - 1; 
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
