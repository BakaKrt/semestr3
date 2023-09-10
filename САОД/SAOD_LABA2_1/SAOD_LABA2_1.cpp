#include <iostream>
#include <vector>

using namespace std;

class bin_tree {
public:
    int x = NULL;
    bin_tree* left = NULL;
    bin_tree* right = NULL;

    bin_tree *add(bin_tree *tree,int in) {
        if (tree == NULL) {
            tree = new bin_tree;
            tree->left = NULL;
            tree->right = NULL;
            tree->x = in;
        }
        else if (in < tree->x) {
            tree->left = add(tree->left, in);
            tree->left->x = in;
        }
        else {
            tree->right = add(tree->right, in);
            tree->right->x = in;
        }
        return tree;
    }
    /*~bin_tree() {

    }*/
} root;

double sr_mat(bin_tree A) {
    vector<int> znach = {};
    cout << A.x << endl;
    while (A.x != NULL) {
        if (A.left != NULL) {
            cout << "левое не пустое" << endl;
            znach.push_back(A.left->x);
        }
        else if (A.right != NULL) {
            cout << "правое не пустое" << endl;
            znach.push_back(A.right->x);
        }
        cout << "Ты в пиве\n";
    }
    double rez=0;
    for (const auto& a : znach) {
        rez += a;
    }
    cout << rez;
    return rez / znach.size();
}

int main()
{
    setlocale(0, "");
    root.x = -1;
    bin_tree a;
    root.add(&a, 12);
    root.add(&a, -1);
    printf("Left: %d \t Right: %d\n", a.left->x, a.right->x);
    root.add(a.left, 100);
    root.add(a.left->left, 1);
    cout << sr_mat(root);
}
