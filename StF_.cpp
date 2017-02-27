#include <time.h>
#include <locale.h>
#include <dir.h>
#include <memory>
#pragma hdrstop
#include "StF_.h"
#include "U_F_CH_.h"
#include "U_NSTR_.h"
#include "U_CKL_.h"
#include "Common_.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int E(const float& x)
{
int   x_;
if (0 <= x) x_ = int(floor(x));
else        x_ = int(floor(x + 1));
return x_;
}; // float E(const float& x)
//---------------------------------------------------------------------------
double  SSTM()
{
double      SSTM_;
time_t      TT;
SYSTEMTIME  SSTM;
TT    = time(NULL);
GetSystemTime(&SSTM);
SSTM_ = TT + 0.001 * SSTM.wMilliseconds;
return  SSTM_;
}; // double  SSTM()
//---------------------------------------------------------------------------
void __fastcall FROMINI(const AnsiString&  P_INI_)
{ // Считывание строк из файла
/*1.*/ unique_ptr<TStringList> List = unique_ptr<TStringList>(new TStringList);
	   List->LoadFromFile(P_INI_);
       List->Text = StringReplace(List->Text, '\t', ' ',  TReplaceFlags() << rfReplaceAll);
	   VR_P.Length = 1;
/*2.*/ for (int kz = 0; kz < List->Count; kz++)
{
/*2.1.*/ unsigned int  P_ERR = 0;
/*2.2.*/ if (Trim(List->Strings[kz]).Length() == 0)  P_ERR = 1;
/*2.3.*/ else
{ // "Цепляем" два пустых символа в начале строки и два в конце
/*2.3.1.*/ List->Strings[kz]   = "  " + List->Strings[kz] + "  ";
AnsiString   STR_VR            = "";  // Накопление символов для тек. имени тэга
AnsiString   CH_X              = " "; // Предыдущий символ
VR_P[(VR_P.Length - 1)].Length = 0;
/*2.3.2.*/ for (int ks = 1; (ks < (List->Strings[kz].Length())); ks++)
{
/*2.3.2.1.*/ if ((VR_P[VR_P.Length - 1].Length == 0) && (!isdigit(List->Strings[kz][ks]))
&& (List->Strings[kz][ks] != '.') && (List->Strings[kz][ks] != ',') && (List->Strings[kz][ks]) != ' ')
{
P_ERR = 1;
break;
}; // 2.3.2.1.
// Переход с пробела на символ
/*2.3.2.2.*/ if ((CH_X == " ") && ((List->Strings[kz][ks]) != ' '))  STR_VR = (List->Strings[kz][ks]);
// При двух символах, отличных от пробела
/*2.3.2.3.*/ if ((CH_X != " ") && ((List->Strings[kz][ks]) != ' '))  STR_VR = STR_VR + (List->Strings[kz][ks]);
// Переход с символа на пробел
/*2.3.2.4.*/ if ((CH_X != " ") && ((List->Strings[kz][ks]) == ' '))
{
VR_P[VR_P.Length - 1].Length++;
VR_P[VR_P.Length - 1][VR_P[VR_P.Length - 1].Length - 1] = STR_VR;
STR_VR                                                  = "";
}; // 2.3.2.4.
/*2.3.2.5.*/ CH_X = (List->Strings[kz][ks]); // Предыдущий символ
}; // 2.3.2.
}; // 2.3.
/*2.4.*/ if (P_ERR == 0)  VR_P.Length++;
}; // 2.
/*3.*/ if (VR_P[VR_P.Length - 1].Length == 0)  VR_P.Length--;
List.reset();
}; // void __fastcall FROMINI(const AnsiString&  P_INI_)
//---------------------------------------------------------------------------
// Стандартная функция установки разделителя целой и дробной частей
AnsiString  RCD(const AnsiString&  S)
{
AnsiString T_STR = Trim(S);
/*1.*/ for (int ks = 1; (ks < (T_STR.Length() + 1)); ks++) // Символы в строке
{
/*1.1.*/ if ((SEP == ',') && (T_STR[ks] == '.'))  T_STR[ks] = ',';
/*1.2.*/ if ((SEP == '.') && (T_STR[ks] == ','))  T_STR[ks] = '.';
}; // 1.
return  T_STR;
}; // AnsiString  RCD(const AnsiString&  S)
//---------------------------------------------------------------------------
void __fastcall NU_LD()
{
/*1.*/ P_NU = AnsiString(PATH_) + "\\NU_CKL.ini";
/*2.*/ if ((F_NU = fopen(P_NU.c_str(), "rt")) != NULL)
{
/*2.1.*/ FROMINI(P_NU);
/*2.3.*/ for (int ns = 1; ns <= K_S; ns++)
{
/*2.3.1.*/ if (VR_P.Length != K_S)
{
MessageDlg("Количество строк со значениями параметров в файле NU_CKL.ini не соответствует количеству сигналов", mtWarning, TMsgDlgButtons() << mbOK, 0);
break;
}; // 2.3.1.
/*2.3.2.*/ for (int nc = 2; nc < (F_CKL->SG_IK_NU->ColCount - 1); nc++)    F_CKL->SG_IK_NU->Cells[nc][ns] = RCD(VR_P[(ns-1)][(nc-2)]);
}; // 2.3.
/*2.4.*/ fclose(F_NU);
}; // 2.
}; // void __fastcall NU_LD()
//---------------------------------------------------------------------------
void __fastcall NU_SAVE()
{
/*1.*/ if ((F_NU = fopen(P_NU.c_str(), "w+")) != NULL)
{
AnsiString  NU__, DT__;
int         NU_;
float       DT_S_, DT1_, DT2_, DT3_, DT4_, DT5_;
/*1.1.*/ for (int ns = 1; (ns < F_CKL->SG_IK_NU->RowCount); ns++)
{
/*1.1.1.*/  NU__ = Trim(F_CKL->SG_IK_NU->Cells[2][ns]);
/*1.1.2.*/  if (NU__ == "")   NU_  = 0;
/*1.1.3.*/  else        	  NU_  = StrToInt(NU__);
/*1.1.4.*/  DT__ = Trim(F_CKL->SG_IK_NU->Cells[3][ns]);
/*1.1.5.*/  if (DT__ == "")   DT_S_  = 0.0;
/*1.1.6.*/  else        	  DT_S_  = StrToFloat(RCD(DT__));
/*1.1.7.*/  DT__ = Trim(F_CKL->SG_IK_NU->Cells[4][ns]);
/*1.1.8.*/  if (DT__ == "")   DT1_  = 0.0;
/*1.1.9.*/  else              DT1_  = StrToFloat(RCD(DT__));
/*1.1.10.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[5][ns]);
/*1.1.11.*/ if (DT__ == "")   DT2_  = 0.0;
/*1.1.12.*/ else        	  DT2_  = StrToFloat(RCD(DT__));
/*1.1.13.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[6][ns]);
/*1.1.14.*/ if (DT__ == "")   DT3_  = 0.0;
/*1.1.15.*/ else        	  DT3_  = StrToFloat(RCD(DT__));
/*1.1.16.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[7][ns]);
/*1.1.17.*/ if (DT__ == "")   DT4_  = 0.0;
/*1.1.18.*/ else        	  DT4_  = StrToFloat(RCD(DT__));
/*1.1.19.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[8][ns]);
/*1.1.20.*/ if (DT__ == "")   DT5_  = 0.0;
/*1.1.21.*/ else        	  DT5_  = StrToFloat(RCD(DT__));
/*1.1.22.*/ fprintf(F_NU, " %3i %9.2f %8.1f %8.1f %8.1f %8.1f %8.1f \n", NU_, DT_S_, DT1_, DT2_, DT3_, DT4_, DT5_);
}; // 1.1.
/*1.2.*/ fclose(F_NU);
}; // 1.
}; // void __fastcall NU_SAVE()
//---------------------------------------------------------------------------
TColor HEXToColor(const AnsiString&  sColor)
{
TColor Res = TColor(RGB(StrToInt("$" + sColor.SubString(1,2)), StrToInt("$" + sColor.SubString(3,2)), StrToInt("$" + sColor.SubString(5,2))));
return  Res;
}; // TColor HEXToColor(const AnsiString&  S)
//---------------------------------------------------------------------------
void __fastcall SG_IK_COLS(const int& P_HS) // Работа с таблицей результатов циклограммы
{
/*1.*/ if (F_CKL->Tag == 0)
{
/*1.1.*/ for (int ns = 0; (ns < F_CKL->SG_IK_NU->RowCount); ns++)
{
/*1.1.1.*/ for (int nc = 0; (nc < F_CKL->SG_IK_NU->ColCount); nc++)
{
/*1.1.1.1.*/ F_CKL->SG_IK_NU->CellStyle[nc][ns]->HorizontalAlignment = taCenter;
			 F_CKL->SG_IK_NU->CellStyle[nc][ns]->Font->Size          = 10;
			 F_CKL->SG_IK_NU->CellStyle[nc][ns]->Font->Color         = clBlack;
/*1.1.1.2.*/ if ((ns == 0) || (nc == 0)) F_CKL->SG_IK_NU->CellStyle[nc][ns]->Font->Style = TFontStyles() << fsBold;
/*1.1.1.3.*/ else
{
/*1.1.1.3.1.*/ if (fmod(double(ns), 2.0) < 1.0E-5)  F_CKL->SG_IK_NU->CellStyle[nc][ns]->BGColor = clWhite;
/*1.1.1.3.1.*/ else                                 F_CKL->SG_IK_NU->CellStyle[nc][ns]->BGColor = clInfoBk;
}; // 1.1.1.3.
}; // 1.1.1.
/*1.1.2.*/ if (ns != 0)
{
F_CKL->SG_IK_NU->Cells[0][ns] = IntToStr(ns);
F_CKL->SG_IK_NU->Cells[1][ns] = IVS_TS[ns - 1]->C_E_NS->Text;
}; // 1.1.2.
}; // 1.1.
/*1.2.*/ for (int ns = 1; ns < F_CKL->SG_IK_NU->RowCount; ns++)  F_CKL->SG_IK_NU->Cells[1][ns] = IVS_TS[ns-1]->C_E_NS->Text;
/*1.3.*/ UINT  K_INT = 10; // Максимальное количество результатов РПС
F_CKL->SG_IK_REZ->SelectedColors->BGColor = HEXToColor("b0ffff");
F_CKL->SG_IK_REZ->RowCount                = F_CKL->SG_IK_NU->RowCount;
F_CKL->SG_IK_REZ->ColCount                = 2 + 2 * K_INT;
UINT  CW_0 = 25, CW_1 = 25, CW_2 = 45, CW_3 = 50;
F_CKL->SG_IK_REZ->ClientWidth = CW_0 + CW_1 + K_INT * (CW_2 + CW_3) + 30;
F_CKL->SG_IK_REZ->ColWidths[0] = CW_0;
F_CKL->SG_IK_REZ->Cells[0][0]  = "№";
F_CKL->SG_IK_REZ->ColWidths[1] = CW_1;
F_CKL->SG_IK_REZ->Cells[1][0]  = "НУ";
/*1.4.*/ for (int ns = 0; ns < F_CKL->SG_IK_REZ->RowCount; ns++)
{
/*1.4.1.*/ if (0 < ns)  F_CKL->SG_IK_REZ->Cells[0][ns] = ns;
/*1.4.2.*/ for (int nc = 0; nc < F_CKL->SG_IK_REZ->ColCount; nc++)
{
/*1.4.2.1.*/ if (fmod(double(ns), 2.0) < 1.0E-5)  F_CKL->SG_IK_REZ->CellStyle[nc][ns]->BGColor = clWhite;
/*1.4.2.2.*/ else                                 F_CKL->SG_IK_REZ->CellStyle[nc][ns]->BGColor = clInfoBk;
/*1.4.2.3.*/ F_CKL->SG_IK_REZ->CellStyle[nc][ns]->HorizontalAlignment = taCenter;
			 F_CKL->SG_IK_REZ->CellStyle[nc][ns]->Font->Size          = 10;
			 F_CKL->SG_IK_REZ->CellStyle[nc][ns]->Font->Color         = clBlack;
/*1.4.2.4.*/ if ((ns == 0) || (nc == 0))  F_CKL->SG_IK_REZ->CellStyle[nc][ns]->Font->Style = TFontStyles() << fsBold;
/*1.4.2.5.*/ if ((ns == 0) &&  (1 < nc))
{
/*1.4.2.5.1.*/ if (fmod(double(nc), 2.0) < 1.0E-5)
{
F_CKL->SG_IK_REZ->ColWidths[nc] = CW_2;
F_CKL->SG_IK_REZ->Cells[nc][0]  = "Зн. " + IntToStr(nc / 2);
} // 1.4.2.5.1.
/*1.4.2.5.2.*/ else
{
F_CKL->SG_IK_REZ->ColWidths[nc] = CW_3;
F_CKL->SG_IK_REZ->Cells[nc][0]  = "Инт. "  + IntToStr((nc - 1) / 2);
}; // 1.4.2.5.2.
}; // 1.4.2.5.
}; // 1.4.2.
}; // 1.4.
/*1.5.*/ F_CKL->Tag = 1;
} // 1.
/*2.*/ try
{
/*2.1.*/ if ((P_HS == 1) && (F_CKL->Visible == true))  F_CKL->Hide(); // F_CKL->SG_IK_REZ->Hide();
/*2.2.*/ for (int ns = 1; ns < F_CKL->SG_IK_REZ->RowCount; ns++) // Очищаем таблицу результатов от предыдущих значений
{
/*2.2.1.*/ for (int np = 1; np < F_CKL->SG_IK_REZ->ColCount; np++)
{
/*2.2.1.1.*/ F_CKL->SG_IK_REZ->Cells[np][ns] = "";
/*2.2.1.2.*/ if (fmod(double(ns), 2.0) < 1.0E-5)  F_CKL->SG_IK_REZ->CellStyle[np][ns]->BGColor   = clWhite;
/*2.2.1.3.*/ else                                 F_CKL->SG_IK_REZ->CellStyle[np][ns]->BGColor   = clInfoBk;
}; // 2.2.1.
}; // 2.2.
/*2.3.*/ for (int ns = 0; ns < K_S; ns++)
{
/*2.3.1.*/ UINT  ns_1 = ns + 1;
F_CKL->SG_IK_REZ->Cells[1][ns_1] = RPS_TS[ns]->PRM_NU;
/*2.3.2.*/ if (0 < RPS_TS[ns]->PRMR.Length)
{
/*2.3.2.1.*/ F_CKL->SG_IK_REZ->CellStyle[1][ns_1]->BGColor = HEXToColor("ffd2d2");
/*2.3.2.2.*/ for (int npp = 0; (npp < RPS_TS[ns]->PRMR.Length); npp++)
{
UINT  npp2_2 = npp * 2 + 2, npp2_3 = npp * 2 + 3;
F_CKL->SG_IK_REZ->CellStyle[npp2_2][ns_1]->BGColor = HEXToColor("ffd2d2");
F_CKL->SG_IK_REZ->CellStyle[npp2_3][ns_1]->BGColor = HEXToColor("ffd2d2");
F_CKL->SG_IK_REZ->Cells[npp2_2][ns_1] = IntToStr(RPS_TS[ns]->PRMR[npp].ZN);
F_CKL->SG_IK_REZ->Cells[npp2_3][ns_1] = FloatToStrF((RPS_TS[ns]->PRMR[npp].KT_PRM - RPS_TS[ns]->PRMR[npp].NT_PRM), ffFixed, 5, 2);
}; // 2.3.2.2.
}; // 2.3.2.
}; // 2.3.
/*2.4.*/ if (P_HS == 1)
{
F_CKL->Show(); // F_CKL->SG_IK_REZ->Show();
F_CKL->Refresh();
}; // 2.4.
} // 2.
/*3.*/ catch(...) // Сбой визуализации
{
// F_CKL->Hide();
KT_PRM_MAX                 = 0;
F_IK->TM_CKL->Enabled      = false;
F_IK->MM_IK_CKL_V->Enabled = true;
/*3.3.*/ MessageDlg("Необходимо повторно осуществить запуск циклограммы.", mtWarning, TMsgDlgButtons() << mbOK, 0);
} // 3.
}; // void __fastcall SG_IK_COLS(const int& P_HS)
//---------------------------------------------------------------------------
void __fastcall SEND_ME(const UnicodeString&  STR, TMaskEdit* const ME)
{
AnsiString  STR_, STR__;
TRect       Rect;
/*1.*/ if (T_COL == 2) // Третья колонка (Начальные условия по сигналу)
{
ME->EditMask        = "0";
ME->Text            = STR;
ME->SelStart = 0;
} // 1.
/*2.*/ if (T_COL == 3) // Четвертая колонка (Задержка начала циклограммы сигнала)
{
/*2.1.*/ ME->EditMask = "00.00";
/*2.2.*/ if (10.0 <= StrToFloat(RCD(STR))) STR_ = STR;
/*2.3.*/ else                              STR_ = "0" + STR;
/*2.4.*/ STR__      = "00.00";
		 STR__[1]   = STR_[1];
		 STR__[2]   = STR_[2];
		 STR__[4]   = STR_[4];
		 STR__[5]   = STR_[5];
		 ME->Text   = STR__;
ME->SelStart = 1;
}; // 2.
/*3.*/ if (3 < T_COL) // С пятой колонки (временные диапазоны значений "0" и "1" сигнала)
{
/*3.1.*/ ME->EditMask = "00.0";
/*3.2.*/ if (10.0 <= StrToFloat(RCD(STR))) STR_ = STR;
/*3.3.*/ else                              STR_ = "0" + STR;
/*3.4.*/ STR__    = "00.0";
		 STR__[1] = STR_[1];
		 STR__[2] = STR_[2];
		 STR__[4] = STR_[4];
		 ME->Text = STR__;
ME->SelStart = 1;
}; // 3.
/*4.*/ Rect = F_CKL->SG_IK_NU->CellRect(T_COL, T_ROW);
ME->Left    = Rect.Left + F_CKL->SG_IK_NU->Left +  6;
ME->Top     = Rect.Top  + F_CKL->SG_IK_NU->Top  + 31;
ME->Width   = Rect.Width();
ME->Height  = Rect.Height();
ME->Show();
ME->SetFocus();
}; // __fastcall void  SEND_ME(const UnicodeString&  STR, TMaskEdit* const ME)
//---------------------------------------------------------------------------
void __fastcall  GET_DIR_FN(const AnsiString& FULLNM, UnicodeString& DIR, UnicodeString& FN)
{
/*1.*/ for (int ns = FULLNM.Length(); 1 <= ns; ns--)
{
/*1.1.*/ if (FULLNM[ns] == '\\')
{
DIR   = FULLNM.SubString(1, ns);
FN    = FULLNM.SubString((ns + 1), (FULLNM.Length() - ns));
break;
}; // 1.1.
}; // 1.
}; // void __fastcall  GET_DIR_FN(const AnsiString& FULLNM, UnicodeString& DIR, UnicodeString& FN)
//---------------------------------------------------------------------------
void __fastcall NASTR_LD()
{
/*1.*/ AnsiString P_NASTR_ = AnsiString(PATH_) + "\\Nastr.ini";
/*2.*/ if ((F_NASTR = fopen(P_NASTR_.c_str(), "rt")) != NULL)
{
AnsiString  STR_, STR__;
/*2.1.*/ FROMINI(P_NASTR_);
U_DT_NC = StrToFloat(RCD(VR_P[0][0])); // 1 - Время задержки перед началом   выполнения циклограммы
U_DT_KC = StrToFloat(RCD(VR_P[0][1])); // 2 - Время задержки после окончания выполнения циклограммы
/*2.2.*/ if (10.0 <= StrToFloat(RCD(VR_P[0][0]))) STR_ =       VR_P[0][0];
/*2.3.*/ else                                     STR_ = "0" + VR_P[0][0];
/*2.4.*/ STR__         = "00.00";
		 STR__[1]      = STR_[1];
		 STR__[2]      = STR_[2];
		 STR__[4]      = STR_[4];
		 STR__[5]      = STR_[5];
F_NSTR->ME_NU_VC_2->Text = STR__;
/*2.5.*/ if (10.0 <= StrToFloat(RCD(VR_P[0][1]))) STR_ =       VR_P[0][1];
/*2.6.*/ else                                     STR_ = "0" + VR_P[0][1];
/*2.7.*/ STR__         = "00.00";
		 STR__[1]      = STR_[1];
		 STR__[2]      = STR_[2];
		 STR__[4]      = STR_[4];
		 STR__[5]      = STR_[5];
F_NSTR->ME_NU_VC_3->Text = STR__;
/*2.8.*/ for (unsigned int i = 0; i < T_DVC::NumOfDevices; i++) // 3... - Признаки визуализации плат
{
/*2.8.1.*/ if ((i + 2) <= VR_P[0].Length)  DVC_TS[i]->P_H = strtoul(VR_P[0][(i + 2)].c_str(), NULL, 10);
/*2.8.2.*/ else                            DVC_TS[i]->P_H = 4294967295; // Все 32 бита - в "1"
}; // 2.8.
/*2.9*/ T_DVC::VIS_DVC(); // Визуализация панелей плат
fclose(F_NASTR);
}; // 2.
}; // void __fastcall NASTR_LD()
//---------------------------------------------------------------------------
void __fastcall NASTR_SAVE()
{
/*1.*/ AnsiString P_NASTR_ = AnsiString(PATH_) + "\\Nastr.ini";
/*2.*/ if ((F_NASTR = fopen(P_NASTR_.c_str(), "w+")) != NULL)
{
double  ME_2_ = StrToFloat(RCD(F_NSTR->ME_NU_VC_2->Text)); // 1 - Время задержки перед началом   выполнения циклограммы
double  ME_3_ = StrToFloat(RCD(F_NSTR->ME_NU_VC_3->Text)); // 2 - Время задержки после окончания выполнения циклограммы
fprintf(F_NASTR, " %7.2f %7.2f", ME_2_, ME_3_);            // 3... - Признаки визуализации плат
/*3.*/ for (unsigned int i = 0; i < T_DVC::NumOfDevices; i++) fprintf(F_NASTR, "%15u", DVC_TS[i]->P_H);
fclose(F_NASTR);
}; // 2.
}; // void __fastcall NASTR_SAVE()
//---------------------------------------------------------------------------
UnicodeString  D_T() // Дата + время (с милисекундами)
{
Word           YY, MN, DD, HH_, MM_, SS_, MS;
UnicodeString              HH,  MM,  SS;
/*1.*/ TDateTime  dtPresent = Now();
dtPresent.DecodeDate(&YY, &MN, &DD);
dtPresent.DecodeTime(&HH_, &MM_, &SS_, &MS);
HH_ < 10  ?  HH = "0" + IntToStr(HH_)  :  HH =       IntToStr(HH_);
MM_ < 10  ?  MM = "0" + IntToStr(MM_)  :  MM =       IntToStr(MM_);
SS_ < 10  ?  SS = "0" + IntToStr(SS_)  :  SS =       IntToStr(SS_);
UnicodeString  D_T_ = IntToStr(DD) + "." + IntToStr(MN) + "." + IntToStr(YY) + "     " +
							   HH + ":" + MM + ":" + SS + ":" + IntToStr(E(MS/100.0));
return  D_T_;
}; // UnicodeString  D_T()
//---------------------------------------------------------------------------
void __fastcall  P_G_C_IVS() // Построение графиков циклограммы ИВС
{
K_CH = 0;
unsigned int nc_  = 0;
double       MAX_ = 0.0;
/*1.*/ if (F_CKL->SG_IK_NU->Cells[9][T_ROW] == "")    K_CH = 1;
/*2.*/ else
{
/*2.2.*/ for (int ns = 1; ns < F_CKL->SG_IK_NU->RowCount; ns++)
{
/*2.2.1.*/ if (F_CKL->SG_IK_NU->Cells[9][ns] == "V")  K_CH++;
}; // 2.2.
}; // 2.
/*3.*/ T_CH_L_TS = new T_CH_L*[K_CH];
/*4.*/ if (0 < K_CH)
{
/*4.1.*/ for (int ns = 1; ns < F_CKL->SG_IK_NU->RowCount; ns++)
{
/*4.1.1.*/ if ( (K_CH == 1) && (ns == T_ROW) || (1 < K_CH) && (F_CKL->SG_IK_NU->Cells[9][ns] == "V"))
{
/*4.1.1.1.*/ F_CKL->SG_IK_NU->Cells[9][ns]              = "";
T_CH_L_TS[nc_]                                          = new T_CH_L();
T_CH_L_TS[nc_]->C_Chart                                 = new TChart(F_CH);
T_CH_L_TS[nc_]->C_Chart->Tag                            = nc_;
T_CH_L_TS[nc_]->C_Chart->Parent                         = F_CH;
T_CH_L_TS[nc_]->C_Label                                 = new TLabel(T_CH_L_TS[nc_]->C_Chart);
T_CH_L_TS[nc_]->C_Label->Parent                         = T_CH_L_TS[nc_]->C_Chart;
T_CH_L_TS[nc_]->C_Chart->OnMouseDown                    = F_CH->MsDn;
T_CH_L_TS[nc_]->C_Chart->View3D                         = false;
T_CH_L_TS[nc_]->C_Chart->Align                          = alNone;
T_CH_L_TS[nc_]->C_Chart->Height                         = F_CH->ClientHeight / K_CH;
T_CH_L_TS[nc_]->C_Chart->Top                            = nc_ * F_CH->ClientHeight / K_CH;
T_CH_L_TS[nc_]->C_Chart->Left                           = 0;
T_CH_L_TS[nc_]->C_Chart->Width                          = F_CH->ClientWidth;
T_CH_L_TS[nc_]->C_Chart->Title->Font->Size              = 12;
T_CH_L_TS[nc_]->C_Chart->Title->Font->Style = TFontStyles() << fsBold;
T_CH_L_TS[nc_]->C_Chart->Title->Text->Add("ИВС  № " + IntToStr(ns) + " :   " + "\"" + IVS_TS[(ns - 1)]->C_E_NS->Text + "\""); // Название сигнала ИВС
T_CH_L_TS[nc_]->C_Chart->Legend->Visible                = false;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->Automatic            = false;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->AutomaticMaximum     = false;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->AutomaticMinimum     = false;
T_CH_L_TS[nc_]->C_Chart->BottomAxis->Automatic          = false;
T_CH_L_TS[nc_]->C_Chart->BottomAxis->AutomaticMaximum   = false;
T_CH_L_TS[nc_]->C_Chart->BottomAxis->AutomaticMinimum   = false;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->Minimum              = 0.0;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->Maximum              = 1.5;
T_CH_L_TS[nc_]->C_Chart->LeftAxis->Increment            = 0.5;
T_CH_L_TS[nc_]->C_Chart->BottomAxis->Minimum            = 0.0;
IVS_TS[(ns - 1)]->P_G_C_IVS(nc_);
double  MAX_L_                             = U_DT_NC + IVS_TS[(ns - 1)]->SDT_PRM + 0.5;
/*4.1.1.2.*/ if (MAX_ < MAX_L_)  MAX_      = MAX_L_;
/*4.1.1.3.*/ if (1 < K_CH)  nc_++;
}; // 4.1.1.
}; // 4.1.
/*4.2.*/ for (int nc = 0; nc < K_CH; nc++)
{
T_CH_L_TS[nc]->C_Chart->BottomAxis->Increment = 0.05 * int(MAX_);
T_CH_L_TS[nc]->C_Chart->BottomAxis->Maximum    = MAX_;
}; // 4.2.
}; // 4.
/*5.*/ F_CH->Show();
}; // void __fastcall  P_G_C_IVS()
//---------------------------------------------------------------------------
void __fastcall  NSTR_B_PL_CL(const TComboBox* const CB_PL_)
{
/*1.*/ for (int npp = 1; npp < F_NSTR->ZCSG_NSTR->RowCount; npp++)
{
IVS_TS[32 * CB_PL_->Tag + npp - 1]->C_E_NS->Text = F_NSTR->ZCSG_NSTR->Cells[1][npp];
RPS_TS[32 * CB_PL_->Tag + npp - 1]->C_E_NS->Text = F_NSTR->ZCSG_NSTR->Cells[2][npp];
}; // 1.
/*2.*/ F_NSTR->B_PL->Enabled = false;
}; // void __fastcall  NSTR_B_PL_CL(const TComboBox* const CB_PL_)
//---------------------------------------------------------------------------
AnsiString  GRtoS(const UINT&  GR) // Преобразование T_IVS.S_C_GR.GR (UINT) в AnsiString
{ // 0 - "11"; 1 - "12"; 2 - "21"; 3 - "22"; 4 - "31"; 5 - "32";
/*1.*/ AnsiString  GR_AS;
/*2.*/ switch(GR)
{
case(0):       GR_AS = "11";   break;
case(1):       GR_AS = "12";   break;
case(2):       GR_AS = "21";   break;
case(3):       GR_AS = "22";   break;
case(4):       GR_AS = "31";   break;
case(5):       GR_AS = "32";   break;
case(6):       GR_AS = "Hide"; break;
default:       GR_AS = "11";   break;
}
/*3.*/ return  GR_AS;
}; // AnsiString  GRtoS(const UINT&  GR)
//---------------------------------------------------------------------------
UINT  StoGR(const AnsiString&  S) // Преобразование  AnsiString  в  T_IVS.S_C_GR.GR (UINT)
{ // 0 - "11"; 1 - "12"; 2 - "21"; 3 - "22"; 4 - "31"; 5 - "32"; 6 - "Hide"
/*1.*/ UINT  AS_GR;
/*2.*/      if  (0 < S.Pos("11"))    AS_GR = 0;
/*3.*/ else if  (0 < S.Pos("12"))    AS_GR = 1;
/*4.*/ else if  (0 < S.Pos("21"))    AS_GR = 2;
/*5.*/ else if  (0 < S.Pos("22"))    AS_GR = 3;
/*6.*/ else if  (0 < S.Pos("31"))    AS_GR = 4;
/*7.*/ else if  (0 < S.Pos("32"))    AS_GR = 5;
/*8.*/ else if  (0 < S.Pos("Hide"))  AS_GR = 6;
/*9.*/ return  AS_GR;
}; // UINT  StoGR(const AnsiString&  S)
//---------------------------------------------------------------------------

