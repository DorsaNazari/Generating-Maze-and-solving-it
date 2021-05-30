#ifndef MAZE_H
#define MAZE_H
#include<iostream>
// #include <list>
// // #include<compare>
// #include<initializer_list>
// #include<set>
#include<vector>
#include <deque>


using Matrix = std ::vector <std :: vector<int>>;

class maze{
    public:
        // maze(maze&);
        maze* create_maze(int row , int col);
        void show();
        maze* make_a_way();
        maze* move(int b);
        bool end (std::deque<maze*> d);
        std::vector<int> possible_moves(Matrix& a);
        std::deque<maze> bfs (std::deque<maze> &mazes);
        Matrix a{};
        std::deque<maze> create_deque (){return std::deque<maze> {*this};} ;     // std::deque<maze> mazes {*this};
        int x{};
        int y{};

};

#endif