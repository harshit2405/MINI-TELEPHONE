#include<iostream>
#include<string.h>
using namespace std;
int j=0; long int history[20]={0};
class landline
{  protected:
    string Name;
    long int No;

public:
    void call(long int n)
    { No=n;
     cout<<"\nCALLING THE CUSTOMER "<<No<<endl;
     history[j]=No;
	 j++;
    }
    void recieve()
    {
        cout<<"\nCONGRATULATIONS!!!!YOU ARE GETTING A CALL!!"<<endl;
    }
    void hist()
    {   int k;
        cout<<"\nYOUR CALL HISTORY IS GETTING REVEALED:::"<<endl;
        for(int p=0;p<20;p++)
            cout<<"\n"<<p+1<<".)"<<history[p];
        cout<<"\nSELECT AN OPTION FROM THE ABOVE NUMBER:"<<endl;
        cin>>k;
        call(history[--k]);
    }
};
class mobile:public landline
{
        long int fno[20];
        string fname[20];int n;
        public:
    void phonebook()
    {
        cout<<"\nENTER THE NUMBER OF CONTACTS YOU WANT TO SAVE :) "<<endl;
        cin>>n;
        cout<<"ENTER DATA INTO THE PHONEBOOK IN ORDER:name,number ::"<<endl;
        for(int i=0;i<n;i++)
           {cin>>fname[i];
            cin>>fno[i];
           }
    }
      void call(string subname,landline ob)
      {
          cout<<"\nSEARCHING THE NAME!!!!"<<endl;
          for(int i=0;i<n;i++)
            {if(subname==fname[i])
              {ob.call(fno[i]);break;}
            else
                cout<<"\nSORRY,NUMBER IS MISSING!!"<<endl;}
      }

};
int main()
{   char c,w;
	int ch;
    mobile obj;
    obj.phonebook();
    string a;
    do{
		cout<<"\t\tCALL AND DIRECTORY";
		cout<<"\n\n1. Place a call\n2. CALL HISTORY\n\nPress number according to choice  =  ";
		cin>>ch;
		if(ch==1)
			{   do
			    {
				cout<<"\nENTER THE NAME YOU WANT TO CALL.."<<endl;
    			cin>>a;	
    			obj.call(a,obj);
    			obj.hist();
    			obj.recieve();
    			cout<<"\n\nDo you want to use this again, press 'Y' = ";
    			cin>>w;
				}while(w=='Y');
			}
		else if (ch==2)
			{
				do
			    {
    			obj.hist();
    			obj.recieve();
    			cout<<"\n\nDo you want to use this again, press 'Y' = ";
    			cin>>w;
				}while(w=='Y');
				
			}
    	else
    		cout<<"\nWRONG OPTION !!!";
    	cout<<"\n\nDo you want to use this again, press 'Y' = ";
    	cin>>c;
	}while(c=='Y');
    
    return 0;
}
