#include <iostream>
#include <math.h>
#include <vector>
#include "Maze.h"

Board::Board(){
  rows_ = sizeof arr_ / sizeof arr_[0];
  cols_ = sizeof arr_[0] / sizeof(int);
  for(int i = 0; i < rows_; i++){
    for (int j = 0; j < cols_; j++) {
      arr_[i][j] = SquareType::Empty;
    }
  }
}

std::string SquareTypeStringify(SquareType sq){
  switch(sq)
  {
    case SquareType::Empty:
      return "Empty";

    case SquareType::Wall:
      return "Wall";

    case SquareType::Exit:
      return "Exit";

    case SquareType::Human:
      return "Human";

    case SquareType::Enemy:
      return "Enemy";

    case SquareType::Treasure:
      return "Treasure";
  }
  return "Empty";
}


void Board::printBoard(){
  for(int i = 0; i < rows_; i++){
    for(int j = 0; j < cols_; j++){
      switch(arr_[i][j])
        {
        case SquareType::Empty:
          std::cout<<"\U0001F7E8";
          break;

        case SquareType::Wall:
          std::cout<<"\U0001F6AB";
          break;

        case SquareType::Exit:
          std::cout<<"\U0001F7E9";
          break;

        case SquareType::Human:
          std::cout<<"\U0001F913";
          break;

        case SquareType::Enemy:
          std::cout<<"\U0001F47B";
          break;

        case SquareType::Treasure:
          std::cout<<"\U0001F352";
          break;


        }

      }
    std::cout<<std::endl;
  }
}

void Board::SetSquareValue(Position pos, SquareType value){
arr_[pos.row][pos.col] = value;
}

SquareType Board::get_square_value(Position pos)const{
  return arr_[pos.row][pos.col];
}


std::vector<Position> Board::GetMoves(Player *p){
  std::vector<Position> moves;
  Player p1 = *p;
  Position newStep = p1.get_position();
  std::string step;
  std::string w = "Wall";
  std::string e = "Enemy";

  if(newStep.row+1 != get_rows())
    {
      step = SquareTypeStringify(arr_[newStep.row+1][newStep.col]);
      if(step != w || step != e){
        std::cout<< "DOWN ";
        Position down;
        down.row=newStep.row+1;
        down.col=newStep.col;
        moves.push_back(down);
      }
    }

  if(newStep.row-1 != -1){
    step = SquareTypeStringify(arr_[newStep.row-1][newStep.col]);
    if(step != w || step != e){
      std::cout<< "UP ";
      Position up;
      up.row=newStep.row-1;
      up.col=newStep.col;
      moves.push_back(up);
    }
  }

  if(newStep.col+1 != get_cols()){
    step = SquareTypeStringify(arr_[newStep.row][newStep.col+1]);
    if(step != w || step != e){
      std::cout<< "RIGHT ";
      Position right;
      right.row=newStep.row;
      right.col=newStep.col+1;
      moves.push_back(right);
    }
  }

  if(newStep.col-1 != -1){
    step = SquareTypeStringify(arr_[newStep.row][newStep.col-1]);
    if(step != w || step != e){
      std::cout<< "LEFT ";
      Position left;
      left.row=newStep.row;
      left.col=newStep.col-1;
      moves.push_back(left);
    }
  }
  std::cout<<std::endl;

  return moves;
}

bool Board::MovePlayer(Player *p, Position pos){

  if(pos.row >= get_rows() || pos.row < 0 ||  pos.col >= get_cols() || pos.col < 0){
    return false;
  }

  Player p1 = *p;
  int diffRow = p1.get_position().row - pos.row;
  int diffCol = p1.get_position().col - pos.col;
  if((abs(diffRow) == 1 && diffCol == 0) || (diffRow == 0 && abs(diffCol) == 1)){
    arr_[p1.get_position().row][p1.get_position().col] = SquareType::Empty;
    arr_[pos.row][pos.col] = SquareType::Human;
    p1.SetPosition(pos);
    return true;
  }



  return false;
}

