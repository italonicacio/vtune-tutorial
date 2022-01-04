#include <iostream>
#include <chrono>
#include <string>

#include "mkl.h"

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<float> fsec;

#define MAX 10000

int main()
{
    int N = MAX;

	double *A = nullptr;
	double *w = nullptr; 
	A = new double[N*N];
	w = new double[N];

	
	int ISEED[4] = {0,0,0,1}, ione = 1;	

	double error;

	std::cout << "Creating the Matrix" << std::endl;
	std::cout << " - N = " << N << std::endl;
	
	std::chrono::high_resolution_clock::time_point time_start;
	std::chrono::high_resolution_clock::time_point time_end;
	fsec fs;

	time_start = Time::now();
	LAPACKE_dlarnv(ione, ISEED, N*N, A);
	time_end = Time::now();
	fs = (time_end - time_start);
	std::cout << "Time dlarnv: " << fs.count() << std::endl;

	time_start = Time::now();
	LAPACKE_dsyevd(LAPACK_ROW_MAJOR, 'V', 'L', N, A, N, w);
	time_end = Time::now();
	fs = (time_end - time_start);
	std::cout << "Time dsyevd: " << fs.count() << std::endl;
	
	delete[] A;
	delete[] w;

    return 0;
}

