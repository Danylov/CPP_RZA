#pragma hdrstop
#include "IVS_RPS_.h"
#include "U_F_CH_.h"
#include "U_CKL_.h"
#include "Common_.h"
#include "U_F_CH_IR_.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
unsigned int RGP = 15; // ���������� �� �������� ���� ������ �� �������� ���� ��������
//---------------------------------------------------------------------------
T_IVS::T_IVS(const UINT& N_IVS, TGroupBox* const C_GBX) // �����-� ��. �� �������. ������
{
/*1.*/ if (N_IVS == 0)
{ // ������ � 1
C_PNL        = F_IK->PNL_IVS_1;
C_CHB        = F_IK->CHB_IVS_1;
C_E_NM       = F_IK->E_IVS_NM_1;
C_IM         = F_IK->IM_IVS_I_1;
C_B_SS       = F_IK->B_IVS_SS_1;
C_E_NS       = F_IK->E_IVS_NS_1;
C_E_DS       = F_IK->E_IVS_DS_1;
C_TM         = F_IK->TM_IVS_1;
} // 1.
/*2.*/ else
{ // ������� �� 2 - N
C_PNL   = new TPanel(C_GBX);
C_CHB   = new TCheckBox(C_PNL);
C_E_NM  = new TEdit(C_PNL);
C_IM    = new TImage(C_PNL);
C_B_SS  = new TAdvToolButton(C_PNL);
C_E_DS  = new TEdit(C_PNL);
C_E_NS  = new TEdit(C_PNL);
C_TM    = new TZylTimer(C_PNL);
}; // 2.

/*3.*/ Tag              = N_IVS;
P_TM_EN                 = 0;

C_PNL->Parent           = C_GBX;
C_PNL->ParentFont       = false;
C_PNL->ParentColor      = false;
C_PNL->ParentBackground = false;
C_PNL->Name             = "PNL_IVS_" + UIntToStr(N_IVS + 1);
C_PNL->Caption          = "";
C_PNL->Color            = cl3DLight;
C_PNL->Height           = (C_GBX->ClientHeight - 66 - RGP) / 33;
C_PNL->Top              = RGP + (N_IVS % 32 + 1) * int((float(C_GBX->ClientHeight - RGP)) / 33.0);
C_PNL->ParentFont       = false;
C_PNL->Font->Size       = 12;
C_PNL->Font->Name       = "Times New Roman";
C_PNL->Font->Style      = TFontStyles() >> fsBold;
C_PNL->Tag              = N_IVS;

C_CHB->Parent   	= C_PNL;
C_CHB->Name         = "CHB_IVS_" + UIntToStr(N_IVS + 1);
C_CHB->Caption      = "";
C_CHB->Height       = C_PNL->ClientHeight / 2;
C_CHB->Top          = C_PNL->ClientHeight / 4;
C_CHB->Tag          = N_IVS;

C_E_NM->Parent      = C_PNL;
C_E_NM->Name        = "E_NM_IVS_" + UIntToStr(N_IVS + 1);
C_E_NM->Height      = C_PNL->ClientHeight - 2;
C_E_NM->Top         = 1;
C_E_NM->AutoSize    = false;
C_E_NM->Alignment   = taCenter;
C_E_NM->ParentFont  = false;
C_E_NM->Font->Size  = 12;
C_E_NM->Font->Name  = "Times New Roman";
C_E_NM->Font->Style = TFontStyles() >> fsBold;
C_E_NM->ReadOnly    = true;
C_E_NM->Text        = UIntToStr(N_IVS + 1);
C_E_NM->Tag         = N_IVS;

C_IM->Parent       = C_PNL;
C_IM->Name         = "IM_IVS_" + UIntToStr(N_IVS + 1);
C_IM->AutoSize     = false;
C_IM->Proportional = false;
C_IM->Center       = true;
C_IM->Stretch      = true;
C_IM->Height       = C_PNL->ClientHeight - 2;
C_IM->Top          = 1;
C_IM->Tag          = N_IVS;
C_IM->PopupMenu    = F_IK->PUM_IM;
C_IM->OnMouseDown  = F_IK->IM_IVS_I_1MouseDown;

C_B_SS->Parent         = C_PNL;
C_B_SS->Name           = "B_SS_IVS_" + UIntToStr(N_IVS + 1);
C_B_SS->Height         = C_PNL->ClientHeight - 4;
C_B_SS->Top            = 2;
C_B_SS->GroupIndex     = N_IVS + 1;
C_B_SS->AllowAllUp     = true;
C_B_SS->Color          = clGray;
C_B_SS->ColorTo        = clGray;
C_B_SS->ColorChecked   = clLime;
C_B_SS->ColorCheckedTo = clLime;
C_B_SS->Down           = false;
C_B_SS->Tag            = N_IVS;
C_B_SS->OnClick        = F_IK->B_IVS_SS_1Click;
IZM_SOST_KN(3);

C_E_DS->Parent       = C_PNL;
C_E_DS->Name         = "E_IVS_DS_" + UIntToStr(N_IVS + 1);
C_E_DS->Text         = "0,0";
C_E_DS->Height       = C_PNL->ClientHeight - 2;
C_E_DS->Top          = 1;
C_E_DS->ParentFont   = false;
C_E_DS->Font->Style  = TFontStyles() >> fsBold;
C_E_DS->Font->Size   = 12;
C_E_DS->Font->Name   = "Times New Roman";
C_E_DS->Tag          = N_IVS;
C_E_DS->OnKeyDown    = F_IK->E_IVS_DS_1KeyDown;

C_E_NS->Parent       = C_PNL;
C_E_NS->Name         = "E_IVS_NS_" + UIntToStr(N_IVS + 1);
C_E_NS->Text         = "";
C_E_NS->Height       = C_PNL->ClientHeight - 2;
C_E_NS->Top          = 1;
C_E_NS->Tag          = N_IVS;
C_E_NS->ParentFont   = false;
C_E_NS->Font->Style  = TFontStyles() >> fsBold;
C_E_NS->Font->Size   = 12;
C_E_NS->Font->Name   = "Times New Roman";
C_E_NS->OnMouseMove  = F_IK->E_IVS_NS_1MouseMove;
C_E_NS->ReadOnly     = true;
C_E_NS->ShowHint     = true;

C_TM->Name           = "TM_IVS_" + UIntToStr(N_IVS + 1);
C_TM->Interval       = 0.01;
C_TM->Cycled         = true;
C_TM->Enabled        = (P_TM_EN == 1);
C_TM->Tag            = N_IVS;
C_TM->OnTimer        = F_IK->TM_IVS_1Timer;
C_TM->Tag            = N_IVS;

C_LS                    = NULL;
}; // T_IVS::T_IVS(const UINT& N_IVS, TGroupBox* const C_GBX)
//---------------------------------------------------------------------------
T_IVS::~T_IVS()
{
fclose(F_IVS_REZ);
delete C_CHB;
delete C_E_NM;
delete C_IM;
delete C_B_SS;
delete C_E_DS;
delete C_E_NS;
delete C_TM;
delete C_PNL;
}; // T_IVS::~T_IVS
//---------------------------------------------------------------------------
void __fastcall T_IVS::ZAP_SRS() // ���������� ����� ������� ��� ����������� ������������
{
/*1.*/ if ((S_C_GR.SLCTN == 0) || (S_C_GR.GR == 6))  C_LS.reset(); // ������ ��� ����������� �� ������ ��� �� ����� ������ ��� ����������� (������� ����������� ������)
/*2.*/ else
{
/*2.1.*/ if (C_LS.get() == NULL)  C_LS = unique_ptr<TLineSeries>(new TLineSeries(F_CH_IR->CHL_IR[S_C_GR.GR]->C_Chart/*.get()*/));
/*2.2.*/ C_LS->ParentChart = F_CH_IR->CHL_IR[S_C_GR.GR]->C_Chart/*.get()*/;
C_LS->Title             = "��� � " + IntToStr(int(Tag + 1));
C_LS->XValues->DateTime = true;
C_LS->Clear();
C_LS->Color                = S_C_GR.CLR;
/*2.2.*/ for (int i = 0; i < IVS_NV.size(); i++)
{
/*2.2.1.*/ TDateTime TMP_DT = IVS_NV[i].get_D_T();     // �������� �������
		   UINT      TMP_ZN = IVS_NV[i].get_ZN_P(Tag); // �������� ������� � Tag (0 - ...) (�������� �������)
		   TDateTime TMP_DT_PRT;
           UINT      TMP_ZN_PRT, TMP_ZN_1;
/*2.2.2.*/ if (i == 0)  TMP_ZN_1 = 0;  // ���������� �������� ������� � Tag (0 - ...) (�������� �������)
/*2.2.3.*/ else         TMP_ZN_1 = IVS_NV[i-1].get_ZN_P(Tag);
/*2.2.4.*/ if (TMP_ZN_1 != TMP_ZN)
{
TMP_DT_PRT = TMP_DT - 0.01/3600/24;         // �������� ������� �� 10 ���������� �� ������� TMP_DT
TMP_ZN_PRT = 1 - TMP_ZN;                    // �������� ������� �� 10 ���������� �� ������� TMP_DT
C_LS->AddXY(TMP_DT_PRT, TMP_ZN_PRT);
}; // 2.2.4.
/*2.2.5.*/ C_LS->AddXY(TMP_DT, TMP_ZN);
}; // 2.2.
}; // 2.
} // void __fastcall T_IVS::ZAP_SRS()
//---------------------------------------------------------------------------
void __fastcall T_IVS::F_I() // ����������� ����� ������ �������������
{
P_IVS_REZ = DIR_REZ + "IVS.rez";
F_IVS_REZ = fopen(P_IVS_REZ.c_str(), "w+");
P_IVS_GR  = AnsiString(PATH_) + "\\IVS_GR.ini";
//F_IVS_GR  = fopen(P_IVS_GR.c_str(), "w+");
}; // void __fastcall T_IVS::F_I()
//---------------------------------------------------------------------------
void __fastcall T_IVS::F_V() // ����������� ����� ��������� ����������� ���
{
String TEMP_IVS  = P_IVS_REZ;
fclose(F_IVS_REZ);
ShellExecute(F_IK->Handle, L"open", L"notepad.exe", TEMP_IVS.w_str(), NULL, SW_SHOWNORMAL);
F_IVS_REZ = fopen(P_IVS_REZ.c_str(), "a+");
}; // void __fastcall T_IVS::F_V()
//---------------------------------------------------------------------------
void  __fastcall  T_IVS::IVS_GR_LD()
{
/*1.*/ if ((F_IVS_GR = fopen(P_IVS_GR.c_str(), "rt")) != NULL)
{
/*1.1.*/ FROMINI(P_IVS_GR);
/*1.2.*/ for (int i = 0; i < VR_P.Length; i++)
{
/*1.2.1.*/ if (VR_P.Length != K_S)
{
MessageDlg("���������� ����� �� ���������� ���������� � ����� IVS_GR.ini �� ������������� ���������� ��������", mtWarning, TMsgDlgButtons() << mbOK, 0);
break;
}; // 1.2.1.
/*1.2.2.*/ IVS_TS[i]->S_C_GR.SLCTN = StrToInt(VR_P[i][1]);         // 2: 0 - ������ ��� ����������� �� ������, 1 - ������
IVS_TS[i]->S_C_GR.CLR              = (TColor)StrToInt(VR_P[i][2]); // 3: ����  �����������  �������
IVS_TS[i]->S_C_GR.GR               = StrToInt(VR_P[i][3]);         // 4: ������  �����������  �������: 0 - "11", ...
}; // 1.2.
/*1.3.*/ fclose(F_IVS_GR);
}; // 1.
}; // void  __fastcall  T_IVS::IVS_GR_LD()
//---------------------------------------------------------------------------
void  __fastcall  T_IVS::IVS_GR_SV()
{
/*1.*/ if ((F_IVS_GR = fopen(P_IVS_GR.c_str(), "w+")) != NULL)
{
/*1.1.*/ for (int npp = 0; npp < K_S; npp++)
{
UINT        T_NPP   = IVS_TS[npp]->Tag + 1;      // 1: � ������� ���
UINT        T_SLCTN = IVS_TS[npp]->S_C_GR.SLCTN; // 2: ������ ��� ����������� �� ������, 1 - ������
UINT        T_CLR   = IVS_TS[npp]->S_C_GR.CLR;   // 3: ����  �����������  �������
UINT        T_GR    = IVS_TS[npp]->S_C_GR.GR;    // 4: �����  ������� �����������  ������� (0 - "11", ...)
fprintf(F_IVS_GR, " %5i %20i %20i %10i \n", T_NPP, T_SLCTN, T_CLR, T_GR);
}; // 1.1.
/*1.2.*/ fclose(F_IVS_GR);
}; // 2.
}; // void  __fastcall  T_IVS::IVS_GR_SV()
//---------------------------------------------------------------------------
T_I_NV_O::T_I_NV_O() // ����������� ������, ������������ ����� ������ ������� ����������� �������� ���
{
/*1.*/ D_T = Now();
/*2.*/ for (UINT i = 0; i < T_DVC::NumOfDevices; i++)
{
/*2.1.*/ UINT  ZN_P_TMP = 0;
/*2.2.*/ for (UINT j = 0; j < 32; j++)
{ // IVS_TS[j]->C_B_SS->Down - � ��� � j
/*2.2.1.*/ UINT k = 32 * i + j;
/*2.2.2.*/ if (IVS_TS[k]->C_B_SS->Down == true)  ZN_P_TMP |=  (1 << j); // ��������� ���� j
} // 2.2.
/*2.3.*/ ZN_P.push_back(ZN_P_TMP);
} // 2.
}; // T_I_NV_O::T_I_NV_O()
//---------------------------------------------------------------------------
TDateTime   T_IR_NV_O::get_D_T() // ���������� �������� �������
{
return  D_T;
}; // TDateTime   T_IR_NV_O::get_D_T()
//---------------------------------------------------------------------------
UINT   T_IR_NV_O::get_ZN_P(const int& N_S) // ���������� �������� ������� � N_S (0...)
{
const   UINT  N_P  = N_S / 32;                        // � ����� (0 - ...)
const   UINT  N_SP = N_S % 32;                        // � ������� ����� N_P (0 - ...)
UINT    ZN_S = (ZN_P[N_P] & ( 0x01 << N_SP)) >> N_SP; // �������� ������� � N_SP ����� � N_P
return  ZN_S;
}; // UINT   T_IR_NV_O::get_ZN_P(const int& N_S)
//---------------------------------------------------------------------------
T_I_NV_O::~T_I_NV_O()
{
ZN_P.clear();
} // T_I_NV_O::~T_I_NV_O()
//---------------------------------------------------------------------------
void  T_IVS::S_Z() // ������ ����� �������� ��� � ���� � ������ ����������� �������� ���
{
fprintf(F_IVS_REZ, " %30ls %5i %5i\n", D_T().c_str(), Tag + 1, int(C_B_SS->Down));
IVS_NV.push_back(T_I_NV_O());
}; // void  T_IVS::S_Z()
//---------------------------------------------------------------------------
void  T_IVS::IZM_SOST_KN(const int& Down_) // ���. ����. ��.: 0 - Down = 0; 1 - Down = 1; 2 - �������� Down; 3 - ��� ���.
{
/*1.*/ if (Down_ == 0)  C_B_SS->Down = false;
/*2.*/ if (Down_ == 1)  C_B_SS->Down = true;
/*3.*/ if (Down_ == 2)  C_B_SS->Down = !C_B_SS->Down;
/*4.*/ if  (C_B_SS->Down == true)
{
C_B_SS->ColorHot    = C_B_SS->ColorChecked;
C_B_SS->ColorHotTo  = C_B_SS->ColorChecked;
}
/*5.*/ else
{
C_B_SS->ColorHot    = C_B_SS->Color;
C_B_SS->ColorHotTo  = C_B_SS->Color;
C_B_SS->ColorDown   = C_B_SS->Color;
C_B_SS->ColorDownTo = C_B_SS->Color;
}; // 5.
}; // void  T_IVS::IZM_SOST_KN(const int& Down_)
//---------------------------------------------------------------------------
void  T_IVS::IN_KN_PL() // ��������� ��������� ������ ������ �� ��������� ��������� �� �����
{
IZM_SOST_KN(1);
}; // void  T_IVS::IN_KN_PL()
//---------------------------------------------------------------------------
void  T_IVS::IN_KN_INI() // ���������� ������ � ��������� ��������� ������ �� �������� � ����� ������������ IVS.ini
{
/*1.*/ IN_IM(); // �������� ����� ��������
/*2.*/ if ((C_B_SS->Down == true)  && (T_S == 0) ||  // ������ � ���������� ������
		  ((C_B_SS->Down == false) && (T_S == 1)))   // ������ � ���������� ������
{
/*2.1.*/ IZM_SOST_KN(2);
/*2.4.*/ NO_KN(0,0);
}; // 2.
}; // void  T_IVS::IN_KN_INI()
//---------------------------------------------------------------------------
void  T_IVS::NO_KN(const int& P_NIS, const int& I_D) // P_NIS = 1 - �������� � ��������, I_D = 1 - �������� Down
{ // �������-������� ��. � �������� ����������. ���������: 0 - �������, 1 - �������
/*1.*/ if (I_D == 0)  IZM_SOST_KN(3);  // �� ����������� Down
/*2.*/ else           IZM_SOST_KN(2);  // ����������� Down
/*3.*/ UINT  NM_TAG = C_E_NM->Tag;
UINT  T_PLATA =  NM_TAG / 32;                // �����
UINT  T_PORT  = (NM_TAG - T_PLATA * 32) / 8; // ����
UINT  T_KANAL =  NM_TAG %  8;                // �����

/*5.*/ if (C_B_SS->Down == true) // �������  ��  ������
{
/*5.1.*/ DVC_TS[T_PLATA]->C_CH[T_PORT].UpdateLED(DVC_TS[T_PLATA]->C_instantDoCtrl, T_KANAL, 1);
/*5.2.*/ if ((0 < P_NIS) && (1.0E-5 < F_DS))
{
/*5.2.1.*/ if (T_S == 0) // T_S: 0 - ������ "0 -> 1", 1 - ������ "1 -> 0"
{
N_VR                         = SSTM();
P_TM_EN                      = 1;
C_TM->Enabled                = true;
RPS_TS[NM_TAG]->C_E_DS->Text = "";
} // 5.2.1.
/*5.2.2.*/ else  P_TM_EN     = 0;
}; // 5.2.
/*5.3.*/ S_Z(); // ������ ����� �������� ��� � ���� � ������ ����������� �������� ���
}  // 5.
/*6.*/ else                      // �������  ������
{
/*6.1.*/ DVC_TS[T_PLATA]->C_CH[T_PORT].UpdateLED(DVC_TS[T_PLATA]->C_instantDoCtrl, T_KANAL, 0);
/*6.2.*/ if ((0 < P_NIS) && (1.0E-5 < F_DS))
{
/*6.2.1.*/ if (T_S == 1) // T_S: 0 - ������ "0 -> 1", 1 - ������ "1 -> 0"
{
N_VR                         = SSTM();
P_TM_EN                      = 1;
C_TM->Enabled                = true;
RPS_TS[NM_TAG]->C_E_DS->Text = "";
} // 6.2.1.
/*6.2.2.*/ else  P_TM_EN     = 0;
}; // 6.2.
/*6.3.*/ S_Z(); // ������ ����� �������� ��� � ���� � ������ ����������� �������� ���
}; // 6.
/*7.*/ if (P_H == 1)
{
C_B_SS->Hide();
C_B_SS->Show();
}; // 7.
}; // void  T_IVS::NO_KN(const int& P_NIS, const int& I_D)
//---------------------------------------------------------------------------
void  T_IVS::IN_IM() // �������� ����� ��������
{
/*1.*/ if (T_S == 0)
{
/*1.1.*/ if (1.0E-5 < F_DS)  F_IK->IL_IVS->GetBitmap(2, C_IM->Picture->Bitmap);  // 0-1-0
/*1.2.*/ else                F_IK->IL_IVS->GetBitmap(0, C_IM->Picture->Bitmap);  // 0-1
} // 1.
/*2.*/ else
{
/*2.1.*/ if (1.0E-5 < F_DS)  F_IK->IL_IVS->GetBitmap(3, C_IM->Picture->Bitmap);  // 1-0-1
/*2.2.*/ else                F_IK->IL_IVS->GetBitmap(1, C_IM->Picture->Bitmap);  // 1-0
}; // 2.
C_IM->Invalidate(); // ��������������
}; // void  T_IVS::IN_IM()
//---------------------------------------------------------------------------
void  T_IVS::PRM(const UINT&  P_KT_PRM) // ������������ ����������� ������� ��������� �������� ��������
{
/*1.*/ SDT_PRM = 0.0;  // ����� ����������� ������� ��������� ��������
/*2.*/ for (int i = 0; i < 6; i++)
{
PRM_I[i].DT_PRM  = StrToFloat(F_CKL->SG_IK_NU->Cells[3 + i][Tag + 1]);
SDT_PRM         += PRM_I[i].DT_PRM;
}; // 2.
/*3.*/ if (1.0E-5 < SDT_PRM)
{
PRM_I[0].DT_PRM += U_DT_NC;
SDT_PRM         += U_DT_NC;
}; // 3.
/*2.*/ if (0 < P_KT_PRM)
{
/*2.1.*/ for (int i = 0; i < 6; i++)
{ // ����� ��������� ������� ���������� ������������ ������� ��������� ��������
/*2.1.1.*/ if  (i == 0) PRM_I[i].KT_PRM  = SSTM()   + PRM_I[i].DT_PRM;
/*2.1.2.*/ else         PRM_I[i].KT_PRM  = PRM_I[i-1].KT_PRM + PRM_I[i].DT_PRM;
PRM_I[i].P_ZAV = 0;
}; // 2.1.
}; // 2.
 // ������� ������������� �������������� ����� ��������� ������� ����������
/*3.*/ PRM_I[0].P_PRM = ((1.0E-5 < PRM_I[0].DT_PRM)  && ((1.0E-5 < PRM_I[1].DT_PRM) || (PRM_I[2].DT_PRM < 1.0E-5)));
	   PRM_I[1].P_PRM = ((1.0E-5 < PRM_I[1].DT_PRM)  && ((1.0E-5 < PRM_I[2].DT_PRM) || (PRM_I[3].DT_PRM < 1.0E-5)));
	   PRM_I[2].P_PRM = ((1.0E-5 < PRM_I[2].DT_PRM)  && ((1.0E-5 < PRM_I[3].DT_PRM) || (PRM_I[4].DT_PRM < 1.0E-5)));
	   PRM_I[3].P_PRM = ((1.0E-5 < PRM_I[3].DT_PRM)  && ((1.0E-5 < PRM_I[4].DT_PRM) || (PRM_I[5].DT_PRM < 1.0E-5)));
	   PRM_I[4].P_PRM =  (1.0E-5 < PRM_I[4].DT_PRM);
	   PRM_I[5].P_PRM =  (1.0E-5 < PRM_I[5].DT_PRM);
}; // void  T_IVS::PRM(const UINT&  P_KT_PRM)
//---------------------------------------------------------------------------
void  T_IVS::NVC() // ��������, ����������� ����� ����������� �����������
{
/*1.*/ int C_2 = StrToInt(F_CKL->SG_IK_NU->Cells[2][Tag + 1]);
/*2.*/ if ((PRM_I[0].DT_PRM < 1.0E-5) && (1.0E-5 <= PRM_I[1].DT_PRM))  C_2 = 1 - C_2;
/*3.*/ if ((C_2 == 0) && (C_B_SS->Down == true) || (C_2 == 1) && (C_B_SS->Down == false))     NO_KN(0,1);
/*4.*/ PRM(1);
}; // void  T_IVS::NVC()
//---------------------------------------------------------------------------
void  T_IVS::P_G_C_IVS(const UINT&  N_CH_) // ���������� ������� ����������� ���������� ���
{
/*1.*/ C_LS_CKL =  new TLineSeries(T_CH_L_TS[N_CH_]->C_Chart);
C_LS_CKL->ParentChart    = T_CH_L_TS[N_CH_]->C_Chart;
C_LS_CKL->LinePen->Width = 3;
C_LS_CKL->Clear();
PRM(0);
float  T_X = 0.0;
unsigned int  T_Y = StrToInt(F_CKL->SG_IK_NU->Cells[2][Tag + 1]);
C_LS_CKL->AddXY(T_X, T_Y, "", clRed);
/*2.*/ for (int i = 0; i < 6; i++)
{
/*2.1.*/ if (PRM_I[i].P_PRM == 1)
{
T_X = T_X + PRM_I[i].DT_PRM;
C_LS_CKL->AddXY(T_X, T_Y, "", clRed);
T_X = T_X + 0.00001;
T_Y = 1 - T_Y;
C_LS_CKL->AddXY(T_X, T_Y, "", clRed);
} // 2.1.
/*2.2.*/ else  T_X = T_X + PRM_I[i].DT_PRM;
}; // 2.
/*3.*/ T_X = T_X + 0.5;
C_LS_CKL->AddXY(T_X, T_Y, "", clRed);
T_CH_L_TS[N_CH_]->C_Chart->AddSeries(C_LS_CKL);
}; // void  T_IVS::P_G_C_IVS(const UINT&  N_CH_)
//---------------------------------------------------------------------------
void  T_IVS::VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_) // ������������ ������ ������� ���
{
C_PNL->Width   = (DVC_TS[DVC_Tag]->C_GB->ClientWidth - 2 * RKG_ - RIR_) / 2;
C_PNL->Left    = RKG_;
C_CHB->Width   = C_PNL->ClientHeight / 2;
C_CHB->Left    = 3;
C_E_NM->Width  = 28;
C_E_NM->Left   = C_CHB->Left  + C_CHB->Width  + 2;
C_IM->Width    = 30;
C_IM->Left     = C_E_NM->Left + C_E_NM->Width + 2;
C_B_SS->Width  = 22;
C_B_SS->Left   = C_IM->Left   + C_IM->Width   + 2;
C_E_DS->Width  = 36;
C_E_DS->Left   = C_PNL->ClientWidth - C_E_DS->Width - 2;
C_E_NS->Width  = C_E_DS->Left - C_B_SS->Left  - C_B_SS->Width - 2;
C_E_NS->Left   = C_B_SS->Left + C_B_SS->Width + 2;
P_H            = (DVC_TS[DVC_Tag]->P_H & ( 0x01 << i_)) >> i_;
C_PNL->Visible = bool(P_H);
}; // void  T_IVS::VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_)
//---------------------------------------------------------------------------
T_RPS::T_RPS(const UINT& N_RPS, TGroupBox* const C_GBX)
{
/*1.*/ if (N_RPS == 0)
{
// ������ � 1
C_PNL          = F_IK->PNL_RPS_1;
C_E_NM         = F_IK->E_RPS_NM_1;
C_IM           = F_IK->IM_RPS_I_1;
C_CHB_I        = F_IK->CHB_RPS_I_1;
C_E_NS         = F_IK->E_RPS_NS_1;
C_E_DS         = F_IK->E_RPS_DS_1;
} // 1.
/*2.*/ else
{// ������� �� 2 - N
C_PNL    = new TPanel(C_GBX);
C_E_NM   = new TEdit(C_PNL);
C_IM     = new TImage(C_PNL);
C_CHB_I  = new TCheckBox(C_PNL);
C_E_DS   = new TEdit(C_PNL);
C_E_NS   = new TEdit(C_PNL);
}; // 2.

/*3.*/  Tag             = N_RPS;

C_PNL->Parent           = C_GBX;
C_PNL->ParentFont       = false;
C_PNL->ParentColor      = false;
C_PNL->ParentBackground = false;
C_PNL->Name             = "PNL_RPS_" + UIntToStr(N_RPS + 1);
C_PNL->Caption          = "";
C_PNL->Color            = cl3DLight;
C_PNL->Height           = (C_GBX->ClientHeight - 66 - RGP) / 33;
C_PNL->Top              = RGP + (N_RPS % 32 + 1) * int((float(C_GBX->ClientHeight - RGP)) / 33.0);
C_PNL->ParentFont       = false;
C_PNL->Font->Size       = 12;
C_PNL->Font->Name       = "Times New Roman";
C_PNL->Font->Style      = TFontStyles() >> fsBold;
C_PNL->Tag              = N_RPS;

C_E_NM->Parent      = C_PNL;
C_E_NM->Name        = "C_E_NM" + UIntToStr(N_RPS + 1);
C_E_NM->Text        = "";
C_E_NM->Height      = C_PNL->ClientHeight - 2;
C_E_NM->Top         = 1;
C_E_NM->Alignment   = taCenter;
C_E_NM->ReadOnly    = true;
C_E_NM->ParentFont  = false;
C_E_NM->Font->Size  = 12;
C_E_NM->Font->Name  = "Times New Roman";
C_E_NM->Font->Style = TFontStyles() >> fsBold;
C_E_NM->Text        = UIntToStr(N_RPS + 1);
C_E_NM->Tag         = N_RPS;

C_IM->Parent       = C_PNL;
C_IM->Name         = "C_IM" + UIntToStr(N_RPS + 1);
C_IM->AutoSize     = false;
C_IM->Proportional = false;
C_IM->Center       = true;
C_IM->Stretch      = true;
C_IM->Height       = C_PNL->ClientHeight - 4;
C_IM->Top          = 2;
C_IM->Tag          = N_RPS;
C_IM->OnMouseDown  = F_IK->IM_RPS_I_1MouseDown;

C_CHB_I->Parent    = C_PNL;
C_CHB_I->Name      = "C_CHB_I" + UIntToStr(N_RPS + 1);
C_CHB_I->Caption   = "";
C_CHB_I->Height    = C_PNL->ClientHeight / 2;
C_CHB_I->Top       = C_PNL->ClientHeight / 4;
C_CHB_I->Tag       = N_RPS;
C_CHB_I->OnClick   = F_IK->CHB_RPS_I_1Click;

C_E_DS->Parent       = C_PNL;
C_E_DS->Name         = "C_E_DS" + UIntToStr(N_RPS + 1);
C_E_DS->Text         = "";
C_E_DS->Height       = C_PNL->ClientHeight - 2;
C_E_DS->Top          = 1;
C_E_DS->ParentFont   = false;
C_E_DS->ReadOnly     = true;
C_E_DS->Font->Size   = 12;
C_E_DS->Font->Style  = TFontStyles() >> fsBold;
C_E_DS->Font->Name   = "Times New Roman";
C_E_DS->Tag          = N_RPS;

C_E_NS->Parent       = C_PNL;
C_E_NS->Name         = "C_E_NS" + UIntToStr(N_RPS + 1);
C_E_NS->Text         = "";
C_E_NS->Height       = C_PNL->ClientHeight - 2;
C_E_NS->Top          = 1;
C_E_NS->Tag          = N_RPS;
C_E_NS->OnMouseMove  = F_IK->E_IVS_NS_1MouseMove;
C_E_NS->ParentFont   = false;
C_E_NS->Font->Size   = 12;
C_E_NS->Font->Style  = TFontStyles() >> fsBold;
C_E_NS->Font->Name   = "Times New Roman";
C_E_NS->ReadOnly     = true;
C_E_NS->ShowHint     = true;

C_IVS                = NULL;

C_LS                    = NULL;

P_N1T  = 0;
SOST_X = 2;
IM_CANVAS(3);
PRM_NU = 0;
}; // T_RPS::T_RPS(const UINT& N_RPS, TGroupBox* const C_GBX)
//---------------------------------------------------------------------------
T_RPS::~T_RPS()
{
fclose(F_RPS_REZ);
delete C_E_NM;
delete C_IM;
delete C_CHB_I;
delete C_E_DS;
delete C_E_NS;
delete C_PNL;
}; // T_RPS::~T_RPS
//---------------------------------------------------------------------------
void __fastcall T_RPS::ZAP_SRS() // ���������� ����� ������� ��� ����������� ������������
{
/*1.*/ if ((S_C_GR.SLCTN == 0) || (S_C_GR.GR == 6))  C_LS.reset(); // ������ ��� ����������� �� ������ ��� �� ����� ������ ��� ����������� (������� ����������� ������)
/*2.*/ else
{
/*2.1.*/ if (C_LS.get() == NULL)  C_LS = unique_ptr<TLineSeries>(new TLineSeries(F_CH_IR->CHL_IR[S_C_GR.GR]->C_Chart/*.get()*/));
/*2.2.*/ C_LS->ParentChart = F_CH_IR->CHL_IR[S_C_GR.GR]->C_Chart/*.get()*/;
C_LS->Title             = "��� � " + IntToStr(int(Tag + 1));
C_LS->XValues->DateTime = true;
C_LS->Clear();
C_LS->Color                = S_C_GR.CLR;
/*2.2.*/ for (int i = 0; i < RPS_NV.size(); i++)
{
/*2.2.1.*/ TDateTime TMP_DT = RPS_NV[i].get_D_T();     // �������� �������
		   UINT      TMP_ZN = RPS_NV[i].get_ZN_P(Tag); // �������� ������� � Tag (0 - ...) (�������� �������)
		   TDateTime TMP_DT_PRT;
           UINT      TMP_ZN_PRT, TMP_ZN_1;
/*2.2.2.*/ if (i == 0)  TMP_ZN_1 = 0;  // ���������� �������� ������� � Tag (0 - ...) (�������� �������)
/*2.2.3.*/ else         TMP_ZN_1 = RPS_NV[i-1].get_ZN_P(Tag);
/*2.2.4.*/ if (TMP_ZN_1 != TMP_ZN)
{
TMP_DT_PRT = TMP_DT - 0.01/3600/24;         // �������� ������� �� 10 ���������� �� ������� TMP_DT
TMP_ZN_PRT = 1 - TMP_ZN;                    // �������� ������� �� 10 ���������� �� ������� TMP_DT
C_LS->AddXY(TMP_DT_PRT, TMP_ZN_PRT);
}; // 2.2.4.
/*2.2.5.*/ C_LS->AddXY(TMP_DT, TMP_ZN);
}; // 2.2.
}; // 2.
} // void __fastcall T_RPS::ZAP_SRS()
//---------------------------------------------------------------------------
void __fastcall T_RPS::F_I() // ����������� ����� ������ �������������
{
P_RPS_REZ = DIR_REZ + "RPS.rez";
F_RPS_REZ = fopen(P_RPS_REZ.c_str(), "w+");
P_RPS_GR  = AnsiString(PATH_) + "\\RPS_GR.ini";
//F_RPS_GR  = fopen(P_RPS_GR.c_str(), "w+");
}; // void __fastcall T_IVS::F_I()
//---------------------------------------------------------------------------
void __fastcall T_RPS::F_V() // ����������� ����� ��������� ����������� ���
{
String TEMP_RPS  = P_RPS_REZ;
fclose(F_RPS_REZ);
ShellExecute(F_IK->Handle, L"open", L"notepad.exe", TEMP_RPS.w_str(), NULL, SW_SHOWNORMAL);
F_RPS_REZ = fopen(P_RPS_REZ.c_str(), "a+");
}; // void __fastcall T_RPS::F_V()
//---------------------------------------------------------------------------
void  __fastcall  T_RPS::RPS_GR_LD()
{
/*1.*/ if ((F_RPS_GR = fopen(P_RPS_GR.c_str(), "rt")) != NULL)
{
/*1.1.*/ FROMINI(P_RPS_GR);
/*1.2.*/ for (int i = 0; i < VR_P.Length; i++)
{
/*1.2.1.*/ if (VR_P.Length != K_S)
{
MessageDlg("���������� ����� �� ���������� ���������� � ����� RPS_GR.ini �� ������������� ���������� ��������", mtWarning, TMsgDlgButtons() << mbOK, 0);
break;
}; // 1.2.1.
/*1.2.2.*/ RPS_TS[i]->S_C_GR.SLCTN = StrToInt(VR_P[i][1]);         // 2: 0 - ������ ��� ����������� �� ������, 1 - ������
RPS_TS[i]->S_C_GR.CLR              = (TColor)StrToInt(VR_P[i][2]); // 3: ����  �����������  �������
RPS_TS[i]->S_C_GR.GR               = StrToInt(VR_P[i][3]);         // 4: ������  �����������  �������: 0 - "11", ...
}; // 1.2.
/*1.3.*/ fclose(F_RPS_GR);
}; // 1.
}; // void  __fastcall  T_RPS::RPS_GR_LD()
//---------------------------------------------------------------------------
void  __fastcall  T_RPS::RPS_GR_SV()
{
/*1.*/ if ((F_RPS_GR = fopen(P_RPS_GR.c_str(), "w+")) != NULL)
{
/*1.1.*/ for (int npp = 0; npp < K_S; npp++)
{
UINT        T_NPP   = RPS_TS[npp]->Tag + 1;      // 1: � ������� ���
UINT        T_SLCTN = RPS_TS[npp]->S_C_GR.SLCTN; // 2: ������ ��� ����������� �� ������, 1 - ������
UINT        T_CLR   = RPS_TS[npp]->S_C_GR.CLR;   // 3: ����  �����������  �������
UINT        T_GR    = RPS_TS[npp]->S_C_GR.GR;    // 4: �����  ������� �����������  ������� (0 - "11", ...)
fprintf(F_RPS_GR, " %5i %20i %20i %10i \n", T_NPP, T_SLCTN, T_CLR, T_GR);
}; // 1.1.
/*1.2.*/ fclose(F_RPS_GR);
}; // 1.
}; // void  __fastcall  T_RPS::RPS_GR_SV()
//---------------------------------------------------------------------------
void  T_RPS::DTM()
{ // SOST: 1 - ���� ������ (�������); 2 - ��� �������, �� ������������ (������); 3 - ��� �������, ������������ (���).
/*1.*/ if ((C_CHB_I->Checked == false) &&  (SOST == 1) ||
		   (C_CHB_I->Checked == true)  && ((SOST == 2)))  C_E_DS->Text = "";
/*2.*/ if ((C_CHB_I->Checked == true)  &&  (SOST == 1) ||
		   (C_CHB_I->Checked == false) && ((SOST == 2)))
{
/*2.1.*/ if (SOST == 1)  C_E_DS->Font->Color = HEXToColor("177245"); // DT ���������� ������� - ������� (www.getcolor.ru)
/*2.2.*/ else            C_E_DS->Font->Color = HEXToColor("FF0000"); // DT   �������  ������� - ������� (www.getcolor.ru)
/*2.3.*/ if (1.0E-4 < DLT_VR)  C_E_DS->Text = FloatToStrF(DLT_VR, ffFixed, 1000, 2);
}; // 2.
}; // void  T_RPS::DTM()
//---------------------------------------------------------------------------
void  T_RPS::PNL_OBNOVL() // ������������ ������ � �������� �� ��� � ����������� �� �������� P_H
{
/*1.*/ C_IM->Hide();
C_IM->Picture->Bitmap->Assign(NULL);
// Sleep(5);
/*2.*/ switch(SOST)
{
case 1:  F_IK->IL_RPS->GetBitmap(2, C_IM->Picture->Bitmap); break; // Red
case 2:  F_IK->IL_RPS->GetBitmap(1, C_IM->Picture->Bitmap); break; // Yellow
case 3:  F_IK->IL_RPS->GetBitmap(0, C_IM->Picture->Bitmap); break; // Gray
}; // 2.
/*3.*/ C_PNL->Visible = bool(P_H);
/*4.*/ if (P_H == 1)
{
C_IM->Repaint();
C_IM->Show();
}; // 3.
}; // void  T_RPS::PNL_OBNOVL()
//---------------------------------------------------------------------------
T_R_NV_O::T_R_NV_O() // ����������� ������, ������������ ����� ������ ������� ����������� �������� ���
{
/*1.*/ D_T = Now();
/*2.*/ for (UINT i = 0; i < T_DVC::NumOfDevices; i++)
{
/*2.1.*/ UINT  ZN_P_TMP = 0;
/*2.2.*/ for (UINT j = 0; j < 32; j++)
{ // IVS_TS[j]->C_B_SS->Down - � ��� � j
/*2.2.1.*/ UINT k = 32 * i + j;
/*2.2.2.*/ if (RPS_TS[k]->SOST == 1)  ZN_P_TMP |=  (1 << j); // ��������� ���� j
} // 2.2.
/*2.3.*/ ZN_P.push_back(ZN_P_TMP);
} // 2.
}; // T_R_NV_O::T_R_NV_O()
//---------------------------------------------------------------------------
T_R_NV_O::~T_R_NV_O()
{
ZN_P.clear();
} // T_R_NV_O::~T_R_NV_O()
//---------------------------------------------------------------------------
void  T_RPS::IM_CANVAS(const UINT& PR_S) // ������� ������� ������� � �������� PR_S: 1 - ���� ������, 2 - ��� �������, 3 - ������������
{ // SOST, SOST_X: 1 - ���� ������ (�������); 2 - ��� �������, �� ������������ (������); 3 - ��� �������, ������������ (���).
/*1.*/ if ((SOST_X != 1) && (PR_S == 1))  SOST = 1; // ������ ��������
/*2.*/ if ((SOST_X == 1) && (PR_S == 2))  SOST = 2; // ������ �����, �� �� ��� ������������
/*3.*/ if ((SOST_X == 2) && (PR_S == 3))  SOST = 3; // ������������ ������������ �������
/*4.*/ if (SOST_X != SOST)
{
/*4.1.*/ if (P_H == 1)
{
C_IM->Hide();
C_IM->Picture->Bitmap->Assign(NULL);
}; // 4.1.
/*4.2.*/ if (SOST == 1)
{
/*4.2.1.*/ F_IK->IL_RPS->GetBitmap(2, C_IM->Picture->Bitmap);                // Red
/*4.2.2.*/ RPS_NV.push_back(T_R_NV_O()); // ������ ����� �������� ��� ������ ����������� �������� ���
fprintf(F_RPS_REZ, " %30ls %5i %5s\n",  D_T().c_str(), (Tag + 1), "1");
/*4.2.3.*/ if ((C_IVS != NULL) && (C_IVS->C_B_SS->Down == false))  C_IVS->NO_KN(1,1); // ��� -> ���
} // 4.2.
/*4.3.*/ if (SOST == 2)
{
F_IK->IL_RPS->GetBitmap(1, C_IM->Picture->Bitmap);                           // Yellow
RPS_NV.push_back(T_R_NV_O()); // ������ ����� �������� ��� ������ ����������� �������� ���
fprintf(F_RPS_REZ, " %30ls %5i %5s\n",  D_T().c_str(), (Tag + 1), "0");
}; // 4.3.
/*4.4.*/  if (SOST == 3)  F_IK->IL_RPS->GetBitmap(0, C_IM->Picture->Bitmap); // Gray
/*4.5.*/  if (P_H == 1)
{
//Sleep(1);
C_IM->Repaint();
C_IM->Show();
}; // 4.5.
/*4.6.*/ if ((SOST == 1) || (SOST == 2))
{
/*4.6.1.*/ if (P_N1T != 0)  DLT_VR = SSTM() - N_VR; // ���������� ������� ������� (����������) ������� ���
/*4.6.2.*/ else
{
DLT_VR = 0.0;
P_N1T  = 1;
}; // 4.6.2.
/*4.6.3.*/ N_VR = SSTM();
}; // 4.6.
/*4.7.*/ if ((PR_CKL == 1) && ((SOST == 1) || (SOST == 2)))
{
/*4.7.1.*/ if (PRMR.Length == 0)
{
/*4.7.1.1.*/ PRMR.Length++;
PRMR[(PRMR.Length - 1)].NT_PRM = 0.0; // ����� ������ �������� ���������� ������������ ������� ������ �����������
/*4.7.1.2.*/ if (SOST == 1)  PRMR[(PRMR.Length - 1)].ZN = 0; // �������� ������� �� 1 ����������
/*4.7.1.3.*/ else            PRMR[(PRMR.Length - 1)].ZN = 1;
}; // 4.7.1.
/*4.7.2.*/ PRMR.Length++;
PRMR[(PRMR.Length - 1)].NT_PRM = SSTM() - T_NC;
PRMR[(PRMR.Length - 2)].KT_PRM = PRMR[(PRMR.Length - 1)].NT_PRM - 0.0001;
/*4.7.3.*/ if (SOST == 1)  PRMR[(PRMR.Length - 1)].ZN = 1;   // �������� ������� �� 1 ����������
/*4.7.4.*/ else            PRMR[(PRMR.Length - 1)].ZN = 0;
}; // 4.7.
/*4.8.*/ DTM();
SOST_X = SOST;
}; // 4.
}; // void  T_RPS::IM_CANVAS(const UINT& PR_S)
//---------------------------------------------------------------------------
void  T_RPS::VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_) // ������������ ������ ������� ���
{
C_PNL->Width   = (DVC_TS[DVC_Tag]->C_GB->ClientWidth - 2 * RKG_ - RIR_) / 2;
C_PNL->Left    = RKG_ + RIR_ + C_PNL->ClientWidth;
C_E_NM->Width  = 28;
C_E_NM->Left   = 3;
C_IM->Width    = 22;
C_IM->Left     = C_E_NM->Left + C_E_NM->Width + 2;
C_CHB_I->Width = C_PNL->ClientHeight / 2;
C_CHB_I->Left  = C_PNL->ClientWidth - C_CHB_I->Width - 2;
C_E_DS->Width  = 35;
C_E_DS->Left   = C_CHB_I->Left - C_E_DS->Width - 2;
C_E_NS->Width  = C_E_DS->Left - C_IM->Left - C_IM->Width - 2;
C_E_NS->Left   = C_IM->Left   + C_IM->Width + 2;
P_H            = (DVC_TS[DVC_Tag]->P_H & ( 0x01 << i_)) >> i_;
PNL_OBNOVL();
}; // void  T_RPS::VIS(const UINT& DVC_Tag, const UINT& i_, const UINT& RKG_, const UINT& RIR_)
//---------------------------------------------------------------------------
T_L_IVS::T_L_IVS(const UINT& N_L_IVS, TGroupBox* const C_GBX)
{
// �������
C_PNL   = new TPanel(C_GBX);
C_L_CHB = new TLabel(C_GBX);
C_L_NM  = new TLabel(C_GBX);
C_L_IM  = new TLabel(C_GBX);
C_L_SS  = new TLabel(C_GBX);
C_L_DS  = new TLabel(C_GBX);
C_L_NS  = new TLabel(C_GBX);

C_PNL->Parent           = C_GBX;
C_PNL->ParentFont       = false;
C_PNL->ParentColor      = false;
C_PNL->ParentBackground = false;
C_PNL->Name             = "PNL_IVS_" + UIntToStr(100 + N_L_IVS);
C_PNL->Caption          = "";
C_PNL->Color            = cl3DLight;
C_PNL->Top              = RGP;
C_PNL->Height           = IVS_TS[0]->C_PNL->Height;
C_PNL->Tag              = N_L_IVS;

C_L_CHB->Parent  	 = C_PNL;
C_L_CHB->Name        = "L_CHB_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_CHB->Top         = 1;
C_L_CHB->Height      = IVS_TS[0]->C_E_NM->Height;
C_L_CHB->AutoSize    = false;
C_L_CHB->Layout      = tlCenter;
C_L_CHB->Alignment   = taCenter;
C_L_CHB->Caption     = "�";
C_L_CHB->Tag         = N_L_IVS;
C_L_CHB->Font->Style = TFontStyles() << fsBold;

C_L_NM->Parent  	 = C_PNL;
C_L_NM->Name         = "L_NM_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_NM->Top          = 1;
C_L_NM->Height       = IVS_TS[0]->C_E_NM->Height;
C_L_NM->AutoSize     = false;
C_L_NM->Layout       = tlCenter;
C_L_NM->Alignment    = taCenter;
C_L_NM->Caption      = "�";
C_L_NM->Tag          = N_L_IVS;
C_L_NM->Font->Style  = TFontStyles() << fsBold;

C_L_IM->Parent  	 = C_PNL;
C_L_IM->Name         = "L_IM_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_IM->Top          = 1;
C_L_IM->Height       = IVS_TS[0]->C_IM->Height;
C_L_IM->AutoSize     = false;
C_L_IM->Layout       = tlCenter;
C_L_IM->Alignment    = taCenter;
C_L_IM->Caption      = "���";
C_L_IM->Tag          = N_L_IVS;
C_L_IM->Font->Style  = TFontStyles() << fsBold;

C_L_SS->Parent  	 = C_PNL;
C_L_SS->Name         = "L_SS_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_SS->Top          = 1;
C_L_SS->Height       = IVS_TS[0]->C_B_SS->Height;
C_L_SS->AutoSize     = false;
C_L_SS->Layout       = tlCenter;
C_L_SS->Alignment    = taCenter;
C_L_SS->Caption      = "�/�";
C_L_SS->Tag          = N_L_IVS;
C_L_SS->Font->Style  = TFontStyles() << fsBold;

C_L_DS->Parent  	 = C_PNL;
C_L_DS->Name         = "L_DS_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_DS->Top          = 1;
C_L_DS->Height       = IVS_TS[0]->C_E_DS->Height;
C_L_DS->AutoSize     = false;
C_L_DS->Layout       = tlCenter;
C_L_DS->Alignment    = taCenter;
C_L_DS->Caption      = "��., �.";
C_L_DS->Tag          = N_L_IVS;
C_L_DS->Font->Style  = TFontStyles() << fsBold;

C_L_NS->Parent  	 = C_PNL;
C_L_NS->Name         = "L_NS_IVS_" + UIntToStr(N_L_IVS + 1);
C_L_NS->Top          = 1;
C_L_NS->Height       = IVS_TS[0]->C_E_NS->Height;
C_L_NS->AutoSize     = false;
C_L_NS->Layout       = tlCenter;
C_L_NS->Alignment    = taCenter;
C_L_NS->Caption      = "��������";
C_L_NS->Tag          = N_L_IVS;
C_L_NS->Font->Style  = TFontStyles() << fsBold;
}; // T_L_IVS::T_L_IVS(const UINT& N_L_IVS, TGroupBox* const C_GBX)
//---------------------------------------------------------------------------
void  T_L_IVS::VIS() // ������������ ������ �������� ���
{
C_PNL->Width       = IVS_TS[0]->C_PNL->Width;
C_PNL->Left        = IVS_TS[0]->C_PNL->Left;
C_L_CHB->Width     = IVS_TS[0]->C_CHB->Width;
C_L_CHB->Left      = IVS_TS[0]->C_CHB->Left;
C_L_NM->Width      = IVS_TS[0]->C_E_NM->Width;
C_L_NM->Left       = IVS_TS[0]->C_E_NM->Left;
C_L_IM->Left       = IVS_TS[0]->C_IM->Left;
C_L_IM->Width      = IVS_TS[0]->C_IM->Width;
C_L_SS->Width      = IVS_TS[0]->C_B_SS->Width;
C_L_SS->Left       = IVS_TS[0]->C_B_SS->Left;
C_L_DS->Width      = IVS_TS[0]->C_E_DS->Width;
C_L_DS->Left       = IVS_TS[0]->C_E_DS->Left;
C_L_NS->Width      = IVS_TS[0]->C_E_NS->Width;
C_L_NS->Left       = IVS_TS[0]->C_E_NS->Left;
}; // void  T_L_IVS::VIS()
//---------------------------------------------------------------------------
T_L_IVS::~T_L_IVS()
{
delete C_L_CHB;
delete C_L_NM;
delete C_L_IM;
delete C_L_SS;
delete C_L_DS;
delete C_L_NS;
delete C_PNL;
}; // T_L_IVS::~T_L_IVS()
//---------------------------------------------------------------------------
T_L_RPS::T_L_RPS(const UINT& N_L_RPS, TGroupBox* const C_GBX)
{
// �������
C_PNL     = new TPanel(C_GBX);
C_L_NM    = new TLabel(C_GBX);
C_L_IM    = new TLabel(C_GBX);
C_L_CHB_I = new TLabel(C_GBX);
C_L_DS    = new TLabel(C_GBX);
C_L_NS    = new TLabel(C_GBX);

C_PNL->Parent           = C_GBX;
C_PNL->ParentFont       = false;
C_PNL->ParentColor      = false;
C_PNL->ParentBackground = false;
C_PNL->Name             = "PNL_RPS_" + UIntToStr(100 + N_L_RPS);
C_PNL->Caption          = "";
C_PNL->Color            = cl3DLight;
C_PNL->Top              = RGP;
C_PNL->Height           = RPS_TS[0]->C_PNL->Height;
C_PNL->Tag              = N_L_RPS;

C_L_NM->Parent  	 = C_PNL;
C_L_NM->Name         = "L_NM_RPS_" + UIntToStr(N_L_RPS + 1);
C_L_NM->Top          = 1;
C_L_NM->Height       = RPS_TS[0]->C_E_NM->Height;
C_L_NM->AutoSize     = false;
C_L_NM->Layout       = tlCenter;
C_L_NM->Alignment    = taCenter;
C_L_NM->Caption      = "�";
C_L_NM->Tag          = N_L_RPS;
C_L_NM->Font->Style  = TFontStyles() << fsBold;

C_L_IM->Parent  	 = C_PNL;
C_L_IM->Name         = "L_IM_RPS_" + UIntToStr(N_L_RPS + 1);
C_L_IM->Top          = 1;
C_L_IM->Height       = RPS_TS[0]->C_IM->Height;
C_L_IM->AutoSize     = false;
C_L_IM->Layout       = tlCenter;
C_L_IM->Alignment    = taCenter;
C_L_IM->Caption      = " ��� ";
C_L_IM->Tag          = N_L_RPS;
C_L_IM->Font->Style  = TFontStyles() << fsBold;

C_L_CHB_I->Parent  	   = C_PNL;
C_L_CHB_I->Name        = "L_CHB_I_RPS_" + UIntToStr(N_L_RPS + 1);
C_L_CHB_I->Top         = 1;
C_L_CHB_I->Height      = C_L_IM->Height;
C_L_CHB_I->AutoSize    = false;
C_L_CHB_I->Layout      = tlCenter;
C_L_CHB_I->Alignment   = taCenter;
C_L_CHB_I->Caption     = "�";
C_L_CHB_I->Tag         = N_L_RPS;
C_L_CHB_I->Font->Style = TFontStyles() << fsBold;

C_L_DS->Parent  	 = C_PNL;
C_L_DS->Name         = "L_DS_RPS_" + UIntToStr(N_L_RPS + 1);
C_L_DS->Top          = 1;
C_L_DS->Height       = RPS_TS[0]->C_E_DS->Height;
C_L_DS->AutoSize     = false;
C_L_DS->Layout       = tlCenter;
C_L_DS->Alignment    = taCenter;
C_L_DS->Caption      = "��., �.";
C_L_DS->Tag          = N_L_RPS;
C_L_DS->Font->Style  = TFontStyles() << fsBold;

C_L_NS->Parent  	 = C_PNL;
C_L_NS->Name         = "L_NS_RPS_" + UIntToStr(N_L_RPS + 1);
C_L_NS->Top          = 1;
C_L_NS->Height       = RPS_TS[0]->C_E_NS->Height;
C_L_NS->AutoSize     = false;
C_L_NS->Layout       = tlCenter;
C_L_NS->Alignment    = taCenter;
C_L_NS->Caption      = "��������";
C_L_NS->Tag          = N_L_RPS;
C_L_NS->Font->Style  = TFontStyles() << fsBold;
}; // T_L_RPS::T_L_RPS(const UINT& N_L_RPS, TGroupBox* const C_GBX)
//---------------------------------------------------------------------------
void  T_L_RPS::VIS() // ������������ ������ �������� ���
{
C_PNL->Width       = RPS_TS[0]->C_PNL->Width;
C_PNL->Left        = RPS_TS[0]->C_PNL->Left;
C_L_NM->Width      = RPS_TS[0]->C_E_NM->Width;
C_L_NM->Left       = RPS_TS[0]->C_E_NM->Left;
C_L_IM->Width      = RPS_TS[0]->C_IM->Width + 5;
C_L_IM->Left       = RPS_TS[0]->C_IM->Left;
C_L_CHB_I->Left    = RPS_TS[0]->C_CHB_I->Left;
C_L_CHB_I->Width   = RPS_TS[0]->C_CHB_I->Width;
C_L_DS->Width      = RPS_TS[0]->C_E_DS->Width;
C_L_DS->Left       = RPS_TS[0]->C_E_DS->Left;
C_L_NS->Width      = RPS_TS[0]->C_E_NS->Width;
C_L_NS->Left       = RPS_TS[0]->C_E_NS->Left;
}; // void  T_L_RPS::VIS()
//---------------------------------------------------------------------------
T_L_RPS::~T_L_RPS()
{
delete C_L_NM;
delete C_L_IM;
delete C_L_CHB_I;
delete C_L_DS;
delete C_L_NS;
delete C_PNL;
}; // T_L_RPS::~T_L_RPS()
//---------------------------------------------------------------------------
T_CH::T_CH()
{
}; // T_CH::T_CH
//---------------------------------------------------------------------------
T_CH::~T_CH()
{
}; // T_CH::~T_CH
//---------------------------------------------------------------------------
void  T_CH::UpdateLED(InstantDoCtrl *C_T_instantDoCtrl, const UINT&  kanal, const UINT&  mode)
{
uint8  state;
// instantDoCtrl �������. ������. ��� ���-��� ��-��, ���-�� � ���-�� ��� ����� DO ��������� ����� (static DO)
// state  - ��������� �����
 ErrorCode    ret   = Success;
 ret = C_T_instantDoCtrl->Read(N_PORT, state);  // �������� ������ ������ �� ����� N_PORT � state
 F_IK->CheckError(ret);

/*1.*/ if (mode == 1)  state |=   0x01 << kanal;  // ��������� ����
/*2.*/ else            state &= ~(0x01 << kanal); // �����     ����

 ret = Success;
 ret = C_T_instantDoCtrl->Write(N_PORT, state); // ������ state � ���� N_PORT
 F_IK->CheckError(ret);
}; // void  T_CH::UpdateLED(const InstantDoCtrl *C_T_instantDoCtrl, const UINT&  bit, const UINT&  mode)
//---------------------------------------------------------------------------
void  T_CH::NACH_USL_PORT(byte  *portState)
{
unsigned int N_KN;
/*3.*/   if (*portState & 0x01)  {N_KN = 32 * N_DVC + 8 * N_PORT;      IVS_TS[N_KN]->IN_KN_PL(); }; // 3.
/*4.*/   if (*portState & 0x02)  {N_KN = 32 * N_DVC + 8 * N_PORT + 1;  IVS_TS[N_KN]->IN_KN_PL(); }; // 4.
/*5.*/   if (*portState & 0x04)  {N_KN = 32 * N_DVC + 8 * N_PORT + 2;  IVS_TS[N_KN]->IN_KN_PL(); }; // 5.
/*6.*/   if (*portState & 0x08)  {N_KN = 32 * N_DVC + 8 * N_PORT + 3;  IVS_TS[N_KN]->IN_KN_PL(); }; // 6.
/*7.*/   if (*portState & 0x10)  {N_KN = 32 * N_DVC + 8 * N_PORT + 4;  IVS_TS[N_KN]->IN_KN_PL(); }; // 7.
/*8.*/   if (*portState & 0x20)  {N_KN = 32 * N_DVC + 8 * N_PORT + 5;  IVS_TS[N_KN]->IN_KN_PL(); }; // 8.
/*9.*/   if (*portState & 0x40)  {N_KN = 32 * N_DVC + 8 * N_PORT + 6;  IVS_TS[N_KN]->IN_KN_PL(); }; // 9.
/*10.*/  if (*portState & 0x80)  {N_KN = 32 * N_DVC + 8 * N_PORT + 7;  IVS_TS[N_KN]->IN_KN_PL(); }; // 10.
}; // void  T_CH::NACH_USL_PORT(byte  *portState)
//---------------------------------------------------------------------------
void  T_DVC::NACH_USL_DVC()
{ // portStates - ��������� ������, ���������� � ���������� ��������� ���������� (instantDiCtrl->Read(...))
// ������ ��������� portStates � ��� �������� ����� ������ ����. ������� �������. ������, ���������� � ������� new
/*1.*/ byte  *portStates = new byte[K_PORT];
// ������ ������� �� K_PORT ������, ������� � ����� � 0 � ������ ��������� ������ � portStates
ErrorCode ret = C_instantDiCtrl->Read(0, K_PORT, portStates);
F_IK->CheckError(ret);
// ���������� ����������� ������ � ��������� ������ ����� �� ������ ������� ���������
/*2.*/ for (UINT j = 0; j < K_PORT; j++)  C_CH[j].NACH_USL_PORT(portStates+j);
/*3.*/ delete[]  portStates;
}; // void  T_DVC::NACH_USL_DVC()
//---------------------------------------------------------------------------
T_DVC::T_DVC(const UINT& i)
{/*1.*/ C_instantDiCtrl = AdxInstantDiCtrlCreate();
		C_instantDoCtrl = AdxInstantDoCtrlCreate();
DVC_DI                  = C_supportedDevices_DI->getItem(i);
DVC_DO                  = C_supportedDevices_DO->getItem(i);
N_DVC                   = i /*DVC_DI.DeviceNumber*/;
ErrorCode           ret = Success;
DeviceInformation   devInfo_DI(DVC_DI.Description);
ret = C_instantDiCtrl->setSelectedDevice(devInfo_DI);
F_IK->CheckError(ret);
DeviceInformation   devInfo_DO(DVC_DO.Description);
ret = C_instantDoCtrl->setSelectedDevice(devInfo_DO);
F_IK->CheckError(ret);
C_CH       = new T_CH[K_PORT];
/*2.*/ if (i == 0)  C_GB = F_IK->GB_PL_1;
/*3.*/ else         C_GB = new TGroupBox(F_IK->PC_IK_TS1);
/*4.*/ C_GB->Parent      = F_IK->PC_IK_TS1;
C_GB->Font->Color = clBlack;
C_GB->Font->Style = TFontStyles() << fsBold;
C_GB->Caption     = "����� � " + UIntToStr(UINT(N_DVC + 1));
C_GB->Top         = 0;
C_GB->Height      = F_IK->PC_IK_TS1->ClientHeight - 5;
/*5.*/ for (int j = 0; j < K_PORT; j++)
{
C_CH[j].N_DVC  = N_DVC;
C_CH[j].N_PORT = j;
}; // 5.
/*6.*/ for (int k = 0; k < 32; k++)
{
unsigned int  l = 32 * N_DVC + k;
IVS_TS[l] = new T_IVS(l, C_GB);
RPS_TS[l] = new T_RPS(l, C_GB);
C_DIVS[k] = IVS_TS[l];
C_DRPS[k] = RPS_TS[l];
}; // 6.
/*7.*/ L_IVS_TS[i]   = new T_L_IVS(i, C_GB);
	   C_L_IVS       = L_IVS_TS[i];
	   L_RPS_TS[i]   = new T_L_RPS(i, C_GB);
	   C_L_RPS       = L_RPS_TS[i];
	   Tag           = i;
	   P_H           = 0;
	   NACH_USL_DVC();
}; // T_DVC::T_DVC(const UINT& i)
//---------------------------------------------------------------------------
T_DVC::~T_DVC()
{
/*1.*/ for (int k = 0; k < K_PORT; k++)  {delete[] C_CH;};
/*2.*/ C_instantDiCtrl->Dispose();   // ����������� ���������� instantDiCtrl
       C_instantDoCtrl->Dispose();   // ����������� ���������� instantDoCtrl
/*3.*/ if (N_DVC != 0)  {delete C_GB;};
}; // T_DVC::~T_DVC
//---------------------------------------------------------------------------
void __fastcall T_DVC::VIS_PAN(const UINT& DVC_VS_T_, const UINT& DVC_VS_CM_) // �����. P_H � ������. ������� ����. ��� � ��� � ���. �� ����. <=> ���� T_DVC->P_H
{ // DVC_VS_T_ - ����� ������� DVC ����� ��������������� DVC, DVC_VS_CM_ - ����� ���������� ��������������� DVC.
/*1.*/ unsigned int RFG =  5; // ���������� �� ���� ����� �� GroupBox
	   unsigned int RGG = 10; // ���������� ����� GroupBox
	   unsigned int RKG =  5; // ���������� �� ���� GroupBox �� ������� ��� (���)
	   unsigned int RIR = 10; // ���������� ����� ��������� ��� � ���
/*2.*/ if (DVC_VS_CM_ == 0) C_GB->Width = 0;
/*3.*/ else                 C_GB->Width = (F_IK->PC_IK_TS1->ClientWidth - 2 * RFG - (DVC_VS_CM_ - 1) * RGG) / DVC_VS_CM_;
C_GB->Left           = RFG + (DVC_VS_T_ - 1) * (RGG + C_GB->Width);
C_GB->Visible        = (0 < P_H);
/*2.*/ for (UINT i = 0; i < 32; i++)
{
IVS_TS[(32 * N_DVC + i)]->VIS(this->Tag, i, RKG, RIR);
RPS_TS[(32 * N_DVC + i)]->VIS(this->Tag, i, RKG, RIR);
}; // 2.
/*3.*/ C_L_IVS->VIS();
	   C_L_RPS->VIS();
}; // void __fastcall T_DVC::VIS_PAN(const UINT& DVC_VS_T_, const UINT& DVC_VS_CM_)
//---------------------------------------------------------------------------
void __fastcall T_DVC::VIS_DVC()
{
/*1.*/ if (F_IK->Tag < 2) // ���� �� ���������� ������� T_DVC (��. F_IK::FormDestroy(...))
{
/*1.1.*/ UINT DVC_VS_CM = 0; // ����� ���������� ��������������� DVC
   	     UINT DVC_VS_T  = 0; // ����� ������� DVC ����� ��������������� DVC
/*1.2.*/ for (UINT i = 0; i < NumOfDevices; i++)
{
/*1.2.1.*/ if (0 < DVC_TS[i]->P_H)  DVC_VS_CM++;
}; // 1.2.
/*1.3.*/ for (UINT i = 0; i < NumOfDevices; i++)
{
/*1.3.1.*/ if (0 < DVC_TS[i]->P_H)  DVC_VS_T++;
/*1.3.2.*/ DVC_TS[i]->VIS_PAN(DVC_VS_T, DVC_VS_CM);
}; // 1.3.
}; // 1.
}; // void __fastcall T_DVC::VIS_DVC()
//---------------------------------------------------------------------------
void __fastcall T_DVC::F_I() // ����������� ����� ������ �������������
{
InstantDiCtrl  *C_T_instantDiCtrl = AdxInstantDiCtrlCreate();
InstantDoCtrl  *C_T_instantDoCtrl = AdxInstantDoCtrlCreate();
// ��������� ����, �������������� static DI � static DO
C_supportedDevices_DI = C_T_instantDiCtrl->getSupportedDevices();
C_supportedDevices_DO = C_T_instantDoCtrl->getSupportedDevices();
// ���������� ����, �������������� static DI
NumOfDevices          = C_supportedDevices_DI->getCount();
// ���������� ������ � �����
ErrorCode           ret = Success;
DeviceInformation   devInfo_DI(C_supportedDevices_DI->getItem(0).Description);
ret = C_T_instantDiCtrl->setSelectedDevice(devInfo_DI);
F_IK->CheckError(ret);
K_PORT                = C_T_instantDiCtrl->getPortCount();
C_T_instantDiCtrl->Dispose();   // ����������� ���������� instantDiCtrl
C_T_instantDoCtrl->Dispose();   // ����������� ���������� instantDoCtrl
}; // void __fastcall T_DVC::F_I()
//---------------------------------------------------------------------------
