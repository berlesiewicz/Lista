#pragma once
#include <iostream>
#include <string>
#include "intlist.cpp"

//using namespace std;

class Element
{   public:
    int value;
    class Element *next;
    Element()   //KONSTRUKTOR
    {   value = 0;
        next = NULL;
    }
};

class IntList
{
    public:
    class Element *beg;
    std::string name;

    Element *create_el(int new_value);				   //utworzenie nowego elementu i zwrócenie wskaŸnika
    int add_el_ind(int value, unsigned int index);       //dodaje element o wartoœci "value" w miejsce "index" do listy; zwraca 0 - powodzenie, -1 - niepowodzenie (za krótka lista)
    int add_el_beg(int value);       				//dodanie elementu na początek
    int add_el_aft(int value, int after);        //dodaje element o wartoœci "value" po elementach o wartoœci "after" do listy; zwraca liczbê dodanych elementów
    int del_el_ind(unsigned int index);  		//usuwa el. o podanym indeksie zwr -1 jeśli się nie udało
    int del_el_val(int valdel);   				//usuwa pierwszy element o podanej wartości "valdel", zwraca indeks usuniętego elementu lub -1 jeśli nie było szukanego el.
    int del_el_btw(int value_1, int value_2);    //zwraca liczbę usuniętych elementów
    Element *get_el_ind(unsigned int index);  	//zwrócenie wskaźnika na element o przekazanym indeksie (NULL jeśli nie ma takiego)
    Element *get_el_val(int demanded);  	//zwrócenie wskaźnika na element o żądanej wartości (NULL jeśli nie ma takiego)
    int add_lists(IntList *other);    		//Dodaje przekazaną listę na koniec
    int subtract_lists(IntList *other);  	//odejmuje od listy elementy z przekazanej listy
    IntList *copy_list();    				//zwraca wskaźnik na skopiowaną listę
    int del_rep_el();    					//usuwa wartości powtarzające się na liście, sostawia tyklo pierwsze elementy
    unsigned int length();
    int compare(IntList *other);     		//zwraca o ile lista jest dłuższa od listy "other" (wart ujemne - "other" dłuższa, 0 - równe, wart. dodatnie - "other" krótsza

    IntList()   				//konstruktor
    {   name = "DEFAULTNAME";
        beg = NULL;
    }
};


