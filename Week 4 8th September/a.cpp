#include<iostream> 
using namespace std; 
void fun ( int *x, int*y )

{
x = y; *y = 3 ; *x = 4 ;
}

int main()

{

int a = 1 , b = 2; fun(&a, &b); cout<<a+b;

return 0;

}