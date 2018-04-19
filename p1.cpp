
#include<stdio.h>
struct process
{
char name;
int at,bt,ct,wt,tt,priority;
int processed;
float ntt;
}p[10];
int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}

int main()
{
int i,j,time=0,sum_bt=0,largest;
char c;
        float avgwt=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time , burst time, priority of process%c: ",p[i].name);
 scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].priority);
 p[i].processed=0;
 sum_bt+=p[i].bt;
 
}
void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
{
    
    for (i= 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
sortByArrival();
p[9].priority=-9999;
printf("\nName\tArrival Time\tBurst Time\tPriority\t WT \t TT \t NTT");
  for(time=p[0].at;time<sum_bt;)
  {
    largest=9;
    for(i=0;i<n;i++)
    {
      if(p[i].at<=time && p[i].processed!=1 && p[i].priority>p[largest].priority)
        largest=i;
    }
      time+=p[largest].bt;
  p[largest].ct=time;
          p[largest].wt=p[largest].ct-p[largest].at-p[largest].bt;
     p[largest].tt=p[largest].ct-p[largest].at;
     p[largest].ntt=((float)p[largest].tt/p[largest].bt);
    p[largest].processed=1;
    avgwt+=p[largest].wt;
printf("\n%c\t\t%d\t\t%d\t\t%d\t%d\t%d\t%f",p[largest].name,p[largest].at,p[largest].bt,p[largest].priority,p[largest].wt,p[largest].tt,p[largest].ntt);
}
printf("\nAverage waiting time:%f\n",avgwt/n);
}
