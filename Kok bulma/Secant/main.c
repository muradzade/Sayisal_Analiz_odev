#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x);
double f_drv(double *arr,int equ_pow,double X,double X0);
double secant(double *katsayilar,int derece,double a,double b,double E);
int main(int argc, char *argv[]) {
	
	double *katsayilar;
	int derece , i ;
	double E , X0 ,X1;
	
	printf("Polinomun derecesini giriniz : ");
	scanf("%d",&derece);
	katsayilar=(double *) calloc(derece+1 ,sizeof(double));
	
	for(i=0;i<=derece;i++)
	{
		printf("derecesi %d olan elemanin katsayisi? : ",derece-i);
		scanf("%lf",&katsayilar[i]);	
	}
	
	printf("epislon degerini giriniz : "); scanf("%lf",&E);
	
	printf("X0 degerini giriniz : "); scanf("%lf",&X0);
	printf("X1 degerini giriniz : "); scanf("%lf",&X1);
	secant(katsayilar,derece,X0,X1,E);
	
	free(katsayilar);
	
	getch();
	return 0;
}

double f(double *arr,int equ_pow,double x)
{
	int i;
	double sonuc=0;
	for(i=equ_pow;i>=0;i--)
	{
		sonuc += arr[equ_pow-i] * pow(x,i);
	}	

	return sonuc;
}

double f_drv(double *arr,int equ_pow,double X,double X0)
{
	return (f(arr,equ_pow,X0)-f(arr,equ_pow,X))/(X0-X);
}


double secant(double *katsayilar,int derece,double a,double b,double E)
{
	double c=0, c_eski = 0;
	
	if(f(katsayilar,derece,a) * f(katsayilar,derece,b) > 0)
	{	
		printf("Verdiginiz aralikta kok yoktur\n");
		return;
	}
	else if(f(katsayilar,derece,a) * f(katsayilar,derece,b) == 0)
	{
		if( !f(katsayilar,derece,a))
		{
			printf("x = %ld ",a);
			return;
		}
		printf("x = %ld",b);
		return;
	}
	
	do
	{
		c_eski=c;
		c=a - (( b - a) / ( f(katsayilar,derece,b) - f(katsayilar,derece,a)))*f(katsayilar,derece,a);
		
		if(f(katsayilar,derece,a)*f(katsayilar,derece,c) <= 0)
		{
			if(f(katsayilar,derece,a) == 0)
			{
				printf("x = %ld",a);
				return;
			}
			
			else if(f(katsayilar,derece,c) == 0)
			{
				printf("x = %ld",c);
				return;
			}
			
			b = c;
		}
		
		else if(f(katsayilar,derece,b)*f(katsayilar,derece,c) <= 0)
		{
			if(f(katsayilar,derece,b) == 0)
			{
				printf("x = %ld",b);
				return;
			}
			
			else if(f(katsayilar,derece,c) == 0)
			{
				printf("x = %ld",c);
				return;
			}

			a = c;
		}
	}while(fabs(c - c_eski) > E);
	printf(" x = %lf",c);
	return c;
}



