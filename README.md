# minitalk
Server - Client mini chat written on C, using only 2 signals (SIGUSR1 and SIGUSR2) to send a message.

#Usage:
  
make

$ ./server
PID: <PID_SERVER>

(wait)

$ ./client <PID_SERVER> <STRING_TO_SEND>

