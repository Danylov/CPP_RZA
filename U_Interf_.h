#ifndef U_Interf_H
#define U_Interf_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "AdvToolBtn.hpp"
#include "ZylTimer.hpp"
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include "ZColorStringGrid.hpp"
#include <Vcl.Grids.hpp>
#include "AdvPanel.hpp"
#include <Vcl.Mask.hpp>
#include "AdvSplitter.hpp"
#include <Vcl.ImgList.hpp>
#include "AdvMenus.hpp"
#include "AdvScrollBox.hpp"
#include <System.ImageList.hpp>
#include <Vcl.Graphics.hpp>
#include "bdaqctrl.h"
#include "AdvToolBar.hpp"
using namespace Automation::BDaq;
//---------------------------------------------------------------------------
class TF_IK : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PC_IK;
	TTabSheet *PC_IK_TS1;
	TZylTimer *TM_IVS_1;
	TPopupMenu *PUM_IK;
	TMenuItem *N_EX;
	TMenuItem *N1;
	TMenuItem *N_ABOUT;
	TSaveDialog *SV;
	TOpenDialog *OD;
	TImageList *IL_IVS;
	TPopupMenu *PUM_IM;
	TMenuItem *N_T;
	TImageList *IL_RPS;
	TZylTimer *TM_RPS;
	TZylTimer *TM_CKL;
	TMainMenu *MM_IK;
	TMenuItem *MM_IK_F;
	TMenuItem *MM_IK_EX;
	TMenuItem *MM_IK_IVS;
	TMenuItem *MM_IK_RPS;
	TMenuItem *MM_IK_IVS_SV;
	TMenuItem *MM_IK_IVS_LD;
	TMenuItem *MM_IK_IVS_S;
	TMenuItem *MM_IK_IVS_SVB;
	TMenuItem *MM_IK_RPS_SV;
	TMenuItem *MM_IK_RPS_LD;
	TMenuItem *MM_IK_RPS_S;
	TMenuItem *MM_IK_RPS_SI;
	TMenuItem *MM_IK_R3;
	TMenuItem *MM_IK_RPSIVS;
	TMenuItem *MM_IK_IVS_R1;
	TMenuItem *MM_IK_IVS_SKV;
	TMenuItem *MM_IK_IVS_ZKV;
	TMenuItem *MM_IK_PRNT;
	TMenuItem *MM_IK_CKL;
	TMenuItem *MM_IK_CKL_V;
	TGroupBox *GB_PL_1;
	TPanel *PNL_IVS_1;
	TAdvToolButton *B_IVS_SS_1;
	TImage *IM_IVS_I_1;
	TCheckBox *CHB_IVS_1;
	TEdit *E_IVS_NM_1;
	TEdit *E_IVS_NS_1;
	TEdit *E_IVS_DS_1;
	TPanel *PNL_RPS_1;
	TImage *IM_RPS_I_1;
	TEdit *E_RPS_NM_1;
	TEdit *E_RPS_NS_1;
	TEdit *E_RPS_DS_1;
	TCheckBox *CHB_RPS_I_1;
	TMenuItem *MM_IK_RPS_IVS;
	TMenuItem *MM_IK_CKL_2;
	TMenuItem *MM_IK_CKL_NU;
	TMenuItem *MM_IK_CKL_S;
	TMenuItem *MM_IK_CKL_LD;
	TMenuItem *MM_IK_CKL_R;
	TMenuItem *MM_IK_R4;
	TMenuItem *MM_IK_OFR;
	TMenuItem *MM_K;
	TMenuItem *MM_IK_CKL_1;
	TMenuItem *MM_IK_CKL_W;
	TMenuItem *MM_S;
	TMenuItem *MM_O;
	TMenuItem *N2;
	TMenuItem *MM_IK_R2;
	TAdvToolBar *ATB_IK;
	TAdvToolBarButton *ATB_IK_P;
	TImageList *IL_ATB_IK;
	TAdvToolBarButton *ATB_IK_KR;
	TMenuItem *MM_IK_GR;
	TMenuItem *MM_IK_N;
	TMenuItem *MM_IK_VS;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N_EXClick(TObject *Sender);
	void __fastcall N_ABOUTClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall B_IVS_SS_1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TM_IVS_1Timer(TObject *Sender);
	void __fastcall E_IVS_DS_1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall N_TClick(TObject *Sender);
	void __fastcall IM_IVS_I_1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall TM_CKLTimer(TObject *Sender);
	void __fastcall CHB_RPS_I_1Click(TObject *Sender);
	void __fastcall IM_RPS_I_1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall E_IVS_NS_1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall MM_IK_EXClick(TObject *Sender);
	void __fastcall MM_IK_IVS_SVClick(TObject *Sender);
	void __fastcall MM_IK_IVS_SVBClick(TObject *Sender);
	void __fastcall MM_IK_IVS_SKVClick(TObject *Sender);
	void __fastcall MM_IK_IVS_ZKVClick(TObject *Sender);
	void __fastcall MM_IK_IVS_LDClick(TObject *Sender);
	void __fastcall MM_IK_IVS_SClick(TObject *Sender);
	void __fastcall MM_IK_RPSIVSClick(TObject *Sender);
	void __fastcall MM_IK_RPS_SVClick(TObject *Sender);
	void __fastcall MM_IK_RPS_LDClick(TObject *Sender);
	void __fastcall MM_IK_RPS_SClick(TObject *Sender);
	void __fastcall MM_IK_RPS_SIClick(TObject *Sender);
	void __fastcall MM_IK_PRNTClick(TObject *Sender);
	void __fastcall MM_IK_CKL_VClick(TObject *Sender);
	void __fastcall MM_IK_CKL_SClick(TObject *Sender);
	void __fastcall MM_IK_CKL_LDClick(TObject *Sender);
	void __fastcall MM_IK_CKL_RClick(TObject *Sender);
	void __fastcall MM_IK_OFRClick(TObject *Sender);
	void __fastcall MM_KClick(TObject *Sender);
	void __fastcall MM_IK_CKL_WClick(TObject *Sender);
	void __fastcall MM_OClick(TObject *Sender);
	void __fastcall TM_RPSTimer(TObject *Sender);
	void __fastcall ATB_IK_PClick(TObject *Sender);
	void __fastcall ATB_IK_KRClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall MM_IK_NClick(TObject *Sender);
	void __fastcall MM_IK_VSClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	  __fastcall  TF_IK(TComponent* Owner);
void  __fastcall  CheckError(ErrorCode  errorCode);
}; // class TF_IK : public TForm
//---------------------------------------------------------------------------
extern PACKAGE TF_IK *F_IK;
//---------------------------------------------------------------------------
#endif
