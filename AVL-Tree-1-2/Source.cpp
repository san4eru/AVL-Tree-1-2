#include <iostream>

using namespace std;

struct Node
{
	int Key;
	int Count;
	int bal;
	Node* Left;
	Node* Right;

	Node (int x) {
		Key = x;
		Count = 1;
		Left = NULL;
		Right = NULL;
		bal = 0;
	}
};

class TREE {
private:
	bool ChangeH;
	Node* Tree;
public:
	TREE() { Tree = NULL; ChangeH = false; }
	void Search(int, Node*&);
	void Vyvod(Node*&, int);
	Node*& GetTree() { return Tree; }

	Node* RR(Node*&);
	Node* LL(Node*&);

	Node* RL(Node*&);
	Node* LR(Node*&);
};

void main()
{
	system("chcp 1251>null");

	TREE A;
	int n, el;

	/*cout << "Количество вершин в дереве: ";
	cin >> n;
	cout << "Информационные поля вершин дерева: \n";
	for (i = 1; i <= n; i++)
	{
		cin >> el; A.Search(el, A.GetTree());
	}*/

	int newnum[7] = { 4,5,7,2,1,3,6 };
	
	for (int i = 0; i < 7; i++)
	{
		A.Search(newnum[i], A.GetTree());
	}

	cout << "АВЛ-дерево:\n"; A.Vyvod(A.GetTree(), 0);
}

Node* TREE::RR(Node*& p) {
	Node* pR = p->Right;
	p->Right = pR->Left;
	pR->Left = p; 
	p->bal = 0;
	return pR;
}
Node* TREE::LL(Node*& p) {
	Node* pL = p->Left;
	p->Left = pL->Right;
	pL->Right = p;
	p->bal = 0;
	return pL;
}

Node* TREE::RL(Node*& p) {
	Node* pR = p->Right;
	Node* pRL = pR->Left;
	pR->Left = pRL->Right;
	pRL->Right = pR;
	p->Right = pRL->Left;
	pRL->Left = p;
	
	if (pRL->bal == 1)
		p->bal = -1;
	else 
		p->bal = 0;
	
	if (pRL->bal == -1)
		pR->bal = 1;
	else 
		pR->bal = 0;
	
	return pRL;
}
Node* TREE::LR(Node*& p) {
	Node* pL = p->Left;
	Node* pLR = pL->Right;
	pL->Right = pLR->Left;
	pLR->Left = pL;
	p->Left = pLR->Right;
	pLR->Right = p;
	
	if (pLR->bal == -1)
		p->bal = 1;
	else 
		p->bal = 0;
	
	if (pLR->bal == 1)
		pL->bal = -1;
	else 
		pL->bal = 0;

	return pLR;
}

void TREE::Search(int x, Node*& p) {
	ChangeH = false;
	if (p == NULL) {
		p = new Node(x);
		ChangeH = true;
	}
	else if (x <= p->Key) {
		Search(x, p->Left);
		if (ChangeH == true) {
			if (p->bal == 1) {
				p->bal = 0;
				ChangeH = false;
			}
			else if (p->bal == 0) {
				p->bal = -1;
			}
			else if (p->bal == -1) {
				if (p->Left->bal == -1)
					p = LL(p);
				else
					p = LR(p);

				p->bal = 0;
				ChangeH = false;
			}
		}
	}
	else if (x > p->Key) {
		Search(x, p->Right);
		if (ChangeH == true) {
			if (p->bal == -1) {
				p->bal = 0;
				ChangeH = false;
			}
			else if (p->bal == 0) {
				p->bal = 1;
			}
			else if (p->bal == 1) {
				if (p->Right->bal == 1)
					p = RR(p);
				else
					p = RL(p);

				p->bal = 0;
				ChangeH = false;
			}
		}
	}
}

void TREE::Vyvod(Node*& w, int l) {
	int i;

	if (w != NULL)
	{
		Vyvod(w->Right, l + 1);
		
		for (i = 1; i <= l; i++) 
			cout << "   ";
		cout << w->Key << endl;
		
		Vyvod(w->Left, l + 1);
	}
}