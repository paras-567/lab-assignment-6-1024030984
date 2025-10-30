#include <iostream> 
using namespace std; 
 
struct DNode { 
    int v; 
    DNode* p; 
    DNode* n; 
    DNode(int val) : v(val), p(nullptr), n(nullptr) {} 
}; 
 
struct CNode { 
    int v; 
    CNode* n; 
    CNode(int val) : v(val), n(nullptr) {} 
}; 
 
void insDNode(DNode*& h, DNode*& t, int v) { 
    DNode* nn = new DNode(v); 
    if (!h) { 
        h = t = nn; 
    } else { 
        nn->p = t; 
        t->n = nn; 
        t = nn; 
    } 
} 
 
int sizeDLL(DNode* h) { 
    int c = 0; 
    DNode* curr = h; 
    while (curr) { 
        c++; 
        curr = curr->n; 
    } 
    return c; 
} 
 
void insCNode(CNode*& l, int v) { 
    CNode* nn = new CNode(v); 
    if (!l) { 
        l = nn; 
        l->n = l; 
    } else { 
        nn->n = l->n; 
        l->n = nn; 
        l = nn;  
    } 
} 
 
int sizeCLL(CNode* l) { 
    if (!l) return 0; 
    int c = 0; 
    CNode* h = l->n; 
    CNode* curr = h; 
    do { 
        c++; 
        curr = curr->n; 
    } while (curr != h); 
    return c; 
} 
 
void dispDLL(DNode* h) { 
    DNode* curr = h; 
    cout << "DLL: "; 
    while (curr) { 
        cout << curr->v << " -> "; 
        curr = curr->n; 
    } 
    cout<<endl; 
} 
 
void dispCLL(CNode* l) { 
    if (!l) { 
        cout << "CLL: Empty.\n"; 
        return; 
    } 
    CNode* h = l->n; 
    CNode* c = h; 
    cout << "CLL: "; 
    do { 
        cout << c->v << " -> "; 
        c = c->n; 
    } while (c != h); 
    cout << h->v << '\n'; 
} 
 
int main() { 
    DNode* dHead = nullptr; 
    DNode* dTail = nullptr; 
    CNode* cLast = nullptr; 
 
    insDNode(dHead, dTail, 81); 
    insDNode(dHead, dTail, 42); 
    insDNode(dHead, dTail, 13); 
    insDNode(dHead, dTail, 74); 
    insDNode(dHead, dTail, 25); 
 
    insCNode(cLast, 10); 
    insCNode(cLast, 92); 
    insCNode(cLast, 63); 
    insCNode(cLast, 14); 
    insCNode(cLast, 55); 
    insCNode(cLast, 36); 
    insCNode(cLast, 77); 
 
    dispDLL(dHead); 
    cout << "DLL Size: " << sizeDLL(dHead) << "\n"; 
 
    cout << "\n"; 
 
    dispCLL(cLast); 
    cout << "CLL Size: " << sizeCLL(cLast) << "\n"; 
return 0; 
} 
