.SUFFIXES:  .cpp .o
CC      = g++
OBJS    = card.o deck.o game.o genericplayer.o hand.o house.o player.o
CFLAGS  = -Wall

all:		blackjack
blackjack:	$(OBJS) blackjack.o
			$(CC) $(OBJS) blackjack.o -o blackjack

%.o:		%.cpp %.h
			$(CC) $(CFLAGS) -c $<

