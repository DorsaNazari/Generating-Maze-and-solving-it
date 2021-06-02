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
        void show2();
        maze* make_a_way();
        maze* move(int b);
        bool end (std::deque<maze*> d);
        std::vector<int> possible_moves();
        std::deque<maze> bfs (std::deque<maze> mazes);
        bool visited (std::vector<int> k);
        std::deque<maze> dfs (std::deque<maze>&mazes);
        Matrix a{};

        // static Matrix visitedd;
        std::deque<maze> create_deque (){return std::deque<maze> {*this};} ;
        int x{};
        int y{};

};

#endif