#ifndef PUZZLETABLE_H
#define PUZZLETABLE_H
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class PuzzleTable
{
    public:
        PuzzleTable(string pos,int x,int y);
        PuzzleTable();
        bool goUp(PuzzleTable &p);
        bool goDown(PuzzleTable &p);
        bool goRight(PuzzleTable &p);
        bool goLeft(PuzzleTable &p);
        void setXY(int x);
        void setPrev(PuzzleTable *p);
        PuzzleTable *getPrev(){ return prev;}
        string getposValue();
        string getsteps();
        void setposValue(string s);
        void setsolutionSteps(string s){solutionSteps=s;}
        string getsolutionSteps();
        bool isFinal();
        int getDepth(){ return depth;}
        int getEmptyPos();
        vector <PuzzleTable *> expand();
        void setsteps(string s){steps=s;}
        PuzzleTable operator= (PuzzleTable o);

    private:
        int WIDTH;
        int HEIGHT;
        int depth;
        string posValue;                 //n*m character value shows the status of puzzle
        string solutionSteps;              // moves
        string steps;
        PuzzleTable *prev;


};

#endif // PUZZLETABLE_H
