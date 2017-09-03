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
extern struct ball matBall[15][15] , *same_color[20] ;
extern int counter , start_delete , check_balls , click ;
int v = 0 , summation = 0 ;

void my_score () ;
void reset () ;
void suspense_balls () ;

int find_same_color ( int h , int k )
{
	int i , j , same = 0 ;
	same_color[v++] = & matBall[h][k] ;
	matBall[h][k].visit = 1 ;
	if ( matBall[h][0].x == 40 && h != 0 ) 
	{
		if ( matBall[h-1][k].color == matBall[h][k].color && matBall[h-1][k].visit == 0 )
		{
			matBall[h-1][k].visit = 1 ;
			same_color[v++] = & matBall[h-1][k] ;
			same ++ ;
		}
		if ( k != 14 )
		{
			if ( matBall[h-1][k+1].color == matBall[h][k].color && matBall[h-1][k+1].visit == 0 )
			{
				matBall[h-1][k+1].visit = 1 ;
				same_color[v++] = & matBall[h-1][k+1] ;
				same ++ ;
			}
		}
		if ( k != 0 )
		{
			if ( matBall[h][k-1].color == matBall[h][k].color && matBall[h][k-1].visit == 0 )
			{
				matBall[h][k-1].visit = 1 ;
				same_color[v++] = & matBall[h][k-1] ;
				same ++ ;
			}
		}
		if ( k != 14 )
		{
			if ( matBall[h][k+1].color == matBall[h][k].color && matBall[h][k+1].visit == 0 )
			{
				matBall[h][k+1].visit = 1 ;
				same_color[v++] = & matBall[h][k+1] ;
				same ++ ;
			}
		}
		if ( matBall[h+1][k].color == matBall[h][k].color && matBall[h+1][k].visit == 0 )
		{
			matBall[h+1][k].visit = 1 ;
			same_color[v++] = & matBall[h+1][k] ;
			same ++ ;
		}
		if ( k != 14 )
		{
			if ( matBall[h+1][k+1].color == matBall[h][k].color && matBall[h+1][k+1].visit == 0 )
			{
				matBall[h+1][k+1].visit = 1 ;
				same_color[v++] = & matBall[h+1][k+1] ;
				same ++ ;
			}
		}
	}
	if ( matBall[h][0].x == 20 && h != 0 ) 
	{
		if ( k != 0 )
		{
			if ( matBall[h-1][k-1].color == matBall[h][k].color && matBall[h-1][k-1].visit == 0 )
			{
				matBall[h-1][k-1].visit = 1 ;
				same_color[v++] = & matBall[h-1][k-1] ;
				same ++ ;
			}
		}
		if ( matBall[h-1][k].color == matBall[h][k].color && matBall[h-1][k].visit == 0 )
		{
			matBall[h-1][k].visit = 1 ;
			same_color[v++] = & matBall[h-1][k] ;
			same ++ ;
		}
		if ( k != 0 )
		{
			if ( matBall[h][k-1].color == matBall[h][k].color && matBall[h][k-1].visit == 0 )
			{
				matBall[h][k-1].visit = 1 ;
				same_color[v++] = & matBall[h][k-1] ;
				same ++ ;
			}
		}
		if ( k != 14 )
		{
			if ( matBall[h][k+1].color == matBall[h][k].color && matBall[h][k+1].visit == 0 )
			{
				matBall[h][k+1].visit = 1 ;
				same_color[v++] = & matBall[h][k+1] ;
				same ++ ;
			}
		}
		if ( k != 0 )
		{
			if ( matBall[h+1][k-1].color == matBall[h][k].color && matBall[h+1][k-1].visit == 0 )
			{
				matBall[h+1][k-1].visit = 1 ;
				same_color[v++] = & matBall[h+1][k-1] ;
				same ++ ;
			}
		}
		if ( matBall[h+1][k].color == matBall[h][k].color && matBall[h+1][k].visit == 0 )
		{
			matBall[h+1][k].visit = 1 ;
			same_color[v++] = & matBall[h+1][k] ;
			same ++ ;
		}
	}
	if ( matBall[0][0].x == 20 )
	{
		if ( k != 0 )
		{
			if ( matBall[h][k-1].color == matBall[h][k].color && matBall[h][k-1].visit == 0 )
			{
				matBall[h][k-1].visit = 1 ;
				same_color[v++] = & matBall[h][k-1] ;
				same ++ ;
			}
		}
		if ( k != 14 )
		{
			if ( matBall[h][k+1].color == matBall[h][k].color && matBall[h][k+1].visit == 0 )
			{
				matBall[h][k+1].visit = 1 ;
				same_color[v++] = & matBall[h][k+1] ;
				same ++ ;
			}
		}
		if ( k != 0 )
		{
			if ( matBall[h+1][k-1].color == matBall[h][k].color && matBall[h+1][k-1].visit == 0 )
			{
				matBall[h+1][k-1].visit = 1 ;
				same_color[v++] = & matBall[h+1][k-1] ;
				same ++ ;
			}
		}
		if ( matBall[h+1][k].color == matBall[h][k].color && matBall[h+1][k].visit == 0 )
		{
			matBall[h+1][k].visit = 1 ;
			same_color[v++] = & matBall[h+1][k] ;
			same ++ ;
		}
	}
	if ( matBall[0][0].x == 40 )
	{
		if ( k != 0 )
		{
			if ( matBall[h][k-1].color == matBall[h][k].color && matBall[h][k-1].visit == 0 )
			{
				matBall[h][k-1].visit = 1 ;
				same_color[v++] = & matBall[h][k-1] ;
				same ++ ;
			}
		}
		if ( k != 14 )
		{
			if ( matBall[h][k+1].color == matBall[h][k].color && matBall[h][k+1].visit == 0 )
			{
				matBall[h][k+1].visit = 1 ;
				same_color[v++] = & matBall[h][k+1] ;
				same ++ ;
			}
		}
		if ( matBall[h+1][k].color == matBall[h][k].color && matBall[h+1][k].visit == 0 )
		{
			matBall[h+1][k].visit = 1 ;
			same_color[v++] = & matBall[h+1][k] ;
			same ++ ;
		}
		if ( k != 14 )
		{
			if ( matBall[h+1][k+1].color == matBall[h][k].color && matBall[h+1][k+1].visit == 0 )
			{
				matBall[h+1][k+1].visit = 1 ;
				same_color[v++] = & matBall[h+1][k+1] ;
				same ++ ;
			}
		}
	}
	if ( same == 1 )
	{
		i = (*same_color[same]).y / 40 ;
		if ( matBall[i][0].x == 40 )
			j = (*same_color[same]).x / 40 - 1 ;
		else
			j = (*same_color[same]).x / 40 ;
		if ( matBall[i][0].x == 40 && i != 0 ) 
		{
			if ( matBall[i-1][j].color == matBall[i][j].color && matBall[i-1][j].visit == 0 )
			{
				matBall[i-1][j].visit = 1 ;
				same_color[v++] = & matBall[i-1][j] ;
				same ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i-1][j+1].color == matBall[i][j].color && matBall[i-1][j+1].visit == 0 )
				{
					matBall[i-1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i-1][j+1] ;
					same ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					same ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					same ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				same ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i+1][j+1].color == matBall[i][j].color && matBall[i+1][j+1].visit == 0 )
				{
					matBall[i+1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j+1] ;
					same ++ ;
				}
			}
		}
		if ( matBall[i][0].x == 20 && i != 0 ) 
		{
			if ( j != 0 )
			{
				if ( matBall[i-1][j-1].color == matBall[i][j].color && matBall[i-1][j-1].visit == 0 )
				{
					matBall[i-1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i-1][j-1] ;
					same ++ ;
				}
			}
			if ( matBall[i-1][j].color == matBall[i][j].color && matBall[i-1][j].visit == 0 )
			{
				matBall[i-1][j].visit = 1 ;
				same_color[v++] = & matBall[i-1][j] ;
				same ++ ;
			}
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					same ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					same ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i+1][j-1].color == matBall[i][j].color && matBall[i+1][j-1].visit == 0 )
				{
					matBall[i+1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j-1] ;
					same ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				same ++ ;
			}
		}
		if ( matBall[0][0].x == 20 )
		{
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					same ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					same ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i+1][j-1].color == matBall[i][j].color && matBall[i+1][j-1].visit == 0 )
				{
					matBall[i+1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j-1] ;
					same ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				same ++ ;
			}
		}
		if ( matBall[0][0].x == 40 )
		{
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					same ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					same ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				same ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i+1][j+1].color == matBall[i][j].color && matBall[i+1][j+1].visit == 0 )
				{
					matBall[i+1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j+1] ;
					same ++ ;
				}
			}
		}
	}
	if ( same == 0 )
		(*same_color[0]).visit = 0 ;
	if ( same == 1 )
	{
		(*same_color[0]).visit = 0 ;
		(*same_color[1]).visit = 0 ;
	}
	return same ;
}

