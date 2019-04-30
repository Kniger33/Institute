//Tables - student musician composition
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>

#include <commctrl.h>
#include <mysql.h>
#include <mysqld_error.h>

#define CM_EDITBTN 101
#define CM_EDITBTN_PRESSED 102

#define BTN_OK 103
#define BTN_NEXT 104

#define CM_EDITBTN_ENTER_VALUE 106
#define CM_EDITBTN_ENTER_VALUE_PRESSED 107

#define CM_MODE_TABLE 1001
#define CM_MODE_REQUEST 1002

#define IDC_LISTVIEW 1111
#define ID_RESTABLE 1112
#define ID_COMBOBOX 1113

using namespace std;

BOOL RegClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndTRProc(HWND, UINT, WPARAM, LPARAM);

HWND CreateListView(HWND, UINT);
LRESULT CALLBACK NewEditProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK NewEditEnterValueProc(HWND, UINT, WPARAM, LPARAM);

char szMainClass[] = "MainClass";
char szTRClass[] = "TableRequestClass";

char menuName[] = "Mode";
char menuModeTable[] = "&Table";
char menuModeRequest[] = "&Request";

HINSTANCE hInst;

HWND hwndTR;

HMENU hMainMenu, hModeMenu;

HWND hwndEditTableName;
HWND hwndListBox;
HWND hwndBtnOk, hwndBtnNext;
HWND hwndQueryStatic;
HWND hwndResTable;

HWND hwndOperationsList;
HWND hwndEnterValue;

WNDPROC DefEditProc;

MYSQL *conn, mysql;
MYSQL_RES *res;

int state = 0;

