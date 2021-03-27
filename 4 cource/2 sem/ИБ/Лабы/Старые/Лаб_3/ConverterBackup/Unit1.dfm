object Form1: TForm1
  Left = 268
  Top = 159
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'3'
  ClientHeight = 442
  ClientWidth = 700
  Color = clSilver
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Courier New'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 18
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 681
    Height = 425
    ActivePage = TabSheet4
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1064#1080#1092#1088' '#1079#1072#1084#1077#1085#1099
      object Label1: TLabel
        Left = 104
        Top = 32
        Width = 40
        Height = 18
        Caption = #1050#1083#1102#1095
      end
      object Label2: TLabel
        Left = 104
        Top = 112
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label3: TLabel
        Left = 104
        Top = 200
        Width = 140
        Height = 18
        Caption = #1048#1090#1086#1075#1086#1074#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Edit1: TEdit
        Left = 40
        Top = 64
        Width = 265
        Height = 26
        TabOrder = 0
        OnKeyPress = Edit1KeyPress
      end
      object Edit2: TEdit
        Left = 40
        Top = 144
        Width = 265
        Height = 26
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 40
        Top = 224
        Width = 265
        Height = 26
        TabOrder = 2
      end
      object Button1: TButton
        Left = 344
        Top = 144
        Width = 257
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100'/'#1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 3
        OnClick = Button1Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1052#1077#1090#1086#1076' '#1087#1077#1088#1077#1089#1090#1072#1085#1086#1074#1082#1080
      ImageIndex = 1
      object Label4: TLabel
        Left = 104
        Top = 32
        Width = 40
        Height = 18
        Caption = #1050#1083#1102#1095
      end
      object Label5: TLabel
        Left = 104
        Top = 112
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label6: TLabel
        Left = 96
        Top = 192
        Width = 140
        Height = 18
        Caption = #1048#1090#1086#1075#1086#1074#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Edit4: TEdit
        Left = 40
        Top = 64
        Width = 265
        Height = 26
        MaxLength = 9
        TabOrder = 0
        OnKeyPress = Edit1KeyPress
      end
      object Edit5: TEdit
        Left = 40
        Top = 144
        Width = 265
        Height = 26
        TabOrder = 1
      end
      object Edit6: TEdit
        Left = 40
        Top = 224
        Width = 265
        Height = 26
        TabOrder = 2
      end
      object Button2: TButton
        Left = 344
        Top = 88
        Width = 257
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 3
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 344
        Top = 120
        Width = 257
        Height = 25
        Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 4
        OnClick = Button3Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'DES'
      ImageIndex = 2
      object Label7: TLabel
        Left = 104
        Top = 32
        Width = 40
        Height = 18
        Caption = #1050#1083#1102#1095
      end
      object Label8: TLabel
        Left = 104
        Top = 112
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label9: TLabel
        Left = 96
        Top = 192
        Width = 140
        Height = 18
        Caption = #1048#1090#1086#1075#1086#1074#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Button4: TButton
        Left = 344
        Top = 120
        Width = 257
        Height = 25
        Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 0
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 344
        Top = 88
        Width = 257
        Height = 25
        Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 1
        OnClick = Button5Click
      end
      object Edit7: TEdit
        Left = 40
        Top = 64
        Width = 265
        Height = 26
        MaxLength = 9
        TabOrder = 2
      end
      object Edit8: TEdit
        Left = 40
        Top = 144
        Width = 265
        Height = 26
        TabOrder = 3
      end
      object Edit9: TEdit
        Left = 40
        Top = 224
        Width = 265
        Height = 26
        TabOrder = 4
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1069#1085#1080#1075#1084#1072
      ImageIndex = 3
      object Label10: TLabel
        Left = 16
        Top = 16
        Width = 60
        Height = 18
        Caption = #1050#1083#1102#1095' 1'
      end
      object Label11: TLabel
        Left = 16
        Top = 96
        Width = 60
        Height = 18
        Caption = #1050#1083#1102#1095' 2'
      end
      object Label12: TLabel
        Left = 16
        Top = 176
        Width = 60
        Height = 18
        Caption = #1050#1083#1102#1095' 3'
      end
      object Label13: TLabel
        Left = 16
        Top = 264
        Width = 60
        Height = 18
        Caption = #1050#1083#1102#1095' 4'
      end
      object Label14: TLabel
        Left = 304
        Top = 16
        Width = 140
        Height = 18
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Label15: TLabel
        Left = 304
        Top = 136
        Width = 140
        Height = 18
        Caption = #1048#1090#1086#1075#1086#1074#1099#1081' '#1090#1077#1082#1089#1090
      end
      object Edit10: TEdit
        Left = 16
        Top = 48
        Width = 169
        Height = 26
        TabOrder = 0
      end
      object Edit11: TEdit
        Left = 16
        Top = 128
        Width = 169
        Height = 26
        TabOrder = 1
      end
      object Edit12: TEdit
        Left = 16
        Top = 208
        Width = 169
        Height = 26
        TabOrder = 2
      end
      object Edit13: TEdit
        Left = 16
        Top = 296
        Width = 169
        Height = 26
        TabOrder = 3
      end
      object Edit14: TEdit
        Left = 304
        Top = 48
        Width = 329
        Height = 26
        TabOrder = 4
      end
      object Edit15: TEdit
        Left = 304
        Top = 168
        Width = 329
        Height = 26
        TabOrder = 5
      end
      object Button6: TButton
        Left = 304
        Top = 96
        Width = 121
        Height = 25
        Caption = #1064#1090#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 6
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 504
        Top = 96
        Width = 131
        Height = 25
        Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
        TabOrder = 7
        OnClick = Button7Click
      end
    end
  end
end
