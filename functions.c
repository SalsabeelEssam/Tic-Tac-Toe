#include "function.h"

enum setup_stat setValue(s8 arr[3][3], s8 value, s8 row, s8 col) 
{
	/***********************************************************************************
	* in this condition, we check if anyone played in this place arr[row][col] before, 
	* if there is no one played before, update this place with this value and return 'set'
	* else  return 'not_set' you can't update this place 
	**********************************************************************************/
	if (('x' != arr[row][col]) && ('o' != arr[row][col])) {
		arr[row][col] = value;
		return set;
	} else {
		return not_set;
	}
}

void draw(const s8* arr)
 {
    //draw.
	/*********************************************************************************** 
		The first three lines is used to draw the first raw of the board
		we call the first three elements stored in the two dimentional array 'arr'
	***********************************************************************************/  
    printf("       |     | \n");
    printf("    %c  |  %c  |  %c\n",arr[0],arr[1],arr[2]);
    printf("  _____|_____|_____\n");
	
	/*********************************************************************************** 
		The second three lines is used to draw the second raw of the board
		we call the second three elements stored in the two dimentional array 'arr'
	***********************************************************************************/ 
    printf("       |     | \n");
    printf("    %c  |  %c  |  %c\n",arr[3],arr[4],arr[5]);
    printf("  _____|_____|_____\n");

	/*********************************************************************************** 
		The last three lines is used to draw the third raw of the board
		we call the last three elements stored in the two dimentional array 'arr'
	***********************************************************************************/ 
    printf("       |     | \n");
    printf("    %c  |  %c  |  %c\n",arr[6],arr[7],arr[8]);
    printf("       |     | \n\n");
 }



enum win_state isWin(s8 arr[3][3])
{   
    s8 i=0 ,j=0;
	
	
	/****************************************checking _rows****************************************/
	    
		if((arr[0][0]==arr[0][1] && arr[0][0]==arr[0][2])  )
		{
			if('x'==arr[0][0])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}	
			
		}
	    if((arr[1][0]==arr[1][1] && arr[1][0]==arr[1][2])  )
		{
			if('x'==arr[1][0])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
			
			
		}
		if((arr[2][0]==arr[2][1] && arr[2][0]==arr[2][2])  )
		{
			if('x'==arr[2][0])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
			
		}
		/********************************compeleted columns*********************************************/
	   if((arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0])  )
		{
			if('x'==arr[0][0])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
		}	
			
	   if((arr[0][1]==arr[1][1] && arr[0][1]==arr[2][1])  )
		{
			if('x'==arr[0][1])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
			
			
		}
		if((arr[0][2]==arr[1][2] && arr[0][2]==arr[2][2])  )
		{
			if('x'==arr[0][2])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
			
			
		}
		
	/*****************************checking diagonal**************************************************/
	if((arr[0][0]==arr[1][1]&& arr[0][0]==arr[2][2]))
	{   
		  if('x'==arr[0][0])
			{
				return winner_is_player1;
			}
			else
			{
				return winner_is_player2;
			}
	}
	
	if( (arr[1][1]==arr[0][2]&& arr[2][0]==arr[1][1] ))
	{  
           if('x'==arr[1][1])
			{
				return winner_is_player1;
			}
			else 
			{
				return winner_is_player2;
			}
	}
	
	
	/***********game still running*******************/

	for(i=0;i<3;i++)
	{  
		for(j=0;j<3;j++)
		{ 
			if(('x' != arr[i][j]) && ('o' != arr[i][j])  )
			{
								
				return Game_is_running;		
			}
		}
	}
   /***********game draw**********************/
	return Game_draw;
}


