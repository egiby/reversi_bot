#ifndef _CLIENT
#define _CLIENT

#include "Strategy.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Client
{
//~ public:
    IStrategy * strategy;
    
    Color color;
    vector<vector<char> > board;
    
    void badError()
    {
        std::cerr << "Something wrong!" << endl;
    }
    
    void init()
    {
        board = vector<vector<char> >(8, vector<char>(8, EMPTY));
        
        string s;
        cin >> s;
        if (s == "init")
        {
            string s_color;
            cin >> s_color;
            
            if (s_color == "black")
                color = BLACK;
            else
                color = WHITE;
        }
        else
            badError();
        
        board[3][3] = board[4][4] = WHITE;
        board[3][4] = board[4][3] = BLACK;
    }
    
    void move()
    {
        pair<int, int> answer = strategy->move(color, board);
        
        getMove(answer.first, answer.second, color, board);
    #ifdef _GEANY
        cerr << "move " << answer.first << ' ' << answer.second << endl;
    #endif
        cout << "move " << (char)(answer.first + 'a') << ' ' << answer.second + 1 << endl;
    }
    
    void readMove()
    {
        char c;
        ui32 idx;
        
        cin >> c >> idx;
    #ifdef _GEANY
        cerr << c << ' ' << idx << endl;
    #endif
        getMove(c - 'a', idx - 1, anotherColor(color), board);
    }
    
    Client ()
    {
    }
public:
    
    Client (IStrategy * strategy)
    : strategy(strategy)
    {
    }
    
    void game()
    {
        init();
        while (1)
        {
            string s;
            cin >> s;
        #ifdef _GEANY
            cerr << s << endl;
        #endif
            if (s == "turn")
            {
                move();
            }
            else if (s == "move")
            {
                readMove();
            }
            else if (s == "bad")
            {
                badError();
                break;
            }
            else
                break;
        #ifdef _GEANY
            cerr << "----------------------------------------------------------------------------------------" << endl;
        #endif
        }
    }
    
    ~Client ()
    {
        delete strategy;
    }
};

#endif
