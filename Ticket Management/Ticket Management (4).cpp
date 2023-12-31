#include <iostream>
#include <unistd.h>
#include <string>
#include<cstdlib>
#include <fstream>
#include<limits>

using namespace std;
void seatsavailable(int,int,int);
void signup(string &name,string &num,string &usrname,string &password);
void price(int num,int &kids,int &audlt,int &seniorCitizen);

int pr = 100;
int eco = 100;
int vip = 100;

int main ()
{

	int match1=0,match2=0,match3=0;  	//stores number of tickets booked of each match
	int match4=0,match5=0,match6=0;
	int match7=0,match8=0,match9=0,match10=0;
	bool flag2=0;						//bool to make sure first ticket is booked so next time user can view his bookings, used at line 269
	int rs[100];						//stores payable amount of total bill
	double sum=0;
	ofstream write("schedule.txt");
	if(write.is_open())
	{
		write<<"1. Thu, 27 Jan \t\t Karachi Kings vs Multan Sultans \t\t National Stadium, Karachi"<<endl;
		write<<"2. Fri, 28 Jan \t\t Multan Sultans vs Lahore Qalandars \t\t Gaddafi Stadium, Lahore"<<endl;
		write<<"3. Sun, 6 Feb \t\t Karachi Kings vs Islamabad United \t\t Cricket Stadium, Rawalpindi"<<endl;
		write<<"4. mon, 7 Feb \t\t Islamabad united vs Queta Gladiaters \t\tcricket stadium, Rawalpindi"<<endl;
		write<<"5. mon, 9 Feb \t\t peshawar zalmi vs Lahore Qalanders \t\tcricket stadium, Lahore"<<endl;
		write<<"6. mon, 13 Feb \t\t Queta Gladiaters vs Multan Sultan \t\tcricket stadium, karachi"<<endl;
		write<<"7. mon, 16 Feb \t\t karachi kings vs peshawar Zalmi \t\tcricket stadium, Rawalpindi"<<endl;
		write<<"8. mon, 20 Feb \t\t Lahore Qulanders vs Islamabad United \t\tcricket stadium, Lahore"<<endl;
		write<<"9. mon, 22 Feb \t\t Multan Sultan vs lahore Qulanders \t\tcricket stadium, Karachi"<<endl;
		write<<"10. mon, 24 Feb \t\t Karachi KIngs vs Peshawar Zalmi \t\tcricket stadium, Rawalpindi"<<endl;
	}
	else
	{
		cout<<"Schedule not seen"<<endl;
	}
	write.close();

    cout << "\t PAKISTAN SUPER LEAGUE 2024" <<endl<<endl;
    cout << "You have to sign up First" <<endl;
    
    int check=0;						// variable for forever continutiy of program
    bool flag=0;						//used at line 69 and 74 to make sure user first SIGN UP at the start of Program
    string name,usrnme,password;		//Variables to Store username , name and password for login
    string  num;							//variable stores phone number
    while (check!=1)
    {
        
        string sign;
        cout << "a.Sign in | b. Sign Up | (Press 1 to Exit) "<<endl;

        getline(cin,sign);
        cout <<endl;
        
        
        
        if (sign=="sign up" || sign=="Sign up" || sign =="up" || sign=="signup")
        {
            signup(name,num,usrnme,password);  //function
            
            
            flag+=1;
        system("CLS");    				//clears the console output screen
    	}
    	else if (sign=="sign in" || sign=="Sign in" || sign =="in" || sign=="signin")
    	{
    		if (flag==0)
    		{
    			cout << "NOT YET REGISTERED! Please Sign UP First "<<endl;
    			
    		}
    		else
    		{
    			string in_usrname;
    			cout << "Enter Username: ";
    			getline(cin,in_usrname);
    			string in_password;
    			cout << "Enter Password: ";
    			getline(cin,in_password);
    			cout << endl;
    			system("CLS");
    			if (usrnme==in_usrname && password==in_password)
    			{
    				string flag1="0"; 		// flag1 variable to run the booking and view menu till the user wants used on line 272
    				while(flag1== "0")
    				{
	    				cout << "Welcome to your profile "<<endl
							<<"1. Booking  2.View  3.Clear Record  4.Exit: "<<endl;
	    				string menu;
	    				cout<<"Enter your choice to book, view, clear or to exit from the above menu:  ";
	    				cin >>menu;
	    				
	    				int i=0; 		// will be used on RS arry variable
	    				if(menu=="1")
		    			{
		    				
		    				int pr,vip,eco;
		    				
		    			    cout << "Hi, "<<name<<" WELCOME TO PSL TICKETING PORTAL"<<endl <<endl;
		    			    cout << "Date \t\t\t\t\t Match \t\t\t\t\t Venue" <<endl;
		    			    ifstream read("schedule.txt");
		    			    string line;
		    			    if(read.is_open())
		    			    {
		    			    	while(getline(read, line))
		    			    	{
		    			    		cout<<line<<endl;
								}
								read.close();
							}
							else
							{
								cout<<"File does not exist"<<endl;
							}
		    				
		    						int choice;  		//choice variable to select Particular match
		    						cout<<"Select the match you want to book tickets for: "<<endl;
		    						
		    						while (true)
									{
		    							cout<<"Enter your choice(1-10): ";
		    							if(cin>> choice && choice > 0 && choice < 11)
										{
		    								break;
										}
								     	else
									   {
										cin.clear();       //clear error flags
										cin.ignore(numeric_limits<streamsize> ::max (), '\n');   //Discard invalid input
										cout<<"Invalid Input, please enter choice(1-10)."<<endl;
								     	}
								   }
		    						
		    						//Now userInput contains a valid positive integer
		    						if(choice==1)
		    						{
		    							match1+=1;
									}
									else if(choice==2)
		    						{
		    							match2+=1;
									}
									else if(choice==3)
		    						{
		    							match3+=1;
									}
									else if(choice==4)
									{
										match4+=1;
									}
									else if(choice==5)
									{
										match5+=1;
									}
									else if(choice==6)
									{
										match6+=1;
									}
									else if(choice==7)
									{
										match7+=1;
									}
									else if(choice==8)
									{
										match8+=1;
									}
									else if(choice==9)
									{
										match9+=1;
									}
									else if(choice==10)
									{
										match10+=1;
									}
									else 
		    						system("CLS");
		    						
		    						
		    						
		    						
		    						
		    						seatsavailable(pr,vip,eco); 	//FUNCTION
		    						cout <<"CHOOSE FROM ABOVE: "<<endl;
		    					
		    						while(true)
									{
		    							cout<<"Enter your choice(1-3): ";
		    							if (cin>>choice && choice >0 && choice <4)
		    							{
		    								break;
										}
								    	else
										{
										cin.clear();     //clear error flags
										cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard invalid input
										cout<<"Invalid Input, please enter a choice between(1-3)."<<endl;
								    	}
								   }
		    					
									int kids,audlt, seniorCitizen;			//VARIABLES to Show PRICES OF EACH Category
									
									price(choice,kids,audlt,seniorCitizen); //function 
									cout <<"Which Category you wanna buy? "<<endl;
									cout <<"CHOOSE FROM ABOVE: ";
								
									cout <<endl;
									while (true){
										
										cout<<"Enter your choice(1-3): ";
										if(cin >> choice && choice >0 && choice <4)
										{
											break;
										}
										else
										{
											cin.clear();    //clear error flags
											cin.ignore(numeric_limits<streamsize>::max(), '\n');   //Discard invalid input
											cout<<"Invalid Input, please enter a choice between(1-3). "<<endl;
										}
									}
									
									int count;			// number of Tickets
									cout <<"HOW MANY TICKETS YOU WANT TO BUY? " <<endl
										<<"Note You can avail Discount of 10% if you buy more than 5 of any category"<<endl;
									
									cin >> count;
									cout <<endl;
									int discount;
									
									if (choice==1)
									{
										discount =0;
										rs[i]=count*kids;        // num of tickets x Kids Price, it stores the payable amount and i currently=0      
									
									}
									else if(choice==2)
									{
										discount=0;
										rs[i]=audlt*count;
										
									}
									else
									{
										discount=0;
										rs[i]=seniorCitizen*count;
									
									}
									if (count>5)     // discouny calculation
									{
										
										discount = ((rs[i]/100)*10);
										rs[i]=rs[i]-((rs[i]/100)*10);
										
									}
									
									sum+=rs[i];
									
									cout << "BOOKED SUCESSFULLY"<<endl;
									cout<<"You got discount price of "<<discount<<" rupees."<<endl;
									cout <<"Final Payable amount: "<<rs[i] <<endl;
									i++;				//increment in i used in RS Variable
									flag2+=1; 			// reference on line 23
									
									cout << "Press 0 to continue and any key to EXIT: ";
									cin >> flag1;		//reference on line 91
									system("CLS");
								
						} 
    				
    				
    		
    				else if(menu=="2")
    				{
    					
    					if (flag2>0)
    					{
    						cout << "Your Previous Purchase was of: "<< rs[i] <<endl;
	    					
    						
							cout << "Total amount spent: " <<sum <<endl;
    						cout<< "Tickets of first match " <<" are " <<match1<<endl;
							cout<< "Tickets of second match" <<" are " <<match2<<endl;
							cout<< "Tickets of third match " <<" are " <<match3<<endl;
							cout<< "Tickets of fourth match " <<" are " <<match4<<endl;
							cout<< "Tickets of fifth match " <<" are " <<match5<<endl;
							cout<< "Tickets of sixth match " <<" are " <<match6<<endl;
							cout<< "Tickets of seventh match " <<" are " <<match7<<endl;
							cout<< "Tickets of eighth match " <<" are " <<match8<<endl;
							cout<< "Tickets of Ninth match " <<" are " <<match9<<endl;
							cout<< "Tickets of Tehth match " <<" are " <<match10<<endl;
								
						}
						else
						{
							cout << "Currently no purchase has been made" <<endl; 
						}
					}
					
					else if(menu=="3")
					{
						sum=0;
						match1=0;
						match2=0;
						match3=0;
						match4=0;
						match5=0;
						match6=0;
						match7=0;
						match8=0;
						match9=0;
						match10=0;
						rs[i]=0;
						cout << "Data Cleared Sucessfully"<<endl;
					}
					
				
					else if(menu=="4")
					{
						cout << "Exit Sucessfully" <<endl;
						return 0;
					}
					
					
					else
					{
						cout <<"Wrong Input" <<endl;
					}
				}
			}
    			else 
    			{
    			    cout << "Wrong password"<<endl
    			    	<< "Forget passwrod? (yes/no): ";
    			    string forget;
    			    getline(cin,forget);
    			    if(forget=="yes")
    			    {
    			    	cout << "Username is: " <<usrnme <<endl
    			    		<<"Password is: "<<password <<endl;
    			    		sleep(5);
    			    		system("CLS");
    			    }
    			    else
    			    {
    			    	cout <<"Program Finished";
    			    	return 0;
					}
    			    
    			    
    			}
    			
    			
    		}
    	}
    	else if (sign=="1")
    	{
    		return 0;
		}
		else 
		{
			continue;
		}
    	
    }
    return 0;
}


