#include "maze.h"
#include<iostream>
#include<vector>
#include <time.h>
#include<iomanip>
#include <deque>
// #include <list>
// #include <initializer_list>
// #include<algorithm> 
// #include<stdexcept>
// // #include<compare>
// #include <iterator>

using Matrix = std ::vector <std :: vector<int>>;

// maze::maze(maze& m){
//     for(auto i:m){
//     }
// }

maze* maze::create_maze(int row , int col){
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
    b[0][0] = 5;
    b[row-1][col-1] = 0;
    a = b;
    return this;
}

void maze::show()
{
        for(size_t i{0} ;i<a.size() ;i++)
    {
        for(size_t j{0};j<a[i].size();j++){
            // std::cout<< std::setiosflags(std::ios::left)<< std::setw(2)<< a[i][j] ;
            if(a[i][j] == 1)
                std::cout<< "#" ;
            if(a[i][j] == 0)   
                std::cout<< "-" ;
            if(a[i][j] == 5){
                std::cout<< "\u001b[31m$" ;
                std::cout<<"\u001b[0m";
            }

        }
        std::cout<<std::endl;    
    }
}

// maze* maze::create_maze(int row , int col){
//     Matrix b;
//     // std::vector<int> vect(col, 1);
//     // b.push_back(vect);
//     srand( (unsigned)time(NULL) ); //Randomize seed initialization
//     // for(int i{0} ;i<row-2 ;i++)
//     for(int i{0} ;i<row ;i++)
//     {
//         std :: vector <int> temp;
//         for(int j{0};j<col;j++){
// 	        int randNum = rand() % 2; // Generate a random number between 0 and 1
//             temp.push_back(randNum);
//             // temp[0] = 1;
//             // temp[col-1] = 1;
//     }
//         b.push_back(temp);
//     }   
//     // b.push_back(vect);
//     // b[1][1] = 0;
//     // b[row-2][col-2] = 0;
//     b[0][0] = 0;
//     b[row-1][col-1] = 0;
//     size_t down = 0;
//     size_t right = 0;
//     std :: vector <int> tempe;
//     while (down < b.size()-1 && right < b[0].size()-1)
//     {
//         int randNum1 = rand() % 2;
//         if( randNum1 == 0 ){
//             down += 1;
//             tempe.push_back(randNum1);
//         }
//         else{
//             right += 1;
//             tempe.push_back(randNum1);
//         }
//     }
//     if(down < b.size()-1){
//         while (down < b.size()-1)
//         {
//             down += 1;
//             tempe.push_back(0);
//         } 
//     }
//     if(right < b[0].size()-1){
//         while (right < b[0].size()-1)
//         {
//             right += 1;
//             tempe.push_back(1);
//         } 
//     }
//     int row1{};
//     int col1{};
//     for(size_t i{};i<tempe.size();i++){
//         if(tempe[i] == 0){
//             // std::cout<<"down\n";
//             b[row1 +1][col1] = 0;
//         }
//         else
//         {
//             // std::cout<<"right\n";
//             b[row1][col1+1] = 0; 
//         }       
//     }
//     a = b;
//     return this;
// }

maze* maze::make_a_way(){
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
    return this;
}

maze* maze::move(int b){
    //0->up  1->right  2->down  3->left   7->start
    //start
    // a[x][y] = 0;
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
    return this;
}

std::vector<int> maze::possible_moves(){
    std::vector<int> dir;
    if(a[x][y] != 1 ){
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
        std::cout<<"possible moves Are : "<<i<<" ";
    }
    std::cout<<std::endl;
    return dir;
}

std::deque<maze> maze::bfs (std::deque<maze> &mazes){
    //make a deque
    if(mazes.size()==0){
        std::cout<<"no way\n";
        return mazes;
    }
    maze m = mazes[0];
    //if its end return the deque
    if(m.a[a.size()-1][a[0].size()-1] == 5){
        std::cout<<"solution is found\n";
        m.show();
        return mazes;
    }
    else{
        std::cout<<"here2\n";
    //else delete first maze and move to possible cells then run bfs on elements of deque again
        std::vector<int> v = m.possible_moves();
        for(auto j:v){
            maze n = m;
            mazes.push_back(*n.move(j));
        }
        mazes.pop_front();
        m.bfs(mazes);
    }
    return mazes;
}

std::deque<maze> maze::dfs (std::deque<maze>&mazes){
    maze m = mazes[0];
    static int depth{};
    // std::cout<<depth<<"\n";
    if(m.a[a.size()-1][a[0].size()-1] == 5){
        std::cout<<"solution is found\n";
        m.show();
        return mazes;
    }
    if(depth > 50){
        std::cout<<"answer not found!\n";
        return mazes;
    }
    else{
        std::vector<int> v = m.possible_moves();
        for(auto j:v){
            maze n = m;
            mazes.push_back(*n.move(j));
            depth += 1;
            mazes.pop_front();
            std::deque<maze> k = n.dfs(mazes);
            depth -= 1;
            if(k[0].a[a.size()-1][a[0].size()-1] == 5){
                return k;
            }
        }
    }
    return mazes;
}


        // std::cout<<"now :\n";
        // i->show(i->a);
        // std::cout<<"\n";