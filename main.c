/*
 * main.c
 * 
 * Copyright 2018 Priscila Gutierres <priscila.gutierres@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "iomisc.h"
#include "alglin.h"
#define NSIZE(N) 2*N+1

int main(int argc, char **argv)
{
	
	FILE *fp;
	
	int M,N,i,j;
	double *x;
	double *y;
	double *z;
	double *ans;
	 
	char *buffer;
	char *token;
	const char sep[2] = " ";
	
	if (argc != 3) {
		fprintf(stderr,"Program argument missing \n");
		return -1;
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file \n");
		return -1;
	}
	
		
	N = atoi(argv[2]);

    
    size_t bufsize = 64;
    size_t characters;
	buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
		fprintf(stderr, "Unable to allocate buffer\n");
        return -1;
    }
    
   
    
    
    if (getline(&buffer,&bufsize,fp) != EOF){
		token = strtok(buffer, sep);	
		M = atoi(buffer); 
		
		x = malloc ((M) * sizeof (double));
		y = malloc ((M) * sizeof (double));
		z = malloc ((M) * sizeof (double));

	}
	
	j = 0;
	while(getline(&buffer,&bufsize,fp) != EOF)
		{
			
			x[j] = atof(strtok(buffer, sep));	
			y[j] = atof(strtok(NULL, sep));
			z[j] = atof(strtok(NULL, sep));  
			
			j++;
			

	}
	
	FILE *fptr = fopen("output.dat","w");
	fprintf(fptr,"%d \n",NSIZE(N));	
	
	ans = olse(x,y,z,N,M);
	show_vector(ans,NSIZE(N));
	
	for (i=0;i<NSIZE(N);i++) {
		fprintf(fptr,"%2.7f\n",ans[i]);
	}
		
	fclose(fp); 
	fclose(fptr); 
	free(ans);
	
return 0;
}
