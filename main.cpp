#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct Pytania {
    string literka;
    string pytanie;
};

struct Fakty {
    string literka;
    string fakt;
    //bool spelniony;
};

struct Reguly_i_Wnioski {
    string pierwsza;
    string druga;
    string wynik;
    bool pierwszab;
    bool drugab;
    bool spelniona;
};

int main()
{
    Pytania *pytanie;
    Fakty *fakt;
    Reguly_i_Wnioski *regula, *wniosek;
    int i, pytania=0, fakty=0, reguly=0, wnioski=0;
    fstream plik1, plik2, plik3, plik4;
    string tekst;
    plik1.open("pytania.txt", ios::in);
    if(plik1.good()==false) cout << "Problem z otwarciem pliku1" << endl;
    else cout << "Otwarty poprawnie plik1!" << endl;
    plik2.open("reguly.txt", ios::in);
    if(plik2.good()==false) cout << "Problem z otwarciem pliku2" << endl;
    else cout << "Otwarty poprawnie plik2!" << endl;
    plik3.open("wnioski.txt", ios::in);
    if(plik3.good()==false) cout << "Problem z otwarciem pliku3" << endl;
    else cout << "Otwarty poprawnie plik3!" << endl;
    plik4.open("fakty.txt", ios::in);
    if(plik4.good()==false) cout << "Problem z otwarciem pliku4" << endl;
    else cout << "Otwarty poprawnie plik4!" << endl;
    //cout << "Liczba pytan: " << pytania << endl;
    getline(plik1, tekst);
    pytania=atoi(tekst.c_str());
    pytanie=new Pytania[pytania];
    for (i=0; i<pytania; i++)
    {
         getline(plik1, pytanie[i].literka, ' ');
         getline(plik1, pytanie[i].pytanie);
    }
    plik1.close();
    getline(plik4, tekst);
    fakty=atoi(tekst.c_str());
    fakt=new Fakty[fakty];
    for (i=0; i<fakty; i++)
    {
         getline(plik4, fakt[i].literka, ' ');
         getline(plik4, fakt[i].fakt);
    }
    plik4.close();
    getline(plik2, tekst);
    reguly=atoi(tekst.c_str());
    regula=new Reguly_i_Wnioski[reguly];
    for (i=0; i<reguly; i++)
    {
         getline(plik2, regula[i].pierwsza, ' ');
         getline(plik2, regula[i].druga, ' ');
         getline(plik2, regula[i].wynik);
         regula[i].pierwszab=false;
         regula[i].drugab=false;
         regula[i].spelniona=false;
    }
    plik2.close();
    getline(plik3, tekst);
    wnioski=atoi(tekst.c_str());
    wniosek=new Reguly_i_Wnioski[wnioski];
    for (i=0; i<wnioski; i++)
    {
         getline(plik3, wniosek[i].pierwsza, ' ');
         getline(plik3, wniosek[i].druga, ' ');
         getline(plik3, wniosek[i].wynik);
         wniosek[i].pierwszab=false;
         wniosek[i].drugab=false;
         wniosek[i].spelniona=false;
    }
    plik3.close();
    //cout << fakt[4].fakt << endl;
    for (int j=0; j<pytania; j++) //zadaje pytania
    {
        cout << pytanie[j].pytanie << endl;
        cin >> tekst;
        if (tekst=="tak" || tekst=="Tak")
        {
            for (int k=0; k<reguly; k++)
            {
                if (pytanie[j].literka==regula[k].pierwsza) regula[k].pierwszab=true;
                else if (pytanie[j].literka==regula[k].druga) regula[k].drugab=true;
                if (regula[k].pierwszab==true && regula[k].drugab==true) regula[k].spelniona=true;
            }
        }
    }
    for (int z=0; z<wnioski; z++)
    {
        for (int x=0; x<reguly; x++)
        {
            if (wniosek[z].pierwsza==regula[x].wynik && regula[x].spelniona==true) wniosek[z].pierwszab=true;
            else if (wniosek[z].druga==regula[x].wynik && regula[x].spelniona==true) wniosek[z].drugab=true;
            if (wniosek[z].pierwszab==true && wniosek[z].drugab==true) wniosek[z].spelniona=true;
            //cout << wniosek[z].pierwszab << " " << wniosek[z].drugab << " " << wniosek[z].spelniona << endl;
        }
    }
    cout << endl;
    cout << "Twoje oczekiwania spelnia: " << endl;
    for (int q=0; q<wnioski; q++) //porownuje wnioski do faktow
    {
        for (int a=0; a<fakty; a++)
        {
            if (wniosek[q].spelniona==true && wniosek[q].wynik==fakt[a].literka) cout << fakt[a].fakt << endl;
        }
        //cout << wniosek[q].pierwszab << " " << wniosek[q].drugab << " " << wniosek[q].spelniona << endl;
    }
    delete []pytanie;
    delete []fakt;
    delete []regula;
    delete []wniosek;
    getch();
    return 0;
}
