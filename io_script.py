#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  io_script.py
#  
#  Copyright 2018 Priscila Gutierres <priscila.gutierres@gmail.com>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
# 

import numpy as np
import math

def write_file(fname, xx, yy, zz):
	wfile =  open(fname,"w")
	n = str(len(xx))
	print(str(n))
	wfile.write(n)
	
	wfile.write("\n")
	
	for i in range(0,len(xx)):
		string = str(xx[i])+" "+str(yy[i])+" "+str(zz[i])+"\n"
		wfile.write(string)
	wfile.close()
	
	
def read_file(fname):
	fp = open(fname,"r")
	tam = int(math.sqrt(int(fp.readline())))
	DATA = np.genfromtxt(fp,dtype='float')
	X = DATA[:,0]
	Y = DATA[:,1]
	Z = DATA[:,2]
	fp.close()
	
	return X,Y,Z
	
def read_file_olse(fname):
	fp = open(fname,"r")
	NSIZE = int(fp.readline())
	poly = []
	for i in range(NSIZE):
		poly.append(float(fp.readline()))
	fp.close()	
	x = poly[:int(((NSIZE-1)/2)+1)]
	y = poly[int((NSIZE-1)/2+1):]
	y.insert(0,0.0)
	return x,y,int((NSIZE-1)/2)
