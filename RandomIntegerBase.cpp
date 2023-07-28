#include<stdio.h>
#include<stdlib.h>

long long int number;
int max_digit;

int highest_base(long long int);
int max(long long int);

int highest_base(long long int r){
number = r;
max_digit = max(number);
return max_digit+1;
}

int max(long long int num)
{
    int r, large = 0;  // r=remainder
    while (num != 0)
    {
        r = num % 10; // This will divide the num by 10, and then store the remainder, hence will give the last digit in a number
        if (r > large)
        {
            large = r;
        }
        num = num / 10; // this will remove the last digit in the num and afterwards store tha new value
    }
    return large;
}

int main(){
//long long int is taken as we have to input a 10 digit no.(this prevents truncation issues.)
long long int initial_random, random ;
int base;

initial_random =  rand() + 10000000;  //firstly, a 8-digit no is generated 
random = initial_random + 5000000000;  //then, 5000000000 is added to get 1st digit as 5.

base = highest_base(random);

printf("the highest base of the number %lld is %d ",random, base); //lld for long long int
    return 0;
}
