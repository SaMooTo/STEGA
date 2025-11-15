//---------------------------------------------------------------------------

#ifndef uLOGINH
#define uLOGINH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *BG;
	TEdit *LOGIN;
	TEdit *PASS;
	TEdit *NEWPASS;
	TButton *ENTER;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *MHelp;
	void __fastcall MouseEnter(TObject *Sender);
	void __fastcall MouseLeave(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ENTERClick(TObject *Sender);
	void __fastcall MHelpClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
