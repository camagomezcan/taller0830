#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
using namespace Eigen;
int main()
{  int n =10,m,i=0;
	double p,l;
	l=10.0;
	MatrixXd A(n,n);
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
			
		l = l-1.0;
		
	}
	SelfAdjointEigenSolver<MatrixXd> eigensolver(A);
	if (eigensolver.info() != Success) abort();
	std::cout<<A<<std::endl;
	std::cout<<"Los autovalores de la Matriz son: \n"<<eigensolver.eigenvalues()<<std::endl;
	std::cout<<"Los autovectores de los autovalores correspondietes son:\n"<<eigensolver.eigenvectors()<<std::endl;
	
	return 0;
}
