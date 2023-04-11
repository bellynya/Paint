//---------------------------------------------------------------------------

#ifndef Paint_MainH
#define Paint_MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include "Color_str.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TPanel *Panel1;
	TSpeedButton *sbPencil;
	TSpeedButton *sbLine;
	TSpeedButton *sbFigure;
	TSpeedButton *sbLastic;
	TSpeedButton *sbPipetka;
	TColorBox *ColorBox1;
	TShape *Shape1;
	TShape *Shape2;
	TSpinEdit *SpinEdit1;
	TComboBox *cbPenStyles;
	TColorDialog *ColorDialog1;
	TComboBox *cbFillStyle;
	TPopupMenu *PopupMenu1;
	TMenuItem *Rectangle1;
	TMenuItem *Rectangle2;
	TSpeedButton *sbFill;
	TCheckBox *CheckBox1;
	TSpeedButton *sbText;
	TEdit *Edit1;
	TPanel *Panel2;
	TLabel *Label1;
	TButton *Button1;
	TLabel *lFontExample;
	TFontDialog *FontDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *Load1;
	TMenuItem *Load2;
	TMenuItem *Clearall1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *Cancel1;
	TMenuItem *Cope1;
	TMenuItem *Cope2;
	TSpeedButton *sbSelect;
	TMenuItem *Draw1;
	TPopupMenu *PopupMenu2;
	TMenuItem *pmEllipse;
	TMenuItem *pmRectangle;
	TMenuItem *pmTriangle;
	TMenuItem *Vectors1;
	TMenuItem *vLoad;
	TMenuItem *vSave;
	TMemo *Memo1;
	TMenuItem *MyFigure1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ColorBox1Change(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall cbPenStylesChange(TObject *Sender);
	void __fastcall Shape2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall cbFillStyleChange(TObject *Sender);
	void __fastcall Rectangle1Click(TObject *Sender);
	void __fastcall Rectangle2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall sbTextClick(TObject *Sender);
	void __fastcall Clearall1Click(TObject *Sender);
	void __fastcall File2Click(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall Cancel1Click(TObject *Sender);
	void __fastcall Cope1Click(TObject *Sender);
	void __fastcall Cope2Click(TObject *Sender);
	void __fastcall vSaveClick(TObject *Sender);
	void __fastcall vLoadClick(TObject *Sender);


private:	// User declarations
void ChangeFillStyle(int);
void Triangle(int, int, int, int);
void AddToLog(AnsiString,int);
void AddToLog(AnsiString,int, int);
void AddToLog(AnsiString,int, int, int, int);
void Draw();
void ChangePenStyles(int);
void GetPenRGBColor();
void GetBrushRGBColor();
void AddToLog(AnsiString, Color_);
void AddToLog(AnsiString, int, int, TColor);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
