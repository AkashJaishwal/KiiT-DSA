#include<iostream>
using namespace std;
int fun (int x, int y)
{
return x + y;
}
double fun(int x, int y)
{
return x*y;
}
int main()
{
    cout<<fun(5, 10.2);
    return 0;
}