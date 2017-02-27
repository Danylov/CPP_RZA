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
typedef struct  // ��������� ������, ����� �������, ������� ��� �����������
{
UINT          SLCTN; // 0 - ������ ��� ����������� �� ������, 1 - ������
TColor        CLR;   // ����  �����������  �������
UINT          GR;    // ������  �����������  �������: 0 - "11"; 1 - "12"; 2 - "21"; 3 - "22"; 4 - "31"; 5 - "32"; 6 - "Hide"
} T_S_C_GR;
//---------------------------------------------------------------------------
typedef struct  // ���������� �������������� �������� ��� � �������� ���������� �����������
{
double  DT_PRM; // ������������ ������� ���������� ������������ ������� ��������� ��������
double  KT_PRM; // ����� ��������� ������� ���������� ������������ ������� ��������� ��������
int     P_PRM;  // ������� ������������� �������������� ����� ��������� ������� ����������
int     P_ZAV;  // ������� ����, ��� ������ ���������� ��� ������� � ������ ����� ��� ��������� ��� ��������������� (��� �������������)
} T_PRM_IVS;
//---------------------------------------------------------------------------
typedef struct  // ���������� ������ �������� ������� ��� � �������� ���������� �����������
{
double  NT_PRM; // ����� ������    �������� ���������� ������������ ������� ������ �����������
double  KT_PRM; // ����� ��������� �������� ���������� ������������ ������� ������ �����������
int     ZN;     // �������� ������� �� ������ ����������
} T_PRM_RPS;
//---------------------------------------------------------------------------
class T_IR_NV_O // ������� �����, ��������������� �������� ���� �������� ��� (���) � ������� ������ �������
{
protected:
TDateTime     D_T;  // ������ ������� ����� �������� ������ �� ��������
vector<UINT>  ZN_P; // ������ � ������������ ���������� ���� �������� �� ������, � ��� ����� ����� �������� ������������� �������
public:
TDateTime     get_D_T();                // ���������� �������� �������
UINT          get_ZN_P(const int& N_S); // ���������� �������� ������� � N_S (0...)
virtual      ~T_IR_NV_O();
}; // class T_IR_NV_O
//---------------------------------------------------------------------------
class T_I_NV_O : public  T_IR_NV_O // �����, ������ �������� ������������� �������� ���� �������� ��� � ������� ������ �������
{               // ������ ��������� ��� ��������� �������� ������ ������� � �������� � �. �. ����� �������� ����� �������
public:
 T_I_NV_O();
~T_I_NV_O();
}; // class T_I_NV_O
//---------------------------------------------------------------------------
class T_R_NV_O : public  T_IR_NV_O // �����, ������ �������� ������������� �������� ���� �������� ��� � ������� ������ �������
{               // ������ ��������� ��� ��������� �������� ������ ������� � �������� � �. �. ����� �������� ����� �������
public:
 T_R_NV_O();
~T_R_NV_O();
}; // class T_R_NV_O
//---------------------------------------------------------------------------
// ������� ���
class T_IVS // InstantDoCtrl
{
static  FILE              *F_IVS_REZ; // ���������� �����������
static  AnsiString         P_IVS_REZ;
static  FILE              *F_IVS_GR;  // ���������� �������� ��� ����������� �������� ���
static  AnsiString         P_IVS_GR;
public:
static  vector<T_I_NV_O>   IVS_NV; // ������ ����������� �������� ��� (����� ������ ����������� ��� �����. ������ �������)
UINT             Tag;      // �����  �  �������  ������������  ���
UINT             T_S;      // ��� �������: 0 - ������ "0 -> 1", 1 - ������ "1 -> 0"
double           N_VR, DLT_VR; // ��������� �������� � ��������  ������������ ��������� �������
double           F_DS;     // ��������� ������������ ��������� �������
double           SDT_PRM;  // ��������� ������������ ����������� ������������ ������� ��������� �������� ��� ����. �����������
TPanel          *C_PNL;    // ������ ���
TCheckBox       *C_CHB;    // ����� ����������� �������� ��������
unsigned int     P_CHB;    // ������� ������� � ������������ ����������� �������� ��������
unsigned int     P_H;      // ������� ����������� ������, <=> ������� ���
UINT             P_TM_EN;  // ������� ���������� ������� ������� ��� (1 - �������)
T_PRM_IVS        PRM_I[6]; // ���������� �������������� �������� ��� � �������� ���������� �����������
TEdit           *C_E_NM;   // ����� ��������� �������
TImage          *C_IM;     // �������, ������������ ��� �������
TAdvToolButton  *C_B_SS;   // ������ ���������-���������� �������
TEdit           *C_E_NS;   // �������� ��������� �������
TEdit           *C_E_DS;   // ������������ ��������� �������
TZylTimer       *C_TM;     // ������ ��������� �������
TLineSeries     *C_LS_CKL; // ������ ������ ��� ��� �����������
T_S_C_GR         S_C_GR;   // ��������� ������, ����� �������, ������� ��� �����������
unique_ptr<TLineSeries>  C_LS; // ������ ������ ��� ��� ����������� �� ������ �������� (�� �����������)
static void __fastcall F_I(); // ����������� ����� ������ �������������
static void __fastcall F_V(); // ����������� ����� ��������� ����������� ���
static void __fastcall IVS_GR_LD();
static void __fastcall IVS_GR_SV();
void __fastcall  ZAP_SRS();   // ���������� ����� ������� ��� ����������� ������������
void             S_Z();       // ������ ����� �������� ��� � ���� � ������
void             IZM_SOST_KN(const int& Down_); // ����� ��������� ������: 0 - Down=0; 1 - Down=1; 2 - �������� Down
void             IN_KN_PL();  // ��������� ��������� ������ ������ �� ��������� ��������� �� �����
void             IN_KN_INI(); // ���������� ������ � ��������� ��������� ������ �� �������� � ����� ������������ IVS.ini
void             NO_KN(const int& P_NIS, const int& I_D);  // P_NIS = 1 - �������� � ��������, I_D = 1 - �������� Down // ���.-���. ��. � ����. �����.
void             IN_IM();     // �������� ����� ��������
void             PRM(const UINT&  P_KT_PRM); // ������������ ����������� ������� ��������� �������� ��������
void             NVC();       // ��������, ����������� ����� ����������� �����������
void             P_G_C_IVS(const UINT& N_CH_); // ���������� ������� ����������� ���������� ���
void             VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_); // ������������ ������ ������� ���
				 T_IVS(const UINT& N_IVS, TGroupBox* const C_GBX);
