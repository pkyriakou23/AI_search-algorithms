#include "PuzzleTable.h"

#include <string>
#include <sstream>
#include <vector>
#include<iostream>
using namespace std;


PuzzleTable::PuzzleTable(string pos,int x,int y)
{
    posValue=pos;
    WIDTH=x;
    HEIGHT=y;
    steps="";
    setPrev(nullptr);
    depth=0;
}
PuzzleTable::PuzzleTable()
{
    posValue="";
    WIDTH=0;
    HEIGHT=0;
    steps="";
    setPrev(nullptr);
    depth=0;
}

PuzzleTable PuzzleTable::operator= (PuzzleTable o)
{
        WIDTH=o.WIDTH;
        HEIGHT=o.HEIGHT;
        depth=o.depth;
        posValue=o.posValue;           //n*m character value shows the status of puzzle
        solutionSteps=o.solutionSteps;
        steps=o.steps;        // moves
        prev=o.prev;
        return *this;

}

bool PuzzleTable::goUp(PuzzleTable &p)
{
        for(int i=0;i<WIDTH;i++)
            if(posValue[i]=='0')
                return false;
    p=*this;
    string temp=p.getposValue();
    int i=p.getEmptyPos();
    temp[i]=temp[i-1];
    temp[i-1]='0';
    p.setposValue(temp);
    p.setsteps("up");
    setPrev(this);

    return true;
        return true;
}

bool PuzzleTable::goDown(PuzzleTable &p)
{
    for(int i=HEIGHT*WIDTH-HEIGHT;i<WIDTH*HEIGHT;i++)
        if(posValue[i]=='0')
            return false;
    p=*this;
    string temp=p.getposValue();
    int i=p.getEmptyPos();
    temp[i]=temp[i+WIDTH];
    temp[i+WIDTH]='0';
    p.setposValue(temp);
    p.setsteps("down");
    setPrev(this);

    return true;
    return true;
}

bool PuzzleTable::goRight(PuzzleTable &p)
{
    for(int i=WIDTH-1;i<HEIGHT*WIDTH;i+=WIDTH)
        if(posValue[i]=='0')
            return false;
    p=*this;
    string temp=p.getposValue();
    int i=p.getEmptyPos();
    temp[i]=temp[i+1];
    temp[i+1]='0';
    p.setposValue(temp);
    p.setsteps("right");
    setPrev(this);

    return true;
        return true;
}

bool PuzzleTable::goLeft(PuzzleTable &p)
{
    for(int i=0;i<=HEIGHT*WIDTH-WIDTH;i+=WIDTH)
        if(posValue[i]=='0')
              return false;
    p=*this;
    string temp=p.getposValue();
    int i=p.getEmptyPos();
    temp[i]=temp[i-1];
    temp[i-1]='0';
    p.setposValue(temp);
    p.setsteps("left");
    setPrev(this);

    return true;
}
int PuzzleTable::getEmptyPos()
{
    for(int i=0;i<WIDTH*HEIGHT;i++)
        if(posValue[i]=='0')
            return i;
    return -1;
}

string PuzzleTable::getposValue()
{
    return posValue;

}
void PuzzleTable::setposValue(string s)
{
    posValue=s;
}

string PuzzleTable::getsteps()
{
    return steps;
}

string PuzzleTable::getsolutionSteps()
{
    int count=0;
    PuzzleTable *p=this;
    while(p!=nullptr)
    {
        cout<<solutionSteps<<endl;
    count++;
   solutionSteps = p->getsteps()+" "+solutionSteps;
        p = p->getPrev();

    }
    depth=count;
   return solutionSteps;
}

bool PuzzleTable::isFinal()
{
    string temp="";
    for(int i=1;i<WIDTH*HEIGHT;i++)
        temp+=to_string(i);
    temp+='0';
    if(posValue==temp)
        return true;
    return false;
}

void PuzzleTable::setPrev(PuzzleTable *p)
{
    prev=p;

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
    child = new PuzzleTable(*this);
    return children;

}


