#include <iostream> 
#include <fstream>
#include <jsoncpp/json/json.h>
#include <string.h>
#define col 128 
#define row 10 

using namespace std;
char* path = new char[30];
char line[row][col];

int slashcount(){
	int count=0;
	for(int i=0; i<strlen(path); i++)
	{
		if(path[i]=='/')
			count++;
	}
	return count;
}

void mkdir(char* dp){
	ifstream ifs("drive.json");
	ofstream ofs("drive2.json");
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs, obj);

	int count=slashcount();
	for(int i=0; i<strlen(dp); i++)
	{
		if(dp[i]=='/')
			count++;
	}
	count++;
	cout<<count;
	if(count==3)
	{
		obj.append(dp);
	}
	else if(count==4)
	{
		int i=0;
		char lone[10];
		char ltwo[10];

		while(dp[i]!='/')
		{
			lone[i]=dp[i];
			i++;
		}

		i++;
		int j=0;
		for(i; i<strlen(dp); i++)
		{
			ltwo[j]=dp[i];
			j++;
		}
		
		obj[lone].append(ltwo);
	}
	ofs<<obj;
	remove("drive.json");
	rename("drive2.json","drive.json");		
}

void rm(char* dp){
	ifstream ifs("drive.json");
	ofstream ofs("drive2.json");
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs, obj);

	int count=slashcount();
	for(int i=0; i<strlen(dp); i++)
	{
		if(dp[i]=='/')
			count++;
	}
	cout<<count;
	if(count==3)
	{
		//cout<<obj.get(dp,"does not exist")<<endl;
		obj.removeMember(dp);
	}
	else if(count==4)
	{
		int i=0;
		char lone[10];
		char ltwo[10];

		while(dp[i]!='/')
		{
			lone[i]=dp[i];
			i++;
		}

		i++;
		int j=0;
		for(i; i<strlen(dp); i++)
		{
			ltwo[j]=dp[i];
			j++;
		}
		
		obj[lone].removeMember(ltwo);
	}
	ofs<<obj;
	remove("drive.json");
	rename("drive2.json","drive.json");
}

char* cd(char* op){
	if(op=="..")
	{	
		int count=slashcount();

		if(count>=3)
		{
			int er=0;
			int i=0, j=0;
			char* p2 = new char[30];
			while(er < count)
			{
				if(path[i]=='/')
				{
					er++;
				}
				if(er<count)
				{
				p2[j]=path[i];
				j++;
				i++;
				}
			}
			strcpy(path,p2);
		}
	}
	else
	{
		strcat(path,"/");
		strcat(path,op);
	}
}

void ls(){
	ifstream ifs("drive.json");
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs, obj);

	int count=0;
	char lone[10];
	char ltwo[10];
	int j=0;
	cout<<"Current path is"<<path<<endl;
	for(int i=0; i<strlen(path); i++)
	{
		if(path[i]=='/')
		{
			count++;
			i++;
			j=0;
		}
		if(count==4)
		{
			lone[j]=path[i];
			j++;
		}
		else if(count==5)
		{
			ltwo[j]=path[i];
			j++;
		}	
	}
	lone[j]='\0';
	ltwo[j]='\0';
	if(count>=3)
	{
		if(count==5)
		{
			cout<<obj[lone].get(ltwo,"does not exist")<<endl;
		}
		else if(count==4)
		{
	cout<<"lone: "<<lone<<endl;
			cout<<obj.get(lone,"does not exist")<<endl;
		}
		else if(count==3)
			cout<<obj<<endl;	
	}
}

int main(int argc, char** args) {

	char c;
	char dir;
	int i =0;
	// FILE *fptr = NULL;
	// string line;

	// fptr = fopen("drive.json", "r");
 //    while(fgets(line[i], col, fptr)) {
 //        line[i][strlen(line[i]) - 1] = '\0';
 //        i++;
 //    }

 //    for(int i=0; i<18; i++){                                //Use this to check the array
 //      printf("%s\n", line[i]);
 //    }

	
	strcpy(path, " home/seed/Desktop/drive.json");
	while(1){

	
		printf("Enter an option\n");
		printf("1. ls\n");
		printf("2. rm\n");
		printf("3. mkdir\n");
		printf("4. cd\n");
		printf("5. import\n");

		printf("Input: ");
		c = getchar();

		if(c == '1'){			
			ls();
		}
		else if(c == '2'){
			rm("D"); //working
		}
		else if(c == '3'){
			mkdir("D"); //gives error but working
		}
		if(c == '4'){
			cd("D");
			cout<<"Current path is"<<path<<endl;
		}	
		if(c == '5'){
			cout<<"\nOption not implemented yet\n"<<endl;
		}			
		c = getchar();
	}
	return 1;
}
