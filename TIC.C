#include<stdio.h>
#include<conio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
int p;
void head()
{
	printf("\t\t\t\t-:Tic Tac Toe:-\n");
	printf("\t\t\t\t ------------- \n\n");
}
void show()
{
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[0],a[1],a[2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[3],a[4],a[5]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[6],a[7],a[8]);
	printf("\t\t\t---|---|---\n\n");
}
void symbol()
{
	printf("Symbols used by players:\n ");
	printf("\tPlayer 1: 0\n\tPlayer 2: X\n\n");
}
void start()
{
	printf("Enter who will start the game player 1 OR 2: ");
	scanf("%d",&p);
	if (p==1 || p==2){}
	else
	{
		printf("Unautherised player.\n");
		start();
	}
}
void play()
{
	int pos;
	printf("\nEnter the position of player %d: ",p);
	scanf("%d",&pos);
	if(a[pos-1]=='X' || a[pos-1]=='0')
	{
		printf("Unautherized position.\n");
		play();
	}
	else if(pos<1 || pos>9)
	{
		printf("Unautherized position.\n");
		play();
	}
	else
	{
		if(p==1)
		{
			a[pos-1]='0';
			p=2;
		}
		else if(p==2)
		{
			a[pos-1]='X';
			p=1;
		}
	}
}
int check()
{
	if(a[0]=='0' && a[1]=='0' && a[2]=='0')
		return 100;
	else if(a[0]=='X' && a[1]=='X' && a[2]=='X')
		return 200;
	else if(a[3]=='0' && a[4]=='0' && a[5]=='0')
		return 100;
	else if(a[3]=='X' && a[4]=='X' && a[5]=='X')
		return 200;
	else if(a[6]=='0' && a[7]=='0' && a[8]=='0')
		return 100;
	else if(a[6]=='X' && a[7]=='X' && a[8]=='X')
		return 200;

	else if(a[0]=='0' && a[3]=='0' && a[6]=='0')
		return 100;
	else if(a[0]=='X' && a[3]=='X' && a[6]=='X')
		return 200;
	else if(a[1]=='0' && a[4]=='0' && a[7]=='0')
		return 100;
	else if(a[1]=='X' && a[4]=='X' && a[7]=='X')
		return 200;
	else if(a[2]=='0' && a[5]=='0' && a[8]=='0')
		return 100;
	else if(a[2]=='X' && a[5]=='X' && a[8]=='X')
		return 200;

	else if(a[0]=='0' && a[4]=='0' && a[8]=='0')
		return 100;
	else if(a[0]=='X' && a[4]=='X' && a[8]=='X')
		return 200;

	else if(a[2]=='0' && a[4]=='0' && a[6]=='0')
		return 100;
	else if(a[2]=='X' && a[4]=='X' && a[6]=='X')
		return 200;
	return 300;
}
void main()
{
	int i,c;
	char more;
	Label:
	i=0;
	clrscr();
	head();
	show();
	symbol();
	start();
	play();
	c=check();
	while(c!=100  && c!=200)
	{
		clrscr();
		show();
		play();
		c=check();

		if(c==100){
			clrscr();
			show();
			printf("Player 1 WON the game.");
			getch();
			break;
		}
		else if(c==200){
			clrscr();
			show();
			printf("Player 2 WON the game.");
			getch();
			break;
		}
		i++;
		if(i==8)
			break;
	}
	if(i==8){
		show();
		printf("\t\tGAME OVER");
	}
    /*	fflush(stdin);
	printf("\n\nDo You want to play again: \nPress Y for yes and N for No: ") ;
	scanf("%c",more);
	if(more=='Y' || more=='y')
	{
		a[0]='1';
		a[1]='2';
		a[2]='3';
		a[3]='4';
		a[4]='5';
		a[5]='6';
		a[6]='7';
		a[7]='8';
		a[8]='9';
		goto Label;
	}  */
	getch();
}