#include <stdio.h>

int main() {
    int n;
    printf("enter how MANY processes are there\n");
    scanf("%d",&n);
    struct fcfs{
    char processname;
    float xi, ai, ci, wi, ti;
}p[n];

    for(int i=0; i<3; i++){
        printf("Enter the burst time and arrival time for each process[%d];\n", i+1);
        scanf("%f %f", &p[i].xi, &p[i].ai);
    }
    for(int i=0; i<n; i++){
        p[i].ci=(p[i].xi)+p[i-1].ci;
	p[i].wi=(p[i].ci)-(p[i].xi)-p[i].ai;
	p[i].ti=(p[i].ci)-p[i].ai;
    }
 
   float avgwi=0;
     float avgti=0;
    for(int i=0;i<n;i++)
        {avgwi=avgwi+p[i].wi;}
        avgwi=avgwi/n;

      for(int i=0;i<n;i++)
        {avgti=avgti+p[i].ti;}
        avgti=avgti/n;
    
    printf("\nprocess  ci      wi     ti\n");
    for(int i=0; i<n; i++){
        printf("p[%d]\t%3.2f\t%3.2f\t%3.2f\n", i+1, p[i].ci, p[i].wi, p[i].ti);
    }
    printf("\nAverage waiting time: %3.2f\n", avgwi);
    printf("\nAverage turnaround time: %3.2f\n", avgti);
    return 0;
}