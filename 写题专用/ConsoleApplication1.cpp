#include<iostream>
#include<string>
using namespace std;
struct tree {
	int data;
	tree* lchild, * rchild;
};
void create_node(tree* t, int x) {  //在指针t处生成一个新的节点，内容为x
	t = new tree;
	t->data = x;
	t->lchild = NULL;
	t->rchild = NULL;
}
void create_pre(tree* t) {
	int x;
	cin >> x;
	if (x == 0)return;
	else {
		create_node(t, x);
		create_pre(t->lchild);
		create_pre(t->rchild);
	}
}
void prt(tree* p) {
	if (!p) { return; }
        cout << p->data;
	    prt(p->lchild);
	    prt(p->rchild);
		cout << endl;
	
}
int main() {
	int n,h;
	cin >> n;
	tree* t = new tree;
	cin >> h;
	create_node(t, h);
	for (int i = 1; i < n; i++) {
		create_pre(t);
	}
	prt(t);
	return 0;
}