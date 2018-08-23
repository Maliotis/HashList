#include <iostream>
#include <cstring>
#include "sinartiseis.h"

using namespace std;

int main()
{
	int ok, id;
	char id_inp[50], attr;
	
	initialize (3000);
	
	ok = create_id ((char*)"Musical_Instruments.txt", (char*)"Musical_Instruments_id.txt");
	if(ok==0) { cout<<"\nProvlima me tin create_id"<<endl; destroy(); return 0;}
	
	while(1)
	{ 
		cout<<"Doste str kai attribute (0 gia eksodo): ";
		cin>>id_inp>>attr;
		
		if(strcmp(id_inp, "0") == 0) break;
		
		id = return_id (id_inp, attr);	
	
		if(id<0) cout<<" -> Den vrethike"<<endl;
		else cout<<" -> "<<id<<endl;
	}

	destroy();
	
	return 0;
}
