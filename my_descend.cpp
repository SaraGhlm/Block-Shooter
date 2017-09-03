#include <iostream>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                      
#include <time.h>
#include <Windows.h>

using namespace std;

const int RADIUS = 20 ;
struct ball { int color , x , y , visit ; } ;
extern struct ball matBall[15][15] ;
extern int arColor[5] , enter_descend , gameOver ;

void descend (  )
{
	int i , m , n , b , new_color[7] , counter = 0 ;
	for ( i = 0 ; i < 5 ; i ++ )
		new_color[i] = arColor[i] ;
	srand ( time ( 0 ) ) ;
	for ( m = 13 ; m >= 0 ; m -- )
	{
		for ( n = 0 ; n < 15 ; n ++ )
		{
			matBall[m+1][n].x = matBall[m][n].x ;
			matBall[m+1][n].y = matBall[m][n].y + 40 ;
			matBall[m+1][n].color = matBall[m][n].color ;
			matBall[m+1][n].visit = matBall[m][n].visit ;
		}
	}
	if ( enter_descend % 2 )
	{
		for ( n = 0 ; n < 15 ; n ++ )
		{
			new_color[5] = matBall[1][n].color ;
			new_color[6] = matBall[1][n+1].color ;
			again :
			b = rand () %7 ;
			for ( i = 0 ; i < n ; i ++ )
			{
				if ( matBall[0][i].color == new_color[b] )
					counter ++ ;
			}
			if ( counter == 5 )
			{
				counter = 0 ;
				goto again ;
			}
			matBall[0][n].x = 40 * n + 20 ;
			matBall[0][n].y = 20 ;
			matBall[0][n].color = new_color[b] ;
			counter = 0 ;
		}
	}
	else 
	{
		for ( n = 0 ; n < 15 ; n ++ )
		{
			new_color[5] = matBall[1][n].color ;
			new_color[6] = matBall[1][n+1].color ;
			Again :
			b = rand () %7 ;
			for ( i = 0 ; i < n ; i ++ )
			{
				if ( matBall[0][i].color == new_color[b] )
					counter ++ ;
			}
			if ( counter == 5 )
			{
				counter = 0 ;
				goto Again ;
			}
			matBall[0][n].x = 40 * n + 40 ;
			matBall[0][n].y = 20 ;
			matBall[0][n].color = new_color[b] ;
			counter = 0 ;
		}
	}
	setfillstyle ( SOLID_FILL , BLACK ) ;
	bar ( 0 , 0 , 630 , 610 ) ; 
	for ( m = 0 ; m < 15 ; m ++ )
    {
	   for ( n = 0 ; n < 15 ; n ++ )
	   {
		   if ( matBall[m][n].color != BLACK )
		   {
			   setcolor ( matBall[m][n].color ) ;
			   setfillstyle ( SOLID_FILL , matBall[m][n].color ) ;
			   fillellipse ( matBall[m][n].x , matBall[m][n].y , RADIUS , RADIUS ) ;
		   }
	   }
    } 
	for ( n = 0 ; n < 15 ; n ++ )
	{
		if ( matBall[13][n].color != BLACK )
		{
			setfillstyle ( SOLID_FILL , WHITE ) ;
			outtextxy ( 200 , 300 , "GAME OVER" ) ;
			gameOver = 1 ;
			Sleep ( 3000 ) ;
		}
	}
	enter_descend ++ ;
}