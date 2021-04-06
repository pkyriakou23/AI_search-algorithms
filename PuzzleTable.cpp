#include "PuzzleTable.h"

#include <string>
#include <sstream>
#include <vector>
#include<iostream>
#include<math.h>
using namespace std;

void print(string s,int a)
{
   /* if(a==0)
        cout<<s<<endl;
    else if(s=="")
    cout<<" "<<a<<endl;
    else*/
     //   cout<<endl<<s<<" "<<a<<endl;
}

PuzzleTable::PuzzleTable(int *boardT,int sizeT)
{
    board=boardT;
    size=sizeT;
    steps=0;
    setPrev(nullptr);

    emptyPos=getEmptyPos();

}

PuzzleTable PuzzleTable::operator= (PuzzleTable o)
{
    board=new int[9];
    for(int i=0;i<9;i++)
        board[i]=o.board[i];

    size=o.size;
    steps=o.steps;
    setPrev(o.prev);
    emptyPos=o.emptyPos;

        return *this;

}

bool PuzzleTable::goUp(PuzzleTable &p)
{

    print("up",getposValue());

    for(int i=0;i<3;i++)
        if(board[i]==0)
            return false;
    p=*this;

    int ep=p.getEmptyPos();
    p.board[ep]=p.board[ep-3];
    p.board[ep-3]=0;
    p.setEmptyPos(p.getEmptyPos());
    p.setsteps(1);
    p.setPrev(this);
    return true;
}

bool PuzzleTable::goDown(PuzzleTable &p)
{
    print("down",getposValue());

      for(int i=6;i<9;i++)
        if(board[i]==0)
            return false;
    p=*this;
    int ep=p.getEmptyPos();
    p.board[ep]=p.board[ep+3];
    p.board[ep+3]=0;
    p.setEmptyPos(p.getEmptyPos());
    p.setsteps(3);
    p.setPrev(this);
    return true;
}

bool PuzzleTable::goRight(PuzzleTable &p)
{

    print("right",getposValue());

    for(int i=2;i<9;i+=3)
        if(board[i]==0)
            return false;
    p=*this;

    int ep=p.getEmptyPos();
    p.board[ep]=p.board[ep+1];
    p.board[ep+1]=0;
    p.setEmptyPos(p.getEmptyPos());

    p.setsteps(2);
    p.setPrev(this);
    return true;
}

bool PuzzleTable::goLeft(PuzzleTable &p)
{

    print("left",getposValue());

      for(int i=0;i<7;i+=3)
        if(board[i]==0)
            return false;
    p=*this;
    int ep=p.getEmptyPos();
    p.board[ep]=p.board[ep-1];
    p.board[ep-1]=0;
    p.setEmptyPos(p.getEmptyPos());


    p.setsteps(4);
    p.setPrev(this);
    return true;
}
int PuzzleTable::getEmptyPos()
{
   for(int i=0;i<9;i++)
    if(board[i]==0)
        return i;
}


bool PuzzleTable::isFinal()
{
    for(int i=0;i<8;i++)
        if(board[i]!=i+1)
            return false;
    return true;
}

bool PuzzleTable::operator==(const PuzzleTable& s)
{
    return (board==s.board);
}

int PuzzleTable::heuristic(bool a)
{

        int count=0;
        for(int i=0;i<8;i++)
            if(board[i]!=i+1)
                count++;
        count+=board[8]==0?0:1;
        if(!a)
        {return count;}
        return count+=getDepth();

}

int PuzzleTable::getDepth()
{
    int counter =0;
    PuzzleTable *p = this;
    while (p->prev!=nullptr)
    {
        p=p->prev;
        counter++;
    }
    return counter;

}

vector <PuzzleTable *>  PuzzleTable::expand()
{

    vector <PuzzleTable *> children;
    PuzzleTable *child;
    child = new PuzzleTable(*this);
    if (goUp(*child))
        children.push_back(child);
    else
        delete child;
    child = new PuzzleTable(*this);
    if (goDown(*child))
        children.push_back(child);
    else
        delete child;
    child = new PuzzleTable(*this);
    if (goLeft(*child))
        children.push_back(child);
    else
        delete child;
    child = new PuzzleTable(*this);
    if (goRight(*child))
        children.push_back(child);
    else
        delete child;

    return children;

}


