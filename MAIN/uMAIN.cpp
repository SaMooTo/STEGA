#include <vcl.h>
#pragma hdrstop

#include "uMAIN.h"
#include "uHELP.h"
#include "uABOUT.h"
#include "pngimage.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

//Пользовательские переменные|Начало
TBitmap *Bmp;
int WIDTH = 0, HEIGHT = 0;
struct pnt {
	int x=0;
	int y=0;
};
bool isPic = false;
int R,G,B;
//Пользовательские переменные|Конец
BYTE GetBit(BYTE B, int N) {
	if ((1 << N) & B) return 1;
	return 0;
}

BYTE ChangeByte(BYTE B, int bit) {
	if (GetBit(B, 0) == bit) return B;
	else if (GetBit(B, 0) == 1 && bit == 0) return B-1;
	else if (GetBit(B, 0) == 0 && bit == 1) return B|bit;
	return NULL;
}

pnt NextPos(pnt p, int Step, int WIDTH) {
	if (p.x + Step > (WIDTH-1)) {
		while (p.x + Step > (WIDTH-1)) {
			p.y++;
			Step = Step - WIDTH;
		}
	}
	p.x = p.x + Step;
	return p;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CODEClick(TObject *Sender)
{
//Обработка DLL библиотеки
	HINSTANCE MyDll;
	typedef TColor(__stdcall * pfCrypt)(TColor, char, int);
	pfCrypt Crypt;
	MyDll = LoadLibraryW(L"DLL.dll");
	Crypt = (pfCrypt)GetProcAddress(MyDll, "Crypt");
//Обработка DLL библиотеки|Конец
	pnt p;
	p.y = 0; p.x = 0;
	AnsiString Text = MEMO->Text;
	if (Text.Length() == 0) {
		ShowMessage("Критическая ошибка! Необходимо ввести текст!");
		return;
	}
	if (!isPic) {
		ShowMessage("Критическая ошибка!\nДля начала работы загрузите изображение!");
		return;
	}
	int Step = WIDTH * HEIGHT / Text.Length() / 8;
	for (int i = 1; i < Text.Length()+1; i++) {
		char c = Text[i];
		for (int j = 0; j < 8; j++) {
			TColor Color = Bmp->Canvas->Pixels[p.x][p.y];
			Bmp->Canvas->Pixels[p.x][p.y] = Crypt(Color, c, j); //Использование функции из DLL.dll
			p = NextPos(p, Step, WIDTH);
			PROGRESSBAR->Position = i / MEMO->Text.Length() * 100;
		}
	}
	ShowMessage("Шаг: " + IntToStr(Step) + "\n" + "Длина текста: " + IntToStr(Text.Length()));
	MEMO->Text = "";
	STEP->Text = "";
	PROGRESSBAR->Position = 0;
	FreeLibrary(MyDll);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DECODEClick(TObject *Sender)
{
	if (!isPic) {
		ShowMessage("Критическая ошибка!\nДля начала работы загрузите изображение!");
		return;
	}
	if (LEN->Text != "" && STEP->Text != "") {
	//Обработка DLL библиотеки
		HINSTANCE MyDll;
		typedef int(__stdcall * pfDecrypt)(TColor, int, int);
		pfDecrypt Decrypt;
		MyDll = LoadLibraryW(L"DLL.dll");
		Decrypt = (pfDecrypt)GetProcAddress(MyDll, "Decrypt");
	//Обработка DLL библиотеки|Конец
		int key = StrToInt(LEN->Text);
		pnt p;
		p.x = 0; p.y = 0;
		string sbuf = "";
		for (int i = 1; i < key+1; i++) {
			int ibuf = 0;
			for (int j = 0; j < 8; j++) {
				TColor Color = Bmp->Canvas->Pixels[p.x][p.y];
				ibuf = Decrypt(Color, ibuf, j);
//				ibuf = ibuf + GetBit(R, 0) * pow(2, 7-j);
				p = NextPos(p, StrToInt(STEP->Text), WIDTH);
			}
			sbuf = sbuf + (char)ibuf;
		}
		MEMO->Text = sbuf.c_str();
		FreeLibrary(MyDll);
	} else {ShowMessage("Заполните поля ввода!");}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OPENClick(TObject *Sender)
{
	if (OpenDialog->Execute()){
		IMG->Picture->LoadFromFile(OpenDialog->FileName);
		Bmp = IMG->Picture->Bitmap;
		Bmp->PixelFormat = pf24bit;
		WIDTH = Bmp->Width;
		HEIGHT = Bmp->Height;
		isPic = true;
		MEMO->Enabled = true;
		LOADTXT->Enabled = true;
		SAVETXT->Enabled = true;
		Label5->Visible = true;
        CNT->Visible = true;
		CNT->Caption = WIDTH * HEIGHT / 8;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SAVEClick(TObject *Sender)
{
	if (WIDTH == 0) {
		ShowMessage("Критическая ошибка!\nНевозможно сохранить пустое изображение!");
		return;
	}
	if (SaveDialog->Execute()) {
		IMG->Picture->SaveToFile(SaveDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LOADTXTClick(TObject *Sender)
{
	if (OpenDialogTXT->Execute()) {
		MEMO->Lines->LoadFromFile(OpenDialogTXT->FileName, TEncoding::UTF8);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SAVETXTClick(TObject *Sender)
{
	if (MEMO->Text.Length() == 0) {
		ShowMessage("Критическая ошибка!\nВ поле сохранения нет текста!");
        return;
	}
	if (SaveDialogTXT->Execute()) {
		MEMO->Lines->SaveToFile(SaveDialogTXT->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Kill(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EXITBUTClick(TObject *Sender) {
	Application->Terminate();
}
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::MUserClick(TObject *Sender)
{
	Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MAboutClick(TObject *Sender)
{
	Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MEMOChange(TObject *Sender)
{
	CNT->Caption = WIDTH * HEIGHT / 8 - MEMO->Text.Length();
}
//---------------------------------------------------------------------------

