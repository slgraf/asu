#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include <unistd.h>

char BName[21]={0};
int NumberOfFiles = 1;


void parseArgs(int argc, char** argv);
void createOneFile(int N, char* BaseName, int idx);
void printUsage();

//input argument includes the number of output files and the user name, e.g. EXECNAME  3    Mike
//by default, the number of output file is ONE, the user name is "HELLOWORLD"
int main(int argc, char** argv)
{

	int FIdx = 0;
	int Lines = 0;

	//parse input arguments to initialize the number of files and name
	parseArgs(argc, argv);
	//printUsage();

	//initialize the random seed
	srand(time(NULL));

	//create output files one by one
	//printf("Starting generating activity files...\n");
	for(int i=0;i<NumberOfFiles;i++)
	{
		Lines = 0;
		while(Lines<7)
          Lines = rand()%1000;
		
		//printf("Creating %dth output file...", i+1);
		createOneFile(Lines, BName, i);
		//printf("Done\n");
	}

	return 0;
}


void parseArgs(int argc, char** argv)
{
	int NoFiles = 1;

	if(argc>1)
	{
		if(argv[1][0]>='0' && argv[1][0]<='9')
		{
			NoFiles = atoi(argv[1]);

		}
		NumberOfFiles = NoFiles;
	}

	if(argc>2)
	{
		strcpy(BName, argv[2]);
	}
	else
	{
		strcpy(BName, "HelloWorld");
	}
}



void createOneFile(int N, char* BaseName, int idx)
{
	//create file, if file exists, overwrite it
	//FILE* OFile = 0;
	//char filenameIdx[40]={0};
	//char oneLine[20]={0};
	//sprintf(filenameIdx, "%s_%d.txt", BaseName, idx);

	//OFile = fopen(filenameIdx, "w");

	printf("%d\n", N);
	//fwrite(oneLine, sizeof(char), strlen(oneLine), OFile);
	int lvl;
	for(int i=0;i<N;i++)
	{
		lvl = rand()%3;
		switch(lvl)
		{
			case 0://low
				lvl = rand()%4500 + 500;
				break;

			case 1://median
				lvl = rand()%20000 + 5000;
				break;

			case 2://high
				lvl = rand()%50000 + 25000;
				break;
		}
		printf("%d\n", lvl);
		//memset(oneLine, 0, sizeof(char)*20);
	    //sprintf(oneLine, "%d\n", lvl);
	    //fwrite(oneLine, sizeof(char), strlen(oneLine), OFile);

	}


	//close file, return the index working
	//fclose(OFile);
}


//print the usage of the utility
void printUsage()
{
	printf("Commnad [N] [Name]\n");
	printf("N: the number of output files\n");
	printf("Name: the name of output files\n");
}
