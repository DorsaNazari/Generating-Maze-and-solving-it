#include "maze.h"
#include<iostream>
#include<vector>
#include <time.h>
#include<iomanip>
// #include <list>
// #include <initializer_list>
// #include<algorithm> 
// #include<stdexcept>
// // #include<compare>
// #include <iterator>

using Matrix = std ::vector <std :: vector<int>>;

Matrix maze::create_maze(int row , int col){
    Matrix b;
    // std::vector<int> vect(col, 1);
    // b.push_back(vect);
    srand( (unsigned)time(NULL) ); //Randomize seed initialization
    // for(int i{0} ;i<row-2 ;i++)
    for(int i{0} ;i<row ;i++)
    {
        std :: vector <int> temp;
        for(int j{0};j<col;j++){
	        int randNum = rand() % 2; // Generate a random number between 0 and 1
            temp.push_back(randNum);
            // temp[0] = 1;
            // temp[col-1] = 1;
    }
        b.push_back(temp);
    }   
    // b.push_back(vect);
    // b[1][1] = 0;
    // b[row-2][col-2] = 0;
    b[0][0] = 0;
    b[row-1][col-1] = 0;
    return b;
}

void maze::show(Matrix& a)
{
        for(size_t i{0} ;i<a.size() ;i++)
    {
        for(size_t j{0};j<a[i].size();j++){
            // std::cout<< std::setiosflags(std::ios::left)<< std::setw(2)<< a[i][j] ;
            if(a[i][j] == 1)
                std::cout<< "%" ;
            if(a[i][j] == 0)   
                std::cout<< "-" ;
            if(a[i][j] == 5){
                std::cout<< "$" ;
                a[i][j] = 0;
            }

        }
        std::cout<<std::endl;    
    }
}

Matrix maze::make_a_way(Matrix& a){
    srand( (unsigned)time(NULL) );
    size_t down = 0;
    size_t right = 0;
    std :: vector <int> temp;
    while (down < a.size()-1 && right < a[0].size()-1)
    {
        int randNum = rand() % 2;
        if( randNum == 0 ){
            down += 1;
            temp.push_back(randNum);
        }
        else{
            right += 1;
            temp.push_back(randNum);
        }
    }
    if(down < a.size()-1){
        while (down < a.size()-1)
        {
            down += 1;
            temp.push_back(0);
        } 
    }
    if(right < a[0].size()-1){
        while (right < a[0].size()-1)
        {
            right += 1;
            temp.push_back(1);
        } 
    }
    // for(size_t i{};i<temp.size();i++){
    //     std::cout<<temp[i];
    // }
    // std::cout<<"\n";
    int row{};
    int col{};
    for(size_t i{};i<temp.size();i++){
        if(temp[i] == 0){
            // std::cout<<"down\n";
            row += 1;
            a[row][col] = 0;
        }
        else
        {
            // std::cout<<"right\n";
            col += 1;
            a[row][col] = 0; 
        }       
    }
    return a;
}

Matrix maze::move(Matrix &a,int b){
    //0->up  1->right  2->down  3->left   7->start
    //start
    if(b == 7){
        x = 0;
        y = 0;
        a[x][y] = 5;
    }
    //up
    if(b == 0){
        if(x -1 > 0){
            if( a[x -1][y] == 0 ){
                a[x -1][y] = 5;
                x -= 1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //right
    if(b == 1){
        if(y +1 < static_cast<int>(a[0].size())){
            if( a[x][y+1] == 0 ){
                a[x][y+1] = 5;
                y +=1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //down
    if(b == 2){
        if(x+1 < static_cast<int>(a.size())){
            if( a[x+1][y] == 0 ){
                a[x+1][y] = 5;
                x += 1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //left
    if(b == 3){
        if(y-1 > 0){
            if( a[x][y-1] == 0 ){
                a[x][y-1] = 5;
                y -= 1;
            }
            else    
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }   
    return a;
}

std::vector<int> maze::possible_moves(Matrix& a){
    std::vector<int> dir;
    if(a[x][y] == 0){
        if(x -1 > 0){
            if( a[x -1][y] == 0 )
                dir.push_back(0);  
        }
        if(y +1 < static_cast<int>(a[0].size())){
            if( a[x][y+1] == 0 )
                dir.push_back(1);
        }
        if(x+1 < static_cast<int>(a.size())){
            if( a[x+1][y] == 0 )
                dir.push_back(2);
        }
        if(y-1 > 0){
            if( a[x][y-1] == 0 )
                dir.push_back(3);
        }
    }
    else
        std::cout<<"this cell is full!\n";

    for(auto i:dir){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    
    return dir;
}