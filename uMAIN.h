//---------------------------------------------------------------------------

#ifndef uMAINH
#define uMAINH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *CODE;
	TButton *DECODE;
	TMemo *MEMO;
	TEdit *LEN;
	TOpenDialog *OpenDialog;
	TEdit *OpenPath;
	TButton *SAVE;
	TButton *OPEN;
	TSaveDialog *SaveDialog;
	TPanel *Panel2;
	TImage *IMG;
	TEdit *STEP;
	TControlBar *PROGRESSBAR;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label1;
	TLabel *Label2;
	TButton *EXITBUT;
	TMainMenu *MENU;
	TMenuItem *MFile;
	TMenuItem *MHelp;
	TMenuItem *MPicture;
	TMenuItem *MLoad;
	TMenuItem *MSave;
	TMenuItem *MText;
	TMenuItem *MLoadTXT;
	TMenuItem *MSaveTXT;
	TMenuItem *N1;
	TMenuItem *MExit;
	TMenuItem *MUser;
	TMenuItem *MAbout;
	TButton *LOADTXT;
	TButton *SAVETXT;
	TOpenDialog *OpenDialogTXT;
	TSaveDialog *SaveDialogTXT;
	void __fastcall CODEClick(TObject *Sender);
	void __fastcall DECODEClick(TObject *Sender);
	void __fastcall OPENClick(TObject *Sender);
	void __fastcall SAVEClick(TObject *Sender);
	void __fastcall EXITBUTClick(TObject *Sender);
	void __fastcall LOADTXTClick(TObject *Sender);
	void __fastcall SAVETXTClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
