// Sara Gholami ( 92222087 )

#include <iostream>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                      
#include <time.h>
#include <Windows.h>

using namespace std;

const int RADIUS = 20 ;
int main_ball_color , arColor[5] = { LIGHTRED , YELLOW , LIGHTGREEN , MAGENTA , LIGHTBLUE } ;
int tempArColor[5] , numcolor[5] , enter_descend , move_ball = 0 , click = 0 ;
int gameOver = 0 , out = 0 ,  main_balls[3] , x1 , check_balls = 0 , uncorrect_shoot = 0 ;
int  Rstrike = 0 , Lstrike = 0 , start_delete = 0 , should_restart = 0 , should_quit = 0 ;
float mx , my , ti = 0 , tj = 0 ;
char score[5] ={0000} ;
struct ball { int color , x , y , visit ; } ;
struct ball matBall[15][15] ;
extern int v , tscore ;

void drowMat () ;
void descend () ;
void winning () ;
void slant ( int , int ) ;
void moving () ;
int find_same_color ( int , int ) ;
void remove_balls () ;
void reset () ;
void drow_pipe ( int , int ) ;
void suspense_balls () ;

int APIENTRY WinMain
( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
restart_game :
	initwindow ( 810 , 610 , "Balls" ) ;
	int i , j , p = 2 , t ;
	int m = 0 , n = 0 , circ = 0 , col , quit = 0 , window = 0 ;
	int outflag = 0 , out1 = 0 , out2 = 0 , sum = 0 ;
	enter_descend = 0 ;
	for ( i = 0 ; i < 4 ; i ++ )
	{
		score[i] = '0' ;
	}
	drowMat () ;
	t = time ( 0 ) ;
    while ( 1 )
	{
		setactivepage ( p ) ;
		cleardevice () ;
		//drow toolbar
		setfillstyle ( SOLID_FILL , LIGHTMAGENTA ) ;
	    bar ( 630 , 0 , 810 , 610 ) ;
		setcolor ( LIGHTMAGENTA ) ;
		setfillstyle ( SOLID_FILL , LIGHTMAGENTA ) ;
		bar ( 670 , 300 , 770 , 330 ) ;
		settextstyle( 7 , 0 , 4 ) ;
		outtextxy ( 670 , 300 , "Restart" ) ;
		bar ( 670 , 400 , 740 , 430 ) ;
		settextstyle( 7 , 0 , 4 ) ;
		outtextxy ( 670 , 400 , "Quit" ) ;
		outtextxy ( 670 , 50 , "Score" ) ;
		outtextxy ( 670 , 100 , score ) ;
		//drow balls
		for ( i = 0 ; i < 15 ; i ++ )
		{
			for ( j = 0 ; j < 15 ; j ++ )
			{
				if ( matBall[i][j].color != BLACK )
				{
					setcolor ( matBall[i][j].color ) ;
					setfillstyle ( SOLID_FILL , matBall[i][j].color ) ;
					fillellipse ( matBall[i][j].x , matBall[i][j].y , RADIUS , RADIUS ) ;
				}
			}
		}
		//drow 3 main ball
		setcolor ( main_balls[0] ) ;
		setfillstyle ( SOLID_FILL , main_balls[0] );
		fillellipse ( 305 , 580 , RADIUS , RADIUS ) ;
		setcolor ( main_balls[1] ) ;
		setfillstyle ( SOLID_FILL , main_balls[1] );
		fillellipse ( 265 , 580 , RADIUS , RADIUS ) ;
		setcolor ( main_balls[2] ) ;
		setfillstyle ( SOLID_FILL , main_balls[2] );
		fillellipse ( 225 , 580 , RADIUS , RADIUS ) ;
		//shift down
		if ( time ( 0 ) - t >= 7 || uncorrect_shoot == 2 )
		{
			t = time ( 0 ) ;
			descend () ;
			uncorrect_shoot = 0 ;
		}
		//registermousehandler ( WM_MOUSEMOVE , drow_pipe ) ;
		registermousehandler ( WM_LBUTTONDOWN , slant ) ;
		//restart
		if ( should_restart == 1 )
		{
			tscore = 0 ;
			reset () ;
			closegraph () ;
			goto restart_game ;
		}
		//quit
		if ( should_quit == 1  )
		{
			move_ball = 0 ;
			quit = 1 ;
			break ;
		}
		//movement
		if ( move_ball == 1 ) 
		{
			t = time ( 0 ) ;
			moving () ;
		}
		//delete
		if ( start_delete == 1 )
		{
			t = time ( 0 ) ;
			remove_balls () ;
		}
		if ( check_balls == 1 )
		{
			t = time ( 0 ) ;
			suspense_balls () ;
		}
		setvisualpage ( p ) ;
		p = p==2? 1: 2;
    }
	return 0 ;
}

