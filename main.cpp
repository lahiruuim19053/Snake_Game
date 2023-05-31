#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
bool GameOver;//The variable associated with the game loop.
bool champion;//The variable associated withe the game option loop.
bool Gamerepeat=false;//The variable associated with the game repeat loop.
bool menus=false;//The loop variable that prints the menu screen.
int const wallwidth=20,wallheight=20;// The const variable that stores wall size.
int SnakeHeadx,SnakeHeady;// The variable that stores the X and Y coordinates in the snake's head
int fruitx,fruity;// The two variables that store the X and Y coordinates of the fruit.
int score,Snake_speed;//score = The variable that adds points,Snake_speed=The variable that stores snake's speed.
int TailSize=0,SnakeTailx[300],SnakeTaily[300];//tail size=The variable that stores the length of the snake's tail.,SnakeTailx&SnakeTaily=Two Arrays store X and Y coordinates of the tail.
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};//
Direction dir;
HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);// The function that adds colours.
void gamerepeat();////The function to repeat the game.
void gamelevel();//The function that selects the game level.
void SnakeSetup();//The function that stores the game setup.
void SnakeDraw();//The function that prints the game while the game is playing.
void SnakeInput();//Function to get user inputs while playing the game.
void SnakeLogic();//The function that stores logic of the game.
void help();
void Showconsolecursor();
int main()
{
    do{
    SnakeSetup();
    while(!GameOver){//game loop
        SnakeDraw();
        SnakeInput();
        SnakeLogic();
        Sleep(Snake_speed);
    }
        gamerepeat();
}       while(!Gamerepeat);//game repeat loop
    system("cls");//The function that clears the console window.
    cout<<"final score="<<score<<endl;//The output that displays the final score when exiting the game.
    return 0;
}













