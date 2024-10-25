
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void lire(float *A, int d) {
    int i;
    printf("Vous allez entrer %d valeurs\n",d);
    for (i = 0; i < d; i++) {
    	printf("element %d\t",i);
        scanf("%f", &A[i]); }}
void afficher(float *A, int d) {
	int i;
    for (i = 0; i < d; i++) {
        printf("%.0f\t", A[i]);}
    printf("\n");}
float produit(float *A, float *B, int d) {
	int i;
    float P = 0.0;
    for (i = 0; i < d; i++) {
        P += A[i] * B[i];}
    return P;}
float* somme(float *A, float *B, int d) {
    int i;
    float *Z;
    Z = (float*)malloc(d * sizeof(float));
    if (Z == NULL) {
        printf("erreur de reservation\n");
        return NULL;}
    for (i = 0; i < d; i++) {
        Z[i] = A[i] + B[i];}
    return Z;}
float* scal(float A[], int d, int k) {
    int i;
    float *z = (float*)malloc(d * sizeof(float));
    if (z == NULL) {
        printf("Erreur de reservation\n");
        exit(1);}
    for (i = 0; i < d; i++) {
        z[i] = k * A[i];}
    return z;}
void dist(float *A, float *B, int d) {
    int i;
    float somme = 0.0;
    for (i = 0; i < d; i++) {
        somme += pow((A[i] - B[i]), 2);}
    float dis = sqrt(somme);
    printf("La distance Euclidienne est : %.2f\n", dis);}
int main() {
    int ch, d, k;
    float *A, *B, *result;
    printf("Entrer la dimension des vecteurs : ");
    scanf("%d", &d);
    A = (float*)malloc(d * sizeof(float));
    B = (float*)malloc(d * sizeof(float));
    if (A == NULL || B == NULL) {
        printf("Erreur de reservation\n");
        return 1;}
    do {
        printf("\t----Menu----\n");
        printf("\t1- Lecture\n");
        printf("\t2- Affichage\n");
        printf("\t3- Somme\n");
        printf("\t4- Produit\n");
        printf("\t5- Scalaire\n");
        printf("\t6- Distance\n");
        printf("\t7- Quitter\n");
        printf("Taper votre choix : ");
        scanf("%d", &ch);
        if (ch != 7) {
            lire(A, d);
            lire(B, d);}
        switch (ch) {
            case 1:
                break;
            case 2:
            	lire(A, d);
            	lire(B, d);
                break;
            case 3:
                result = somme(A, B, d);
                printf("La somme des deux matrices est :\n");
                afficher(result, d);
                free(result);
                break;
            case 4:
                printf("Le produit des deux matrices est : %.0f\n", produit(A, B, d));
                break;
            case 5:
                printf("Entrer le scalaire multiplicatif : ");
                scanf("%d", &k);
                result = scal(A, d, k);
                printf("Le produit scalaire est :\n");
                printf("\n");
                afficher(result, d);
                printf("Le tableau est \n");
                free(result);
                break;
            case 6:
                dist(A, B, d);
                break;
            case 7:
                break;
            default:
                printf("Choix invalide\n");}
        if (ch != 7) {
            afficher(A, d);
            afficher(B, d);}
    } while (ch != 7);
    free(A);
    free(B);
    return 0;}

void affichage ( int **A, int C, int L)
{
		int i, j ;
	for (i=0 ; i<L ; i++)
	{
		for ( j=0 ; j<C ; j++)
		{
			printf(" %d\t", *(A[i]+j));	
		}
		printf("\n");
	}
}

int ** produit ( int **A, int **B, int L, int LC, int C)
{
	int **D;
	int p,i,k,j;
	D= allouer (L,C);
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
			{
				p=0;
					for (k=0; k<LC;k++)
						{
						p=p+ A[i][k]*B[k][j];	
						}
						D[i][j]=p;
		}
	}
	return (D);
}

main()
{
	int **M1, **M2, **M3;
	int Lig=3, LC=2, Col=3;
	M1=allouer(Lig,Col);
	M2=allouer(LC,Lig);
	M3=allouer(Lig,Col);
	printf("----Matrice M1----\n");
	lecture(M1, Lig,LC);
	affichage(M1,Lig,LC);
	printf("----Matrice M2----\n");
	lecture(M2,LC,Col);
	affichage(M1,LC,Col);
	printf("----Matrice M3----\n");
	M3= produit(M1,M2,Lig,LC,Col);
	affichage(M3,Lig,Col);
	liberation(M1,Lig,Col);
	liberation(M2,Lig,Col);
	liberation(M3,Lig,Col);
	system("pause");
}
