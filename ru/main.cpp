#include<winsock.h>
#include<mysql.h>
#include<bits/stdc++.h>
#include<string>
#include<cstdio>
#include<conio.h>
using namespace std;
vector<string>d_array;
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
void printingredient(vector<string>d_array);
int convertToASCII(string letter);
int main() {

   char *server = "localhost";
   char *user = "root";
   char *password = "admin";
   char *database = "clc";

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      return(0);
   }
/*    string pass ="";
   char ch;
    int c;
    int admin=0;
    int userr=0;
    cout<<"ENTER ACCESS OPTION"<<endl;
    cout<<"1)USER"<<endl;
    cout<<"2)ADMIN"<<endl;
    cin>>c;
    if(c==2)
    {
        cout<<"Enter Password"<<endl;
        ch = _getch();
        while(ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
         }
         cout<<endl;
         if(pass == "admin")
         {
             cout<<"Access granted"<<endl;admin=1;

         }
         else
         {
                cout<<"Access not granted"<<endl;
                exit(1);
         }
    }

if(admin==1){
int qstate;
stringstream ss;
string d_name;
cout<<"ENTER DISH NAME"<<endl;
cin>>d_name;

int n;
string ingredient;
int stop=0;
int countt=0;
while(stop!=1){
    string str="insert into ";
    cout<<"PRESS 1 TO ENTER INGREDINTS"<<endl;how to
    cout<<"PRESS 2 TO END"<<endl;
    //cout<<"select"<<endl;
    cin>>n;

    switch(n){
        case 1:{
                cin>>ingredient;
                str=str+ingredient+"(d_name) values('"+d_name+"')";
                //cout<<str<<endl;
                const char* q=str.c_str();
                qstate=mysql_query(conn,q);

                cout<<endl;
                countt++;
                break;
            }
        case 2:{
                stop=1;
                string st;
                ss<<countt;
                ss>>st;
                string query="insert into dish (d_name,no_ingredient)  values('"    + d_name +   "',"    + st +   ")";
                //cout<<query;
                const char* q=query.c_str();
                qstate=mysql_query(conn,q);
                cout<<"THANK YOU FOR ADDING NEW DISH"<<endl;
                break;
            }
    }
}
}*/
int c=1;
if(c==1){
cout<<"WELCOME"<<endl<<endl;
int n;
int stop=0;
cout<<"ENTER THE INGREDIENTS YOU HAVE AND GET IDEAS FOR DELICIOUS DISHES"<<endl<<endl;

string ingre;
while(stop!=1){
    cout<<"PRESS 1 TO ENTER INGREDIENTS"<<endl;
    cout<<"PRESS 2 COMPLETE"<<endl;
    cin>>n;

    switch(n){
    case 1:{
        string query="select d_name from ";
        cout<<"ENTER INGREDIENT"<<endl;
        cin>>ingre;
           if(conn){
                query=query+ingre;
                //cout<<op<<endl;
                const char * q=query.c_str();
                //cout<<&q<<endl;
                int qstate=mysql_query(conn,q);
                if(!qstate){
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)) != NULL){
                                d_array.push_back(row[0]);
                                }
                        }
                }

            }
            break;
    case 2:{
            stop=1;
            printingredient(d_array);
            break;

        }

    }
}
}

/*for(int i=0;i<d_array.size();i++){
    cout<<d_array[i]<<endl;
}*/
cout<<endl;
mysql_free_result(res);
mysql_close(conn);

}
int convertToASCII(string letter){
	int sum=0;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        sum=sum+int(x);
    }
    return sum;
}
void printingredient(vector<string>d_array){
    //int size=sizeof(d_array)/sizeof(d_array[0]);
    int siz=d_array.size();
	sort(d_array.begin(),d_array.end());
	/*for(int i=0;i<siz;i++)
	{
		cout<<d_array[i]<<" ";

	}*/
    cout<<endl;
	//cout<<size<<endl;
	vector<int>has[siz];//hash

	stack<string>stac;
	stac.push(d_array[0]);
	//cout<<stac.top()<<endl;

	int j;
	for(int i=0;i<siz;i++){
		has[i].push_back(0);
	}
	for(int i=0;i<siz;i++){
	int j=convertToASCII(d_array[i])%siz; //hash function
		if(stac.top()==d_array[i]){
			has[j][has[j].size()-1]++;
		}
		else{

			stac.push(d_array[i]);

			if(has[j][has[j].size()-1]!=0){
				has[j].push_back(0);
			}
			has[j][has[j].size()-1]++;
		}
	}
	/*for(int i=0;i<siz;i++)
	{
		for(int j=0;j<has[i].size();j++)
		{
			cout<<has[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int yy=stac.size();
/*	for(int i=0;i<yy;i++){
        cout<<stac.top()<<endl;
        stac.pop();
	}
*/
int flag=0;
for(int i=0;i<yy;i++){


    string x=stac.top();
    string a;
    string b;
    int k=convertToASCII(x)%siz;
    int num = has[k][has[k].size()-1];
    has[k].resize(has[k].size()-1);
    stringstream qq;
    qq<<num;
    qq>>b;

    //select no_ingredient form dish where d_name =x;
    string query="select no_ingredient from dish where d_name = ";
    query = query+"'"+x+"'";
    //cout<<query<<endl;
    if(conn){
        const char * q=query.c_str();
        int qstate=mysql_query(conn,q);
        if(!qstate){
                res = mysql_store_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL){
                        a=row[0];

                        //cout<<"a = "<<a<<endl;
                                                }
                    }
        }
        else cout<<"gadbad"<<endl;
    //cout<<a<<" "<<b<<endl;
    if(a==b){

        cout<<x<<" CAN BE PREPARED"<<endl;
        flag=1;
    }
    stac.pop();
}
if (flag==0) cout<<"SORRY NO DISH FOUND"<<endl;

}
