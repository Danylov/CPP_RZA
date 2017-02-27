#include <vcl.h>
#include <dir.h>
#pragma hdrstop
#include "U_Interf_.h"
#include "StF_.h"
#include "U_Help_.h"
#include "U_TVS_.h"
#include "U_ZAV_.h"
#include "U_F_CH_.h"
#include "U_F_CH_NSTR_.h"
#include "U_F_CH_IR_.h"
#include "U_NSTR_.h"
#include "U_CKL_.h"
#include "Common_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvToolBtn"
#pragma link "ZylTimer"
#pragma link "AdvPanel"
#pragma link "AdvSplitter"
#pragma link "AdvMenus"
#pragma link "AdvScrollBox"
#pragma link "AdvToolBar"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TF_IK *F_IK;
//---------------------------------------------------------------------------
__fastcall TF_IK::TF_IK(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_IK::TF_IK(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_IK::FormCreate(TObject *Sender)
{
/*1.*/ Top    = 0;
	   Height = Screen->Height - 27;
	   Left   = 0;
	   Width  = Screen->Width;
DoubleBuffered       = true;
Application->HintPause     =   0/*100*/; // Миллисекунд
Application->HintHidePause =  3000;
SEP = FormatSettings.DecimalSeparator;
HorzScrollBar->Visible    = true;
VertScrollBar->Visible    = true;
AutoScroll                = true;
HorzScrollBar->ButtonSize = 3;
HorzScrollBar->Increment  = 1;
HorzScrollBar->Range      = ClientWidth - 10;
HorzScrollBar->Size       = 3;
HorzScrollBar->Style      = ssRegular;
HorzScrollBar->ThumbSize  = 3;
HorzScrollBar->Tracking   = true;
VertScrollBar->ButtonSize = 3;
VertScrollBar->Increment  = 1;
VertScrollBar->Range      = ClientHeight - 10;
VertScrollBar->Size       = 3;
VertScrollBar->Style      = ssRegular;
VertScrollBar->ThumbSize  = 3;
VertScrollBar->Tracking   = true;
ATB_IK->Left  = 0;
ATB_IK->Top   = 0;
PC_IK->Top    = ATB_IK->Top  + ATB_IK->Height;
PC_IK->Height = ClientHeight - ATB_IK->Top - ATB_IK->Height - HorzScrollBar->Size - 1;
PC_IK->Left   = 0;
PC_IK->Width  = ClientWidth;
// Пути
getcwd(PATH_, 100);
DIR_REZ = AnsiString(PATH_) + "\\REZ\\";
/*2.*/ if (!DirectoryExists(DIR_REZ))  CreateDir(DIR_REZ);
/*3.*/ T_IVS::F_I();
	   T_RPS::F_I();
}; // void __fastcall TF_IK::FormCreate(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::N_EXClick(TObject *Sender)
{
Application->Terminate();
}; // void __fastcall TF_IK::N_EXClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::N_ABOUTClick(TObject *Sender)
{
F_HELP->Show();
}; // void __fastcall TF_IK::N_ABOUTClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::FormDestroy(TObject *Sender)
{
/*1.*/ Tag = 2; // Объекты удалены, нельзф перерисовывать панели
TM_RPS->Enabled = false;
TM_CKL->Enabled = false;
MM_IK_IVS_SV->Click();
MM_IK_RPS_SV->Click();
// Сохранение параметров отображения графиков ИВС и РПС
T_IVS::IVS_GR_SV();
T_RPS::RPS_GR_SV();
/*2.*/ for (unsigned int i = 0; i < K_S; i++)
{
delete IVS_TS[i];
delete RPS_TS[i];
}; // 2.
/*3.*/ for (int i = 0; i < T_DVC::NumOfDevices; i++)
{
delete L_IVS_TS[i];
delete L_RPS_TS[i];
delete DVC_TS[i];
delete ZAV_TS[i];
}; // 3.
/*4.*/ delete[] IVS_TS;
delete[] RPS_TS;
delete[] L_IVS_TS;
delete[] L_RPS_TS;
//delete[] DeviceList;
delete[] DVC_TS;
delete[] ZAV_TS;
delete F_HELP;
delete F_TVS;
delete F_ZAV;
delete F_CH;
delete F_CH_IR;
delete F_CH_NSTR;
delete F_CKL;
delete F_NSTR;
}; // void __fastcall TF_IK::FormDestroy(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::B_IVS_SS_1Click(TObject *Sender)
{
/*1.*/ unsigned int Tag = ((TAdvToolButton*)(Sender))->Tag;
IVS_TS[Tag]->NO_KN(1,0);
IVS_TS[Tag]->C_CHB->Checked = false;
/*3.*/ for (unsigned int i = 0; i < K_S; i++)
{
/*3.1.*/ if (IVS_TS[i]->C_CHB->Checked == true)
{
IVS_TS[i]->NO_KN(1,1);
IVS_TS[i]->C_CHB->Checked = false;
}; // 3.1.
}; // 3.
/*4.*/ MM_IK_IVS_SVB->Caption = "&Выбрать все";
}; // void __fastcall TF_IK::B_IVS_SS_1Click(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::FormShow(TObject *Sender)
{
/*1.*/ if (Tag == 0)
{ // Создание панелей ИВС и РПС
/*1.1.*/ T_DVC::F_I();
/*1.2.*/ if (T_DVC::NumOfDevices == 0)
{
MessageBox(this->WindowHandle, String("Установите драйвера для плат Advantech").w_str(),
String("Warning Information").w_str(), MB_ICONWARNING);
exit(0);
} // 1.2.
/*1.3.*/ else  K_S = 32 * T_DVC::NumOfDevices;
/*1.4.*/ IVS_TS = new T_IVS*[K_S];
RPS_TS          = new T_RPS*[K_S];
L_IVS_TS = new T_L_IVS*[T_DVC::NumOfDevices];
L_RPS_TS = new T_L_RPS*[T_DVC::NumOfDevices];
DVC_TS   = new T_DVC*[T_DVC::NumOfDevices];
/*1.5.*/ for (int i = 0; i < T_DVC::NumOfDevices; i++)   DVC_TS[i] = new T_DVC(i);
// Открытие файла "IVS.ini", "RPS.ini"
/*1.6.*/ OD->Title    = "Укажите файл IVS.ini";
OD->FileName = "IVS.ini";
MM_IK_IVS_LD->Click();
OD->Title    = "Укажите файл RPS.ini";
OD->FileName = "RPS.ini";
MM_IK_RPS_LD->Click();
// Создание форм
F_HELP    = new TF_HELP(F_IK);     // Помощь
F_TVS     = new TF_TVS(F_IK);      // Тип  сигнала  ("0->1", "1->0", "0->1->0", "1->0->1")
F_ZAV     = new TF_ZAV(F_IK);      // Соответствие "РПС->ИВС"
F_ZAV->F_ZAV_AFTERCREATE();
F_CH      = new TF_CH(F_IK);       // График  отображения сигнала  ИВС (удалить)
F_CH_IR   = new TF_CH_IR(F_IK);    // Графики отображения сигналов ИВС и РПС
F_CH_IR->F_CH_IR_AFTERCREATE();
F_CH_NSTR = new TF_CH_NSTR(F_IK);  // Настойка графиков отображения сигналов ИВС и РПС
F_CKL     = new TF_CKL(F_IK);      // Окно  циклограммы
SG_IK_COLS(0);
F_NSTR    = new TF_NSTR(F_IK);     // Настройка  (конфигурация)  программы
// Открытие файла "Nastr.ini"
NASTR_LD();
// Открытие файла "NU_CKL.ini"
NU_LD();
// Приведение кнопок в требуемое состояние исходя из значения в файле конфигурации IVS.ini
/*1.7.*/ for (UINT i = 0; i < K_S; i++)  IVS_TS[i]->IN_KN_INI();
/*1.8.*/ TM_RPS->Interval  = 0.01;
TM_RPS->Enabled   = true;
TM_CKL->Interval  = 0.01;
TM_CKL->Enabled   = false;
Tag               = 1;
}; // 1.
}; // void __fastcall TF_IK::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::TM_IVS_1Timer(TObject *Sender)
{
/*1.*/ UINT  Tag = ((TZylTimer*)Sender)->Tag;
IVS_TS[Tag]->C_TM->Enabled = false;
IVS_TS[Tag]->DLT_VR = SSTM() - IVS_TS[Tag]->N_VR;
/*2.*/ if (IVS_TS[Tag]->F_DS < IVS_TS[Tag]->DLT_VR)  IVS_TS[Tag]->NO_KN(1,1);
/*3.*/ IVS_TS[Tag]->C_TM->Enabled = (IVS_TS[Tag]->P_TM_EN == 1);
}; // void __fastcall TF_IK::TM_IVS_1Timer(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::E_IVS_DS_1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
/*1.*/ if (Key == VK_RETURN)
{
/*1.1.*/ for (unsigned int i = 0; i < K_S; i++)
{
IVS_TS[i]->F_DS = StrToFloat(RCD(IVS_TS[i]->C_E_DS->Text));
IVS_TS[i]->IN_IM();
}; // 1.1.
}; // 1.
}; // void __fastcall TF_IK::E_IVS_DS_1KeyDown(...)
//---------------------------------------------------------------------------
void __fastcall TF_IK::N_TClick(TObject *Sender)
{
F_TVS->Show();
}; // void __fastcall TF_IK::N_TClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::IM_IVS_I_1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*1.*/ if (Button == mbLeft)  ((TImage*)(Sender))->Repaint();
/*2.*/ if (Button == mbRight)
{
/*2.1.*/ T_NIM        = ((TImage*)(Sender))->Tag;
/*2.2.*/ N_T->Enabled = (IVS_TS[T_NIM]->P_TM_EN == 0);
/*2.3.*/ F_TVS->Top   = IVS_TS[T_NIM]->C_PNL->Top;
F_TVS->Left = IVS_TS[T_NIM]->C_PNL->Left + IVS_TS[T_NIM]->C_IM->Left + IVS_TS[T_NIM]->C_IM->Width + 20;
}; // 2.
}; // void __fastcall TF_IK::IM_IVS_I_1MouseDown(...)
//---------------------------------------------------------------------------
void __fastcall TF_IK::TM_CKLTimer(TObject *Sender)
{
TM_CKL->Enabled = false;
UINT    P_TM_CKL_EN = 1;
double  DT_VC       = KT_PRM_MAX - SSTM();
/*1.*/ if ((PR_CKL == 0) && (U_DT_NC <= (SSTM() - T_B_NU))) // Начало циклограммы
{
/*1.1.*/ PR_CKL = 1;
		 T_NC   = SSTM();
/*1.2.*/ for (int ns = 0; ns < K_S; ns++)  RPS_TS[ns]->PRM_NU = int(RPS_TS[ns]->SOST_X == 1); // Есть сигнал
/*1.3.*/ SG_IK_COLS(1); // Очистка таблицы результатов циклограммы
}; // 1.
/*2.*/ if (PR_CKL == 1)
{
/*2.1.*/ for (int ns = 0; ns < K_S; ns++)
{
/*2.1.1.*/ for (int np = 0; np < 6; np++)
{
/*2.1.1.1.*/ if ((IVS_TS[ns]->PRM_I[np].P_ZAV == 0) && (IVS_TS[ns]->PRM_I[np].KT_PRM < SSTM()))
{
/*2.1.1.1.1.*/ if  (IVS_TS[ns]->PRM_I[np].P_PRM == 1)  IVS_TS[ns]->NO_KN(0,1);
/*2.1.1.1.2.*/ IVS_TS[ns]->PRM_I[np].P_ZAV = 1;
}; // 2.1.1.1.
}; // 2.1.1.
}; // 2.1.
/*2.2.*/  if (KT_PRM_MAX < SSTM())
{
/*2.2.1.*/ unsigned int RPS_MKI = 0; // Максимальное количество интервалов по РПС в процессе реализации циклограммы
		   P_TM_CKL_EN          = 0;
		   PR_CKL               = 0;
		   MM_IK_CKL_V->Enabled = true;
/*2.2.2.*/ for (int ns = 0; ns < K_S; ns++)
{
/*2.2.2.1.*/ if (0 < RPS_TS[ns]->PRMR.Length)  RPS_TS[ns]->PRMR[(RPS_TS[ns]->PRMR.Length - 1)].KT_PRM = SSTM() - T_NC;
}; // 2.2.2.
/*2.2.3.*/ SG_IK_COLS(1);            // Визуализация результатов циклограммы
/*2.2.4.*/ for (int ns = 0; ns < K_S; ns++)  IVS_TS[ns]->C_B_SS->Enabled = true;
};  // 2.2.
}; // 2.
/*3.*/ String  Str = " " + FloatToStrF(DT_VC, ffFixed, 4, 1) + " с."; // Время до окончания циклограммы
/*4.*/ if (1E-2 < DT_VC)  F_CKL->E_DT_VC->Text = Str.w_str();
/*5.*/ else               F_CKL->E_DT_VC->Text = "";
/*6.*/ TM_CKL->Enabled = (P_TM_CKL_EN == 1);
}; // void __fastcall TF_IK::TM_CKLTimer(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::CHB_RPS_I_1Click(TObject *Sender)
{
unsigned int Tag = ((TCheckBox*)(Sender))->Tag;
/*1.*/ RPS_TS[Tag]->C_E_DS->Text = "";
RPS_TS[Tag]->DTM();
}; // void __fastcall TF_IK::CHB_RPS_I_1Click(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::IM_RPS_I_1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*1.*/ unsigned int Tag = ((TImage*)(Sender))->Tag;
/*2.*/ if (RPS_TS[Tag]->SOST_X == 2)   RPS_TS[Tag]->IM_CANVAS(3); // Признак наличия сигнала с контакта PR_S: 1 - есть сигнал, 2 - нет сигнала, 3 - квитирование
/*3.*/ else                            RPS_TS[Tag]->PNL_OBNOVL();
}; // void __fastcall TF_IK::IM_RPS_I_1MouseDown(...)
//---------------------------------------------------------------------------
void __fastcall TF_IK::E_IVS_NS_1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
((TEdit*)Sender)->Hint = ((TEdit*)Sender)->Text;
}; // void __fastcall TF_IK::E_IVS_NS_1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_EXClick(TObject *Sender)
{
Application->Terminate();
} // void __fastcall TF_IK::MM_PR_EXClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_SVClick(TObject *Sender)
{
/*1.*/ SV->InitialDir = P_IVS;
SV->Title      = "Укажите каталог сохранения файла IVS.ini";
SV->FileName   = "IVS.ini";
/*2.*/ if (SV->Execute())
{
/*2.1.*/ P_IVS = SV->FileName;
/*2.2.*/ if ((F_IVS = fopen(P_IVS.c_str(), "w+")) != NULL)
{
/*2.2.1.*/ for (int npp = 0; npp < K_S; npp++)
{
AnsiString  T_NM    = Trim(IVS_TS[npp]->C_E_NM->Text);  // 1    - Номер сигнала
int         T_C1    = IVS_TS[npp]->C_E_NS->Font->Color; // 2    - Цвет  текста
int         T_C2    = IVS_TS[npp]->C_E_NS->Color;       // 3    - Цвет  фона
AnsiString  T_DS    = Trim(IVS_TS[npp]->C_E_DS->Text);  // 4    - Длительность  сигнала
AnsiString  T_NS    = Trim(IVS_TS[npp]->C_E_NS->Text);  // 5... - Описание сигнала
fprintf(F_IVS, " %4s %5i %20i %20i %20s %50s \n", T_NM.c_str(), IVS_TS[npp]->T_S, T_C1, T_C2, T_DS.c_str(), T_NS.c_str());
}; // 2.2.1.
/*2.2.2.*/ fclose(F_IVS);
}  // 2.2.
}; // 2.
}
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_SVBClick(TObject *Sender)
{
/*1.*/ if (MM_IK_IVS_SVB->Caption.Pos("брать") == 0)
{
/*1.1.*/ for (int ns = 0; ns < K_S; ns++)  IVS_TS[ns]->C_CHB->Checked = false;
/*1.2.*/ MM_IK_IVS_SVB->Caption = "&Выбрать все";
} // 1.
/*2.*/ else
{
/*2.1.*/ for (int ns = 0; ns < K_S; ns++)
{
/*2.1.*/ if (IVS_TS[ns]->P_H == 1)         IVS_TS[ns]->C_CHB->Checked = true;
};
/*2.2.*/ MM_IK_IVS_SVB->Caption = "&Отменить выбор сигналов";
}; // 2.
}; // void __fastcall TF_IK::MM_IK_IVS_SVBClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_SKVClick(TObject *Sender)
{
/*1.*/ for (int ns = 0; ns < K_S; ns++)
{
/*1.1.*/ IVS_TS[ns]->P_CHB = int(IVS_TS[ns]->C_CHB->Checked == true);
}; // 1.
}; // void __fastcall TF_IK::MM_IK_IVS_SKVClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_ZKVClick(TObject *Sender)
{
/*1.*/ for (int ns = 0; ns < K_S; ns++)
{
/*1.1.*/ IVS_TS[ns]->C_CHB->Checked = (IVS_TS[ns]->P_CHB == 1);
}; // 1.
}; // void __fastcall TF_IK::MM_IK_IVS_ZKVClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_LDClick(TObject *Sender)
{
/*1.*/ OD->Title = "Укажите файл IVS.ini";
OD->FileName   ="IVS.ini";
/*2.*/ if (OD->Execute())
{
/*2.1.*/ P_IVS = OD->InitialDir + OD->FileName;
/*2.2.*/ if ((F_IVS = fopen(P_IVS.c_str(), "rt")) != NULL)
{
/*2.2.1.*/ FROMINI(P_IVS);
/*2.2.2.*/ for (int i = 0; i < VR_P.Length; i++)
{
/*2.2.2.1.*/ if (VR_P.Length != K_S)
{
MessageDlg("Количество строк со значениями параметров в файле IVS.ini не соответствует количеству сигналов", mtWarning, TMsgDlgButtons() << mbOK, 0);
break;
}; // 2.2.2.1.
/*2.2.2.2.*/ AnsiString  TMP_S = "";
IVS_TS[i]->T_S = StrToInt(VR_P[i][1]);                                             // 2    - Значение  сигнала
/*2.2.2.3.*/ IVS_TS[i]->C_E_NS->Font->Color = (TColor)StrToInt(VR_P[i][2]);        // 3    - Цвет  текста
/*2.2.2.4.*/ IVS_TS[i]->C_E_NS->Color       = (TColor)StrToInt(VR_P[i][3]);        // 4    - Цвет  фона
/*2.2.2.5.*/ if (Trim(VR_P[i][4]) == "(null)")  TMP_S = RCD("0.0");                // 5    - Длительность  сигнала
/*2.2.2.6.*/ else		                        TMP_S = RCD(VR_P[i][4]);
/*2.2.2.7.*/ IVS_TS[i]->C_E_DS->Text = TMP_S;
			 IVS_TS[i]->F_DS         = double(StrToFloat(TMP_S));
TMP_S = "";
/*2.2.2.8.*/  for (int j = 5; j < VR_P[i].Length; j++)  TMP_S = TMP_S + VR_P[i][j] + "  ";
/*2.2.2.9.*/  if (Trim(TMP_S) == "(null)")  IVS_TS[i]->C_E_NS->Text = "";          // 6... - Описание сигнала
/*2.2.2.10.*/ else                          IVS_TS[i]->C_E_NS->Text = Trim(TMP_S);
}; // 2.2.2.
/*2.2.3.*/ fclose(F_IVS);
}; // 2.2.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_IVS_LDClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_IVS_SClick(TObject *Sender)
{
/*1.*/ int TMP_ = MessageDlg("Подтвердите обнуление длительностей всех сигналов  ИВС", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*2.*/ if (TMP_ == mrYes)
{
/*2.1.*/ for (int nm = 0; nm < K_S; nm++)
{
IVS_TS[nm]->C_E_DS->Text = "0,0";
IVS_TS[nm]->F_DS         = 0.0;
}; // 2.1.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_IVS_SClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_RPSIVSClick(TObject *Sender)
{
F_IK->Hide();
F_ZAV->Show();
}; // void __fastcall TF_IK::MM_IK_RPSIVSClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_RPS_SVClick(TObject *Sender)
{
/*1.*/ SV->InitialDir = P_RPS;
SV->Title      = "Укажите каталог сохранения файла RPS.ini";
SV->FileName   = "RPS.ini";
/*2.*/ if (SV->Execute())
{
/*2.1.*/ P_RPS = SV->FileName;
/*2.1.*/ if ((F_RPS = fopen(P_RPS.c_str(), "w+")) != NULL)
{
/*2.1.1.*/ for (UINT npp = 0; npp < K_S; npp++)
{
/*2.1.1.1.*/ AnsiString  T_NM = UIntToStr(npp + 1);                                // 1    - Номер сигнала
unsigned int             T_C1 = RPS_TS[npp]->C_E_NS->Font->Color;                  // 2    - Цвет текста
unsigned int             T_C2 = RPS_TS[npp]->C_E_NS->Color;                        // 3    - Цвет фона
unsigned int             T_I, T_IVS;
/*2.1.1.2.*/ if (RPS_TS[npp]->C_CHB_I->Checked == true)  T_I = 1;                  // 4    - Признак наличия группового выбора сигнала
/*2.1.1.3.*/ else                                        T_I = 0;
/*2.1.1.4.*/ if (RPS_TS[npp]->C_IVS == NULL)  T_IVS = 0;
/*2.1.1.5.*/ else                             T_IVS = RPS_TS[npp]->C_IVS->Tag + 1; // 5    - № сигнала ИВС, инициализируемый данным сигналом РПС
/*2.1.1.6.*/ AnsiString  T_NS = Trim(RPS_TS[npp]->C_E_NS->Text);                   // 6... - Описание сигнала
fprintf(F_RPS, " %4s %20i %20i %5i %5i %50s \n", T_NM.c_str(), T_C1, T_C2, T_I, T_IVS, T_NS.c_str());
}; // 2.1.1.
/*2.1.2.*/ fclose(F_RPS);
}  // 2.1.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_RPS_SVClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_RPS_LDClick(TObject *Sender)
{
/*1.*/ OD->Title = "Укажите файл RPS.ini";
OD->FileName   = "RPS.ini";
/*2.*/ if (OD->Execute())
{
P_RPS = OD->InitialDir + OD->FileName;
/*2.1.*/ if  ((F_RPS = fopen(P_RPS.c_str(), "rt")) != NULL)
{
/*2.1.1.*/ FROMINI(P_RPS);
/*2.1.2.*/ for (int i = 0; i < VR_P.Length; i++)
{
/*2.1.2.1.*/ if (VR_P.Length != K_S)
{
MessageDlg("Количество строк со значениями параметров в файле RPS.ini не соответствует количеству сигналов", mtWarning, TMsgDlgButtons() << mbOK, 0);
break;
}; // 2.1.2.1.
/*2.1.2.2.*/  AnsiString TMP_S = "";
RPS_TS[i]->C_E_NS->Font->Color = (TColor)StrToInt(VR_P[i][1]);                                      // 2    - Цвет текста
RPS_TS[i]->C_E_NS->Color       = (TColor)StrToInt(VR_P[i][2]);                                      // 3    - Цвет фона
/*2.1.2.3.*/ if (StrToInt(VR_P[i][3]) == 1)  RPS_TS[i]->C_CHB_I->Checked = true;                    // 4    - Признак наличия группового выбора сигнала
/*2.1.2.4.*/ else                            RPS_TS[i]->C_CHB_I->Checked = false;
/*2.1.2.5.*/ if (StrToInt(VR_P[i][4]) != 0)  RPS_TS[i]->C_IVS = IVS_TS[(StrToInt(VR_P[i][4]) - 1)]; // 5    - № сигнала ИВС, инициализируемый данным сигналом РПС
/*2.1.2.6.*/ else                            RPS_TS[i]->C_IVS = NULL;
/*2.1.2.7.*/ for (int j = 5; j < VR_P[i].Length; j++)  TMP_S = TMP_S + VR_P[i][j] + "  ";           // 6... - Описание сигнала
/*2.1.2.8.*/ if (Trim(TMP_S) == "(null)")    RPS_TS[i]->C_E_NS->Text = "";
/*2.1.2.9.*/ else                            RPS_TS[i]->C_E_NS->Text = Trim(TMP_S);
}; // 2.1.2.
/*2.1.2.*/ fclose(F_RPS);
}; // 2.1.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_RPS_LDClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_RPS_SClick(TObject *Sender)
{
/*1.*/ int TMP_ = MessageDlg("Подтвердите обнуление длительностей всех сигналов ИПС", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*2.*/ if (TMP_ == mrYes)
{
/*2.1.*/ for (int nm = 0; nm < K_S; nm++)  RPS_TS[nm]->C_E_DS->Text = "";
}; // 2.
}; // void __fastcall TF_IK::MM_IK_RPS_SClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_RPS_SIClick(TObject *Sender)
{
/*1.*/ for (int nm = 0; nm < K_S; nm++)
{
/*1.1.*/ if (RPS_TS[nm]->SOST_X == 2)  RPS_TS[nm]->IM_CANVAS(3); // Признак наличия сигнала с контакта PR_S: 1 - есть сигнал, 2 - нет сигнала, 3 - квитирование
}; // 1.
}; // void __fastcall TF_IK::MM_IK_RPS_SIClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_PRNTClick(TObject *Sender)
{
/*1.*/ int TMP_ = MessageDlg("Печатать копию изображения экрана?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*2.*/ if (TMP_ == mrYes)
{
Printer()->Orientation = poLandscape;
F_IK->Scaled = true;
F_IK->PrintScale = poPrintToFit;
F_IK->Print();
}; // 2.
}; // void __fastcall TF_IK::MM_IK_PRNTClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_CKL_VClick(TObject *Sender)
{
/*1.*/  F_CKL->Show();
        double  SDT_PRM_MAX = 0.0;
		KT_PRM_MAX  = 0.0;
		PR_TB_ZP    = 1;
/*2.*/ for (int ns  = 0; ns < K_S; ns++)
{
/*2.1.*/ RPS_TS[ns]->PRMR.Length = 0;
IVS_TS[ns]->NVC();
/*2.2.*/ if (SDT_PRM_MAX < IVS_TS[ns]->SDT_PRM)          SDT_PRM_MAX = IVS_TS[ns]->SDT_PRM;
/*2.3.*/ if (KT_PRM_MAX  < IVS_TS[ns]->PRM_I[5].KT_PRM)  KT_PRM_MAX  = IVS_TS[ns]->PRM_I[5].KT_PRM;
}; // 2.
/*3.*/ if (1.0E-3 < SDT_PRM_MAX)
{
MM_IK_CKL_V->Enabled = false;
KT_PRM_MAX           = KT_PRM_MAX + U_DT_KC;
String  Str          = " " + FloatToStr(SDT_PRM_MAX) + " с.";
F_CKL->E_DT_VC->Text = Str.w_str();
T_B_NU               = SSTM();
TM_CKL->Enabled      = true;
} // 3.
/*4.*/ else  PR_TB_ZP = 0;
}; // void __fastcall TF_IK::MM_IK_CKL_VClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_CKL_SClick(TObject *Sender)
{
UnicodeString  ID_, FN_;
/*1.*/ GET_DIR_FN(P_NU, ID_, FN_);
SV->InitialDir = ID_;
SV->Title      = "Укажите каталог сохранения файла NU_CKL.ini";
SV->FileName   = FN_;
/*2.*/ if (SV->Execute())
{
/*2.1.*/ P_NU = SV->FileName;
/*2.2.*/ if ((F_NU = fopen(P_NU.c_str(), "w+")) == NULL)
{
FileCreate(P_NU);
F_NU = fopen(P_NU.c_str(), "w+");
}; // 2.2.
AnsiString  NU__, DT__;
int         NU_;
float       DT_S_, DT1_, DT2_, DT3_, DT4_, DT5_;
/*2.3.*/ for (int ns = 1; (ns < F_CKL->SG_IK_NU->RowCount); ns++)
{
/*2.3.1.*/  NU__ = Trim(F_CKL->SG_IK_NU->Cells[2][ns]);
/*2.3.2.*/  if (NU__ == "")   NU_  = 0;
/*2.3.3.*/  else        	  NU_  = StrToInt(NU__);
/*2.3.4.*/  DT__ = Trim(F_CKL->SG_IK_NU->Cells[3][ns]);
/*2.3.5.*/  if (DT__ == "")   DT_S_  = 0.0;
/*2.3.6.*/  else        	  DT_S_  = StrToFloat(RCD(DT__));
/*2.3.7.*/  DT__ = Trim(F_CKL->SG_IK_NU->Cells[4][ns]);
/*2.3.8.*/  if (DT__ == "")   DT1_  = 0.0;
/*2.3.9.*/  else              DT1_  = StrToFloat(RCD(DT__));
/*2.3.10.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[5][ns]);
/*2.3.11.*/ if (DT__ == "")   DT2_  = 0.0;
/*2.3.12.*/ else        	  DT2_  = StrToFloat(RCD(DT__));
/*2.3.13.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[6][ns]);
/*2.3.14.*/ if (DT__ == "")   DT3_  = 0.0;
/*2.3.15.*/ else        	  DT3_  = StrToFloat(RCD(DT__));
/*2.3.16.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[7][ns]);
/*2.3.17.*/ if (DT__ == "")   DT4_  = 0.0;
/*2.3.18.*/ else        	  DT4_  = StrToFloat(RCD(DT__));
/*2.3.19.*/ DT__ = Trim(F_CKL->SG_IK_NU->Cells[8][ns]);
/*2.3.20.*/ if (DT__ == "")   DT5_  = 0.0;
/*2.3.21.*/ else        	  DT5_  = StrToFloat(RCD(DT__));
/*2.3.22.*/ fprintf(F_NU, " %3i %9.2f %8.1f %8.1f %8.1f %8.1f %8.1f \n", NU_, DT_S_, DT1_, DT2_, DT3_, DT4_, DT5_);
}; // 2.3.
/*2.2.2.*/ fclose(F_NU);
}; // 2.
}; // void __fastcall TF_IK::MM_IK_CKL_SClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_CKL_LDClick(TObject *Sender)
{
/*1.*/ OD->Title = "Укажите файл NU_CKL.ini";
OD->FileName   ="NU_CKL.ini";
/*2.*/ if (OD->Execute())
{
P_NU = OD->InitialDir + OD->FileName;
/*2.1.*/ if ((F_NU = fopen(P_NU.c_str(), "rt")) != NULL)
{
/*2.1.1.*/ FROMINI(P_NU);
/*2.1.2.*/ for (int ns = 1; ns < K_S; ns++)
{
/*2.1.2.1.*/ for (int nc = 2; nc < (F_CKL->SG_IK_NU->ColCount - 1); nc++)    F_CKL->SG_IK_NU->Cells[nc][ns] = RCD(VR_P[(ns-1)][(nc-2)]);
}; // 2.1.2.
/*2.1.3.*/ fclose(F_NU);
}; // 2.1.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_CKL_LDClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_CKL_RClick(TObject *Sender)
{
/*1.*/ int TMP_ = MessageDlg("Подтвердите обнуление начальных значений и длительностей всех интервалов циклограммы", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
/*2.*/ if (TMP_ == mrYes)
{
/*2.1.*/ for (int ns = 1; (ns < F_CKL->SG_IK_NU->RowCount); ns++)
{
/*2.1.1.*/                                                               F_CKL->SG_IK_NU->Cells[2][ns]  = "0";
/*2.1.2.*/                                                               F_CKL->SG_IK_NU->Cells[3][ns]  = RCD("0.00");
/*2.1.3.*/ for (int nc = 4; nc < (F_CKL->SG_IK_NU->ColCount - 1); nc++)  F_CKL->SG_IK_NU->Cells[nc][ns] = RCD("0.0");
}; // 2.1.
}; // 2.
}; // void __fastcall TF_IK::MM_IK_CKL_RClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_OFRClick(TObject *Sender)
{
T_IVS::F_V();
T_RPS::F_V();
}; // void __fastcall TF_IK::MM_IK_OFRClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_KClick(TObject *Sender)
{
//F_NSTR->ModalResult = 0;
F_NSTR->Show();
}; // void __fastcall TF_IK::MM_KClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_CKL_WClick(TObject *Sender)
{
F_CKL->Show();
}; // void __fastcall TF_IK::MM_IK_CKL_WClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_OClick(TObject *Sender)
{
F_HELP->Show();
}; // void __fastcall TF_IK::MM_OClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::CheckError(ErrorCode errorCode)
{ // Обнаружение возможной ошибки
 if (errorCode != Success)
 { // Вывод сообщения об ошибке
  int err = errorCode;
  String str = "Возникла  ошибка  с  кодом:  0x" + System::Sysutils::Format("%X",ARRAYOFCONST((err)));
  MessageBox(this->WindowHandle, str.w_str(), String("Error").w_str(), MB_ICONERROR);
 }; // if (errorCode != Success)
}; // void TF_IK::CheckError(ErrorCode errorCode)
//---------------------------------------------------------------------------
void __fastcall TF_IK::TM_RPSTimer(TObject *Sender)
{
/*1.*/ TM_RPS->Enabled = false;
/*2.*/ try
{
/*2.1.*/ for (int i = 0; i < T_DVC::NumOfDevices; i++) // Перебор плат
{ // Чтение данных с DI портов (read DI data)
// portStates - состояния портов, получаемое в результате обратного считывания (instantDiCtrl->Read(...))
/*2.1.1./*/ byte  *portStates = new byte[T_DVC::K_PORT];
// Чтение обратно из T_DVC::K_PORT портов, начиная с порта № 0 и запись считанных данных в portStates
 ErrorCode ret = Success;
 ret = DVC_TS[i]->C_instantDiCtrl->Read(0, T_DVC::K_PORT, portStates);
 CheckError(ret);
/*2.1.2.*/ for (int j = 0; j < T_DVC::K_PORT; j++) // Перебор портов
{
int  N_VH_0 = 32 * i + 8 * j;
if (portStates[j] & 0x1)   RPS_TS[N_VH_0]->IM_CANVAS(1);     else RPS_TS[N_VH_0]->IM_CANVAS(2);     // Признак наличия сигнала с контакта PR_S: 1 - есть сигнал, 2 - нет сигнала, 3 - квитирование
if (portStates[j] & 0x2)   RPS_TS[(N_VH_0+1)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+1)]->IM_CANVAS(2);
if (portStates[j] & 0x4)   RPS_TS[(N_VH_0+2)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+2)]->IM_CANVAS(2);
if (portStates[j] & 0x8)   RPS_TS[(N_VH_0+3)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+3)]->IM_CANVAS(2);
if (portStates[j] & 0x10)  RPS_TS[(N_VH_0+4)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+4)]->IM_CANVAS(2);
if (portStates[j] & 0x20)  RPS_TS[(N_VH_0+5)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+5)]->IM_CANVAS(2);
if (portStates[j] & 0x40)  RPS_TS[(N_VH_0+6)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+6)]->IM_CANVAS(2);
if (portStates[j] & 0x80)  RPS_TS[(N_VH_0+7)]->IM_CANVAS(1); else RPS_TS[(N_VH_0+7)]->IM_CANVAS(2);
}; // 2.1.2.
/*2.1.3.*/ delete[] portStates;
}; // 2.1.
}  // 2.
/*3.*/ catch(...)
{
TM_RPS->Enabled = true;
}; // 3.
/*4.*/ TM_RPS->Enabled = true;
}; // void __fastcall TF_IK::TM_RPSTimer(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::ATB_IK_PClick(TObject *Sender)
{
MM_IK_PRNT->Click();
} // void __fastcall TF_IK::AdvToolBarButton1Click(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::ATB_IK_KRClick(TObject *Sender)
{
MM_IK_RPS_SI->Click();
}; // void __fastcall TF_IK::ATB_IK_KRClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::FormResize(TObject *Sender)
{
PC_IK->Width  = ClientWidth;
T_DVC::VIS_DVC();
}; // void __fastcall TF_IK::FormResize(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_NClick(TObject *Sender)
{
F_CH_NSTR->Show();
} // void __fastcall TF_IK::MM_IK_NClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_IK::MM_IK_VSClick(TObject *Sender)
{
F_CH_NSTR->B_GRClick(F_CH_NSTR->B_GR);
} // void __fastcall TF_IK::MM_IK_VSClick(TObject *Sender)
//---------------------------------------------------------------------------
