#ifndef PUZZLETABLE_H
#define PUZZLETABLE_H
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class PuzzleTable
{
    public:
        PuzzleTable(int *boardT,int sizeT);
        PuzzleTable();

        bool goUp(PuzzleTable &p);
        bool goDown(PuzzleTable &p);
        bool goRight(PuzzleTable &p);
        bool goLeft(PuzzleTable &p);

        void setPrev(PuzzleTable *p){prev=p;}
        void setsteps(int s){steps=steps*10+s;}
        void setEmptyPos(int s){emptyPos=s;}
        void setHvalue(double n){hvalue=n;}


        PuzzleTable *getPrev(){ return prev;}
        double getHvalue(){return hvalue;}
        int getsteps();
        int getEmptyPos();
        int getDepth();
        int getposValue()
        {
            int t=board[0];
            for(int i=1;i<9;i++)
                t=t*10+board[i];
            return t;
        }
        int heuristic(bool);



        bool isFinal();

        vector <PuzzleTable *> expand();

        PuzzleTable operator= (PuzzleTable o);
        bool operator==(const PuzzleTable& s) ;


    private:
        int size;
        PuzzleTable *prev;
        int *board;
        int emptyPos;
        double hvalue;
        int steps;  //1=up 2=right 3=down 4= left



};
class myComparator
{
public:
    int operator() (PuzzleTable *p1 , PuzzleTable *p2) const
    {
        return p1->getHvalue()>p2->getHvalue();
    }
};

#endif // PUZZLETABLE_H