int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance,	LPSTR lpCmdLine,	int nCmdShow)
{
    MSG msg;
    HWND hwnd;

    hInst = hInstance;

    if (!RegClass(WndProc, szMainClass, COLOR_WINDOW)) { return FALSE; }
    if (!RegClass(WndTRProc, szTRClass, COLOR_WINDOW)) { return FALSE; }

    hwnd = CreateWindow(szMainClass,
                        "Main Window",
                        WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        600,
                        0,
                        0,
                        hInst,
                        NULL);

    if (!hwnd)
    {
        MessageBox(NULL, "Window Creation Failed.", "Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    while (GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = Proc;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(brBackground + 1);
    wc.lpszMenuName = (LPCTSTR)NULL;
    wc.lpszClassName = szName;
    return (RegisterClass(&wc) != 0);
}

BOOL CreateMenuItem(HMENU hMenu, char *str, UINT ulns, UINT uCom, HMENU hSubMenu, BOOL flag, UINT fType)
{
    MENUITEMINFO mii;
    mii.cbSize = sizeof(MENUITEMINFO);
    mii.fMask = MIIM_STATE | MIIM_TYPE | MIIM_SUBMENU | MIIM_ID;
    mii.fType = fType;
    mii.fState = MFS_ENABLED;
    mii.dwTypeData = str;
    mii.cch = sizeof(str);
    mii.wID = uCom;
    mii.hSubMenu = hSubMenu;
    return InsertMenuItem(hMenu, ulns, flag, &mii);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    RECT mainRect;
    GetWindowRect(hWnd, &mainRect);

    switch (msg)
    {
        case WM_CREATE:
        {
            mysql_init(&mysql);
            conn = mysql_real_connect(&mysql, "localhost", "root", "1234", "winapi", 3306, NULL, 0);

            if (conn)
            {
                mysql_set_character_set(conn, "utf8");
                //Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1
                //cout<<"connectioncharacterset: "<<mysql_character_set_name(conn) <<endl;
            }
            else
            {
                MessageBox(NULL, mysql_error(&mysql), "Error", MB_OK | MB_ICONERROR);
            }

            hMainMenu = CreateMenu();
            hModeMenu = CreatePopupMenu();
            int i = 0;
            CreateMenuItem(hModeMenu, menuModeTable, i++, CM_MODE_TABLE, NULL, FALSE, MFT_STRING);
            CreateMenuItem(hModeMenu, NULL, i++, 0, NULL, FALSE, MFT_SEPARATOR);
            CreateMenuItem(hModeMenu, menuModeRequest, i++, CM_MODE_REQUEST, NULL, FALSE, MFT_STRING);

            i = 0;
            CreateMenuItem(hMainMenu, menuName, i++, 0, hModeMenu, FALSE, MFT_STRING);

            SetMenu(hWnd, hMainMenu);
            DrawMenuBar(hWnd);

            break;
        }

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case CM_MODE_TABLE:
                {
                    //MessageBox(hWnd, "Table", "Mode", MB_OK);
                    state = 1;
                    if (IsWindow(hwndTR))
                    {
                        SendMessage(hwndTR, WM_CLOSE, 0, 0);
                    }
                    hwndTR = CreateWindow(szTRClass,
                                             NULL,
                                             WS_VISIBLE | WS_CHILD,
                                             0, 0,
                                             mainRect.right, mainRect.bottom,
                                             hWnd,
                                             0,
                                             hInst,
                                             NULL);

                    EnableMenuItem(hMainMenu, 0, MF_DISABLED | MF_BYPOSITION);

                    break;
                }
                case CM_MODE_REQUEST:
                {
                    if (IsWindow(hwndTR))
                    {
                        SendMessage(hwndTR, WM_CLOSE, 0, 0);
                    }
                    state = 2;
                    hwndTR = CreateWindow(szTRClass,
                                               NULL,
                                               WS_VISIBLE | WS_CHILD,
                                               0, 0,
                                               mainRect.right, mainRect.bottom,
                                               hWnd,
                                               0,
                                               hInst,
                                               NULL);

                    EnableMenuItem(hMainMenu, 0, MF_DISABLED | MF_BYPOSITION );
                    break;
                }

                default: break;
            }
            break;
        }

        case WM_DESTROY:
        {
            SetWindowLongPtr(hwndEditTableName, GWLP_WNDPROC, (LPARAM)DefEditProc);
            SetWindowLongPtr(hwndEnterValue, GWLP_WNDPROC, (LPARAM)DefEditProc);
            mysql_free_result(res);
            mysql_close(conn);
            PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

}

MYSQL_ROW row;
MYSQL_FIELD *field;

char tableName[128];
vector <string> fields;
string outQuery = "";
string queryTableNames;
string query;
char fieldName[64];

char enteredValue[128];
char whereTableName[128];
char operation[64];
char *operations[8] = {"=", ">", "<", ">=", "<=", "!=", "AND", "OR"};
bool isWhereCondition = false;
int it = 0;

LRESULT CALLBACK WndTRProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    RECT tableRect;
    GetWindowRect(hWnd, &tableRect);

    int index, operationsIndex;

    switch (msg)
    {
        case WM_CREATE:
        {
            EnableWindow(hwndEditTableName, TRUE);
            EnableWindow(hwndListBox, TRUE);
            EnableWindow(hwndBtnOk, TRUE);
            EnableWindow(hwndBtnOk, TRUE);
            SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)"");
            fields.clear();
            query.clear();
            outQuery.clear();
            isWhereCondition = false;

            hwndEditTableName = CreateWindow("Edit",
                                         "",
                                         WS_CHILD | WS_BORDER | WS_VISIBLE | ES_LEFT,
                                         0, 0,
                                         200, 25,
                                         hWnd,
                                         (HMENU)CM_EDITBTN,
                                         hInst,
                                         NULL);

            DefEditProc = (WNDPROC)GetWindowLongPtr(hwndEditTableName, GWLP_WNDPROC);
            SetWindowLongPtr(hwndEditTableName, GWLP_WNDPROC, (LPARAM)NewEditProc);

            if (!hwndEditTableName)
            {
                MessageBox(NULL, "Edit create Failed.", "Error", MB_OK | MB_ICONERROR);
                break;
            }

            break;
        }

        case WM_COMMAND:
        {
            switch (HIWORD(wParam))
            {
                case LBN_DBLCLK:
                {
                    if(!isWhereCondition)
                    {
                        index = (int)SendMessage(hwndListBox, LB_GETCURSEL, 0, 0L);
                        if (index != LB_ERR)
                        {
                            SendMessage(hwndListBox, LB_GETTEXT, index, (LPARAM)fieldName);
                            fields.push_back((string)fieldName);
                        }
                        outQuery.clear();
                        outQuery += "SELECT ";
                        for(int i = 0; i < fields.size(); i++)
                        {
                            if(i == 0)
                            {
                                outQuery += fields[i];
                                continue;
                            }
                            outQuery += ", ";
                            outQuery += fields[i];
                        }
                        outQuery += " FROM ";
                        outQuery += tableName;
                        SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)outQuery.c_str());
                    }
                    else
                    {
                        index = (int)SendMessage(hwndListBox, LB_GETCURSEL, 0, 0L);
                        if (index != LB_ERR)
                        {
                            SendMessage(hwndListBox, LB_GETTEXT, index, (LPARAM)fieldName);
                        }
                        outQuery += fieldName;
                        query += fieldName;
                        SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)" ");
                        SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)outQuery.c_str());
                        EnableWindow(hwndListBox, FALSE);
                        EnableWindow(hwndOperationsList, TRUE);
                    }


                    break;
                }
                case LBN_ERRSPACE:
                {
                    MessageBox(NULL, "Memory", "Error", MB_OK | MB_ICONERROR);
                    break;
                }

                default: break;
            }

            switch (LOWORD(wParam))
            {
                //Edit - поле ввода названия таблицы
                case CM_EDITBTN_PRESSED:
                {
                    GetWindowText(hwndEditTableName, tableName, 128);

                    queryTableNames = "SELECT * FROM ";
                    queryTableNames += tableName;
                    const char* q = queryTableNames.c_str();
                    mysql_query(conn, q);

                    if (res = mysql_store_result(conn))
                    {
                        hwndListBox = CreateWindow("listbox", NULL,
                                               WS_CHILD | WS_VISIBLE | LBS_STANDARD ,
                                               210, 0,
                                               150, 200,
                                               hWnd,
                                               (HMENU)IDC_LISTVIEW,
                                               hInst, NULL);
                        if (!hwndListBox)
                        {
                            MessageBox(NULL, "ListBox create Failed.", "Error", MB_OK | MB_ICONERROR);
                            break;
                        }
                        while((field = mysql_fetch_field(res)))
                        {
                            SendMessage(hwndListBox, LB_ADDSTRING, 0, (LPARAM)field->name);
                        }
                        hwndQueryStatic = CreateWindow("STATIC", "",
                                                   WS_CHILD | WS_VISIBLE,
                                                   0, 30,
                                                   200, 165,
                                                   hwndTR, nullptr, hInst, NULL);
                        ShowWindow(hwndQueryStatic, SW_SHOWNORMAL);

                        hwndBtnOk = CreateWindow("button", "OK",
                                             WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                             450, 10,
                                             50, 25,
                                             hWnd, (HMENU)BTN_OK, hInst, NULL);

                        hwndResTable = CreateListView(hWnd, ID_RESTABLE);
                        ShowWindow(hwndResTable, SW_SHOWNORMAL);
                        if (state == 2)
                        {
                            hwndBtnNext = CreateWindow("button", "NEXT",
                                                       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                                       450, 45,
                                                       50, 25,
                                                       hWnd, (HMENU)BTN_NEXT, hInst, NULL);
                        }
                    }
                    else
                    {
                        MessageBox(NULL, mysql_error(conn), "Error", MB_OK | MB_ICONERROR);
                        SetWindowText(hwndEditTableName, "");
                    }

                    queryTableNames = "";
                    break;
                }
                //Нажатие кнопки ОК
                case BTN_OK:
                {
                    if(outQuery.empty() || fields.empty())
                    {
                        MessageBox(hWnd, "Incorrectly query", "Query Error", MB_OK | MB_ICONERROR);
                        break;
                    }
                    if(!isWhereCondition)
                    {
                        EnableWindow(hwndEditTableName, FALSE );
                        EnableWindow(hwndListBox, FALSE);
                        EnableWindow(hwndBtnOk, FALSE);

                        query.clear();
                        query += "SELECT ";
                        for(int i = 0; i < fields.size(); i++)
                        {
                            if(i == 0)
                            {
                                query += fields[i];
                                continue;
                            }
                            query += ", ";
                            query += fields[i];
                        }
                        query += " FROM ";
                        query += tableName;//"student";

                        //Если режим запроса
                        if(state == 2)
                        {
                            //Отключение кнопки NEXT(переход в состояние 8)
                            EnableWindow(hwndBtnNext, FALSE);
                        }

                    }
                    else
                    {
                        EnableWindow(hwndListBox, FALSE );
                        EnableWindow(hwndBtnOk, FALSE );
                        EnableWindow(hwndBtnNext, FALSE );
                        EnableWindow(hwndOperationsList, FALSE );
                        EnableWindow(hwndEditTableName, FALSE );
                    }
                    //MessageBox(hWnd, query.c_str(), "BTN_OR QUERY", MB_OK);
                    const char* q = query.c_str();
                    mysql_query(conn, q);
                    res = mysql_store_result(conn);

                    //Структура для создания столбцов
                    LVCOLUMN structColumn;
                    memset(&structColumn, 0, sizeof(structColumn));
                    structColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
                    structColumn.fmt = LVCFMT_LEFT;
                    structColumn.cx = 100; //ширина столбца

                    int i = 0;
                    while(field = mysql_fetch_field(res))
                    {
                        structColumn.pszText = field->name;
                        ListView_InsertColumn(hwndResTable, i, &structColumn);
                        i++;
                    }

                    //структура для создания строк
                    LV_ITEM lvi;
                    lvi.mask = LVIF_TEXT;
                    lvi.pszText = "1";

                    int colCount;
                    colCount = mysql_num_fields(res);

                    i = 0;

                    while(row = mysql_fetch_row(res))
                    {
                        for(int j = 0; j < colCount; j++)
                        {
                            lvi.iItem = i;
                            lvi.iSubItem = j;
                            ListView_InsertItem(hwndResTable, &lvi);
                            ListView_SetItemText(hwndResTable, i, j, row[j]);
                        }
                        i++;
                    }
                    EnableMenuItem(hMainMenu, 0, MF_ENABLED | MF_BYPOSITION );
                    query.clear();
                    break;
                }
                //Нажатие кнопки NEXT
                case BTN_NEXT:
                {
                    if(outQuery.empty() || fields.empty())
                    {
                        MessageBox(hWnd, "Incorrectly query", "Query Error", MB_OK | MB_ICONERROR);
                        break;
                    }
                    EnableWindow(hwndEditTableName, FALSE );
					EnableWindow(hwndBtnNext, FALSE);

                    query.clear();
                    query += "SELECT ";
                    for(int i = 0; i < fields.size(); i++)
                    {
                        if(i == 0)
                        {
                            query += fields[i];
                            continue;
                        }
                        query += ", ";
                        query += fields[i];
                    }
                    query += " FROM ";
                    query += tableName;//"student";
                    outQuery += " WHERE ";
                    SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)" ");
                    SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)outQuery.c_str());
                    query += " WHERE ";
                    isWhereCondition = true;

                    hwndOperationsList = CreateWindow("ComboBox", NULL,
                            WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS,
                            375, 80,
                            60, 500,
                            hWnd, (HMENU)ID_COMBOBOX, hInst, NULL);
                    for(int i = 0; i < 8; i++)
                    {
                        SendMessage(hwndOperationsList, CB_ADDSTRING, 0, (LPARAM)operations[i]);
                    }

                    hwndEnterValue = CreateWindow("Edit",
                                                  "",
                                                  WS_CHILD | WS_BORDER | WS_VISIBLE | ES_LEFT,
                                                  375, 130,
                                                  200, 25,
                                                  hWnd,
                                                  (HMENU)CM_EDITBTN_ENTER_VALUE,
                                                  hInst,
                                                  NULL);

                    DefEditProc = (WNDPROC)GetWindowLongPtr(hwndEnterValue, GWLP_WNDPROC);
                    SetWindowLongPtr(hwndEnterValue, GWLP_WNDPROC, (LPARAM)NewEditEnterValueProc);

                    break;
                }
                //Edit - поле ввода значения для сравнения в условии WHERE
                case CM_EDITBTN_ENTER_VALUE_PRESSED:
                {
                    it++;
                    GetWindowText(hwndEnterValue, enteredValue, 1024);
                    if((enteredValue[0] >= '0' && enteredValue[0] <= '9') || (enteredValue[1] >= '0' && enteredValue[1] <= '9'))
                    {
                        outQuery += enteredValue;
                        query += enteredValue;
                    }
                    else
                    {
                        outQuery += "\"";
                        string tmp = enteredValue;
                        if(it >= 2)
                        {
                            tmp.erase(0, 1);
                        }
                        outQuery += tmp;
                        outQuery += "\"";
                        query += "\"";
                        query += tmp;
                        query += "\"";
                    }
                    SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)" ");
                    SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)outQuery.c_str());


                    EnableWindow(hwndListBox, TRUE);
                    EnableWindow(hwndOperationsList, TRUE);
                    SendMessage(hwndEnterValue, WM_SETTEXT, (WPARAM)0, (LPARAM)" ");
                    break;
                }
                //Выпадающий список оперций
                case ID_COMBOBOX:
                {
                    switch (HIWORD(wParam))
                    {
                        //Выбор операции из списка операций
                        case CBN_SELCHANGE:
                        {
                            operationsIndex = (int)SendMessage(hwndOperationsList, CB_GETCURSEL, 0, 0L);
                            if (operationsIndex != LB_ERR)
                            {
                                SendMessage(hwndOperationsList, CB_GETLBTEXT, (WPARAM)operationsIndex, (LPARAM)operation);

                                outQuery += " ";
                                outQuery += operation;
                                outQuery += " ";
                                SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)" ");
                                SendMessage(hwndQueryStatic, WM_SETTEXT, (WPARAM)0, (LPARAM)outQuery.c_str());

                                query += " ";
                                query += operation;
                                query += " ";

                                EnableWindow(hwndOperationsList, FALSE);
                            }

                            break;
                        }

                        case CBN_ERRSPACE:
                        {
                            MessageBox(hWnd, "ComboBox Memory", "Err", MB_OK | MB_ICONERROR);
                            break;
                        }
                        default: return 0;
                    }
                    break;
                }

                default: return 0;
            }

            break;
        }

        case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            break;
        }

        case WM_DESTROY:
        {
            //PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);

    }

}
//Функция создания таблицы для вывода ответа на запрос
HWND CreateListView(HWND hWndParent, UINT uId)
{
    INITCOMMONCONTROLSEX icex;
    //icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC  = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&icex);

    RECT rcl;
    GetClientRect(hWndParent, &rcl);

    HWND hWndLV = CreateWindowEx(NULL,  WC_LISTVIEW, "",
                               WS_CHILD | WS_BORDER | LVS_REPORT | LVS_REPORT | LVS_EDITLABELS |LVS_EX_FULLROWSELECT,
                               0, 250,
                               600, 350,
                               hWndParent, (HMENU)uId, hInst, NULL);


    // Чтобы определялись строка (item) и столбец (subitem) обязательно устанавливаем
    // расширенный стиль LVS_EX_FULLROWSELECT.
    ListView_SetExtendedListViewStyleEx(hWndLV, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    return (hWndLV);
}

//Функция изменения функции окна класса Edit для ввода названия таблицы, чтобы обрабатывался Enter
LRESULT CALLBACK NewEditProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CHAR:
        {
            if (wParam == 13)  //13 - enter
            {
                SendMessage(GetParent(hwnd), WM_COMMAND, CM_EDITBTN_PRESSED, 0);
                return(0);
            }
            break;
        }
    }
    return((LRESULT)CallWindowProc((WNDPROC)DefEditProc, hwnd, message, wParam, lParam));
}

//Функция изменения функции окна класса Edit для ввода значения для условия WHERE, чтобы обрабатывался Enter
LRESULT CALLBACK NewEditEnterValueProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CHAR:
        {
            if (wParam == 13)  //13 - enter
            {
                SendMessage(GetParent(hwnd), WM_COMMAND, CM_EDITBTN_ENTER_VALUE_PRESSED, 0);
                return(0);
            }
            break;
        }
    }
    return((LRESULT)CallWindowProc((WNDPROC)DefEditProc, hwnd, message, wParam, lParam));
}