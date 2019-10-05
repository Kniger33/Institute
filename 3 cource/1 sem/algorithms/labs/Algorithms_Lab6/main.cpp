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

int main()
{
    int _keysCount = 50;
    int _M = 512;

    vector<string> _keys;

    for (int i = 0; i < _keysCount; ++i)
    {
        _keys.push_back(CreateKey());
    }

    return 0;
}