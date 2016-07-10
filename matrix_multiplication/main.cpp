#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

void prettyPrint(int &N, double** A, double** B, double** C)
{
    for(int ii = 0; ii < N; ii++)
    {
        for(int jj = 0; jj < N; jj++)
        {
            cout << A[ii][jj] << " ";
        }
        
        cout << "   ";
        if(ii == ceil(N/2))
            cout << "X" << "   ";
        else
            cout << "    ";
        
        for(int jj = 0; jj < N; jj++)
        {
            cout << B[ii][jj] << " ";
        }
        
        cout << "   ";
        if(ii == ceil(N/2))
            cout << "=" << "   ";
        else
            cout << "    ";
        
        for(int jj = 0; jj < N; jj++)
        {
            cout << C[ii][jj] << " ";
        }
        
        cout << endl;
    }

}

int main()
{
    int N;
    cout << "How big should the matrix be? " << endl;
    cin >> N;
    
    double** A = new double*[N];
    double** B = new double*[N];
    double** C = new double*[N];
    
    //initialize second dimension of array (cannot dynamically allocate 2D array in C++)
    for(int ii = 0; ii < N; ii++)
    {
        A[ii] = new double[N];
        B[ii] = new double[N];
        C[ii] = new double[N];
    }
    
    //set arrays to some values
    for(int ii = 0; ii < N; ii++)
    {
        for(int jj = 0; jj < N; jj++)
        {
            A[ii][jj] = ii * N + jj;
            B[ii][jj] = jj * N + ii;
            C[ii][jj] = 0;
        }
    }
    
    clock_t begin = clock();
    
    //matrix multiplication!
    for(int ii = 0; ii < N; ii++)
        for(int xx = 0; xx < N; xx++)
            for(int zz = 0; zz < N; zz++)
            {
                C[ii][xx] += A[ii][zz] * B[zz][xx];
            }
    
    clock_t end = clock();
    double time = double(end-begin);
    cout << "The elapsed time is " << time << " clocks!" << endl << endl;
    
    prettyPrint(N, A, B, C);
    
    //deallocate 2D arrays
    for(int ii = 0; ii < N; ii++)
    {
        delete[] A[ii];
        delete[] B[ii];
        delete[] C[ii];
    }
    delete A;
    delete B;
    delete C;
    
    return 0;
}
