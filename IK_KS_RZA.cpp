#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("U_F_CH_.cpp", F_CH);
USEFORM("U_F_CH_IR_.cpp", F_CH_IR);
USEFORM("U_F_CH_NSTR_.cpp", F_CH_NSTR);
USEFORM("U_CKL_.cpp", F_CKL);
USEFORM("U_ZAV_.cpp", F_ZAV);
USEFORM("U_TVS_.cpp", F_TVS);
USEFORM("U_Help_.cpp", F_HELP);
USEFORM("U_Interf_.cpp", F_IK);
USEFORM("U_NSTR_.cpp", F_NSTR);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TF_IK), &F_IK);
		Application->Run();
	} // try
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	} // catch (Exception &exception)
	catch (...)
	{
		try
		{
			throw Exception("");
		} // try
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		} // catch (Exception &exception)
	} // catch (...)
	return 0;
} // int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
//---------------------------------------------------------------------------
