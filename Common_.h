#ifndef  Common_H
#define  Common_H
#include <stdio.h>
#include <memory>
#include "IVS_RPS_.h"
#include "StF_.h"
#include "bdaqctrl.h"
#include "DaqUtils.hpp"
//---------------------------------------------------------------------------
using  std::unique_ptr;
using  std::vector;
using namespace  Automation::BDaq;
//---------------------------------------------------------------------------
typedef struct // Промежутки инвертирования сигналов ИВС в процессе реализации циклограммы
{
TChart*  C_Chart;
TLabel*  C_Label;
} T_CH_L;
//---------------------------------------------------------------------------
// ИВС
extern  T_IVS**              IVS_TS;
extern  T_L_IVS**            L_IVS_TS; // Метки ИВС на форме
// РПС
extern  T_RPS**              RPS_TS;
extern  T_L_RPS**            L_RPS_TS; // Метки РПС на форме
extern  AnsiString           DIR_REZ;  // Каталог с результатами ИВС и РПС
// Работа сплатами
extern  T_DVC**              DVC_TS;
extern  unsigned int         K_S;      // Количество сигналов ИВС и РПС
extern  TZColorStringGrid**  ZAV_TS;
// Системный разделитель
extern  AnsiString SEP;
// Файлы инициализации
extern  DynamicArray< DynamicArray< AnsiString > > VR_P;
extern  char PATH_[100];
extern  FILE         *F_IVS;
extern  AnsiString    P_IVS;
extern  FILE         *F_RPS;
extern  AnsiString    P_RPS;
extern  FILE         *F_NU;  // Циклограмма
extern  AnsiString    P_NU;
extern  FILE         *F_NASTR;
extern  AnsiString    P_NASTR;
extern  UINT T_COL, T_ROW, T_COL_NSTR, T_ROW_NSTR;      // Колонка  и  строка  обрабатываемой  ячейки
extern  UINT          T_NIM;                            // Номер TImage в таблице сканирования IVS_TS
// TChart
extern  T_CH_L**      T_CH_L_TS;
extern  unsigned int  K_CH;
// Циклограмма
extern  unsigned int  PR_CKL;           // Признак реализации циклограммы
extern  unsigned int  PR_TB_ZP;         // Признак запрета переключения между вкладками
extern  double  T_B_NU, U_DT_NC, T_NC;  // T наж. на кн., уст. задерж. нач. цикл., время начала циклограммы
extern  double  KT_PRM_MAX, U_DT_KC;    // Максимальная длительность выдачи сигналов при реализации циклограммы
// Форматирование текста
extern  String       ZCSG_FC, ZCSG_BGC;
//---------------------------------------------------------------------------
#endif
