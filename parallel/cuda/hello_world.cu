#include <cuda_runtime.h>
#include <iostream>

using namespace std;

__global__ void kernel(void){
    printf("Hello, World from the GPU! (block: %d thread:(%d %d %d))\n",blockIdx.x,threadIdx.x,threadIdx.y,threadIdx.z);
}

int main(){
    kernel<<<2,2>>>();
    cudaDeviceSynchronize();
    cout << "Hello, World from the CPU!" << endl;
    return 0;
}