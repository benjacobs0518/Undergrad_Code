#include <iostream>

class Board {
public:
	Board(){
    play = false;
    p1Turn = true;
    for(int i =0; i < 3; i++){
      for(int j=0; j< 3; j++){
         board[i][j]= "empty";
      }
    }
    std::cout<<"Player 1, what would you like your marker to be?"<<std::endl;
    std::cin >> markerp1;
    std::cout<<"Player 2, what would you like your marker to be?"<<std::endl;
    std::cin >> markerp2;
  };
	void DisplayBoard(){
    for(int i =0; i < 3; i++){
      std::cout<<i+1;
      for(int j=0; j< 3; j++){
        std::cout<<"|" << board[i][j];
      }
      std::cout<<"|"<<std::endl;
    }
  };

  void GetPlayerChoice(){
    int choice1;
    int choice2;
    std::string marker;
    bool goodChoice = false;
    bool goodRow = false;
    bool goodCol = false;
    while(goodChoice == false){
      std::cout<<"What position would you like to fill?"<<std::endl;
      while(goodRow == false){
        std::cout<<"Row:"<<std::endl;
        std::cin >> choice1;
        if(choice1 < 1 || choice1 > 3){
          std::cout<<"Enter a valid row choice"<<std::endl;
        }
        else{
          goodRow = true;
        }
      }
      while(goodCol == false){
        std::cout<<"Col:"<<std::endl;
        std::cin >> choice2;
        if(choice2 < 1 || choice2 > 3){
          std::cout<<"Enter a valid col choice"<<std::endl;
        }
        else{
          goodCol = true;
        }
      }
      if(goodRow == true && goodCol == true){
        if(board[choice1-1][choice2-1] == "empty"){
          goodChoice = true;
          if(p1Turn == true){
            PlaceMarker(choice1-1,choice2-1,markerp1);
          }
          else{
            PlaceMarker(choice1-1,choice2-1,markerp2);
          }

          DisplayBoard();
        }
        else{
          std::cout<<"Please enter a valid position"<<std::endl;
          goodRow = false;
          goodCol = false;
        }

      }
    }
};

  bool getPlay(){return play;}
void PlaceMarker(int x, int y, std::string mark){
  board[x][y] = mark; //edited values

};
  void setPlayer(){p1Turn = !p1Turn;}
	int get_rows() const {return 3; }  // you should be able to change the size of your
	int get_cols() const {return 3; }  // board by changing these numbers and the numbers in the arr_ field

private:
	std::string board[3][3];
  bool play;
  bool p1Turn;
  std::string markerp1;
  std::string markerp2;

};

int main( int argc, char *argv[])
{
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    Board p1;
    p1.DisplayBoard();
    int i = 0;
    while(p1.getPlay() == true || i < 9)
    {
      p1.GetPlayerChoice();
      p1.setPlayer();
      i++;
    }

}
