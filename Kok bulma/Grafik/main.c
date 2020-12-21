#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x);
double grafik(double *katsayilar,int derece,double x,double artis,double E);

int main(int argc, char *argv[]) {
	
	double E , x , artis;	
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
	
	printf("x ilk degerini giriniz : "); scanf("%lf",&x);
	
	printf("artis degerini giriniz : "); scanf("%lf",&artis);
	
	
	printf("denkleminin koklerinden biri %lf",grafik(katsayilar,derece,x,artis,E));
	
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


double grafik(double *katsayilar,int derece,double x,double artis,double E)
{
	//artis degeri zaten delta X
		
	while(artis > E)
	{
			while(f(katsayilar,derece+1,x) < 0)
			{
				x += artis;	
				printf("%lf \n",x);
			}
			x -= artis; //en son 1 kez artmis degeri 0'dan buyuk oldu. Onceki degere donmek icin - olacak
		artis /=2;
	}
	
	while(f(katsayilar,derece+1,x) < 0) // son artis yapilarak deger bulunlur
	{
		x += artis;			
	}
	
	return x;
}


