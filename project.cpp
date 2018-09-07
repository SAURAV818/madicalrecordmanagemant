#include<iostream>
#include<fstream>
using namespace std;
//function prototype

void show();
void edit();
void add(); 
void del();


class medicines
{
	
	long int id;
	char name[30];
	int cabinet_no,rack_no,quantity;
	float u_cost,s_cost;
	
	public:
		void getdata(){
			
			cout<<"Enter the id of medicine::";
			cin>>id;
			cout<<"\nEnter the name of the medicine::";
			cin.ignore();
			gets(name);
			cout<<"\nEnter the cabinet No::";
			cin>>cabinet_no;
			cout<<"\nEnter Rack No::";
			cin>>rack_no;
			cout<<"\nEnter Unit cost::";
			cin>>u_cost;
			cout<<"\nEnter Sales cost::";
			cin>>s_cost;
		}
		
		void putdata(){
			cout<<"\n\n\t\tMEDICINE PURCHASED";
			cout<<"\n\n\nMEDICINE ID::"<<id;
			cout<<"\t\tNAME OF MEDICINE::"<<name<<endl;
			cout<<"CABINET NO::"<<cabinet_no;
			cout<<"\t\t\tRACK NO::"<<rack_no<<endl;
			cout<<"UNIT COST::"<<u_cost;
			cout<<"\t\t\tSALES COST::"<<s_cost<<endl;
		}
		long int getid(){
			return id;
		}
};

int main()
{
	system("color b1");
		cout<<("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB1    Medicine Record Managment System    \xB1\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ");
    B:
	int ch;
	while(ch!=5){
	cout<<"\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MADICINE STORE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"1.Add Medicine"<<endl;
	cout<<"2.Delete Medicine"<<endl;
	cout<<"3.Edit Medicine"<<endl;
	cout<<"4.Show Medicine"<<endl;
	cout<<"5.Exit"<<endl;
    cout<<"Enter Your choice::";
	cin>>ch;
	switch(ch){
		case 1:add();
			   break;
		case 2:del();
			   break;
		case 3:edit();
			   break;
		case 4: show();
		       break;
		case 5: exit(0);
		       break;
		default: cout<<"\n\n Wrong choice!!"<<endl;
		
	}	
}
	
}
//function to add a medicine record
void add()
{
	fstream f;
	medicines M;
	f.open("med.dat",ios::app|ios::binary);
	if(!f){
		cout<<"No record found!!!";
		exit(0);
	}
	M.getdata();
	f.write((char*)&M,sizeof(M));
	cout<<"\n Data saved successfully!!"<<endl;

	
}
//function to delete a medicine reco55rd
void del()
{   long int id;

	fstream f,temp;
	medicines M;
	bool found=false;
	f.open("med.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	if(!f){
		cout<<"No record found!!!";
		exit(0);
	}
	cout<<"Enter Medicine Id::";
	cin>>id;
	while(f.read((char*)&M,sizeof(M))){
		if(M.getid()!=id){
			temp.write((char*)&M,sizeof(M));
			found=true;
		}
	}
	f.close();
	temp.close();
	remove("med.dat");
	rename("temp.dat","med.dat");
	if(found==false){
		cout<<"\nNo record found with this id"<<endl;
	}else{
		cout<<"\nData Deleted Successfully!!"<<endl;
	}
	
}
//function to edit a given record
void edit()
{
	long int id;
	fstream f;
	medicines M;
	bool found=false;
	f.open("med.dat",ios::in|ios::binary|ios::out);
	if(!f)
	{
		cout<<"No record found!!!";
		exit(0);
	}
	cout<<"Enter Medicine Id::";
	cin>>id;
	
	while(f.read((char*)&M,sizeof(M))){
		if(M.getid()==id){
			M.putdata();
			cout<<"\n\nEnter New Details for altering Data"<<endl;
			long pos=(-1)*sizeof(M);
			f.seekp(pos,ios::cur);
			M.getdata();
			M.putdata();
	        f.write((char*)&M,sizeof(M));
			found=true;
		}
	}
	
	f.close();
	if(found==false){
		cout<<"\nNo record found with this id"<<endl;
	}else{
		cout<<"Data Altered Successfully!!!"<<endl;
	}
	
}
//function to edit a medicine recor+d.
void show()
{
	
   long int id;
	fstream f;
	medicines M;
	bool found=false;
	f.open("med.dat",ios::in|ios::binary);
	if(!f){
		cout<<"No record found!!!";
		exit(0);
	}
	cout<<"Enter Medicine Id::";
	cin>>id;
	
	while(f.read((char*)&M,sizeof(M))){
		if(M.getid()==id){
			M.putdata();
			found=true;
		
		}
	}
	f.close();
	
	if(found==false){
		cout<<"\nNo record found with this id"<<endl;
	}
	
}
