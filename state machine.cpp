#include <iostream>
#include <string>
using namespace std;

bool virazenie(string& str);
bool virazenieZvezda(string& str);
bool checkChar(char& chara);
bool zveno(string& str);
bool zvenoZvezda(string& str);
bool slagaemo(string& str);
bool mnozitel(string& str);
bool mnozitelZvezda(string& str);
bool skoba(string& str);
char cutStr(string& str);
bool checkZvezda(char& chara);
bool checkPlus(char& chara);

bool virazenie(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (checkChar(chara))
    {
        result = zveno(str);
    }
    else if (chara == '(')
    {
        result = skoba(str);
        char chara = cutStr(str);
        if (checkZvezda(chara))
        {
            result = mnozitel(str);
        }
    }
    if (str != "")
        result = false;
    return result;
}

bool virazenieZvezda(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (checkChar(chara))
    {
        result = zvenoZvezda(str);
    }
    else if (chara == '(')
    {
        result = skoba(str);
        char chara = cutStr(str);
        if (checkZvezda(chara))
        {
            result = mnozitel(str);
        }
    }
    return result;
}

bool checkChar(char& chara)
{
    if (chara > 96 && chara < 123)
    {
        return true;
    }
    return false;
}

bool zveno(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (chara == '3')
    {
        result = true;
    }
    else if (chara == ')')
    {
        str = ")" + str;
        result = true;
    }
    else if (checkPlus(chara))
    {
        result = slagaemo(str);
    }
    else if (checkZvezda(chara))
    {
        result = mnozitel(str);
    }
    return result;
}

bool zvenoZvezda(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (chara == '3')
    {
        result = true;
    }
    else if (checkZvezda(chara))
    {
        result = mnozitelZvezda(str);
    }
    else if (checkPlus(chara))
    {
        str = chara + str;
        return true;
    }
    return result;
}

bool slagaemo(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (checkChar(chara))
    {
        result = zveno(str);
    }
    else if (chara == '(')
    {
        result = skoba(str);
        char chara = cutStr(str);
        if (checkZvezda(chara))
        {
            result = mnozitel(str);
        }
    }
    return result;
}

bool mnozitel(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (checkChar(chara))
    {
        result = zveno(str);
    }
    else if (chara == '(')
    {
        result = skoba(str);
        if(result)
            result = zveno(str);
    }
    return result;
}

bool mnozitelZvezda(string& str)
{
    char chara = cutStr(str);
    bool result = false;
    if (checkChar(chara))
    {
        result = zvenoZvezda(str);
    }
    else if (chara == '(')
    {
        result = skoba(str);
        if (result)
            result = zvenoZvezda(str);
    }
    return result;
}

bool skoba(string& str)
{
    char chara;
    bool result = false;
    result = virazenieZvezda(str);
    chara = cutStr(str);
    if (checkPlus(chara) && result)
    {
        result = slagaemo(str);
        if (result)
        {
            chara = cutStr(str);
            if (chara == ')')
                result = true;
            else
                result = false;
        }
    }
    return result;
}

char cutStr(string& str)
{
    char chara;
    if (str.length() == 0)
    {
        chara = '3';
    }
    else
    {
        chara = str[0];
        str = str.substr(1, str.length() - 1);
    }
    return chara;
}

bool checkZvezda(char& chara)
{
    if (chara == '*' || chara == '/')
    {
        return true;
    }
    return false;
}

bool checkPlus(char& chara)
{
    if (chara == '+' || chara == '-')
    {
        return true;
    }
    return false;
}

int main()
{
    string str;
    while (true)
    {
        getline(cin, str);
        if (str == "0")
            break;

        bool result = virazenie(str);
        if (result)
            cout << "correct!" << endl << endl;
        else
            cout << "incorrect!" << endl << endl;
    }
    return 0;
}
