#include <iostream> //Header files
#include <cstdlib>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;
char num[10] = {'o','1','2','3','4','5','6','7','8','9'};
enum players { Computer, Human, Draw, None };
const int iWin[8][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }, { 2, 4, 6 } }; //win situation checking for single player mode

void single();

void SetColor(int ForgC) //Function to set different text color in console
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void about(char x) //Function to show about data (about games and developers)
{
    if(x=='1')
    {
        SetColor(7);
     cout<<"\n\t\t\t\t\t\t### Tic Tac Toe ###\n\n\tTic-tac-toe (also known as Noughts and crosses or Xs and Os) is a paper-and-pencil game for two players,\n X and O, who take turns marking the spaces in a 3*3 grid.\n The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.\n For more details please visit https://en.wikipedia.org/wiki/Tic-tac-toe \n";
    }
    else
    {
        SetColor(9);
        cout<<"\n\n\t Hello!\n\t We are";
        SetColor(10);
    cout<<"\n\n\t\tMehedi Hasan Akash\n\t\tMusfiqur Rahman Saikat\n\t\tSadia Islam\n\t\tSanjida Tasnim Munia\n\t\tShakib Khan\n";
    }
}

void game() //Function to draw main game diagram for multiplayer mode
{
    SetColor(9);
    cout << "\n\n\t   xoxo> Tic Tac Toe <oxox\n\n";
    SetColor(11);
    cout << "\tPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    SetColor(7);
    cout << "\t        |     |     " << endl;
    cout << "\t     " << num[1] << "  |  " << num[2] << "  |  " << num[3] << endl;

    cout << "\t   _____|_____|_____" << endl;
    cout << "\t        |     |     " << endl;

    cout << "\t     " << num[4] << "  |  " << num[5] << "  |  " << num[6] << endl;

    cout << "\t   _____|_____|_____" << endl;
    cout << "\t        |     |     " << endl;

    cout << "\t     " << num[7] << "  |  " << num[8] << "  |  " << num[9] << endl;

    cout << "\t        |     |     " << endl << endl;
}

int win()  //Function to return status 1 for game over with a success,-1 for game in progress and 0 for game over & draw situation (for multiplayer mode)
{
    if (num[1] == num[2] && num[2] == num[3])

        return 1;
    else if (num[4] == num[5] && num[5] == num[6])

        return 1;
    else if (num[7] == num[8] && num[8] == num[9])

        return 1;
    else if (num[1] == num[4] && num[4] == num[7])

        return 1;
    else if (num[2] == num[5] && num[5] == num[8])

        return 1;
    else if (num[3] == num[6] && num[6] == num[9])

        return 1;
    else if (num[1] == num[5] && num[5] == num[9])

        return 1;
    else if (num[3] == num[5] && num[5] == num[7])

        return 1;
    else if (num[1] != '1' && num[2] != '2' && num[3] != '3'
                    && num[4] != '4' && num[5] != '5' && num[6] != '6'
                  && num[7] != '7' && num[8] != '8' && num[9] != '9')

        return 0;
    else
        return -1;
}

