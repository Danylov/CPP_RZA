#include <vcl.h>
#pragma hdrstop
#include "U_F_CH_.h"
#include "IVS_RPS_.h"
#include "Common_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TF_CH *F_CH;
//---------------------------------------------------------------------------
__fastcall TF_CH::TF_CH(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_CH::TF_CH(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_CH::FormCloseQuery(TObject *Sender, bool &CanClose)
{
/*1.*/ for (int npp = 0; npp < K_CH; npp++)
{
/*1.1.*/ while (T_CH_L_TS[npp]->C_Chart->SeriesCount() != 0)
{
TChartSeries*  C_CS = T_CH_L_TS[npp]->C_Chart->Series[T_CH_L_TS[npp]->C_Chart->SeriesCount() - 1];
T_CH_L_TS[npp]->C_Chart->RemoveSeries(C_CS);
delete  C_CS;
}; // 1.1.
/*1.2.*/ delete  T_CH_L_TS[npp]->C_Label;
		 delete  T_CH_L_TS[npp]->C_Chart;
		 delete  T_CH_L_TS[npp];
}; // 1.
/*2.*/ delete[] T_CH_L_TS;
}; // void __fastcall TF_CH::FormCloseQuery(TObject *Sender, bool &CanClose)
//---------------------------------------------------------------------------
void __fastcall TF_CH::N_EXClick(TObject *Sender)
{
F_CH->Close();
}; // void __fastcall TF_CH::N_EXClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH::FormCreate(TObject *Sender)
{
Top    = 0;
Height = Screen->Height - 25;
Left   = 0;
Width  = Screen->Width;
}; // void __fastcall TF_CH::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH::MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) // Событие для отображения координаты курсора
{ // Поменял T_CH_L_TS[CH->Tag] на CH
/*1.*/ TChart* CH = ((TChart*)Sender);
/*2.*/ if ((Shift.Contains(ssCtrl)) &&  Shift.Contains(ssLeft))
{
T_CH_L_TS[CH->Tag]->C_Label->Left    = X + 10;
T_CH_L_TS[CH->Tag]->C_Label->Top     = Y - 20;
double  tmpX, tmpY;
T_CH_L_TS[CH->Tag]->C_Chart->Series[0]->GetCursorValues(tmpX, tmpY);
String  X_V = String(T_CH_L_TS[CH->Tag]->C_Chart->Series[0]->GetHorizAxis->LabelValue(tmpX));
String  Y_V = String(T_CH_L_TS[CH->Tag]->C_Chart->Series[0]->GetVertAxis->LabelValue(tmpY));
T_CH_L_TS[CH->Tag]->C_Label->Caption = " T = " + X_V + "; VALUE = " + Y_V + ".";
} // 2.
/*3.*/ else  T_CH_L_TS[CH->Tag]->C_Label->Caption = "";
}; // void __fastcall TF_CH::MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
//---------------------------------------------------------------------------
void __fastcall TF_CH::FormDestroy(TObject *Sender)
{
T_IVS::IVS_NV.clear();
T_RPS::RPS_NV.clear();
} // void __fastcall TF_CH::FormDestroy(TObject *Sender)
//---------------------------------------------------------------------------

