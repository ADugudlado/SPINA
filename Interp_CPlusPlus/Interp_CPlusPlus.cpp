// Interp_CPlusPlus.cpp : main project file.

//#include "Interp_main.h"
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