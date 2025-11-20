#include "LasInstrucciones.h"

using namespace System;
using namespace TF;

void main2()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew LasInstrucciones());
}