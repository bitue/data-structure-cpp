#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin>>n ;
    if(n==1){
        cout<<1 <<endl;
    }
    else if(n==2) cout<<2 <<endl;
    else {
      long long  int m = pow(2, n-2);
     long long   int y = pow(2 , n-1);
     long long int z = m*y ;
        cout<<z<<endl;
    }
    return 0;
}