virtual			~T_IVS();
}; // class T_IVS
//---------------------------------------------------------------------------
// ������� ���
class T_RPS // InstantDiCtrl
{
static  FILE              *F_RPS_REZ; // ���������� �����������
static  AnsiString         P_RPS_REZ;
static  FILE              *F_RPS_GR;  // ���������� �������� ��� ����������� �������� ���
static  AnsiString         P_RPS_GR;
public:
static  vector<T_R_NV_O>   RPS_NV; // ������ ����������� �������� ��� (����� ������ ����������� ��� �����. ������ �������)
unsigned int     Tag;     // �����  �  �������  ������������  ���
unsigned int     P_N1T;   // ������� �� 1 ����� (����� �������������)
public:                        // SOST, SOST_X: 3 - ��� �������,  ������������ (���).
unsigned int     SOST, SOST_X; // SOST, SOST_X: 1 - ���� ������ (�������); 2 - ��� �������, �� ������������ (������);
double           N_VR, DLT_VR;
unsigned int     P_H;     // ������� ����������� ������, <=> ������� ���
DynamicArray <T_PRM_RPS>  PRMR;
int                       PRM_NU; // ��������� �������� ������� ��� �� ������ ������ ����������� (0 - ��� �������, 1 - ���� ������)
TPanel          *C_PNL;   // ������ ���
TEdit           *C_E_NM;  // ����� �������� �������
TImage          *C_IM;    // ��������� �������� �������
TCheckBox       *C_CHB_I; // �����, �������� ������� ����������� ������� ���������� �������
TEdit           *C_E_DS;  // ������������ �������� �������
TEdit           *C_E_NS;  // �������� �������� �������
T_S_C_GR         S_C_GR;  // ��������� ������, ����� �������, ������� ��� �����������
unique_ptr<TLineSeries>  C_LS; // ������ ������ ��� ��� ����������� �� ������ �������� (�� �����������)
void __fastcall  ZAP_SRS();    // ���������� ����� ������� ��� ����������� ������������
static void __fastcall F_I();  // ����������� ����� ������ �������������
static void __fastcall F_V();  // ����������� ����� ��������� ����������� ���
static void __fastcall RPS_GR_LD();
static void __fastcall RPS_GR_SV();
T_IVS           *C_IVS;   // ������  ��  ������  ���,  �������  ����������  ������������  �����  ���������  ���  1->0
void             IM_CANVAS(const UINT& PR_S);
void             DTM();
void             VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_); // ������������ ������ ������� ���
void             PNL_OBNOVL();
				 T_RPS(const UINT& N_RPS, TGroupBox* const C_GBX);
