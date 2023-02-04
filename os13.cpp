#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void recurse(int files[])
{
    int flag = 0, startBlock, len, j, i, ch;
    printf("Enter the starting block and the length of the files: ");
    scanf("%d%d", &startBlock, &len);
    for (j=startBlock; j<(startBlock+len); j++)
	{
        if (files[j] == 0)
            flag++;
    }
    if(len == flag)
	{
        for (int i=startBlock; i<(startBlock+len); i++)
		{
            if (files[i] == 0)
			{
                files[i] = 1;
                printf("%d\t%d\n",i, files[i]);
            }
        }
        if (i!= (startBlock+len-1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");
    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files);
    else
        exit(0);
    return;
}

int main()
{
int files[50];
for(int l=0;l<50;l++)
files[l]=0;
printf("Files Allocated are :\n");

recurse(files);
getch();
return 0;
}
