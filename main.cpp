////////////////////Todo Management System/////////////////////////////
///////////////////////////Header Files////////////////////////////////
#include <iostream>
#include <cstddef>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <cstring>
#include <windows.h>
////////////////////////Function Declaration///////////////////////////

void menu();
void pascode();
void cpascode();

using namespace std;

//////////////////class One////////////////////////////////////////////

class one
{
    public:
    virtual void get()=0;
    virtual void show()=0;
    virtual void Day()=0;

};
///////////////////////class Time//////////////////////////////////////
class Time {
public:
Time(int =0, int =0, int =0 );
void setTime(int ,int ,int);
void setHour(int h);
void setMinute(int m);
void setSecond(int s);
int getHour(){return hour;}
int getMinute(){return minute;}
int getSecond(){return second;}
void printUniversal();
void printStandard();
private:
int hour;     // 0 - 23 (24-hour clock format)
int minute;   // 0 - 59
int second;   // 0 - 59
};

void Time::setHour(int h)
{
	hour   = (0<=h<24) ?h:  0;
}
void Time::setMinute(int m)
{
	minute   = (0<=m<24) ?m:  0;
}
void Time::setSecond(int s)
{
	second   = (0<=s<24) ?s:  0;
}
void Time::printUniversal(){
cout << hour << ":" << minute << ":"<< second;
}
void Time::printStandard(){
cout <<( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )<< ":"  << minute << ":" << second << ( hour < 12 ? " AM" : " PM" );
}
//////////////////////class Date///////////////////////////////////////


//////////////////class information////////////////////////////////////

class info : public one
{
    public:
    char name[50], tim[50] ,comment[50] ;
    int  number;
    int  d;
    Time *t ;
    Time t1(2);
    void get()
    {
    	int a , b , c;
        system("cls");
        cin.sync();
        cout<<"\n Enter the work name =";
        cin.getline(name, 50);
        cout<<"\n Enter the Date Time =";
        cout<<"shanbe yekshanbe ...";
        cin>>d;
        cout<<"\n Enter number =";
        cin>>number;
        cout<<"\n Enter time(HH-MM-SS) : ";
        cin>>a >> b >> c;
        t->setHour(a);
        t->setMinute(b);
        t->setSecond(c);
        cout<<"\n Enter comment : ";
        cin.getline(comment,50);
    }
    void show()
    {
        cout<<"\nName ="<<name;
       // cout<<"\nDay ="<<

        cout<<"\nNumber ="<<number;
        cout<<"\nTime(HH-MM-SS) : "<<t1.printUniversal());
        cout<<"\nComment : "<<comment;
    }
    void Day(int d)
{
        switch(d)
        {
            case '0': cout<<"shanbeh";    break;
            case '1': cout<<"yekshanbeh"; break;
            case '2': cout<<"dooshanbeh"; break;
            case '3': cout<<"sehshanbeh"; break;
            case '4': cout<<"charshanbeh";break;
            case '5': cout<<"pangshanbeh";break;
            default : cout<<"shanbeh";
        }
}
};

///////////////////////class level1//////////////////////////////////////

class level1 : public info
{

    public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("level1.txt", ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1 ,sizeof(info));
        out.close();
        cout<<"Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("level1.txt");
        if(!EOF)
        {
            cout<<"\n\nNo Data In The File ";
            cout<<"\n\n\t\tPress Any Key To Continue : ";
            getch();
            menu();

        }
        else{

            while(!in.eof())
            {
             in.read((char*)&a1, sizeof(a1));
             a1.show();
            }
            in.close();
            getch();
            menu();
        }
        }
};

/////////////////////class  level2/////////////////////////////////////

class level2:public info
{

    public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("level2.txt", ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1 ,sizeof(info));
        out.close();
        cout<<"Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("level2.txt");
        if(!EOF)
        {
            cout<<"\n\nNo Data In The File ";
            cout<<"\n\n\t\tPress Any Key To Continue : ";
            getch();
            menu();

        }
        else
        {

        while(!in.eof())
        {
        in.read((char*)&a1, sizeof(a1));
        a1.show();
        }
        in.close();
        cout<<"Press Enter To Continue =";
        getch();
        menu();
    }}




};


////////////////////////class  level3///////////////////////////////////


class level3: public info
{
    public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("level3.txt", ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1 ,sizeof(info));
        out.close();
        cout<<"Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("level3.txt");
        if(!EOF)
        {
            cout<<"No Data In The File ";
            cout<<"\nPress Any Key To Continue : ";
            getch();
            menu();
        }

        while(!in.eof())
        {

         in.read((char*)&a1, sizeof(info));


         a1.show();
        }
        in.close();
    }




};


class timed:public one
{
    public:

    char all[999];
    char name[50],time[20],number[30];

