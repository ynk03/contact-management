// Including Header files

#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>

using namespace std;

//Global variable
string fname,lname,phone_no;


//Function Declaration
void add_contact();
void search_contact();
void display_contact();
void delete_contact();
void _exit();

bool check_length(string);
bool check_digit(string);



int main()
{
   system("cls");
   system("color 0A");
   
   int option;
   
   cout<<"\n\n\n\t\t\tCONTACT MANAGEMENT";
   cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Show All Contact Details \n\t4. Delete Contact\n\t5. Exit\n\t";
   cin>>option;
   
   switch(option)
   {
   	    case 1:
   	    	add_contact();
   	    	break;
   	    
   	    case 2:
   	    	search_contact();
   	    	break;
   	    
   	    case 3:
   	    	display_contact();
   	    	break;
   	    	
   	    case 4:
   	    	delete_contact();
   	    	break;
   	    
   	    case 5:
   	    	_exit();
   	    
   	    default:
   	    	cout<<"\n\n\tInvalid Input";
   	    	cout<<"\n\tPress any key to continue";
   	    	getch();
   	    	main();
   }
   
   
   return 0;
}


void add_contact()
{
	ofstream phone("contact.txt",ios::app);
	system("cls");
	cout<<"Enter first name : ";
	cin>>fname;
	cin.ignore();
	cout<<"Enter last name : ";
	cin>>lname;
	cin.ignore();
	cout<<"Enter 10 digit phone no : ";
	cin>>phone_no;
	cin.ignore();
	
	char ch;
	
	if(check_length(phone_no)==true)
	{
		if(check_digit(phone_no)==true)
		{
			if(phone.is_open())
			{
				phone<<fname<<" "<<lname<<" "<<phone_no<<endl;
				cout<<"\n\tContact Added Successfully\n";
				phone.close();
				getch();
				main();
			}
			else
			{
				cout<<"\n\tError Opening File\n";
				getch();
				main();
			}
		}
		else
		{
			phone.close();
			cout<<"\n\tContact Saving failed";
			cout<<"\n\tPhone number must contain number only(0 to 9)\n";
			getch();
			main();
		}
	}
	
	else
	{
		phone.close();
		cout<<"\n\tContact Saving  failed";
		cout<<"\n\tPlease enter 10 digit phone number\n";
		getch();
		main();
	}
	
	
}

void search_contact()
{
	system("cls");
	bool found=false;
	ifstream phone("contact.txt",ios::in);
	string keyword;
	cout<<"\n\tEnter keyword to search in contact : ";
	cin>>keyword;
	
	while(phone >> fname>>lname>>phone_no)
	{
		if(keyword==fname || keyword==lname)
		{
			cout<<"\n\tContact Details ....";
			cout<<"\n\tFirst Name = "<<fname;
			cout<<"\n\tLast Name = "<<lname;
			cout<<"\n\tMobile Number = "<<phone_no<<endl;
			
			found =true;
		}
	}
	
	if(found == false)
	{
		cout<<"\n\tNo Contact Details found\n";
	}
	getch();
	main();
	
}

void display_contact()
{
	bool found=false;
	system("cls");
	ifstream phone("contact.txt");
	cout<<"\n\tContact Details ...";
	while(phone >>fname>>lname>>phone_no)
	{
		found=true;
		cout<<"\n\tFirst Name = "<<fname;
		cout<<"\n\tLast Name = "<<lname;
		cout<<"\n\tPhone number = "<<phone_no<<endl;	
	}
	if(found==false)
	{
		cout<<"\n\tNo Contact details found\n";
	}
	getch();
	main();
}

void delete_contact()
{
	vector<string> data;
	string line;
	bool found=false;
	system("cls");
	ifstream phone("contact.txt",ios::in);
	string keyword;
	
	cout<<"\n\tEnter keyword to be deleted : ";
	cin>>keyword;
	
	cout<<"\n\tDeleted Contact Details ....";
	
	while(phone>>fname>>lname>>phone_no)
	{
		if(keyword==fname || keyword==lname)
		{
			cout<<"\n\tFirst Name = "<<fname;
			cout<<"\n\tLast Name = "<<lname;
			cout<<"\n\tPhone Number = "<<phone_no<<endl;
			
			found=true;
		}
		
		else
		{
			line=fname+" "+lname+" "+phone_no;
			data.push_back(line);
		}
	}
	phone.close();
	
	ofstream offile("contact.txt",ios::out);
	int n=data.size();
	for(int i=0;i<n;i++)
	{
		line=data[i];
		offile<<line<<endl;
	}
	
	
	if(found==false)
	{
		cout<<"\n\tNo contact details with keyword found\n";
	}
	else
	{
		cout<<"\n\tContact deleted successfully\n";
		
	}
	
	getch();
	main();
}

void _exit()
{
	cout<<"\n\tTHANK YOU FOR USING\n";
	exit(0);
}



bool check_length(string ph)
{
	if(ph.size()==10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_digit(string ph)
{
	for(int i=0;i<ph.size();i++)
	{
		if(!(int(ph[i])>=48 && int(ph[i])<=57))
		{
			return false;
		}
	}
	return true;
}
