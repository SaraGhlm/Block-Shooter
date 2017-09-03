#include <iostream>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                      
#include <time.h>
#include <Windows.h>

using namespace std;

extern int move_ball , main_ball_color , main_balls[3] , arColor[5] , minus , summation , should_restart , should_quit , x1 , click ;
extern float mx , my ;
extern char score[] ;
struct ball { int color , x , y , visit ; } ;
extern struct ball matBall[15][15] ;
int tscore = 0 ;

void slant ( int x , int y )
{
	if ( click == 0 )
	{
		int i , j , r = 1 , tempx , tempy , rx , ry , diffx , diffy , getout = 0 , b , temp_color[5] = {0} , k , exist = 0 , l = 0 ;
		srand ( time ( NULL ) ) ;
		move_ball = 1 ;
		x1 = x ;
		diffx = x - 305 ;
		tempx = abs ( diffx ) ;
		diffy = y - 580 ;
		tempy = abs ( diffy ) ;
		for ( i = 2 ; i <= abs (diffx ) || i <= ( diffy ) ; ++ i ) 
		{
			for ( j = 2 ; j < i ; ++ j )
			{
				r = i % j ;
				if ( r == 0 )
				break ;
			}
			if ( r == 0 )
				continue ;
			else
			{
				while ( tempx != 0 && tempy != 0 && getout == 0 ) 
				{
					rx = tempx % i ;
					ry = tempy % i ;
					if ( rx == 0 && ry == 0 )
					{
						tempx = tempx / i ;
						tempy = tempy / i ;
					}
					else
						getout = 1  ;
				}
				getout = 0 ;
			}
		}
		mx = tempx ;
		my = tempy ;
		while ( my > 10 || mx > 10 )
		{
			mx = mx / 10 ;
			my = my / 10 ;
		}
		main_ball_color = main_balls[0] ;
		main_balls[0] = main_balls[1] ;
		main_balls[1] = main_balls[2] ;
		for ( i = 0 ; i < 15 ; i ++ )
		{
			for ( j = 0 ; j < 15 ; j ++ )
			{
				for ( k = 0 ; k < 5 ; k ++ )
				{
					if ( matBall[i][j].color == temp_color[k] || matBall[i][j].color == BLACK )
						exist = 1;
				}
				if ( exist == 0 )
					temp_color[l++] = matBall[i][j].color ;
				exist = 0 ;
			}
		}
		b = rand () %(l-1) ;
		main_balls[2] = temp_color[b] ;
		if ( x >= 670 && x <= 770 && y >= 300 && y <= 330 )
			should_restart = 1 ;
		if ( x >= 670 && x <= 740 && y >= 400 && y <= 430 )
			should_quit = 1 ;
	}
}

void my_score ()
{
	int temp_score , r ;
	char tochar ;
	if ( minus == 1 )
	{
		tscore -- ;
		temp_score = abs ( tscore ) ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[3] = tochar ;
		temp_score = temp_score / 10 ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[2] = tochar ;
		temp_score = temp_score / 10 ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[1] = tochar ;
		temp_score = temp_score / 10 ;
	}
	if ( summation == 1 )
	{
		tscore += 2 ;
		temp_score = abs( tscore ) ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[3] = tochar ;
		temp_score = temp_score / 10 ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[2] = tochar ;
		temp_score = temp_score / 10 ;
		r = temp_score % 10 ;
		tochar = r + '0' ;
		score[1] = tochar ;
		temp_score = temp_score / 10 ;
	}
	if ( tscore < 0 )
		score[0] = '-' ;
	if ( tscore >= 0 )
		score[0] = '+' ;
	summation = 0 ;
	minus = 0 ;
}