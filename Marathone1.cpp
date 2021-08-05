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

int main()
{
    std::string path = "myNote.odt";
    std::ofstream fout;
    fout.open(path);
    if(!fout.is_open())
    {
        std::cout<<"problem";
    }
    else
    {
        std::cout<<"How many contacts do you want to create _";
      //  std::string num;
        //correct_num(num);
        int num;
        std::cin>>num;
       

        for (int i = 0;i<num; ++i)
        {  // std::cin.get();
        
            firstname();
            std::string username;
            getline(cin,username);
            std::cin.get();
           
            fout<<username;
            //fout << "/n";
            lastname();
            getline(cin,username);
            std::cin.get();
          
            fout<<username;
            fout<<"/n";
            phonenumber();
            getline(cin,username);
            std::cin.get();
          
            fout<<username;
            fout<<"/n";
            adress1();
            getline(cin,username);
            std::cin.get();
         
            fout<<username;
            fout<<"/n";
            std::cout<<"You create  "<<i+1<<" contact(s)";
            std::cout<<"If You want Enter another contact "<<std::endl;
            // std::string sel;
            // getline(std::cin,sel);
            // std::cin.get();
          
            std::cout<<"Enter next "<<std::endl;
            // if(sel=="YES"||sel=="yes")
            // {
            //     std::cout<<"OK let's go";
            // }
            // else
            // {
            //     break;
            // }

        }    
    }
    return 0;
}