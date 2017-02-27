//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "U_Help_.h"
#include "StF_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_HELP *F_HELP;
//---------------------------------------------------------------------------
__fastcall TF_HELP::TF_HELP(TComponent* Owner) : TForm(Owner)
{
}; // __fastcall TF_HELP::TF_HELP(TComponent* Owner) : TForm(Owner)
//---------------------------------------------------------------------------
void __fastcall TF_HELP::B_OKClick(TObject *Sender)
{
F_HELP->Hide();
}; // void __fastcall TF_HELP::B_OKClick(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_HELP::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key == VK_ESCAPE) F_HELP->Hide();
}; // void __fastcall TF_HELP::FormKeyDown(...)
//---------------------------------------------------------------------------
void __fastcall TF_HELP::FormShow(TObject *Sender)
{
Top   = int(float(Screen->Height - Height) / 4.0);
Left  = int(float(Screen->Width  - Width)  / 2.0);
L_ABOUT->Top    =                                      20;
L_AUTOR->Top    = L_ABOUT->Top + L_ABOUT->Height     + 20;
L_AUTOR->Left   =                                      60;
E_AUTOR->Top    = L_AUTOR->Top;
E_AUTOR->Left   = L_AUTOR->Left + L_AUTOR->Width     + 10;
E_MAIL->Top     = L_AUTOR->Top;
E_MAIL->Left    = E_AUTOR->Left + E_AUTOR->Width     + 40;
L_COMPANY->Top  = L_AUTOR->Top + L_AUTOR->Height     + 20;
ClientWidth     = E_MAIL->Left  + E_MAIL->Width      + 60;
L_COMPANY->Left = E((ClientWidth - L_COMPANY->Width) / 2.0);
L_ABOUT->Left   = E((ClientWidth - L_ABOUT->Width)   / 2.0);
B_OK->Top       = L_COMPANY->Top + L_COMPANY->Height + 20;
B_OK->Left      = E((ClientWidth - B_OK->Width)      / 2.0);
ClientHeight    = B_OK->Top  + B_OK->Height          + 20;
}; // void __fastcall TF_HELP::FormShow(TObject *Sender)
//---------------------------------------------------------------------------
void __fastcall TF_HELP::FormClick(TObject *Sender)
{
F_HELP->Show();
}; // void __fastcall TF_HELP::FormClick(TObject *Sender)
//---------------------------------------------------------------------------

