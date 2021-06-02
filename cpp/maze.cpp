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

using Matrix = std ::vector <std :: vector<int>>;

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

void maze::show2()
{
    size_t row = a.size() * 2 + 1;
    size_t column = a[0].size() * 2 + 1;
    size_t r, c;
    std::vector<std::vector<const char*>> disp;
    for (size_t i = 0; i < row; i++)
    {
        std::vector<const char*> temp;
        for (size_t j = 0; j < column; j++)
        {
            r = (i-1)/2;
            c = (j-1)/2;
            if(j%2 == 0 || i%2 == 0 || i == 0 || i == row-1)
                temp.push_back("# ");
            else
            {
                if(a[r][c] == 1)  //divar keshi
                    temp.push_back("# ");
                else if(a[r][c] == 0)  //khune khali
                {
                    temp.push_back("  ");
                }
                else
                    temp.push_back("* ");
            }
        }
        disp.push_back(temp);
    }
    r = (row-1)/2;
    c = (column-1)/2;
    size_t r2, c2;
    // std::cout <<"size: " << r <<", "<<c<<std::endl;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            r2 = i*2+1;
            c2 = j*2+1;
            if(a[i][j] != 1)
            {
                // std::cout << i*2+1 << ", " << j*2+1 << " - ";
                if(i>0)  //bala
                {
                    if(a[i-1][j] != 1)
                        disp[r2-1][c2] = "  ";
                }
                else if(i<r-1)  //paeen
                {
                    if(a[i+1][j] != 1)
                        disp[r2+1][c2] = "  ";
                }
                if(j>0)  //chap
                {
                    if(a[i][j-1] != 1)
                        disp[r2][c2-1] = "  ";
                }
                else if(j<c-1)  //raast
                {
                    if(a[i][j+1] != 1)
                        disp[r2][c2+1] = "  ";
                }
            }
        }
    }
    std::cout << std::endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            if(disp[i][j] == static_cast<const char*>("* "))
            {
                std::cout<< "\e[0;106m" ;
                std::cout << "  ";
                std::cout<<"\u001b[0m";
            }
            else
                std::cout << disp[i][j];
        }
        std::cout << std::endl;
    }
}

void maze::show(){
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
        if(x -1 >= 0){
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
        if(y-1 >= 0){
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
        if(x -1 >= 0){
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
        if(y-1 >= 0){
            if( a[x][y-1] == 0 )
                dir.push_back(3);
        }
    }
    else
        std::cout<<"this cell is full!\n";
    // for(auto i:dir){
    //     std::cout<<"possible moves : "<<i<<" ";
    // }
    // std::cout<<std::endl;
    return dir;
}

std::deque<maze> maze::bfs (){
    // std::cout<<"here \n";
    //make a deque
    static std::deque<maze> mazes{*this};

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
    //else delete first maze and move to possible cells then run bfs on elements of deque again
        std::vector<int> v = m.possible_moves();
        std::vector<int> l{};
        for(auto j:v){
            std::cout << "here " << j << std::endl;
            maze n = m;
            n.move(j);
            n.show();
            l.push_back(n.x);
            l.push_back(n.y);
            if(!(n.visited(l))){
                mazes.push_back(n);
                // n.visitedd.push_back(l);
                // visitedd.push_back(l);
                // std::cout<<"now "<<n.x<<n.y<<" "<<a[x][y] <<"\n";
                }
        }
        mazes.pop_front();
        m.bfs();
    }
    return mazes;
}

bool maze::visited (std::vector<int> k){
    static Matrix visitedd;
    std::cout << "visited: \n";
    std::cout << k[0] << k[1]<<"\n";
    for(size_t h{};h<visitedd.size();h++){
        std::cout<<"(" << visitedd[h][0]<<", "<<visitedd[h][1]<<"), ";
    }
    std::cout << std::endl;
    bool is_visited = false;
    for(auto i:visitedd){
        if(i[0] == k[0] && i[1] == k[1]){
            is_visited = true;
        }
    }
    if (!is_visited)
        visitedd.push_back(k);
    std::cout << is_visited << std::endl;
    return is_visited;
}

std::deque<maze> maze::dfs (std::deque<maze>&mazes){
    maze m = mazes[0];
    static int depth{};
    if(m.a[a.size()-1][a[0].size()-1] == 5){
        std::cout<<"solution is found\n";
        m.show2();
        return mazes;
    }
    if(depth > 110){
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