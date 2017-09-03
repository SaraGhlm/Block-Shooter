//#include <iostream>
//#include "graphics.h"
//#include <math.h>
//#include <stdlib.h>                     
//#include <ctype.h>                      
//#include <time.h>
//#include <Windows.h>
//
//using namespace std;
//
//void drow_pipe ( int x , int y )
//{
//	int i , j , r = 1 , tempx , tempy , rx , ry , diffx , diffy , getout = 0 ;
//	float slant_x , slant_y , x2 = 305 , y2 = 580 ;
//	diffx = x - 305 ;
//	tempx = abs ( diffx ) ;
//	diffy = y - 580 ;
//	tempy = abs ( diffy ) ;
//	for ( i = 2 ; i <= abs (diffx ) || i <= ( diffy ) ; ++ i ) 
//	{
//		for ( j = 2 ; j < i ; ++ j )
//		{
//			r = i % j ;
//			if ( r == 0 )
//			break ;
//		}
//		if ( r == 0 )
//			continue ;
//		else
//		{
//			while ( tempx != 0 && tempy != 0 && getout == 0 ) 
//			{
//				rx = tempx % i ;
//				ry = tempy % i ;
//				if ( rx == 0 && ry == 0 )
//				{
//					tempx = tempx / i ;
//					tempy = tempy / i ;
//				}
//				else
//					getout = 1  ;
//			}
//			getout = 0 ;
//		}
//	}
//	slant_x = tempx ;
//	slant_y = tempy ;
//	while ( slant_y > 10 || slant_x > 10 )
//	{
//		slant_x = slant_x / 10 ;
//		slant_y = slant_y / 10 ;
//	}
//	if ( x >= 305 )
//	{
//		while ( pow ( x2 - 305 , 2 ) + pow ( y2 - 580 , 2 ) <= 5000 )
//		{
//			x2 += slant_x ;
//			y2 -= slant_y ;
//		}
//	}
//	else
//	{
//		while ( pow ( x2 - 305 , 2 ) + pow ( y2 - 580 , 2 ) <= 5000 )
//		{
//			x2 -= slant_x ;
//			y2 -= slant_y ;
//		}
//	}
//	setlinestyle ( DASHED_LINE , 0 , 3 ) ;
//	setcolor ( WHITE ) ;
//	line ( 305 , 580 , x2 , y2 ) ;
//	setlinestyle ( SOLID_LINE , 0 , 1 ) ;
//}