#ifndef U_F_CH_NSTR_H
#define U_F_CH_NSTR_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "NxColumns6.hpp"
#include "NxControls6.hpp"
#include "NxCustomGrid6.hpp"
#include "NxGrid6.hpp"
#include "NxGridView6.hpp"
#include "NxVirtualGrid6.hpp"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TF_CH_NSTR : public TForm
{
__published:	// IDE-managed Components
	TNextGrid6 *NGr_IVS;
	TNxReportGridView6 *NxReportGridView61;
	TNxTextColumn6 *NxTextColumn61;
	TNxCheckBoxColumn6 *NxCheckBoxColumn61;
	TNxTextColumn6 *NxTextColumn62;
	TComboBox *CB_PL;
	TLabel *L_PL;
	TNextGrid6 *NGr_RPS;
	TNxReportGridView6 *NxReportGridView62;
	TNxCheckBoxColumn6 *NxCheckBoxColumn62;
	TNxTextColumn6 *NxTextColumn63;
	TNxTextColumn6 *NxTextColumn64;
	TNxComboBoxColumn6 *NxComboBoxColumn61;
	TNxTextColumn6 *NxTextColumn66;
	TNxComboBoxColumn6 *NxComboBoxColumn62;
	TNxTextColumn6 *NxTextColumn65;
	TColorDialog *CD;
	TButton *B_PL;
	TButton *B_GR;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall NGr_IVSCellClick(TObject *Sender, int ACol, int ARow, TMouseButton Button);
	void __fastcall B_PLClick(TObject *Sender);
	void __fastcall CB_PLChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall B_GRClick(TObject *Sender);

private:	// User declarations
TColor   SC_Current; // Текущее значение цвета выделенных ячеек в TNextGrid6

public:		// User declarations
	__fastcall TF_CH_NSTR(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_CH_NSTR *F_CH_NSTR;
//---------------------------------------------------------------------------
#endif
