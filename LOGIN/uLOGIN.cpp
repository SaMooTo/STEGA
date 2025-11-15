//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include <Lmcons.h>
#include "uLOGIN.h"
#include "uMAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int MAX_PEOPLE = 10;
char logins[10][16];
char passwords[10][16];
using namespace std;
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MouseEnter(TObject *Sender)
{
	Label1->Font->Color = clBlue;
	Label1->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MouseLeave(TObject *Sender)
{
	Label1->Font->Color = clBlack;
	Label1->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label1Click(TObject *Sender)
{
	if (ENTER->Caption == "Вход") {
		NEWPASS->Visible = true;
		ENTER->Caption = "Сменить\nпароль";
		Label1->Caption = "Вход";
		PASS->TextHint = "Старый пароль";
	}
	else {
		NEWPASS->Visible = false;
		ENTER->Caption = "Вход";
		Label1->Caption = "Смена пароля";
		PASS->TextHint = "Пароль";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	char username[UNLEN+1];
	DWORD username_len = UNLEN+1;
	GetUserNameA(username, &username_len); //Получение имени пользователя
	char path[256] = "C:\\Users\\";
	strcat(strcat(path, username), "\\Desktop\\LOGINS.txt"); //Путь к рабочему столу
	fstream file(path, ios::in);
	if (file.is_open()) {
		for (int i = 0; !file.eof(); i+=2) {
			file >> logins[i/2]; //Получение логинов пользователей
			file >> passwords[i/2]; //Получение паролей пользователей
		}
		file.close();
	}
	else {
		ShowMessage("Критическая ошибка!\nНе удалось найти файл логинов!\nЗагрузите на рабочий стол файл LOGINS.txt");
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ENTERClick(TObject *Sender)
{
	int flag = 0;
	if (LOGIN->Text.Length() < 8) {
		ShowMessage("Критическая ошибка!\nИмя пользователя - не менее 8 знаков");
		return;
	}
	if (PASS->Text.Length() < 4) {
		ShowMessage("Критическая ошибка!\nПароль - не менее 4 знаков");
		return;
	}
	for (int i = 0; i < MAX_PEOPLE; i++) {
		if (ENTER->Caption == "Вход") {
			if (LOGIN->Text == logins[i] && PASS->Text == passwords[i]) {
				Form1->Show();
				Form2->Hide();
				return;
			}
		}
		if (ENTER->Caption == "Сменить\nпароль") {
			if (NEWPASS->Text.Length() < 4) {
				ShowMessage("Критическая ошибка!\nПароль - не менее 4 знаков");
				return;
			}
			else {
				if (LOGIN->Text == logins[i] && PASS->Text == passwords[i]) {
					strcpy(passwords[i], AnsiString(NEWPASS->Text).c_str());
					ShowMessage("Пароль успешно изменен!");
					flag = 1;
				}
			}
		}
	}
	if (flag == 0) {
		ShowMessage("Неверный пароль или имя пользователя!\nОтказано в доступе!");
		ENTER->Enabled = false;
	}
	else {
        char username[UNLEN+1];
		DWORD username_len = UNLEN+1;
		GetUserNameA(username, &username_len); //Получение имени пользователя
		char path[256] = "C:\\Users\\";
		strcat(strcat(path, username), "\\Desktop\\LOGINS.txt"); //Путь к рабочему столу
		fstream file(path, ios::out);
		if (file.is_open()) {
			for (int i = 0; i < MAX_PEOPLE*2; i+=2) {
				file << logins[i/2] << " ";
				file << passwords[i/2] << "\n";
			}
			file.close();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MHelpClick(TObject *Sender)
{
	ShowMessage("В поле логин вписывается Фамилия на русском английскими буквами, нижнее подчёркивание\nи номер по списку(Пример: Ivanov_10)\nСтандартный пароль: 1234");
}
//---------------------------------------------------------------------------

