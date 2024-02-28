#include <stdio.h>

void MultMat(int *mat1, int *mat2, int *result, int n);
void DispMat(int *mat, int n);  

int main() 
{
    int n;

    
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    int mat1[n][n], mat2[n][n], result[n][n];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    MultMat(&mat1[0][0], &mat2[0][0], &result[0][0], n);

    printf("\nMatrix 1:\n");
    DispMat(&mat1[0][0], n);

    printf("\nMatrix 2:\n");
    DispMat(&mat2[0][0], n);

    printf("\nResultant Matrix:\n");
    DispMat(&result[0][0], n);

    return 0;
}

void MultMat(int *mat1, int *mat2, int *result, int n) 
{
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            *(result + i * n + j) = 0;  
            for (int k = 0; k < n; ++k) 
			{
                *(result + i * n + j) += (*(mat1 + i * n + k)) * (*(mat2 + k * n + j));
            }
        }
    }
}


void DispMat(int *mat, int n) 
{
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            printf("%d\t", *(mat + i * n + j));
        }
        printf("\n");
    }
}
