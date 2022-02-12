

#ifndef FUNCTION_H_
#define FUNCTION_H_
	//includes
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "STD_TYPES.h"
	
	//enums
	enum setup_stat{not_set, set};
	enum game_turn{player1_turn, player2_turn};
	enum win_state{Game_is_running,winner_is_player1,winner_is_player2,Game_draw};
	
	//prototypes 
	/************************************************************************************************
	* Function Name         : draw
	* Function Description  : Function to draw the X_O game board
	* [args]                : const s8 *p
	* [in]                  : Address of first element exists in two 
	*						: dimensional array
	*
	* [out]                 : X_O board with number of each square 
	*						: in the board from (1 to 9)
	*						  
	* [in/out]  			: None
	* [Returns]  			: void
	************************************************************************************************/
	void draw(const s8* );
	
	/************************************************************************************************
	* Function Name         : setValue
	* Function Description  : Function to set game from player if x or o check if  we can 
	*                       : set value in a specific place return ture else reture false 
	* [args]                : arr[3][3], value, row, col
	* [in]                  : arr[3][3] : Pointer to Array of Array
	*                       : value : signed char have "X" or "O" that update game with
	*                       : row : signed char have number of row in arr[3][3]
	*                       : col : signed char have number of col in arr[3][3]
	* [out]                 : none
	* [in/out]              : none
	* [Returns]             : enum setup_stat
	*                       : not_set : return 0 if false we can't update value 
	*                       : set : return 1 if true we can update value 
	************************************************************************************************/
	enum setup_stat setValue(s8 [3][3], s8 , s8 , s8);
	
	/************************************************************************************************
	*Function Name          : isWin
	*Function Description   : isWin function check the state of game continuously then return then return one  
    *                       : of the realized states (game running , player1 is winner,player2 is winner, game draw)
	*[Inputs]       		: s8 arr[3][3] (This function receives 2D array (X_O Board)
	*[Returns]         		: enum that contains that contains game states .
	************************************************************************************************/
	enum win_state isWin(s8 [3][3]);
	
	/*************************************************************************
	* Functions Name       : Computer_Turn_Easy
	* Function Description : Functions To determine the next move of computer
	* [arg]                : XO_Value[3][3]
	* [in]                 : XO_Value[3][3] (2d array of values of game)
	* 
	* [out]                : none
	* [Returns]            : place of the next move by computer
	**************************************************************************/
	s32  Computer_Turn_Easy(s8 [3][3]);
	
	/*************************************************************************
	* Functions Name       : Computer_Turn_Hard
	* Function Description : Functions To determine the next move of computer
	* [arg]                : XO_Value[3][3]
	* [in]                 : XO_Value[3][3] (2d array of values of game)
	* 
	* [out]                : none
	* [Returns]            : place of the next move by computer
	**************************************************************************/
	s32   Computer_Turn_Hard(s8 [3][3]);
#endif