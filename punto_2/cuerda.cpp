#include <iostream>
#include <cmath>

using namespace std;
double u_inicial(double x);

double L;

int main(){
	L = 100;
	double T = 40, rho = 10, t = 200;
	double c2 = T/rho;
	double dx = 0.01;
	double dt = 0.001;
	double k2 = pow(c2*dt/dx, 2);
	double x_up = L, x_down = 0;
	int nx = x_up/dx+1;

	double *u = new double[nx];
	double *temp = new double[nx];
	double *viejo = new double[nx];
	double **respuestas = new double*[200];

	for(int i=0; i<200; i++){
		respuestas[i] = new double[nx];
	}

	double x = x_down;
	
	for(int i=0; i<nx; i++){
		u[i] = u_inicial(x);
		temp[i] = u_inicial(x);
		viejo[i] = u_inicial(x);
		x = x + dx;
	}

	int soluciones = 0;
	double aja = 0;

	while(soluciones<200){
		for(int i=1; i<nx-1; i++){
			if(aja==0){
				u[i] = (k2/2.0)*(temp[i+1]+temp[i-1]-2*temp[i])+temp[i];
			}else{
				u[i] = k2*(temp[i+1]+temp[i-1]-2*temp[i])+2*temp[i]-viejo[i];
			}
		}

		if(aja>=soluciones){
			for(int i=0; i<nx; i++){
				respuestas[soluciones][i] = u[i];
			}
			soluciones += 1;
		}
		
		for(int i=1; i<nx-1; i++){
			viejo[i] = temp[i];
			temp[i] = u[i];
		}
		aja += dt;
	}

	x = x_down;
	for(int i=0; i<nx; i++){
		cout<<x<<" ";
		for(int j=0; j<200; j++){
			cout<<respuestas[j][i]<<" ";
		}
		cout<<endl;
		x += dx;
	}
	return 0;
}

double u_inicial(double x){
	if(x <= 0.8*L){
		return 1.25*x/L;
	}else{
		return 5-5*x/L;
	}
}
