#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void registration();
void login();
void forgot();
void directing();

int main(){
    int c;
    cout<<"\t\t\t______________________________________________________________________________________\n\n\n";
    cout<<"\t\t\t                               Welcome to the Login page                              \n\n\n";
    cout<<"\t\t\t_______________________________         MENU            ______________________________\n\n\n";
    cout<<"\t\t\t| Press 1 to LOGIN                        |"<<endl;
    cout<<"\t\t\t| Press 2 to REGISTER                     |"<<endl;
    cout<<"\t\t\t| Press 3 to if you forgot your password  |"<<endl;
    cout<<"\t\t\t| Press 4 to EXIT                         |"<<endl;
    cout<<"\t\t\tEnter your choice here : ";
    cin>>c;
    cout<<endl;

    switch (c)
    {
    case 1 :
            login();
        break;

    case 2 :
            registration();
        break;
    
    case 3 : 
            forgot();
        break;

    case 4 : 
            cout<<"\t\t\tTHANK YOU for visiting!";
        break;
    
    default:
            system("cls");      //this is to clean the screen
            cout<<"\t\t\tPlease select from the options below\n";
            main();
        break;
    }
}

void login(){
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\tplease enter your username and password \n";
    cout<<"\t\t\tUSERNAME : ";
    cin>>userId;
    cout<<"\t\t\tPASSWORD : ";
    cin>>password;

    ifstream input("database.txt");     //this is to get the username and passowrd from file    //here input is object name

    while(input>>id>>pass){         //we are reading the id and password and then we will match the id and password with that of user
        if (id == userId && pass == password)
        {
                count = 1;
                system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout<<"\t\t\t"<<userId<<" your login is successful\n";
        main();
    }
    else{
        cout<<"\t\t\tUser not found! \n \t\t\tCheck your id and password\n";
        main();
    }
    
}

void registration(){
    string r_userId, r_password, r_id, r_pass;
    system("cls");
    cout<<"\t\t\tEnter username : ";
    cin>>r_userId;
    cout<<"\t\t\tEnter password : ";
    cin>>r_password;

    ofstream f1("database.txt", ios::app);       //helps to write in file      //here f1 is object name   
                                //here the ios =  input output stream and app means it will append it in the end
    
    f1<<r_userId<<' '<<r_password<<endl;
    system("cls");

    cout<<"\t\t\tregistration is successful !!\n";
    main();
}

void forgot(){
    int option;
    system("cls");

    cout<<"\t\t\tFind your password -- \n";
    cout<<"\t\t\tpress 1 to search your ID\n";
    cout<<"\t\t\tpress 2 to reset your password\n";
    cout<<"\t\t\tenter your choice : ";
    cin>>option;
    cout<<"\n";

    switch (option)
    {
    case 1 : {
            int count = 0;
            string sUserId, sId, sPass;
            cout<<"\t\t\tEnter your username :";
            cin>>sUserId;
            ifstream f2("database.txt");
            while (f2>>sId>>sPass)
            {
                if (sId == sUserId)
                {
                    count = 1;
                }
            }
            f2.close();
            if(count == 1){
                cout<<"\t\t\tYour account has been found !!!\n";
                cout<<"\t\t\tYour password is : "<<sPass;
                main();
            }
            else{
                cout<<"\t\t\tSorry your account is not found!\n";
                main();
            }
        break;
    }
    
    case 2 : {
            string newPassword;
            int count = 0;
            string cUserId, cId, cPass;
            cout<<"\t\t\tEnter your username :";
            cin>>cUserId;
            cout<<"\t\t\tNew passoword : ";
            cin>>newPassword;
            ifstream f2("database.txt");
            ofstream outFile("database.txt", ios::app);
            while (f2>>cId>>cPass)
            {
                if (cId == cUserId)
                {
                    outFile<<cUserId<<' '<<newPassword<<endl;
                    break;
                }
            }
            outFile.close();
            f2.close();
            login();            
    } 

    default:
            cout<<"\t\t\tWrong choice please try again ";
            main();
        //break;
    }
}

void directing(){
    main();
}

//BUG   try pressing 3 2 4 
