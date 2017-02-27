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
typedef struct // ���������� �������������� �������� ��� � �������� ���������� �����������
{
TChart*  C_Chart;
TLabel*  C_Label;
} T_CH_L;
//---------------------------------------------------------------------------
// ���
extern  T_IVS**              IVS_TS;
extern  T_L_IVS**            L_IVS_TS; // ����� ��� �� �����
// ���
extern  T_RPS**              RPS_TS;
extern  T_L_RPS**            L_RPS_TS; // ����� ��� �� �����
extern  AnsiString           DIR_REZ;  // ������� � ������������ ��� � ���
// ������ ��������
extern  T_DVC**              DVC_TS;
extern  unsigned int         K_S;      // ���������� �������� ��� � ���
extern  TZColorStringGrid**  ZAV_TS;
// ��������� �����������
extern  AnsiString SEP;
// ����� �������������
extern  DynamicArray< DynamicArray< AnsiString > > VR_P;
extern  char PATH_[100];
extern  FILE         *F_IVS;
extern  AnsiString    P_IVS;
extern  FILE         *F_RPS;
extern  AnsiString    P_RPS;
extern  FILE         *F_NU;  // �����������
extern  AnsiString    P_NU;
extern  FILE         *F_NASTR;
extern  AnsiString    P_NASTR;
extern  UINT T_COL, T_ROW, T_COL_NSTR, T_ROW_NSTR;      // �������  �  ������  ��������������  ������
extern  UINT          T_NIM;                            // ����� TImage � ������� ������������ IVS_TS
// TChart
extern  T_CH_L**      T_CH_L_TS;
extern  unsigned int  K_CH;
// �����������
extern  unsigned int  PR_CKL;           // ������� ���������� �����������
extern  unsigned int  PR_TB_ZP;         // ������� ������� ������������ ����� ���������
extern  double  T_B_NU, U_DT_NC, T_NC;  // T ���. �� ��., ���. ������. ���. ����., ����� ������ �����������
extern  double  KT_PRM_MAX, U_DT_KC;    // ������������ ������������ ������ �������� ��� ���������� �����������
// �������������� ������
extern  String       ZCSG_FC, ZCSG_BGC;
//---------------------------------------------------------------------------
#endif
