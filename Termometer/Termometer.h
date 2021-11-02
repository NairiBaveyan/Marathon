#ifndef TERMOMETER_H_
#define TERMOMETER_H_
#include <chrono>
#include <fstream>

using std::cout;
using std::endl;



class Termometer
{

	public:
		Termometer();//{++m_count;}
		Termometer(double temp)=delete;
		Termometer(const Termometer& rhs)= delete;
		~Termometer();

	public:
		static int m_count;
		void interface();
		//std::ofstream operator<<(std::ofstream fout,const Termometer &hs);

	private:
		void clearT();
		void read();
		void save();
		void setPath();
		void show();
		void setTime();
		void setTemperature();	
		double with_calvin(double);
		double with_celsius(double);
		double with_farengate(double);
		double m_temperature{};
		std::string m_time;
		std::string m_path;
};


void Termometer::clearT()
{
	setPath();
	std::ofstream fout;
	fout.open(m_path);
	fout.close();
	cout<<"Your file alrady clear!"<<endl;
}

Termometer::Termometer()
{
	interface();
}

Termometer::~Termometer()
{
	cout<<"End of <Termometer>";
}

void Termometer::read()
{
	std::ifstream fin;
	setPath();
	fin.open(m_path);
	std::string str;
	while(!fin.eof())
	{
		fin>>str;
		cout<<str<<endl;
	}
	fin.close();
}

void Termometer::setPath()
{

	m_path = "Temperature";    //+std::to_string(m_count);
}

void Termometer::interface()
{
	cout<<"Hello. "<<endl<<"What do you want to do."<<endl;
	cout<<"For reading notes press R"<<endl;
	cout<<"For creating new Not press N"<<endl;
	cout<<"For cleaning press C"<<endl;
	char command;
	std::cin>>command;
	if(command == 'R'||command == 'r')
	{
		read();
	}
	else if(command == 'N'||command == 'n')
	{
		setTemperature();
		save();
	}
	else if(command == 'C'||command == 'c')
	{
		clearT();
	}
	else
	{
		cout<<"incorrect command"<<endl;
	}
	//cout<<"Your note saved!"<<endl;

}


void Termometer::setTemperature()
{
	cout<<"With what standard you want to work"<<endl;
	cout<<"For Calvin press 1"<<endl;
	cout<<"For Celsius press 2"<<endl;
	cout<<"For Farengate press 3"<<endl;
	char command2;
	std::cin>>command2;
	if(command2 == '1')
	{	
		double temp{};
		cout<<"Enter temperature"<<endl;
		std::cin>>temp;
		m_temperature = with_calvin(temp);
		setTime();
	}
	else if(command2 == '2')
	{
       		double temp{};
                cout<<"Enter temperature"<<endl;
                std::cin>>temp;
		m_temperature = with_celsius(temp);
		setTime();
	}
	else if(command2 == '3')
	{
		double temp{};
                cout<<"Enter temperature"<<endl;
                std::cin>>temp;
		m_temperature = with_farengate(temp);
		setTime();
	}
	else
	{
		cout<<"Incorrect command";
		//error section
	}
}
/*std::ofstream Termometer::operator<<(std::ofstream& fout,Termometer& tmp)
{
	fout<<tmp.m_temperature<<m_time;
	return fout;
}*/	

void Termometer::save()
{
	setPath();
	std::ofstream fout;
	fout.open(m_path,std::fstream::app);//ios_base::in | ios_base::out); //  path, ios_base::in | ios_base::out
	fout<<m_time<<endl;
	fout<<m_temperature<<" Celsius "<<endl;
	fout.close();
	cout<<"Your note was saved!";
	
}

double Termometer::with_calvin(double temp)
{
	return temp+273.15;
}

double Termometer::with_farengate(double temp)
{
	return temp*5/9;
}

double Termometer::with_celsius(double temp)
{
	return temp;
}

void Termometer::setTime()
{
	std::time_t tm = std::time(nullptr);
	m_time = std::asctime(std::localtime(&tm)); 
}

int Termometer::m_count{0};
#endif //
