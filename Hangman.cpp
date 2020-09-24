#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>
using namespace std;
int NUM_TRY=3;
int checkGuess(char,string,string&);
void main_menu();
string message;
int main()
{
    string name,month;
    char letter;
    string months[]=
    {
    	"january",
    	"february",
    	"march",
    	"april",
    	"may",
    	"june",
    	"july",
    	"august",
    	"september",
    	"october",
    	"november",
    	"december"
    };
    srand(time(NULL));
    int n=rand()%12;
    month=months[n];
    string hide_m(month.length(),'X');
    cout<<"\n\t\t\t\tHANGMAN GAME!";
    cout<<"\n\n\nRules of the game are as follows:";
    cout<<"\n\n1.Category: Months of the Year.";
    cout<<"\n2.Total number of tries: 3";
    cout<<"\n3.Guess the correct month in the given number of tries or you will be hanged!";
    cout<<"\n\n\n\t\t\t\tENJOY!";
    getch();
    while(NUM_TRY!=0)
    {
    	main_menu();
    	cout<<"\n\n\t\t\t\t"<<hide_m;
    	cout<<"\n\n\t\t\t\tGuess a letter:";
    	cin>>letter;
    	if(checkGuess(letter,month,hide_m)==0)
    	{
			message="Incorrect letter.";
    		NUM_TRY=NUM_TRY-1;
    	}
    	else
    		message="NICE!You guessed a letter.";
     	if(month==hide_m)
    	{
    		system("cls");
			cout<<"\n\n\n\t\t\t\tCONGRATULATIONS!";
			cout<<"\n\t\t\t\tYou guessed the word!";
    		cout <<"\n\n\t\t\t\tTHE MONTH IS: "<<month<<endl;
    		break;
    	}
    }
    if(NUM_TRY==0)
    {
    	message="YOU HAVE BEEN HANGED!";
    	main_menu();
    	cout<<endl;
    	cout<<endl;
    	cout<<"\t\t|----------------------"<<endl;
    	cout<<"\t\t|                      |"<<endl;
    	cout<<"\t\t|                      O"<<endl;
    	cout<<"\t\t|                      |"<<endl;
    	cout<<"\t\t|                      X"<<endl;
    	cout<<"\t\t                      - -"<<endl;
    	cout<<"\n\n\t\t\tTHE MONTH WAS: "<<month<<endl;
    }
    getch();
    return 0;
}
int checkGuess(char guess,string secretmonth,string &guessmonth)
{
    int i;
    int matches=0;
    int len=secretmonth.length();
    for(i=0;i<len;i++)
    {
    	if(guess==secretmonth[i])
    	{
    		guessmonth[i]=guess;
    		matches++;
    	}
    }
    return matches;
}
void main_menu()
{
    system("cls");
    cout<<"\n\t\t\t\tHANGMAN GAME!";
    cout<<endl;
    cout<<endl;
    cout<<"\n\t\tYou have "<<NUM_TRY<<" tries left to try to guess the month.";
    cout<<"\n\n\t\t"<<message;
}
