object Form1: TForm1
  Left = 272
  Top = 229
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'1'
  ClientHeight = 357
  ClientWidth = 631
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 609
    Height = 337
    ActivePage = TabSheet1
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1055#1086#1083#1080#1073#1080#1072#1085#1089#1082#1080#1081' '#1084#1077#1090#1086#1076
      object Label1: TLabel
        Left = 96
        Top = 168
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label2: TLabel
        Left = 72
        Top = 232
        Width = 200
        Height = 18
        Caption = #1056#1077#1079#1091#1083#1100#1090#1080#1088#1091#1102#1097#1080#1081' '#1090#1077#1082#1089#1090
      end
      object StringGrid1: TStringGrid
        Left = 16
        Top = 24
        Width = 329
        Height = 129
        FixedCols = 0
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 0
      end
      object Button1: TButton
        Left = 368
        Top = 56
        Width = 201
        Height = 81
        Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1089#1083#1091#1095#1072#1081#1085#1086
        TabOrder = 1
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 24
        Top = 192
        Width = 321
        Height = 26
        TabOrder = 2
      end
      object Edit2: TEdit
        Left = 24
        Top = 264
        Width = 321
        Height = 26
        TabOrder = 3
      end
      object Button2: TButton
        Left = 384
        Top = 192
        Width = 145
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 4
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 384
        Top = 264
        Width = 145
        Height = 25
        Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 5
        OnClick = Button3Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1077#1088#1077#1089#1090#1072#1085#1086#1074#1082#1072' '#1087#1086' '#1082#1083#1102#1095#1091
      ImageIndex = 1
      object Label3: TLabel
        Left = 24
        Top = 8
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label4: TLabel
        Left = 296
        Top = 8
        Width = 40
        Height = 18
        Caption = #1050#1083#1102#1095
      end
      object Edit3: TEdit
        Left = 24
        Top = 32
        Width = 193
        Height = 26
        MaxLength = 39
        TabOrder = 0
      end
      object Edit4: TEdit
        Left = 232
        Top = 32
        Width = 161
        Height = 26
        MaxLength = 7
        TabOrder = 1
      end
      object Button4: TButton
        Left = 408
        Top = 32
        Width = 153
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 2
        OnClick = Button4Click
      end
      object StringGrid2: TStringGrid
        Left = 24
        Top = 64
        Width = 265
        Height = 193
        ColCount = 7
        DefaultColWidth = 34
        FixedCols = 0
        RowCount = 7
        FixedRows = 0
        TabOrder = 3
      end
      object StringGrid3: TStringGrid
        Left = 296
        Top = 64
        Width = 265
        Height = 193
        ColCount = 7
        DefaultColWidth = 34
        FixedCols = 0
        RowCount = 7
        FixedRows = 0
        TabOrder = 4
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1052#1077#1090#1086#1076' '#1073#1080#1075#1088#1072#1084#1084
      ImageIndex = 2
      object Label5: TLabel
        Left = 57
        Top = 11
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label6: TLabel
        Left = 201
        Top = 75
        Width = 200
        Height = 18
        Caption = #1056#1077#1079#1091#1083#1100#1090#1080#1088#1091#1102#1097#1080#1081' '#1090#1077#1082#1089#1090
      end
      object Label7: TLabel
        Left = 473
        Top = 11
        Width = 40
        Height = 18
        Caption = #1050#1083#1102#1095
      end
      object Edit5: TEdit
        Left = 9
        Top = 35
        Width = 360
        Height = 26
        MaxLength = 30
        TabOrder = 0
      end
      object StringGrid4: TStringGrid
        Left = 16
        Top = 136
        Width = 393
        Height = 129
        ColCount = 6
        FixedCols = 0
        FixedRows = 0
        TabOrder = 1
      end
      object Button5: TButton
        Left = 416
        Top = 160
        Width = 177
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 2
        OnClick = Button5Click
      end
      object Edit6: TEdit
        Left = 16
        Top = 99
        Width = 570
        Height = 26
        TabOrder = 3
      end
      object Edit7: TEdit
        Left = 400
        Top = 35
        Width = 193
        Height = 26
        MaxLength = 30
        TabOrder = 4
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1058#1088#1072#1092#1072#1088#1077#1090#1085#1099#1081' '#1089#1087#1086#1089#1086#1073
      ImageIndex = 3
      object Label8: TLabel
        Left = 184
        Top = 8
        Width = 150
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1089#1082#1089#1090
      end
      object Label9: TLabel
        Left = 168
        Top = 64
        Width = 170
        Height = 18
        Caption = #1064#1048#1092#1088#1086#1074#1072#1085#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Edit8: TEdit
        Left = 72
        Top = 32
        Width = 361
        Height = 26
        MaxLength = 16
        TabOrder = 0
      end
      object Edit9: TEdit
        Left = 72
        Top = 88
        Width = 361
        Height = 26
        TabOrder = 1
      end
      object StringGrid5: TStringGrid
        Left = 120
        Top = 136
        Width = 265
        Height = 105
        ColCount = 4
        FixedCols = 0
        RowCount = 4
        FixedRows = 0
        TabOrder = 2
      end
      object Button6: TButton
        Left = 448
        Top = 64
        Width = 121
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 3
        OnClick = Button6Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1052#1077#1090#1086#1076' '#1076#1074#1091#1093' '#1090#1072#1073#1083#1080#1094
      ImageIndex = 4
      object Label10: TLabel
        Left = 16
        Top = 8
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label11: TLabel
        Left = 16
        Top = 40
        Width = 170
        Height = 18
        Caption = #1064#1080#1092#1088#1086#1074#1072#1085#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object StringGrid6: TStringGrid
        Left = 192
        Top = 88
        Width = 185
        Height = 184
        DefaultColWidth = 34
        FixedCols = 0
        RowCount = 7
        FixedRows = 0
        TabOrder = 0
      end
      object StringGrid7: TStringGrid
        Left = 384
        Top = 88
        Width = 185
        Height = 185
        DefaultColWidth = 34
        FixedCols = 0
        RowCount = 7
        FixedRows = 0
        TabOrder = 1
      end
      object Edit10: TEdit
        Left = 240
        Top = 8
        Width = 353
        Height = 26
        TabOrder = 2
      end
      object Edit11: TEdit
        Left = 240
        Top = 48
        Width = 353
        Height = 26
        TabOrder = 3
      end
      object Button7: TButton
        Left = 48
        Top = 200
        Width = 105
        Height = 73
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 4
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 48
        Top = 104
        Width = 105
        Height = 81
        Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100
        TabOrder = 5
        OnClick = Button8Click
      end
    end
  end
end
