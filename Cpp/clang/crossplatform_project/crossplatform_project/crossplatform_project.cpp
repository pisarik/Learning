// crossplatform_project.cpp : Defines the exported functions for the DLL application.
//

#include "crossplatform_project.h"

// This is an example of an exported variable
crossplatform_project_API int ncrossplatform_project=0;

// This is an example of an exported function.
crossplatform_project_API int fncrossplatform_project(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see crossplatform_project.h for the class definition
Ccrossplatform_project::Ccrossplatform_project()
{
    return;
}
