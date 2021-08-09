#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

//!getline(fout,str);voch mi dzev chashxatec
using namespace std;
int correct_num(std::string num)
{
    for(int i = 0;i<num.length()-1;++i)
    {
        if(num[i]<=57&&num[i]>=49)
        {
            int n = 0;
            std::istringstream conteiner(num);
            conteiner>>n;
            return n;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
void firstname()
{
    std::cout<<"Enter your Firstname _";
}

void lastname()
{
    std::cout<<"Enter your Lastname _";
}
void phonenumber()
{
    std::cout<<"Enter your phone number +374 ";
}

void adress1()
{
    std::cout<<"Enter your adress _";
}

string name_editing(string &username)
{
    std::cout << username << std::endl;
    std::cout << "Edit your contact" << std::endl;
    cin>>username;
    return username+"   ";
}

string check_command(string com,string path)
{
    if(com=="W"||com=="w")
    {
        
        std::ofstream fout;
        fout.open(path);
        if(fout.is_open())
        {
            std::cout<<"How many contacts do you want to create _  ";
            int num;
            cin>>num;
       

        for (int i = 0;i<num; ++i)
        {  // std::cin.get();

            std::string username;            
            //1
            //fout<</n;
            phonenumber();
            cin>>username;
            fout<<"Phone: ";
            fout<<username+"   ";
            firstname();
            cin>>username;
            fout<<"Name: ";
            fout<<username +"   ";
            //fout << /n;
            lastname();
            cin>>username;
            fout<<"LastName: ";
          
            fout<<username+"   ";
            //fout<</n;
            adress1();
            cin>>username;
            fout<<"Adress: ";
            fout<<username+"   ";
            fout<<"stop ";
            //fout<</n;
            std::cout<<"You create  "<<i+1<<" contact(s) ";
        }
            std::cout << "Very well " << std::endl;
        }
        else
        {
            std::cout << "Problem" << std::endl;
        }
        
        return "you can write";

    }
    else if(com =="R"||com =="r")
    {
        std::ifstream fin;
        fin.open(path);
          if(fin.is_open())
        {
            std::cout << "you can read" << std::endl;
            string phone;
            std::cout << "Please Enter your phone number " << std::endl;
            std::cout << "and I can quickly find your information" << std::endl;
            cin>>phone;
            while(!fin.eof())
            {
                string str;
                fin>>str;
                if(str==phone)
                {
                    std::cout << "Phone:" << std::endl;
                   while(str!="stop")
                   {
                       std::cout << str << std::endl;
                       fin>>str;
                   }
                }
    

             }
        /*else
        {else{
                    
                    break;
                }
            std::cout << "Problem" << std::endl;
        }*/
        
        return "you can read";   
        }
        return 0;  

    }
    else if (com=="e"||com=="E")
    {

        ifstream fin;
        ofstream fout;
        fin.open(path);
        fout.open(path,ios_base::out|ios_base::in);
        string name;
        string phone;
        std::cout << "For easy founding and editing enter phone number" << std::endl;
        cin>>phone;
        while(!fin.eof())
            {
                string str;
                fin>>str;
                if(str==phone)
                {
                   while(str!="stop")
                   {
                       std::cout << str << std::endl;
                       if(str=="Name:")
                       {
                           std::cout << " " << std::endl;;
                       }else if(str=="Phone:"){
                           std::cout << " " << std::endl;;
                       }else if (str=="stop")
                       {
                           std::cout << " " << std::endl;;
                       }
                       
                       else if (str=="LastName:")
                       {
                           std::cout << " " << std::endl;;
                       }else if (str=="Adress:")
                       {
                            std::cout << " " << std::endl;;   
                       }else{
                       //str=
                       fout<<name_editing(str);;
                       }
                       fin>>str;
                   }
                }
    

             }
    }
    return "1";
}


int  main()
{
    std::string path = "myNote.odt";
    std::ofstream fout;
    fout.open(path,std::ofstream::app);
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "For writing press W" << std::endl;
    std::cout << "for reading press R" << std::endl;
    std::cout << "For editing press E" << std::endl;
    string command;
    cin>>command;
    string quest = check_command(command,path);
    //fout.open(path,ios_base::out|ios_base::app);
   /* if(!fout.is_open())
    {
        std::cout<<"problem";
    }
    else
    {*/
        
      //  std::string num;
        //correct_num(num);
        
            //std::cout<<"If You want Enter another contact "<<std::endl;
            // std::string sel;
            // getline(std::cin,sel);
            // std::cin.get();
          
            //std::cout<<"Enter next "<<std::endl;
            // if(sel=="YES"||sel=="yes")
            // {
            //     std::cout<<"OK let's go";
            // }
            // else
            // {
            //     break;
            // }

    
    return 0;
}