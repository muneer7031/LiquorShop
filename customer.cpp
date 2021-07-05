#include<iostream>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;
#define clrscr(); system("cls");
const int age=23;
char username[20];
char password[20];
class new_customer
{
    char customer_name[50];
    int customer_age;
    int hno;
    string street_name;
    char city[23];
    string district;
    char pincode[20];
    char phno[20];
    char payment_mode[5];
    public: 
            void get_details();
	        void show_details();
            char* cus_name()
            {
                return customer_name;
            }
            char* phonenum()
            {
                return phno;
            }
            char* cty()
            {
                return city;
            }
            char* pincd()
            {
                return pincode;
            }
            int age()
            {
                return customer_age;
            }
            
};//end of class new customer
void new_customer :: get_details()
{
    getchar();
	cout<<"\n ENTER YOUR NAME:";
	cin>>customer_name;
	cout<<"\n ENTER YOUR AGE:";
	cin>>customer_age;
	cout<<"\n ENTER YOUR HOUSE NUMBER/FLAT NUMBER:";
	cin>>hno;
    getchar();
	cout<<"\n ENTER YOUR LANDMARK(FLAT NAME):";
	cin>>street_name;
	cout<<"\n ENTER YOUR LOCATION:";
	cin>>city;
	cout<<"\n ENTER YOUR DISTRICT:";
	cin>>district;
	cout<<"\n ENTER YOUR PINCODE:";
	cin>>pincode;
	cout<<"\n ENTER YOUR PHONE NUMBER:";
	cin>>phno;
	cout<<"\n\n DUE TO THE PANDEMIC, WE PROMOTE PAYMENT THROUGH ONLINE INORDER TO PREVENT ANY DIRECT CONTACT.\nCHOOSE WISELY\n\n ENTER PAYMENT MODE(CASH/CARD):";
	cin>>payment_mode;

}//fetching new customer details
void new_customer :: show_details()
{
    cout<<customer_name<<'\t'<<customer_age<<'\t'<<hno<<'\t';
    cout<<street_name;
    cout<<'\t';
    cout<<city;
    cout<<'\t';
    cout<<district;
    cout<<'\t'<<pincode<<'\t'<<phno<<'\t';
    puts(payment_mode);
}
void existing_user()
{
    new_customer n;
    int flag=0;
    ifstream fin;
    fin.open("newCustomer.dat",ios::binary);
    clrscr();
    cout<<"\t \t \t |-------------------------------------------------------|\n";
    cout<<"\t \t \t |\t E   X   I   S   T   I   N   G   U   S   E   R    |\n";
    cout<<"\t \t \t |-------------------------------------------------------|\n";

    cout<<"\nENTER YOUR PHONE NUMBER : ";
    cin>>username;
 
    while(fin.read((char*)&n,sizeof(n)))
    {   

        if(fin.eof())
        {
            break;
        }
        if(strcmp(n.phonenum(),username)==0)
        {
            cout<<"ENTER YOUR PINCODE : ";
            cin>>password;
            if(strcmp(n.pincd(),password)==0)
            {   
            
                cout<<"WELCOME "<<n.cus_name();
                Sleep(2000);
            }
            else
            {
                cout<<"WRONG PINCODE! PLEASE REGISTER AS A USER!\n ";
                int counter = 10; //amount of seconds
                while (counter >= 0)
                {
                    cout << "\r CLOSING SOFTWARE IN " << counter << " SECONDS" ;
                    Sleep(1000);
                    counter--;
                }
            }
        }
        else
        {
            
            cout<<"\nWRONG PHONENUMBER! PLEASE REGISTER AS A USER! \n";
            int counter = 10; //amount of seconds
            while (counter >= 0)
            {
                cout << "\r CLOSING SOFTWARE IN " << counter << " SECONDS" ;
                Sleep(1000);
                counter--;
            }
            exit(0);
            
        }
    }
  
    fin.close();
    return;
}
void new_user()
{
    clrscr();
    cout<<"REGISTERING AS A USER\n";
    new_customer n;
    ofstream fout;
    fout.open("newCustomer.dat",ios::binary|ios::app);
    n.get_details();
    if(age>n.age())
    {
        clrscr();
        cout<<"\n\n\n\n \t\t\t\tYOU ARE NOT ELIGIBLE FOR CONSUMING ALCOHOL.....\n\n\n\n\n";

        int counter = 15; //amount of seconds

            while (counter >= 0)
            {
                cout << " \r CLOSING SCREEN IN : " << counter << "SECONDS" ;
                Sleep(1000);
                counter--;
            }
        exit(0);
    }

    fout.write((char*)&n,sizeof(n));
    fout.close();
    cout<<"ACCOUNT CREATED SUCCESSFULLY! \n REDIRECTING TO MENU PAGE....\n";
    Sleep(3000);
    
    return;
}// to store the contents into a file
void cus_login()
{

    int ch;
    int i=1;
    menu:
    clrscr();
    
    cout<<"\t \t \t |------------------------|\t|---------------|\n";
	cout<<"\t \t \t |C  U  S  T  O  M  E  R  | \t| L  O  G  I  N |\n";
	cout<<"\t \t \t |------------------------|\t|---------------|\n \n";
    cout<<"\t 1. EXISTING USER \n" ;
    cout<<"\t 2. NEW USER \n";
    cout<<"\t ENTER YOUR CHOICE : ";
    cin>>ch;
    switch (ch)
    {
        case 1:
                existing_user();
                break;
        case 2:
                new_user();
                break;
        default:
                int counter = 7; //amount of seconds
                while (counter >= 0)
                {
                    cout << "\n WRONG CHOICE ENTERED!! \n  \r REDIRECTING TO CUSTOMER LOGIN PAGE .... " << counter << " SECONDS" ;
                    Sleep(1000);
                    counter--;
                }
                goto menu; 
        
    }

    return;
 
}
char* getuser()
{
    return username;
}