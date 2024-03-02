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
    while(!(cin >> input) || cin.peek()!='\n') 
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
    while(!(cin >> input ||cin.peek()!='\n')) 
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
                cout<<"\t\t\t Password     \t\t\t ";
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

void Administrator() 
{
    int Choice;
    do 
    {
        cout<<"\n\n\n\t\t\t Administrator menu";
        cout<<"\n\t\t\t|_____1) Add the Product______|";
        cout<<"\n\t\t\t|                             |";
        cout<<"\n\t\t\t|_____2) Modify the Product___|";
        cout<<"\n\t\t\t|                             |";
        cout<<"\n\t\t\t|_____3) Delete the Product___|";
        cout<<"\n\t\t\t|                             |";
        cout<<"\n\t\t\t|_____4) Back to Main Menu____|";
        cout<<"\n\t\t\t|                             |";
        cout<<"\n\t\t\t|_____5) Clear screen_________|";
        cout<<"\n\n\t Please enter your Choice ";
        Choice = GetValidIntInput();
        switch(Choice) 
        {
            case 1:
                Add();
                break;
            case 2:
                Edit();
                break;
            case 3:
                Remove();
                break;
            case 4:
                return;
                break;
            case 5:
				system("cls");
				break;    

            default:
                cout<<"Invalid choice!!!";
        }
    } 
    while (true);
}

void Buyer() 
{
    int Choice;
    do 
    {
        cout<<"\t\t\t 1) Buyer \n";
        cout<<"\t\t\t________________\n";
        cout<<"                      \n";
        cout<<"\t\t\t 1) Buy Product \n";
        cout<<"                      \n";
        cout<<"\t\t\t 2) Go Back      \n";
        cout<<"\t\t\t Enter Your Choice : ";
        Choice = GetValidIntInput();
        switch(Choice) 
        {
            case 1:
                Receipt();
                break;
            case 2:
                return;
                
            default:
                cout<<"Invalid Choice!!!";
        }
    } 
    while(true);
}

void Add() 
{
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product code: ";
    products[productCount].ProductCode = GetValidIntInput();
    cout<<"\n\n\t Name of the product: ";
    cin>>products[productCount].ProductName;
    cout <<"\n\n\t Price of the Product: ";
    products[productCount].Price = GetValidFloatInput();
    cout<<"\n\n\t Discount on Product: ";
    products[productCount].Discount = GetValidFloatInput();

    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data<<" "<<products[productCount].ProductCode<<" "<<products[productCount].ProductName<<" "<<products[productCount].Price<<" "<<products[productCount].Discount<<"\n";
        data.close();
    } 
    else 
    {
        data>>c>>n>>p>>d;
        while(!data.eof()) 
        {
            if (c == products[productCount].ProductCode) 
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if(token == 1)
        return;
    else 
    {
        data.open("database.txt", ios::app | ios::out);
        data<<" "<<products[productCount].ProductCode<<" "<<products[productCount].ProductName<<" "<<products[productCount].Price<<" "<<products[productCount].Discount<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted !";
    productCount++;
}

void Edit() 
{
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the Record";
    cout <<"\n\t\t\t Product Code: ";
    pkey = GetValidIntInput();
    data.open("database.txt", ios::in);
    if (!data) 
    {
        cout<<"\n\n File does not Exist!!!";
    } 
    else 
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>c>>n>>p>>d;
        while (!data.eof()) 
        {
            if (pkey == c) 
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product:";
                cin>>n;
                cout<<"\n\t\t Price: ";
                p = GetValidFloatInput();
                cout<<"\n\t\t Discount: ";
                d = GetValidFloatInput();
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited :)";
                token++;
            } 
            else 
            {
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if(token == 0) 
        {
            cout<<"\n\n Record not Found Sorry!";
        }
    }
}

void Remove() 
{
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete product";
    pkey = GetValidIntInput();
    data.open("database.txt", ios::in);
    if(!data) 
    {
        cout<<"File does Not exist";
    } 
    else 
    {
        data1.open("database1.txt",ios::app|ios::out);
        int c;
        float p;
        float d;
        string n;
        data>>c>>n>>p>>d;
        while (!data.eof()) 
        {
            if (c == pkey) 
            {
                cout<<"\n\n\t Product deleted Successfully";
                token++;
            } 
            else 
            {
                data1<<" "<<c<< " "<<n<< " "<<p<<" "<<d<<"\n";
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if(token == 0) 
        {
            cout<<"\n\n Record not Found";
        }
    }
}

void List() 
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n_____________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|____________________________________________\n";
    int ProductCode;
    string ProductName;
    float Price;
    float Discount;
    data>>ProductCode >> ProductName >> Price >> Discount;
    while(!data.eof()) 
    {
        cout<<ProductCode<<"\t\t"<<ProductName<<"\t\t"<<Price<< "\n";
        data>>ProductCode>>ProductName>>Price>>Discount;
    }
    data.close();
}

void Receipt() 
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char Choice;
    int c= 0;
    float amount =0;
    float dis =0;
    float Total =0;
    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data) 
    {
        cout<<"\n\n Empty Database";
    } 
    else 
    {
        data.close();
        List();
        cout<<"\n _________________________________________________\n";
        cout<<"\n|                                                 \n";
        cout<<"\n               Please place the Order             \n";
        cout<<"\n|                                                 \n";
        cout<<"\n _________________________________________________\n";
        do 
        {
            cout<<"\n\n Enter Product Code: ";
            arrc[c] = GetValidIntInput();
            cout<<"\n\n Enter the Product Quantity: ";
            arrq[c] = GetValidIntInput();
            for (int i=0;i<c;i++) 
            {
                if(arrc[c] == arrc[i]) 
                {
                    cout<<"\n\n Duplicate product code. Try Again!";
                    continue;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y/Y else no  : ";
            cin>>Choice;
        } 
        while(Choice == 'y' || Choice == 'Y');

        cout<<"\n\n\t\t\t\t_________________________RECEIPT__________________________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\t\tPrice\t\tAmount\t\tAmount with discount\n";

        for (int i = 0; i < c; i++) 
        {
            data.open("database.txt", ios::in);
            int ProductCode;
            string ProductName;
            float Price;
            float Discount;
            data>>ProductCode>>ProductName>>Price>>Discount;
            while(!data.eof()) 
            {
                if(ProductCode == arrc[i]) 
                {
                    amount = Price * arrq[i];
                    dis = amount-(amount*Discount/ 100);
                    Total = Total + dis;
                    cout<<"\n" <<ProductCode<<"\t\t "<<ProductName<<"\t\t "<<arrq[i]<<"\t\t\t\t"<<Price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>ProductCode>>ProductName>>Price>>Discount;
            }
            data.close();
        }
    }
    cout<<"\n\n\t\t\t\t________________________________________________________";
    cout<<"\n Total Amount : " << Total;
}

int main() 
{
    Menu();
    return 0;
}
