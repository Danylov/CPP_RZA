#include <vcl.h>
#include <System.SysUtils.hpp>
#pragma hdrstop
#include "U_NSTR_.h"
#include "Common_.h"
#include "StF_.h"
#include "U_CKL_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ZColorStringGrid"
#pragma link "AdvToolBtn"
#pragma resource "*.dfm"
TF_NSTR *F_NSTR;
//---------------------------------------------------------------------------
__fastcall TF_NSTR::TF_NSTR(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_NSTR::TF_NSTR(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::B_PLClick(TObject *Sender)
{
NSTR_B_PL_CL(CB_PL);
}; // void __fastcall TF_NSTR::B_PLClick(TObject *Sender)
//---------------------------------------------------------------------------
void  ZCSG_NSTR_Obnovl() // Обновление информации по выбору сигналов ИВС и РПС для отображения
{
/*1.*/ for (int ns = 0; ns < F_NSTR->ZCSG_NSTR->RowCount; ns++)
{
/*1.1.*/ for (int nc = 0; nc < F_NSTR->ZCSG_NSTR->ColCount; nc++)
{
/*1.1.1.*/ if ((ns == 0) || (nc == 0))               F_NSTR->ZCSG_NSTR->CellStyle[nc][ns]->Font->Style = TFontStyles() << fsBold;
/*1.1.2.*/ if ((ns == 0) || (nc == 0) || (nc == 3))  F_NSTR->ZCSG_NSTR->CellStyle[nc][ns]->HorizontalAlignment = taCenter;
/*1.1.2.*/ F_NSTR->ZCSG_NSTR->CellStyle[nc][ns]->Font->Color                                                   = clBlack;
F_NSTR->ZCSG_NSTR->CellStyle[nc][ns]->Font->Size                                                               = 12;
F_NSTR->ZCSG_NSTR->CellStyle[nc][ns]->VerticalAlignment                                                        = vaCenter;
}; // 1.1.
/*1.2.*/ if (0 < ns)
{
/*1.2.1.*/ if (fmod(double(ns), 2.0) < 1.0E-5)  F_NSTR->ZCSG_NSTR->CellStyle[2][ns]->BGColor = clWhite;
/*1.2.2.*/ else                                 F_NSTR->ZCSG_NSTR->CellStyle[2][ns]->BGColor = clInfoBk;
/*1.2.3.*/ F_NSTR->ZCSG_NSTR->Cells[0][ns]       = 32 * F_NSTR->CB_PL->ItemIndex + ns;
F_NSTR->ZCSG_NSTR->Cells[1][ns]                  = IVS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Text;
F_NSTR->ZCSG_NSTR->CellStyle[1][ns]->BGColor     = IVS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Color;
F_NSTR->ZCSG_NSTR->CellStyle[1][ns]->Font->Color = IVS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Font->Color;
F_NSTR->ZCSG_NSTR->Cells[2][ns]                  = RPS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Text;
F_NSTR->ZCSG_NSTR->CellStyle[2][ns]->BGColor     = RPS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Color;
F_NSTR->ZCSG_NSTR->CellStyle[2][ns]->Font->Color = RPS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->C_E_NS->Font->Color;
/*1.2.4.*/ if (IVS_TS[32 * F_NSTR->CB_PL->ItemIndex + ns - 1]->P_H == 0)  F_NSTR->ZCSG_NSTR->Cells[3][ns] = "";
/*1.2.5.*/ else                                                           F_NSTR->ZCSG_NSTR->Cells[3][ns] = "V";
}; // 1.2.
}; // 1.
}; // void  ZCSG_NSTR_Obnovl()
//---------------------------------------------------------------------------
void  MD_Col_3(const int& ACol_,const int&  ARow_, const UINT& P_D = 2) // Установка и снятие метки выбора сигнала для его отображения
{ // P_D: 0 - установка Cells в ""; 1 - установка Cells в "V"; 2 - инверсия Cells;
/*1.*/ AnsiString  TEMP = "";
/*2.*/ if ((P_D == 0) || (P_D == 2) && (F_NSTR->ZCSG_NSTR->Cells[ACol_][ARow_] == "V"))
{
TEMP = "";
DVC_TS[F_NSTR->CB_PL->ItemIndex]->P_H = DVC_TS[F_NSTR->CB_PL->ItemIndex]->P_H & ~(0x01 << (ARow_ - 1)); // сброс бита номер (ARow_ - 1) в 0.
} // 2.
/*3.*/ if ((P_D == 1) || (P_D == 2) && (F_NSTR->ZCSG_NSTR->Cells[ACol_][ARow_] == ""))
{
TEMP = "V";
DVC_TS[F_NSTR->CB_PL->ItemIndex]->P_H = DVC_TS[F_NSTR->CB_PL->ItemIndex]->P_H |  (0x01 << (ARow_ - 1)); // установка бита номер (ARow_ - 1) в 1.
}; // 3.
/*4.*/ F_NSTR->ZCSG_NSTR->Cells[ACol_][ARow_] = TEMP;
}; // void  MD_Col_3(const int& ACol_,const int&  ARow_, const UINT& P_D = 2)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::CB_PLChange(TObject *Sender)
{
/*1.*/ if (B_PL->Enabled == true)
{
/*1.1.*/ AnsiString TMP  = "Сохранить изменения названий сигналов для платы № " + IntToStr(CB_PL->Tag + 1) + "?";
int TMP_ = MessageDlg(TMP, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*1.2.*/ if (TMP_ == mrYes)  B_PL->Click();
}; // 1.
/*2.*/ ZCSG_NSTR_Obnovl();
CB_PL->Tag = CB_PL->ItemIndex;
}; // void __fastcall TF_NSTR::CB_PLChange(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::FormCreate(TObject *Sender)
{
/*1.*/ Top                     = 0;
	   Left                    = 0;
	   Width                   = Screen->Width;
	   Height                  = Screen->Height - 25;
	   PC_NSTR->Top            = 0;
	   PC_NSTR->Left           = 0;
	   PC_NSTR->Width          = ClientWidth;
	   PC_NSTR->Height         = ClientHeight;
	   L_PL->Top               = 5;
	   L_PL->Left              = 5;
	   CB_PL->Top              = L_PL->Top;
	   CB_PL->Left             = L_PL->Left + L_PL->Width;
	   CB_PL->Width            = 100;
	   B_PL->Top               = L_PL->Top;
	   B_PL->Left              = CB_PL->Left + CB_PL->Width +  5;
	   B_SH->Top               = L_PL->Top;
	   B_SH->Left              = B_PL->Left  + B_PL->Width  + 20;
	   B_F->Top                = L_PL->Top;
	   B_F->Left               = B_SH->Left  + B_SH->Width  + 20;
	   CB_PL->ItemIndex        = 0;
	   ZCSG_NSTR->Top          = L_PL->Top   + L_PL->Height + 15;
	   ZCSG_NSTR->Height       = PC_NSTR_2->ClientHeight - ZCSG_NSTR->Top;
	   ZCSG_NSTR->Left         =   0;
	   ZCSG_NSTR->Width        = PC_NSTR_2->ClientWidth;
	   ZCSG_NSTR->ColCount     =   4;
	   ZCSG_NSTR->RowCount     =  33;
	   ZCSG_NSTR->ColWidths[0] =  60;
	   ZCSG_NSTR->ColWidths[3] =  70;
	   ZCSG_NSTR->ColWidths[1] = int(double(ZCSG_NSTR->ClientWidth - ZCSG_NSTR->ColWidths[0] - ZCSG_NSTR->ColWidths[3] - 5) / 2.0);
	   ZCSG_NSTR->ColWidths[2] =  ZCSG_NSTR->ColWidths[1];
	   ZCSG_NSTR->Cells[0][0]  = "№ п/п";
	   ZCSG_NSTR->Cells[1][0]  = "Название  сигнала  ИВС";
	   ZCSG_NSTR->Cells[2][0]  = "Название  сигнала  ИПС";
	   ZCSG_NSTR->Cells[3][0]  = "Отобр.";
}; // void __fastcall TF_NSTR::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::B_SHClick(TObject *Sender)
{
/*1.*/ if ((ZCSG_NSTR->Col == 1) || (ZCSG_NSTR->Col == 2))
{
/*1.1.*/ if (CD->Execute())
{
/*1.1.1.*/ if (ZCSG_NSTR->Col == 1)
{
IVS_TS[32 * CB_PL->ItemIndex + ZCSG_NSTR->Row - 1]->C_E_NS->Color = CD->Color;
ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->BGColor     = CD->Color;
} // 1.1.1.
/*1.1.2.*/ else
{
RPS_TS[32 * CB_PL->ItemIndex + ZCSG_NSTR->Row - 1]->C_E_NS->Color = CD->Color;
ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->BGColor     = CD->Color;
}; // 1.1.2.
}; // 1.1.
/*1.2.*/ if (FD->Execute())
{
/*1.2.1.*/ if (ZCSG_NSTR->Col == 1)
{
IVS_TS[32 * CB_PL->ItemIndex + ZCSG_NSTR->Row - 1]->C_E_NS->Font->Assign(FD->Font);
ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->Font->Assign(FD->Font);
} // 1.2.1.
/*1.2.2.*/ else
{
RPS_TS[32 * CB_PL->ItemIndex + ZCSG_NSTR->Row - 1]->C_E_NS->Font->Assign(FD->Font);
ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->Font->Assign(FD->Font);
}; // 1.2.2.
}; // 1.2.
}; // 1.
ZCSG_NSTR->Repaint();
}; // void __fastcall TF_NSTR::B_SHClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::FDApply(TObject *Sender, HWND Wnd)
{
ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->Font->Assign(FD->Font);
ZCSG_NSTR->Repaint();
}; // void __fastcall TF_NSTR::FDApply(TObject *Sender, HWND Wnd)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ZCSG_NSTRDblClick(TObject *Sender)
{
System::WideChar  Key_ = VK_RETURN;
ZCSG_NSTRKeyPress(ZCSG_NSTR, Key_);
}; // void __fastcall TF_NSTR::ZCSG_NSTRDblClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::B_FClick(TObject *Sender)
{
/*1.*/ if  (B_F->Down == true)
{ // Отжатая -> нажатая кнопка
B_F->ColorHot    = B_F->ColorChecked;
B_F->ColorHotTo  = B_F->ColorChecked;
ZCSG_FC  = System::Uiconsts::ColorToString(ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->Font->Color);
ZCSG_BGC = System::Uiconsts::ColorToString(ZCSG_NSTR->CellStyle[ZCSG_NSTR->Col][ZCSG_NSTR->Row]->BGColor);
} // 1.
/*2.*/ else
{ // Нажатая -> отжатая кнопка
B_F->ColorHot    = B_F->Color;
B_F->ColorHotTo  = B_F->Color;
B_F->ColorDown   = B_F->Color;
B_F->ColorDownTo = B_F->Color;
}; // 2.
}; // void __fastcall TF_NSTR::B_FClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::B_OKClick(TObject *Sender)
{
U_DT_NC = StrToFloat(RCD(ME_NU_VC_2->Text));
U_DT_KC = StrToFloat(RCD(ME_NU_VC_3->Text));
}; // void __fastcall TF_NSTR::B_OKClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ME_NU_VC_2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
U_DT_NC = StrToFloat(RCD(ME_NU_VC_2->Text));
F_CKL->E_DT_VC->Text = "";
}; // void __fastcall TF_NSTR::ME_NU_VC_2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ME_NU_VC_3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
U_DT_KC = StrToFloat(RCD(ME_NU_VC_3->Text));
F_CKL->E_DT_VC->Text = "";
}; // void __fastcall TF_NSTR::ME_NU_VC_3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::FormDestroy(TObject *Sender)
{
NASTR_SAVE();
}; // void __fastcall TF_NSTR::FormDestroy(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::FormShow(TObject *Sender)
{
/*1.*/ if (Tag == 0)
{
/*1.1.*/ for (UINT i = 0; i < T_DVC::NumOfDevices; i++)
{
AnsiString  TEMP = "Плата № " + System::Sysutils::IntToStr(Int32(i + 1));
CB_PL->AddItem(TEMP, NULL);
} // 1.1.
/*1.2.*/ CB_PL->ItemIndex = 0;
Tag = 1;
}; // 1.
/*2.*/ ZCSG_NSTR_Obnovl();
}; // void __fastcall TF_NSTR::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::PC_NSTRChange(TObject *Sender)
{
/*1.*/ if (PC_NSTR->ActivePageIndex == 1)  ZCSG_NSTR_Obnovl();
}; // void __fastcall TF_NSTR::PC_NSTRChange(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ZCSG_NSTRMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
int  ACol, ARow;
/*1.*/ ZCSG_NSTR->MouseToCell(X, Y, ACol, ARow);
ZCSG_NSTR->CellStyle[T_COL_NSTR][T_ROW_NSTR]->BorderCellStyle = Zcolorstringgrid::sgNone;
ZCSG_NSTR->CellStyle[ACol][ARow]->BorderCellStyle             = sgRaised;
T_COL_NSTR = ACol;
T_ROW_NSTR = ARow;
/*2.*/ if (B_F->Down == true) // Кнопка  нажата
{
/*2.1.*/  if (ACol == 1)
{
ZCSG_NSTR->CellStyle[ACol][ARow]->Font->Color = System::Uiconsts::StringToColor(ZCSG_FC.w_str());
IVS_TS[32 * CB_PL->ItemIndex + ARow - 1]->C_E_NS->Font->Assign(ZCSG_NSTR->CellStyle[ACol][ARow]->Font);
ZCSG_NSTR->CellStyle[ACol][ARow]->BGColor     = System::Uiconsts::StringToColor(ZCSG_BGC.w_str());
IVS_TS[32 * CB_PL->ItemIndex + ARow - 1]->C_E_NS->Color = ZCSG_NSTR->CellStyle[ACol][ARow]->BGColor;
}; // 2.1.
/*2.2.*/  if (ACol == 2)
{
ZCSG_NSTR->CellStyle[ACol][ARow]->Font->Color = System::Uiconsts::StringToColor(ZCSG_FC.w_str());
RPS_TS[32 * CB_PL->ItemIndex + ARow - 1]->C_E_NS->Font->Assign(ZCSG_NSTR->CellStyle[ACol][ARow]->Font);
ZCSG_NSTR->CellStyle[ACol][ARow]->BGColor     = System::Uiconsts::StringToColor(ZCSG_BGC.w_str());
RPS_TS[32 * CB_PL->ItemIndex + ARow - 1]->C_E_NS->Color = ZCSG_NSTR->CellStyle[ACol][ARow]->BGColor;
}; // 2.2.
}; // 2.
/*3.*/ if (ACol == 3)
{
/*3.1.*/ if (ARow == 0)
{
/*3.1.1.*/ UINT P_O = 0;
/*3.1.2.*/ for (UINT i = 0; i < 32; i++)
{
/*3.1.2.1.*/ if (F_NSTR->ZCSG_NSTR->Cells[(ZCSG_NSTR->ColCount - 1)][i] == "V")
{
P_O = 1;
break;
}; // 3.1.2.1.
}; // 3.1.2.
/*3.1.3.*/ for (UINT i = 0; i < 32; i++)
{
/*3.1.3.1.*/ if (P_O == 1)  MD_Col_3((ZCSG_NSTR->ColCount - 1), i+1, 0);
/*3.1.3.2.*/ else           MD_Col_3((ZCSG_NSTR->ColCount - 1), i+1, 1);
}; // 3.1.3.
} // 3.1.
/*3.2.*/ else  MD_Col_3(ACol, ARow);
}; // 3.
/*4.*/ T_DVC::VIS_DVC(); // Визуализация панелей плат
}; // void __fastcall TF_NSTR::ZCSG_NSTRMouseDown(...)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::FormClose(TObject *Sender, TCloseAction &Action)
{
/*1.*/ if (B_PL->Enabled == true)  CB_PLChange(CB_PL);
}; // void __fastcall TF_NSTR::FormClose(TObject *Sender, TCloseAction &Action)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ZCSG_NSTRKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
/*1.*/ UINT T_Col = ZCSG_NSTR->Col, T_Row = ZCSG_NSTR->Row;
ZCSG_NSTR->CellStyle[T_Col][T_Row]->BorderCellStyle = Zcolorstringgrid::sgNone;
/*2.*/ if ((Key == VK_UP)    && (1 < T_Row))                         T_Row--;
/*3.*/ if ((Key == VK_DOWN)  && (T_Row < (ZCSG_NSTR->RowCount - 1))) T_Row++;
/*4.*/ if ((Key == VK_LEFT)  && (1 < T_Col))                         T_Col--;
/*5.*/ if ((Key == VK_RIGHT) && (T_Col < (ZCSG_NSTR->ColCount - 1))) T_Col++;
/*6.*/ ZCSG_NSTR->CellStyle[T_Col][T_Row]->BorderCellStyle = sgRaised;
/*7.*/ if ((Key == VK_RETURN) && (T_Col < (ZCSG_NSTR->ColCount - 1)))  ZCSG_NSTR->Options = ZCSG_NSTR->Options >> goEditing; // goEditing в роли признака, что не в режиме редактирования
/*8.*/ T_COL_NSTR = T_Col; T_ROW_NSTR = T_Row;
}; // void __fastcall TF_NSTR::ZCSG_NSTRKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
//---------------------------------------------------------------------------
void __fastcall TF_NSTR::ZCSG_NSTRKeyPress(TObject *Sender, System::WideChar &Key)
{
/*1.*/ if (Key == VK_RETURN)
{
/*1.1.*/ UINT T_Col = ZCSG_NSTR->Col, T_Row = ZCSG_NSTR->Row;
/*1.2.*/ if (T_Col < (ZCSG_NSTR->ColCount - 1))  // Реакция на Enter не в режиме редактирования
{
/*1.2.1.*/ if (!ZCSG_NSTR->Options.Contains(goEditing))
{
ZCSG_NSTR->Options = ZCSG_NSTR->Options << goEditing;
B_PL->Enabled = true;
} // 1.2.1.
/*1.2.2.*/ else
{
ZCSG_NSTR->Options = ZCSG_NSTR->Options >> goEditing;
B_PL->Click();
} // 1.2.2.
} // 1.2.
/*1.3.*/ else
{
ZCSG_NSTR->Options = ZCSG_NSTR->Options >> goEditing;
MD_Col_3(T_Col, T_Row);
T_DVC::VIS_DVC();
}; // 1.3.
}; // 1.
}; // void __fastcall TF_NSTR::ZCSG_NSTRKeyPress(TObject *Sender, System::WideChar &Key)
//---------------------------------------------------------------------------