s32  Computer_Turn_Easy(s8 xo_Value[3][3]){
	
	/*   Variables which number of x and o is stored in each row ,colum and diagonal */
	// Number of x in Rows
	u8 row_x[3] ={0};
	// Number of x in Columns
	u8 col_x[3] ={0};

	u8 diagonal_rx = 0;            // number of x in Right diagonal
	u8 diagonal_lx = 0;			   // number of x in left diagonal
	// Number of o in Rows
	u8 row_o[3] ={0};
	// Number of o in Columns
	u8 col_o[3] ={0};

	u8 diagonal_ro = 0;            // number of o in Right diagonal
	u8 diagonal_lo = 0;            // number of o in Right diagonal

	// Place of the next move will be in
	s32 place=0;                    
	
	u8 i,j;
/***********************************************************************************
*	Rows, Colums and Diagonal analysis to calculate number of x and o 
*   in each Row, Colum and Diagonal
************************************************************************************/
	for(i=0;i<3;i++){
		// Rows and colums count of x and o
		for(j=0;j<3;j++){
			if(xo_Value[i][j]=='x'){
				row_x[i]++;
				col_x[j]++;
			}
			else if(xo_Value[i][j]=='o'){
				row_o[i]++;
				col_o[j]++;
			}
		}
		// Right and Left Diagonal count of x and o
		if (xo_Value[i][i]=='x')
			diagonal_rx++;
		else if(xo_Value[i][i]=='o')
			diagonal_ro++;
		if (xo_Value[i][2-i]=='x')
			diagonal_lx++;
		else if(xo_Value[i][2-i]=='o')
			diagonal_lo++;
	}

/***************************************************************
*    Periority 1 : In Case of play To Win the game
*	 (in case of there is Two o in one row or colum or diagonal 
*	 and the thrid place is Empty )	
***************************************************************/
	
	//Right Diagonal analysis
	if( (diagonal_rx == 0) && (diagonal_ro==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][i]!='o'){
				place = (i*4)+1;
				break;
			}
		}		
	}
	//Left Diagonal analysis
	else if( (diagonal_lx == 0) && (diagonal_lo==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][2-i]!='o'){
				place = (i*2)+3;
				break;
			}
		}		
	}
    // Rows analysis	
	// Row 1
	else if( (row_x[0] == 0) && (row_o[0]==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[0][i]!='o'){
				place = i+1;
				break;
			}
		}		
	}
	// Row 2
	else if((row_x[1] == 0) && (row_o[1]==2)){
	
		for(i=0;i<3;i++){
			if (xo_Value[1][i]!='o'){
				place = i+4;
				break;
			}
		}
		
	}
	// Row 3
	else if((row_x[2] == 0) && (row_o[2]==2)){
		
		for(i=0;i<3;i++){
			if (xo_Value[2][i]!='o'){
				place = i+7;
				break;
			}
		}
	}
	// colums analysis	
	// Colum 1
	else if((col_x[0] == 0) && (col_o[0]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][0]!='o'){
				place = (i*3)+1;
				break;
			}
		}
	}
	// Colum 2
	else if((col_x[1] == 0) && (col_o[1]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][1]!='o'){
				place = (i*3)+2;
				break;
			}
		}
	}
	// Colum 3
	else if((col_x[2] == 0) && (col_o[2]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][2]!='o'){
				place = (i*3)+3;
				break;
			}
		}
	}
