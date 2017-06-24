#ifndef __STD_TYPE_H__
#define __STD_TYPE_H__
#include <stdio.h>

typedef unsigned int  	u32_t;
typedef signed int 		s32_t;
typedef unsigned short  u16_t;
typedef signed short	s16_t;
typedef unsigned char  	u8_t;
typedef signed char 	s8_t;
typedef char 			str_t;
typedef signed int 		bool_t;

#define LOG_E(msg,...) fprintf(stderr,"%s:[E] " msg "\n", __FUNCTION__,##__VA_ARGS__)
#define LOG_W(msg,...) fprintf(stderr,"%s:[W] " msg "\n", __FUNCTION__,##__VA_ARGS__)

#if LOG_LEVEL >= 1
#define LOG_D(msg,...) fprintf(stderr,"%s:[D] " msg "\n", __FUNCTION__,##__VA_ARGS__)
#else
#define LOG_D(msg,...) 
#endif

#if LOG_LEVEL >= 2
#define LOG_V(msg,...) fprintf(stderr,"%s:[V] " msg "\n", __FUNCTION__,##__VA_ARGS__)
#else
#define LOG_V(msg,...) 
#endif

#define LOG_I(msg,...) fprintf(stdout, msg "\n",##__VA_ARGS__)

#define TRUE  1
#define FALSE 0


#endif

