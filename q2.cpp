#include <iostream> 
using namespace std; 
 
struct CNode { 
    int v; 
    CNode* n; 
    CNode(int val) : v(val), n(nullptr) {} 
}; 
 
void dispCLL(CNode* l) { 
    if (!l) { 
        cout << "List Empty.\n"; 
        return; 
    } 
    CNode* h = l->n; 
    CNode* c = h; 
 
    cout << "CLL: "; 
    do { 
        cout << c->v << " -> "; 
        c = c->n; 
    } while (c != h); 
     
    cout << h->v <<'\n'; 
} 
 
void insNode(CNode*& l, int v, bool isLast) { 
    CNode* nn = new CNode(v); 
    if (!l) { 
        l = nn; 
        l->n = l; 
    } else { 
        nn->n = l->n; 
        l->n = nn; 
    } 
     
    if (isLast) { 
        l = nn; 
    } 
} 
 
void clr(CNode*& l) { 
    if (!l) return; 
    CNode* h = l->n; 
    CNode* c = h; 
    do {  
        CNode* n = c->n;  
        delete c;  
        c = n;  
    } while (c != h); 
    l = nullptr; 
} 
 
int main() { 
    CNode* last = nullptr; 
     
 
    insNode(last, 10, true); 
    insNode(last, 20, true); 
    insNode(last, 30, true); 
    insNode(last, 40, true); 
    insNode(last, 50, true); 
    insNode(last, 60, true); 
    insNode(last, 70, true); 
 
    dispCLL(last); 
 
    clr(last); 
     
    return 0; 
}
