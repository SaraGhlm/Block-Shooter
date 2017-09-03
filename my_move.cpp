#include <iostream>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                      
#include <time.h>
#include <Windows.h>

using namespace std;

const int RADIUS = 20 ;
extern float mx , my , ti , tj ;
extern int x1 , arColor[5] , main_ball_color , Rstrike , Lstrike , move_ball , start_delete , uncorrect_shoot , click ;
struct ball { int color , x , y , visit ; } ;
extern struct ball matBall[15][15] ;
float centerx , centery , temp ;
struct ball *same_color[20] ;
int minus = 0 , counter ;

int stop_ball () ;
void reset () ;
void my_score () ;
int find_same_color ( int , int ) ;
void remove_balls () ;

void moving ()
{
	int i , tempi , same ;
	float distance , min_distance = 40 ;
	if ( x1 >= 305 )
	{
		tj += my ;
		ti += mx ;
		if ( ti >= 300 && Lstrike == 0 && Rstrike == 0 )
		{
			temp = 305 + ti ;
			ti = mx ;
			Rstrike = 1 ;
			goto right_strike ;
		}
		centerx = 305 + ti ;
		centery = 580 - tj ;
	}
	if ( x1 < 305 && Rstrike == 0 && Lstrike == 0 )
	{
		tj += my ;
		ti += mx ;
		if ( ti >= 300 )
		{
			temp = ti - 285 ;
			ti = mx ;
			Lstrike = 1 ;
			goto left_strike ;
		}
		centerx = 305 - ti ;
		centery = 580 - tj ;
	}
right_strike:
	if ( Rstrike == 1 )
	{
		tj += my ;
		ti += mx ;
		if ( ti >= 600 )
		{
			temp = ti - 590 ;
			Rstrike = 0 ;
			Lstrike = 1 ;
			ti = mx ;
			goto left_strike ;
		}
		centerx = temp - ti ;
		centery = 580 - tj ;
	}
left_strike:
	if ( Lstrike == 1 )
	{
		tj += my ;
		ti += mx ;
		if ( ti >= 600 )
		{
			temp = ti ;
			Lstrike = 0 ;
			Rstrike = 1 ;
			ti = mx ;
			goto right_strike ;
		}
		centerx = temp + ti ;
		centery = 580 - tj ;
	}
	same = stop_ball () ;
	if ( same == -1 )
	{
		click = 1 ;
		if ( centery <= 20 )
		{
			for ( i = 0 ; i < 15 ; i ++ )
			{
				if ( matBall[0][i].color == BLACK )
				{
					distance = sqrt ( pow ( matBall[0][i].x - ( centerx ) , 2 ) + pow ( matBall[0][i].y - ( centery ) , 2 ) ) ;
					if ( distance <= min_distance )
					{
						min_distance = distance ;
						tempi = i ;
					}
				}
			}
			matBall[0][tempi].color = main_ball_color ;
			setcolor ( matBall[0][tempi].color ) ;
			setfillstyle ( SOLID_FILL , matBall[0][tempi].color ) ;
			fillellipse ( matBall[0][tempi].x , matBall[0][tempi].y , RADIUS , RADIUS ) ;
			move_ball = 0 ;
		}
		else
		{
			setcolor ( main_ball_color ) ;
			setfillstyle ( SOLID_FILL , main_ball_color ) ;
			fillellipse ( centerx , centery , RADIUS , RADIUS ) ;
			Sleep ( 20 ) ;
		}
	}
	if ( same == 1 || same == 0 )
	{
		click = 0 ;
		uncorrect_shoot ++ ;
		minus = 1 ;
		reset () ;
		my_score () ;
	}
	if ( same >= 2 )
	{
		click = 0 ;
		uncorrect_shoot = 0 ;
		counter = same + 1 ;
		start_delete = 1 ;
	}	
}

int stop_ball () 
{
	int i , j , h , k , tempk , temph , maxH , is_stoped = 0 , same = -1 , flag = 0 ;
	float d , distance , min_distance = 50 ;
	for ( i = 0 ; i < 15 && flag == 0 ; i ++ )
	{
		for ( j = 0 ; j < 15 && flag == 0 ; j ++ )
		{
			d = sqrt ( pow ( matBall[i][j].x - ( centerx ) , 2 ) + pow ( matBall[i][j].y - ( centery ) , 2 ) ) ;
			if ( d <= 40 && matBall[i][j].color != BLACK )
			{
				h = centery / 40 ;
				h -- ;
				maxH = h + 3 ;
				for ( h ; h < maxH ; h ++ )
				{
					flag = 1 ;
					for ( k = 0 ; k < 15 ; k ++ )
					{
						if ( matBall[h][k].color == BLACK )
						{
							distance = sqrt ( pow ( matBall[h][k].x - ( centerx ) , 2 ) + pow ( matBall[h][k].y - ( centery ) , 2 ) ) ;
							if ( distance <= min_distance )
							{
								is_stoped = 1 ;
								temph = h ;
								tempk = k ;
								min_distance = distance ;
							}
						}
					}
				}
				matBall[temph][tempk].color = main_ball_color ;
				setcolor ( matBall[temph][tempk].color ) ;
				setfillstyle ( SOLID_FILL , matBall[temph][tempk].color ) ;
				fillellipse ( matBall[temph][tempk].x , matBall[temph][tempk].y , RADIUS , RADIUS ) ;
				move_ball = 0 ;
			}
		}
	}
	if ( is_stoped == 1 ) 
		same = find_same_color ( temph , tempk ) ;
	return same ;
}