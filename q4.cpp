#include <iostream> 
#include <string> 
using namespace std; 
struct DNode { 
char v; 
DNode* p; 
DNode* n; 
DNode(char val) : v(val), p(nullptr), n(nullptr) {} 
}; 
void insNode(DNode*& h, DNode*& t, char v) { 
DNode* nn = new DNode(v); 
if (!h) { 
h = t = nn; 
} else { 
nn->p = t; 
t->n = nn; 
t = nn; 
    } 
} 
 
bool isPal(DNode* h, DNode* t) { 
    if (!h) return true; 
 
    DNode* l = h; 
    DNode* r = t; 
 
    while (l != r && l->p != r) { 
        if (l->v != r->v) { 
            return false; 
        } 
        l = l->n; 
        r = r->p; 
    } 
    return true; 
} 
 
void disp(DNode* h) { 
    DNode* curr = h; 
    cout << "List: "; 
    while (curr) { 
        cout << curr->v; 
        if (curr->n) cout << " <-> "; 
        curr = curr->n; 
    } 
    cout << "\n"; 
} 
 
void clr(DNode*& h, DNode*& t) { 
    DNode* curr = h; 
    while (curr) { 
        DNode* next = curr->n; 
        delete curr; 
        curr = next; 
    } 
    h = t = nullptr; 
} 
 
void testPal(const string& s) { 
    DNode* h = nullptr; 
    DNode* t = nullptr; 
     
    for (char c : s) { 
insNode(h, t, c); 
} 
disp(h); 
bool res = isPal(h, t); 
cout << "Palindrome? " << (res ? "YES" : "NO") << "\n\n"; 
clr(h, t); 
} 
int main() { 
testPal("MADAM"); 
testPal("RACECAR"); 
testPal("HELLO"); 
return 0; 
} 
