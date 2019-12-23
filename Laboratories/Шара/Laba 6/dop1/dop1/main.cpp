//
//  main.cpp
//  dop1
//
//  Created by Пушнова Алиса Сергеевна on 12/1/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

string Replace_All(string, string, string);
string Replace_All_With_Dictionary(string, list<tuple<string, string>>);
string Remove_Double_Chars(string);

int main()
{
    string text = "Xxx Too swift for Theex, too quick for Gallow,\nToo strong for young Prince Joseph to follow.tt";
    
    cout << text << endl << endl;
    
    list < tuple < string, string > > dictionary =
    {
        {"you", "u"},
        { "oo", "u" },
        { "ce", "se" },
        { "ci", "si" },
        { "cy", "sy" },
        { "c", "k" },
        { "qu", "kv" },
        { "q", "k" },
        { "x", "ks" },
        { "w", "v" },
        { "ph", "f" },
        { "ee", "i" },
        { "th", "z" }
    };
    
    text = Replace_All_With_Dictionary(text, dictionary);
    
    text = Remove_Double_Chars(text);
    
    cout << text << endl;
   
    return 0;
}

string Replace_All(string source, string sub, string with)
{
    string altsub = "";
    altsub += (char)(toupper(sub[0])); // toupper выполняет преобразование строчных букв в прописные.
    for (unsigned int i = 1; i < sub.length(); i++)
    {
        altsub += sub[i];
    }
    
    string altwith = "";
    altwith += (char)(toupper(with[0]));
    for (unsigned int i = 1; i < with.length(); i++)
    {
        altwith += with[i];
    }
    
    while (source.find(altsub) != string::npos)
    {
        int long pos = source.find(altsub);
        source.erase(pos, altsub.length());
        source.insert(pos, altwith);
    }
    
    while (source.find(sub) != string::npos)
    {
        int long pos = source.find(sub);
        source.erase(pos, sub.length());
        source.insert(pos, with);
    }
    
    return source;
}

string Replace_All_With_Dictionary(string text, list<tuple<string, string>> dict)
{
    for (auto d : dict)
    {
        text = Replace_All(text, get<0>(d), get<1>(d));
    }
    
    return text;
}

string Remove_Double_Chars(string src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        if (src[i] == src[i + 1])
        {
            src.erase(i + 1, 1);
            i--;
        }
        i++;
    }
    
    return src;
}



