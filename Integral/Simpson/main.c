#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *arr,int equ_pow,double x);
double simpson(double *katsayilar,int derece,double ust,double alt,double n);

int main(int argc, char *argv[]) {
	
	double ust , alt , n;	
	double *katsayilar;
	int derece , i ;//n mesafe veya hata payidir,ne kadar buyuk olursa hata payi kuculur
	
	printf("Polinomun derecesini giriniz : "); scanf("%d",&derece);
	katsayilar=(double *) calloc(derece+1 ,sizeof(double));
	for(i=0;i<=derece;i++)
	{	
		printf("derecesi %d olan elemanin katsayisi? : ",derece-i);
		scanf("%lf",&katsayilar[i]);	
	}
	
	printf("n (mesafe) degerini giriniz : "); scanf("%lf",&n);
	

	printf("ust limit degerini giriniz : "); scanf("%lf",&ust);
	
	printf("alt limit degerini giriniz : "); scanf("%lf",&alt);

	printf("integral degeri = %lf",simpson(katsayilar,derece,ust,alt,n));
	
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

double simpson(double *katsayilar,int derece,double ust,double alt,double n) //n aradaki mesafe,hata payi gibi dusunulebilir
{
	double toplam ,deltaX = (ust-alt)/n; //deltaX = h
	int i;
	
	toplam = (f(katsayilar,derece,alt) + f(katsayilar,derece,ust)) ;
	
	for(i=1; i< n ;i++)
	{
		if(i%2==0)
			toplam += 2 * f(katsayilar,derece,alt + i*deltaX);
		else
			toplam += 4 * f(katsayilar,derece,alt + i*deltaX);
	}
	
	return toplam*deltaX/3;
}
