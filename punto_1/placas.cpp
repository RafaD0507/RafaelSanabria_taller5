#include <iostream>
#include <cmath>

using namespace std;

double v_inicial(double x, double y);
double V;

int main(){
	double L = 5.0, l = 2.0, d = 1.0; //longitudes en centimetros
	double h = 5.0/512.0; // tamanio del paso
	V = 100; //potencial electrico en Volts
	int N = 2*pow(L/h, 2); //numero de iteraciones
	N = 10000;
	int tamanio = L/h+1.0; //dimension de la matriz
	double **cuadrado = new double*[tamanio]; //matriz
	double **viejo = new double*[tamanio]; //matriz donde se guardan los valores antiguos
	double **campox = new double*[tamaio]; 
	double **campoy = new double*[tamanio];
	
	//Se inicializa la matriz
	for(int i=0; i<tamanio; i++){
		cuadrado[i] = new double[tamanio];
		viejo[i] = new double[tamanio];
		campox[i] = new double[tamanio];
		campoy[i] = new double[tamanio];
	}
	
	//Se carga la matriz con las condiciones iniciales
	for(int i=0; i<tamanio; i++){
		for(int j=0; j<tamanio; j++){
			cuadrado[i][j] = v_inicial(j*h,i*h);
			viejo[i][j] = v_inicial(j*h, i*h);
			campox[i][j] = 0.0;
			campoy[i][j]  0.0;
		} 
	}

	for(int iter=0; iter<N; iter++){
		for(int i=1; i<tamanio-1; i++){
			for(int j=1; j<tamanio-1; j++){
				if(not(j*h>=1.5 && j*h<=3.5 && i*h>=2.0 && i*h<=3.0)){
					cuadrado[i][j] = (viejo[i+1][j]+viejo[i-1][j]+viejo[i][j+1]+viejo[i][j-1])/4.0;
				}
			}
		}
		for(int i=1; i<tamanio-1; i++){
			for(int j=1; j<tamanio-1; j++){
				viejo[i][j] = cuadrado[i][j];
			}
		}
	}

	for(int i=0; i<tamanio-1; i++{
		for(int j=0; j<tamanio-1; j++){
			campox[i][j] = -(cuadrado[i][j+1]-cuadrado[i][j])/h;
			campoy[i][j] = -(Cuadrado[i+1][j]-cuadrado[i][j])/h;
		}
	}	

	for(int i=0; i<tamanio; i++){
		for(int j=0; j<tamanio; j++){
			cout<<cuadrado[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

//Potencial inicial debido a las placas
double v_inicial(double x, double y){
	if(x>=1.5 && x<=3.5 && y>=2.0 && y<=3.0){
		if(y==2){
			return -V/2.0;
		}else if(y==3.0){
			return V/2.0;
		}else{
			return V;
		}
	}else{
		return 0;
	}
}
