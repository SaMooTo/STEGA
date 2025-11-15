object Form2: TForm2
  Left = 613
  Top = 332
  AutoSize = True
  Caption = #1042#1093#1086#1076
  ClientHeight = 113
  ClientWidth = 290
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnCreate = FormCreate
  TextHeight = 15
  object BG: TPanel
    Left = 0
    Top = 0
    Width = 290
    Height = 113
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 183
      Top = 78
      Width = 98
      Height = 27
      Alignment = taCenter
      AutoSize = False
      Caption = #1057#1084#1077#1085#1072' '#1087#1072#1088#1086#1083#1103
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
      OnClick = Label1Click
      OnMouseEnter = MouseEnter
      OnMouseLeave = MouseLeave
    end
    object LOGIN: TEdit
      Left = 8
      Top = 7
      Width = 169
      Height = 27
      TabStop = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      TextHint = #1051#1086#1075#1080#1085
    end
    object PASS: TEdit
      Left = 8
      Top = 43
      Width = 169
      Height = 27
      TabStop = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      TextHint = #1055#1072#1088#1086#1083#1100
    end
    object NEWPASS: TEdit
      Left = 8
      Top = 78
      Width = 169
      Height = 27
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      TextHint = #1053#1086#1074#1099#1081' '#1087#1072#1088#1086#1083#1100
      Visible = False
    end
    object ENTER: TButton
      Left = 183
      Top = 7
      Width = 98
      Height = 65
      Caption = #1042#1093#1086#1076
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      HotImageName = 'Enter'
      ParentFont = False
      TabOrder = 3
      TabStop = False
      WordWrap = True
      OnClick = ENTERClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 256
    Top = 80
    object MHelp: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      OnClick = MHelpClick
    end
  end
end
