#pragma hdrstop
#include "Common_.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ИВС
 T_IVS**              IVS_TS;
 T_L_IVS**            L_IVS_TS;     // Метки ИВС на форме
// РПС
 T_RPS**              RPS_TS;
 T_L_RPS**            L_RPS_TS;     // Метки РПС на форме
AnsiString            DIR_REZ;       // Каталог с результатами ИВС и РПС
// Работа с платами
 T_DVC**              DVC_TS;
 unsigned int         K_S;          // Количество сигналов ИВС и РПС
 TZColorStringGrid**  ZAV_TS;
// Системный разделитель
 AnsiString SEP;
// Файлы инициализации
DynamicArray< DynamicArray< AnsiString > > VR_P;
char PATH_[100];
FILE          *F_IVS;         // Сохранение настроек
AnsiString     P_IVS;
FILE          *F_RPS;
AnsiString     P_RPS;
FILE          *F_NU;          // Циклограмма
AnsiString     P_NU;
FILE          *F_NASTR;
AnsiString     P_NASTR;
UINT T_COL, T_ROW, T_COL_NSTR, T_ROW_NSTR;              // Колонка  и  строка  обрабатываемой  ячейки
UINT        T_NIM;                                      // Номер TImage в таблице сканирования IVS_TS
// TChart
T_CH_L**       T_CH_L_TS;
unsigned int   K_CH;
// Циклограмма
unsigned int   PR_CKL   = 0;      // Признак реализации циклограммы
unsigned int   PR_TB_ZP = 0;      // Признак запрета переключения между вкладками
double  T_B_NU, U_DT_NC, T_NC;    // T наж. на кн., уст. задерж. нач. цикл., время начала циклограммы
double  KT_PRM_MAX, U_DT_KC;      // Максимальная длительность выдачи сигналов при реализации циклограммы
// Форматирование текста
String         ZCSG_FC, ZCSG_BGC;
//---------------------------------------------------------------------------
