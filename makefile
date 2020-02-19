#
# PROGRAM:    assignment6.cc
# PROGRAMMER: Margaret Higginbotham
# LOGON ID:   Z1793581
# DATE DUE:   March 22, 2018
#

# Complier Variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6.exe: assignment6main.cc
	g++ $(CCFLAGS) assignment5.cc assignment6.cc assignment6main.cc -o assignment6.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm assignment6.exe
