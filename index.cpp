#include<iostream>
#include<iomanip>
#include<fstream>
#include<limits>
#include<string>
using namespace std;

struct Product
{
    int ProductCode;
    float Price;
    float Discount;
    string ProductName;
};

int GetValidIntInput() 
{
    int input;
    while(!(cin >> input)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid input. Please enter a valid integer: ";
    }
    return input;
}

float GetValidFloatInput() 
{
    float input;
    while(!(cin >> input)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid input. Please enter a valid float: ";
    }
    return input;
}

void Menu();
void Administrator();
void Buyer();
void Add();
void Edit();
void Remove();
void List();
void Receipt();

int productCount = 0;
Product products[100];

void Menu() 
{
    int Choice;
    string Email;
    string Password;
    do 
    {
        cout<<"\t\t\t\t______________________________________\n";
        cout<<"\t\t\t\t                                      \n";
        cout<<"\t\t\t\t        Supermarket Main Menu         \n";
        cout<<"\t\t\t\t                                      \n";
        cout<<"\t\t\t\t______________________________________\n";
        cout<<"\t\t\t\t                                      \n";
        cout<<"\t\t\t\t| 1) Administrator   |\n";
        cout<<"\t\t\t\t|                    |\n";
        cout<<"\t\t\t\t| 2) Buyer           |\n";
		cout<<"\t\t\t\t|                    |\n";
        cout<<"\t\t\t\t| 3) Clear screen    |\n";
        cout<<"\t\t\t\t|                    |\n";
        cout<<"\t\t\t\t| 4) Exit            |\n";
        cout<<"\t\t\t\t|                    |\n";
        cout<< "\n\t\t\t Please Select :";
        Choice = GetValidIntInput();

        switch(Choice) 
        {
            case 1:
                cout<<"\t\t\t Please Login \n";
                cout<<"\t\t\t Enter Email  \t\t\t ";
                cin>>Email;
                cout<<"\t\t\t Password     \1t\t\t ";
                cin>>Password;
                if(Email=="faizanemustafa256@gmail.com" && Password=="faizan@2") {
                    Administrator();
                } 
                else 
                {
                    cout<<"Invalid email/password\n";
                }
                break;
            case 2:
                Buyer();
                break;
            case 3:
            	system("cls");
            	break;
            case 4:
                exit(0);
                break;

            default:
                cout<<"Please select from the given option\n";
        }
    } 
    while(true);
}

int main() 
{
    Menu();
    return 0;
}
