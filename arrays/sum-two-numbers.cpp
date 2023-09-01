// Convetional summation of two numbers represented as array

class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int n = a.size(), 
	        m = b.size(), 
	        i = n - 1,
	        j = m - 1,
	        carry = 0;
	   vector<int> ans;
	    while(i >= 0 && j >= 0) {
	        ans.push_back((a[i] + b[j] + carry) % 10);
	        carry = (a[i] + b[j] + carry) / 10;
	        i--; 
	        j--;
	    }
	    while(i >= 0) {
	        ans.push_back((a[i] + carry) % 10);
	        carry = (a[i] + carry) / 10;
	        i--;
	    }
	    while(j >= 0) {
	        ans.push_back((b[j] + carry) % 10);
	        carry = (b[j] + carry) / 10;
	        j--;
	    }
	    if(carry > 0) ans.push_back(carry);
	    reverse(ans.begin(), ans.end());
	    return ans;
	}

};
