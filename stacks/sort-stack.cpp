//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void sortedInsert(stack<int>& s, int x) {
    if(s.empty() || s.top() <= x) {
        s.push(x);
        return ;
    }
    
    int tmp = s.top();
    s.pop();
    
    sortedInsert(s, x);
    
    s.push(tmp);
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    if(this->s.empty()) {
        return;
    }
    
    int tmp = this->s.top();
    this->s.pop();
     
    this->sort();
    
    sortedInsert(this->s, tmp);
}

/*
3
3 2 1
*/
