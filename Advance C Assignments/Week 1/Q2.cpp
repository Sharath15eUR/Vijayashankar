#include <stdio.h>

int countSetBits(int n) 
{
    int count = 0;
    while (n) 
	{
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int main() 
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int result = countSetBits(n);
    
    printf("Number of set bits in %d is %d.\n", n, result);
    return 0;
}
