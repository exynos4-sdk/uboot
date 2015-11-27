/*
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *              http://www.samsung.com/
 *   
 * 20120315:  yang81.li@samsung.com for add trustzone image
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void do_add_padding(char* file, int size)
{
    FILE *fp_src_file = NULL;
    char *fn_src_file = file;


    unsigned char *src = NULL;
    int fs = 0;

    fp_src_file = fopen(fn_src_file, "ab+");
    if (NULL == fp_src_file)
    {
        printf("can't open uboot file for read(%s)\n", fn_src_file);
        return;
    }
    
    fseek(fp_src_file, 0L, SEEK_END);
    fs = ftell(fp_src_file);
    printf("before padding %s size= %dByte\n", fn_src_file, fs);

   if (fs > size){
		printf("error: too large %s !!!\n", fn_src_file);
		return ;
   }
   src = (unsigned char *)calloc((size_t)(size - fs), 1);
	
   memset(src,0,(size_t)(size - fs));

   if (!src){
	    printf("memory alloc failed !!!\n");
		return ;
   }
		
    fs = fwrite(src, 1, (size_t)(size - fs), fp_src_file);

    printf("%d Byte written \n", fs);
	
    free(src);
	
    fclose(fp_src_file);
}


int main(int argc, char *argv[])
{
	int	size;
	if (argc != 3)
	{
		printf("Usage: padding <source file> <size> \n");
		return -1;
	}
	size = atoi(argv[2]);
    do_add_padding(argv[1], size);
	return 0;
}