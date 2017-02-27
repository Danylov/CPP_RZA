#include <vcl.h>
#pragma hdrstop
#include "U_TVS_.h"
#include "U_Interf_.h"
#include "Common_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvToolBtn"
#pragma resource "*.dfm"
TF_TVS *F_TVS;
//---------------------------------------------------------------------------
__fastcall TF_TVS::TF_TVS(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_TVS::TF_TVS(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_TVS::FormCreate(TObject *Sender)
{
B_0_1->Top  = (ClientHeight -     B_0_1->Height) / 2;
B_0_1->Left = (ClientWidth  - 2 * B_0_1->Width)  / 3;
B_1_0->Top  = B_0_1->Top;
B_1_0->Left = 2 * B_0_1->Left + B_0_1->Width;
F_IK->IL_IVS->GetBitmap(0, B_0_1->Glyph);  // 0-1
F_IK->IL_IVS->GetBitmap(1, B_1_0->Glyph);  // 1-0
}; // void __fastcall TF_TVS::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_TVS::B_0_1Click(TObject *Sender)
{
IVS_TS[T_NIM]->T_S = 0; // 0-1
IVS_TS[T_NIM]->IN_IM();
F_TVS->Hide();
}; // void __fastcall TF_TVS::B_0_1Click(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_TVS::B_1_0Click(TObject *Sender)
{
IVS_TS[T_NIM]->T_S = 1; // 1-0
IVS_TS[T_NIM]->IN_IM();
F_TVS->Hide();
}; // void __fastcall TF_TVS::B_1_0Click(TObject *Sender)
//---------------------------------------------------------------------------
