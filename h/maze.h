#ifndef MAZE_H
#define MAZE_H
#include<iostream>
// #include <list>
// // #include<compare>
// #include<initializer_list>
// #include<set>
#include<vector>

using Matrix = std ::vector <std :: vector<int>>;

class maze{
    public:
       Matrix create_maze(int row , int col);
       void show();


};


#endif