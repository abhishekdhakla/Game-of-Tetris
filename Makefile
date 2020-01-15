CXX = g++
CXXFLAGS = -std=c++14

quadris: game.o board.o quadris.o block.o Score.o window.o graphicsDisplay.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o
	${CXX} ${CXXFLAGS} game.o board.o quadris.o block.o Score.o window.o graphicsDisplay.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o -L/usr/X11R6/lib -lX11 -o quadris

block.o: block.cc block.h blockCell.h
	${CXX} ${CXXFLAGS} -c block.cc

iblock.o: iblock.cc iblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c iblock.cc

jblock.o: jblock.cc jblock.h board.h board.cc blockCell.h
	${CXX} ${CXXFLAGS} -c jblock.cc

lblock.o: lblock.cc lblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c lblock.cc

oblock.o: oblock.cc oblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c oblock.cc

sblock.o: sblock.cc sblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c sblock.cc

tblock.o: tblock.cc tblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c tblock.cc

zblock.o: zblock.cc zblock.h board.h board.cc
	${CXX} ${CXXFLAGS} -c zblock.cc

Score.o: Score.cc score.h
	${CXX} ${CXXFLAGS} -c Score.cc

window.o: window.cc window.h
	${CXX} ${CXXFLAGS} -c window.cc

quadris.o: board.h cell.h block.h game.h
	${CXX} ${CXXFLAGS} -c quadris.cc

graphicsDisplay.o: graphicsDisplay.cc graphicsDisplay.h
	${CXX} ${CXXFLAGS} -c graphicsDisplay.cc

board.o: board.cc board.h
	${CXX} ${CXXFLAGS} -c board.cc

game.o: game.cc game.h iblock.cc jblock.cc zblock.cc tblock.cc sblock.cc oblock.cc lblock.cc
	${CXX} ${CXXFLAGS} -c game.cc

clean:
	rm *.o *.gch
.PHONY: clean
