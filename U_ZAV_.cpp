#include <vcl.h>
#pragma hdrstop
#include "U_ZAV_.h"
#include "Common_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_ZAV *F_ZAV;
//---------------------------------------------------------------------------
__fastcall TF_ZAV::TF_ZAV(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_ZAV::TF_ZAV(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_ZAV::SG_ZAVKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
if (!((isdigit(Key)) || (Key == VK_BACK) || (Key == VK_DELETE)))  Key = 0;
}; // void __fastcall TF_ZAV::SG_ZAVKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
//---------------------------------------------------------------------------
void __fastcall TF_ZAV::FormShow(TObject *Sender)
{
/*1.*/ for (unsigned int i = 0; i < T_DVC::NumOfDevices; i++)
{
/*1.1.*/ for (UINT ns = 1; ns < ZAV_TS[i]->RowCount; ns++) // № строки в таблице
{
/*1.1.1.*/ unsigned int npp = 32 * i + ns - 1;            // № сигнала ИВС, РПС (0 - ...)
ZAV_TS[i]->Cells[0][ns] = npp + 1;
/*1.1.2.*/ if (RPS_TS[npp]->C_IVS == NULL)  ZAV_TS[i]->Cells[1][ns] = "0";
/*1.1.3.*/ else                             ZAV_TS[i]->Cells[1][ns] = UIntToStr(RPS_TS[npp]->C_IVS->Tag + 1);
}; // 1.1.
}; // 1.
}; // void __fastcall TF_ZAV::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_ZAV::B_CClick(TObject *Sender)
{
F_ZAV->Hide();
F_IK->Show();
}; // void __fastcall TF_ZAV::B_CClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_ZAV::B_OKClick(TObject *Sender)
{
/*1.*/ for (unsigned int i = 0; i < T_DVC::NumOfDevices; i++)
{
/*1.1.*/ for (int ns = 1; ns < ZAV_TS[i]->RowCount; ns++) // № строки в таблице
{
/*1.1.1.*/ unsigned int npp = 32 * i + ns - 1;            // № сигнала ИВС, РПС (0 - ...)
/*1.1.2.*/ if (StrToInt(ZAV_TS[i]->Cells[1][ns]) != 0)  RPS_TS[npp]->C_IVS = IVS_TS[(StrToInt(ZAV_TS[i]->Cells[1][ns]) - 1)];
/*1.1.3.*/ else                                         RPS_TS[npp]->C_IVS = NULL;
}; // 1.1.
}; // 1.
/*2.*/ F_ZAV->Hide();
F_IK->Show();
}; // void __fastcall TF_ZAV::B_OKClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall  TF_ZAV::F_ZAV_AFTERCREATE()
{
/*1.*/ ZAV_TS = new TZColorStringGrid*[T_DVC::NumOfDevices];
/*2.*/ for (unsigned int i = 0; i < T_DVC::NumOfDevices; i++)
{
/*2.1.*/ ZAV_TS[i]       = new TZColorStringGrid(F_ZAV);
ZAV_TS[i]->Options       = ZAV_TS[i]->Options << goEditing;
ZAV_TS[i]->Parent        = F_ZAV;
ZAV_TS[i]->RowCount      = 33;
ZAV_TS[i]->ColCount      =  2;
ZAV_TS[i]->ColWidths[0]  = 60;
ZAV_TS[i]->ColWidths[1]  = 70;
ZAV_TS[i]->Cells[0][0]   = "№  ИПС";
ZAV_TS[i]->Cells[1][0]   = "№  ИВС";
/*2.2.*/ for (int ns = 0; ns < ZAV_TS[i]->RowCount; ns++)
{
/*2.2.1.*/ ZAV_TS[i]->CellStyle[0][ns]->HorizontalAlignment = taCenter;
		   ZAV_TS[i]->CellStyle[0][ns]->Font->Size          = 10;
		   ZAV_TS[i]->CellStyle[0][ns]->Font->Color         = clBlack;
		   ZAV_TS[i]->CellStyle[0][ns]->Font->Style         = TFontStyles() << fsBold;
		   ZAV_TS[i]->CellStyle[1][ns]->HorizontalAlignment = taCenter;
		   ZAV_TS[i]->CellStyle[1][ns]->Font->Size          = 10;
		   ZAV_TS[i]->CellStyle[1][ns]->Font->Color         = clBlack;
/*2.2.2.*/ if (ns != 0)
{
/*2.2.2.1.*/ if (fmod(double(ns), 2.0) < 1.0E-5)  ZAV_TS[i]->CellStyle[1][ns]->BGColor = clWhite;
/*2.2.2.2.*/ else                                ZAV_TS[i]->CellStyle[1][ns]->BGColor = clInfoBk;
}; // 2.2.2.
}; // 2.2.
/*2.3.*/ ZAV_TS[i]->Top  = 0;
ZAV_TS[i]->Height        = 33 * ZAV_TS[i]->RowHeights[0] + 50;
ZAV_TS[i]->Width         = ZAV_TS[i]->ColWidths[0] + ZAV_TS[i]->ColWidths[1] + 20;
ZAV_TS[i]->Left          = 10 + i * (ZAV_TS[i]->Width + 10);
}; // 2.
/*3.*/ F_ZAV->B_OK->Left = 5;
F_ZAV->B_OK->Top         = ZAV_TS[0]->Height + 5;
F_ZAV->B_C->Left         = F_ZAV->B_OK->Left + F_ZAV->B_OK->Width + 5;
F_ZAV->B_C->Top          = F_ZAV->B_OK->Top;
F_ZAV->Top               = int(float(Screen->Height - F_ZAV->Height) / 2.0);
F_ZAV->ClientWidth       = T_DVC::NumOfDevices * ZAV_TS[0]->Width + (T_DVC::NumOfDevices + 1) * 10;
F_ZAV->ClientHeight      = F_ZAV->B_OK->Top + F_ZAV->B_OK->Height + 5;
F_ZAV->Left              = int(float(Screen->Width - F_ZAV->Width) / 2.0);
}; // __fastcall  void  TF_ZAV::F_ZAV_AFTERCREATE()
//---------------------------------------------------------------------------
