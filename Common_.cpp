#pragma hdrstop
#include "Common_.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ���
 T_IVS**              IVS_TS;
 T_L_IVS**            L_IVS_TS;     // ����� ��� �� �����
// ���
 T_RPS**              RPS_TS;
 T_L_RPS**            L_RPS_TS;     // ����� ��� �� �����
AnsiString            DIR_REZ;       // ������� � ������������ ��� � ���
// ������ � �������
 T_DVC**              DVC_TS;
 unsigned int         K_S;          // ���������� �������� ��� � ���
 TZColorStringGrid**  ZAV_TS;
// ��������� �����������
 AnsiString SEP;
// ����� �������������
DynamicArray< DynamicArray< AnsiString > > VR_P;
char PATH_[100];
FILE          *F_IVS;         // ���������� ��������
AnsiString     P_IVS;
FILE          *F_RPS;
AnsiString     P_RPS;
FILE          *F_NU;          // �����������
AnsiString     P_NU;
FILE          *F_NASTR;
AnsiString     P_NASTR;
UINT T_COL, T_ROW, T_COL_NSTR, T_ROW_NSTR;              // �������  �  ������  ��������������  ������
UINT        T_NIM;                                      // ����� TImage � ������� ������������ IVS_TS
// TChart
T_CH_L**       T_CH_L_TS;
unsigned int   K_CH;
// �����������
unsigned int   PR_CKL   = 0;      // ������� ���������� �����������
unsigned int   PR_TB_ZP = 0;      // ������� ������� ������������ ����� ���������
double  T_B_NU, U_DT_NC, T_NC;    // T ���. �� ��., ���. ������. ���. ����., ����� ������ �����������
double  KT_PRM_MAX, U_DT_KC;      // ������������ ������������ ������ �������� ��� ���������� �����������
// �������������� ������
String         ZCSG_FC, ZCSG_BGC;
//---------------------------------------------------------------------------
