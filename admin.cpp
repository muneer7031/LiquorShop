#include<iostream>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<windows.h>
#include<ctime>
#include "customer.cpp"
using namespace std;
#define clrscr(); system("cls");
void bill(int choice);
string existingusername="Pecado";
char existingpassword[7]="311001";
string admname;
long int admpass;
int total_price;
class Admin
{
    int no;
    char name[20];
    int stock;
    int price;
    int quantity; 
    public :
            void add();
            void display();
            void modify();
            void delete_details();
            void billscreen_display();
            char* liqname();
            int ds();
            int ino();
            int pr();
            int qty();
};
int Admin :: ds()
{
    return stock;
}
char* Admin :: liqname()
{
    return (name);
}
int Admin :: ino()
{
    return no;
}
int Admin :: pr()
{
    return (price);
}
int Admin :: qty()
{
    return (quantity);
}
void Admin :: add()
{
      cout<<"\n\nENTER ITEM NUMBER : ";
      cin>>no;
      cout<<"\n ENTER PRODUCT NAME : ";
      cin>>name;
      cout<<"\n ENTER PRODUCT PRICE : ";
      cin>>price;
      cout<<"\n ENTER NUMBER OF PRODUCT IN STOCK : ";
      cin>>stock;
      cout<<"\n QUANTITY PER BOTTLE(mL) : ";
      cin>>quantity;
      cout<<" \n  \t\t   YOUR DATA HAS BEEN SUCCESSFULLY ADDED";
}
void Admin :: modify()
{
    clrscr();
    cout<<"\n\n ENTER NEW ITEM NUMBER";
    cin>>no;
    cout<<"\n ENTER NEW PRODUCT NAME : ";
    cin>>name;
    cout<<"\n ENTER NEW LIQUUOR PRICE : ";
    cin>>price;
    cout<<"\n ENTER NUMBER OF PRODUCT IN STOCK : ";
    cin>>stock;
    cout<<"\n QUANTITY PER BOTTLE(mL) : ";
    cin>>quantity;
    cout<<" \n  \t\t   YOUR DATA HAS BEEN SUCCESSFULLY EDITED";
}
void Admin :: display()
{
    cout<<setw(5)<<no<<setw(20)<<name<<setw(20)<<quantity<<setw(20)<<price<<setw(20)<<stock<<endl;
}
void Admin :: billscreen_display()
{
    cout<<setw(20)<<name<<setw(20)<<quantity<<setw(20)<<price<<endl;
}
void Admdetails()
{
    char choice='y';
    do
    { 
        clrscr();
        cout<<"ENTER ADMIN USERNAME:";
        cin>>admname;       
        if (admname==existingusername)
        {
            char pin[7];
            int k=0;
            cout<<"\nENTER 6 DIGIT PASSWORD : ";
            while(pin[k-1]!='\r') 
            {
                pin[k]=getch();
                if(pin[k-1]!='\r')
                {
                    cout<<"*";
                }
                k++;
            }
            pin[k-1]='\0';
            if(strcmp(pin,existingpassword)==0)
            {
                cout<<"\n LOGIN SUCCESSFULL!!";
                Sleep(2000);
                break;
            }
            else
            {
                cout<<"\n WRONG PASSWORD ENTERED!";
                goto common_err;
            }
        }
        else 
        {
            cout<<"\n INVALID USERNAME";
            goto common_err;
        }
        common_err:
        cout<<"\n DO YOU WANT TO TRY AGAIN?";
        cin>>choice;
    } while (choice=='y' || choice=='Y' );
}
void add_liq()
{
    Admin a;
    char ch='y';
   ofstream fo ("liquor.txt",ios::out|ios::app);
    do
    {
        a.add();
        fo.write((char*)&a,sizeof(a));
        cout<<"\n DO YOU WANT TO ADD MORE PRODUCTS?(Y/N) : ";
        cin>>ch;
    } while (ch =='y' || ch == 'Y');
    fo.close();
}
void del_liq()
{
    Admin a;
    string ip;
    ifstream fi("liquor.txt",ios::in);
    ofstream fo("NEW.txt",ios::out);
    cout<<"ENTER THE NAME OF THE PRODUCT TO BE DELETED : ";
    cin>>ip;
    while(fi.read((char*)&a,sizeof(a)))
    {
        string op=a.liqname();
        if(ip!=op)
            fo.write((char*)&a,sizeof(a));
        if(fi.eof())
            break;
    }
    fi.close();
    fo.close();
    remove("liquor.txt");
    rename("NEW.txt","liquor.txt");
    cout<<"ITEM DELETED SUCCESSFULLY!";
}
void mod_liq()
{
    Admin a;
    string ip;
    ifstream fi("liquor.txt",ios::in);
    ofstream fo("NEW.txt",ios::out);
    cout<<"ENTER THE NAME OF THE PRODUCT TO BE MODIFIED : ";
    cin>>ip;
    while(fi.read((char*)&a,sizeof(a)))
    {
        string op=a.liqname();
        if(ip==op)
        {
            a.modify();
        }
        fo.write((char*)&a,sizeof(a));
        if(fi.eof())
            break;
    }
    fi.close();
    fo.close();
    remove("liquor.txt");
    rename("NEW.txt","liquor.txt");
}
void dis_liq()
{
     Admin a;
     cout<<"ITEM NUMBER \t LIQUOR NAME \t\t QUANTITY \t\t PRICE "<<setw(20)<<"STOCK"<<endl;
    ifstream fin("liquor.txt");
    while (fin.read((char*)&a,sizeof(a)))
    {
        a.display();
        if(fin.eof())
            break;
    }
    fin.close();
}
void add_baw()
{
    Admin a;
    char ch='y';
   ofstream fo ("baw.txt",ios::out|ios::app);
    do
    {
        a.add();
        fo.write((char*)&a,sizeof(a));
        cout<<"\n DO YOU WANT TO ADD MORE PRODUCTS?(Y/N) : ";
        cin>>ch;
    } while (ch =='y' || ch == 'Y');
    fo.close();
}
void del_baw()
{
    Admin a;
    string ip;
    ifstream fi("baw.txt",ios::in);
    ofstream fo("NEW1.txt",ios::out);
    cout<<"ENTER THE NAME OF THE PRODUCT TO BE DELETED : ";
    cin>>ip;
    while(fi.read((char*)&a,sizeof(a)))
    {
        string op=a.liqname();
        if(ip!=op)
            fo.write((char*)&a,sizeof(a));
        if(fi.eof())
            break;
    }
    fi.close();
    fo.close();
    remove("baw.txt");
    rename("NEW1.txt","baw.txt");
    cout<<"ITEM DELETED SUCCESSFULLY!";
}
void mod_baw()
{
    Admin a;
    string ip;
    ifstream fi("baw.txt",ios::in);
    ofstream fo("NEW1.txt",ios::out);
    cout<<"ENTER THE NAME OF THE PRODUCT TO BE MODIFIED : ";
    cin>>ip;
    while(fi.read((char*)&a,sizeof(a)))
    {
        string op=a.liqname();
        if(ip==op)
        {
            a.modify();
        }
        fo.write((char*)&a,sizeof(a));
        if(fi.eof())
            break;
    }
    fi.close();
    fo.close();
    remove("baw.txt");
    rename("NEW1.txt","baw.txt");
}
void dis_baw()
{
     Admin a;
      cout<<"ITEM NUMBER \t LIQUOR NAME \t\t QUANTITY \t\t PRICE "<<setw(20)<<"STOCK"<<endl;
    ifstream fin("baw.txt");
    while (fin.read((char*)&a,sizeof(a)))
    {
        a.display();
        if(fin.eof())
            break;  
    }
    fin.close();
}
void beer_panel()
{
    int i=1;
    int ch;
    do
    {
        
        clrscr();
        cout<<"\t \t \t |-------------|\t|---------------|\n";
        cout<<"\t \t \t |A  D  M  I  N| \t| L  O  G  I  N |\n";
        cout<<"\t \t \t |-------------|\t|---------------|\n\n\n\n";
        cout<<"\t 1. ADD A PRODUCT \n" ;
        cout<<"\t 2. DELETE A PRODUCT \n";
        cout<<"\t 3. MODIFY A PRODUCT \n";
        cout<<"\t 4. DISPLAY PRODUCT \n";
        cout<<"\t ENTER YOUR CHOICE : ";
        cin>>ch;
        clrscr();
        switch (ch)
        {
            case 1:
                    add_baw();
                    break;
            case 2:
                    del_baw();
                    break;
            case 3:
                    mod_baw();
                    break;
            case 4: 
                    dis_baw();
                    break;
        }
        cout<<"\n PRESS 1 TO DISPAY HOMESCREEN , 0 TO GO BACK : ";
        cin>>i;
        if (i==0)
        {
            break;
        }
        
    } while (i==1);
}
void liq_panel()
{
    int i=1;
    int ch;
    do
    {
        clrscr();
        cout<<"\t \t \t |-------------|\t|---------------|\n";
        cout<<"\t \t \t |A  D  M  I  N| \t| L  O  G  I  N |\n";
        cout<<"\t \t \t |-------------|\t|---------------|\n\n\n\n";
        cout<<"\t 1. ADD A PRODUCT \n" ;
        cout<<"\t 2. DELETE A PRODUCT \n";
        cout<<"\t 3. MODIFY A PRODUCT \n";
        cout<<"\t 4. DISPLAY PRODUCT \n";
        cout<<"\t ENTER YOUR CHOICE : ";
        cin>>ch;
        clrscr();
        switch (ch)
        {
            case 1:
                    add_liq();
                    break;
            case 2:
                    del_liq();
                    break;
            case 3:
                    mod_liq();
                    break;
            case 4: 
                    dis_liq();
                    break;
        }
        cout<<"\n PRESS 1 TO DISPAY HOMESCREEN , 0 TO GO BACK : ";
        cin>>i;
        if (i==0)
        {
            break;
        }
        
    } while (i==1);
}
void Adm_menu()
{
    int choice=0;
    char ch='Y',done='o';
    do
    {
        clrscr();
        cout<<"\t \t \t |-------------|\t|---------------|\n";
        cout<<"\t \t \t |A  D  M  I  N| \t| L  O  G  I  N |\n";
        cout<<"\t \t \t |-------------|\t|---------------|\n\n\n\n";
        cout<<"\t 1.LIQUOR \n\t 2.BEER AND WINE \n\t 3.SAVE AND EXIT\n\n\t";
        cout<<"WHICH SECTION DO YOU WANT TO ACCESS? : ";
        cin>>choice;
        switch (choice)
        {
            case 1 :
                    liq_panel();
                    break;
            case 2:
                    beer_panel();
                    break;
            case 3:
                    cout<<"ARE YOU SURE YOU WANT TO EXIT? PRESS 'O' TO LOGOUT :";
                    cin>>done;
                    if (done=='o'||done=='O')
                    {
                        cout<<"PROGRESS HAS BEEN SAVED. \n ";
                        int counter = 15; //amount of seconds
                        while (counter >= 0)
                        {
                            cout << " \r TERMINATING SOFTWARE IN " << counter << " SECONDS" ;//<< flush;
                            Sleep(1000);
                            counter--;
                        }
                        exit(0);
                    }
        }
        cout<<"DO YOU WANT TO DISPLAY MAIN PANEL?";
        cin>>ch;
    } while (ch=='y' || ch=='Y');
   cout<<"\nPROGRESS HAS BEEN SAVED. \n ";
    int counter = 10; //amount of seconds
    while (counter >= 0)
    {
        cout << " \r TERMINATING SOFTWARE IN " << counter << " SECONDS" ;
        Sleep(1000);
        counter--;
    }
     exit(0);
}
void bill_l(int choice)
{
    Admin a;
    fstream fin("liquor.txt",ios :: in);
    fstream fout;
    fout.open("bill.txt",ios::app | ios::out);
    if(!fout)
    {
        cout<<"File not found";
    }
    while (fin.read((char*)&a,sizeof(a)))
    {    
        if(a.ino()==choice)
        {
            total_price+=a.pr();
            fout.write((char*)&a,sizeof(a));
        }
        if(fin.eof())
        {
            break;
        }
    }
    fin.close();
    fout.close();
}
void bill_baw(int choice)
{
    Admin a;
    fstream fin("baw.txt",ios :: in);
    fstream fout;
    fout.open("bill.txt",ios::app | ios::out);
    if(!fout)
    {
        cout<<"File not found";
    }
    while (fin.read((char*)&a,sizeof(a)))
    {    

        if(a.ino()==choice)
        {
            total_price+=a.pr();
            fout.write((char*)&a,sizeof(a));

        }
        if(fin.eof())
        {
            break;
        }
    }
    fin.close();
    fout.close();
}
void Liquor()
{
    char ch='y';
    int choice;
    cout<<setw(5)<<"ITEM NO"<<setw(20)<<"PRODUCT NAME"<<setw(20)<<"QUANTITY(mL)"<<setw(20)<<"PRICE"<<setw(20)<<"STOCK"<<endl;
    Admin a;
    fstream fin("liquor.txt",ios :: in);
   do
    {
        while(fin.read((char*)&a,sizeof(a)))
        {
            a.display();
            if(fin.eof())
            break;
        }
        cout<<"WHICH ITEM DO YOU WANT TO CHOOSE?";
        cin>>choice;
        bill_l(choice);
        cout<<"DO YOU WANT TO CONTINUE PURCHASING IN THE SAME SECTION ?";
        cin>>ch;
    }while (ch =='y' || ch == 'Y');
    fin.close();
}
void BeerandWine()
{
    char ch='y';
    int choice;
     cout<<setw(5)<<"ITEM NO"<<setw(20)<<"PRODUCT NAME"<<setw(20)<<"QUANTITY(mL)"<<setw(20)<<"PRICE"<<setw(20)<<"STOCK"<<endl;
    Admin a;
    fstream fin("baw.txt",ios :: in);
   do
    {
        while(fin.read((char*)&a,sizeof(a)))
        {
            a.display();
            if(fin.eof())
            break;
        }
        cout<<"WHICH ITEM DO YOU WANT TO CHOOSE?";
        cin>>choice;
        bill_baw(choice);
        cout<<"DO YOU WANT TO CONTINUE PURCHASING IN THE SAME SECTION ?";
        cin>>ch;
    }while (ch =='y' || ch == 'Y');
    fin.close();    
}
void intend()
{
    cout<<"\n\n\n\n";
}
void get_time()
{
    cout<<"\n\n DATE OF PURCHASE : "; 
    std::time_t result = std::time(nullptr);
    std::cout << std::ctime(&result);
}
void cust_det(char* user)
{
    new_customer n;
    ifstream fin("newCustomer.dat",ios::in|ios::binary);
    while (fin.read((char*)&n,sizeof(n)))
    {
        if(fin.eof())
            break;
        if(strcmp(user,n.phonenum())==0)
        {
           cout<<"\n CUSTOMER NAME : "<<n.cus_name();
           cout<<endl<<"PHONE NUMBER : "<<n.phonenum();
           cout<<endl<<"PLACE FOR DELIVERY : "<<n.cty();
           cout<<endl<<"PINCODE : "<<n.pincd()<<endl;
        }
    }
    fin.close();
    return;
} 
void bill_screen()
{
    clrscr();
    Admin a;
    int i=1;
    cout<<"\n\t\t\t E BILL\n\n";
    char  user[20];
    strcpy(user,getuser());
    cust_det(user);
    get_time();
    cout<<endl;
    cout<<endl<<endl<<setw(5)<<"ITEM NO"<<setw(20)<<"PRODUCT NAME"<<setw(20)<<"QUANTITY(mL)"<<setw(20)<<"PRICE\n\n";
    fstream fin;
    fin.open("bill.txt"); 
    while(fin.read((char*)&a,sizeof(a)))
    {
        cout<<setw(5)<<i;
        a.billscreen_display();
        if(fin.eof())
            break;
        else 
            ++i;
    }
    fin.close();
    cout<<"\n\n TOTAL AMOUNT : "<<total_price+70;
    cout<<"\n\n PS: 70 INR HAS BEEN ADDED TO THE TOTAL PRICE AS DELIVERY CHARGE";
}
void end()
{
    char choice;
    cout<<"\n\n YOUR ORDER HAS BEEN PLACED SUCCESSFULLY AND WILL BE DELIVERED TO YOU WITHIN 1 HOUR.\n\n PLEASE SHOW YOUR PROOF OF ID TO VERIFY YOUR AGE AT THE TIME OF  DELIVERY. \n\n PRESS Y TO TERMINATE\n";
    cin>>choice;
    if(choice=='y')
    {
        fstream fclear;
        fclear.open("bill.txt",ios_base::trunc| ios::out);
        
        fclear.close();
    }
    else
        cout<<"WAITING";
}
void menu_main()
{
    total_price=0;
    char choice;
    int drink_section;
    do
    {
        clrscr();
        cout<<"\t \t \t |------------|\n";
        cout<<"\t \t \t |MAIN \t MENU |\n";
        cout<<"\t \t \t |------------|\n\n\n\n";
        cout<<"\t 1.LIQUOR\n";
        cout<<"\t 2.BEER AND WINE \n";
        cout<<"\t WHICH SECTION DO YOU WANT TO CHOOSE : ";
        cin>>drink_section;
        switch(drink_section)
        {
            case 1 :  
                    intend();
                    Liquor();
                    break;
            case 2 :  
                    intend();
                    BeerandWine();
                    break;
            default : cout<<"\n YOU HAVE ENTERED WRONG CHOICE!!";
        }
        cout<<"\n DO YOU WANT TO MOVE TO MAIN MENU?(y/n)";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    return;
}
void admin_cust()
{
    clrscr();
    int choice=0;
    cout<<"\t \t \t |-------------|\n";
    cout<<"\t \t \t |    !BEVQ    |\n";
    cout<<"\t \t \t |-------------|\n\n\n\n";
    cout<<" 1.LOGIN AS ADMIN \n 2. LOGIN AS CUSTOMER \n 3.EXIT\n";
    cout<<"\t WHICH SECTION DO YOU WANT TO CHOOSE : ";
    cin>>choice;
    switch (choice)
    {
        case 1:
                Admdetails();
                Adm_menu();
                break;
        case 2:
               cus_login();
               menu_main();
                break;
        case 3:
            
                int counter = 10; //amount of seconds
                while (counter >= 0)
                {
                    cout << " \r TERMINATING SOFTWARE IN " << counter << " SECONDS" ;//<< flush;
                    Sleep(1000);
                    counter--;
                }
                exit(0);
    }
    return;
}
int main()
{

    admin_cust();
    clrscr(); 
    cout<<"\t\t\t\tPREPARING YOUR E BILL....PLEASE WAIT\n" ;
    Sleep(10000);
    bill_screen();

    end();

    return 0;
}