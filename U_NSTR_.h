#ifndef U_NSTR_H
#define U_NSTR_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "ZColorStringGrid.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include "AdvToolBtn.hpp"
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TF_NSTR : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PC_NSTR;
	TTabSheet *PC_NSTR_2;
	TLabel *L_PL;
	TComboBox *CB_PL;
	TButton *B_PL;
	TButton *B_SH;
	TTabSheet *PC_NSTR_1;
	TZColorStringGrid *ZCSG_NSTR;
	TFontDialog *FD;
	TColorDialog *CD;
	TAdvToolButton *B_F;
	TTabSheet *PC_NSTR_3;
	TLabel *L_NU_VC_2;
	TLabel *L_NU_VC_3;
	TButton *B_OK;
	TMaskEdit *ME_NU_VC_2;
	TMaskEdit *ME_NU_VC_3;
	void __fastcall B_PLClick(TObject *Sender);
	void __fastcall CB_PLChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall B_SHClick(TObject *Sender);
	void __fastcall FDApply(TObject *Sender, HWND Wnd);
	void __fastcall ZCSG_NSTRDblClick(TObject *Sender);
	void __fastcall B_FClick(TObject *Sender);
	void __fastcall B_OKClick(TObject *Sender);
	void __fastcall ME_NU_VC_2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ME_NU_VC_3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PC_NSTRChange(TObject *Sender);
	void __fastcall ZCSG_NSTRMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ZCSG_NSTRKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ZCSG_NSTRKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TF_NSTR(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_NSTR *F_NSTR;
//---------------------------------------------------------------------------
#endif
