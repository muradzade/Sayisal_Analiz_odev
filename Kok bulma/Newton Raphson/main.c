#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double f(double *arr,int equ_pow,double x);
double f_drv(double *arr,int equ_pow,double X,double X0);
double newton_raphson(double *katsayilar,int derece,double X0,double E);

int main(int argc, char *argv[]) {
		
	double *katsayilar;
	int derece , i ;
	double E , X0 ;
	
	printf("Polinomun derecesini giriniz : ");
	scanf("%d",&derece);
	katsayilar=(double *) calloc(derece+1 ,sizeof(double));
	
	for(i=0;i<=derece;i++)
	{
		printf("derecesi %d olan elemanin katsayisi? : ",derece-i);
		scanf("%lf",&katsayilar[i]);	
	}
	
	printf("epislon degerini giriniz : "); scanf("%lf",&E);
	
	printf("X0 baslangic degerini giriniz : "); scanf("%lf",&X0);
	newton_raphson(katsayilar,derece,X0,E);

	
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

double newton_raphson(double *katsayilar,int derece,double X0,double E)
{
	double X=0,X0_oncesi=0; // X0_oncesi geri farkla turev almak icin lazim.kullanicidan almadigim icin 0'la baslattim
	
	X=X0 - f(katsayilar,derece,X0)/f_drv(katsayilar,derece,X0,X0_oncesi);
	
	while(fabs(X-X0)>E)
	{
		X0_oncesi=X0;
		X0=X;
		X=X0 - f(katsayilar,derece,X0)/f_drv(katsayilar,derece,X0,X0_oncesi);
		
	}
		
	printf("%lf\n",X);
	return X;
}
