#include <iostream>
#include <string>
#include "intlist.h"

using namespace std;

//PROGRAM TESTUJĄCY KLASĘ
int show_list(IntList given)
{   Element *curr = given.beg;
    std::cout << given.name << ": " << endl;
    while(curr!=NULL)
    {   std::cout << curr->value << endl;
        curr = curr->next;
    }
    return 0;
}

int main()
{
    IntList list1, list2;
    if(list1.beg==NULL)
    {   cout << "lista1: ma nulla i nazwe " << list1.name << endl;
    }

    Element e1, e2, e3;
    if(e1.next==NULL)
    {   cout << "pierwszy ma nulla i wartosc" << e1.value << endl;
    }
    e3.value = 5;
    e3.next = NULL;
    e2.value = 12;
    e2.next = &e3;
    e1.value = -1;
    e1.next = &e2; //1 12 5
    list1.name = "lista pierwsza";
    list1.beg = &e1;
    //cout << e2.value;
    //Element e1, e2, e3;
    //e1.value = 5;

    cout << list1.name << endl;
    cout << e1.value << ", " << list1.beg->value << endl;
    cout << e2.value << ", " << e1.next->value << ", " << list1.beg->next->value << endl;
    cout << e3.value << ", " << e2.next->value << ", " << e1.next->next->value << ", " << list1.beg->next->next->value << endl;
    cout << "rozmiar klasy listy: " << sizeof(IntList) << endl;
    cout << "rozmiar klasy elementu: " << sizeof(IntList) << endl;

    e3.next = list1.create_el(115);   //-1 12 5 115
    e3.next->next = NULL;

    cout << e3.next->value << endl;
    e3.next->value = 112;       //-1 12 5 112
    cout << e3.next->value << endl;
    list1.add_el_ind(-5, 2);    //-1 12 -5 5 112
    cout << "nowy element o wartosci -5 na miejscu 2" << list1.beg->next->next->value << endl;

    show_list(list1);           //-1 12 -5 5 112
    list1.add_el_ind(17, 1);    //-1 17 12 -5 5 112
    show_list(list1);
    list1.add_el_ind(18, 0);    //18 -1 17 12 -5 5 112          DODAWANIE IND NA POCZ DZIAŁA
    show_list(list1);
    list1.add_el_aft(57, 12);   //18 -1 17 12 57 -5 5 112
    show_list(list1);
    list1.add_el_ind(-33, 8);   //18 -1 17 12 57 -5 5 112 -33   DODAWANIE IND NA KOŃCU DZIAŁA
    show_list(list1);
    list1.add_el_beg(11);       //11 18 -1 17 12 57 -5 5 112 -33   DODAWANIE BEG DZIAŁA
    show_list(list1);
    list1.add_el_aft(-30, -33); //11 18 -1 17 12 57 -5 5 112 -33 -30    DODAWANIE AFT NA KOŃCU DZIALA
    show_list(list1);
    list1.add_el_aft(-11, 11);  //11  -11 18 -1 17 12 57 -5 5 112 -33 -30    DODAWANIE AFT PO PIERWSZYM DZIALA
    show_list(list1);
    list1.add_el_aft(-1, -30);  //11  -11 18 -1 17 12 57 -5 5 112 -33 -30 -1
    show_list(list1);

    list2.name = "Nowa lista";
    //list2.beg = NULL;
    list2.add_el_beg(5);        //5
    show_list(list2);
    list2.add_el_beg(-18);        //-18 5
    show_list(list2);
    list2.add_el_ind(7, 1);     //-18 7 5
    show_list(list2);
    list2.add_el_aft(-3, 2);    //-18 7 5
    show_list(list2);
    list2.add_el_ind(-1, 2);    //-18 7 -1 5
    show_list(list2);
    list2.add_el_ind(-1, 2);    //-18 7 -1 -1 5
    show_list(list2);
    list2.add_el_ind(-1, 5);    //-18 7 -1 -1 5 -1
    show_list(list2);
    list2.add_el_ind(-1, 0);    //-1 -18 7 -1 -1 5 -1
    show_list(list2);
    list2.add_el_ind(-18, 5);    //-1 -18 7 -1 -1 -18 5 -1
    show_list(list2);

    show_list(list1);

    list1.add_lists(&list2);   //odjęcie od listy 1 listę 1
    show_list(list1);           //11  -11 18 -1 17 12 57 -5 112 -33 -30 -1


    list2.del_rep_el();
    show_list(list2);

    //cout << "Por:" << list1.compare(&list2) << endl;

    return 0;
}

