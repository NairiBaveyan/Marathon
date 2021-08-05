#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
void From_a_to_A(string &str,int size)
{
    if((str[0]>=97 )&& (str[0]<=122))
    {
        string tmp;
        str[0]= str[0]-32;
    }
    if((str[size-1]>=97)&&(str[size-1]<=122))
    {
        str[size-1]=str[size-1]-32;
    }
}
int main()  
{
    string path = "myNote.odt";
    ifstream fin;
    ofstream fout;
    fin.open(path);
    fout.open(path,ios_base::out|ios_base::app);
    string name;
    while(!fin.eof())
    {
    fin>>name;
    int size = name.size();
    From_a_to_A(name,size);
    cout<<name;
    fout<<name+" ";
    }
    fin.close();
    return 0;
}