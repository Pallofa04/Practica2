#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512

float Mat[N][N];
float MatDD[N][N];
float V1[N],V2[N],V3[N];

void InitData(){
int i,j;
srand(8824553);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}



// 1. Mostrar un cert nombre d'elements d'un vector.

void PrintVect( float vect[N], int from, int numel ){
	for(int i=from; i<numel; i++ )
		printf("Mostrar vector: %f\n",vect[i]);
}

// 2. Mostrar un cert nombre d'elements d'una fila d'una matriu.

void PrintRow( float Mat[N][N], int row, int from, int numel ){
	for (int j=from; j<numel; j++)
		printf("Mostrar matriu: %f\n",Mat[row][j]);
}

// 3. Calcular la multiplicació d'un escalar d’un vector per una constant consisteix en multiplicar tots els elements d’un vector per una constant.


void MultEscalar( float vect[N], float vectres[N], float alfa ){
	for (int i=0; i<N; i++){
		vectres[i]=vect[i]*alfa;
		printf("Mostrar vector multiplicat: %f\n",vectres[i]);
	}
}

// 4. Calcular el producte escalar de dos vectors.

float Scalar( float vect1[N], float vect2[N] ){
	float res;
        for (int i =0; i<N; i++){
		float multiplicacio = vect1[i]*vect2[i];
		res+=multiplicacio;
	}
	printf("Resultat: %f\n",res);
	return res;
}

// 5. Calcular la longitud d'un vector.

double  Magnitude( float vect[N] ){
	double longitud;
	float  arrel =  Scalar(vect,vect);
	double arrel_d = arrel;
	longitud = sqrt(arrel_d);
	return longitud;
}

// 6. Determinar si dos vectors són ortogonals. Dos vectors són ortogonals si l’angle entre ells és recte. El producte escalar ha de ser 0.

int Ortogonal( float vect1[N],float vect2[N] ){
	float zero =0.0;
	if (Scalar(vect1,vect2)==zero){
		return 1;}
	else{
		return 0;}
}

// 7. Calcular el vector projecció d’un vector sobre un altre.

void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	float numerador = Scalar(vect1,vect2);
	float denominador = Magnitude(vect2);
	float divisio = numerador / denominador;
	for ( int i = 0; i<N; i++){
		vectres[i]= divisio * vect2[i];
	}
}

// 8. Calcular la Infini-norma d’una matriu.

float Infininorm( float M[N][N] ){
	float valor;
	float suma;
	float max = 0.0;
	for (int i = 0; i<N; i++){
		suma = 0.0;
		for (int j = 0; j<N; j++){
			if (M[i][j]<0){
				valor = -(M[i][j]);}
			else{
				valor = M[i][j];}
			suma+=valor;
		}
		if (suma>max){
			max=suma;}
	}
	return max;
}

// 9. Calcular la norma-ú d’una matriu.

float Onenorm( float M[N][N] ){
        float valor;
        float suma;
        float max = 0.0;
        for (int j = 0; j<N; j++){
                suma = 0.0;
                for (int i = 0; i<N; i++){
                        if (M[i][j]<0){
                                valor = -(M[i][j]);}
                        else{
                                valor = M[i][j];}
                        suma+=valor;
                }
                if (suma>max){
                        max=suma;}
        }
        return max;
}

//10. Calcular la norma de Frobenius d’una matriu.

float NormFrobenius( float M[N][N] ){
	float suma = 0.0;
	float quadrat;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			quadrat = M[i][j]*M[i][j];
			suma+=quadrat;
		}
	}
	float frobenius = sqrt(suma);
	return frobenius;
}

//11. Determinar si una matriu és o no Diagonal Dominant.

int DiagonalDom( float M[N][N] ){
	float suma = 0.0;
	float valor;
	int elements = 0;
	int diag = 0;
	for (int i=0; i<N; i++){
		valor=0.0;
		for (int j=0; j<N; j++){
			if (i==j){
				valor = M[i][j];
				elements+=1;}
			else{
				suma+= M[i][j];}
		}
		if (valor>suma){
			diag+=1;}
	}
	if (elements==diag){
		return 1;}
	else{
		return 0;}
}

// Funció main

