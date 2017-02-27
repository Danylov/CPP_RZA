#ifndef IVS_RPS_H
#define IVS_RPS_H
//---------------------------------------------------------------------------
#include <stdio.h>
#include <vector>
#include <VCLTee.Series.hpp>
#include "U_Interf_.h"
#include "StF_.h"
//---------------------------------------------------------------------------
using  std::unique_ptr;
using  std::vector;
//---------------------------------------------------------------------------
typedef struct  // Настройка выбора, цвета сигнала, графика его отображения
{
UINT          SLCTN; // 0 - сигнал для отображения не выбран, 1 - выбран
TColor        CLR;   // Цвет  отображения  сигнала
UINT          GR;    // График  отображения  сигнала: 0 - "11"; 1 - "12"; 2 - "21"; 3 - "22"; 4 - "31"; 5 - "32"; 6 - "Hide"
} T_S_C_GR;
//---------------------------------------------------------------------------
typedef struct  // Промежутки инвертирования сигналов ИВС в процессе реализации циклограммы
{
double  DT_PRM; // Длительность данного промежутка формирования взаимно инверсных сигналов
double  KT_PRM; // Время окончания данного промежутка формирования взаимно инверсных сигналов
int     P_PRM;  // Признак необходимости инвертирования после окончания данного промежутка
int     P_ZAV;  // Признак того, что данный промежуток был пройден и сигнал после его окончания был проинвертирован (при необходимости)
} T_PRM_IVS;
//---------------------------------------------------------------------------
typedef struct  // Промежутки одного значения сигнала РПС в процессе реализации циклограммы
{
double  NT_PRM; // Время начала    текущего промежутка относительно времени начала циклограммы
double  KT_PRM; // Время окончания текущего промежутка относительно времени начала циклограммы
int     ZN;     // Значение сигнала на данном промежутке
} T_PRM_RPS;
//---------------------------------------------------------------------------
class T_IR_NV_O // Базовый класс, характеризующий значения всех сигналов ИВС (РПС) в текущий момент времени
{
protected:
TDateTime     D_T;  // Момент времени смены значения одного из сигналов
vector<UINT>  ZN_P; // Вектор с упакованными величинами всех сигналов по платам, в том числе новое значение изменившегося сигнала
public:
TDateTime     get_D_T();                // Извлечение значения времени
UINT          get_ZN_P(const int& N_S); // Извлечение значения сигнала № N_S (0...)
virtual      ~T_IR_NV_O();
}; // class T_IR_NV_O
//---------------------------------------------------------------------------
class T_I_NV_O : public  T_IR_NV_O // Класс, объект которого характеризует значения всех сигналов ИВС в текущий момент времени
{               // Объект создается при изменении значения любого сигнала и содержит в т. ч. новое значение этого сигнала
public:
 T_I_NV_O();
~T_I_NV_O();
}; // class T_I_NV_O
//---------------------------------------------------------------------------
class T_R_NV_O : public  T_IR_NV_O // Класс, объект которого характеризует значения всех сигналов РПС в текущий момент времени
{               // Объект создается при изменении значения любого сигнала и содержит в т. ч. новое значение этого сигнала
public:
 T_R_NV_O();
~T_R_NV_O();
}; // class T_R_NV_O
//---------------------------------------------------------------------------
// Сигналы ИВС
class T_IVS // InstantDoCtrl
{
static  FILE              *F_IVS_REZ; // Сохранение результатов
static  AnsiString         P_IVS_REZ;
static  FILE              *F_IVS_GR;  // Сохранение настроек для отображения графиков ИВС
static  AnsiString         P_IVS_GR;
public:
static  vector<T_I_NV_O>   IVS_NV; // Вектор упакованных значений ИВС (новая запись добавляется при измен. любого сигнала)
UINT             Tag;      // Номер  в  таблице  сканирования  ИВС
UINT             T_S;      // Тип сигнала: 0 - сигнал "0 -> 1", 1 - сигнал "1 -> 0"
double           N_VR, DLT_VR; // Начальное значение и реальная  длительность выходного сигнала
double           F_DS;     // Требуемая длительность выходного сигнала
double           SDT_PRM;  // Суммарная длительность промежутков формирования взаимно инверсных сигналов при реал. циклограммы
TPanel          *C_PNL;    // Панель ИВС
TCheckBox       *C_CHB;    // Метка группировки выходных сигналов
unsigned int     P_CHB;    // Признак наличия в конфигурации группировки выходных сигналов
unsigned int     P_H;      // Признак отображения панели, <=> сигналу ИВС
UINT             P_TM_EN;  // Признак активности таймера сигнала ИВС (1 - активен)
T_PRM_IVS        PRM_I[6]; // Промежутки инвертирования сигналов ИВС в процессе реализации циклограммы
TEdit           *C_E_NM;   // Номер выходного сигнала
TImage          *C_IM;     // Рисунок, отображающий тип сигнала
TAdvToolButton  *C_B_SS;   // Кнопка включения-отключения сигнала
TEdit           *C_E_NS;   // Описание выходного сигнала
TEdit           *C_E_DS;   // Длительность выходного сигнала
TZylTimer       *C_TM;     // Таймер выходного сигнала
TLineSeries     *C_LS_CKL; // График канала ИВС для циклограммы
T_S_C_GR         S_C_GR;   // Настройка выбора, цвета сигнала, графика его отображения
unique_ptr<TLineSeries>  C_LS; // График канала ИВС для отображения на панели графиков (не циклограммы)
static void __fastcall F_I(); // Статический метод первой инициализации
static void __fastcall F_V(); // Статический метод просмотра результатов ИВС
static void __fastcall IVS_GR_LD();
static void __fastcall IVS_GR_SV();
void __fastcall  ZAP_SRS();   // Заполнение серии данными для последующей сизуализации
void             S_Z();       // Запись новых значений ИВС в файл и вектор
void             IZM_SOST_KN(const int& Down_); // Новое состояние кнопки: 0 - Down=0; 1 - Down=1; 2 - инверсия Down
void             IN_KN_PL();  // Начальное состояние кнопки исходя из состояния контактов на плате
void             IN_KN_INI(); // Приведение кнопок в требуемое состояние исходя из значения в файле конфигурации IVS.ini
void             NO_KN(const int& P_NIS, const int& I_D);  // P_NIS = 1 - работаем с таймером, I_D = 1 - инверсия Down // Наж.-отж. кн. в проц. функц.
void             IN_IM();     // Картинки типов сигналов
void             PRM(const UINT&  P_KT_PRM); // Формирование промежутков времени инверсных значений сигналов
void             NVC();       // Действия, необходимые перед выполнением циклограммы
void             P_G_C_IVS(const UINT& N_CH_); // Построение графика циклограммы конкретной ИВС
void             VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_); // Визуализация панели сигнала ИВС
				 T_IVS(const UINT& N_IVS, TGroupBox* const C_GBX);
