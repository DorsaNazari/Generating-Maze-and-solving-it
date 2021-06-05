#ifndef MAZE_H
#define MAZE_H
#include<iostream>
#include<vector>
#include <deque>


using Matrix = std ::vector <std :: vector<int>>;

class maze{
    public:
        maze* create_maze(int row , int col);
        void show(Matrix& a);
        void show2();
        maze* make_a_way();
        maze* move(int b);
        maze* move_c(int b);
        std::vector<int> possible_moves();
        std::vector<int> possible_moves_c();
        std::deque<maze> bfs (std::deque<maze> mazes);
        bool visited (std::vector<int> k);
        std::deque<maze> dfs (std::deque<maze>&mazes,int d);
        std::vector<std::deque<maze>> bidirectional (std::vector<std::deque<maze>> z);
        std::vector<std::deque<maze>> bidirectional_ (std::vector<std::deque<maze>> z);
        std::vector<int> comparison(std::deque<maze> mazes1,std::deque<maze> mazes2);
        Matrix a{};
        Matrix c{};
        std::deque<maze> create_deque (){return std::deque<maze> {*this};} ;
        int x{};
        int y{};
        int x_c{};
        int y_c{};


};

#endif