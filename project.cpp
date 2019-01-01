#include<map>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Admin
{
   public:
       char data;
       int maxVote1=0;
       int maxVote2=0;
   void viewSymbol()
     {
       ifstream infile;
       infile.open("afile.dat",ios::in|ios::binary);
       if ( infile.fail())
          {
             cout << "Could not open input file.";
             exit(1);
          }
       cout << "Reading from the file" << endl;
       infile >> noskipws;
       infile >> data;
       while(!infile.eof())
          {
             cout << data ;
             infile >> data;
          }
       infile.close();
     }
   void addSymbol()
     {
       char data[200],data2[200];
       ofstream outfile;
       outfile.open("afile.dat",ios::app|ios::binary);
       if ( outfile.fail())
          {
            cout << "Could not open input file.";
            exit(1);
          }
       cout<< "Writing in the file" <<endl;
       cout<<"Enter Party Name : "<<endl;
       cin.getline(data,sizeof(data));
       outfile << data <<endl;
       cout<<"Enter Party Symbol : "<<endl;
       cin.getline(data2,sizeof(data2));
       outfile << data2<<endl;
       outfile.close();
     }
   void deleteSymbol()
     {
        int skip=0;
        string line;
        string name;
        cout << "Please Enter the name of Party you want to delete: ";
        getline(cin,name);
        cin.sync();
        ifstream myfile;
        ofstream temp;
        myfile.open("afile.dat");
        temp.open("temp.txt");
        temp.flush();
        while (getline(myfile, line))
          {
           if ((line != name) && !(skip > 0))   {
           temp << line << endl;
            }
        else {
           if(skip == 0) {
           skip = 1;
           }
           else {
           --skip;
              }
           }
           temp.flush();
          }
        cout << "The Party with the name " << name << " has been deleted if it existed" << endl;
        myfile.close();
        temp.close();
        remove("afile.dat");
        rename("temp.txt", "afile.dat");
     }

   void count_NA()
     {
       ifstream fin;
       fin.open("3file.dat");
       if ( fin.fail())
          {
              cout << "Could not open input file.";
              exit(1);
          }
       string next;
       map <string, int> words;
       while (fin >> next)
       {
          words[next]++;
       }
       map< string, int>::iterator it;
       for ( it  = words.begin();
          it != words.end();
          it++ )
       {
           cout << it->first;
           cout << ": ";
           cout << it->second;
           cout << endl;
       }
       for (it = words.begin(); it!= words.end(); it++)
       {
          if(it->second > maxVote1)
            {
               maxVote1 = it->second;
            }
       }
       for (it = words.begin(); it!= words.end(); it++)
       {
          if(it->second >= maxVote1)
            {
              cout<<"\n\n\n\n\n\t\t\t\t\t";
              cout<<"Winner: "<<it->first<<"===>";
            }
       }
       cout<<"Votes : "<<maxVote1<<endl;
       }

    void count_PS()
       {
       ifstream fin;
       fin.open("4file.dat");
       if ( fin.fail())
          {
             cout << "Could not open input file.";
             exit(1);
          }
       string next;
       map <string, int> words;
       while (fin >> next)
       {
           words[next]++;
       }
       map< string, int>::iterator it;
       for ( it  = words.begin();
          it != words.end();
          it++ )
       {
          cout << it->first;
          cout << ": ";
          cout << it->second;
          cout << endl;
       }
       for (it = words.begin(); it!= words.end(); it++)
         {
           if(it->second > maxVote2)
              {
                maxVote2 = it->second;
              }
         }
       for (it = words.begin(); it!= words.end(); it++)
         {
           if(it->second >= maxVote2)
              {
                cout<<"\n\n\n\n\n\t\t\t\t\t";
                cout<<"Winner: "<<it->first<<"===>";
              }
         }
       cout<<"Votes : "<<maxVote2<<endl;
       }
};
class userWindow
{
   private:
    uint64_t id;
    char name[50];
    char gender;
    Admin a;
   public:
    void getData()
    {
        ofstream fout;
        fout.open("file2.dat",ios::app);
        if ( fout.fail()){
        cout << "Could not open input file.";
        exit(1);
        }
        cout<<"WELCOME TO VOTING BOOTH"<<endl;
        cout<<"Are You A Male Or Female (M/F) ?? "<<endl;
        cin>>gender;
        fout<<gender<<endl;
        cout<<"Please Enter Your Correct Name (Full Name) And ID Number (13 digits) To Proceed"<<endl;
        cin.ignore();
        cout<<"Name : ";
        cin.getline(name,sizeof(name));
        fout<<name<<endl;
        cin.sync();
        cout<<"ID Number: ";
        cin>>id;
        fout <<id<<endl;
        fout.close();
    }
    void showSymbol()
    {
        a.viewSymbol();
    }
    void vote_for_NA()
   {
       char choice[20];
       ofstream fout;
       fout.open("3file.dat",ios::app);
       if ( fout.fail()){
        cout << "Could not open input file.";
        exit(1);
        }
       cout<<"Enter The Party Symbol To Whom You Want To Vote"<<endl;
       cin>>choice;
       fout << choice << endl;
       cout<<"Your Vote Has Been Registered , Now Cast Your Vote For Provincial Assembly..."<<endl;
       fout.close();
   }
   void vote_for_PS()
   {
       char choice[20];
       ofstream fout;
       fout.open("4file.dat",ios::app);
       if ( fout.fail()){
        cout << "Could not open input file.";
        exit(1);
        }
       cout<<"Enter The Party Symbol To Whom You Want To Vote"<<endl;
       cin>>choice;
       fout << choice << endl;
       cout<<"Your Vote Has Been Registered !!! Thank You"<<endl;
       fout.close();
   }
};
int password()
 {
   string username;
   string password;
   int count=1;
   system("cls");
   cout<<"ENTER THE PASSWORD:\n"<<endl;
   while (count < 4 )
   {
    cout << "USERNAME: ";
    cin.sync();
    getline(cin, username);
    cout<<"\n\n";
    cout << "PASSWORD: ";
    getline(cin, password);
    cout<<"\n\n";
    if (username!= "danish" || password != "project123")
    {
      cout << "INVALID USERNAME OR PASSWORD, PLEASE TRY AGAIN" <<endl;
      cout<<"\n\n";
      count++;
    }
    else
      break;
   }
    if(username == "danish" && password == "project123" )
    {
      return(1);
    }
    else
    {
      cout<<"YOU ARE AN INTRUDER"<<endl;
      exit(1);
    }
  }

