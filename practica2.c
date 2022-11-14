#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

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
		printf("%f\n",vect[i]);
}

// 2. Mostrar un cert nombre d'elements d'una fila d'una matriu.

void PrintRow( float Mat[N][N], int row, int from, int numel ){
	for (int j=from; j<numel; j++)
		printf("%f\n",Mat[row][j]);
}

// 3. Calcular la multiplicació d'un escalar d’un vector per una constant consisteix en multiplicar tots els elements d’un vector per una constant.


void MultEscalar( float vect[N], float vectres[N], float alfa ){
	for (int i=0; i<N; i++){
		vectres[i]=vect[i]*alfa;
		printf("%f\n",vectres[i]);
	}
}

// 4. Calcular el producte escalar de dos vectors.

float Scalar( float vect1[N], float vect2[N] ){
	float res;
        for (int i =0; i<N; i++){
		float multiplicacio = vect1[i]*vect2[i];
		res+=multiplicacio;
	}
	return res;
}

// 5. Calcular la longitud d'un vector.

float Magnitude( float vect[N] ){
	float arrel=0;
	float longitud;
	for (int i=0; i<N; i++){
		double vect[i];
		double potencia=2;
		double  elevat = pow(vect[i],potencia);
		printf("La potència és %d\n",elevat);
		arrel+=elevat;
	}
	longitud = sqrt(arrel);
	printf("%f\n",longitud);
	return longitud;
}

// 6. Determinar si dos vectors són ortogonals. Dos vectors són ortogonals si l’angle entre ells és recte. El producte escalar ha de ser 0.

int Ortogonal( float vect[N] ){
	if (Scalar(vect,V2)==0){
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


int main(){
	InitData();
	PrintVect(V1,2,6);
	PrintRow(Mat,4,4,7);
	MultEscalar(V1,V3,4.3);
	float prod_escalar=Scalar(V1,V2);
	float longitud=Magnitude(V1);
	Projection(V1,V2,V3);
}
