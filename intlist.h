#include <iostream>
#include <string>

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
    Element *create_el(int new_value)   //utworzenie nowego elementu i zwrócenie wskaŸnika
    {
        Element * new_el = new Element;
        new_el->value = new_value;
        return new_el;
    }
    int add_el_ind(int value, unsigned int index)       //dodaje element o wartoœci "value" w miejsce "index" do listy; zwraca 0 - powodzenie, -1 - niepowodzenie (za krótka lista)
    {   Element *new_el = create_el(value);     //powstaje nowy element z wpisan¹ ju¿ wartoœci¹     ////int error = 0;
        if(index==0)                //jeœli dodanie na pocz¹tek to nie zmienia siê wskaŸnika w poprzednim elemencie, tylko wskaŸnik pocz¹tku listy
        {   new_el->next=beg;
            beg = new_el;
        }
        else
        {   unsigned int i = 0;
            Element *prev = NULL;
            Element *curr = beg;
            while(i!=index)
            {   if(curr==NULL)      //(ewentualna modyfikacja, ¿eby zamiast zwracaæ b³¹d dodawa³a na koniec listy)
                {   delete new_el;  //nie ma takiego miejsca
                    return -1;
                }
                prev = curr;
                curr = curr->next;
                i++;
            }
            prev->next = new_el;
            new_el->next = curr;
        }
        return 0;
    }
    int add_el_beg(int value)       //dodanie elementu na początek
    {   if(add_el_ind(value, 0)==0) {return 0;}  //czyli dodanie na miejscu i indeksie 0
        else {return -1;}
    }
    int add_el_aft(int value, int after)        //dodaje element o wartoœci "value" po elementach o wartoœci "after" do listy; zwraca liczbê dodanych elementów
    {   Element *curr = beg;
        int n = 0;              //liczba dodanych
        while(curr!=NULL)
        {   if(curr->value==after)
            {   Element *new_el = create_el(value);     //powstaje nowy element z wpisan¹ ju¿ wartoœci¹
                new_el->next = curr->next;
                curr->next = new_el;
                curr = new_el;

            }
            curr = curr->next;
        }
        return n;
    }
    int del_el_ind(unsigned int index)  //usuwa el. o podanym indeksie zwr -1 jeśli się nie udało
    {   if(beg==NULL)
        {   return -1;      //jeśli nie ma żadnych elementów
        }
        Element *curr = beg;
        Element *prev = NULL;
        unsigned int i = 0;
        while(i!=index)
        {   if(curr->next==NULL)
            {   return -1;     //jeśli koniec listy, a el. powinien być dalej
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(index==0)
        {   beg = curr->next;        //początek na następnym
        }
        else
        {   prev->next = curr->next; //odczepienie z listy
        }
        delete curr;            //zwolnienie pamięci
        return 0;
    }
    int del_el_val(int valdel)   //usuwa pierwszy element o podanej wartości "valdel", zwraca indeks usuniętego elementu lub -1 jeśli nie było szukanego el.
    {   if(beg==NULL)
        {   return -1;
        }
        Element *curr = beg;
        Element *prev = NULL;
        while(curr->value!=valdel)  //jeśli to jeszcze nie ta wartość
        {   if(curr->next==NULL)    //jeśli nie ma już więcej el.
            {   return -1;
            }
            prev = curr;
            curr = curr->next;
        }
        if(prev==NULL)          //jeśli na samym początku
        {   beg = curr->next;
        }
        else
        {   prev->next = curr->next;
        }
        delete curr;
        return 0;
    }
    int del_el_btw(int value_1, int value_2)    //zwraca liczbę usuniętych elementów
    {   if(value_1 > value_2)
        {   int v;
            v = value_1;
            value_1 = value_2;
            value_2 = v;
        }
        if(beg==NULL)
        {   return 0;
        }
        Element *curr = beg;
        Element *prev = NULL;
        int n = 0;                                              //licznik usuniętych
        while(curr!=NULL)                                       //aż do końca listy
        {   if(curr->value>=value_1 && curr->value<=value_2)    //jesli wartość w zakresie
            {   if(prev==NULL)                                  //jeślli początek llisty
                {   beg = curr->next;
                    delete curr;
                    curr = beg;
                }
                else
                {   prev->next = curr->next;
                    delete curr;
                    n++;
                    curr = prev->next;
                }
                n++;
            }
            else
            {   prev = curr;
                curr = curr->next;
            }

        }
        return n;
    }
    Element *get_el_ind(unsigned int index)  //zwrócenie wskaźnika na element o przekazanym indeksie (NULL jeśli nie ma takiego)
    {   Element *curr = beg;
        for(unsigned int i = 0; curr!=NULL; i++)
        {   if(i==index)
            {   break;
            }
            curr = curr->next;
        }
        return curr;
    }
    Element *get_el_val(int demanded)  //zwrócenie wskaźnika na element o żądanej wartości (NULL jeśli nie ma takiego)
    {   Element *curr = beg;
        while(curr!=NULL)
        {   if(curr->value==demanded)
            {   break;
            }
            curr = curr->next;
        }
        return curr;
    }
    int add_lists(IntList *other)    //Dodaje przekazaną listę na koniec
    {   Element *curr = beg;
        if(beg==NULL)
        {   beg = other->beg;
        }
        else
        {    while(curr->next!=NULL)
            {   curr = curr->next;
            }
            curr->next = other->beg;
        }
    return 0;
    }
    int subtract_lists(IntList *other)  //odejmuje od listy elementy z przekazanej listy
    {   Element *curr = other->beg;
        while(curr!=NULL)               //usuwa z listy kolejno elementy, które występują w przekazanej liście
        {   del_el_val(curr->value);
            curr = curr->next;
        }
        return 0;
    }
    IntList *copy_list()    //zwraca wskaźnik na skopiowaną listę
    {   IntList *copied = new IntList;
        copied->name = name + " - copy";
        if(beg!=NULL)
        {   copied->beg = new Element;      //początek listy
            copied->beg->value = beg->value;
            Element *curr_origin = beg;
            Element *curr_copied = copied->beg;
            while(curr_origin->next!=NULL)  //dopóki są elementy do skopiowania
            {   curr_origin = curr_origin->next;
                curr_copied->next = new Element;
                curr_copied = curr_copied->next;
                curr_copied->value = curr_origin->value;
            }

        }
        return copied;
    }
    int del_rep_el()    //usuwa wartości powtarzające się na liście, sostawia tyklo pierwsze elementy
    {   Element *leave = beg;
        while(leave!=NULL)        //kolejne elementy o wartości takiej jak "leave" zostaną usuniete
        {   Element *curr = leave->next;
            Element *prev = leave;
            //int j=(i+1);
            while(curr!=NULL)
            {   if(leave->value==curr->value)
                {   prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                else
                {   prev = curr;
                    curr = curr->next;
                }
            }
            leave = leave->next;
        }
        return 0;
    }
    unsigned int length()
    {   unsigned int n=0;
        for(Element *curr = beg;curr!=NULL;n++)
        {   curr=curr->next;
        }
        return n;
    }
    int compare(IntList *other)     //zwraca o ile lista jest dłuższa od listy "other" (wart ujemne - "other" dłuższa, 0 - równe, wart. dodatnie - "other" krótsza
    {   unsigned int this_l = length();
        unsigned int that_l = other->length();
        int compared = this_l - that_l;
        return compared;
    }
    IntList()   //konstruktor
    {   name = "DEFAULTNAME";
        beg = NULL;
    }
};


