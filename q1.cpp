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
 
DNode* dll_f(DNode* h, int t) { 
    DNode* c = h; 
    while (c && c->v != t) c = c->n; 
    return c; 
} 
 
void dll_disp(DNode* h) { 
    if (!h) { cout << "List Empty.\n"; return; } 
    DNode* c = h; 
    cout << "DLL: "; 
    while (c) { 
        cout << c->v << (c->n ? " <-> " : ""); 
        c = c->n; 
    } 
    cout << endl; 
} 
 
void dll_iF(DNode*& h, DNode*& t, int v) { 
    DNode* nn = new DNode(v); 
    if (!h) { h = t = nn; } 
    else { nn->n = h; h->p = nn; h = nn; } 
    cout << v << " Inserted Front.\n"; 
} 
 
void dll_iL(DNode*& h, DNode*& t, int v) { 
    DNode* nn = new DNode(v); 
    if (!t) { h = t = nn; } 
    else { nn->p = t; t->n = nn; t = nn; } 
    cout << v << " Inserted Back.\n"; 
} 
     
void dll_iA(DNode*& h, DNode*& t, int v, int target) { 
    DNode* trg = dll_f(h, target); 
    if (!trg) { cout << "Target " << target << " Not Found.\n"; return; } 
 
    if (trg == t) { dll_iL(h, t, v); return; } 
 
    DNode* nn = new DNode(v); 
    nn->p = trg; 
    nn->n = trg->n; 
    trg->n->p = nn; 
    trg->n = nn; 
    cout << v << " Inserted After " << target << ".\n"; 
} 
 
void dll_iB(DNode*& h, DNode*& t, int v, int target) { 
    DNode* trg = dll_f(h, target); 
    if (!trg) { cout << "Target " << target << " Not Found.\n"; return; } 
 
    if (trg == h) { dll_iF(h, t, v); return; } 
     
    DNode* nn = new DNode(v); 
    nn->n = trg; 
    nn->p = trg->p; 
    trg->p->n = nn; 
    trg->p = nn; 
    cout << v << " Inserted Before " << target << ".\n"; 
} 
 
void dll_del(DNode*& h, DNode*& t, int target) { 
    DNode* trg = dll_f(h, target); 
    if (!trg) { cout << target << " Not Found.\n"; return; } 
 
    if (trg->p) trg->p->n = trg->n; 
    else h = trg->n; 
 
    if (trg->n) trg->n->p = trg->p; 
    else t = trg->p; 
     
    delete trg; 
    cout << target << " Deleted.\n"; 
} 
 
void dll_srch(DNode* h, int t) {  
    cout << t << (dll_f(h, t) ? " Found.\n" : " Not Found.\n"); 
} 
 
void dll_clr(DNode*& h, DNode*& t) { 
    DNode* c = h; 
    while (c) { DNode* n = c->n; delete c; c = n; } 
    h = t = nullptr; 
} 
 
CNode* cll_f(CNode* l, int t, CNode*& p) { 
    if (!l) return nullptr; 
    CNode* h = l->n; 
    CNode* c = h; 
    p = l; 
    do { 
        if (c->v == t) return c; 
        p = c; 
        c = c->n; 
    } while (c != h); 
    return nullptr; 
} 
 
void cll_disp(CNode* l) { 
    if (!l) { cout << "List Empty.\n"; return; } 
    CNode* h = l->n;  
    CNode* c = h; 
    cout << "CLL: "; 
    do { 
        cout << c->v << (c != l ? " -> " : " -> (H)"); 
        c = c->n; 
    } while (c != h); 
    cout << endl; 
} 
 
void cll_iF(CNode*& l, int v) { 
    CNode* nn = new CNode(v); 
    if (!l) { l = nn; l->n = l; }  
    else { nn->n = l->n; l->n = nn; }      
    cout << v << " Inserted Front.\n"; 
} 
 
void cll_iL(CNode*& l, int v) { 
    cll_iF(l, v);  
    l = l->n;  
    cout << v << " Inserted Back.\n";  
} 
     
void cll_iA(CNode*& l, int v, int t) { 
    CNode *p = nullptr, *trg = cll_f(l, t, p); 
    if (!trg) { cout << "Target " << t << " Not Found.\n"; return; } 
 
    CNode* nn = new CNode(v); 
    nn->n = trg->n; 
    trg->n = nn; 
    if (trg == l) l = nn;  
     
    cout << v << " Inserted After " << t << ".\n"; 
} 
 
