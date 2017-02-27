#ifndef U_F_CH_H
#define U_F_CH_H
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TF_CH : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PUM_CH;
	TMenuItem *N_EX;
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall N_EXClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall FormDestroy(TObject *Sender); // —обытие дл€ отображени€ координаты курсора
private:	// User declarations
public:		// User declarations
__fastcall TF_CH(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_CH *F_CH;
//---------------------------------------------------------------------------
#endif