    void get()
    {
        ofstream out("timed.txt",ios::app);
        {   system("cls");
            cin.sync();
            cout<<"\nEnter Name = ";
            cin.getline(name,50);
            cout<<"\nEnter Time = ";
            cin.getline(time,20);
            cout<<"\nEnter number = ";
            cin.getline(number,30);
///oooohire

        }
        out<<"\nName = "<<name<<"\nTime "<<time<<"\nnumber"<<number;
        out.close();
        cout<<"\n\nYour Information has been saved :\n\t\t\tPress any key to continue ";
        getch();
        menu();
    }
    void show()
    {

        ifstream in("timed.txt");
        if(!in)
        {
          cout<<"File open error";
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;


        }
        in.close();
        cout<<"\n\n\t\t\tPress Any Key To Continue : ";
        getch();
        menu();
    }





};

/////////////////////////////class information//////////////////////////
class information
{
    public:
    void Levelinfo()
    {
    system("cls");
    system("color F3");
    cout<<"\n==============================================================================\n";
    cout<<"\n\n\t\t(Three LEVEL Available) \n\n \t\t[Information And Timing Are Given Below]\n)";
    cout<<"----------------------------------------------------------------------------\n";
    cout<<"\t\tLevel Available:\n";



    getch();
    menu();


    }




};


void pinfoshow()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t\Press 1 for level1  \n\n\t\t Press 2 for level2 \n\n\t\t Press 3 for Level level3 ";
    cout<<"Please Enter Your Choice :";
    cin>>choice;
    one *ptr;
    level1 s3;
    level2 s4;
    level3 s5;
    if(choice==1)
    {
    ptr=&s3;
    ptr->show();
    }
    else if(choice==2)
    {
        ptr=&s4;
        ptr->show();
    }
    else if(choice==3)
    {
        ptr=&s5;
        ptr->show();
    }
    else
    {
        cout<<"Sorry Invalid choice : ";
        getch();
        menu();
    }

}


void call_Level()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t\Press 1 for level1  \n\n\t\t Press 2 for level2 \n\n\t\t Press 3 for level3 ";
    cin>>choice;

    one *ptr;
    level1 s3;
    level2 s4;
    level3 s5;
    if(choice==1)
    {
    ptr=&s3;
    ptr->get();

    }
    if(choice==2)
    {
    ptr=&s4;
    ptr->get();


    }
    if(choice==3)
    {
     ptr=&s5;
     ptr->get();

    }

else {

    cout<<"Sorry invalid choice :";
    }
}

void menu()
{

    system("cls");
    system("color Fc");

    cout<<"\n";
    cout<<"\n";

    cout<<"\t\t  |   ++++++++++   MAIN MENU   ++++++++++   |  \n";
    cout<<"\t\t  |        TODOLIST MANAGEMENT SYSTEM       |\n";
    cout<<"\t\t  |=========================================|  \n";

    cout<<"\n--------------------------------------------------------------------------\n";
    cout<<"\t\t           Please Select Any Option          \n  ";

    cout<<"\n\n\t1-\t\tPress 1 For Available work Information\n\n";
    cout<<"\t2-\t\tPress 2 for work Appointment\n\n";
    cout<<"\t3-\t\tPress 3 for Saving time information\n\n";
    cout<<"\t4-\t\tPress 4 for Checking Works Times Menu:\n\n";
    cout<<"\t5-\t\tPress 5 for Checking time Information Menu:\n\n";
    cout<<"\t6-\t\tPress 6 for Checking Password or Create password   :\n\n";
    cout<<"\t7-\t\tPress 7 for Remove item: \n\n";
    cout<<"\t8-\t\t[   Press 8 for Logout       ]\n";

    cout<<"\n==========================================================================\n";
    cout<<"\n\n\t\tPlease Enter Your choice : ";
    information a1;
    one *ptr;
    timed a2;
    int a;
    cin>>a;
    if(a==1)
    {
        a1.Levelinfo();
    }
    else if(a==2)
    {
        call_Level();
    }
    else if(a==3)
    {
        ptr=&a2;
        ptr->get();

    }
    else if(a==4)
    {
        pinfoshow();
    }
    else if(a==5)
    {
        ptr=&a2;
        ptr->show();
    }
    else if(a==6)
    {
        cpascode();
    }
    else if(a==7)
    {
       // Remove_item();//<--
    }
    else if(a==8)
    {
        pascode();
    }
    else
    {
        cout<<"Sorry invalid choice : ";
    }
}

void pascode()
{
    system("cls");
    char p1[50],p2[50],p3[50];


    system("color Fc");

     ifstream in("password.txt");
     {
         cin.sync();

         cout<<"\n\n\n\n\n\n\n\t\t\tEnter the Password: ";
         cin.getline(p1,50);
         in.getline(p2,50);
         if(strcmp(p2,p1)==0)

         {
             menu();
         }
         else
        {

            cout<<"\n\n\t\t\tIncorrect Password Please Try Again\n";
            Sleep(999);
            pascode();
        }
     }
     in.close();
}




void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnter The New password ";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\n\your Password has been saved : ";
    getch();
    menu();

}
int main()
{


    pascode();
    system("pause");
}

