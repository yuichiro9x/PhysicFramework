#ifndef __DEFINE_H__
#define __DEFINE_H__

#define padding				20
#define SCREEN_W			1080
#define SCREEN_H			720
#define SCREEN_CENTER_W		(SCREEN_W/2)
#define SCREEN_CENTER_H		(SCREEN_H/2)
#define LIMIT_FPS			60

	// define variable
#define MAX_LENGTH			255

	// Macro
#define PI					3.14159265f
#define HALFPI				(PI/2.0f)
#define SAFE_DEL(x)			{if(x){delete x; x = NULL;}}
#define SAFE_DEL_ARRAY(x)	{if(x){delete[] x; x = NULL;}}
#define X2GAME(x)			((1.0f*x - SCREEN_CENTER_W)/SCREEN_CENTER_W)
#define Y2GAME(y)			(-1.0f*(1.0f*y - SCREEN_CENTER_H)/SCREEN_CENTER_H)


#endif