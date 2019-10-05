#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <time.h>
#include "Functions.h"

using namespace std;

void DictInsert(map<int, int> &dict, int key)
{
    if(dict.find(key) == dict.end())
    {
        dict.insert(pair<int, int>(key, 1));
    }
    else
    {
        dict[key]++;
    }
}

void Print(map<int, int> &dict, ofstream &ofstream)
{
    map <int, int>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++)
    {
        ofstream << (*it).first << "    " << (*it).second << endl;
    }
}

string CreateKey()
{
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    string res;

    for (int i = 0; i < 6; ++i)
    {
        res += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    cout << "KEY: " << res << endl;

    return res;
}

int main() {

    srand(time(nullptr));

    int _keysCount = 50;
    int _M = 64;

    map<int, int> dictAddDiv;
    map<int, int> dictAddMult;
    map<int, int> dictExcDiv;
    map<int, int> dictExcMult;

    vector<string> _keys;

    for (int i = 0; i < _keysCount; ++i)
    {
        _keys.push_back(CreateKey());
    }

    for (int i = 0; i < _keysCount; ++i)
    {
        int key = HashDivision(HashAdditive(_keys[i]), _M);
        DictInsert(dictAddDiv, key);

        key = HashMultiply(HashAdditive(_keys[i]), _M);
        DictInsert(dictAddMult, key);

        key = HashDivision(HashExcludive(_keys[i]), _M);
        DictInsert(dictExcDiv, key);

        key = HashMultiply(HashExcludive(_keys[i]), _M);
        DictInsert(dictExcMult, key);
    }

    ofstream fout;
    fout.open("data.txt");

    fout << "AddDiv" << endl;
    fout << "Key   Value" << endl;
    Print(dictAddDiv, fout);

    fout << endl << "AddMult" << endl;
    fout << "Key   Value" << endl;
    Print(dictAddMult, fout);

    fout << endl << "ExcDiv" << endl;
    fout << "Key   Value" << endl;
    Print(dictExcDiv, fout);

    fout << endl << "ExcMult" << endl;
    fout << "Key   Value" << endl;
    Print(dictExcMult, fout);

    fout.close();

    return 0;
}