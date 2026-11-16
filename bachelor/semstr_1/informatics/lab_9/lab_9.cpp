#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
using namespace std;

int count_words(string s){
    int count = 1;
    for (int i = 0; i < size(s); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
int count_sogl(string s)
{
    int count = 0;
    string sogl = "цкнгшщзхфвпрлджчсмтбЦКНГШЩХФВПРЛДЖЧСМТБ";
    for (int i = 0; i < size(s); i++)
    {
        if (sogl.find(s[i]) != string::npos)
            count++;
    }
    return count;
}

int main()
{
    setlocale(LC_ALL,".UTF8");
    string s;

    ofstream F1("F1.txt",ios_base::out);
    if (F1.is_open()){
        F1 << "Я просто слепну, ведь твоей красоты не может выдержать глаз" << endl
        << "И мне прозреть приходится, чтобы ещё хотя бы" << endl
        << "раз" << endl
        << "Увидеть тебя голою, худую или" << endl
        << "полную" << endl
        << "Прыщавой или чистою — мне, честно, просто пофигу" << endl
        << "Офигительна, ослепительна" << endl
        << "Невозможно совсем не любить тебя" << endl
        << "Руки целовал твоим родителям" << endl
        << "Все другие тёлки на любителя!" << endl
        << "Офигительна, ослепительна" << endl
        << "Невозможно совсем не любить тебя" << endl
        << "Руки целовал твоим родителям" << endl
        << "Все другие тёлки на любителя!" << endl;
    }
    F1.close();
    ifstream F("F1.txt");

    ofstream F2("F2.txt",ios_base::out);
    if (F2.is_open()){
        while (getline(F,s)){
            if (count_words(s) == 1)
            {
                F2 << s << endl;
                cout << "Добавлена в F2 строка: " << s << endl;
            }
        }
        int index = 0,max = 0,num;
        s = "";
        while(F >> s){
            index++;
            int f = count_sogl(s);
            if (max < f){
                num = index;
                max = f;
            }
        }
        cout << "Наибольшее кол-во согласных в слове под номером " << num;
    }
    F.close();
    F2.close();
    return 0;
}