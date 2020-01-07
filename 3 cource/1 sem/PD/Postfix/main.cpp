#include <iostream>
#include <string>
using namespace std;

int main() {
    string str,stack;
    char word, word_last;
    while(cin>>word){
        if((word>=48)&&(word<=57)){ //если символ это число
            if((word_last>=48)&&(word_last<=57)){ // Проверка, я вляется ли предыдущий символ - числом
                str+=word; //Если да , то просто добавляем его, тем самым не разрушая число
            }
            else{
                str+=' '; // В противном  случае добавляем пробел и добавляем символ в главную строку
                str+=word;
            }
        }

        if(((word>=42)&&(word<=47))||(word==94)){ //если символ это операнд
            if(word=='*'){  //Замена умножения
                word='.';
            }
            if(word=='-'){ //Замена минуса
                word=',';
            }
            if(stack.empty()){ //  Если стэк пустой - то просто кладем символ в стэк
                stack+=word;
            }
            else{	 // Если стэк не пуст
                if((stack.back()>=word)||(stack.back()==word-1)||(stack.back()==word+1)){ // Если  верхний элемент стэка имеет больший приоритет
                    while((stack.back()>=word)||(stack.back()==word-1)||(stack.back()==word+1)){ //выталкиваем все элементы из стэка
                        str+=' ';														//До тех пор, пока приоритет верхнего элемента не будет
                        str+=stack.back();													//ниже входящего символа
                        stack.pop_back();
                    }
                    stack+=word;
                }
                else{ // если же верхний элемент ниже приоритетом - то просто кладем символ в стэк
                    stack+=word;
                }
            }
        }
        if(word=='('){ //Если символ - открывающая скобка
            stack+=word;  //добавляем ее в стэк
        }
        if(word==')'){    //Если встречающийся симвлл - закрывающая скобка
            while(stack.back()!='('){ // пока в стэке не встретится открывающая скобка
                str+=' ';        // выталкиваем в главную строку  все символы
                str+=stack.back();
                stack.pop_back();
            }
            stack.pop_back(); //Удаляем открывающую скобку из стека
        }

        word_last=word; //Присваеваем значение текущего символа для проверки в последующем цикле

        /*cout << "Numb:" << 0 << endl; // Распечатка пошаговых действий
        cout << "Word:  |" << word << endl;
        cout <<"STR:| "  << str <<"|  SRA:|" << stack << endl;*/

        if(word == 'q')
        {
            break;
        }
    }
    while(!stack.empty()){ //При окончании строки выталкиваем все символы из стека
        str+=' ';
        str+=stack.back();
        stack.pop_back();
    }

    for( int i=0; i<str.length();i++){ // Проходим циклом финальную строку для возврата тербуемых символов
        if(str[i]=='.')
            str[i]='*';
        if(str[i]==',')
            str[i]='-';
    }

    cout <<"FINAL:___  " <<  str << endl;
    return 0;
}