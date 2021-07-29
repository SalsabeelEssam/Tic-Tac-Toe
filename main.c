// gcc main.c functions.c 
#include "function.h"

int main(void)
{
	s8 input;
	s8 player1[10];
	s8 player2[10];
	s8 xo_game[3][3];
	s32 choice;
	s8 row;
	s8 col;
	s8 check_winer;
	
	enum game_turn turn;
	enum setup_stat is_seted;
	
	printf("Welcome\n");
	while(1)
	{
		do
		{
			printf("please enter 's' to start new game or 'e' to exit\n");
			// return the input = 0 after each iteration
			scanf("%c",&input);
			fflush(stdin);
		}while(input != 's' && input != 'e');
	
		if(input == 's')//  s for start the game 
		{
			
			printf("\n");
			printf("Choose from options bellow:-\n\n");
			printf("   1- Player vs Player\n");
			printf("   2- Player vs Computer\n\n");
			printf("Enter option Num : ");
			scanf("%c",&input);
			fflush(stdin);
			printf("\n");
			
			if('1' == input)
			{
				printf("Enter player1 name : ");
				scanf("%s",player1);
				printf("Enter player2 name : ");
				scanf("%s",player2);
			}
			
			else if('2' == input)
			{
				printf("Enter player name : ");
				scanf("%s",player1);
				printf("\n");
				printf("Choose from options bellow:-\n\n");
				printf("   1- Enter 'ce' for easy level\n");
				printf("   2- Enter 'ch' for hard level\n\n");
				printf("Enter your choice : ");
				//user can play with another user or with our system in two options (easy , hard)
				scanf("%s",player2);
				
			}
			system("cls");
			
			printf("%s-> x\n%s -> o\n",player1,player2);
			
			//our game matrix 3*3 from 1 to 9 (XO_game)
			s8 xo_game[3][3] =
			{
				{'1','2','3'},
				{'4','5','6'},
				{'7','8','9'},
			};
			turn = player1_turn;
			check_winer = 0;
			do
			{
				
				draw((s8*)xo_game);
				printf("%s your turn\nchoose square by number ",(turn == player1_turn) ? player1 : player2);
				// to know if second player is system (easy,hard)or another player 
				if(player2_turn == turn && (strcmp(player2,"ce") == 0 || strcmp(player2,"ch") == 0) && '2'==input)
				{
					if(strcmp(player2,"ce") == 0)
						choice = Computer_Turn_Easy(xo_game);// easy mood 
					else if(strcmp(player2,"ch") == 0)
						choice = Computer_Turn_Hard(xo_game);// hard mood
				}
				else
				{
					scanf("%d", &choice);// another player
					fflush(stdin);
				}
				
				
				if(choice <=9 && choice > 0)
				{
					// convert number to (row, column)
					row = (s8)(choice-1)/3;
					col = (s8)(choice-1)%3;
					// set "X" if player_1 turn and "O" if player_2 turn 
					is_seted = (turn == player1_turn) ? setValue(xo_game,'x',row,col) : setValue(xo_game,'o',row,col);
					if(is_seted == set)
					{
						// check after 5 turns if any win because we sure that no win till 5 turn
						check_winer++;
						if(check_winer<5 || isWin(xo_game) == Game_is_running)
						{
							//switch turn between two players
							turn = (turn == player1_turn) ? player2_turn : player1_turn;
						}
						else if(isWin(xo_game) == winner_is_player1)
						{
							// player1 wins
							system("cls");
							printf("congratulation %s win the game\n",player1);
							draw((s8*)xo_game);
							break;
						}
						else if(isWin(xo_game) == winner_is_player2)
						{
							// player2 wins
							system("cls");
							if((strcmp(player2,"ce") == 0 || strcmp(player2,"ch") == 0) && '2'==input)
							{
								printf("You Lose The Game\n");
							}	
							else
							{
								printf("congratulation %s win the game\n",player2);
							}
							draw((s8*)xo_game);
							break;
						}
						else if(isWin(xo_game) == Game_draw)
						{
							// all cells are filled and game is over
							system("cls");
							printf("Game is over no winner\n");
							draw((s8*)xo_game);
							break;
						}
						system("cls");
						
					}
					else 
					{
						//if any player choosed filled cell 
						system("cls");
						printf("Please enter empty place\n");
					}
					
				}
				else
				{
					// if any player put invalid cell
					system("cls");
					printf("please choose number from 1 to 9\n");
				}
				
				
			}while(1);

		}
		else if(input == 'e')//  e for exit from the game 
		{
			break;
		}
	}
	return 0;

}