object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 361
  ClientWidth = 504
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
    Left = 48
    Top = 24
    Width = 168
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1089#1083#1086#1074#1086'/'#1089#1083#1086#1074#1086#1089#1086#1095#1077#1090#1072#1085#1080#1077': '
  end
  object Edit1: TEdit
    Left = 48
    Top = 51
    Width = 289
    Height = 21
    TabOrder = 0
    TextHint = #1046#1076#1091' '#1074#1074#1086#1076#1072
  end
  object Button1: TButton
    Left = 48
    Top = 78
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 128
    Width = 481
    Height = 233
    TabOrder = 2
  end
  object Button2: TButton
    Left = 418
    Top = 78
    Width = 75
    Height = 44
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1087#1086#1080#1089#1082#1072
    TabOrder = 3
    WordWrap = True
    OnClick = Button2Click
  end
end
