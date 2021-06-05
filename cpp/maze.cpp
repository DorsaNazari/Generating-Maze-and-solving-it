#include "maze.h"
#include<iostream>
#include<vector>
#include <time.h>
#include<iomanip>
#include <deque>


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

void maze::show(Matrix& u){
    for(size_t i{0} ;i<u.size() ;i++)
    {
        for(size_t j{0};j<u[i].size();j++){
            // std::cout<< std::setiosflags(std::ios::left)<< std::setw(2)<< a[i][j] ;
            if(u[i][j] == 1)
                std::cout<< "#" ;
            if(u[i][j] == 0)   
                std::cout<< "-" ;
            if(u[i][j] == 5){
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
    c = a;
    c[0][0] = 0;
    c[row][col] = 5;
    x_c = row;
    y_c = col;
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

maze* maze::move_c(int b){
    //0->up  1->right  2->down  3->left   7->start
    //start
    // a[x][y] = 0;
    if(b == 7){
        x_c = 0;
        y_c = 0;
        c[x_c][y_c] = 5;
    }
    //up
    if(b == 0){
        if(x_c -1 >= 0)
        // if(x_c -1 < static_cast<int>(c.size()))
        {
            if( c[x_c -1][y_c] == 0 ){
                c[x_c -1][y_c] = 5;
                x_c -= 1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //right
    if(b == 1){
        if(y_c +1 < static_cast<int>(c[0].size())){
            if( c[x_c][y_c+1] == 0 ){
                c[x_c][y_c+1] = 5;
                y_c +=1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //down
    if(b == 2){
        if(x_c + 1 < static_cast<int>(c.size())){
            if( c[x_c+1][y_c] == 0 ){
                c[x_c+1][y_c] = 5;
                x_c += 1;
            }
            else
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }
    //left
    if(b == 3){
        if(y_c-1 >= 0){
            if( c[x_c][y_c-1] == 0 ){
                c[x_c][y_c-1] = 5;
                y_c -= 1;
            }
            else    
                std::cout<<"There's not a way!\n";
        }
        else
            std::cout<<"out of band!\n";
    }   
    // std::cout<<"move ccc\n";
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
    //     std::cout<<"dir : "<<i<<" ";
    // }
    // std::cout<<std::endl;
    return dir;
}

std::vector<int> maze::possible_moves_c(){
    std::vector<int> dir;
    if(c[x_c][y_c] != 1 ){
        if(x_c -1 >= 0){
            if( c[x_c -1][y_c] == 0 )
                dir.push_back(0);  
        }
        if(y_c +1 < static_cast<int>(c[0].size())){
            if( c[x_c][y_c+1] == 0 )
                dir.push_back(1);
        }
        if(x_c+1 < static_cast<int>(c.size())){
            if( c[x_c+1][y_c] == 0 )
                dir.push_back(2);
        }
        if(y_c-1 >= 0){
            if( c[x_c][y_c-1] == 0 )
                dir.push_back(3);
        }
    }
    else
        std::cout<<"this cell is full!\n";
    // for(auto i:dir){
    //     std::cout<<"dir : "<<i<<" ";
    // }
    // std::cout<<std::endl;
    return dir;
}

std::deque<maze> maze::bfs(std::deque<maze> mazes){
    if(mazes.size()==0){
        std::cout<<"no way\n";
        return mazes;
    }
    maze m = mazes[0];
    //if its end return the deque
    if(m.a[a.size()-1][a[0].size()-1] == 5){
        std::cout<<"solution is found\n";
        m.show2();
        return mazes;
    }
    else{
    //else delete first maze and move to possible cells then run bfs on elements of deque again
        std::vector<int> v = m.possible_moves();
        for(auto j:v){
            std::vector<int> l{};
            maze n = m;
            n.move(j);
            l.push_back(n.x);
            l.push_back(n.y);
            if(!(visited(l)))
                mazes.push_back(n);
        }
        mazes.pop_front();
        m.bfs(mazes);
    }
    return mazes;
}

bool maze::visited (std::vector<int> k){
    static Matrix visitedd;
    // std::cout << "visited: \n";
    // std::cout << k[0] << k[1]<<"\n";
    // for(size_t h{};h<visitedd.size();h++){
    //     std::cout<<"(" << visitedd[h][0]<<", "<<visitedd[h][1]<<"), ";
    // }
    // std::cout << std::endl;
    bool is_visited = false;
    for(auto i:visitedd){
        if(i[0] == k[0] && i[1] == k[1]){
            is_visited = true;
        }
    }
    if (!is_visited)
        visitedd.push_back(k);
    // std::cout << is_visited << std::endl;
    return is_visited;
}

std::deque<maze> maze::dfs (std::deque<maze>&mazes,int d){
    maze m = mazes[0];
    static int depth{};
    if(m.a[a.size()-1][a[0].size()-1] == 5){
        std::cout<<"solution is found\n";
        m.show2();
        return mazes;
    }
    if(depth > d){
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
            std::deque<maze> k = n.dfs(mazes,d);
            depth -= 1;
            if(k[0].a[a.size()-1][a[0].size()-1] == 5){
                return k;
            }
        }
    }
    return mazes;
}

std::vector<std::deque<maze>> maze::bidirectional_ (std::vector<std::deque<maze>> z){
    if(z[0].size()==0 || z[1].size()==0 ){
        std::cout<<"no way\n";
        show(a);
        show(c);
        return z;
    }
    maze m1 = z[0][0];
    maze m2 = z[1][0];
    //if its end return the deque
    if( comparison(z[0],z[1])[0] != -1 ){
        std::cout<<"solution is found\n";
        m1.show(a);
        std::cout<<"*********\n";
        return z;
    }
    else{
    //else delete first maze and move to possible cells then run bfs on elements of deque again
        std::vector<int> v1 = m1.possible_moves();
        std::vector<int> v2 = m2.possible_moves_c();
        // std::cout<<v[0]<<"\n";
        for(auto j1:v1){
            std::vector<int> l1{};
            maze n1 = m1;
            n1.move(j1);
            l1.push_back(n1.x);
            l1.push_back(n1.y);
            // if(!(visited(l1)))
                z[0].push_back(n1);
        }
        for(auto j2:v2){
            std::vector<int> l2{};
            maze n2 = m2;
            n2.move_c(j2);
            l2.push_back(n2.x_c);
            l2.push_back(n2.y_c);
            // if(!(visited(l2)))
                z[1].push_back(n2);
        }
        z[0].pop_front();
        z[1].pop_front();
        m1.bidirectional_(z);
    }
    return z;
}

std::vector<std::deque<maze>> maze::bidirectional (std::vector<std::deque<maze>> z){
    if(z[0].size()==0 || z[1].size()==0 ){
        std::cout<<"no way\n";
        show(a);
        show(c);
        return z;
    }
    maze m1 = z[0][0];
    maze m2 = z[1][0];
    //if its end return the deque
    if( comparison(z[0],z[1])[0] != -1 ){
        std::cout<<"solution is found\n";
        // m1.show(a);
        std::cout<<"*********\n";
        m2.show(c);
        return z;
    }
    else{
    //else delete first maze and move to possible cells then run bfs on elements of deque again
        std::vector<int> v1 = m1.possible_moves();
        std::vector<int> v2 = m2.possible_moves_c();
        // std::cout<<v[0]<<"\n";
        for(auto j1:v1){
            std::vector<int> l1{};
            maze n1 = m1;
            n1.move(j1);
            l1.push_back(n1.x);
            l1.push_back(n1.y);
            // if(!(visited(l1)))
                z[0].push_back(n1);
        }
        for(auto j2:v2){
            std::vector<int> l2{};
            maze n2 = m2;
            n2.move_c(j2);
            l2.push_back(n2.x_c);
            l2.push_back(n2.y_c);
            // if(!(visited(l2)))
                z[1].push_back(n2);
        }
        z[0].pop_front();
        z[1].pop_front();

        m2.bidirectional(z);
    }
    return z;
}

std::vector<int> maze::comparison(std::deque<maze> mazes1,std::deque<maze> mazes2){
    std::vector<int> v;
    for(size_t i{};i<mazes1.size();i++){
        for(size_t j{};j<mazes2.size();j++)
        {
            if(mazes1[i].x == mazes2[j].x_c && mazes1[i].y == mazes2[j].y_c){
                v.push_back(i);
                v.push_back(j);
                // mazes1[i].show(a);
                // mazes2[j].show(c);
                // std::cout<<"compariccccccccc"<<mazes2[j].x_c<<mazes2[j].y_c<<"aaaaaaa"<<mazes1[i].x<<mazes1[i].y<<"\n";
                return v; 
            }
        }
    }
    v.push_back(-1);
    return v;
}