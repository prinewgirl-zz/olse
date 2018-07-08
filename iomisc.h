/*
 * iomisc.h
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
#ifndef IOMISC_H
#define IOMISC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double **creat_matrix(int k, int w);
void show_matrix(double **A, int k, int w);
void show_vector(double *b,int n);
double *multiply(double *x,int a,int n);
#endif
