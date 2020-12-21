#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double *katsayilar,int N,double *degiskenler,int Xn);
double *gauss_seidel(double **katsayilar,int N,double E);

int main(int argc, char *argv[]) {
	
	int N ,i ,j;
	double **katsayilar ,E;
	
	printf("Degisken sayisini giriniz : "); scanf("%d",&N);
	printf("Epislon degerini giriniz : "); scanf("%lf",&E);
	
	katsayilar=(double **)calloc(N,sizeof(double *));
	for(i=0;i<N;i++) katsayilar[i]=(double *)calloc(N+1,sizeof(double));
	
	for(i=0;i<N;i++)
	{
		printf("%d. fonksiyon icin : \n",i+1);
		for(j=0;j<N;j++)
		{
			printf("%d. degiskenin katsayisini giriniz : ",j+1); scanf("%lf",&katsayilar[i][j]);
		}
		printf("fonksiyonun esit oldugu deger ? :");scanf("%lf",&katsayilar[i][N]);
		printf("\n");
	}
	
	
	double *degiskenler=gauss_seidel(katsayilar,N,E);
	
	for(i=0;i<N;i++) printf("X%d = %lf\n",i,degiskenler[i]);
	
	for(i=0;i<N+1;i++)
		free(katsayilar[i]);
	free(katsayilar);
	free(degiskenler);
	
	
	getch();
	return 0;
}

double f(double *katsayilar,int N,double *degiskenler,int Xn)
{
	int i;
	double temp=0;
	for(i=0;i<N;i++)
	{
		if(i!=Xn)
		{
			temp+=katsayilar[i]*degiskenler[i];
		}
	}
	return (katsayilar[N] - temp)/katsayilar[Xn];

}

double *gauss_seidel(double **katsayilar,int N,double E)
{
	int i,j,flag=1,E_denKucukDegiskenSayi;
	double *onceki_degiskenler=(double *)calloc(N,sizeof(double));
	double *degiskenler=(double *)calloc(N,sizeof(double));
	for(i=0;i<N;i++) degiskenler[i]=0;
	
	while(flag)
	{
		for(i=0;i<N;i++) onceki_degiskenler[i]=degiskenler[i];//degiskenler dongu kontrolu icin onceki_degiskenler yedeklernir
		
		for(i=0;i<N;i++)
		{
			degiskenler[i]=f(katsayilar[i],N,degiskenler,i); //degiskenlerin yeni degeri icin guncel degerler degiskenler fonksiyona gonderilerek kullanilir
		}
		
		E_denKucukDegiskenSayi=0;
		for(i=0;i<N;i++)
		{
			if(fabs(degiskenler[i]-onceki_degiskenler[i])<E)
				E_denKucukDegiskenSayi++;
		}
		if(E_denKucukDegiskenSayi==N) flag=0;
		
	}
	free(onceki_degiskenler);
	
	return degiskenler;
}

