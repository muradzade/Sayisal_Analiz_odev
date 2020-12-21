#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x);
double turev(double *katsayilar,double derece,int x,double deltaX);

int main(int argc, char *argv[]) {
	
	double E , X ,deltaX;	
	double *katsayilar;
	int derece , mertebe , i ;
	
	printf("Polinomun derecesini giriniz : ");
	scanf("%d",&derece);
	katsayilar=(double *) calloc(derece+1 ,sizeof(double));
	
	for(i=0;i<=derece;i++)
	{
		printf("derecesi %d olan elemanin katsayisi? : ",derece-i);
		scanf("%lf",&katsayilar[i]);	
	}
	
	printf("turev noktasi giriniz : "); scanf("%lf",&X);
	printf("delta X degerini giriniz : "); scanf("%lf",&deltaX);


	printf("fonksiyonun %lf noktasindaki turevi = %lf",X,turev(katsayilar,derece,X,deltaX));
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

double turev(double *katsayilar,double derece,int x,double deltaX)
{
	return ((f(katsayilar,derece,x + deltaX)-f(katsayilar,derece,x))/deltaX);
}