int main(){

	//A.--------------------------------------------------------------
	 InitData();
	//a. Els elements 0 al 9 i 256 al 265 dels vectors V1, V2 i V3.
	int numel=9;
	int from1=0;
	int from2=256;
	//Vector 1
	PrintVect(V1,from1,numel);
	PrintVect(V1,from2,numel);
	//Vector 2
	PrintVect(V1,from1,numel);
        PrintVect(V1,from2,numel);
	//Vector 3
	PrintVect(V1,from1,numel);
        PrintVect(V1,from2,numel);
	//b. Els elements 0 al 9 de les files 0 i 100 de la matriu Mat.
	PrintRow(Mat,0,0,9);
	PrintRow(Mat,100,0,9);
	//c. Els elements 0 al 9 de la fila 0 i 90 a 99 de la fila 100 de la matriu MatDD.
	PrintRow(MatDD,0,0,9);
        PrintRow(MatDD,100,90,9);

	//B.-------------------------------------------------------------
	//Mat
	printf("\nMatriu Mat\n");
	//a.La seva Infini-norma
	float Infini_norma = Infininorm(Mat);
	printf("La infini-norma de la matriu Mat és %f\n",Infini_norma);
	//b. La seva norma ú
	float Norma_u = Onenorm(Mat);
	printf("La norma ú de la matriu Mat és %f\n",Norma_u);
	//c. La seva norma de Frobenius
	float Frobenius = NormFrobenius(Mat);
	printf("La norma de Frobenius de la matriu Mat és %f\n",Frobenius);
	//d. Si la matriu és o no diagonal dominant
	int Diag_dominant = DiagonalDom(Mat);
	if (Diag_dominant==1){
		printf("La matriu Mat és diagonal dominant\n");}
	else{
		printf("La matriu Mat no és diagonal dominant\n");}

        //MatDD
	printf("\nMatriu MatDD\n");
        //a.La seva Infini-norma
        float Infini_normaDD = Infininorm(MatDD);
        printf("La infini-norma de la matriu MatDD és %f\n",Infini_normaDD);
        //b. La seva norma ú
        float Norma_uDD = Onenorm(MatDD);
        printf("La norma ú de la matriu MatDD és %f\n",Norma_uDD);
        //c. La seva norma de Frobenius
        float FrobeniusDD = NormFrobenius(MatDD);
        printf("La norma de Frobenius de la matriu MatDD és %f\n",FrobeniusDD);
        //d. Si la matriu és o no diagonal dominant
        int Diag_dominantDD = DiagonalDom(MatDD);
        if (Diag_dominantDD==1){
                printf("La matriu MatDD és diagonal dominant\n");}
        else{
                printf("La matriu MatDD no és diagonal dominant\n\n");}

	//C.-----------------------------------------------------------------
	//a. V1·V2
	float Pe12=Scalar(V1,V2);
        printf("Producte escalar V1 i V2 és %f\n", Pe12);
	//n. V1·V3
        float Pe13=Scalar(V1,V3);
        printf("Producte escalar V1 i V3 és %f\n", Pe13);
	//c. V2·V3
	float Pe23=Scalar(V2,V3);
        printf("Producte escalar V2 i V3 és %f\n\n", Pe23);

	//D.----------------------------------------------------------------
	//V1
	double  magnitud1 = Magnitude(V1);
	printf("La magnitud del vector V1 és %f\n",magnitud1);
        //V2
        double  magnitud2 = Magnitude(V2);
        printf("La magnitud del vector V2 és %f\n",magnitud2);
        //V3
        double  magnitud3 = Magnitude(V3);
        printf("La magnitud del vector V3 és %f\n\n",magnitud3);

	//E.------------------------------------------------------------
	//V1 i V2
        int ortogonal12 = Ortogonal(V1,V2);
        if (ortogonal12 ==1){
                printf("Els vectors V1 i V2 són ortogonals.\n");}
        else{
                printf("Els vectors V1 i V2 no són ortogonals.\n");}
	//V1 i V3
        int ortogonal13 = Ortogonal(V1,V3);
        if (ortogonal13 ==1){
                printf("Els vectors V1 i V3 són ortogonals.\n");}
        else{
                printf("Els vectors V1 i V3 no són ortogonals.\n");}

	//V2 i V3
        int ortogonal23 = Ortogonal(V2,V3);
        if (ortogonal23 ==1){
                printf("Els vectors V2 i V3 són ortogonals.\n");}
        else{
                printf("Els vectors V2 i V3 no són ortogonals.\n\n");}

	//F.------------------------------------------------------------
	float vectres[N];
	MultEscalar(V2,vectres,2.0);
	PrintVect(vectres,0,9);
	PrintVect(vectres,256,9);

	//G.-----------------------------------------------------------
	//V2 sobre V3
	printf("\nProjecció V2 sobre V3\n");
	float project23[N];
	Projection(V2,V3,project23);
	PrintVect(project23,0,9);
	//V2 sobre V3
        printf("Projecció V1 sobre V2\n");
        float project12[N];
        Projection(V1,V2,project12);
        PrintVect(project12,0,9);

}