void cll_iB(CNode*& l, int v, int t) { 
    CNode *p = nullptr, *trg = cll_f(l, t, p); 
    if (!trg) { cout << "Target " << t << " Not Found.\n"; return; } 
 
    if (trg == l->n) { cll_iF(l, v); return; } 
     
    CNode* nn = new CNode(v); 
    nn->n = trg; 
    p->n = nn; 
    cout << v << " Inserted Before " << t << ".\n"; 
} 
 
void cll_del(CNode*& l, int t) { 
    CNode *p = nullptr, *trg = cll_f(l, t, p); 
    if (!trg) { cout << t << " Not Found.\n"; return; } 
 
    if (trg == l && l->n == l) { delete l; l = nullptr; cout << t << " Deleted 
(Empty).\n"; return; } 
 
    p->n = trg->n; 
    if (trg == l) l = p; 
     
    delete trg; 
    cout << t << " Deleted.\n"; 
} 
 
void cll_srch(CNode* l, int t) { 
    CNode* p = nullptr; 
    cout << t << (cll_f(l, t, p) ? " Found.\n" : " Not Found.\n"); 
} 
 
void cll_clr(CNode*& l) { 
    if (!l) return; 
    CNode* h = l->n; 
    CNode* c = h; 
    do { CNode* n = c->n; delete c; c = n; } while (c != h); 
    l = nullptr; 
} 
 
void handleDLL(DNode*& h, DNode*& t) { 
    int opt, v, trg; 
    do { 
        cout << "\n--- DLL ---\n1. Ins Front\n2. Ins Back\n3. Ins After\n4. Ins 
Before\n5. Delete\n6. Search\n7. Display\n8. Back\nOpt: "; 
        if (!(cin >> opt)) { cin.clear(); cin.ignore(10000, '\n'); continue; } 
 
        if (opt < 1 || opt > 8) { cout << "Invalid.\n"; continue; } 
        if (opt == 8) return; 
 
        if (opt >= 1 && opt <= 4) { cout << "Val: "; cin >> v; } 
        if (opt == 3 || opt == 4 || opt == 5 || opt == 6) { cout << "Trg: "; cin 
>> trg; } 
 
        switch (opt) { 
            case 1: dll_iF(h, t, v); break; 
            case 2: dll_iL(h, t, v); break; 
            case 3: dll_iA(h, t, v, trg); break; 
            case 4: dll_iB(h, t, v, trg); break; 
            case 5: dll_del(h, t, trg); break; 
            case 6: dll_srch(h, trg); break; 
            case 7: dll_disp(h); break; 
        } 
    } while (true); 
} 
 
void handleCLL(CNode*& l) { 
    int opt, v, trg; 
    do { 
        cout << "\n--- CLL ---\n1. Ins Front\n2. Ins Back\n3. Ins After\n4. Ins 
Before\n5. Delete\n6. Search\n7. Display\n8. Back\nOpt: "; 
        if (!(cin >> opt)) { cin.clear(); cin.ignore(10000, '\n'); continue; } 
 
        if (opt < 1 || opt > 8) { cout << "Invalid.\n"; continue; } 
        if (opt == 8) return; 
 
        if (opt >= 1 && opt <= 4) { cout << "Val: "; cin >> v; } 
        if (opt == 3 || opt == 4 || opt == 5 || opt == 6) { cout << "Trg: "; cin 
>> trg; } 
 
        switch (opt) { 
            case 1: cll_iF(l, v); break; 
            case 2: cll_iL(l, v); break; 
            case 3: cll_iA(l, v, trg); break; 
            case 4: cll_iB(l, v, trg); break; 
            case 5: cll_del(l, trg); break; 
            case 6: cll_srch(l, trg); break; 
            case 7: cll_disp(l); break; 
        } 
    } while (true); 
} 
 
int main() { 
    DNode* dH = nullptr; 
    DNode* dT = nullptr; 
    CNode* cL = nullptr; 
    int opt; 
     
    do { 
        cout << "\n--- Main ---\n1. DLL\n2. CLL\n3. Exit\nSel: "; 
        if (!(cin >> opt)) { cin.clear(); cin.ignore(10000, '\n'); continue; } 
 
        switch (opt) { 
            case 1: handleDLL(dH, dT); break; 
            case 2: handleCLL(cL); break; 
            case 3:  
                cout << "Exiting. Cleanup.\n";  
                dll_clr(dH, dT); 
                cll_clr(cL); 
                return 0; 
            default: cout << "Invalid.\n"; 
        } 
    } while (true); 
} 
 