/***********************************************************************
*   Periority 2 In Case of play To Prevent player from win the game 
*	(in case of there is Two x in one row or colum or diagonal 
*	and the thrid place is Empty )	   
***********************************************************************/
	// Right Diagonal analysis	
	else if( (diagonal_rx == 2) && (diagonal_ro==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][i]!='x'){
				place = (i*4)+1;
				break;
			}
		}		
	}
	// Left Diagonal analysis
	else if( (diagonal_lx == 2) && (diagonal_lo==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][2-i]!='x'){
				place = (i*2)+3;
				break;
			}
		}		
	}
	// Rows analysis
	//Row1
	else if( (row_x[0] == 2) && (row_o[0]==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[0][i]!='x'){
				place = i+1;
				break;
			}
		}		
	}
	//Row 2
	else if((row_x[1] == 2) && (row_o[1] ==0)){
	
		for(i=0;i<3;i++){
			if (xo_Value[1][i]!='x'){
				place = i+4;
				break;
			}
		}
		
	}
	// Row 3
	else if((row_x[2] == 2) && (row_o[2] ==0)){
		
		for(i=0;i<3;i++){
			if (xo_Value[2][i]!='x'){
				place = i+7;
				break;
			}
		}
	}
	// Colums analysis
	// Colum 1
	else if((col_x[0] == 2) && (col_o[0]==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][0]!='x'){
				place = (i*3)+1;
				break;
			}
		}
	}
	// Colum 2
	else if((col_x[1] == 2) && (col_o[1] ==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][1]!='x'){
				place = (i*3)+2;
				break;
			}
		}
	}
	//Colum 3
	else if((col_x[2] == 2) && (col_o[2] ==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][2]!='x'){
				place = (i*3)+3;
				break;
			}
		}
	}
/***********************************************************************
*	Periority 3 : In Case of play Normal Move (To try to win)
*	(in case of there is only one o in a row or colum or diagonal)
***********************************************************************/
	// Right Diagonal analysis
	else if( (diagonal_rx == 0) && (diagonal_ro==1) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][i]!='o'){
				place = (i*4)+1;
				break;
			}
		}		
	}
	// Left Diagonal analysis
	else if( (diagonal_lx == 0) && (diagonal_lo==1) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][2-i]!='o'){
				place = (i*2)+3;
				break;
			}
		}		
	}	

	// Rows analysis
	//Row 1
	else if( (row_x[0] == 0) && (row_o[0]==1) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[0][i]!='o'){
				place = i+1;
				break;
			}
		}		
	}
	// Row 2
	else if((row_x[1] == 0) && (row_o[1]==1)){
	
		for(i=0;i<3;i++){
			if (xo_Value[1][i]!='o'){
				place = i+4;
				break;
			}
		}
		
	}
	// Row 3
	else if((row_x[2] == 0) && (row_o[2]==1)){
		
		for(i=0;i<3;i++){
			if (xo_Value[2][i]!='o'){
				place = i+7;
				break;
			}
		}
	}
	// Colums analysis
	// Colum 1
	else if((col_x[0] == 0) && (col_o[0]==1)){

		for(i=0;i<3;i++){
			if (xo_Value[i][0]!='o'){
				place = (i*3)+1;
				break;
			}
		}
	}
	// Colum 2
	else if((col_x[1] == 0) && (col_o[1]==1)){

		for(i=0;i<3;i++){
			if (xo_Value[i][1]!='o'){
				place = (i*3)+2;
				break;
			}
		}
	}
	//Colum 3
	else if((col_x[2] == 0) && (col_o[2]==1)){

		for(i=0;i<3;i++){
			if (xo_Value[i][2]!='o'){
				place = (i*3)+3;
				break;
			}
		}
	}
/******************************************************************************
*	Periority 4 In Case of play 1ST Move oR there is No Win condition     
*******************************************************************************/
	else{
		// FIRST MoVE
		if ( (xo_Value[1][1]!='x') && (xo_Value[1][1]!='o') ){
			place = 5;
		}
		// Normal Move Where No win Condition or first move at place =1
		else{
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if ( (xo_Value[i][j]!='x') && (xo_Value[i][j]!='o') ){
						place = (i*3)+j+1;
						i=j=3;
						break;
					}
				}
			}
		}
	}	
	return place;
	
}

