import sys
for b in sys.argv[1:]:
 e=''
 for i in zip(list(map(chr,range(65,91)))+list(map(chr,range(30,39))),'01 1000 1010 100 0 0010 110 0000 00 0111 101 0100 11 10 111 0110 1101 010 000 1 001 0001 011 1001 1011 1100 11111 01111 00111 00011 00001 00000 10000 11000 11100 11110'.split()):
  print(b)