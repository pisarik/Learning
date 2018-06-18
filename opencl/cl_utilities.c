#include "cl_utilities.h"

void printPlatformInfo(cl_platform_id platform, cl_platform_info info){
  char *param;
  size_t param_size;

  clGetPlatformInfo(platform, info, 0, NULL, &param_size);

  param = (char*)malloc(param_size);
  clGetPlatformInfo(platform, info, param_size, param, NULL);
  printf("%s", param);
  free(param);
}

void printDeviceInfo(cl_device_id device, cl_device_info info){
  char *param;
  cl_uint ui_param;
  cl_ulong ul_param;
  size_t param_size;

  if (info == CL_DEVICE_NAME || info == CL_DEVICE_VENDOR ||
      info == CL_DEVICE_VERSION || info == CL_DEVICE_EXTENSIONS ||
      info == CL_DRIVER_VERSION){
    clGetDeviceInfo(device, info, 0, NULL, &param_size);

    param = (char*)malloc(param_size);
    clGetDeviceInfo(device, info, param_size, param, NULL);
    printf("%s", param);
    free(param);
  }
  else if (info == CL_DEVICE_GLOBAL_MEM_SIZE ||
           info == CL_DEVICE_LOCAL_MEM_SIZE){
    clGetDeviceInfo(device, info, sizeof(ul_param), &ul_param, NULL);
    printf("%ld", ul_param);
  }
  else{
    clGetDeviceInfo(device, info, sizeof(ui_param), &ui_param, NULL);
    printf("%d", ui_param);
  }
}
