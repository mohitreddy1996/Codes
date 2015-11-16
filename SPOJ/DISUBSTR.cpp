#include <algorithm>
#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define LL long long
#define pi 3.141592653589793238462643383
string s;
int P[16][50001];
struct entry
{
 int i,nr[2];
}L[50001];
bool cmp(entry a,entry b){
 if(a.nr[0]==b.nr[0])
   return a.nr[1] < b.nr[1];
 else
   return a.nr[0] < b.nr[0];
}
int stp = 1;
void compute_suffix_array(){
 int i,l;
 l = s.length();
 for(i=0;i<l;i++)
  P[0][i] = s[i];
 int cnt = 1;
 while(cnt < l){
  for(i=0;i<l;i++){
   L[i].i = i;
   L[i].nr[0] = P[stp-1][i];
   L[i].nr[1] = i + cnt < l ? P[stp - 1][i + cnt] : -1;
  }
  sort(L,L+l,cmp);
  int rank = 0;
  for(i = 0;i < l;i++){
   if(i-1>=0){
    if(L[i].nr[0] != L[i-1].nr[0] || L[i].nr[1] != L[i-1].nr[1])
      rank++;
   }
   P[stp][L[i].i] = rank;
  }
  cnt = cnt<<1;
  stp++;
 }
}
int lcp(int x, int y){
 if(x == y)
  return s.length() - x;
 int ans  = 0;
 int i;
 for(i = stp - 1; i>=0 && x < s.length() && y < s.length();i--){
  if(P[i][x] == P[i][y]){
   ans += 1<<i;
   x += 1<<i;
   y += 1<<i;
  }
 }
 return ans;
 
}
int main()
{
 int t,l,i,j;
 LL temp;
    cin>>t;
 while(t > 0){
  cin>>s;
  stp = 1;
  compute_suffix_array();
  l = s.length();
  temp = 0;
  for(i=0;i<l-1;i++){
   temp = temp + lcp(L[i].i,L[i+1].i); 
  }
  LL l1 = s.length();
  LL ans = (l1 * (l1 + 1)) / 2 - temp;
  cout<<ans<<endl;
  t--;
 }
}
