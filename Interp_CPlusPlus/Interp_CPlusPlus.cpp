// Interp_CPlusPlus.cpp : main project file.

////////////////////////////////////////////////////////////////////////
// Interp_CplusPlus.cpp: main project file which initiates the instance 
// of SPINA form.
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "SPINAUserInterface.h"


[STAThreadAttribute]
int main(array<System::String  ^> ^args)
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false); 
   Application::Run(gcnew Interp_CPlusPlus::SPINAUserInterface());
   
   return 0;
}

//"m[]={1}:{2}:{3};s[]={1,0,0}:{0,1,0}:{0,0,1};m[]=s[]*m[];"