void SnakeSetup(){
    system("cls");
    //bool menus=false;
    while(!menus) { //The loop that prints the menu screen.
    SetConsoleTextAttribute(out,10);//The function that adds colours.
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;

    cout<<"                                           8888888888 8888      88  88888888  88    88 8888888888      888888888888  88888888   888      888 8888888888               "<<endl;
    cout<<"                                           88      88 88 88     88 88      88 88   88  88              88        88 88      88  88 8    8 88 88                       "<<endl;
    cout<<"                                           88         88  88    88 88      88 88  88   88              88           88      88  88  8  8  88 88                       "<<endl;
    cout<<"                                           8888888888 88   88   88 8888888888 88888    8888888888      888888888888 8888888888  88   88   88 8888888888               "<<endl;
    cout<<"                                                   88 88    88  88 88      88 88  88   88              88      88 8 88      88  88        88 88                       "<<endl;
    cout<<"                                           88      88 88     88 88 88      88 88   88  88              88      88 8 88      88  88        88 88                       "<<endl;
    cout<<"                                           8888888888 88      8888 88      88 88    88 8888888888      8888888888 8 88      88  88        88 8888888888               "<<endl;

    cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    SetConsoleTextAttribute(out,5);
    cout<<"                                           -------------------- "<<endl;
    cout<<"                                           MAIN MENU"<<endl;
    cout<<"                                           -------------------- "<<endl;
    cout<<"                                           1.START GAME"<<endl;
    cout<<"                                           2.EXIT GAME"<<endl;
    cout<<"                                           3.HELP"<<endl;
    cout<<"                                           4.GAME MODE"<<endl;
    cout<<"                                           -------------------- "<<endl;
    cout<<endl;
    cout<<"                                           -------------------- "<<endl;
    switch(_getch()){ //Select ascii input from the menu and execute it.
        case '1':
         menus=true;
         GameOver=false;
         break;
        case '2':
         menus=true;
         GameOver=true;
         break;
        case '3':
         help();
         break;
        case '4':
         GameOver=false;
         gamelevel();

         //SnakeSetup();
         break;
   }

}
     dir=STOP;
     SnakeHeadx=wallwidth/2;//Assign the x and y coordinates to the corresponding variables where the snake's head should be at the start of the game.
     SnakeHeady=wallheight/2;//Assign the x and y coordinates to the corresponding variables where the snake's head should be at the start of the game.
     fruitx= rand()% wallwidth;//Obtain the random x and y coordinates corresponding to the location of the fruit by the rand function.
     fruity= rand()% wallheight;//Obtain the random x and y coordinates corresponding to the location of the fruit by the rand function.
     score=0;
     Snake_speed=100;
}
void SnakeDraw(){
    system("cls");
    SetConsoleTextAttribute(out,10);
    for(int wallx=0;wallx<wallwidth+1;wallx++){ //The for loop that prints the horizontal wall above.
     cout<<"#";
    }
    cout<<endl;
    SetConsoleTextAttribute(out,15);
    for(int wally=0;wally<wallheight;wally++){//The for loop that prints the two vertical walls.
        for(int wallx=0;wallx<wallwidth;wallx++){
            if(wallx==0){
                SetConsoleTextAttribute(out,10);
                cout<<"#";
            }
            if(wallx==wallwidth-1){
                SetConsoleTextAttribute(out,10);
                cout<<"#";
            }
                SetConsoleTextAttribute(out,15);
            if(wally==SnakeHeady&&wallx==SnakeHeadx){ //The if function that prints the snake's head according to the x and y coordinates.
                SetConsoleTextAttribute(out,7);
                cout<<"O";

            }
            else if(wally==fruity&&wallx==fruitx){ //The if function that prints the fruit according to the x and y coordinates.
                SetConsoleTextAttribute(out,20);
                cout<<"X";
            }

            else{
                bool print=false;
                for(int k=0;k<TailSize;k++){ //The for loop that prints the snake's tail according to the x and y coordinates.
                    if(SnakeTailx[k]==wallx&&SnakeTaily[k]==wally){
                        SetConsoleTextAttribute(out,7);
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print){ //The if condition that prints spaces within the game area.
                cout<<" ";}
            }
        }
        cout<<endl;
    }
    for(int wallx=0;wallx<wallwidth+1;wallx++){ //The for loop that prints the bottom horizontal wall.
     SetConsoleTextAttribute(out,10);
     cout<<"#";
    }
    cout<<endl;
    SetConsoleTextAttribute(out,4);
    cout<<"Score="<<score<<endl;}// The output that shows the score when the user is playing the game.
void SnakeInput(){
     if(_kbhit()){ //The switch that stores the input received while the game is playing.
        switch (_getch()){
         case 'a':
            dir=LEFT;
            break;
         case 'd':
            dir=RIGHT;
            break;
         case 'w':
            dir=UP;
            break;
         case 's':
            dir=DOWN;
            break;
         case 'o':
            GameOver=true;
            break;
        }
     }

}
void SnakeLogic(){

    int Prev_SnakeTailx=SnakeTailx[0];
    int Prev_SnakeTaily=SnakeTaily[0];
    int Prev_SnakeTail2x;
    int Prev_SnakeTail2y;
    SnakeTailx[0]=SnakeHeadx;//Assign the x and y coordinates of the snake's head to the end of the tail.(1st part of the tail)
    SnakeTaily[0]=SnakeHeady;//Assign the x and y coordinates of the snake's head to the end of the tail.(1st part of the tail)
    for(int i=1;i<TailSize;i++){
        Prev_SnakeTail2x=SnakeTailx[i];
        Prev_SnakeTail2y=SnakeTaily[i];
        SnakeTailx[i]=Prev_SnakeTailx;
        SnakeTaily[i]=Prev_SnakeTaily;
        Prev_SnakeTailx=Prev_SnakeTail2x;
        Prev_SnakeTaily=Prev_SnakeTail2y;//Move the x and y coordinates of each tail section to the tail behind it.
    }
    switch(dir){ //Switch that changes the x and y coordinates of the snake's head according to user input.
    case LEFT:
        SnakeHeadx--;
        break;
    case RIGHT:
        SnakeHeadx++;
        break;
    case UP:
        SnakeHeady--;
        break;
    case DOWN:
        SnakeHeady++;
        break;
    default:
        break;
    }
    if(!champion){
    if(SnakeHeadx>wallwidth||SnakeHeadx<0||SnakeHeady>wallheight||SnakeHeady<0){  //Logic that relates to the champion mode.(Game is over when the snake's head hits the wall.)
        GameOver=true;

    }}
    if(champion){
    if(SnakeHeadx>=wallwidth){SnakeHeadx=0;}
    else if (SnakeHeadx<0){SnakeHeadx=wallwidth-1;} //Logic that relates to the classic mode.(Game is not over when the snake's head hits the wall.)
    if(SnakeHeady>=wallheight){SnakeHeady=0;}
    else if (SnakeHeady<0){SnakeHeady=wallheight-1;}
    }
    for(int i=0;i<TailSize;i++){
        if(SnakeTailx[i]==SnakeHeadx&&SnakeTaily[i]==SnakeHeady){//The logic of finishing the game when the snake's head goes over his body.
            GameOver=true;
        }
    }
    if(fruitx==SnakeHeadx&&fruity==SnakeHeady){ // The logic of adding points when eating a fruit,printing a new fruit randomly and increasing the length of the tail.
        score+=10;
        fruitx= rand()% wallwidth;
        fruity= rand()% wallheight;
        TailSize++;
    }
    if (score<=50){ //The logic that increases the speed of the snake as the number of points obtained increases.
                Snake_speed=90;
       }
           else if (score<=100){
                Snake_speed=80;
       }
           else if (score<=150){
                Snake_speed=70;
       }
           else if (score<=200){
                Snake_speed=60;
       }
           else if (score<=250){
                Snake_speed=50;
       }
           else if (score<=300){
                Snake_speed=45;
       }
           else if (score<=350){
                Snake_speed=40;
       }
           else if (score<=400){
                Snake_speed=35;
       }
           else if (score<=450){
                Snake_speed=30;
       }
           else if  (score<=500){
                Snake_speed=20;
       }

}
void gamelevel(){
         system("cls");
         bool gamelevel=false;
         while(!gamelevel){ //The loop that prints the game option window.
         SetConsoleTextAttribute(out,10);
         cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;

        cout<<"                                           8888888888 8888      88  88888888  88    88 8888888888      888888888888  88888888   888      888 8888888888               "<<endl;
        cout<<"                                           88      88 88 88     88 88      88 88   88  88              88        88 88      88  88 8    8 88 88                       "<<endl;
        cout<<"                                           88         88  88    88 88      88 88  88   88              88           88      88  88  8  8  88 88                       "<<endl;
        cout<<"                                           8888888888 88   88   88 8888888888 88888    8888888888      888888888888 8888888888  88   88   88 8888888888               "<<endl;
        cout<<"                                                   88 88    88  88 88      88 88  88   88              88      88 8 88      88  88        88 88                       "<<endl;
        cout<<"                                           88      88 88     88 88 88      88 88   88  88              88      88 8 88      88  88        88 88                       "<<endl;
        cout<<"                                           8888888888 88      8888 88      88 88    88 8888888888      8888888888 8 88      88  88        88 8888888888               "<<endl;

        cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
        cout<<"                                           88    88 8888888 88888888 8888888        "<<endl;
        cout<<"                                           8 8  8 8 8     8  8     8 8          "<<endl;
        cout<<"                                           8  88  8 8     8  8     8 8888888           "<<endl;
        cout<<"                                           8      8 8     8  8     8 8           "<<endl;
        cout<<"                                           8      8 8888888 88888888 8888888 "<<endl;

        cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
        cout<<"                                           1.Champion Mood"<<endl;
        cout<<"                                           2.Classic Mood"<<endl;
            switch(_getch()){ //The switch that activates the game options to store input.
              case '1':
                  menus=false;
                  gamelevel=true;
                  champion=true;
                  system("cls");
                  break;
              case '2':
                  menus=false;
                  gamelevel=true;
                  champion=false;
                  system("cls");
                  break;

         }
         }

   }
void gamerepeat(){
     system("cls");
      SetConsoleTextAttribute(out,10);
      cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
      cout<<"                                                      8888888888 888888888 88    88 88888888    88888888 8        8 88888888 88888888 "<<endl;
      cout<<"                                                      8          8       8 8 8  8 8 8           8      8  8      8  8        8      8 "<<endl;
      cout<<"                                                      8888888888 888888888 8  88  8 88888888    8      8   8    8   88888888 88888888 "<<endl;
      cout<<"                                                      8      8 8 8       8 8      8 8           8      8    8  8    8        888888   "<<endl;
      cout<<"                                                      88888888 8 8       8 8      8 88888888    88888888     88     88888888 8     88 "<<endl;
      cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
      cout<<"                                                                                       score="<<score<<endl;
      cout<<endl;cout<<endl;cout<<endl;cout<<endl;
      cout<<"                                                      1.play again"<<endl;
      cout<<"                                                      2.exit game"<<endl;
      cout<<"                                                      3.main menu"<<endl;
     switch(_getch()){ //The switch that stores user input after the game is over.
         case '1':
          Gamerepeat=false;
          GameOver=false;
          break;
         case '2':
           Gamerepeat=true;
           break;
         case '3':
           menus=false;
           Gamerepeat=false;
           break;
             }
}
void help(){
system ("CLS");
   SetConsoleTextAttribute(out,10);
   cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;

        cout<<"                                           8888888888 8888      88  88888888  88    88 8888888888      888888888888  88888888   888      888 8888888888               "<<endl;
        cout<<"                                           88      88 88 88     88 88      88 88   88  88              88        88 88      88  88 8    8 88 88                       "<<endl;
        cout<<"                                           88         88  88    88 88      88 88  88   88              88           88      88  88  8  8  88 88                       "<<endl;
        cout<<"                                           8888888888 88   88   88 8888888888 88888    8888888888      888888888888 8888888888  88   88   88 8888888888               "<<endl;
        cout<<"                                                   88 88    88  88 88      88 88  88   88              88      88 8 88      88  88        88 88                       "<<endl;
        cout<<"                                           88      88 88     88 88 88      88 88   88  88              88      88 8 88      88  88        88 88                       "<<endl;
        cout<<"                                           8888888888 88      8888 88      88 88    88 8888888888      8888888888 8 88      88  88        88 8888888888               "<<endl;
        SetConsoleTextAttribute(out,5);
        cout<<endl;cout<<endl;cout<<endl;cout<<endl;
        cout<<"                                           8    8 888888 8      8888888   "<<endl;
        cout<<"                                           8    8 8      8      8     8   "<<endl;
        cout<<"                                           888888 888888 8      8888888   "<<endl;
        cout<<"                                           8    8 8      8      8         "<<endl;
        cout<<"                                           8    8 888888 888888 8         "<<endl;
        cout<<endl;cout<<endl;cout<<endl;cout<<endl;
       SetConsoleTextAttribute(out,8);
       cout<<"                                           Controls"<<endl;
       SetConsoleTextAttribute(out,10);
       cout<<"                                                 Letter “O” is the Head of the snake."<<endl;
       cout<<"                                                 Letter “X” is the Fruit."<<endl;
       cout<<"                                                 The player controls the letter “O” on the console using W A S D keys."<<endl;
       cout<<"                                                        W- Move Forward"<<endl;
       cout<<"                                                        S- Move Backward"<<endl;
       cout<<"                                                        A- Move Left"<<endl;
       cout<<"                                                        D- Move Right"<<endl;
       SetConsoleTextAttribute(out,8);
       cout<<"                                           Game Play "<<endl;
       SetConsoleTextAttribute(out,10);
       cout<<"                                                 As The Head of Snake moves forward, the Tail of the snake follows it."<<endl;
       cout<<"                                                 The game places a Fruit in a random place on the console."<<endl;
       cout<<"                                                 Player has to maneuver the snake and eat the food. "<<endl;
       cout<<"                                                 Each food which snake eaten makes snake longer."<<endl;
       cout<<"                                                 If the Snake collides with its own body or tail game is over."<<endl;
       SetConsoleTextAttribute(out,8);
       cout<<"                                           Game Mode"<<endl;
       SetConsoleTextAttribute(out,10);
       cout<<"                                                 Player can choose 2 different game modes from the main menu."<<endl;
       cout<<"                                                          1.Champion Mode: the Snake can go through the walls."<<endl;
       cout<<"                                                          2.Classic Mode: If the Snake collides with the walls, game is over."<<endl;
       cout<<endl;
       cout<<endl;
       cout<<endl;
       cout<<endl;
       cout<<endl;
       SetConsoleTextAttribute(out,5);
       cout<<"                                            1.MAIN MENU"<<endl;
        if(_getch()){
          menus=false;
          SnakeSetup();
     }
}




