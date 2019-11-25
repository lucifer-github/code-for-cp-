#include <iostream>

using namespace std;
int64_t power(int64_t a,int64_t n)
{
    if(n==0)
      return 1;

    else if(n==1)
      return a;

    else
    {
        int64_t r=power(a,n/2);
        if(n%2==0)
          return r*r;
        else
          return r*r*a;
    }
}

int main()
{cout<<power(3,11);
   return 0;
}
