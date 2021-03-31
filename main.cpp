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

///*
PuzzleTable *DFS2(PuzzleTable *initial, long long &examined, long long &mem)
{
    stack<PuzzleTable *> agenda;
    unordered_map <string ,PuzzleTable *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {

        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        PuzzleTable *s = agenda.top();
        agenda.pop();
       cout<<"value "<<s->getposValue()<<" "<<s->getsteps()<<endl;
       // cout<<closed.size()<<endl;
        if (closed.count(s->getposValue())==0)
        {
            examined++;
         //   cout<<s->isFinal()<<endl;
            if (s->isFinal())
            {
                cout<<s->getposValue();
             return s;}
            pair<string,PuzzleTable *> k (s->getposValue(),s);
            closed.insert(k);
            vector<PuzzleTable *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getposValue())==0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

//*/

int main()
{
    long long mem,examined;
    PuzzleTable a("852367410",3,3);
    PuzzleTable *b;
    PuzzleTable *s=&a;
    b=DFS2(s,examined,mem);
    cout<<"finish";
    cout<<b->getposValue()<<" sol:"<<b->getsolutionSteps();
    //<<" depth:"<<s->getDepth();

}
