/*
 * alglin.h
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
#ifndef ALGLIN_H
#define ALGLIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "iomisc.h"
#define Tol 0.000001

int LUPDecompose(double **A, int N, int *P);
double *LUPSolve(double **A, int *P, double *b, int N);
double **matrix_mult(double **A, double **B, int m, int n, int y);
double **transpose(double **A,int m, int n);
double **basis(double *x, double *y, int N, int M);
double *olse(double *x, double *y, double *z, int N, int M);

#endif
