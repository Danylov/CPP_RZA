#include <vcl.h>
#pragma hdrstop
#include "U_CKL_.h"
#include "Common_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPanel"
#pragma link "AdvSplitter"
#pragma link "ZColorStringGrid"
#pragma resource "*.dfm"
TF_CKL *F_CKL;
//---------------------------------------------------------------------------
__fastcall TF_CKL::TF_CKL(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_CKL::TF_CKL(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::FormCreate(TObject *Sender)
{
Top                       = 180;
Left                      =   0;
Width                     = Screen->Width;
Height                    = Screen->Height - Top - 28;
HorzScrollBar->Visible    = true;
VertScrollBar->Visible    = true;
AutoScroll                = true;
HorzScrollBar->ButtonSize = 3;
HorzScrollBar->Increment  = 1;
HorzScrollBar->Range      = ClientWidth - 10;
HorzScrollBar->Size       = 3;
HorzScrollBar->Style      = ssRegular;
HorzScrollBar->ThumbSize  = 3;
HorzScrollBar->Tracking   = true;
VertScrollBar->ButtonSize = 3;
VertScrollBar->Increment  = 1;
VertScrollBar->Range      = ClientHeight - 10;
VertScrollBar->Size       = 3;
VertScrollBar->Style      = ssRegular;
VertScrollBar->ThumbSize  = 3;
VertScrollBar->Tracking   = true;
// Расположение  элементов  второй  вкладки  на  форме
P_C_SG->Top               = 0;
P_C_SG->Left              = 0;
P_C_SG->Width             = 550;
P_C_SG->Height            = ClientHeight - 5;
E_DT_VC->Top              = P_C_SG->ClientHeight - E_DT_VC->Height - 20;
L_DT_VC->Top              = E_DT_VC->Top + (E_DT_VC->Height - L_DT_VC->Height) / 2;
L_DT_VC->Left             = 5;
E_DT_VC->Left             = L_DT_VC->Left + L_DT_VC->Width + 2;
S_C->Width                = 5;
S_C->Height               = P_C_SG->Height;
SG_IK_NU->Top             = 0;
SG_IK_NU->Left            = 0;
SG_IK_NU->Width           = P_C_SG->ClientWidth;
SG_IK_NU->Height          = E_DT_VC->Top - 5;
SG_IK_NU->ColCount        =  10;
SG_IK_NU->ColWidths[0]    =  25;
SG_IK_NU->ColWidths[1]    = 250;
SG_IK_NU->ColWidths[2]    = 20;
SG_IK_NU->ColWidths[3]    = 40;
SG_IK_NU->ColWidths[4]    = 35;
SG_IK_NU->ColWidths[5]    = 35;
SG_IK_NU->ColWidths[6]    = 35;
SG_IK_NU->ColWidths[7]    = 35;
SG_IK_NU->ColWidths[8]    = 35;
SG_IK_NU->ColWidths[9]    = 20;
SG_IK_NU->Cells[0][0]     = "№";
SG_IK_NU->Cells[1][0]     = "Название";
SG_IK_NU->Cells[2][0]     = "НУ";
SG_IK_NU->Cells[3][0]     = "DТ_S";
SG_IK_NU->Cells[4][0]     = "DТ1";
SG_IK_NU->Cells[5][0]     = "DТ2";
SG_IK_NU->Cells[6][0]     = "DТ3";
SG_IK_NU->Cells[7][0]     = "DТ4";
SG_IK_NU->Cells[8][0]     = "DТ5";
SG_IK_NU->Cells[9][0]     = "M";
SG_IK_NU->RowCount        = K_S + 1;
SG_IK_NU->SelectedColors->BGColor  = HEXToColor("b0ffff");
}; // void __fastcall TF_CKL::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::ME1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
/*1.*/  if (Key == VK_RETURN)
{
/*1.1.*/ if (T_COL == 2)
{
/*1.1.1.*/ if (StrToInt(ME1->Text) < 2)   SG_IK_NU->Cells[T_COL][T_ROW] = ME1->Text;
/*1.1.2.*/ else                           SG_IK_NU->Cells[T_COL][T_ROW] = "1";
}; // 1.1.
/*1.2.*/ if (T_COL == 3)  SG_IK_NU->Cells[T_COL][T_ROW] = FloatToStrF((StrToFloat(RCD(ME1->Text))), ffFixed, 5, 2);
/*1.3.*/ if (3 <  T_COL)  SG_IK_NU->Cells[T_COL][T_ROW] = FloatToStrF((StrToFloat(RCD(ME1->Text))), ffFixed, 4, 1);
/*1.4.*/ ME1->Hide();
}; // 1.
/*2.*/  if (Key == VK_ESCAPE)  ME1->Hide();
}; // void __fastcall TF_CKL::ME1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::SG_IK_NUClick(TObject *Sender)
{
/*1.*/ if ((SG_IK_NU->Col == 1) || (SG_IK_NU->Col == 1) || (SG_IK_NU->Col == 9))  ME1->Hide();
/*2.*/ if ((1 < SG_IK_NU->Col) && (SG_IK_NU->Col < 9))
{
T_COL = SG_IK_NU->Col;
T_ROW = SG_IK_NU->Row;
SEND_ME(SG_IK_NU->Cells[T_COL][T_ROW], ME1);
}; // 2.
/*3.*/ if (SG_IK_NU->Col == 9)
{
/*3.1.*/ if (SG_IK_NU->Cells[SG_IK_NU->Col][SG_IK_NU->Row] == "V")  SG_IK_NU->Cells[SG_IK_NU->Col][SG_IK_NU->Row] = "";
/*3.2.*/ else                                                       SG_IK_NU->Cells[SG_IK_NU->Col][SG_IK_NU->Row] = "V";
}; // 3.
}; // void __fastcall TF_CKL::SG_IK_NUClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::SG_IK_NUDblClick(TObject *Sender)
{
/*1.*/ if (SG_IK_NU->Col == 1)
{
T_COL = SG_IK_NU->Col;
T_ROW = SG_IK_NU->Row;
P_G_C_IVS(); // Вторая колонка (Название  сигнала) - построение графиков циклограммы ИВС
}; // 1.
}; // void __fastcall TF_CKL::SG_IK_NUDblClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::FormDestroy(TObject *Sender)
{
NU_SAVE();
}; // void __fastcall TF_CKL::FormDestroy(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::FormResize(TObject *Sender)
{
P_C_SG->Height            = ClientHeight - 5;
E_DT_VC->Top              = P_C_SG->ClientHeight - E_DT_VC->Height - 20;
L_DT_VC->Top              = E_DT_VC->Top + (E_DT_VC->Height - L_DT_VC->Height) / 2;
L_DT_VC->Left             = 5;
E_DT_VC->Left             = L_DT_VC->Left + L_DT_VC->Width + 2;
SG_IK_NU->Width           = P_C_SG->ClientWidth;
SG_IK_NU->Height          = E_DT_VC->Top - 5;
SG_IK_REZ->Height         = E_DT_VC->Top + E_DT_VC->Height;
}; // void __fastcall TF_CKL::FormResize(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CKL::FormShow(TObject *Sender)
{
Sleep(50);
P_C_SG->SetFocus();
} // void __fastcall TF_CKL::FormShow(TObject *Sender)
//---------------------------------------------------------------------------

