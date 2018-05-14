#include <iostream>
#include <cmath>

using namespace std;

double e;

double dqdt_1(double p_p1);
double dpdt_1(double p_q1);
double dqdt_2(double p_p2);
double dpdt_2(double p_q1, double p_q2);

double dqdt_1(double p_p1){
	return p_p1;
}

double dpdt_1(double p_q1){
	double denominador = pow(pow(2*p_q1,2)+pow(e,2),1.5);
	return -2*p_q1/denominador;
}

double dqdt_2(double p_p2){
	return p_p2;
}

double dpdt_2(double p_q1, double p_q2){
	double denom1 = pow(pow(p_q1-p_q2,2)+pow(e/2.0,2),1.5);
	double denom2 = pow(pow(p_q1+p_q2,2)+pow(e/2.0,2),1.5);
	return (p_q1-p_q2)/denom1-(p_q1+p_q2)/denom2;
}

int main(){
	double dt = 0.006;
	double t_final = 3000;
	double a = 1/(2*sqrt(2));
	e = 0.001;
	double q1=a, p1=0, q2=-a, p2=0;
	int N = t_final/dt;
	double q1_viejo;
	//cout<<q1<<" "<<q2<<" "<<p1<<" "<<p2<<endl;

	double kq1, kq1_1, kq1_2, kq1_3, kq1_4;
	double kp1, kp1_1, kp1_2, kp1_3, kp1_4;
	double kq2, kq2_1, kq2_2, kq2_3, kq2_4;
	double kp2, kp2_1, kp2_2, kp2_3, kp2_4;
	
	for(int i=0; i<N; i++){

		q1_viejo = q1;	

		kq1_1 = dqdt_1(p1);
		kq2_1 = dqdt_2(p2);
		kp1_1 = dpdt_1(q1);
		kp2_1 = dpdt_2(q1, q2);

		kq1_2 = dqdt_1(p1+kp1_1*dt/2.0);
		kq2_2 = dqdt_2(p2+kp2_1*dt/2.0);
		kp1_2 = dpdt_1(q1+kq1_1*dt/2.0);
		kp2_2 = dpdt_2(q1+kq1_1*dt/2.0, q2+kq2_1*dt/2.0);

		kq1_3 = dqdt_1(p1+kp1_2*dt/2.0);
		kq2_3 = dqdt_2(p2+kp2_2*dt/2.0);
		kp1_3 = dpdt_1(q1+kq1_2*dt/2.0);
		kp2_3 = dpdt_2(q1+kq1_2*dt/2.0, q2+kq2_2*dt/2.0);

		kq1_4 = dqdt_1(p1+kp1_3*dt);
		kq2_4 = dqdt_2(p2+kp2_3*dt);
		kp1_4 = dpdt_1(q1+kq1_3*dt);
		kp2_4 = dpdt_2(q1+kq1_3*dt, q2+kq2_3*dt);
				
		kq1 = (kq1_1+2*kq1_2+2*kq1_3+kq1_4)/6.0;
		kq2 = (kq2_1+2*kq2_2+2*kq2_3+kq2_4)/6.0;
		kp1 = (kp1_1+2*kp1_2+2*kp1_3+kp1_4)/6.0;
		kp2 = (kp2_1+2*kp2_2+2*kp2_3+kp2_4)/6.0;
		
		p2 = p2 + dt*kp2;
		p1 = p1 + dt*kp1;
		q1 = q1 + dt*kq1;
		q2 = q2 + dt*kq2;
		

		if(q1*q1_viejo<0){
			cout<<q2<<" "<<p2<<endl;
		}
	}
	
}
