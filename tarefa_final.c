#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define N 200 

void imprime(double M[N][N])
{  int i, j;

   for(i=0;i<N;i++)
   {   for(j=0;j<N;j++)
       {    printf("%.3lf\t" , M[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}

double potencial(double M[N][N], double Maux[N][N])
{	int i, j;
	
	for(i=0; i<N; i++)
	{	for(j=0; j<N; j++)
		{
			if(Maux[i][j]==0)
			{	M[i][j] = (M[i-1][j] + M[i+1][j] + M[i][j+1] + M[i][j-1])/4. ;		}	
		}
	}
}

void main()
{	double M[N][N], Maux[N][N]={0};
	int i, j;	
	//FILE *entrada;
	//entrada =  fopen("nome_arquivo_entrada.dat", "r");
	
	//condições de contorno
	for(j=0; j<N;j++)
	{	
		M[N-1][j]=100.;
		M[0][j]=0.;

		Maux[N-1][j]=1;
		Maux[0][j]=1;
	
	}
	
	for(j=39; j<N-39; j++)
	{	
		M[N-39][j]=100.; 
		M[j][99]=100.;	

		Maux[N-39][j]=1;
		Maux[j][99]=1;
	}
		
	for(i=0; i<20000; i++)
	{		potencial(M, Maux);	}
	imprime(M);
	//fclose(entrada);
}
