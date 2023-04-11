object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 597
  ClientWidth = 1091
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 49
    Width = 903
    Height = 548
    Align = alClient
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
    ExplicitLeft = 8
    ExplicitWidth = 1091
  end
  object Label1: TLabel
    Left = 89
    Top = 13
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1091
    Height = 49
    Align = alTop
    TabOrder = 0
    object sbPencil: TSpeedButton
      Left = 8
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Pencil'
    end
    object sbLine: TSpeedButton
      Left = 55
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = '|'
    end
    object sbFigure: TSpeedButton
      Left = 102
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Figure'
      PopupMenu = PopupMenu2
    end
    object sbLastic: TSpeedButton
      Left = 173
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Lastic'
      PopupMenu = PopupMenu1
    end
    object sbPipetka: TSpeedButton
      Left = 220
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Pipetka'
    end
    object Shape1: TShape
      Left = 577
      Top = 7
      Width = 33
      Height = 36
      Brush.Color = clBtnText
    end
    object Shape2: TShape
      Left = 632
      Top = 7
      Width = 33
      Height = 36
      OnMouseUp = Shape2MouseUp
    end
    object sbFill: TSpeedButton
      Left = 292
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Fill'
    end
    object sbText: TSpeedButton
      Left = 395
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Text'
      OnClick = sbTextClick
    end
    object sbSelect: TSpeedButton
      Left = 516
      Top = 8
      Width = 41
      Height = 35
      GroupIndex = 1
      Caption = 'Select'
    end
    object ColorBox1: TColorBox
      Left = 696
      Top = 15
      Width = 145
      Height = 22
      TabOrder = 0
      OnChange = ColorBox1Change
    end
    object SpinEdit1: TSpinEdit
      Left = 847
      Top = 15
      Width = 50
      Height = 22
      MaxValue = 0
      MinValue = 0
      TabOrder = 1
      Value = 0
      OnChange = SpinEdit1Change
    end
    object cbPenStyles: TComboBox
      Left = 903
      Top = 0
      Width = 145
      Height = 21
      TabOrder = 2
      TextHint = 'Pen Styles'
      OnChange = cbPenStylesChange
      Items.Strings = (
        'Solid'
        'Dash'
        'Dot'
        'DashDot'
        'DashDotDot'
        'Clear')
    end
    object cbFillStyle: TComboBox
      Left = 903
      Top = 27
      Width = 145
      Height = 21
      TabOrder = 3
      TextHint = 'Fill Style'
      OnChange = cbFillStyleChange
      Items.Strings = (
        'Solid'
        'Clear'
        'Horizontal'
        'Vertical'
        'Diagonal Left Top -> Right Bottom'
        'Diagonal Reberse'
        'Cross'
        'Diagonal Cross')
    end
    object CheckBox1: TCheckBox
      Left = 339
      Top = 17
      Width = 50
      Height = 17
      Caption = 'Border'
      TabOrder = 4
      OnClick = CheckBox1Click
    end
  end
  object Edit1: TEdit
    Left = 384
    Top = 55
    Width = 121
    Height = 21
    TabOrder = 1
    TextHint = 'Input text here'
    Visible = False
    OnKeyUp = Edit1KeyUp
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 9
    Height = 49
    TabOrder = 2
    Visible = False
    object lFontExample: TLabel
      Left = 102
      Top = 13
      Width = 40
      Height = 13
      Caption = 'Example'
    end
    object Button1: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 35
      Caption = 'Font Settings'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object Memo1: TMemo
    Left = 903
    Top = 49
    Width = 188
    Height = 548
    Align = alRight
    TabOrder = 3
    Visible = False
  end
  object ColorDialog1: TColorDialog
    Left = 584
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 264
    Top = 8
    object Rectangle1: TMenuItem
      AutoCheck = True
      Caption = 'Rectangle'
      RadioItem = True
      OnClick = Rectangle1Click
    end
    object Rectangle2: TMenuItem
      AutoCheck = True
      Caption = 'Circle'
      RadioItem = True
      OnClick = Rectangle2Click
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 440
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 480
    Top = 9
    object File1: TMenuItem
      Caption = 'File'
      object File2: TMenuItem
        Caption = 'Save'
        OnClick = File2Click
      end
      object Load1: TMenuItem
        Caption = 'Load'
        OnClick = Load1Click
      end
    end
    object Load2: TMenuItem
      Caption = 'Settings'
      object Clearall1: TMenuItem
        Caption = 'Clear all'
        OnClick = Clearall1Click
      end
      object Cancel1: TMenuItem
        Caption = 'Cancel'
        ShortCut = 16474
        OnClick = Cancel1Click
      end
      object Cope1: TMenuItem
        Caption = 'Copy'
        OnClick = Cope1Click
      end
      object Cope2: TMenuItem
        Caption = 'Paste'
        OnClick = Cope2Click
      end
      object Draw1: TMenuItem
        Caption = 'Draw'
        ShortCut = 16472
      end
    end
    object Vectors1: TMenuItem
      Caption = 'Vectors'
      object vLoad: TMenuItem
        Caption = 'Load'
        OnClick = vLoadClick
      end
      object vSave: TMenuItem
        Caption = 'Save'
        OnClick = vSaveClick
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 104
  end
  object SaveDialog1: TSaveDialog
    Left = 8
    Top = 56
  end
  object PopupMenu2: TPopupMenu
    Left = 144
    Top = 8
    object pmEllipse: TMenuItem
      AutoCheck = True
      Caption = 'Ellipse'
      RadioItem = True
    end
    object pmRectangle: TMenuItem
      AutoCheck = True
      Caption = 'Rectangle'
      RadioItem = True
    end
    object pmTriangle: TMenuItem
      AutoCheck = True
      Caption = 'Triangle'
      RadioItem = True
    end
    object MyFigure1: TMenuItem
      AutoCheck = True
      Caption = 'MyFigure'
      RadioItem = True
    end
  end
end
