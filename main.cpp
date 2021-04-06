#include <iostream>
#include<stack>
#include<vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include "PuzzleTable.h"
using namespace std;


PuzzleTable *DFS(PuzzleTable *initial, long long &examined, long long &mem)
{
    stack<PuzzleTable *> agenda;
    unordered_map < int  ,PuzzleTable *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {

        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        PuzzleTable *s = agenda.top();
        agenda.pop();


        if (closed.count(s->getposValue())==0)
        {
            examined++;

            if (s->isFinal())
                return s;
            pair< int ,PuzzleTable *> k (s->getposValue(),s);
            closed.insert(k);
            vector<PuzzleTable *> children =s->expand();


            for (unsigned int i=0;i<children.size();i++)
            {
              if (closed.count(children[i]->getposValue())==0)
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}


PuzzleTable *BestFS_Astar(PuzzleTable *initial, long long &examined, long long &mem,bool aStar)
{
    priority_queue <PuzzleTable*, vector<PuzzleTable *>,myComparator > agenda;
    unordered_map <int,PuzzleTable*> closed;
    agenda.push(initial);
    examined = 0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        PuzzleTable *s = agenda.top();
        agenda.pop();

        if (closed.count(s->getposValue())==0)
        {
            examined++;
            if (s->isFinal())
                return s;
            pair<int,PuzzleTable*> k (s->getposValue(),s);
            closed.insert(k);
            vector<PuzzleTable *> children = s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (closed.count(children[i]->getposValue())==0)
                {
                    children.at(i)->setHvalue(children.at(i)->heuristic(aStar));
                    agenda.push(children.at(i));
                }
            }
        }
    }
    return nullptr;
}


PuzzleTable *BFS(PuzzleTable *initial, long long &examined, long long &mem)
{
    queue<PuzzleTable *> agenda;
    unordered_map <int,PuzzleTable *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        PuzzleTable *s = agenda.front();
        agenda.pop();
        if (closed.count(s->getposValue())==0)
        {
            examined++;
            if (s->isFinal())
                return s;
            pair<int,PuzzleTable *> k (s->getposValue(),s);
            closed.insert(k);
            vector<PuzzleTable *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getposValue())==0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}



int main()
{
    long long mem,examined;

   int board[9]={3,6,0,1,4,2,7,5,8};

  /*
    int board[9];
    for(int i=0;i<9;i++)
        cin>>board[i];
 //   */

    PuzzleTable a(board,3);
    PuzzleTable *b;
    PuzzleTable *s=&a;

    cout<<endl<<"DFS: ";
    b=DFS(s,examined,mem);
    if(b==nullptr)
        cout<<"DEN EXEI LISI"<<endl;
    else
        cout<<b->getposValue()<<" ex:"<<examined<<" mem:"<<mem;


    cout<<endl<<"BFS: ";
    b=BFS(s,examined,mem);
    if(b==nullptr)
        cout<<"DEN EXEI LISI"<<endl;
   else
        cout<<b->getposValue()<<" ex:"<<examined<<" mem:"<<mem;


    cout<<endl<<"BestFS: ";
    b=BestFS_Astar(s,examined,mem,false);
    if(b==nullptr)
        cout<<"DEN EXEI LISI"<<endl;
    else
        cout<<b->getposValue()<<" ex:"<<examined<<" mem:"<<mem;

    cout<<endl<<"A*: ";
    b=BestFS_Astar(s,examined,mem,true);

    if(b==nullptr)
        cout<<"DEN EXEI LISI"<<endl;
    else
        cout<<b->getposValue()<<" ex:"<<examined<<" mem:"<<mem<<endl;

}
