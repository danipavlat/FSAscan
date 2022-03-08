Dani Pavlat     CMP SCI 4280
P1: Scanner

This program uses an FSA table (defined in token.h) to scan the input 
for legitimate tokens in the course's given programming language, 
returning one valid token (or throwing an error) each time it is called.

## Build
	make

## Usage
	scanner						reads from the keyboard until simulated EOF (CTRL + D)
	scanner < somefile		same as above but redirecting from somefile instead of keyboard
	scanner somefile		reads from somefile.sp2020

## Issues
