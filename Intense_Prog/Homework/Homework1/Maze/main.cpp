#include <iostream>
#include "Maze.h"
#include <vector>

int main(){
  /*
 Board b;
 Player p1("Ben",true);
 b.SetSquareValue(p1.get_position(), SquareType::Human);
 b.printBoard();
 std::cout<<p1.get_name()<<std::endl;
 std::cout<<p1.is_human()<<std::endl;
 std::cout<<p1.get_position().row<<std::endl;
 std::cout<<p1.get_position().col<<std::endl;

if(b.get_square_value(p1.get_position()) == SquareType::Human){
   std::cout<<"WIN"<<std::endl;
}

std::cout<<SquareTypeStringify(SquareType::Wall)<<std::endl;
b.GetMoves(&p1);

Position testerP;
testerP.row = 0;
testerP.col = 0;
std::cout<<b.MovePlayer(&p1,testerP)<<std::endl;
p1.SetPosition(testerP);
b.printBoard();

Position testerP2;
testerP2.row = 1;
testerP2.col = 0;
std::cout<<b.MovePlayer(&p1,testerP2)<<std::endl;
p1.SetPosition(testerP2);
b.printBoard();

Position testerP3;
testerP3.row = 1;
testerP3.col = 1;
std::cout<<b.MovePlayer(&p1,testerP3)<<std::endl;
p1.SetPosition(testerP3);
b.printBoard();
*/

Maze game;
Player guy("Ben",true);
std::cout<<"NEW GAME HERE"<<std::endl;
game.NewGame(&guy,2);





}
