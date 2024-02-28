#include <stdio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int n1, n2;

    printf("Enter the numbers to be swapped: \n");

    scanf("%d %d",&n1,&n2);

    void (*swapPtr)(int *, int *) = swap;
    swapPtr(&n1, &n2);
    
    printf("%d %d\n", n1, n2);

    return 0;
}
