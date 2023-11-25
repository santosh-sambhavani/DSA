//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> st;
    
    // push string in to stack
    for(int i = 0; i < len; i++) {
        st.push(S[i]);
    }
    
    // pop to get reversed string
    char* str = new char[len + 1];
    int index = 0;
    while(!st.empty()) {
        char ch = st.top();
        st.pop();
        str[index++] = ch;
    }
    
    str[index] = '\0';
    return str;
}
