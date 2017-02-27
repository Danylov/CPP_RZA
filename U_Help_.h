//---------------------------------------------------------------------------
#ifndef U_Help_H
#define U_Help_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TF_HELP : public TForm
{
__published:	// IDE-managed Components
        TEdit *E_MAIL;
        TButton *B_OK;
        TEdit *E_AUTOR;
        TLabel *L_AUTOR;
        TLabel *L_COMPANY;
        TLabel *L_ABOUT;
        void __fastcall B_OKClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall FormShow(TObject *Sender);
	    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TF_HELP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_HELP *F_HELP;
//---------------------------------------------------------------------------
#endif