void drowMat () 
{
	int i , j , m , n = 0 , b , r , ball , temp , select , tempb , tColor , fl = 0 , k = 0 ;
	int columnCount , column , circ = 0 , ehtemal[25] , Rehtemal , black_exist = 0 , tempk = 0 ;
	int countR , countG ,countM ,countY ,countB , h ;
	setbkcolor ( BLACK ) ;
    cleardevice () ;
	//drow matrix
	for ( i = 0 ; i < 15 ; ++ i )
	{
		r = i % 2 ;
		if ( r == 0 )
		{
			for ( j = 0 ; j < 15 ; j ++ )
			{
				matBall[i][j].x = 40 * j + 20 ;
				matBall[i][j].y = 40 * i + 20 ;
				matBall[i][j].color = BLACK ;
				matBall[i][j].visit = 0 ;
			}
		}
		if ( r != 0 )
		{
			for ( j = 0 ; j < 15 ; j ++ )
			{
				matBall[i][j].x = 40 * j + 40 ;
				matBall[i][j].y = 40 * i + 20 ;
				matBall[i][j].color = BLACK ;
				matBall[i][j].visit = 0 ;
			}
		}
	}
	srand ( time ( NULL ) ) ;
	//color of first 3 row
	for ( i = 0 ; i < 3 ; i ++ )
	{
		for ( j = 0 ; j < 5 ; j ++ )
			tempArColor[j] = arColor[j] ;
		tColor = 5 ;
		do
		{
			fl = 0 ;
			black_exist = 0 ;
			for ( j = 0 ; j < 15 ; j ++ )
			{
				if ( matBall[i][j].color == BLACK )
					black_exist = 1 ;
			}
			if ( black_exist == 1 )
			{
				if ( tempArColor[0] != BLACK )
				{
					again :
					b = rand () % 5 ;
					if ( tempArColor[b] == BLACK )
						goto again ;
					ball = rand () % 5 ;
					for ( temp = 0 ; temp < ball ; temp ++ )
					{
						select = rand () %15 ;
						if ( matBall[i][select].color != BLACK )
						{
							temp -- ;
							continue ;
						}
						matBall[i][select].color = tempArColor[b] ;
					}
					for ( b ; b < tColor ; b ++ )
						tempArColor[b] = tempArColor[b + 1] ;
					tempArColor[b-1] = BLACK ;
					tColor -- ;
				}
				else 
				{
					countR = 0 , countG = 0 ,countM = 0 ,countY = 0 ,countB = 0 ;
					for ( j = 0 ; j < 5 ; j ++ )
					{
						numcolor[j] = 5 ;
						tempArColor[j] = arColor[j] ;
					}
					for ( j = 0 ; j < 15 ; j ++ )
					{
						if ( matBall[i][j].color == LIGHTRED )
						{
							countR ++ ;
							numcolor[0] = 5 - countR ;
						}
						if ( matBall[i][j].color == YELLOW )
						{
							countY ++ ;
							numcolor[1] = 5 - countY ;
						}
						if ( matBall[i][j].color == LIGHTGREEN )
						{
							countG ++ ;
							numcolor[2] = 5 - countG ;
						}
						if ( matBall[i][j].color == MAGENTA )
						{
							countM ++ ;
							numcolor[3] = 5 - countM ;
						}
						if ( matBall[i][j].color == LIGHTBLUE )
						{
							countB ++ ;
							numcolor[4] = 5 - countB ;
						}
					}
					for ( j = 0 ; j < 5 ; j ++ )
					{
						tempk = k + numcolor[j] ;
						for ( k ; k < tempk ; k ++ )
							ehtemal[k] = arColor[j] ;
					}
					for ( j = 0 ; j < 15 ; j ++ )
					{
						if ( matBall[i][j].color == BLACK  && k != 0)
						{
							Rehtemal = rand () %k ;
							matBall[i][j].color = ehtemal[Rehtemal] ;
							for ( Rehtemal ; Rehtemal < 25 ; Rehtemal ++ )
								ehtemal[Rehtemal] = ehtemal[Rehtemal+1] ;
							k -- ;
						}
					}
					h = 0 , k = 0 ;
				}
			}
			for ( j = 0 ; j < 15 ; j ++ )
			{
				if ( matBall[i][j].color == BLACK )
					fl = 1 ;
			}
		}while ( fl == 1 ) ;
	}
	//color of second 3 row
	columnCount = rand () %15 ;
	for ( i = 3 ; i < columnCount ; i ++ )
	{
		m = 3 ;
		column = rand () %15 ;
		circ = rand () %4 ;
		for ( j = 0 ; j < circ ; j ++ )
		{
			b = rand () %5 ;
			matBall[m][column].color = arColor[b] ;
			m ++ ;
		}
	}
	//color of 3 main ball
	b = rand () %5 ;
	main_balls[0] = arColor[b] ;
	b = rand () %5 ;
	main_balls[1] = arColor[b] ;
	b = rand () %5 ;
	main_balls[2] = arColor[b] ;
}

void reset () 
{
	move_ball = 0 ;
	ti = 0 ;
	tj = 0 ;
	Lstrike = 0 ;
	Rstrike= 0 ;
	should_restart = 0 ;
	start_delete = 0 ;
	v = 0 ;
}

void winning () 
{
	int i , full = 0 ;
	for ( i = 0 ; i < 15 ; i ++ )
	{
		if ( matBall[0][i].color != BLACK )
			full ++ ;
	}
	if ( full == 0 )
	{
		outtextxy ( 200 , 100 , "Win" ) ;
		outtextxy ( 200 , 200 , "High Score :" ) ;
		outtextxy ( 200 , 300 , score ) ;
	}
}