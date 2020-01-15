#include "board.h"
#include "cell.h"
#include "block.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]){
    bool textOnly = false;
    int startLevel =0;
    int seed = 1;
    string scriptFile = "sequence.txt";
    for(int i=1;i<argc;i++){
        string arg = argv[i];
        if(arg=="-text"){
            textOnly = true;
        }
        if(arg=="-startlevel"){
            if (i+1<argc){
                startLevel = stoi(argv[i+1]);
                if(startLevel<0 || startLevel>4){
                    startLevel = 0;
                }
            }
        }
        if(arg=="-seed"){
            if (i+1<argc){
                seed = stoi(argv[i+1]);
                srand(seed);
            }
        }
        if(arg=="-scriptfile"){
            if(i+1<argc){
                scriptFile = argv[i+1];
            }
        }
    }
    Game playGame(startLevel, scriptFile, textOnly,seed);
    playGame.play();
    return 0;
}
