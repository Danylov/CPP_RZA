#include <vcl.h>
#pragma hdrstop
#include "U_F_CH_NSTR_.h"
#include "Common_.h"
#include "IVS_RPS_.h"
#include "U_F_CH_IR_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "NxColumns6"
#pragma link "NxControls6"
#pragma link "NxCustomGrid6"
#pragma link "NxGrid6"
#pragma link "NxGridView6"
#pragma link "NxVirtualGrid6"
#pragma resource "*.dfm"
TF_CH_NSTR *F_CH_NSTR;
//---------------------------------------------------------------------------
__fastcall TF_CH_NSTR::TF_CH_NSTR(TComponent* Owner) : TForm(Owner)
{
} // __fastcall TF_CH_NSTR::TF_CH_NSTR(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void  B_PL_GR(const UINT&  T_F) // T_F: 0 - (B_PL=true; B_GR=false); 1 - (B_PL=false; B_GR=true);
{
/*1.*/ switch(T_F)
{
case  0:  F_CH_NSTR->B_PL->Enabled = true;   F_CH_NSTR->B_GR->Enabled = false;  break;
case  1:  F_CH_NSTR->B_PL->Enabled = false;  F_CH_NSTR->B_GR->Enabled = true;   break;
} // 1.
} // void  B_PL_GR(const UINT&  T_F)
//---------------------------------------------------------------------------
void  NGr_Obnovl() // Обновление информации по настройке  графиков сигналов ИВС и РПС (для новой платы)
{
/*1.*/ for (int ns = 0; ns < F_CH_NSTR->NGr_IVS->RowCount; ns++)
{
// Сигналы ИВС
F_CH_NSTR->NGr_IVS->Cell[0][ns]->SetAsBoolean(IVS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.SLCTN);
F_CH_NSTR->NGr_IVS->Cell[1][ns]->SetAsInteger(32 * F_CH_NSTR->CB_PL->ItemIndex + ns + 1);
F_CH_NSTR->NGr_IVS->Cell[2][ns]->SetAsString(IVS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->C_E_NS->Text);
F_CH_NSTR->NGr_IVS->Cell[2][ns]->SetColor(IVS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->C_E_NS->Color);
F_CH_NSTR->NGr_IVS->Cell[3][ns]->SetAsString(GRtoS(IVS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.GR));
F_CH_NSTR->NGr_IVS->Cell[4][ns]->SetColor(IVS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.CLR);
// Сигналы РПС
F_CH_NSTR->NGr_RPS->Cell[0][ns]->SetAsBoolean(RPS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.SLCTN);
F_CH_NSTR->NGr_RPS->Cell[1][ns]->SetAsInteger(32 * F_CH_NSTR->CB_PL->ItemIndex + ns + 1);
F_CH_NSTR->NGr_RPS->Cell[2][ns]->SetAsString(RPS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->C_E_NS->Text);
F_CH_NSTR->NGr_RPS->Cell[2][ns]->SetColor(RPS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->C_E_NS->Color);
F_CH_NSTR->NGr_RPS->Cell[3][ns]->SetAsString(GRtoS(RPS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.GR));
F_CH_NSTR->NGr_RPS->Cell[4][ns]->SetColor(RPS_TS[32 * F_CH_NSTR->CB_PL->ItemIndex + ns]->S_C_GR.CLR);
}; // 1.
}; // void  NGr_Obnovl()
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::FormCreate(TObject *Sender)
{
/*1.*/ Top                         = 0;
Width                              = Screen->Width;
Left                               = 0;
Height                             = Screen->Height - 27;
// Отображение выпадающего списка для выбора платы, кнопки сохранения изменений
L_PL->Top                          = 7;
L_PL->Left                         = 5;
CB_PL->Top                         = L_PL->Top   -                 2;
CB_PL->Left                        = L_PL->Left  +  L_PL->Width +  5;
CB_PL->Width                       = 100;
CB_PL->ItemIndex                   = 0;
B_PL->Top                          = CB_PL->Top;
B_PL->Left                         = CB_PL->Left + CB_PL->Width +  5;
B_GR->Top                          = B_PL->Top;
B_GR->Left                         = B_PL->Left  + B_PL->Width  +  5;
// Отображение таблицы настройки отображения графиков ИВС
NGr_IVS->Top                       = L_PL->Top  + L_PL->Height   + 15;
NGr_IVS->Height                    = ClientHeight - NGr_IVS->Top -  5;
NGr_IVS->Left                      =   0;
NGr_IVS->Width                     = ClientWidth / 2 - 5;
NGr_IVS->RowCount                  =  32;
NGr_IVS->Font->Size                =  12;
NGr_IVS->ActiveView->HeaderHeight  =  30;
NGr_IVS->Columns->Item[0]->Width   =  20;
NGr_IVS->Columns->Item[1]->Width   =  30;
NGr_IVS->Columns->Item[2]->Width   = 395;
NGr_IVS->Columns->Item[3]->Width   =  85;
NGr_IVS->Columns->Item[4]->Width   =  70;
unique_ptr<TStringList> SL = unique_ptr<TStringList>(new TStringList);
SL->Add("Hide");
SL->Add("11"); SL->Add("12");
SL->Add("21"); SL->Add("22");
SL->Add("31"); SL->Add("32");
/*2.*/ for (UINT i = 0; i < SL->Count; i++)
{
((TNxComboBoxColumn6*)(NGr_IVS->Columns->Item[3]))->Items->Add(SL->Strings[i]);
((TNxComboBoxColumn6*)(NGr_RPS->Columns->Item[3]))->Items->Add(SL->Strings[i]);
}; // 2.
/*3.*/ SL.reset();
/*4.*/ for (int i = 0; i < NGr_IVS->RowCount; i++)
{
/*4.1.*/ for (int j = 0; j < NGr_IVS->ColCount; j++)
{
/*4.1.1.*/ if (j < (NGr_IVS->ColCount - 1))
{
/*4.1.1.1.*/ if (i % 2 == 0) NGr_IVS->Cell[j][i]->SetColor(clWhite);
/*4.1.1.2.*/ else            NGr_IVS->Cell[j][i]->SetColor(clMoneyGreen);
}
/*4.1.2.*/ else  NGr_IVS->Cell[NGr_IVS->ColCount - 1][i]->SetColor(clBlack);
/*4.1.3.*/ NGr_IVS->Columns->Item[j]->Header->Font->Size = 12;
} // 4.1.
/*4.2.*/ NGr_IVS->Row[i]->Height = 25;
NGr_IVS->Cell[1][i]->SetAsInteger(i + 1);
// Попробовать не установить текст, а выбрать первый элемент выпадающего списка
//WideString  WS = WideString(((TNxComboBoxColumn6*)(NGr_IVS->Columns->Item[3]))->Items->Strings[1]);
//NGr_IVS->Cell[3][1]->SetAsString(WS);
//((TNxComboBox6*)(NGr_IVS->Columns->Item[3]))->ItemIndex = 2;
//((TNxComboBox6*)(NGr_IVS->Cell[3][2]))->ItemIndex = 0;
((TNxComboBoxColumn6*)(NGr_IVS->Columns->Item[3]))->DefaultValue = ((TNxComboBoxColumn6*)(NGr_IVS->Columns->Item[3]))->Items->Strings[0];
} // 4.
// Отображение таблицы настройки отображения графиков РПС
/*5.*/ NGr_RPS->Top     = NGr_IVS->Top;
NGr_RPS->Height         = NGr_IVS->Height;
NGr_RPS->Left           = NGr_IVS->Width + 10;
NGr_RPS->Width          = NGr_IVS->Width;
NGr_RPS->RowCount                  =  32;
NGr_RPS->Font->Size                =  12;
NGr_RPS->ActiveView->HeaderHeight  =  30;
NGr_RPS->Columns->Item[0]->Width   =  20;
NGr_RPS->Columns->Item[1]->Width   =  30;
NGr_RPS->Columns->Item[2]->Width   = 395;
NGr_RPS->Columns->Item[3]->Width   =  85;
NGr_RPS->Columns->Item[4]->Width   =  70;
/*6.*/ for (int i = 0; i < NGr_RPS->RowCount; i++)
{
/*6.1.*/ for (int j = 0; j < NGr_RPS->ColCount; j++)
{
/*6.1.1.*/ if (j < (NGr_RPS->ColCount - 1))
{
/*6.1.1.1.*/ if (i % 2 == 0) NGr_RPS->Cell[j][i]->SetColor(clWhite);
/*6.1.1.2.*/ else            NGr_RPS->Cell[j][i]->SetColor(clMoneyGreen);
}
/*6.1.2.*/ else  NGr_RPS->Cell[NGr_RPS->ColCount - 1][i]->SetColor(clBlack);
/*6.1.3.*/ NGr_RPS->Columns->Item[j]->Header->Font->Size = 12;
} // 6.1.
/*6.2.*/ NGr_RPS->Row[i]->Height = 25;
NGr_RPS->Cell[1][i]->SetAsInteger(i + 1);
//NGr_RPS->Cell[3][1]->SetAsString(((TNxComboBoxColumn6*)(NGr_RPS->Columns->Item[3]))->Items->Strings[0]);
} // 6.
//((TNxComboBoxColumn6*)(NGr_IVS->Columns->Item[3]))->EmptyCaption = "Не_визуализировать";
//((TNxComboBoxColumn6*)(NGr_RPS->Columns->Item[3]))->DefaultValue = "Не_визуализировать";
// Цвет выделенной ячейки NGr_IVS и NGr_RPS по умолчанию
/*7.*/ SC_Current = NGr_IVS->SelectionColor;
} // void __fastcall TF_CH_NSTR::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::FormShow(TObject *Sender)
{ // Инициализация компонентов на форме
/*1.*/ if (Tag == 0)
{
/*1.1.*/ for (UINT i = 0; i < T_DVC::NumOfDevices; i++)
{
AnsiString  TEMP = "Плата № " + System::Sysutils::IntToStr(Int32(i + 1));
CB_PL->AddItem(TEMP, NULL);
} // 1.1.
/*1.2.*/ CB_PL->ItemIndex = 0;
		 B_PL->Height     = CB_PL->Height;
// Считывание параметров отображения графиков ИВС и РПС
T_IVS::IVS_GR_LD();
T_RPS::RPS_GR_LD();
Tag = 1;
}; // 1.
/*2.*/ NGr_Obnovl(); // Задание параметров исходя из номера выбранной платы
} // void __fastcall TF_CH_NSTR::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::NGr_IVSCellClick(TObject *Sender, int ACol, int ARow, TMouseButton Button)
{
/*1.*/ TNextGrid6*  NG = ((TNextGrid6*)Sender);
/*2.*/ if (ACol == (NG->ColCount - 1))
{
/*2.1.*/ if  (CD->Execute())
{
NG->Cell[ACol][ARow]->SetColor(CD->Color);
NG->SelectionColor = CD->Color;
} // 2.1.
} // 2.
/*3.*/ else  NG->SelectionColor = SC_Current;
/*4.*/ if ((ACol == 0) || (ACol == 3) || (ACol == 4))  B_PL_GR(0);
} // void __fastcall TF_CH_NSTR::NGr_IVSCellClick(...)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::B_PLClick(TObject *Sender)
{ // Сохранить изменения для сигналов предыдущей платы
/*1.*/ for (int ns = 0; ns < F_CH_NSTR->NGr_IVS->RowCount; ns++)
{
// Сигналы ИВС
IVS_TS[32 * CB_PL->Tag + ns]->S_C_GR.SLCTN = F_CH_NSTR->NGr_IVS->Cell[0][ns]->IsSet();
IVS_TS[32 * CB_PL->Tag + ns]->S_C_GR.GR    = StoGR(F_CH_NSTR->NGr_IVS->Cell[3][ns]->GetAsString());
IVS_TS[32 * CB_PL->Tag + ns]->S_C_GR.CLR   = F_CH_NSTR->NGr_IVS->Cell[4][ns]->GetColor();
// Сигналы РПС
RPS_TS[32 * CB_PL->Tag + ns]->S_C_GR.SLCTN = F_CH_NSTR->NGr_RPS->Cell[0][ns]->IsSet();
RPS_TS[32 * CB_PL->Tag + ns]->S_C_GR.GR    = StoGR(F_CH_NSTR->NGr_RPS->Cell[3][ns]->GetAsString());
RPS_TS[32 * CB_PL->Tag + ns]->S_C_GR.CLR   = F_CH_NSTR->NGr_RPS->Cell[4][ns]->GetColor();
}; // 1.
/*2.*/ B_PL_GR(1);
} // void __fastcall TF_CH_NSTR::B_PLClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::CB_PLChange(TObject *Sender)
{
/*1.*/ if (B_PL->Enabled == true)
{
/*1.1.*/ AnsiString TMP  = "Сохранить изменения (номенклатура и цвет сигналов, графики их отображения) для платы № " + IntToStr(CB_PL->Tag + 1) + "?";
int TMP_ = MessageDlg(TMP, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*1.2.*/ if (TMP_ == mrYes)  B_PL->Click();
/*1.3.*/ else                B_PL_GR(1);
}; // 1.
/*2.*/ NGr_Obnovl(); // Задание параметров исходя из номера выбранной платы
CB_PL->Tag = CB_PL->ItemIndex;
} // void __fastcall TF_CH_NSTR::CB_PLChange(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::FormClose(TObject *Sender, TCloseAction &Action)
{
CB_PL->OnChange(CB_PL);
} // void __fastcall TF_CH_NSTR::FormClose(TObject *Sender, TCloseAction &Action)
//---------------------------------------------------------------------------
void __fastcall TF_CH_NSTR::B_GRClick(TObject *Sender)
{
/*1.*/ for (UINT  i = 0; i < K_S; i++)
{
IVS_TS[i]->ZAP_SRS();
RPS_TS[i]->ZAP_SRS();
}; // 1.
/*2.*/ F_CH_IR->Show();
} // void __fastcall TF_CH_NSTR::B_GRClick(TObject *Sender)
//---------------------------------------------------------------------------

