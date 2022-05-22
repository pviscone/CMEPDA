#include <cuda_runtime.h>
#include "thrust/device_vector.h"
#include "thrust/host_vector.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/* Creo degli array nella global memory della GPU, li sommo
e alla fine li copio in un array nella host memory

Potrei usare i metodi di thrust per evitare i loop per
scrivere e leggere sul vettore*/

__global__ void ker (float * a, float *b, float *c, size_t n)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n)
    {
        a[idx]=idx;
        b[idx]=2*idx;
        c[idx] = a[idx] + b[idx];
    }
}


int main(){
    //In questo caso converrebbe istanziare i device_vector direttamente sulla GPU senza fare la copia dall'host ma
    // è giusto per fare un esempio
    vector <float> h_a{1,2,3,4,5,6,7,8,9,10};
    vector <float> h_b{2,3,4,5,6,7,8,9,10,11};
    size_t n = h_a.size();
    thrust::device_vector<float> a(n), b(n),c(n);
    thrust::host_vector<float> host_res(n) ;

    //Copia gli std::vector nei vettori della GPU
    a=h_a;
    b=h_b;

    //Alloca il numero minimo di threads necessari per soddisfare il task
    int num_blocks = 1+n/1024;
    int num_threads = (n/num_blocks)+1;


    ker<<<num_blocks,num_threads>>>(a.data().get(),b.data().get(),c.data().get(),n);
    cudaDeviceSynchronize();

    //copia il risultato che è nella GPU nell'host
    host_res = c;
    for (int i = 0; i < n; i++)
    {
        cout << host_res[i] << endl;
    }
    return 0;
}
