#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
struct process
{
char proces_name;
int atime, btime, ct, wtime, ttime, priority;
int status;
}
proces_queue[10];

int limit;

void ATime_Sorting()
{
struct process temp;
int i, j;
for(i = 0; i < limit - 1; i++)
{
for(j = i + 1; j < limit; j++)
{
if(proces_queue[i].atime > proces_queue[j].atime)
{
temp = proces_queue[i];
proces_queue[i] = proces_queue[j];
proces_queue[j] = temp;
}
}
}
}
int main()
{
int i, time = 0, btime = 0, large;
char c;
float wtime = 0, ttime = 0, average_wtime, average_ttime;
//printf("\nEnter Total Number of Processes:\t");
 //scanf("%d", &limit);
 limit=4;
 	
 /*for(i = 0, c = 'A'; i < limit; i++, c++)
 {
 		proces_queue[i].proces_name = c;
		printf("\nEnter Details For Proces[%C]:\n", proces_queue[i].proces_name);
		printf("Enter Arrival Time:\t");
		scanf("%d", &proces_queue[i].atime );
		printf("Enter Burst Time:\t");
		scanf("%d", &proces_queue[i].btime);
		printf("Enter Priority:\t");
		scanf("%d", &proces_queue[i].priority);
 		proces_queue[i].status = 0;
 		btime = btime + proces_queue[i].btime;
	}*/
	proces_queue[1].atime=0;
	proces_queue[1].btime=4;
	btime =btime + proces_queue[1].btime;
	proces_queue[1].proces_name='A';
	proces_queue[2].proces_name='B';
	proces_queue[3].proces_name='C';
	proces_queue[4].proces_name='D';
	proces_queue[2].atime=2;
	proces_queue[1].status = 0;
	proces_queue[2].status = 0;
	proces_queue[3].status = 0;
	proces_queue[4].status = 0;
	
	proces_queue[2].btime=1;
        proces_queue[2].atime=1;
	btime = btime + proces_queue[2].btime;
	
	proces_queue[3].atime=2;
	proces_queue[3].btime=2;
	btime = btime + proces_queue[3].btime;
	
	proces_queue[4].atime=3;
	proces_queue[4].btime=1;
	btime = btime + proces_queue[4].btime;
	
	
	printf("enter the priorities\n");
	for(i=1;i<=limit;i++)
	{
		scanf("%d",&proces_queue[i].priority);
	}
	ATime_Sorting();
	proces_queue[9].priority = -9999;
	printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
  	for(time = proces_queue[1].atime; time < btime;)
  	{
    	large = 9;
    	for(i = 1; i <= limit; i++)
    	{
      	if(proces_queue[i].atime <= time && proces_queue[i].status != 1 && proces_queue[i].priority >proces_queue[large].priority)
        {
	large = i;
	}
    	}
      	time = time + proces_queue[large].btime;
  	proces_queue[large].ct = time;
        proces_queue[large].wtime = proces_queue[large].ct - proces_queue[large].atime - proces_queue[large].btime;
     	proces_queue[large].ttime = proces_queue[large].ct - proces_queue[large].atime;
    	proces_queue[large].status = 1;
    	wtime = wtime + proces_queue[large].wtime;
	ttime = ttime + proces_queue[large].ttime;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", proces_queue[large].proces_name, proces_queue[large].atime, proces_queue[large].btime,          proces_queue[large].priority, proces_queue[large].wtime);


	average_wtime = wtime / limit;
	average_ttime = ttime / limit;
	printf("\n\nAverage waiting time:\t%f\n", average_wtime);
        printf("Average Turnaround Time:\t%f\n", average_ttime);
}
}

