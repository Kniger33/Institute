object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 511
  ClientWidth = 684
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 184
    Top = 32
    Width = 68
    Height = 14
    Caption = #1042#1089#1077' '#1090#1086#1074#1072#1088#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 312
    Top = 8
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 312
    Top = 33
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 536
    Top = 96
    Width = 105
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1086#1074#1072#1088
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 52
    Width = 500
    Height = 437
    FixedRows = 0
    GridLineWidth = 2
    TabOrder = 1
  end
  object Button2: TButton
    Left = 536
    Top = 144
    Width = 105
    Height = 25
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 536
    Top = 200
    Width = 105
    Height = 49
    Caption = #1055#1086#1080#1089#1082' '#1090#1086#1074#1072#1088#1072' '#1087#1086' '#1089#1083#1086#1074#1091' '#1080#1083#1080' '#1089#1083#1086#1074#1086#1089#1086#1095#1077#1090#1072#1085#1080#1102
    TabOrder = 3
    WordWrap = True
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 536
    Top = 272
    Width = 105
    Height = 41
    Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1086#1090#1076#1077#1083#1091' '#1080' '#1094#1077#1085#1077' 200-300'
    TabOrder = 4
    WordWrap = True
    OnClick = Button4Click
  end
end