s32   Computer_Turn_Hard(s8 xo_Value[3][3]){
	
	
	/*   Variables which number of x and o is stored in each row ,colum and diagonal */
	// Number of x in Rows
	u8 row_x[3] ={0};
	// Number of x in Columns
	u8 col_x[3] ={0};

	u8 diagonal_rx = 0;            // number of x in Right diagonal
	u8 diagonal_lx = 0;			   // number of x in left diagonal
	// Number of o in Rows
	u8 row_o[3] ={0};
	// Number of o in Columns
	u8 col_o[3] ={0};

	u8 diagonal_ro = 0;            // number of o in Right diagonal
	u8 diagonal_lo = 0;            // number of o in Right diagonal

	// Place of the next move will be in
	s32 place=0;                    
	
	u8 i,j;
/***********************************************************************************
*	Rows, Colums and Diagonal analysis to calculate number of x and o 
*   in each Row, Colum and Diagonal
************************************************************************************/
	for(i=0;i<3;i++){
		// Rows and colums count of x and o
		for(j=0;j<3;j++){
			if(xo_Value[i][j]=='x'){
				row_x[i]++;
				col_x[j]++;
			}
			else if(xo_Value[i][j]=='o'){
				row_o[i]++;
				col_o[j]++;
			}
		}
		// Right and Left Diagonal count of x and o
		if (xo_Value[i][i]=='x')
			diagonal_rx++;
		else if(xo_Value[i][i]=='o')
			diagonal_ro++;
		if (xo_Value[i][2-i]=='x')
			diagonal_lx++;
		else if(xo_Value[i][2-i]=='o')
			diagonal_lo++;
	}

/***************************************************************
*    Priority 1 : In Case of play To Win the game
*	 (in case of there is Two o in one row or colum or diagonal 
*	 and the thrid place is Empty )	
***************************************************************/
	
	//Right Diagonal analysis
	if( (diagonal_rx == 0) && (diagonal_ro==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][i]!='o'){
				place = (i*4)+1;
				break;
			}
		}		
	}
	//Left Diagonal analysis
	else if( (diagonal_lx == 0) && (diagonal_lo==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][2-i]!='o'){
				place = (i*2)+3;
				break;
			}
		}		
	}
    // Rows analysis	
	else if( (row_x[0] == 0) && (row_o[0]==2) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[0][i]!='o'){
				place = i+1;
				break;
			}
		}		
	}
	else if((row_x[1] == 0) && (row_o[1]==2)){
	
		for(i=0;i<3;i++){
			if (xo_Value[1][i]!='o'){
				place = i+4;
				break;
			}
		}
		
	}
	else if((row_x[2] == 0) && (row_o[2]==2)){
		
		for(i=0;i<3;i++){
			if (xo_Value[2][i]!='o'){
				place = i+7;
				break;
			}
		}
	}
	// colums analysis	
	else if((col_x[0] == 0) && (col_o[0]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][0]!='o'){
				place = (i*3)+1;
				break;
			}
		}
	}
	else if((col_x[1] == 0) && (col_o[1]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][1]!='o'){
				place = (i*3)+2;
				break;
			}
		}
	}
	else if((col_x[2] == 0) && (col_o[2]==2)){

		for(i=0;i<3;i++){
			if (xo_Value[i][2]!='o'){
				place = (i*3)+3;
				break;
			}
		}
	}

/***********************************************************************
*   Priority 2 In Case of play To Prevent player from win the game 
*	(in case of there is Two x in one row or colum or diagonal 
*	and the thrid place is Empty )	   
***********************************************************************/
	// Right Diagonal analysis	
	else if( (diagonal_rx == 2) && (diagonal_ro==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][i]!='x'){
				place = (i*4)+1;
				break;
			}
		}		
	}
	// Left Diagonal analysis
	else if( (diagonal_lx == 2) && (diagonal_lo==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[i][2-i]!='x'){
				place = (i*2)+3;
				break;
			}
		}		
	}
	// Rows analysis
	//Row1
	else if( (row_x[0] == 2) && (row_o[0]==0) ){
		
		for(i=0;i<3;i++){
			if (xo_Value[0][i]!='x'){
				place = i+1;
				break;
			}
		}		
	}
	//Row 2
	else if((row_x[1] == 2) && (row_o[1] ==0)){
	
		for(i=0;i<3;i++){
			if (xo_Value[1][i]!='x'){
				place = i+4;
				break;
			}
		}
		
	}
	// Row 3
	else if((row_x[2] == 2) && (row_o[2] ==0)){
		
		for(i=0;i<3;i++){
			if (xo_Value[2][i]!='x'){
				place = i+7;
				break;
			}
		}
	}
	// Colums analysis
	// Colum 1
	else if((col_x[0] == 2) && (col_o[0]==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][0]!='x'){
				place = (i*3)+1;
				break;
			}
		}
	}
	// Colum 2
	else if((col_x[1] == 2) && (col_o[1] ==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][1]!='x'){
				place = (i*3)+2;
				break;
			}
		}
	}
	//Colum 3
	else if((col_x[2] == 2) && (col_o[2] ==0)){

		for(i=0;i<3;i++){
			if (xo_Value[i][2]!='x'){
				place = (i*3)+3;
				break;
			}
		}
	}
