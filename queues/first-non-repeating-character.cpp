//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    queue<char> q;
		    string ans = str;
		    vector<int> mapper(26, 0);
		    
		    q.push(str[0]);
		    mapper[str[0] - 'a'] = 1;
		    for(int i = 1; i < str.size(); i++) {
                char ch = str[i];
                mapper[ch-'a']++;
                q.push(ch);
                
                while(!q.empty()) {
                    if (mapper[q.front()-'a'] > 1) {
                        q.pop();
                    } else {
                        ans[i] = q.front();
                        break;
                    }
                }
                
                if(q.empty()) ans[i] = '#';
		    }
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	return 0;
}
// } Driver Code Ends

//   tcpmxaixsswjelbswxytyhbwjinuhxhvpwaybmdhndafszoghpyzdahiqsgluufqcekjk
//  aabcbca
