#include <iostream>
#include <vector>

using namespace std;

enum MatchResult { WHITE_WIN, BLACK_WIN, WHITE_FORFEIT, BLACK_FORFEIT, STALEMATE, WHILE_RESIGN, BLACK_RESIGN };
enum Color { WHITE, BLACK };

class Person
{
    public:
        string name;
        string mobile;
        string email;
};

class Account
{
    public:
        string username;
        string password;
        uint32_t rating;
};

class Position
{
    public:
        uint8_t x;
        uint8_t y;
};



class Piece
{
    public:
        uint8_t id;
        Color color;
        bool is_killed;

        bool IsValidMove();
        //bool makeMove(Move move);
};

class Cell
{
    public:
        uint8_t id;
        Color color;
        Piece piece;
        bool is_empty;
        Position position;
};

class Player : public Person
{
    public:
        uint32_t id;
        Color color;
        Account account;
        bool turn;

        bool playerMove(Cell src, Cell dst, Piece piece);
};

class Move
{
    public:
        Player player;
        Cell src;
        Cell dest;
        bool is_kill;
};

class Pawn : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};

class Rook : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};

class Bishop : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};

class Knight : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};

class Queen : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};

class King : public Piece
{
    public:
        string name;

        bool IsValidMove();
        bool makeMove(Move move);
};


class Chess
{
    public:
        Player player_1;
        Player player_2;
        vector<vector<Cell> > board;
        vector<Move> moves;
        MatchResult result;

        Chess(){
            // create all the pieces & place them in default position
            // assign random color to players
            return;
        }
        vector<Move> getMoves();
        MatchResult getMatchResult();
        void displayBoard();
        void resetBoard();
};
