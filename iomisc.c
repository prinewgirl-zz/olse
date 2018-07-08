/*
 * iomisc.c
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
#include <math.h>
#include <stdlib.h>
#include "iomisc.h"

double **creat_matrix(int k, int w) {
	double **A;	
	int i,j;
	A = malloc(sizeof(double *) * k); 
	
	

	for (i = 0; i < k; i++) {
		A[i] = malloc(sizeof(double) * w);
	}
	for (i = 0; i < k; i++) {
		for (j = 0; j < w; j++)
			A[i][j] = 0;
		}
		return A;
	}


void show_matrix(double **A, int k, int w) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < w; j++)
            printf("%3.15f ", A[i][j]);
        printf("\n");
        
		}
    printf("------ \n");
	}


void show_vector(double *b,int n) {
	    for (int i = 0; i < n; i++) {
			printf("%2.15f \n",b[i]);

		}
printf("------ \n");

	}

double *multiply(double *x,int a,int n) {
int i;
double *temp = malloc ((n) * sizeof (double));
for(i=0;i<n;i++) {
	temp[i] =pow(x[i],a);
		}
	return temp;
	}
