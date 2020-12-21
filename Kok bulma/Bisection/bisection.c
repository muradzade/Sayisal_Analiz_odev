#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x); 
double bisection(double *elemanlar,int size,double a,double b,double E);

int main(int argc, char *argv[]) {
	

	double E , a , b;	
	double *katsayilar;
	int derece , i ;
	
	printf("Polinomun derecesini giriniz : ");
	scanf("%d",&derece);
	katsayilar=(double *) calloc(derece+1 ,sizeof(double));
	
	for(i=0;i<=derece;i++)
	{
		printf("derecesi %d olan elemanin katsayisi? : ",derece-i);
		scanf("%lf",&katsayilar[i]);	
	}
	

	printf("epislon degerini giriniz : "); scanf("%lf",&E);
	
	printf("a degerini giriniz : "); scanf("%lf",&a);
	
	printf("b degerini giriniz : "); scanf("%lf",&b);
	
	bisection(katsayilar,derece,a,b,E);
	
	
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

double bisection(double *elemanlar,int size,double a,double b,double E)
{
	double c=0, c_eski = 0;
	if(f(elemanlar,size,a) * f(elemanlar,size,b) > 0)
	{	
		printf("Verdiginiz aralikta kok yoktur ya da birden fazla kok var\n");
		return;
	}
	else if(f(elemanlar,size,a) * f(elemanlar,size,b) == 0)
	{
		if( !f(elemanlar,size,a))
		{
			printf("x = %lf ",a);
			return;
		}
		printf("x = %lf",b);
		return;
	}
	
	do
	{
		c_eski=c;
		c=(a+b)/2;
		
		if(f(elemanlar,size,a)*f(elemanlar,size,c) <= 0)
		{
			if(f(elemanlar,size,a) == 0)
			{
				printf("x = %lf",a);
				return;
			}
			
			else if(f(elemanlar,size,c) == 0)
			{
				printf("x = %lf",c);
				return;
			}
			
			b = c;
		}
		
		else if(f(elemanlar,size,b)*f(elemanlar,size,c) <= 0)
		{
			if(f(elemanlar,size,b) == 0)
			{
				printf("x = %lf",b);
				return;
			}
			
			else if(f(elemanlar,size,c) == 0)
			{
				printf("x = %lf",c);
				return;
			}

			a = c;
		}
	}while(fabs(c - c_eski) > E);
	printf(" x = %lf",c);
	return c;
}