int Mainmenu()
{
    int choice;

    cout<<"\n";
    cout<<"Please Select Any Option"<<endl;
    cout<<"\n\n\n\t\t\t\t";
    cout<<"1.LogIn As Admin"<<endl;
    cout<<"\n\n\t\t\t\t";
    cout<<"2.User Window"<<endl;
    cout<<"\n\n\t\t\t\t";
    cout<<"3. Exit "<<endl;
    cout<<"\n\n";
    cin >> choice;
    return(choice);
}
int Submenu()
{
     cout<<"\n\n";
     int choice;
     cout<<"Please Select Any Option"<<endl;
     cout<<"1.View All Party Names With Their Symbols"<<endl;
     cout<<"2.Add A Party Name With Its Symbol In The List"<<endl;
     cout<<"3.Delete A Party Name From The List"<<endl;
     cout<<"4.Count The Number Of Votes Registered To Each Party"<<endl;
     cout<<"5. Exit To Main Menu"<<endl;
     cin >> choice;
     return(choice);
}
int userMenu()
{

        int choice;
        cout<<"Please Select Any Option"<<endl;
        cout<<"\n\n";
        cout<<"1.View All Party Names With Their Symbols"<<endl;
        cout<<"2.Choose Any Party Symbol To Vote"<<endl;
        cout<<"3.Return To Main Menu"<<endl;
        cin >> choice;
        return(choice);
}
int main()
{
    userWindow uW;
    Admin ad;
    int ch=0,n,flag=1,m;
    int tag_password;

    gotoxy(12,5);
    cout<<"***************************E-VOTING APPLICATION ***************************"<<endl;
    gotoxy(45,10);
    cout<<"WELCOME"<<endl;
    cout<<"\n\n\n\n";

    LABEL : ch=Mainmenu();

    while(1){
    if(ch==1)
    {
          tag_password = password();
          if(tag_password)
            {
          LABEL2 : n=Submenu();

          switch(n)
          {
             case 1:
               {
                   system("CLS");
                   ad.viewSymbol();
                   goto LABEL2;
               }
               break;
             case 2:
               {

                   cin.sync();
                   cout<<"\n";
                   ad.addSymbol();
                   goto LABEL2;
               }
               break;
             case 3:
                {
                    cin.sync();
                    cout<<"\n";
                    ad.deleteSymbol();
                    goto LABEL2;
                }
                break;
             case 4:
                {
                    system("cls");
                    cin.sync();
                    cout<<"\n\n\n";
                    cout<<"NATIONAL ASSEMBLY..."<<endl;
                    ad.count_NA();
                    cout<<"\n\n\n";
                    cout<<"PROVINCIAL ASSEMBLY..."<<endl;
                    ad.count_PS();
                    cout<<"\n\n\n";
                    goto LABEL2;
                }
                break;
             case 5:
                {
                 system("CLS");
                 goto LABEL;
                }
                break;
             default:
                {
                 system("CLS");

                 cout<<"Invalid Choice, Try Again"<<endl;
                 goto LABEL2;
                }
            }
          }
          else{
            cin.ignore();
            system("CLS");
            goto LABEL;
          }
    }
    else if(ch==2)
    {
        system("CLS");
        uW.getData();

        LABEL3 :

            m=userMenu();

            switch(m)
            {
                  case 1:
                    {
                        system("CLS");
                        uW.showSymbol();
                        goto LABEL3;
                    }
                    break;
                  case 2:
                    {

                        int q;
                        cout<<"VOTE FOR NATIONAL ASSEMBLY"<<endl;
                           uW.vote_for_NA();
                        cout<<"VOTE FOR PROVINCIAL ASSEMBLY"<<endl;
                           uW.vote_for_PS();
                        goto LABEL;

                    }
                    break;
                  case 3:
                    {
                        system("CLS");
                        goto LABEL;
                    }
                    break;
                  default:
                     {
                       system("CLS");
                       cout<<"Invalid Choice, Try Again"<<endl;
                       goto LABEL3;
                     }
              }
        }
     else if(ch==3)
            {
                exit(1);
            }
     else
            {
                system("CLS");
                cout<<"Invalid Choice, Try Again"<<endl;
                goto LABEL;
            }
     }

}