virtual			~T_IVS();
}; // class T_IVS
//---------------------------------------------------------------------------
// Сигналы РПС
class T_RPS // InstantDiCtrl
{
static  FILE              *F_RPS_REZ; // Сохранение результатов
static  AnsiString         P_RPS_REZ;
static  FILE              *F_RPS_GR;  // Сохранение настроек для отображения графиков РПС
static  AnsiString         P_RPS_GR;
public:
static  vector<T_R_NV_O>   RPS_NV; // Вектор упакованных значений РПС (новая запись добавляется при измен. любого сигнала)
unsigned int     Tag;     // Номер  в  таблице  сканирования  РПС
unsigned int     P_N1T;   // Признак не 1 такта (такта инициализации)
public:                        // SOST, SOST_X: 3 - нет сигнала,  квитирование (фон).
unsigned int     SOST, SOST_X; // SOST, SOST_X: 1 - есть сигнал (красный); 2 - нет сигнала, не заквитирован (желтый);
double           N_VR, DLT_VR;
unsigned int     P_H;     // Признак отображения панели, <=> сигналу РПС
DynamicArray <T_PRM_RPS>  PRMR;
int                       PRM_NU; // Начальное значение сигнала РПС на момент начала циклограммы (0 - нет сигнала, 1 - есть сигнал)
TPanel          *C_PNL;   // Панель РПС
TEdit           *C_E_NM;  // Номер входного сигнала
TImage          *C_IM;    // Состояние входного сигнала
TCheckBox       *C_CHB_I; // Метка, задающая признак отображения времени отсутствия сигнала
TEdit           *C_E_DS;  // Длительность входного сигнала
TEdit           *C_E_NS;  // Описание входного сигнала
T_S_C_GR         S_C_GR;  // Настройка выбора, цвета сигнала, графика его отображения
unique_ptr<TLineSeries>  C_LS; // График канала РПС для отображения на панели графиков (не циклограммы)
void __fastcall  ZAP_SRS();    // Заполнение серии данными для последующей сизуализации
static void __fastcall F_I();  // Статический метод первой инициализации
static void __fastcall F_V();  // Статический метод просмотра результатов РПС
static void __fastcall RPS_GR_LD();
static void __fastcall RPS_GR_SV();
T_IVS           *C_IVS;   // Ссылка  на  сигнал  ИВС,  который  необходимо  инициировать  после  изменения  РПС  1->0
void             IM_CANVAS(const UINT& PR_S);
void             DTM();
void             VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_); // Визуализация панели сигнала РПС
void             PNL_OBNOVL();
				 T_RPS(const UINT& N_RPS, TGroupBox* const C_GBX);
