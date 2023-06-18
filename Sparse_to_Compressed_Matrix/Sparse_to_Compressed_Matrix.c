#include <stdio.h>
#define R 10
#define C 10

int main()
{
	int mat[R][C], i, j, k, mat2[R][C], mat3[R][C], islem;
	int m, n, s_sutun;
	
	for(;;)
	{
		printf("Menu: \n");
		printf("(1) Sparse to compressed matrix\n");
		printf("(2) Compressed to sparse matrix\n");
		printf("(3) Exit\n");
		printf("*********************************************\n");
	
		do{
			printf("Choose Action\n");
			scanf(" %d", &islem);
		}while(islem > 3);
		
		if(islem == 3)
			break;
			
		do{
			printf("Enter the number of rows\n");
			scanf(" %d", &m);
			printf("Enter the number of columns\n");
			scanf(" %d", &n);
		}while(m > R || n > C);
	
		printf("Enter the elements\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf(" Enter the %d. row and %d. column\n", i+1, j+1);
				scanf(" %d", &mat[i][j]);
			}
		}
	
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf(" %d", mat[i][j]);
			printf("\n");	
		}
		printf("\n");
		
		mat2[0][0] = m;
		mat2[0][1] = n;
		k = 1;
		
		//Sparse to compressed matrix -> The first row of the compressed matrix is the number of rows and columns of the matrix that we entered
		if(islem == 1)
		{
			printf("Enter the sparse matrix\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(mat[i][j] != 0)
					{
						mat2[k][0] = i;
                		mat2[k][1] = j;
                		mat2[k][2] = mat[i][j];
                		k++;
					}
				}
				mat2[0][2] = k - 1;
			}
			
			s_sutun = mat2[0][2];
			printf("Compressed Matrix\n");
			
			for (i = 0; i <= s_sutun; i++)
    		{
        		printf("%d\t%d\t%d\n", mat2[i][0], mat2[i][1], mat2[i][2]);
    		}
		}
		//*****************************************************************
		//sýkýþtýrýlmýþtan seyreðe
		if(islem == 2)
		{
			printf("Enter the Compressed Matrix\n");
			
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					mat3[i][j] = 0;
				}
			}
			
			for(i=0;i<m;i++)
			{
				for(j=0;j<3;j++)
				{
					mat3[mat[i][0]][mat[i][1]]= mat[i][2];	
				}		
			}
			printf("Sparse Matrix\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					printf(" %d", mat3[i][j]);
				}
				printf("\n");
			}			
		}
		
			
	}
	
	return 0;
}