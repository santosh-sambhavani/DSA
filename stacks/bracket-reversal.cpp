#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
  stack<char> s;

  for(int i = 0; i < str.size(); i++) {
    char ch = str[i];

    if (ch == '{') {
      s.push(ch);
    }

    if (ch == '}') {
      if(!s.empty() && s.top() == '{') {
        s.pop();
      } else {
        s.push(ch);
      }
    }
  }

  if(s.size() == 1) return -1;

  int a = 0, b = 0;
  while(!s.empty()) {
    if (s.top() == '{') {
      a++;
    } else {
      b++;
    }
    s.pop();
  }

  return ((a+1) / 2) + ((b+1) / 2);
}
