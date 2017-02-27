#ifndef U_F_CH_IR_H
#define U_F_CH_IR_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <vector>
#include "Common_.h"
//---------------------------------------------------------------------------
class T_CHL_IR // Класс для отображения графиков сигналов ИВС (РПС): панель и метка
{
private:
UINT                 Number;    // Номер конкретного объекта
public:
TChart*              C_Chart;
TLabel*              C_Label;
//unique_ptr<TChart>    C_Chart;
//unique_ptr<TLabel>    C_Label;
static  UINT          Number_ST; // Счетчик номеров объектов
 T_CHL_IR();
~T_CHL_IR();
}; // class T_CHL_IR
//---------------------------------------------------------------------------
class TF_CH_IR : public TForm
{
__published:	// IDE-managed Components
TChart *CH11;
void __fastcall FormCreate(TObject *Sender);
void __fastcall FormDestroy(TObject *Sender);
void __fastcall FormShow(TObject *Sender);
void __fastcall MsDn(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
vector<T_CHL_IR*>  CHL_IR;
void __fastcall F_CH_IR_AFTERCREATE();
//---------------------------------------------------------------------------
__fastcall TF_CH_IR(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_CH_IR  *F_CH_IR;
UINT                      T_CHL_IR::Number_ST;
//---------------------------------------------------------------------------
#endif
