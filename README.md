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

2) 2013-05-11
usage define:
	flowc --in {ether_name|self_gen} --filter filters --dest {dest_list} 

3) 2013-05-14
	usage updated: flowc --in {ether_name|self_construct} --filter filters --dest {dest_list} --send-limit {sender_num,wait interval} --write {file_name,file_type,split_interval}
examples:
	1. flowc --in eth0 --filter tcp dst port 80 --dest 00AABB050401 00AABB050402 --send-limit 1,0
		capture packets on device eth0, select those tcp packets with dest port 80,
send them to these machines of device address 00AABB050401 and 00AABB050402 with none wait by only one sender.
	2. flowc --in eth0 --filter tcp dst port 80 --dest 10.0.2.112_tcp_5555 10.0.2.114_udp_8888 --send-limit 1,0
		the difference between example 1 is that the dest appears as tuple (ip,ttype,port) list.
	3. flowc --in eth0 --filter tcp dst port 80 --dest 00AABB050401 10.0.2.112_tcp_5555
		as you can see, this example is the combination of example 1 and 2.
	4. flowc --in eth0 --filter tcp dst port 80 --write test,pcap,0
		store packets to file test_[year_mon_mday_hour_min].pcap and do not split the file into small files diffed by time interval. if the interval is not 0, like 5, then the file will be split to test_20130514_1543.pcap and test_20130514_1548.pcap and so on, until you stop it.

program modules arrangement:
	[preprocessor and pre-init] ----> [packet construct or capture] --> [sender]
			|								|								|
			|								|-----> [logger] <--------------|
			|											^
			|---[local store]---------------------------|

a question to be discussed:
	how to determine and control the send rate of this program when it's used for performance test of some other server?

4) 2013-05-15
program modules arrangement updated:
	[packet capture]---->[packet queue]------------\
	  |						      /	                -->[scheduler {amplifier}]-------->[packet queue]---->[packet sender0]
	  \      [packet generator]---                    	 /  \                 \-------->[packet queue]---->[packet sender1]
	   \	       \									/	 \------->[packet queue]---->[storage]			   /
		\			\								   /								    /				  /
		 ----------------------->[logger] <-------------------------------------------------------------------

