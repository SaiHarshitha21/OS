#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int memsize;
    int allocp=-1;
    int pos;
    int allocSize;
}
m[200];
bool posSort(node a,node b)
{
    return a.pos<b.pos; 
}
bool memSort(node a,node b)
{
    return a.memsize > b.memsize; 
}
int main()
{
    int nm,np,choice, i, j, p[200];
    printf("Enter number of blocks\n");
    scanf(&nm);
    printf("Enter block size\n";
    for(i=0;i<nm;i++)
	{
        scanf(&m[i].memsize);
        m[i].pos=i;
    }
printf("Enter number of processes\n";
    scanf(&np);
    printF("Enter process size\n");
    for(i=0;i<np;i++)
	{
        scanf(&p[i]);
    }
    printf("\n\n";
    sort(m,m+nm,memSort);
    int globalFlag=0;
    for(i=0;i<np;i++)
	{
        int flag=0;
        for(j=0;j<nm;j++)
		{
            if(p[i]<=m[j].memsize && m[j].allocp==-1)
			{
                m[j].allocp=i;
                m[j].allocSize=p[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
		{
                printf("Unallocated Process P"<<i+1<<"\n");
                globalFlag=1;    
            }
        }
sort(m,m+nm,posSort);
    cout<<"\n";
    int intFrag=0,extFrag=0;
    printf("Memory\t\t");
    for(i=0;i<nm;i++)
	{
        printf(m[i].memsize<<"\t";
    }
    cout<<"\n";
    cout<<"P. Alloc.\t";
    for(i=0;i<nm;i++){
        if(m[i].allocp!=-1)
		{
            printf("P",m[i].allocp+1,"\t");
        }
        else
		{
            printf("Empty\t");
        }
    }
    printf("\n");
    printf("Int. Frag.\t");
    for(i=0;i<nm;i++)
	{
            if(m[i].allocp!=-1)
			{
                printf(m[i].memsize-m[i].allocSize,"\t");
                intFrag+=m[i].memsize-m[i].allocSize;
            }
else
           {
                extFrag+=m[i].memsize;
                printf("Empty\t");
            }
    }
    printf("\n");
    printf("\n");
    if(globalFlag==1)
        printf("Total External Fragmentation: ",extFrag,"\n");
    else
	{
        printf("Available Memory: ",extFrag,"\n");   
    }
printf("Total Internal Fragmentation: ",intFrag,"\n");
}
