#include <vcl.h>
#pragma hdrstop
#include "U_F_CH_IR_.h"
#include "U_F_CH_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_CH_IR *F_CH_IR;
//---------------------------------------------------------------------------
T_CHL_IR::T_CHL_IR()
{
Number  = Number_ST;
Number_ST++;
C_Chart                                 = new TChart(F_CH_IR);
C_Chart->OnMouseDown                    = F_CH_IR->MsDn;
//C_Chart = unique_ptr<TChart>(new TChart(F_CH_IR));
C_Chart->Tag                            = Number;
C_Chart->Parent                         = F_CH_IR;
C_Chart->View3D                         = false;
C_Chart->Align                          = alNone;
C_Chart->Title->Font->Size              = 12;
C_Chart->Title->Font->Style             = TFontStyles() << fsBold;
C_Chart->Title->Text->Add("Панель " + IntToStr(int((Number + 2) / 2)) + IntToStr(int(Number % 2 + 1)));
C_Chart->Title->Visible                 = false;
C_Chart->Legend->Visible                = false;
C_Chart->LeftAxis->Automatic            = false;
C_Chart->LeftAxis->AutomaticMaximum     = false;
C_Chart->LeftAxis->AutomaticMinimum     = false;
C_Chart->BottomAxis->Automatic          = false;
C_Chart->BottomAxis->AutomaticMaximum   = false;
C_Chart->BottomAxis->AutomaticMinimum   = false;
C_Chart->LeftAxis->Minimum              = 0.0;
C_Chart->LeftAxis->Maximum              = 1.5;
C_Chart->LeftAxis->Increment            = 0.5;
C_Chart->BottomAxis->Minimum            = 0.0;
C_Chart->BottomAxis->LabelsMultiLine    = true;
C_Chart->BottomAxis->DateTimeFormat     = "hh:mm:ss"; // "dd/mm hh:mm:ss";
C_Chart->BottomAxis->Increment          = DateTimeStep[dtOneMillisecond];
C_Label                                 = new TLabel(C_Chart);
C_Label->Parent                         = C_Chart;
//C_Label = unique_ptr<TLabel>(new TLabel(C_Chart.get()));
}; // T_CHL_IR::T_CHL_IR()
//---------------------------------------------------------------------------
T_CHL_IR::~T_CHL_IR()
{
delete  C_Label;
delete  C_Chart;
//CHL_IR[i]->C_Label.reset();
//CHL_IR[i]->C_Chart.reset();
}; // T_CHL_IR::~T_CHL_IR()
//---------------------------------------------------------------------------
__fastcall TF_CH_IR::TF_CH_IR(TComponent* Owner) : TForm(Owner)
{
} // __fastcall TF_CH_IR::TF_CH_IR(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_CH_IR::FormCreate(TObject *Sender)
{
/*1.*/ Top    = 0;
	   Width  = Screen->Width;
	   Left   = 0;
	   Height = Screen->Height - 27;
} // void __fastcall TF_CH_IR::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_IR::FormDestroy(TObject *Sender)
{
/*1.*/ for (UINT i = 0; i < T_CHL_IR::Number_ST; i++)
{
delete  CHL_IR[i];
// CHL_IR[i].reset(); // deletes managed object
} // 1.
} // void __fastcall TF_CH_IR::FormDestroy(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_CH_IR::FormShow(TObject *Sender)
{
/*1.*/ for (UINT i = 0; i < T_CHL_IR::Number_ST; i++)
{
// Настройка минимума и максимума оси X
// Chart->Series[i]
// Chart->SeriesCount()
// Series1->XValues->MinValue
// Series1->XValues->MaxValue
TDateTime  MIN_X, MAX_X;
/*1.1.*/ for (UINT j = 0; j < CHL_IR[i]->C_Chart->SeriesCount(); j++)
{
/*1.1.1.*/ if (j == 0)
{
MAX_X = CHL_IR[i]->C_Chart->Series[j]->XValues->MaxValue;
MIN_X = CHL_IR[i]->C_Chart->Series[j]->XValues->MinValue;
}
/*1.1.2.*/ else
{
/*1.1.2.1.*/ if (CHL_IR[i]->C_Chart->Series[j]->XValues->MinValue < double(MIN_X))  MIN_X = CHL_IR[i]->C_Chart->Series[j]->XValues->MinValue;
/*1.1.2.2.*/ if (double(MAX_X) < CHL_IR[i]->C_Chart->Series[j]->XValues->MaxValue)  MAX_X = CHL_IR[i]->C_Chart->Series[j]->XValues->MaxValue;
}; // 1.1.2.
/*1.1.3.*/ CHL_IR[i]->C_Chart->BottomAxis->Maximum = MAX_X + TDateTime(1.005 * double(MAX_X - MIN_X));
		   CHL_IR[i]->C_Chart->BottomAxis->Minimum = MIN_X - TDateTime(1.005 * double(MAX_X - MIN_X));
           CHL_IR[i]->C_Chart->Show();
}; // 1.1.
}; // 1.
}  // void __fastcall TF_CH_IR::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall  TF_CH_IR::F_CH_IR_AFTERCREATE()
{
/*1.*/ for (UINT  i = 0; i < 6; i++)  CHL_IR.push_back(new T_CHL_IR());
// for (UINT  i = 0; i < 6; i++)  CHL_IR.push_back(unique_ptr<T_CHL_IR>(new T_CHL_IR()).get());
/*2.*/ int  CW2 = ClientWidth  / 2;
	   int  CH3 = ClientHeight / 3;
/*3.*/ for (UINT i = 0; i < T_CHL_IR::Number_ST; i++)
{
/*3.1.*/ CHL_IR[i]->C_Chart->Width  = CW2;
		 CHL_IR[i]->C_Chart->Height = CH3;
/*3.1.*/ switch(i)
{
case  0: CHL_IR[i]->C_Chart->Left = 0;   CHL_IR[i]->C_Chart->Top = 0;       break; // "11"
case  1: CHL_IR[i]->C_Chart->Left = CW2; CHL_IR[i]->C_Chart->Top = 0;       break; // "12"
case  2: CHL_IR[i]->C_Chart->Left = 0;   CHL_IR[i]->C_Chart->Top = CH3;     break; // "21"
case  3: CHL_IR[i]->C_Chart->Left = CW2; CHL_IR[i]->C_Chart->Top = CH3;     break; // "22"
case  4: CHL_IR[i]->C_Chart->Left = 0;   CHL_IR[i]->C_Chart->Top = 2 * CH3; break; // "31"
case  5: CHL_IR[i]->C_Chart->Left = CW2; CHL_IR[i]->C_Chart->Top = 2 * CH3; break; // "32"
}  // 3.1.
}  // 3.
}; // void __fastcall  TF_CH_IR::F_CH_IR_AFTERCREATE()
//---------------------------------------------------------------------------
void __fastcall TF_CH_IR::MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) // Событие для отображения координаты курсора
{
/*1.*/ TChart* CH = ((TChart*)Sender);
/*2.*/ if ((Shift.Contains(ssCtrl)) &&  Shift.Contains(ssLeft))
{
CHL_IR[CH->Tag]->C_Label->Left    = X + 10;
CHL_IR[CH->Tag]->C_Label->Top     = Y - 20;
double  tmpX, tmpY;
CHL_IR[CH->Tag]->C_Chart->Series[0]->GetCursorValues(tmpX, tmpY);
String  X_V = String(CHL_IR[CH->Tag]->C_Chart->Series[0]->GetHorizAxis->LabelValue(tmpX));
String  Y_V = String(CHL_IR[CH->Tag]->C_Chart->Series[0]->GetVertAxis->LabelValue(tmpY));
CHL_IR[CH->Tag]->C_Label->Caption = " T = " + X_V + "; " + "VALUE = " + Y_V + ".";
} // 2.
/*3.*/ else  CHL_IR[CH->Tag]->C_Label->Caption = "";
}; // void __fastcall TF_CH::MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
//---------------------------------------------------------------------------
