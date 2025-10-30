#include <iostream> 
using namespace std; 
 
struct SNode { 
    int v; 
    SNode* n; 
    SNode(int val) : v(val), n(nullptr) {} 
}; 
 
void insNode(SNode*& h, int v) { 
    SNode* nn = new SNode(v); 
    nn->n = h; 
    h = nn; 
} 
 
bool isCLL(SNode* h) { 
    if (!h || !h->n) return false; 
 
    SNode* s = h;  
    SNode* f = h->n;  
 
    while (f && f->n) { 
        if (s == f) return true;  
 
        s = s->n; 
        f = f->n->n; 
    } 
    return false; 
} 
 
void disp(SNode* h, int limit) { 
    SNode* curr = h; 
    cout << "List: "; 
    for (int i = 0; i < limit && curr; ++i) { 
        cout << curr->v; 
        if (curr->n && i < limit - 1) cout << " -> "; 
        curr = curr->n; 
    } 
    cout << "\n"; 
} 
 
int main() { 
 
    SNode* h1 = nullptr; 
    insNode(h1, 40); 
    insNode(h1, 30); 
    insNode(h1, 20); 
    insNode(h1, 10); 
     
    disp(h1, 4); 
    bool res1 = isCLL(h1); 
    cout << "Circular? " << (res1 ? "YES" : "NO") << "\n\n"; 
    
 
   
    SNode* h2 = new SNode(100); 
    SNode* n2 = new SNode(200); 
    SNode* n3 = new SNode(300); 
    SNode* n4 = new SNode(400); 
 
    h2->n = n2; 
    n2->n = n3; 
    n3->n = n4; 
    n4->n = h2;  
 
    disp(h2, 5);  
    bool res2 = isCLL(h2); 
    cout << "Circular? " << (res2 ? "YES" : "NO") << "\n\n"; 
  
     
    return 0; 
} 
