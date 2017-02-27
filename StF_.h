#ifndef StF_H
#define StF_H
//---------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "AdvToolBtn.hpp"
#include "ZylTimer.hpp"
//---------------------------------------------------------------------------
int              E(const float& x);
double           SSTM();
void __fastcall  FROMINI(const    AnsiString&  P_INI_);
AnsiString       RCD(const        AnsiString&  S);
TColor           HEXToColor(const AnsiString&  sColor);
void __fastcall  SG_IK_COLS(const int& P_HS);
void __fastcall  SEND_ME(const UnicodeString&  STR, TMaskEdit* const ME); // Конст-й ук. на неконст. данные
void __fastcall  NU_SAVE();
void __fastcall  NU_LD();
void __fastcall  NASTR_LD();
void __fastcall  NASTR_SAVE();
void __fastcall  GET_DIR_FN(const AnsiString& FULLNM, UnicodeString& DIR, UnicodeString& FN);
void __fastcall  P_G_C_IVS(); // Построение графика циклограммы ИВС
UnicodeString    D_T();
void __fastcall  NSTR_B_PL_CL(const TComboBox* const CB_PL_); // Конст-й ук. на конст. данные
AnsiString       GRtoS(const UINT&  GR);      // Преобразование T_IVS.S_C_GR.GR (UINT) в AnsiString
UINT             StoGR(const AnsiString&  S); // Преобразование  AnsiString  в  T_IVS.S_C_GR.GR (UINT)
//---------------------------------------------------------------------------
#endif