virtual			~T_RPS();
}; // class T_RPS
//---------------------------------------------------------------------------
// Метки ИВС
class T_L_IVS
{
public:
TPanel    *C_PNL;                                  // Панель надписей ИВС
TLabel    *C_L_CHB, *C_L_NM, *C_L_IM, *C_L_SS, *C_L_DS, *C_L_NS;
void      VIS();                                   // Визуализация панели надписей ИВС
		  T_L_IVS(const UINT& N_L_IVS, TGroupBox* const C_GBX);
virtual	 ~T_L_IVS();
}; // class T_L_IVS
//---------------------------------------------------------------------------
// Метки РПС
class T_L_RPS
{
public:
TPanel    *C_PNL;                                   // Панель надписей РПС
TLabel    *C_L_NM, *C_L_IM, *C_L_CHB_I, *C_L_DS, *C_L_NS;
void       VIS();                                   // Визуализация панели надписей РПС
		   T_L_RPS(const UINT& N_L_RPS, TGroupBox* const C_GBX);
virtual	  ~T_L_RPS();
}; // class T_L_RPS
//---------------------------------------------------------------------------
class T_CH
{
public:
void          UpdateLED(InstantDoCtrl *C_T_instantDoCtrl, const UINT&  kanal, const UINT&  mode);
DWORD         N_DVC;            // Номер  платы
int32         N_PORT;           // Номер  порта
void          NACH_USL_PORT(byte  *portState);
			  T_CH();
virtual	     ~T_CH();
}; // class T_CH
//---------------------------------------------------------------------------
class  T_DVC
{
public:
static unsigned int    K_PORT;          // Количество  каналов
DeviceTreeNode         DVC_DI, DVC_DO;
DWORD                  N_DVC;           // Номер платы (0 - ...)
T_CH                  *C_CH;
T_IVS                 *C_DIVS[32];
T_RPS                 *C_DRPS[32];
T_L_IVS               *C_L_IVS;
T_L_RPS               *C_L_RPS;
TGroupBox             *C_GB;            // GroupBox, <=> плате
void                   NACH_USL_DVC();
UINT                   Tag;             // Номер  в  таблице  сканирования  T_DVC
UINT                   P_H;             // Побитово упакованная переменная, <=> плате
InstantDiCtrl         *C_instantDiCtrl; // Предост. интерф. для упр-ния св-ми, мет-ми и соб-ми для порта DI платы (static DI)
InstantDoCtrl         *C_instantDoCtrl; // Предост. интерф. для упр-ния св-ми, мет-ми и соб-ми для порта DO платы (static DO)
static  ICollection<DeviceTreeNode>  *C_supportedDevices_DI; // Коллекция плат, поддерживающих  static DI
static  ICollection<DeviceTreeNode>  *C_supportedDevices_DO; // Коллекция плат, поддерживающих  static DO
static  UINT           NumOfDevices;    // Количество плат
					   T_DVC(const UINT& i);
virtual	              ~T_DVC();
void        __fastcall VIS_PAN(const UINT& DVC_VS_T_, const UINT& DVC_VS_CM_); // Визуал. панелей сигн. ИВС и РПС в зав. от знач. <=> бита T_DVC->P_H
static void __fastcall VIS_DVC();
static void __fastcall F_I(); // Статический метод первой инициализации
}; // class  T_DVC
unsigned int  T_DVC::K_PORT; // Объявление статической переменной вне класса
ICollection<DeviceTreeNode>*  T_DVC::C_supportedDevices_DI; // Коллекция плат, поддерживающих  static DI
ICollection<DeviceTreeNode>*  T_DVC::C_supportedDevices_DO; // Коллекция плат, поддерживающих  static DO
UINT                          T_DVC::NumOfDevices;          // Количество плат
//---------------------------------------------------------------------------
// Объявление статических переменных вне тела класса
FILE              *T_IVS::F_IVS_REZ; // Сохранение результатов
AnsiString         T_IVS::P_IVS_REZ;
FILE              *T_IVS::F_IVS_GR;  // Сохранение настроек для отображения графиков ИВС
AnsiString         T_IVS::P_IVS_GR;
vector<T_I_NV_O>   T_IVS::IVS_NV;    // Вектор упакованных значений ИВС (новая запись добавляется при измен. любого сигнала)
vector<T_R_NV_O>   T_RPS::RPS_NV;    // Вектор упакованных значений РПС (новая запись добавляется при измен. любого сигнала)
FILE              *T_RPS::F_RPS_REZ; // Сохранение результатов
AnsiString         T_RPS::P_RPS_REZ;
FILE               *T_RPS::F_RPS_GR; // Сохранение настроек для отображения графиков РПС
AnsiString          T_RPS::P_RPS_GR;
T_IR_NV_O::~T_IR_NV_O() {};
//---------------------------------------------------------------------------
#endif
