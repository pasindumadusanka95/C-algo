#include <stdio.h>
#include "mymalloc.h"

int main(){	

	char* OS=MyMalloc(5000);
	char* ProcessA=MyMalloc(2000);
	char* ProcessB=MyMalloc(8000);
	MyFree(ProcessA);
	char* ProcessC=MyMalloc(8000);
	char* ProcessD=MyMalloc(1000);
	display();

	
	return 0;
}


//2016CS132
