#include <stdio.h>
#include <stdlib.h>

float GregoryNewton(float* x,float* y,int n ,float degisken);


int fact(int a)
{
	int i;
	int carpim=1;
	for(i=2;i<=a;i++)
		carpim *= i;
	return carpim;
}

int main(int argc, char *argv[]) {
	
	int n , i ;
	float *x , *y ,degisken;
	float sonuc;
	
	printf("verilen x degerlerinin sayini giriniz : "); scanf("%d",&n);
	
	x=(float *)calloc(n,sizeof(float));
	y=(float *)calloc(n,sizeof(float));
	
	printf("x degerlerini giriniz : \n");
	for(i=0;i<n;i++) scanf("%f",&x[i]);
		
	printf("y degerlerini giriniz : \n");
	for(i=0;i<n;i++) scanf("%f",&y[i]);
	
	printf("Y degerini bulmak istediginiz X degerini giriniz : "); scanf("%f",&degisken);
	
	sonuc = GregoryNewton(x,y,n,degisken);

	printf("x = %.3f degerinde fonksiyon %f degerini alir\n",degisken,sonuc);
	
	getch();
	return 0;
}


float GregoryNewton(float *x,float *y,int n ,float degisken)
{
	int i,j,k,flag=1;
	float *temp	=(float *)calloc(n,sizeof(float));
	float toplam=y[0] , temp2=1 , h;
	
	i=1;
	while(flag)
	{
		
		for(j=i;j<n;j++)
		{
			temp[j]=y[j]-y[j-1];//gecici olarak tempe aktariyoruzki y bozulmasin/cunki y degerlerine daha ihtiyacimiz var
		}
		
		for(j=i;j<n;j++)
		{
			y[j]=temp[j];
		}
		
		
		//donguden cikma kosulunu kontrol eder
		flag=0;
		
		for(j=i;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(y[j]!=y[k])
				{
					flag=1;
				}
			}		
		}
		
		i++;
	}
	i--; // i azaldiktan sonra delta^i f ifade edecek

	h=x[1]-x[0];
	
	for(j=1;j<=i;j++)
	{
		temp2 *= (degisken - x[j-1])/(h);//her seferinde X-Xi ile carparak h degerine boluyoruz
										//bunlar her iterasyon icin sabit oldugu icin farkli degiskende tuttum
		toplam += temp2*y[j]/fact(j);
	}
	
	return toplam;
}

