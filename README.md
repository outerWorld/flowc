flowc
=====
It is a tool for multiple purposes, such as:
1) pressure test
2) function test
3) fetch and store useful packet on some machines

It can:
1) capture packet from network device, such as ethernet card
2) accept filter options, for fetching useful packet
3) modify source/destine ip in packet
4) generate packets by configuration
5) flow speed limit
6) send packet on network device
7) send packet on udp
8) send packet on tcp

It looks like a big or hard project and has similar features compared with
other tools, such as tcpcopy, however, i promise making it with some
difference and good operations.

As you can see that this project is c coded, and some tools with python or shell script
for convenience.

changes:
1) 2013-05-10, create project with such directory structure:
flowc
	--include
	--src
	--build.sh
	--Makefile
	--README.md