/***********************************************************************
*    Priority 3 : In Case of play Normal Move (To try to win)
*	(in case of there is only one o in a row or colum or diagonal)
***********************************************************************/
	// Right Diagonal analysis
	else if( (diagonal_rx == 0) && (diagonal_ro==1) && (diagonal_lx<2) ){
		
		if(xo_Value[0][0]=='o'){
			if( ((row_x[1]>0)&&(row_o[1]==0)) && ((col_x[1]>0)&&(col_o[1]==0)) )
			{
				place =5;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) && ((col_x[2]>0)&&(col_o[2]==0)) ){
				place =9;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) || ((col_x[1]>0)&&(col_o[1]==0)) )
			{
				place =5;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) || ((col_x[2]>0)&&(col_o[2]==0)) ){
				place =9;
			}
			else{
				place=9;
			}
		}
		else if(xo_Value[2][2]=='o'){
			if( ((row_x[0]>0)&&(row_o[0]==0)) && ((col_x[0]>0)&&(col_o[0]==0)) )
			{
				place =1;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) && ((col_x[1]>0)&&(col_o[1]==0)) ){
				place =5;
			}
			else if( ((row_x[0]>0)&&(row_o[0]==0)) || ((col_x[0]>0)&&(col_o[0]==0)) )
			{
				place =1;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) || ((col_x[1]>0)&&(col_o[1]==0)) ){
				place =5;
			}
			else{
				place=1;
			}
		}
		else{
			if( ((row_x[0]>0)&&(row_o[0]==0)) && ((col_x[0]>0)&&(col_o[0]==0)) )
			{
				place =1;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) && ((col_x[2]>0)&&(col_o[2]==0)) ){
				place =9;
			}
			else if( ((row_x[0]>0)&&(row_o[0]==0)) || ((col_x[0]>0)&&(col_o[0]==0)) )
			{
				place =1;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) || ((col_x[2]>0)&&(col_o[2]==0)) ){
				place =9;
			}
			else{
				place =1;
			}
		}
	
	}
	// Left Diagonal analysis
	else if( (diagonal_lx == 0) && (diagonal_lo==1) && (diagonal_rx<2) ){
		
		if(xo_Value[0][2]=='o'){
			if( ((row_x[1]>0)&&(row_o[1]==0)) && ((col_x[1]>0)&&(col_o[1]==0)) )
			{
				place =5;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) && ((col_x[0]>0)&&(col_o[0]==0)) ){
				place =7;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) || ((col_x[1]>0)&&(col_o[1]==0)) )
			{
				place =5;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) || ((col_x[0]>0)&&(col_o[0]==0)) ){
				place =7;
			}
			else{
				place=7;
			}
		}
		else if(xo_Value[2][0]=='o'){
			if( ((row_x[0]>0)&&(row_o[0]==0)) && ((col_x[2]>0)&&(col_o[2]==0)) )
			{
				place =3;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) && ((col_x[1]>0)&&(col_o[1]==0)) ){
				place =5;
			}
			else if( ((row_x[0]>0)&&(row_o[0]==0)) || ((col_x[2]>0)&&(col_o[2]==0)) )
			{
				place =3;
			}
			else if( ((row_x[1]>0)&&(row_o[1]==0)) || ((col_x[1]>0)&&(col_o[1]==0)) ){
				place =5;
			}
			else{
				place=3;
			}
		}
		else{
			if( ((row_x[0]>0)&&(row_o[0]==0)) && ((col_x[2]>0)&&(col_o[2]==0)) )
			{
				place =3;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) && ((col_x[0]>0)&&(col_o[0]==0)) ){
				place =7;
			}
			else if( ((row_x[0]>0)&&(row_o[0]==0)) || ((col_x[2]>0)&&(col_o[2]==0)) )
			{
				place =3;
			}
			else if( ((row_x[2]>0)&&(row_o[2]==0)) || ((col_x[0]>0)&&(col_o[0]==0)) ){
				place =7;
			}
			else{
				place=3;
			}
		}	
	}	
	// Rows analysis
	//Row 1
	else if( (row_x[0] == 0) && (row_o[0]==1) ){
		if(xo_Value[0][0]=='o'){
			place =3;
		}
		else if(xo_Value[0][2]=='o'){
			place =1;
		}
		else{
			if( (col_x[0]>0) && (col_o[0]==0) ){
				place=1;
			}
			else{
				place=3;
			}
		}	
	}
	// Row 2
	else if((row_x[1] == 0) && (row_o[1]==1)){
		if(xo_Value[1][0]=='o'){
			place =6;
		}
		else if(xo_Value[1][2]=='o'){
			place =4;
		}
		else{
			if( (col_x[0]>0) && (col_o[0]==0) ){
				place=4;
			}
			else{
				place=6;
			}
		}		
	}
	// Row 3
	else if((row_x[2] == 0) && (row_o[2]==1)){
		if(xo_Value[2][0]=='o'){
			place =9;
		}
		else if(xo_Value[2][2]=='o'){
			place =7;
		}
		else{
			if( (col_x[0]>0) && (col_o[0]==0) ){
				place=7;
			}
			else{
				place=9;
			}
		}
	}
	// Colums analysis
	// Colum 1
	else if((col_x[0] == 0) && (col_o[0]==1)){
		if(xo_Value[0][0]=='o'){
			place =7;
		}
		else if(xo_Value[2][0]=='o'){
			place =1;
		}
		else{
			if( (row_x[0]>0) && (row_o[0]==0) ){
				place=1;
			}
			else{
				place=7;
			}
		}
	}
	// Colum 2
	else if((col_x[1] == 0) && (col_o[1]==1)){
		if(xo_Value[0][1]=='o'){
			place =8;
		}
		else if(xo_Value[2][1]=='o'){
			place =2;
		}
		else{
			if( (row_x[0]>0) && (row_o[0]==0) ){
				place=2;
			}
			else{
				place=8;
			}
		}
	}
	//Colum 3
	else if((col_x[2] == 0) && (col_o[2]==1)){
		if(xo_Value[0][2]=='o'){
			place =9;
		}
		else if(xo_Value[2][2]=='o'){
			place =3;
		}
		else{
			if( (row_x[0]>0) && (row_o[0]==0) ){
				place=3;
			}
			else{
				place=9;
			}
		}
	}
/******************************************************************************
*   Priority 4 In Case of play 1ST Move oR there is No Win condition     
*******************************************************************************/
	else{
		//First Move
		if ( (xo_Value[1][1]!='x') && (xo_Value[1][1]!='o') ){
			place = 5;
		}
		// No win Condition for both Sides
		else{
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if ( (xo_Value[i][j]!='x') && (xo_Value[i][j]!='o') ){
						place = (i*3)+j+1;
						i=j=3;
						break;
					}
				}
			}
		}
	}
	return place;
	
}