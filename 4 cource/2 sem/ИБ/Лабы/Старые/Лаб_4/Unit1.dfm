object Form1: TForm1
  Left = 726
  Top = 264
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1043#1055#1063'1 '#1080' '#1043#1055#1063'2'
  ClientHeight = 426
  ClientWidth = 591
  Color = clSilver
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
    Left = 8
    Top = 8
    Width = 530
    Height = 18
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1081'  '#1103#1095#1077#1077#1082' '#1083#1080#1085#1077#1081#1085#1086#1075#1086' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1089#1076#1074#1080#1075#1072' '
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 104
    Width = 290
    Height = 18
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1081'  '#1103#1095#1077#1077#1082' '#1055#1053
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 336
    Top = 136
    Width = 240
    Height = 18
    Caption = #1044#1083#1080#1085#1072' '#1087#1086#1089#1083#1077#1076#1086#1074#1086#1090#1077#1083#1100#1085#1086#1089#1090#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 184
    Top = 320
    Width = 190
    Height = 18
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1075#1077#1085#1077#1088#1072#1094#1080#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 32
    Width = 505
    Height = 57
    ColCount = 11
    DefaultColWidth = 44
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnKeyPress = StringGrid1KeyPress
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 128
    Width = 321
    Height = 57
    ColCount = 7
    DefaultColWidth = 44
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    OnKeyPress = StringGrid1KeyPress
    ColWidths = (
      44
      44
      44
      44
      44
      44
      44)
  end
  object Edit1: TEdit
    Left = 336
    Top = 160
    Width = 241
    Height = 26
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '16'
    OnKeyPress = Edit1KeyPress
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 200
    Width = 129
    Height = 105
    Caption = #1042#1099#1073#1086#1088' '#1043#1055#1063
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      #1043#1055#1063'-1'
      #1043#1055#1063'-2')
    ParentFont = False
    TabOrder = 3
  end
  object RadioGroup2: TRadioGroup
    Left = 160
    Top = 200
    Width = 161
    Height = 105
    Caption = #1042#1099#1073#1086#1088' '#1074#1072#1088#1080#1072#1085#1090#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '2'
      '3')
    ParentFont = False
    TabOrder = 4
  end
  object StringGrid3: TStringGrid
    Left = 8
    Top = 344
    Width = 569
    Height = 73
    DefaultColWidth = 44
    FixedCols = 0
    RowCount = 2
    TabOrder = 5
  end
  object Button1: TButton
    Left = 344
    Top = 232
    Width = 185
    Height = 57
    Caption = #1057#1075#1077#1085#1077#1085#1088#1080#1088#1086#1074#1072#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 336
    Top = 104
    Width = 241
    Height = 25
    Caption = #1047#1072#1076#1072#1090#1100' '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
    TabOrder = 7
    OnClick = Button2Click
  end
end
