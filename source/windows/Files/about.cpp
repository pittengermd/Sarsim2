//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include "dest.h"
#include "about.h"
//added by abarta
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//extern char version[30];
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
	: TForm(Owner)
{
 char temp[100];
 sprintf(temp,"Last Build on: %s at %s",__DATE__,__TIME__);
 this->lLastBuild->Caption = temp;
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::Timer1Timer(TObject *Sender)
{
  char PicName[20];
  static int CountSM;
  // show  animation
  CountSM++;
  if (CountSM > 4) {CountSM = 1;}
  sprintf(PicName,"SM_BITMAP_%d",CountSM);
  Image1->Picture->Bitmap->LoadFromResourceName((int)HInstance,PicName);

}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::FormShow(TObject *Sender)
{
  Label1->Caption="Sarsim II - version "+AnsiString(version);
  Timer1->Enabled = TRUE;
  LExp->Caption = "Expires on "+AnsiString(Expire_YEAR)+":"+
    AnsiString(Expire_MONTH)+":"+AnsiString(Expire_DAY);

}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  Timer1->Enabled = FALSE;	
}
//---------------------------------------------------------------------------