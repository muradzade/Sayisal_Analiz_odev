#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define MAX 20

float** MatInverse(float** matris,int N);

int main()
{
	int M,N, i,j ;
	float **matris;
	
	printf("Matrisin satir sayini giriniz : "); scanf("%d", &N);
	
	matris=(float **)calloc(N,sizeof(float *));
	for(i=0;i<N;i++) matris[i]=(float *)calloc(N,sizeof(float));
	
	for (i = 0;i < N; i++)
	{
		for (j = 0;j < N; j++)
       	{
       		printf("%d X %d elemanini giriniz : ",i,j); scanf("%f", &matris[i][j]);  
			
        }
    }
    
    float **sonuc=MatInverse(matris,N);
    
	printf("\nGirilen Matrisin Inversi\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%3.3f ",sonuc[i][j]);
        printf("\n");
    }
    
    free(sonuc);
	free(matris);
	
	getch();
	
	return 0;
}
 

float** MatInverse(float** matris,int N)
{
    //float matris[10][10];
    //float birim[10][10];
    float **birim;
	int i,j,tur;
    float bolum,kat;
	birim=(float **)calloc(N,sizeof(float *));
	for(i=0;i<N;i++) birim[i]=(float *)calloc(N,sizeof(float));
//    printf("Matrisin satir sayisini giriniz:  ");
//    scanf("%d",&N);
//    for(i=0;i<=N-1;i++)
//        for(j=0;j<=N-1;j++)
//        {
//            printf("Matrisin %d.satir %d.sutun elemanini giriniz:  ",i+1,j+1);
//            scanf("%f",&matris[i][j]);
//        }

    //birim matris olusturuluyor
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            if(i==j)
                birim[i][j]=1;
            else
                birim[i][j]=0;
        }


    for(tur=0;tur<N;tur++)
    {
        bolum=matris[tur][tur];
        for(j=0;j<N;j++)
        {
            matris[tur][j]=matris[tur][j]/bolum;
            birim[tur][j]/=bolum;

        }

        for(i=0;i<N;i++)
        {
            if(i!=tur)
            {
                kat=matris[tur][tur]*matris[i][tur];
                for(j=0;j<N;j++)
                 {
                    matris[i][j]-=matris[tur][j]*kat;
                    birim[i][j]-=birim[tur][j]*kat;
                 }
            }
        }
    }
	
	return birim;
}
