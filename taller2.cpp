//Profe, si quiere ver los autovectores: quitar los signos comentario en la linea 60. No los pongo por cuestiones de espacio.
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <cmath>
using namespace Eigen;

double valores(int i)
{
	double v;

	
		v = 1.0/(2.0 - (2.0*cos(((2.0*i-1.0)*M_PI)/(2.0*30.0+1.0))));
			
	
	return v;
}

/////////////////////////////////

int main()
{  
	std::cout.precision(16); std::cout.setf(std::ios::scientific);
	int n =30,m,i=0;
	double p,l;
	l=30.0;
	MatrixXd A(n,n);
	VectorXd U(n);
	VectorXd V(n);
	VectorXd W(n);
	for(i ; i < n; i++)
	{
		p = l;
		m = i;
			for( m ; m < n; m++)
			{
				
				A(i,m) = p;
				A(m,i) = p;
				p = p-1.0;
				
			}
		U(i) = valores(n-i);
		l = l-1.0;
	}
	SelfAdjointEigenSolver<MatrixXd> eigensolver(A);
	if (eigensolver.info() != Success) abort();
	//std::cout<<A<<std::endl; //Profe, esta es la matriz.
	for (int ii=0;ii<n;ii++)
	{ 
		W(ii)=( eigensolver.eigenvalues()[ii] - U[ii])/U[ii];
		if (W(ii) < 0)
		
		{
			W(ii)*=-1.0;
		}
		std::cout<<ii+1<<" \t "<<eigensolver.eigenvalues()[ii]<<" \t "<<U[ii]<<" \t "<<W[ii] <<std::endl;
	}
	//std::cout<<"Los autovectores a los autovalores correspondietes son:\n"<<eigensolver.eigenvectors()<<std::endl; //Esto son los autovectores de la matriz
	
	return 0;
}
