object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 361
  ClientWidth = 548
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
    Left = 56
    Top = 32
    Width = 84
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1086#1090#1076#1077#1083': '
  end
  object Edit1: TEdit
    Left = 56
    Top = 64
    Width = 321
    Height = 21
    TabOrder = 0
    TextHint = #1046#1076#1091' '#1074#1074#1086#1076#1072'...'
  end
  object Button1: TButton
    Left = 56
    Top = 104
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 96
    Width = 80
    Height = 49
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1087#1086#1080#1089#1082#1072
    TabOrder = 2
    WordWrap = True
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 151
    Width = 569
    Height = 209
    TabOrder = 3
  end
end
