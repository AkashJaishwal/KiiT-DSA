//WAP to find the first digit of a number using function. 
// Example : if the number is 1234. output is 1.
#include <stdio.h>
int main(){
    system("cls");
    int num, firstDigit;
    
    // User Input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    
    // Finding first digit of a number
    firstDigit = num;
    while (firstDigit >= 10){
        firstDigit = firstDigit / 10;
    }
    
    // Displaying output
    printf("First digit of %d is : %d \n",num, firstDigit);
    
    return 0;
}