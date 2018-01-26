#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the crossplatform_project_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// crossplatform_project_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef crossplatform_project_EXPORTS
#define crossplatform_project_API __declspec(dllexport)
#else
#define crossplatform_project_API __declspec(dllimport)
#endif

// This is an example of a class exported from the crossplatform_project.dll
class crossplatform_project_API Ccrossplatform_project
{
public:
    Ccrossplatform_project();
    // TODO: add your methods here.
};

// This is an example of an exported variable
extern crossplatform_project_API int ncrossplatform_project;

// This is an example of an exported function.
crossplatform_project_API int fncrossplatform_project(void);
