//https://ide.geeksforgeeks.org/4P0xozfVnM

#include <bits/stdc++.h>
using namespace std;

/*
SuffixTreeNode
    - children
    - suffixLink
    - start, end
    - suffixIndex
*/

struct Node{
    struct Node *children[256];
    struct Node *suffixLink;  //pointer to node via suffix link
    int start, *end; //specifies the edge
    int suffixIndex; //index of suffix for path from root to leaf
};


char text[100]; //input string
Node *root = NULL; //pointer to root
Node *lastNewNode = NULL; 
//points to newly created internal node that is waiting for its suffix link to be set
//this new suffix link will be set in the next extension of same phase

// representation of active point
Node *activeNode = NULL;  
int activeEdge = -1; //char index within string
int activeLength = 0;

//remainingSuffix helps in identifying how many suffix are remaining after rule 3 is applied
int remainingSuffix = 0;
int leafEnd = -1;
int *rootEnd = NULL, *splitEnd = NULL;
int length = -1;

Node *newNode(int start, int *end){
    Node *current = new Node;
    for(int i = 0; i < 256; i++)
        current->children[i] = NULL;
    current->suffixLink = root;
    current->start = start;
    current->end = end;
    current->suffixIndex = -1;
    return current;
}

int edgeLength(Node *current){
    return (*(current->end) - current->start + 1);
}

int walkDown(Node *current){
    //APCFWD --> ap change for walkdown
    int elength = edgeLength(current);
    if(activeLength >= elength){
        //skipcount technique
        activeEdge += elength;
        activeLength -= elength;
        activeNode = current;
        return 1;
    }
    return 0;
}

void extendSuffixTree(int pos){

    //Extension rule 1 ---> extend all the leaves created so far
    leafEnd = pos;
    remainingSuffix ++; //newsuffix is added and its yet to be processed

    lastNewNode = NULL;

    while(remainingSuffix > 0){
        if(activeLength == 0)
            activeEdge = pos; //APCFALZ --> ap change for active length 0

        if(activeNode->children[text[activeEdge]] == NULL){
            //Extension rule 2 --> add new leaf edge
            activeNode->children[text[activeEdge]] = newNode(pos, &leafEnd);

            //new leaf edge created from an existing node, and if there is any node awaiting for its suffixLink to reset; 
            //point suffixLink from last internal node to current activenode
            //then set lastNewNode to NULL indicating no more node is waiting for suffixLink reset
            if(lastNewNode != NULL){
                lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;
            }
        }

        // There is outgoing edge with activeEdge from activeNode
        else{
            //get next node at end of edge starting with activeEdge
            Node *next = activeNode->children[text[activeEdge]];
            if(walkDown(next))
                continue; //start from new activeNode

            //extension rule 3 --> current char being processed is already on edge
            if(text[next->start + activeLength] == text[pos]){
                //if new node is waiting for suffixLink to be set
                if(lastNewNode != NULL && activeNode != root){
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;
                }
                //Trick 3 --
                //stop all the processing and move to next phase
                activeLength++;
                break;
            }

            //when activepoint is in the middle of edge being traversed and current char being processed is not on the edge.
            //Add new internal node and new leaf edge going out of that new node
            //Extension 2 -->
            splitEnd =  new int;
            *splitEnd = next->start + activeLength - 1;
            
            //internal node
            Node *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = next;

            //leaf out of internal node
            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;
            
            //Any internal node in last extension waiting for its suffixLink reset
            if(lastNewNode != NULL){
                lastNewNode->suffixLink = split;
            }
            lastNewNode = split;
        } 
        remainingSuffix--; //one suffix added in tree
        if(activeNode == root && activeLength > 0){
            activeLength--;
            activeEdge = pos - remainingSuffix + 1;
        }
        else if(activeNode != root){
            activeNode = activeNode->suffixLink;
        }
    }
}

//print the suffix tree along with setting suffix index 
void setSuffixIndexByDFS(Node *current, int height){
    if(current == NULL) return;
    if(current->start != -1){
        for(int k = current->start; k <= *(current->end); k++)
            cout<<text[k];
        cout<<"\n";
    }
    int leaf = 1;
    for(int i = 0; i< 256; i++){
        if(current->children[i] != NULL){
            if(leaf == 1 && current->start != -1){
                cout<<"["<<current->suffixIndex<<"]\n";
            }
            leaf = 0;
            setSuffixIndexByDFS(current->children[i], height + edgeLength(current->children[i]));
        }
    }
    if(leaf == 1){
        current->suffixIndex = length - height;
        cout<<"["<<current->suffixIndex<<"]\n";
    }
}

void freeSuffixTreeByPostOrder(Node *n){
    if (n == NULL) return;
    for (int i = 0; i < 256; i++) {
        if (n->children[i] != NULL) {
            freeSuffixTreeByPostOrder(n->children[i]);
        }
    }
    if (n->suffixIndex == -1)
        free(n->end);
    free(n);
}


void buildSuffixTree()
{
    length = strlen(text);
    rootEnd = new int;
    *rootEnd = - 1;
    root = newNode(-1, rootEnd);

    activeNode = root;
    for (int i=0; i<length; i++)
        extendSuffixTree(i);
    
    int labelHeight = 0;
    setSuffixIndexByDFS(root, labelHeight);
 
    //Free the dynamically allocated memory
    freeSuffixTreeByPostOrder(root);
}

int main(){
    strcpy(text, "abcabxabcd$");
    buildSuffixTree();
}