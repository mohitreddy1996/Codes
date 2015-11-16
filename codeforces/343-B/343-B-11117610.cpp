#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
     char ch[100003];
     scanf("%s",ch);
     stack<char> s;
     for(int i=0;ch[i]!='\0';i++)
     {
         if(s.empty())
          s.push(ch[i]);
         else
          {
              if(s.top()==ch[i])
              {
                  s.pop();
              }
              else
              {
                  s.push(ch[i]);
              }
          }
     }
     if(s.empty())
      printf("Yes\n");
     else
      printf("No\n");
    return 0;
}