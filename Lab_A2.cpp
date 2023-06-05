QUESTION ::
----------------------------------------------------------------------------------------
Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers.
----------------------------------------------------------------------------------------
SOURCE CODE ::
-------------------------------------------------------------------------------------
#include <iostream>
#include<string>
using namespace std;
class node
{
    string name;
    long int tel;
    int id;
    public :
    node()
    {
        tel=0;
        id=0;
    }
    friend class hashing;
};
class hashing
{
    node data[100];
    string n;
    long int t;
    int i,index;
    public :
    hashing()
    {
        i=0;
        t=0;
    }
    void create_record(int size,int x)
    {
        for(int y=0;y<x;y++)
        {
            cout<<"\nEnter Id  : ";
            cin>>i;
            cout<<"\nEnter the telephone : ";
            cin>>t;
            cout<<"\nEnter the name : ";
            cin>>n;
            index=i%size;
            for(int j=0;j<size;j++)
            {
                if(data[index].id==0)
                {
                    data[index].id=i;
                    data[index].name=n;
                    data[index].tel=t;
                    break;
                }
                else
                {
                    index=(index+1)%size;
                }
            }
        }
    }
    
    void display_record(int size)
    {
        cout<<"\n\tID \t NAME\t\t\tTELEPHONE"<<endl;
        for(int a=0;a<size;a++)
        {
            if(data[a].id!=0)
            {
                cout<<"\n\t"<<data[a].id<<" \t"<<data[a].name<<"\t\t"<<data[a].tel;
            }
        }
    }
    void search_record(int size)
    {
        int index1,key,flag=0;
        cout<<"\nEnter the Id to Search in Hash table :: ";
        cin>>key;
        index1=key%size;
        for(int a=0;a<size;a++)
        {
        	if(data[index1].id==key)
        	{
        		flag=1;
        		cout<<"\nRecord Found "<<"\tname "<<"\tTelephone "<<"\t "<<endl;
        		cout<<"\n"<<data[index1].id<<"\t"<<data[index1].name<<"\t"<<data[index1].tel;
			    break;
			}
			else
			{
				index1=(index1+1)%size;
			}
		}
		if(flag==0)
		{
			cout<<"\nReord not found....."<<endl;
		}
    }
    void delete_record(int size)
    {
    	int index1,key,flag=0;
    	cout<<"\nEnter id to delete Record :: ";
    	cin>>key;
    	index1=key%size;
    	for(int a=0;a<size;a++)
    	{
    		if(data[index1].id==key)
    		{
    			flag=1;
    			data[index1].id=0;
    			data[index1].name=" ";
    			data[index1].tel=0;
    			cout<<"\nRecord deleted successfully......"<<endl;
    			break;
			}
			else
			{
				index1=(index1+1)%size;
			}
		}
		if(flag==0)
		{
			cout<<"\nRecord not found ....."<<endl;
		}
	}
	void update_record(int size)
	{
		int index1,key,flag=0;
		cout<<"\nEnter Record id to upadate..."<<endl;
		cin>>key;
		index1=key%size;
		for(int a=0;a<size;a++)
		{
			if(data[index1].id==key)
			{
				flag=1;
				break;
			}
			else
			{
				index1=(index1+1)%size;
			}
		}
		if(flag==1)
		{
			cout<<"\nEnter the name :: ";
			cin>>n;
			cout<<"\nEnter the phone :: ";
			cin>>t;
			data[index1].name=n;
			data[index1].tel=t;
			cout<<"\n\t\t........DETAILS UPDATED......."<<endl;
			cout<<"\nId \tname\t\tTelePhone"<<endl;
			cout<<"\n\t"<<data[index1].id<<"\t"<<data[index1].name<<"\t\t"<<data[index1].tel;
		}
	}
};

int main()
{
    int size,ch;
    hashing s;
    int x;
    size=20;
    cout<<"\nHow many Record do You want :: "<<endl;
    cin>>x;
    cout<<"\nCreate Record :: "<<endl;
    do
    {
    	cout<<"\n1-create Record \n2-Display Record\n3-Search Record \n4-Upadate Record \n5-delete"<<endl;
    	cout<<"\nEnter your choice :: "<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			s.create_record(size,x);
    			break;
    		case 2:
    			s.display_record(size);
    			break;
    		case 3:
    			s.search_record(size);
    			break;
    		case 4:
    			s.update_record(size);
    			break;
    		case 5:
    			s.delete_record(size);
    			break;
		}
		cout<<"\nDo you want you continue press.....1"<<endl;
		cin>>ch;
    }while(ch==1);
    return 0;
}

--------------------------------------------------------------------------------
OUTPUT ::
---------------------------------------------------------------------------------

How many Record do You want ::
5

Create Record ::

1-create Record
2-Display Record
3-Search Record
4-Upadate Record
5-delete

Enter your choice ::
1

Enter Id  : 101

Enter the telephone : 77448834

Enter the name : kunal

Enter Id  : 102

Enter the telephone : 99753652

Enter the name : balaji

Enter Id  : 103

Enter the telephone : 74653788

Enter the name : rutu

Enter Id  : 104

Enter the telephone : 83736373

Enter the name : yash

Enter Id  : 105

Enter the telephone : 8837363

Enter the name : pratik

Do you want you continue press.....1
1

1-create Record
2-Display Record
3-Search Record
4-Upadate Record
5-delete

Enter your choice ::
2

        ID       NAME                   TELEPHONE

        101     kunal           77448834
        102     balaji          99753652
        103     rutu            74653788
        104     yash            83736373
        105     pratik          8837363
Do you want you continue press.....1
1

1-create Record
2-Display Record
3-Search Record
4-Upadate Record
5-delete

Enter your choice ::
3

Enter the Id to Search in Hash table :: 102

Record Found    name    Telephone

102     balaji  99753652
Do you want you continue press.....1
1

1-create Record
2-Display Record
3-Search Record
4-Upadate Record
5-delete

Enter your choice ::
4

Enter Record id to upadate...
101

Enter the name :: lagad

Enter the phone :: 8866775

                ........DETAILS UPDATED.......

Id      name            TelePhone

        101     lagad           8866775
Do you want you continue press.....1
1

1-create Record
2-Display Record
3-Search Record
4-Upadate Record
5-delete

Enter your choice ::
2

        ID       NAME                   TELEPHONE

        101     lagad           8866775
        102     balaji          99753652
        103     rutu            74653788
        104     yash            83736373
        105     pratik          8837363
Do you want you continue press.....1
2
