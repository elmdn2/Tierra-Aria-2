#include "ElMenu.h" 

using namespace System;
using namespace System::Windows::Forms;
using namespace TF;

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew ElMenu());
    return 0;
}