virtual			~T_RPS();
}; // class T_RPS
//---------------------------------------------------------------------------
// ����� ���
class T_L_IVS
{
public:
TPanel    *C_PNL;                                  // ������ �������� ���
TLabel    *C_L_CHB, *C_L_NM, *C_L_IM, *C_L_SS, *C_L_DS, *C_L_NS;
void      VIS();                                   // ������������ ������ �������� ���
		  T_L_IVS(const UINT& N_L_IVS, TGroupBox* const C_GBX);
virtual	 ~T_L_IVS();
}; // class T_L_IVS
//---------------------------------------------------------------------------
// ����� ���
class T_L_RPS
{
public:
TPanel    *C_PNL;                                   // ������ �������� ���
TLabel    *C_L_NM, *C_L_IM, *C_L_CHB_I, *C_L_DS, *C_L_NS;
void       VIS();                                   // ������������ ������ �������� ���
		   T_L_RPS(const UINT& N_L_RPS, TGroupBox* const C_GBX);
virtual	  ~T_L_RPS();
}; // class T_L_RPS
//---------------------------------------------------------------------------
class T_CH
{
public:
void          UpdateLED(InstantDoCtrl *C_T_instantDoCtrl, const UINT&  kanal, const UINT&  mode);
DWORD         N_DVC;            // �����  �����
int32         N_PORT;           // �����  �����
void          NACH_USL_PORT(byte  *portState);
			  T_CH();
virtual	     ~T_CH();
}; // class T_CH
//---------------------------------------------------------------------------
class  T_DVC
{
public:
static unsigned int    K_PORT;          // ����������  �������
DeviceTreeNode         DVC_DI, DVC_DO;
DWORD                  N_DVC;           // ����� ����� (0 - ...)
T_CH                  *C_CH;
T_IVS                 *C_DIVS[32];
T_RPS                 *C_DRPS[32];
T_L_IVS               *C_L_IVS;
T_L_RPS               *C_L_RPS;
TGroupBox             *C_GB;            // GroupBox, <=> �����
void                   NACH_USL_DVC();
UINT                   Tag;             // �����  �  �������  ������������  T_DVC
UINT                   P_H;             // �������� ����������� ����������, <=> �����
InstantDiCtrl         *C_instantDiCtrl; // �������. ������. ��� ���-��� ��-��, ���-�� � ���-�� ��� ����� DI ����� (static DI)
InstantDoCtrl         *C_instantDoCtrl; // �������. ������. ��� ���-��� ��-��, ���-�� � ���-�� ��� ����� DO ����� (static DO)
static  ICollection<DeviceTreeNode>  *C_supportedDevices_DI; // ��������� ����, ��������������  static DI
static  ICollection<DeviceTreeNode>  *C_supportedDevices_DO; // ��������� ����, ��������������  static DO
static  UINT           NumOfDevices;    // ���������� ����
					   T_DVC(const UINT& i);
virtual	              ~T_DVC();
void        __fastcall VIS_PAN(const UINT& DVC_VS_T_, const UINT& DVC_VS_CM_); // ������. ������� ����. ��� � ��� � ���. �� ����. <=> ���� T_DVC->P_H
static void __fastcall VIS_DVC();
static void __fastcall F_I(); // ����������� ����� ������ �������������
}; // class  T_DVC
unsigned int  T_DVC::K_PORT; // ���������� ����������� ���������� ��� ������
ICollection<DeviceTreeNode>*  T_DVC::C_supportedDevices_DI; // ��������� ����, ��������������  static DI
ICollection<DeviceTreeNode>*  T_DVC::C_supportedDevices_DO; // ��������� ����, ��������������  static DO
UINT                          T_DVC::NumOfDevices;          // ���������� ����
//---------------------------------------------------------------------------
// ���������� ����������� ���������� ��� ���� ������
FILE              *T_IVS::F_IVS_REZ; // ���������� �����������
AnsiString         T_IVS::P_IVS_REZ;
FILE              *T_IVS::F_IVS_GR;  // ���������� �������� ��� ����������� �������� ���
AnsiString         T_IVS::P_IVS_GR;
vector<T_I_NV_O>   T_IVS::IVS_NV;    // ������ ����������� �������� ��� (����� ������ ����������� ��� �����. ������ �������)
vector<T_R_NV_O>   T_RPS::RPS_NV;    // ������ ����������� �������� ��� (����� ������ ����������� ��� �����. ������ �������)
FILE              *T_RPS::F_RPS_REZ; // ���������� �����������
AnsiString         T_RPS::P_RPS_REZ;
FILE               *T_RPS::F_RPS_GR; // ���������� �������� ��� ����������� �������� ���
AnsiString          T_RPS::P_RPS_GR;
T_IR_NV_O::~T_IR_NV_O() {};
//---------------------------------------------------------------------------
#endif
