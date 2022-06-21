/**ВАРИАНТ #10
В долине озер: 4, уток там живет: 37, а ферм: 1, дней сезона охоты: 7
На Озере 'Тоба' живут следующие виды уток:
    Утка вид: 'Гоголи', умеет: плавать и не знает где она живет, а также имеет атрибуты: имя, вес, высота, окрас хвоста
    Утка вид: 'Лайсанская кряква', умеет: ползать и не знает где она живет, а также имеет атрибуты: имя, вес, окрас оперения, сила
На Озере 'Кратерное Озеро' живут следующие виды уток:
    Утка вид: 'Крохали', умеет: летать и знает где она живет, а также имеет атрибуты: имя, вес, здоровье, окрас хвоста
    Утка вид: 'Хохлатая утка', умеет: ползать и не знает где она живет, а также имеет атрибуты: имя, вес, здоровье, форма клюва
На Озере 'Мьоса' живут следующие виды уток:
    Утка вид: 'Широконоска', умеет: летать и знает где она живет, а также имеет атрибуты: имя, вес, ловкость, размер клюва
    Утка вид: 'Широконоска', умеет: бегать и не знает где она живет, а также имеет атрибуты: имя, вес, форма хвоста, форма клюва
На Озере 'Иссык-Куль' живут следующие виды уток:
    Утка вид: 'Мадагаскарская кряква', умеет: летать и не знает где она живет, а также имеет атрибуты: имя, вес, здоровье, окрас крыльев
    Утка вид: 'Капский чирок', умеет: ползать и не знает где она живет, а также имеет атрибуты: имя, вес, высота в холке, выносливость
Ферма 'JATAPOB' имеет охотников в количестве: 1
    Охотник #1 может поймать уток в количестве: 2-5
С фермы 'JATAPOB' могут сбежать утки, которые умеют: плавать и не знают где они живут, то есть возвращаются в случайное озеро

ДОП. ЗАДАНИЕ:
    В долине в случайном месте (озере или ферме) может появиться: КреативныйКряк (Утка, может придумать любой собственный эффект или героя) на дней: 3
*/

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string names[18] = {"Александр", "Дмитрий", "Максим", "Сергей","Андрей","Алексей","Артём","Илья","Кирилл","Михаил","София","Лиза","Анастасия","Людмила","Ольга","Мария","Женя","Даша"};
string colors[5] = {"Черный","Белый","Голубой","Желтый","Зеленый"};
string razmer[4] = {"Средний","Маленький","Большой","Гигантский"};
string forma[4]= {"Овал", "Круг", "Квадрат", "Ромб"};
class main_duck
{
protected:
    string name;
    int weight, beg;
    main_duck *next;
public:
    friend class main_lake;
    main_duck(): name(names[rand()%18]), weight((rand()%10)+4), beg(0) {};
    virtual ~main_duck() {};
    virtual void get_info() = 0;
    virtual int is_fly() = 0; // утки, которые умеют летать
    virtual int is_swim() = 0; // утки, которые умеют плавать
    virtual int is_crawl() = 0; //утки, которые умеют ползать
    virtual int is_run() = 0; // утки, которые умеют бегать
    virtual int is_kg() = 0;  //утки с грузиком
    virtual int is_gde_ya() = 0;
    virtual void from ()=0; //утки которые сбежали
    virtual int is_beg() = 0; // добавляет утке пометку о побеге
    virtual void kg()=0;  //вешает грузик утке на лапку
    virtual int is_kreative()=0; //утка вида КреативныйКряк
};
class Gogoli: public main_duck
{
    int swim;
    int height;
    string color_tail;
public:
    Gogoli() : swim(1), height((rand()%5)+10),color_tail(colors[rand()%5]) {};
    virtual ~Gogoli() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Гоголи'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я не знаю, где я"<<endl;
        cout<<"Мой рост: "<<height<<endl;
        if(swim)
            cout<<"Я умею плавать";
        else
            cout<<"У меня на лапке грузик"<<beg;
        cout<<endl<<"Цвет моего хвоста: "<<color_tail<<endl<<endl;
    }
    virtual int is_swim()
    {
        return swim;
    }
    virtual int is_kg()
    {
        if (swim)
            return 0;
        else
            return 1;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void from()
    {
        this->beg=1;

    }
    virtual void kg()
    {
        this->swim=0;
    }
    virtual int is_beg()
    {
        return beg;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class Kreativ_kryak: public main_duck
{
public:
    Kreativ_kryak() {};
    virtual ~Kreativ_kryak() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Креативный кряк'"<<endl;
        cout<<"Мое имя: "<<name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"У меня обнаружили covid, поэтому это озеро будет закрыто для входа-выхода на 3 дня"<<endl<<endl;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void from()
    {
    }
    virtual void kg()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 1;
    }
};
class Laysanskaya_kryakva: public main_duck
{
    int power;
    string color_body;
public:
    Laysanskaya_kryakva() :power((rand()%5)+300), color_body(colors[rand()%5]) {};
    virtual ~Laysanskaya_kryakva() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Лайсанская кряква'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я не знаю, где я"<<endl;
        cout<<"Моя сила: "<<power<<endl;
        cout<<"Я умею ползать"<<endl;
        cout<<"Цвет моего оперения: "<<color_body<<endl<<endl;
    }
    virtual int is_crawl()
    {
        return 1;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual is_run()
    {
        return 0;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class Krohali: public main_duck
{
    int health;
    string color_tail;
public:
    Krohali() : health((rand()%100)+1), color_tail(colors[rand()%5]) {};
    virtual ~Krohali() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Крохали'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я знаю, где я"<<endl;
        cout<<"Мое здоровье: "<<health<<endl;
        cout<<"Я умею летать"<<endl;
        cout<<"Цвет моего хвоста: "<<color_tail<<endl<<endl;
    }
    virtual int is_fly()
    {
        return 1;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 1;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class Hohlataya_ytka : public main_duck
{
    int health;
    string beak_forma;
public:
    Hohlataya_ytka(): health((rand()%100)+1), beak_forma(forma[rand()%4]) {};
    virtual ~Hohlataya_ytka() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Хохлатая утка'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я не знаю, где я"<<endl;
        cout<<"Мое здоровье: "<<health<<endl;
        cout<<"Я умею ползать"<<endl;
        cout<<"Форма моего клюва: "<<beak_forma<<endl<<endl;
    }
    virtual int is_crawl()
    {
        return 1;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_cut()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class shirokonoska_1 : public main_duck
{
    int agility;
    string beak_razmer;
public:
    shirokonoska_1(): agility((rand()%100)+55), beak_razmer(razmer[rand()%4]) {};
    virtual ~shirokonoska_1() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Широконоска'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я знаю, где я"<<endl;
        cout<<"Моя ловкость: "<<agility<<endl;
        cout<<"Я умею летать"<<endl;
        cout<<"Размер моего клюва: "<<beak_razmer<<endl<<endl;
    }
    virtual int is_fly()
    {
        return 1;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 1;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class shirokonoska_2 : public main_duck
{
    string tail_forma;
    string beak_forma;
public:
    shirokonoska_2(): tail_forma(forma[rand()%4]), beak_forma(forma[rand()%4]) {};
    virtual ~shirokonoska_2() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Широконоска'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я знаю, где я"<<endl;
        cout<<"Форма моего хвоста: "<<tail_forma<<endl;
        cout<<"Я умею бегать"<<endl;
        cout<<"Форма моего клюва: "<<beak_forma<<endl<<endl;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 1;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class Madagaskarskaya_kryakva : public main_duck
{
    int health;
    string wings_color;
public:
    Madagaskarskaya_kryakva(): health((rand()%100)+1), wings_color(colors[rand()%5]) {};
    virtual ~Madagaskarskaya_kryakva() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Мадагаскарская кряква'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я не знаю, где я"<<endl;
        cout<<"Мое здоровье: "<<health<<endl;
        cout<<"Я умею летать"<<endl;
        cout<<"Цвет моих крыльев: "<<wings_color<<endl<<endl;
    }
    virtual int is_fly()
    {
        return 1;
    }
    virtual int is_crawl()
    {
        return 0;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class Kapskiy_chirok : public main_duck
{
    int hight_;
    int endurance;
public:
    Kapskiy_chirok(): endurance((rand()%100)+15), hight_(rand()%10+6) {};
    virtual ~Kapskiy_chirok() {};
    virtual void get_info()
    {
        cout<<"Мой вид 'Капский чирок'"<<endl;
        cout<<"Мое имя: "<< name<<endl;
        cout<<"Мой вес: "<<weight<<endl;
        cout<<"Я не знаю, где я"<<endl;
        cout<<"Моя высота в холке: "<<hight_<<endl;
        cout<<"Я умею ползать"<<endl;
        cout<<"Моя выносливость: "<<endurance<<endl<<endl;
    }
    virtual int is_crawl()
    {
        return 1;
    }
    virtual int is_swim()
    {
        return 0;
    }
    virtual int is_kg()
    {
        return 0;
    }
    virtual int is_run()
    {
        return 0;
    }
    virtual int is_fly()
    {
        return 0;
    }
    virtual int is_gde_ya()
    {
        return 0;
    }
    virtual void kg()
    {
    }
    virtual void from()
    {
    }
    virtual int is_beg()
    {
        return 0;
    }
    virtual int is_kreative()
    {
        return 0;
    }
};
class main_lake
{
    main_duck *head;
    int size_list=0;
    int count_swim;
    int count_fly;
    int count_crawl;
    int count_run;
    int count_kg;
public:
    main_lake() : head(NULL),count_kg(0), count_swim(0), count_fly(0), count_run(0),count_crawl(0) {};
    ~main_lake()
    {
        main_duck *prev = NULL;
        if(head)
        {
            while(head->next)
            {
                prev=head;
                head=head->next;
                delete prev;
                prev=NULL;
            }
            delete head;
        }
    }
    void add_(main_duck *node)
    {
        main_duck *prev = NULL;
        if(head==NULL)
        {
            head=node;
            head->next = NULL;
            size_list++;
            count_swim+=(node->is_swim());
            count_fly+=(node->is_fly());
            count_crawl+=(node->is_crawl());
            count_run+=(node->is_run());
            count_kg+=(node->is_kg());
        }
        else
        {
            prev=head;
            while((prev)&&(prev->next))
                prev=prev->next;
            if((prev)&&((prev->next)==NULL))
                prev->next = node;
            prev=prev->next;
            prev->next=NULL;
            size_list++;
            count_swim+=(node->is_swim());
            count_fly+=(node->is_fly());
            count_crawl+=(node->is_crawl());
            count_run+=(node->is_run());
            count_kg+=(node->is_kg());
        }
    }
    void print_list()
    {
        main_duck *prev = head;
        while(prev)
        {
            prev->get_info();
            prev=prev->next;

        }
    }
    int get_size_list()
    {
        return size_list;
    }
    int get_count_swim()
    {
        return count_swim;
    }
    int get_count_fly()
    {
        return count_fly;
    }
    int get_count_crawl()
    {
        return count_crawl;
    }
    int get_count_run()
    {
        return count_run;
    }
    int get_count_kg()
    {
        return count_kg;
    }
    main_duck *capture(int k)
    {
        main_duck *pr,*tmp,*q=NULL;
        pr=head;
        int i;
        if(k==0)
        {
            head=head->next;
            pr->next=NULL;
            count_swim-=(pr->is_swim());
            count_fly-=(pr->is_fly());
            count_crawl-=(pr->is_crawl());
            count_run-=(pr->is_run());
            count_kg-=(pr->is_kg());
            size_list--;
            return pr;
        }
        for(i=0; i<k-1; i++)
        {
            pr=pr->next;
        }
        tmp=pr;
        pr=pr->next;
        tmp->next=pr->next;
        pr->next=NULL;
        count_swim-=(pr->is_swim());
        count_fly-=(pr->is_fly());
        count_crawl-=(pr->is_crawl());
        count_run-=(pr->is_run());
        count_kg-=(pr->is_kg());
        size_list--;
        return pr;

    }
    main_duck *adress(int k)
    {
        main_duck *prev = head;
        int i=0;
        while(prev&&prev->next&&i<k)
        {
            i++;
            prev=prev->next;

        }
        return prev;
    }
    void proverka_pobega(main_duck *k)
    {
        if(k->is_beg()==1)
            k->kg();
    }
    void ha(main_duck *k)
    {
        k->from();
    }
    int proverka(main_duck *node)
    {
        if (node->is_gde_ya()==0 && node->is_swim()>0)
            return 1;
        else
            return 0;
    }
    int proverka_(main_duck *node)
    {
        if (node->is_kreative())
            return 1;
        else
            return 0;
    }
};
void raspredelenie (int &a1,int &a2,int &a3,int &a4,int &a5,int &a6,int &a7,int &a8)
{
    int e[8] = {1,2,3,4,5,6,7,8};
    for(int i=7; i>=1; --i) //тусуем массив, чтобы уткам не было обидно)
    {
        int j=rand()%(i+1);
        int t=e[i];
        e[i]=e[j];
        e[j]=t;
    }
    int x;
    int k=37;
    int i=0;
    while (i<8)
    {
        if(k!=0)
        {

            if (i<7)
            {
                x=rand()%k;
                k-=x;
            }
            else
                x=k;
        }
        else
            x=0;
        if(e[i]==1)
            a1=x;
        if(e[i]==2)
            a2=x;
        if(e[i]==3)
            a3=x;
        if(e[i]==4)
            a4=x;
        if(e[i]==5)
            a5=x;
        if(e[i]==6)
            a6=x;
        if(e[i]==7)
            a7=x;
        if(e[i]==8)
            a8=x;
        i++;
    }
}
main_lake toba, krater, mios, issik_kul, ferma, lake;
int ul=0,w, DAY=0, metka=0, l=-1;
void add_duck(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
{
    for(int i=0; i<a1; i++)
        toba.add_(new Gogoli);
    for(int i=0; i<a2; i++)
        toba.add_(new Laysanskaya_kryakva);
    for(int i=0; i<a3; i++)
        krater.add_(new Krohali);
    for(int i=0; i<a4; i++)
        krater.add_(new Hohlataya_ytka);
    for(int i=0; i<a5; i++)
        mios.add_(new shirokonoska_1);
    for(int i=0; i<a6; i++)
        mios.add_(new shirokonoska_2);
    for(int i=0; i<a8; i++)
        mios.add_(new Madagaskarskaya_kryakva);
    for(int i=0; i<a7; i++)
        issik_kul.add_(new Kapskiy_chirok);
}
char m1[] = { "1.Следующий день\n" };
char m2[] = { "2.Информация про озеро 'Тоба'\n" };
char m3[] = { "3.Информация про озеро 'Кратерное озеро'\n" };
char m4[] = { "4.Информация про озеро 'Мьоса'\n" };
char m5[] = { "5.Информация про озеро 'Иссык-Куль'\n" };
char m6[] = { "6.Информация про ферму 'JATAPOB'\n" };
char m7[] = { "7.Информация о прошедшем дне охоты\n" };
char m8[] = { "8.выход :\n" };
char *menu_1[] = {m1,m2,m3,m4,m5,m6,m7,m8};
int fmenu(char *x[])
{
    int q;
    for (int i = 0; i < 8; i++)
        cout << x[i] ;
    cin >> q;
    return q;
}
void exit_programm()
{
    exit(1);
}
void pobeg()
{
    for(int i=0; i<ferma.get_size_list(); i++)
    {
        int var; //процент того, что утка захочет сбежать
        var=rand()%2;
        if(var==0)
        {
            int t=-1;
            w=rand()%4;
            if(w==0&&l!=0)
            {
                lake=toba;
                t++;
            }
            if(w==1&&l!=1)
            {
                lake=krater;
                t++;
            }
            if(w==2&&l!=2)
            {
                lake=mios;
                t++;
            }
            if(w==3&&l!=3)
            {
                lake=issik_kul;
                t++;
            }
            if(t==0&&ferma.proverka(ferma.adress(i))==1)
            {
                main_duck *x=ferma.capture(i);
                lake.ha(x);
                lake.add_(x);
            }
            if(w==0&&l!=0)
                toba=lake;
            if(w==1&&l!=1)
                krater=lake;
            if(w==2&&l!=2)
                mios=lake;
            if(w==3&&l!=3)
                issik_kul=lake;
        }
    }
}
void del_kry (main_lake &x)
{
    for(int i=0; i<x.get_size_list(); i++)
    {
        main_duck *o;
        if(x.proverka_(x.adress(i)))
        {
            o=x.capture(i);
            i++;
        }
    }
}
void hunter(int k, int r, int &p)
{
    int R,kol,x=0, t=-1;
    R=rand()%(toba.get_size_list()+krater.get_size_list()+mios.get_size_list()+issik_kul.get_size_list());
    if(R>=toba.get_size_list()+krater.get_size_list()+mios.get_size_list()&&issik_kul.get_size_list()>=k&&l!=3)
    {
        kol=issik_kul.get_size_list();
        x=rand()%(r-k+1)+k;
        x=min(x,kol);
        lake=issik_kul;
        w=3;
        t++;
    }
    else if(R>=toba.get_size_list()+krater.get_size_list()&&mios.get_size_list()>=k&&l!=2)
    {
        kol=mios.get_size_list();
        x=rand()%(r-k+1)+k;
        x=min(x,kol);
        lake=mios;
        w=2;
        t++;
    }
    else if(R>=toba.get_size_list()&&krater.get_size_list()>=k&&l!=1)
    {
        kol=krater.get_size_list();
        x=rand()%(r-k+1)+k;
        x=min(x,kol);
        lake=krater;
        w=1;
        t++;
    }
    else if (toba.get_size_list()>=k&&l!=0)
    {
        kol=toba.get_size_list();
        x=rand()%(r-k+1)+k;
        x=min(x,kol);
        lake=toba;
        w=0;
        t++;
    }
    if(t==0)
    {
        for(int i=0; i<x; i++)
        {
            int y=rand()%kol;
            main_lake yx;
            main_duck *o=lake.capture(y);
            yx.add_(o);
            yx.proverka_pobega(o);
            o=yx.capture(0);
            ferma.add_(o);
            ul++;
            kol--;
        }
        if(w==0)
            toba=lake;
        if(w==1)
            krater=lake;
        if(w==2)
            mios=lake;
        if(w==3)
            issik_kul=lake;
        p=w;
    }
}
void color()
{
    if(DAY>0&&DAY<4)
        system("color 0E");
    else
        system("color 07");

}
void oxota()
{
    int day=1;
    for(; day<9;)
    {
        int p;
        int kretive=rand()%3; //33% что появится креативный кряк
        if(day<8)
            cout<<"День номер: "<<day<<endl;
        color();
        if(DAY==4)
        {

            metka=0;
            DAY=0;
            if(l==0)
                lake=toba;
            if(l==1)
                lake=krater;
            if(l==2)
                lake=mios;
            if(l==3)
                lake=issik_kul;
            if(l==4)
                lake=ferma;
            del_kry(lake);
            metka=0;
            if(l==0)
                toba=lake;
            if(l==1)
                krater=lake;
            if(l==2)
                mios=lake;
            if(l==3)
                issik_kul=lake;
            if(l==4)
                ferma=lake;
            l=-1;

        }
        //cout<<toba.get_size_list()<<" "<<krater.get_size_list()<<" "<<mios.get_size_list()<<" "<<issik_kul.get_size_list()<<" "<<ferma.get_size_list()<<endl;
        if(day==8)
            cout<<"Конец"<<endl;
        int usl = fmenu(menu_1);
        if(usl==1&&day<8)
        {
            if(DAY==0&&metka==0&&kretive==0)
        {
            l=rand()%5;
            if(l==0)
                {
                    lake=toba;
                    cout<<"ВНИМАНИЕ! Озеро ТОБА на карантине!"<<endl;
                }
            if(l==1)
                {
                    lake=krater;
                    cout<<"ВНИМАНИЕ! Кратерное озеро на карантине!"<<endl;
                }
            if(l==2)
                {
                    lake=mios;
                    cout<<"ВНИМАНИЕ! Озеро Мьос на карантине!"<<endl;
                }
            if(l==3)
                {
                    lake=issik_kul;
                    cout<<"ВНИМАНИЕ! Озеро Иссык-Куль на карантине!"<<endl;
                }
            if(l==4)
                {
                    lake=ferma;
                    cout<<"ВНИМАНИЕ! Ферма на карантине!"<<endl;
                }
            lake.add_(new Kreativ_kryak);
            metka=1;
            if(l==0)
                toba=lake;
            if(l==1)
                krater=lake;
            if(l==2)
                mios=lake;
            if(l==3)
                issik_kul=lake;
            if(l==4)
                ferma=lake;
            DAY++;
        }
            ul=0;
            if(day>1)
            {
                if(l!=4)
                    pobeg();
            }
            if(l!=4)
                hunter(2,5,p);
            day++;
            if(DAY>0)
                DAY++;
        }
        if(usl==2)
        {
            if(l==0)
                cout<<"Озеро закрыто на карантин"<<endl;
            cout<<"Всего количество уток: "<<toba.get_size_list()<<endl;
            cout<<"Количество уток, умеющих плавать: "<<toba.get_count_swim()<<endl;
            cout<<"Количество уток, умеющих бегать: "<<toba.get_count_run()<<endl;
            cout<<"Количество уток, умеющих летать: "<<toba.get_count_fly()<<endl;
            cout<<"Количество уток, умеющих ползать: "<<toba.get_count_crawl()<<endl;
            cout<<"Количество уток, с грузиками на лапках: "<<toba.get_count_kg()<<endl;
            if(l==0)
                cout<<"Креативный кряк: 1"<<endl;
            cout<<"Вывести всех уток на этом озере? 1-да/0-нет"<<endl;
            int ans;
            cin>>ans;
            if(ans==1)
                toba.print_list();
        }

        if(usl==3)
        {
            if(l==1)
                cout<<"Озеро закрыто на карантин"<<endl;
            cout<<"Всего количество уток: "<<krater.get_size_list()<<endl;
            cout<<"Количество уток, умеющих плавать: "<<krater.get_count_swim()<<endl;
            cout<<"Количество уток, умеющих бегать: "<<krater.get_count_run()<<endl;
            cout<<"Количество уток, умеющих летать: "<<krater.get_count_fly()<<endl;
            cout<<"Количество уток, умеющих ползать: "<<krater.get_count_crawl()<<endl;
            cout<<"Количество уток, с грузиками на лапках: "<<krater.get_count_kg()<<endl;
            if(l==1)
                cout<<"Креативный кряк: 1"<<endl;
            cout<<"Вывести всех уток на этом озере? 1-да/0-нет"<<endl;
            int ans;
            cin>>ans;
            if(ans==1)
                krater.print_list();
        }
        if(usl==4)
        {
            if(l==2)
                cout<<"Озеро закрыто на карантин"<<endl;
            cout<<"Всего количество уток: "<<mios.get_size_list()<<endl;
            cout<<"Количество уток, умеющих плавать: "<<mios.get_count_swim()<<endl;
            cout<<"Количество уток, умеющих бегать: "<<mios.get_count_run()<<endl;
            cout<<"Количество уток, умеющих летать: "<<mios.get_count_fly()<<endl;
            cout<<"Количество уток, умеющих ползать: "<<mios.get_count_crawl()<<endl;
            cout<<"Количество уток, с грузиками на лапках: "<<mios.get_count_kg()<<endl;
            if(l==2)
                cout<<"Креативный кряк: 1"<<endl;
            cout<<"Вывести всех уток на этом озере? 1-да/0-нет"<<endl;
            int ans;
            cin>>ans;
            if(ans==1)
                mios.print_list();
        }
        if(usl==5)
        {
            if(l==3)
                cout<<"Озеро закрыто на карантин"<<endl;
            cout<<"Всего количество уток: "<<issik_kul.get_size_list()<<endl;
            cout<<"Количество уток, умеющих плавать: "<<issik_kul.get_count_swim()<<endl;
            cout<<"Количество уток, умеющих бегать: "<<issik_kul.get_count_run()<<endl;
            cout<<"Количество уток, умеющих летать: "<<issik_kul.get_count_fly()<<endl;
            cout<<"Количество уток, умеющих ползать: "<<issik_kul.get_count_crawl()<<endl;
            cout<<"Количество уток, с грузиками на лапках: "<<issik_kul.get_count_kg()<<endl;
            if(l==3)
                cout<<"Креативный кряк: 1"<<endl;
            cout<<"Вывести всех уток на этом озере? 1-да/0-нет"<<endl;
            int ans;
            cin>>ans;
            if(ans==1)
                issik_kul.print_list();
        }
        if(usl==6)
        {
            if(l==4)
                cout<<"Ферма закрыта на карантин"<<endl;
            cout<<"Всего количество уток: "<<ferma.get_size_list()<<endl;
            cout<<"Количество уток, умеющих плавать: "<<ferma.get_count_swim()<<endl;
            cout<<"Количество уток, умеющих бегать: "<<ferma.get_count_run()<<endl;
            cout<<"Количество уток, умеющих летать: "<<ferma.get_count_fly()<<endl;
            cout<<"Количество уток, умеющих ползать: "<<ferma.get_count_crawl()<<endl;
            cout<<"Количество уток, с грузиками на лапках: "<<ferma.get_count_kg()<<endl;
            if(l==4)
                cout<<"Креативный кряк: 1"<<endl;
            cout<<"Вывести всех уток на этом озере? 1-да/0-нет"<<endl;
            int ans;
            cin>>ans;
            if(ans==1)
                ferma.print_list();
        }
        if(usl==7)
        {

            if(ul)
            {
                cout<<"Было поймано уток: "<<ul<<endl;
                cout<<"На озере ";
                if(p==0)
                    cout<<"Тоба"<<endl;
                if(p==1)
                    cout<<"Кратерное"<<endl;
                if(p==2)
                    cout<<"Мьоса"<<endl;
                if(p==3)
                    cout<<"Иссык-куль"<<endl;
            }
            else
                cout<<"Утки не были пойманы"<<endl;
        }
        if(usl==8)
        {
            cout<<"Программа завершается..."<<endl;
            exit_programm();
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout<<"Начало"<<endl;
    srand(time(NULL));
    int kol_gogoli, kol_laysan, kol_krohali, kol_hohlat, kol_shirokonoska_1, kol_shirokonoska_2, kol_madagaskar, kol_kaps;
    raspredelenie(kol_gogoli, kol_laysan, kol_krohali, kol_hohlat,kol_shirokonoska_1,kol_shirokonoska_2, kol_kaps, kol_madagaskar);
    add_duck(kol_gogoli, kol_laysan, kol_krohali, kol_hohlat,kol_shirokonoska_1,kol_shirokonoska_2, kol_kaps, kol_madagaskar);
    oxota();
}
