#include <stdio.h>
#include <CL/cl.h>

#include "../cl_utilities.h"

void printSomePlatformInfo(cl_platform_id platform){
  printf("\tname: ");
  printPlatformInfo(platform, CL_PLATFORM_NAME);
  printf("\n\tversion: ");
  printPlatformInfo(platform, CL_PLATFORM_VERSION);
  printf("\n");
}

void printSomeDeviceInfo(cl_device_id device){
  printf("\t\tname: ");
  printDeviceInfo(device, CL_DEVICE_NAME);
  printf("\n\t\tvendor: ");
  printDeviceInfo(device, CL_DEVICE_VENDOR);
  printf("\n\t\tglobal memory: ");
  printDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_SIZE);
  printf("\n\t\tlocal memory: ");
  printDeviceInfo(device, CL_DEVICE_LOCAL_MEM_SIZE);
  printf("\n\t\tcompute units: ");
  printDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS);
  printf("\n\t\tpreferred vector width char: ");
  printDeviceInfo(device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
  printf("\n\t\tnative vector width char: ");
  printDeviceInfo(device, CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
  printf("\n\t\tmax work group size: ");
  printDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE);
  printf("\n");
}


int main(int argc, char *argv[])
{
  cl_platform_id *platforms;
  cl_device_id *gpus;
  cl_uint platform_num, gpu_num;
  size_t i, j;

  // Platforms
  clGetPlatformIDs(1, NULL, &platform_num);
  platforms = (cl_platform_id*)malloc(platform_num*sizeof(cl_platform_id));
  clGetPlatformIDs(platform_num, platforms, NULL);

  printf("I found %d platforms\n", platform_num);
  for (i = 0; i < platform_num; ++i) {
    printf("Platform #%ld\n", i);
    printSomePlatformInfo(platforms[i]);

    // Devices
    clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, 1, NULL, &gpu_num);
    gpus = (cl_device_id*)malloc(gpu_num*sizeof(cl_device_id));
    clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, gpu_num, gpus, NULL);

    printf("\tFound %d GPUs\n", gpu_num);
    for (j = 0; j < gpu_num; ++j) {
      printf("\tGPU #%ld\n", j);
      printSomeDeviceInfo(gpus[i]);
    }
    
    free(gpus);
  }
  


  free(platforms);
  
  return 0;
}
