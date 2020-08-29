#include<bits/stdc++.h>
 
using namespace std;
 
int main()
 
{
 
long int i,res,p;
long int n,A[1000];
 
cin >> n;
int arr[n];
for(i=0;i<n;i++)
{
cin >> A[i];
}
 
p = pow(10,9);
res = 1;
 
for(i=0; i<n; i++){
res = (res * A[i])% (p+7);
}
cout << res;
}
