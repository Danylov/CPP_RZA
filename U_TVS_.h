//---------------------------------------------------------------------------

#ifndef U_TVS_H
#define U_TVS_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvToolBtn.hpp"
//---------------------------------------------------------------------------
class TF_TVS : public TForm
{
__published:	// IDE-managed Components
	TAdvToolButton *B_0_1;
	TAdvToolButton *B_1_0;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall B_0_1Click(TObject *Sender);
	void __fastcall B_1_0Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF_TVS(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_TVS *F_TVS;
//---------------------------------------------------------------------------
#endif
