object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 371
  ClientWidth = 264
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 104
    Top = 24
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Edit1: TEdit
    Left = 72
    Top = 43
    Width = 129
    Height = 21
    TabOrder = 0
    TextHint = #1053#1086#1084#1077#1088' '#1090#1086#1074#1072#1088#1072
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 72
    Top = 96
    Width = 129
    Height = 21
    TabOrder = 1
    TextHint = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object Edit3: TEdit
    Left = 72
    Top = 144
    Width = 129
    Height = 21
    TabOrder = 2
    TextHint = #1054#1090#1076#1077#1083
  end
  object Edit4: TEdit
    Left = 72
    Top = 192
    Width = 129
    Height = 21
    TabOrder = 3
    TextHint = #1062#1077#1085#1072
    OnChange = Edit4Change
    OnKeyDown = Edit4KeyDown
  end
  object Edit5: TEdit
    Left = 72
    Top = 240
    Width = 129
    Height = 21
    TabOrder = 4
    TextHint = #1056#1072#1079#1083#1080#1095#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
  end
  object Button1: TButton
    Left = 96
    Top = 304
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
end