char mult() //Function to run multiplayer mode
{
    int player = 1,i,j,k=9;//player for showing who's turn, i for winner check, j and k for controlling reset loop
    char n,p,ch; //n for putting Xs and Os, ch for player's input, p for new game and main menu
    do
    {
        game();
        player=(player%2)?1:2;
        SetColor(15);
        cout << " Player " << player << ", enter a number:  ";
        ch=getch();

        n=(player == 1) ? 'X' : 'O';

        if (ch == '1' && num[1] == '1')

            num[1] = n;
        else if (ch == '2' && num[2] == '2')

            num[2] = n;
        else if (ch == '3' && num[3] == '3')

            num[3] = n;
        else if (ch == '4' && num[4] == '4')

            num[4] = n;
        else if (ch == '5' && num[5] == '5')

            num[5] = n;
        else if (ch == '6' && num[6] == '6')

            num[6] = n;
        else if (ch == '7' && num[7] == '7')

            num[7] = n;
        else if (ch == '8' && num[8] == '8')

            num[8] = n;
        else if (ch == '9' && num[9] == '9')

            num[9] = n;
        else
        {
            system("cls");
            SetColor(12);
            cout<<"\t\tWARNING!!!\n\n\tInvalid move!\n\tPress ENTER and Try again";
            player--;
            cin.ignore();
        }
        system("cls");
        i=win();
        player++;
    }
    while(i==-1); //To check whether to continue game or not
    game();
    if(i==1)
    {
        SetColor(10);
        cout<<"\t  Congratulation...\n\t*** Player "<<--player<<" won ***\n";
    }
    else
    {
        SetColor(8);
        cout<<"\t%%% Game draw %%%\n";
    }
for(j=0;j<=k;j++) //To reset game to play again (for multiplayer mode)
{
    if(j==0)
    {
        num[j]='o';
    }
    else if(j==1)
    {
        num[j]='1';
    }
    else if(j==2)
    {
        num[j]='2';
    }
    else if(j==3)
    {
        num[j]='3';
    }
    else if(j==4)
    {
        num[j]='4';
    }
    else if(j==5)
    {
        num[j]='5';
    }
    else if(j==6)
    {
        num[j]='6';
    }
    else if(j==7)
    {
        num[j]='7';
    }
    else if(j==8)
    {
        num[j]='8';
    }
    else if(j==9)
    {
        num[j]='9';
    }
}
    jump4:
        SetColor(15);
    cout<<"\n\tAnother round?\tEnter 1";
    cout<<"\n\tTo Return to Main menu.\tEnter 2\n\tEnter:";
    p=getch();
    if (p=='1'||p=='2')
    {
        return p;
    }
    else
    {
        system("cls");
        SetColor(12);
        cout<<"\n\tWrong input!\n\tTry again\n\n";
        goto jump4;
    }
}

int mainmenu() //Function to control main menu
{
    char c,ch;//ch for about menu
    int m=0; //c for user choice, m for main menu
    SetColor(10);
    cout<<"    <%%%%% Main Menu %%%%%>\n";
    cout<<endl;
    SetColor(9);
    cout<<"\t1.Single player \n";
    cout<<"\t2.Multiplayer \n";
    cout<<"\t3.About\n";
    cout<<"\t4.EXIT \n";
    SetColor(15);
    cout<<"\n Enter your choice (1,2,3 or 4):";
    c=getch();
    system("cls");
    if (c=='1'||c=='2'||c=='3'||c=='4')
    {
    if(c=='1') //single player
    {
        single();
    }
    else if(c=='2')
    {
        char o='1';
        char *m;
        m=&o;
        while(*m=='1')
        {
         o=mult();
         system("cls");
        }
         if (*m=='2')
        {
            mainmenu();
        }
    }

     else if(c=='3') //This will show the about data of the program
    {
        jump1:
        SetColor(10);
        cout<<"\t   $$$ About $$$\n";
        cout<<endl;
        SetColor(11);
        cout<<"\t1.About Game\n";
        cout<<"\t2.About Developers\n";
        SetColor(15);
        cout<<"\n Enter your choice (1 or 2):";
        ch=getch();
        system("cls");
        if(ch=='1' || ch=='2')
        {
         about(ch);
        }
        else
        {
            system("cls");
            SetColor(12);
            cout<<"\n\tWrong input!\n\tTry again\n\n";
            goto jump1;
        }
        char r;
        jump2:
        SetColor(15);
        cout<<"\n\tTo Return to Main menu\n\tEnter 1:";
        r=getch();
        system("cls");
        if (r=='1')
        {
            mainmenu();
        }
        else
        {
            system("cls");
            SetColor(12);
            cout<<"\n\tWrong input!\n\tTry again\n\n";
            goto jump2;
            system ("cls");
        }
    }

        else if(c=='4') //This will end the program
        {
            return 0;
        }
    }
        else
        {
            SetColor(12);
            cout<<"\n\tWrong input!\n\tTry again\n\n";
            mainmenu();
        }
}

class ttt
{
public:
    ttt()
     {
         p = rand() % 2;
         reset();
     }