void remove_balls () 
{
	int i , j ;
	click = 0 ;
	i = (*same_color[0]).y / 40 ;
	if ( matBall[i][0].x == 40 )
		j = (*same_color[0]).x / 40 - 1 ;
	else
		j = (*same_color[0]).x / 40 ;
	if ( counter != 0 )
	{
		if ( matBall[i][0].x == 40 && i != 0 ) 
		{
			if ( matBall[i-1][j].color == matBall[i][j].color && matBall[i-1][j].visit == 0 )
			{
				matBall[i-1][j].visit = 1 ;
				same_color[v++] = & matBall[i-1][j] ;
				counter ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i-1][j+1].color == matBall[i][j].color && matBall[i-1][j+1].visit == 0 )
				{
					matBall[i-1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i-1][j+1] ;
					counter ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					counter ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					counter ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				counter ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i+1][j+1].color == matBall[i][j].color && matBall[i+1][j+1].visit == 0 )
				{
					matBall[i+1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j+1] ;
					counter ++ ;
				}
			}
		}
		if ( matBall[i][0].x == 20 && i != 0 ) 
		{
			if ( j != 0 )
			{
				if ( matBall[i-1][j-1].color == matBall[i][j].color && matBall[i-1][j-1].visit == 0 )
				{
					matBall[i-1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i-1][j-1] ;
					counter ++ ;
				}
			}
			if ( matBall[i-1][j].color == matBall[i][j].color && matBall[i-1][j].visit == 0 )
			{
				matBall[i-1][j].visit = 1 ;
				same_color[v++] = & matBall[i-1][j] ;
				counter ++ ;
			}
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					counter ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					counter ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i+1][j-1].color == matBall[i][j].color && matBall[i+1][j-1].visit == 0 )
				{
					matBall[i+1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j-1] ;
					counter ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				counter ++ ;
			}
		}
		if ( matBall[0][0].x == 20 )
		{
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					counter ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					counter ++ ;
				}
			}
			if ( j != 0 )
			{
				if ( matBall[i+1][j-1].color == matBall[i][j].color && matBall[i+1][j-1].visit == 0 )
				{
					matBall[i+1][j-1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j-1] ;
					counter ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				counter ++ ;
			}
		}
		if ( matBall[0][0].x == 40 )
		{
			if ( j != 0 )
			{
				if ( matBall[i][j-1].color == matBall[i][j].color && matBall[i][j-1].visit == 0 )
				{
					matBall[i][j-1].visit = 1 ;
					same_color[v++] = & matBall[i][j-1] ;
					counter ++ ;
				}
			}
			if ( j != 14 )
			{
				if ( matBall[i][j+1].color == matBall[i][j].color && matBall[i][j+1].visit == 0 )
				{
					matBall[i][j+1].visit = 1 ;
					same_color[v++] = & matBall[i][j+1] ;
					counter ++ ;
				}
			}
			if ( matBall[i+1][j].color == matBall[i][j].color && matBall[i+1][j].visit == 0 )
			{
				matBall[i+1][j].visit = 1 ;
				same_color[v++] = & matBall[i+1][j] ;
				counter ++ ;
			}
			if ( j != 14 )
			{
				if ( matBall[i+1][j+1].color == matBall[i][j].color && matBall[i+1][j+1].visit == 0 )
				{
					matBall[i+1][j+1].visit = 1 ;
					same_color[v++] = & matBall[i+1][j+1] ;
					counter ++ ;
				}
			}
		}
		matBall[i][j].color = BLACK ;
		matBall[i][j].visit = 0 ;
		setcolor ( matBall[i][j].color ) ;
		setfillstyle ( SOLID_FILL , matBall[i][j].color ) ;
		fillellipse ( matBall[i][j].x , matBall[i][j].y , RADIUS , RADIUS ) ;
		Sleep ( 500 ) ;
		summation = 1 ;
		my_score () ;
		counter -- ;
		v -- ;
		for ( i = 0 ; i < 20 ; i ++ )
			same_color[i] = same_color[i+1] ;
	}
	if ( counter == 0 )
	{
		check_balls = 1 ;
		reset () ;
	}
}

void suspense_balls () 
{
	int i , j ;
	for ( i = 1 ; i < 15 ; i ++ )
	{
		for ( j = 0 ; j < 15 ; j ++ )
		{
			if ( i % 2 )
			{
				if ( matBall[i][j].color != BLACK && matBall[i-1][j].color == BLACK && matBall[i-1][j+1].color == BLACK )
				{
					matBall[i][j].color = BLACK ;
					summation = 1 ;
					my_score () ;
				}
			}
			else
			{
				if ( matBall[i][j].color != BLACK && matBall[i-1][j-1].color == BLACK && matBall[i-1][j].color == BLACK )
				{
					matBall[i][j].color = BLACK ;
					summation = 1 ;
					my_score () ;
				}
			}
		}
	}
}