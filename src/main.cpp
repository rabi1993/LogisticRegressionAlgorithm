#include <iostream>
#include <vector>
#include "include/IoClass.h"
#include "include/ProcessData.h"

using namespace std;

//Main Function starts here 
int main()
{	
	IoClass io;
	io.getData();
	ProcessData pd;
	pd.process(io);
	return 0;
}
