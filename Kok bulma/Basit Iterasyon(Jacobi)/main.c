#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x);
double basitIterasyon(double *katsayilar,int derece,double x,double E);

int main(int argc, char *argv[]) {
	
	
	double *katsayilar;
	int derece , i ;
	double E , X0 ;
	double sonuc;
	
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
	
	sonuc=basitIterasyon(katsayilar,derece,X0,E);
	
	printf("\ndenklemin koklerinden biri = %lf",sonuc);
	
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

double basitIterasyon(double *katsayilar,int derece,double x,double E)
{
	int i;
	double h , g , enBuyukDerecelininKatsayisi=katsayilar[0];
	
	for(i=0;i<derece;i++)
	{
		katsayilar[i]=katsayilar[i+1]*(-1);
	}
	
	derece--;
	//katsayilar=(double *)realloc(katsayilar,sizeof(derece));

	g=x;	
	h=pow((f(katsayilar,derece,x)/enBuyukDerecelininKatsayisi) , 1.0/(derece+1));
	
	while(fabs(h-g)>E)
	{
		g=h;
		h=pow((f(katsayilar,derece,g)/enBuyukDerecelininKatsayisi) , 1.0/(derece+1));
		
	}
	
	return h;
}