    void play()
    {
	int res = Draw;//res is the variable to define game result
	while( true )
	{
	    drawGrid();
	    while( true )
	    {
		if( p )
        {
            getHumanMove();
        }
		else
        {
            getComputerMove();
        }
		drawGrid();
		res = checkVictory();
		if( res != None )
            {
                break;
            }

		++p %= 2;
	    }
	    if( res == Human )
            {
                SetColor(10);
                cout << "\n\n\n\n\n\n\nCONGRATULATIONS HUMAN\n*** You won! ***";
            }
	    else if( res == Computer )
        {
            SetColor(14);
            cout << "\n\n\n\n\n\n\nNOT SO MUCH A SURPRISE\n*** I won! ***";
        }
	    else
        {
            SetColor(8);
            cout << "\n\n\n\n\n\n\nIt's a draw!";
        }
	    cout << endl << endl;

	    string st;
	    jump5:
        SetColor(15);
	    cout << "\n\nTo play again enter Y\nTo exit enter N\n( Y / N )? ";
	    cin >> st;

	    if (st=="n"||st=="N")
        {
            return;
        }
        else if( st != "Y" && st != "y" && st != "N" && st != "n" )
        {
            SetColor(12);
            cout<<"\n Wrong input!\n Try again";
            SetColor(15);
            goto jump5;
	    }
        ++p %= 2;
	    reset();
	}
    }

private:
    void reset()
    {
	for( int x = 0; x < 9; x++ )
	    field[x] = None;
    }

    void drawGrid()//this will draw diagram for single player
    {
	system( "cls" );
    COORD c = { 0, 2 }; //For console cursor positioning {x,y}
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );

    SetColor(9);
    cout << "   xoxo> Tic Tac Toe <oxox\n\n";
    SetColor(7);
    cout << "   you have O  -  I have X\n";
    cout << endl;
    SetColor(13);
    cout << "        |     |     " << endl;
    cout << "     1  |  2  |  3  " << endl;
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    cout << "     4  |  5  |  6  " << endl;
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    cout << "     7  |  8  |  9  " << endl;
    cout << "        |     |     " << endl;

	int f = 0;
	for( int y = 5; y < 14; y += 3 )
	    for( int x = 5; x < 18; x += 6 )
	    {
		if( field[f] != None )
		{
		    COORD c = { x, 2 + y };
		    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
		    string o = field[f] == Computer ? "X" : "O"; //for computer X, for player O
		    cout << o;
		}
		f++;
	    }
        c.Y = 9;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
    }

    int checkVictory() //Function to check win situations
    {
	for( int i = 0; i < 8; i++ )
	{
	    if( field[iWin[i][0]] != None &&field[iWin[i][0]] == field[iWin[i][1]] && field[iWin[i][1]] == field[iWin[i][2]] )
	    {
		return field[iWin[i][0]];
	    }
	}
	int i = 0;
	for( int f = 0; f < 9; f++ )
	{
	    if( field[f] != None )
		i++;
	}
	if( i == 9 )
        {
            return Draw;
        }
	return None;
    }

    void getHumanMove() //Function to get player moves
    {
	int m;
	SetColor(15);
	cout << "\n\n\n\n\n\n\nEnter your move ( 1 - 9 ) and press enter: ";
	while( true )
	{
	    m = 0;
	    do
	    { cin >> m; }
	    while( m < 1 && m > 9 );

	    if( field[m - 1] != None )
          {
              SetColor(12);
              cout << "Invalid move. Try again!" << endl;
              SetColor(15);
          }
	    else break;
	}
	field[m - 1] = Human;
    }

    void getComputerMove() //Function to get computer moves
    {
	int move = 0;

	do{ move = rand() % 9; }
	while( field[move] != None );

	for( int i = 0; i < 8; i++ )
	{
	    int try1 = iWin[i][0], try2 = iWin[i][1], try3 = iWin[i][2];

	    if( field[try1] != None && field[try1] == field[try2] && field[try3] == None )
	    {
		move = try3;
		if( field[try1] == Computer ) break;
	    }

	    if( field[try1] != None && field[try1] == field[try3] && field[try2] == None )
	    {
		move = try2;
		if( field[try1] == Computer ) break;
	    }

	    if( field[try2] != None && field[try2] == field[try3] && field[try1] == None )
	    {
		move = try1;
		if( field[try2] == Computer ) break;
	    }
        }
	field[move] = Computer;
    }
int p;
int field[9];
};

void single()
{
    srand( GetTickCount() );//Srand will seed the random number generator to prevent random numbers from being the same every time the program is executed and to allow more pseudorandomness
    ttt tic;
    tic.play();
}

int main()
{
    mainmenu();
}
