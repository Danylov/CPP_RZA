//---------------------------------------------------------------------------
#ifndef U_ZAV_H
#define U_ZAV_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TF_ZAV : public TForm
{
__published:	// IDE-managed Components
	TButton *B_OK;
	TButton *B_C;
	void __fastcall SG_ZAVKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall B_CClick(TObject *Sender);
	void __fastcall B_OKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
__fastcall TF_ZAV(TComponent* Owner);
void __fastcall F_ZAV_AFTERCREATE();
};
//---------------------------------------------------------------------------
extern PACKAGE TF_ZAV *F_ZAV;
//---------------------------------------------------------------------------
#endif
