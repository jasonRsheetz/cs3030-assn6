#include <stdio.h>
#include <stdlib.h>

void SSTF(int*, int);

int main(int argc, char *argv[])
{
//arrays to hold the process run-time and the time the process was added to the ready queue
int access_list[100];


//open the file
FILE *fp = stdin;
if(argc > 1)
{
fp = fopen(argv[1], "r");
        if(fp==NULL)
                {
                perror("error opening file");
                return -1;
                }
}

//while loop index
int i = 0;
int number;

//read run times into arrays
while(fscanf(fp, "%d", &number) != EOF)
{
access_list[i] = number;
i++;
}
//number of processes is half of i
int count = i;

//start with first come first serve
//FCFS(access_list, count);

//shortest seek time first
SSTF(access_list, count);


return 0;
}

void FCFS(int *access_list, int count)
{
//loop variable
int i;

int total_seek = 0;

for(i = 0; i < count; i++)
{
//find the time between the ith and the next accesses
total_seek = total_seek + access_list[i];
}


}

void SSTF(int *access_list, int count)
{
int *this_access_list = access_list;
int current_access = access_list[0];
int next_access;
int temp = access_list[0];
int distance = this_access_list[0];
int total_access = 0;
int i, j, tracker;

for(i = 0; i < count; i++)
{

	for(j = 0; j < count; j++)
	{
		while(this_access_list[j] == 0)
		{
			j++;
		}

	next_access = this_access_list[j];
	temp = next_access - current_access;
	temp = abs(temp);

		if(temp < distance && temp > 0)
		{
			distance = temp;
			tracker = j;
		}

	}
this_access_list[0] = 0;
total_access = total_access + distance;
current_access = this_access_list[tracker];
this_access_list[tracker] = 0;
distance = 1000;
printf("%d\n", total_access);
}



}





























