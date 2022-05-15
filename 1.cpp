#include <vector>
#include <iostream>
#include <deque>

using std::vector;
using std::deque;
using std::cin;
using std::cout; 
using std::endl;

class node{
    public:
        int val;
        vector<node*> neighbors{};

        node(int val): val(val){
        }

        void addNeighbor(node *n){
            neighbors.push_back(n);
        }

};

void DFS(node *rootnode){
    deque<node*> DFS{rootnode};
    vector<int> seen;
    vector<int> sequence;

    seen.push_back(rootnode->val);

    while (!DFS.empty())
    {
        node* curr = DFS.back();
        DFS.pop_back();
        for(auto i: curr->neighbors){
            bool skip = false;
            for(int j : seen){
                if (i->val == j) skip = true;
            }
            if(!skip){
                DFS.push_back(i);
                seen.push_back(i->val);
            }
        }
        sequence.push_back(curr->val);

    }

    for (auto i : sequence) std::cout << i << " " << std::endl;
    
}

int main()
{
    node n0(5);
    node n1(6);


    n0.addNeighbor(&n1);


    DFS(&n0);

    return 0;
}