void seatsavailable (int pr, int vip, int eco)
{
	pr=rand()%1000;		//PREMIUM
	vip=rand()%1000;   //VIP
	eco=rand()%1000;  //ECONOMY
	
	cout<<endl <<"SEATS AVAILABILITY" <<endl
		<<"1. PREMIUM: "<<pr <<endl
		<<"2. VIP: "<<vip <<endl
		<<"3. ECONOMY: "<<eco <<endl;
}


void signup(string &name, string &num, string &username, string &password)
{
	cout << "Enter your name: ";
    getline(cin,name);
      while (true) 
	  {
        cout << "Enter Phone Number: ";
        cin >> num;
        if (num.length() == 11) 
		{
            break;                           // Exit the loop if the phone number is valid
        }
		else 
		{
			cout << "Invalid phone number. Please enter a valid phone Number" << endl;
		}
		
}
    cin.ignore();
        
    cout << "Enter Username: ";
    getline(cin,username);
        
    cout << "Enter Password: ";
    getline(cin,password);

}

void price(int num,int &kids,int &audlt,int &seniorCitizen)
{
		int choice;
		if(num==1)         //corresponds to the vip category
		{
			kids=5000;
			audlt=8000;
			seniorCitizen=3000;
		}
		else if(num==2)       //corresponds to the premium category
		{
			kids=4000;
			audlt=5000;
			seniorCitizen=2000;
		}
	
	    else
		{
			kids=2000;
			audlt=3000;
			seniorCitizen=1000;
		}
	
		cout << endl;
		cout <<"1. KIDS: "<<kids <<endl
			<< "2. AUDLTS: "<<audlt <<endl
			<< "3. seniorCitizen: "<<seniorCitizen <<endl;	
}
	
		
	
