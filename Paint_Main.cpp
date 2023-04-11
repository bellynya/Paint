//---------------------------------------------------------------------------

#include <vcl.h>
#include <Jpeg.hpp>
#include <list>
#include <array>
#pragma hdrstop

#include "Paint_Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const int kEnter = 13;
int tmp1, tmp2;  // x0, y0
std::list<TBitmap*> cancels;
TBitmap * tmp;
TRect copy_r;
bool pencil_drawing = false, lastic = false, copying = true;
int r1, g1, b1;
Color_ col;

int x = 0, y = 0, w = 300, h = 200;
double dx = w/30, dy = h/20;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	tmp = new TBitmap();
	tmp->Height = Image1->Height;
	tmp->Width = Image1->Width;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	sbPencil->AllowAllUp = true;
    SpinEdit1->Value = 1;
}
//---------------------------------------------------------------------------
void TForm1::Triangle(int x_0, int y_0, int x, int y)
{
//coords of rectangle, reads like rbx = right bottom x
	int x_left_t = x_0, y_left_t = y_0, x_right_t = x, y_right_t = y_0,
	x_left_b = x_0, y_left_b = y, x_right_b = x, y_right_b = y;
//triangle top apex
	int triangle_apex_tx = (x_left_t + x_right_t)/2, triangle_apex_ty = (y_left_t + y_right_t)/2;
//triangle bottom apexs;
	int triangle_apex_lbx = x_left_b, triangle_apex_lby = y_left_b,
	triangle_apex_rbx = x_right_b, triangle_apex_rby = y_right_b;


	Image1->Canvas->MoveTo(triangle_apex_tx, triangle_apex_ty);
	Image1->Canvas->LineTo(triangle_apex_lbx, triangle_apex_lby);
	Image1->Canvas->LineTo(triangle_apex_rbx, triangle_apex_rby);
	Image1->Canvas->LineTo(triangle_apex_tx, triangle_apex_ty);
}
//==============================================================================
void TForm1::GetPenRGBColor()
{
	r1 = GetRValue(ColorToRGB(Shape1->Brush->Color));
	g1 = GetGValue(ColorToRGB(Shape1->Brush->Color));
	b1 = GetBValue(ColorToRGB(Shape1->Brush->Color));
	col.R_ = r1; col.G_ = g1, col.B_ = b1;
	AddToLog("PenColor", col);
}
void TForm1::GetBrushRGBColor()
{
	r1 = GetRValue(ColorToRGB(Shape2->Brush->Color));
	g1 = GetGValue(ColorToRGB(Shape2->Brush->Color));
	b1 = GetBValue(ColorToRGB(Shape2->Brush->Color));
	col.R_ = r1; col.G_ = g1, col.B_ = b1;
    AddToLog("BrushColor", col);
}
//==============================================================================
void TForm1::AddToLog(AnsiString name, int X)
{
	Memo1->Lines->Add(name);
	Memo1->Lines->Add(IntToStr(X));
}
void TForm1::AddToLog(AnsiString name, int X, int Y)
{
	Memo1->Lines->Add(name);
	Memo1->Lines->Add(IntToStr(X));
	Memo1->Lines->Add(IntToStr(Y));
}
void TForm1::AddToLog(AnsiString name, int x_0, int y_0, int x, int y)
{
	Memo1->Lines->Add(name);
	Memo1->Lines->Add(IntToStr(x_0));
	Memo1->Lines->Add(IntToStr(y_0));
	Memo1->Lines->Add(IntToStr(x));
	Memo1->Lines->Add(IntToStr(y));
}
void TForm1::AddToLog(AnsiString name, Color_ c)
{
	Memo1->Lines->Add(name);
	Memo1->Lines->Add(IntToStr(c.R_));
	Memo1->Lines->Add(IntToStr(c.G_));
	Memo1->Lines->Add(IntToStr(c.B_));
}
void TForm1::AddToLog(AnsiString name, int X, int Y, TColor c)
{
	Memo1->Lines->Add(name);
	Memo1->Lines->Add(IntToStr(X));
	Memo1->Lines->Add(IntToStr(Y));
	Memo1->Lines->Add(ColorToString(c));
}
//==============================================================================
void TForm1::Draw()
{
	Canvas->Brush->Color = clRed;                            // rectangle 1
	Canvas->Rectangle(x+5*dx, y+5*dy, x+35*dx, y+15*dy);     //
	Canvas->Brush->Color = clBlack;                          // rectangle 2
	Canvas->Rectangle(x+5*dx, y+15*dy, x+35*dx, y+25*dy);    //

	Canvas->Pen->Color = clWhite;
	Canvas->Brush->Color=clWhite;
	Canvas->Pen->Width=5;
	Canvas->MoveTo(x+15*dx, y+9*dy);   //left side
	Canvas->LineTo(x+17*dx,y+14*dy);
	Canvas->LineTo(x+15*dx,y+19*dy);
	Canvas->LineTo(x+18.5*dx,y+19*dy);
	Canvas->LineTo(x+15*dx,y+19*dy);
    Canvas->LineTo(x+15*dx,y+9*dy);
	Canvas->MoveTo(x+25*dx, y+9*dy);   //rigth side
    Canvas->LineTo(x+23*dx,y+14*dy);
	Canvas->LineTo(x+25*dx,y+19*dy);
	Canvas->LineTo(x+21.5*dx,y+19*dy);
	Canvas->LineTo(x+25*dx,y+19*dy);
    Canvas->LineTo(x+25*dx,y+9*dy);
	Canvas->MoveTo(x+20*dx, y+9*dy);   //sword point
	//Canvas->FloodFill(19,13,Canvas->Pixels[19][13],fsSurface);
	Canvas->LineTo(x+18.5*dx,y+13*dy);
	Canvas->LineTo(x+19.5*dx,y+18*dy);
	Canvas->LineTo(x+18.5*dx,y+18*dy);
	Canvas->LineTo(x+21.5*dx,y+18*dy);
	Canvas->LineTo(x+20.5*dx,y+18*dy);
	Canvas->LineTo(x+21.5*dx,y+13*dy);
	Canvas->LineTo(x+20*dx,y+9*dy);
	Canvas->MoveTo(x+20*dx, y+18*dy);   //sword hilt
    Canvas->Pen->Width=8;
	Canvas->LineTo(x+19.7*dx,y+19.8*dy);
	Canvas->LineTo(x+20*dx,y+20.7*dy);
	Canvas->LineTo(x+20.45*dx,y+19.8*dy);
	Canvas->LineTo(x+20*dx,y+18*dy);
	Canvas->Pen->Color = clBlack;
    Canvas->Pen->Width=0;
}
//==============================================================================
void TForm1::ChangePenStyles(int a)
{
	switch (a) {
	case 0:
		Image1->Canvas->Pen->Style = psSolid; break;
	case 1:
		Image1->Canvas->Pen->Style = psDash; break;
	case 2:
		Image1->Canvas->Pen->Style = psDot; break;
	case 3:
		Image1->Canvas->Pen->Style = psDashDot; break;
	case 4:
		Image1->Canvas->Pen->Style = psDashDotDot; break;
	case 5:
		Image1->Canvas->Pen->Style = psClear; break;
	default: Image1->Canvas->Pen->Style = psSolid; break;
	}
}
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	TBitmap * tmp = new TBitmap();
	tmp->Height = Image1->Height;
	tmp->Width = Image1->Width;
	tmp->Assign(Image1->Picture);
	cancels.push_back(tmp);
    x = X, y = Y;
	Image1->Canvas->MoveTo(X, Y);
    AddToLog("MoveTo", X, Y);
	tmp1 = X; tmp2 = Y;
    if (sbPencil->Down) {
		pencil_drawing = true;
	}
	else if (sbLastic->Down) {
		lastic = true;
	}
	else if (sbPipetka->Down) {
		if (Button == mbLeft)
		{
			Shape1->Brush->Color = Image1->Canvas->Pixels[X][Y];
			AddToLog("PipetkaLMB", Image1->Canvas->Pixels[X][Y]);
		}
		else if (Button == mbRight)
		{
			Shape2->Brush->Color = Image1->Canvas->Pixels[X][Y];
			AddToLog("PipetkaRMB", Image1->Canvas->Pixels[X][Y]);
		}
		else if (Button == mbMiddle)
		{
		Shape1->Brush->Color = Image1->Canvas->Pixels[X][Y];
		AddToLog("PipetkaLMB", Image1->Canvas->Pixels[X][Y]);
		Shape2->Brush->Color = Image1->Canvas->Pixels[X][Y];
		AddToLog("PipetkaRMB", Image1->Canvas->Pixels[X][Y]);
		}
	}
	else if (sbFill->Down) {
		if (!CheckBox1->Checked) {
			Image1->Canvas->FloodFill(X, Y, Image1->Canvas->Pen->Color, fsBorder);
			GetPenRGBColor();
			GetBrushRGBColor();
			AddToLog("FillingBorder", X, Y);
		}
		else
		{
			Image1->Canvas->FloodFill(X, Y, Image1->Canvas->Pixels[X][Y], fsSurface);
            GetBrushRGBColor();
			AddToLog("FillingSurface", X, Y, Image1->Canvas->Pixels[X][Y]);
		}
	}
	else if (sbText->Down) {
		Edit1->Left = X + Image1->Left;
		Edit1->Top = Y + Image1->Top;
		Edit1->Text = "";
		Edit1->Visible = true;
		Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if (sbPencil->Down && pencil_drawing) {
		Image1->Canvas->LineTo(X, Y);
	}
	else if (sbLastic->Down && lastic) {
		Image1->Canvas->Pen->Color = clWhite;
		Image1->Canvas->Brush->Color = clWhite;
		if(PopupMenu1->Items[0].Checked) {
			Image1->Canvas->FillRect(Rect(X, Y, X + 10, Y + 10));
		} else if(PopupMenu1->Items[1].Checked) {
			Image1->Canvas->Ellipse(X, Y, X + 10, Y + 10);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (sbLine->Down) {
		Image1->Canvas->LineTo(X, Y);
		AddToLog("LineTo", X, Y);
	}
	else if (sbFigure->Down) {
		if (pmEllipse->Checked)
		{
			Image1->Canvas->Ellipse(tmp1, tmp2, X, Y);
			GetPenRGBColor();
            GetBrushRGBColor();
			AddToLog("Ellipse", tmp1, tmp2, X, Y);
		}
		else if (pmRectangle->Checked)
		{
			Image1->Canvas->Rectangle(tmp1, tmp2, X, Y);
			GetPenRGBColor();
			GetBrushRGBColor();
			AddToLog("Rectangle", tmp1, tmp2, X, Y);
		}
		else if (pmTriangle->Checked)
		{
			Triangle(tmp1, tmp2, X, Y);
			GetPenRGBColor();
			GetBrushRGBColor();
			AddToLog("Triangle", tmp1, tmp2, X, Y);
		}
		else if (MyFigure1->Checked) {
			Draw();
		}
    }
	else if (sbLastic->Down) {
		Image1->Canvas->Pen->Color = Shape1->Brush->Color;
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
	}
	else if (sbSelect->Down&&copying) {
		Image1->Canvas->DrawFocusRect(Rect(tmp1, tmp2, X, Y));
		copy_r.init(tmp1, tmp2, X, Y);
	}
	pencil_drawing = false;
	lastic = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ColorBox1Change(TObject *Sender)
{
	Image1->Canvas->Pen->Color = ColorBox1->Selected;
    Shape1->Brush->Color = ColorBox1->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpinEdit1Change(TObject *Sender)
{
	if (SpinEdit1->Value > 0)
		Image1->Canvas->Pen->Width = SpinEdit1->Value;
	else SpinEdit1->Value = 1;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::cbPenStylesChange(TObject *Sender)
{
	ChangePenStyles(cbPenStyles->ItemIndex);
	AddToLog("ChangePenStyles", cbPenStyles->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Shape2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (ColorDialog1->Execute()) {
		Shape2->Brush->Color = ColorDialog1->Color;
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
	}
}
//---------------------------------------------------------------------------
void TForm1::ChangeFillStyle(int a)
{
	switch (a) {
	case 0:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsSolid; break;
	case 1:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsClear; break;
	case 2:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsHorizontal; break;
	case 3:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsVertical; break;
	case 4:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsFDiagonal; break;
	case 5:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsBDiagonal; break;
	case 6:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsCross; break;
	case 7:
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->Brush->Style = bsDiagCross; break;
	}
}
void __fastcall TForm1::cbFillStyleChange(TObject *Sender)
{
	ChangeFillStyle(cbFillStyle->ItemIndex);
	AddToLog("ChangeFillStyle", cbFillStyle->ItemIndex);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Rectangle1Click(TObject *Sender)
{
	PopupMenu1->Items[0].Checked = true;
	PopupMenu1->Items[1].Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Rectangle2Click(TObject *Sender)
{
	PopupMenu1->Items[1].Checked = true;
	PopupMenu1->Items[0].Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
	{
		CheckBox1->Caption = "Surface";
   	}else CheckBox1->Caption = "Border";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == kEnter) {
		Image1->Canvas->Brush->Style = bsClear;
		// set canvas font settings
		Image1->Canvas->Font = lFontExample->Font;
		Image1->Canvas->Font->Size = lFontExample->Font->Size;
		Image1->Canvas->Font->Style = lFontExample->Font->Style;
		Image1->Canvas->TextOutW(tmp1, tmp2, Edit1->Text);
		// back to normal
		Image1->Canvas->Font = Label1->Font;
		Image1->Canvas->Font->Size = Label1->Font->Size;
		Image1->Canvas->Font->Style = Label1->Font->Style;
		// set lFontExample properties to default
		lFontExample->Font = Label1->Font;
		lFontExample->Font->Size = Label1->Font->Size;
		lFontExample->Font->Style = Label1->Font->Style;

        sbText->Down = false;
		Edit1->Visible = false;
		ChangeFillStyle(cbFillStyle->ItemIndex);
		Panel2->Visible = false;
        Panel2->Width  = 10;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (FontDialog1->Execute()) {
		lFontExample->Font = FontDialog1->Font;
		lFontExample->Font->Size = FontDialog1->Font->Size;
		lFontExample->Font->Style = FontDialog1->Font->Style;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sbTextClick(TObject *Sender)
{
	Panel2->Visible = true;
	Panel2->Width  = 390;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Clearall1Click(TObject *Sender)
{
	Image1->Canvas->Pen->Color = clWhite;
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));
    Image1->Canvas->Pen->Color = Shape1->Brush->Color;
	Image1->Canvas->Brush->Color = Shape2->Brush->Color;
    Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::File2Click(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		Image1->Picture->SaveToFile(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Load1Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
		Image1->Picture->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Cancel1Click(TObject *Sender)
{
	TBitmap * tmp;
	tmp = cancels.back(); cancels.pop_back();
	Image1->Canvas->Draw(0,0, tmp);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Cope1Click(TObject *Sender)
{
	copying = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cope2Click(TObject *Sender)
{
	if (!copying)
		Image1->Canvas->CopyRect(Rect(0, 0, copy_r.Width(), copy_r.Height()),Image1->Canvas, copy_r);
    copying = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vSaveClick(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		Memo1->Lines->SaveToFile(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vLoadClick(TObject *Sender)
{
	int tmp_x0, tmp_y0, X, Y, color, brush;
	if (OpenDialog1->Execute()) {
		Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
		for (size_t i = 0; i < Memo1->Lines->Count; i++) {
			AnsiString s = Memo1->Lines->Strings[i];
			if (s == "MoveTo") {
				X = StrToInt(Memo1->Lines->Strings[i+1]);
				Y = StrToInt(Memo1->Lines->Strings[i+2]);
				Image1->Canvas->MoveTo(X, Y);
			}
			else if (s == "LineTo") {
				X = StrToInt(Memo1->Lines->Strings[i+1]);
				Y = StrToInt(Memo1->Lines->Strings[i+2]);
				Image1->Canvas->LineTo(X, Y);
			}
			else if (s == "PipetkaLMB") {
				Shape1->Brush->Color = ((TColor)StrToInt(Memo1->Lines->Strings[i+1]));
			}
			else if (s == "PipetkaRMB") {
				Shape1->Brush->Color = ((TColor)StrToInt(Memo1->Lines->Strings[i+1]));
			}
			else if (s == "PipetkaMMB") {
				Shape1->Brush->Color = ((TColor)StrToInt(Memo1->Lines->Strings[i+1]));
                Shape1->Brush->Color = ((TColor)StrToInt(Memo1->Lines->Strings[i+2]));
			}
			else if (s == "Ellipse") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				X = StrToInt(Memo1->Lines->Strings[i+3]);
				Y = StrToInt(Memo1->Lines->Strings[i+4]);
				Image1->Canvas->Ellipse(tmp_x0, tmp_y0, X, Y);
			}
			else if (s == "Rectangle") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				X = StrToInt(Memo1->Lines->Strings[i+3]);
				Y = StrToInt(Memo1->Lines->Strings[i+4]);
				Image1->Canvas->Rectangle(tmp_x0, tmp_y0, X, Y);
			}
            else if (s == "Ellipse") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				X = StrToInt(Memo1->Lines->Strings[i+3]);
				Y = StrToInt(Memo1->Lines->Strings[i+4]);
				Triangle(tmp_x0, tmp_y0, X, Y);
			}
			else if (s == "ChangeFillStyle") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				ChangeFillStyle(cbFillStyle->ItemIndex);
			}
			else if (s == "ChangePenStyles") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				ChangePenStyles(cbPenStyles->ItemIndex);
			}
			else if (s =="FillingBorder") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				Image1->Canvas->FloodFill(tmp_x0, tmp_y0, Image1->Canvas->Pen->Color, fsBorder);
			}
			else if (s == "FillingSurface") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				TColor t = StringToColor(Memo1->Lines->Strings[i+3]);
				Image1->Canvas->FloodFill(tmp_x0, tmp_y0, Image1->Canvas->Pixels[tmp_x0][tmp_y0], fsSurface);
			}
			else if (s == "PenColor") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				X = StrToInt(Memo1->Lines->Strings[i+3]);
				Image1->Canvas->Pen->Color = (TColor)RGB(tmp_x0,tmp_y0,X);
			}
			else if (s == "BrushColor") {
				tmp_x0 = StrToInt(Memo1->Lines->Strings[i+1]);
				tmp_y0 = StrToInt(Memo1->Lines->Strings[i+2]);
				X = StrToInt(Memo1->Lines->Strings[i+3]);
				Image1->Canvas->Brush->Color = (TColor)RGB(tmp_x0,tmp_y0,X);
			}
		}
	}
}
//---------------------------------------------------------------------------



