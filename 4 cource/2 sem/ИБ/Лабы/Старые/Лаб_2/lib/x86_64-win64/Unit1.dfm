object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1052#1077#1085#1102
  ClientHeight = 420
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    468
    420)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 153
    Width = 193
    Height = 249
    Caption = #1050#1085#1086#1087#1082#1080
    TabOrder = 0
    object Button1: TButton
      Left = 14
      Top = 14
      Width = 163
      Height = 25
      Caption = #1072#1083#1075#1086#1088#1080#1090#1084' '#1060#1086#1085' '#1053#1077#1081#1084#1072#1085#1072
      Enabled = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 14
      Top = 45
      Width = 163
      Height = 25
      Caption = #1084#1085#1086#1075#1086#1095#1083#1077#1085' '#1076#1088#1086#1073#1085#1072#1103' '#1095#1072#1089#1090#1100
      Enabled = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 14
      Top = 76
      Width = 163
      Height = 25
      Caption = #1082#1086#1085#1075#1088#1091#1101#1090#1085#1099#1081' '#1089#1087#1086#1089#1086#1073' '#1051#1077#1084#1077#1088#1072
      Enabled = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 14
      Top = 107
      Width = 163
      Height = 25
      Caption = #1050#1057#1051' 2'
      Enabled = False
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 14
      Top = 138
      Width = 163
      Height = 25
      Caption = #1040#1083#1075#1086#1088#1080#1090#1084' '#1052#1072#1088#1089#1072#1083#1080#1072'-'#1047#1072#1081#1084#1072
      Enabled = False
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 14
      Top = 200
      Width = 163
      Height = 25
      Caption = 'Clear'
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 14
      Top = 169
      Width = 163
      Height = 25
      Caption = #1087#1086#1082#1072#1079#1072#1090#1100' '#1075#1088#1072#1092#1080#1082
      TabOrder = 6
      OnClick = Button7Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 16
    Width = 193
    Height = 131
    Caption = #1042#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 7
      Height = 13
      Caption = 'A'
    end
    object Label2: TLabel
      Left = 17
      Top = 46
      Width = 6
      Height = 13
      Caption = 'B'
    end
    object Label3: TLabel
      Left = 16
      Top = 73
      Width = 7
      Height = 13
      Caption = 'C'
    end
    object Label4: TLabel
      Left = 16
      Top = 100
      Width = 6
      Height = 13
      Caption = 'K'
    end
    object Edit1: TEdit
      Left = 29
      Top = 16
      Width = 147
      Height = 21
      TabOrder = 0
      OnChange = Edit1Change
    end
    object Edit2: TEdit
      Left = 29
      Top = 43
      Width = 147
      Height = 21
      TabOrder = 1
      OnChange = Edit2Change
    end
    object Edit3: TEdit
      Left = 29
      Top = 70
      Width = 147
      Height = 21
      TabOrder = 2
      OnChange = Edit3Change
    end
    object Edit4: TEdit
      Left = 29
      Top = 97
      Width = 147
      Height = 21
      TabOrder = 3
      OnChange = Edit4Change
    end
  end
  object GroupBox3: TGroupBox
    Left = 232
    Top = 16
    Width = 209
    Height = 386
    Anchors = [akLeft, akTop, akBottom]
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 239
    Top = 41
    Width = 194
    Height = 352
    Anchors = [akLeft, akTop, akBottom]
    ScrollBars = ssVertical
    TabOrder = 3
  end
end
