//---------------------------------------------------------------------------
#ifndef U_CKL_H
#define U_CKL_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvPanel.hpp"
#include "AdvSplitter.hpp"
#include "ZColorStringGrid.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TF_CKL : public TForm
{
__published:	// IDE-managed Components
	TAdvPanel *P_C_SG;
	TLabel *L_DT_VC;
	TZColorStringGrid *SG_IK_NU;
	TEdit *E_DT_VC;
	TAdvSplitter *S_C;
	TMaskEdit *ME1;
	TPanel *P_C_REZ;
	TZColorStringGrid *SG_IK_REZ;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ME1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SG_IK_NUClick(TObject *Sender);
	void __fastcall SG_IK_NUDblClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF_CKL(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_CKL *F_CKL;
//---------------------------------------------------------------------------
#endif