Maze::Maze(){
  board_ = new Board();
  std::vector<Player *> players_;
  turn_count_ = 0;
}

void Maze::NewGame(Player *human, const int enemies){
  Player newP = *human;
  players_.push_back(&newP);
  Position goal;
  Position n;
  Position w1;
  Position w2;

  int rRow = (rand() % board_->get_rows());
  int rCol = (rand() % board_->get_cols());

  goal.row = board_->get_rows()-1;
  goal.col = board_->get_cols()-1;
  board_->SetSquareValue(goal,SquareType::Exit);

  w1.row = rRow;
  w1.col = rCol;
  w2.row = rRow;
  w2.col = rCol +1;

board_->SetSquareValue(w1,SquareType::Wall);
board_->SetSquareValue(w2,SquareType::Wall);



    int i = 0;
    while(i<enemies){
    rRow = (rand() % board_->get_rows());
    rCol = (rand() % board_->get_cols());
    n.row = rRow;
    n.col = rCol;
    std::cout<<"RANDOM ROW" << rRow <<std::endl;
    if(board_->get_square_value(n) == SquareType::Empty){
      for(int j = 0; j <enemies; j++){
        Player *tmp = new Player("Monster " + std::to_string(i+1),false);
        tmp->SetPosition(n);
        board_->SetSquareValue(n,SquareType::Enemy);
        players_.push_back(tmp);
          }
        }
        i++;
    }


    bool running=true;
    while(running == true){
    TakeTurn(&newP);
    if(newP.get_position() == goal){
      newP.ChangePoints(1);
      std::cout<<"You got to the goal!" <<std::endl;
        std::cout<<newP.get_name()<< " got: " << newP.get_points() << " points!"<<std::endl;

      running = false;
      board_->printBoard();
    }
  }

}

void Maze::TakeTurn(Player *p){
  Player p1 = *p;
  Board b1 = *board_;
  if(p1.is_human() == true){
    b1.SetSquareValue(p1.get_position(), SquareType::Human);
  }
  else
  {
    b1.SetSquareValue(p1.get_position(), SquareType::Enemy);
  }
  Position up;
  up.row = p1.get_position().row -1;
  up.col = p1.get_position().col;
  Position down;
  down.row = p1.get_position().row +1;
  down.col = p1.get_position().col;
  Position left;
  left.row = p1.get_position().row;
  left.col = p1.get_position().col -1;
  Position right;
  right.row = p1.get_position().row;
  right.col = p1.get_position().col+1;

  std::string choice;

  bool response = false;
  b1.printBoard();
  std::cout<<p1.get_name()<<"'s turn" <<std::endl;
  std::cout<< p1.get_name() << " can go: ";
  std::vector<Position> possibleM = b1.GetMoves(&p1);
  std::cout<< "Please enter your choice" << std::endl;
  while(response == false){
    response = true;
    getline(std::cin, choice);
    //transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    if((choice == "down") && (b1.MovePlayer(&p1, down) == true)){
      b1.SetSquareValue(down, SquareType::Human);
      p->SetPosition(down);
      std::cout<<"MOVED DOWN" << std::endl;
    }
    else if((choice == "up") && (b1.MovePlayer(&p1, up) == true)){
      b1.SetSquareValue(up, SquareType::Human);
      p->SetPosition(up);
      std::cout<<"MOVED UP" << std::endl;
    }
    else if((choice == "left") && (b1.MovePlayer(&p1, left) == true)){
      b1.SetSquareValue(left, SquareType::Human);
      p->SetPosition(left);
      std::cout<<"MOVED LEFT" << std::endl;
    }
    else if((choice == "right") && (b1.MovePlayer(&p1, right) == true)){
      b1.SetSquareValue(right, SquareType::Human);
      p->SetPosition(right);
      std::cout<<"MOVED RIGHT" << std::endl;
    }
    else{
      response = false;
      std::cout<<"INVAID INPUT PLEASE TRY AGAIN" << std::endl;
    }



  }

}
