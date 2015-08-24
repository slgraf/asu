#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void Usage();

int main(int argc, char** argv)
{
	int numOfPeople, numOfCommand, commandIdx;
	char Names[50][20];
	char Commands[][20] = {"InsertionSort","MergeSort","ParallelMergeSort","Select","Average","ParallelAverage"};

	//Usage();

	srand(time(NULL));	

	if(argc>1)
	{
		if(argv[1][0]>='0' && argv[1][0]<='9')
		{
			numOfPeople = atoi(argv[1]);
		        //printf("Number of people is: %d\n",numOfPeople);

		        for (int i = 2; i <= numOfPeople+1; i++){
		                strcpy(Names[i],argv[i]);
		                //printf("%dth name is: %s \n", i-1, Names[i]);
		                numOfCommand = rand()%10;
		                printf("Start %s\n",Names[i]);
		                for (int j = 1; j <= numOfCommand+1; j++){
		                        commandIdx = rand()%6;
		                        if (commandIdx != 3) printf("%s\n",Commands[commandIdx]);
		                        else if (rand() % 5 ==0 ) printf("%s max\n",Commands[commandIdx]);
					else if (rand() % 5 ==1 ) printf("%s min\n",Commands[commandIdx]);
					else if (rand() % 5 ==2 ) printf("%s median\n",Commands[commandIdx]);
					else printf("%s %d\n",Commands[commandIdx],rand()%1500);
		                }
		                printf("End %s\n",Names[i]);
		        }
		        printf("Exit\n");
		}else{
			Usage();
		}
	}else{
		Usage();
	}
}

void Usage()
{
	printf("Usage:\n");
	printf("executable [N] [Name_1] [Name_2] ... [Name_N]\n");
	printf("N: Number of people. N<50\n");
	printf("Name_i: Name of the people (max name length is 20)\n \n");
}
