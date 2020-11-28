#ifndef AVL_H
#define AVL_H

#include <functional>

using namespace std;

template<typename T, typename R = T, T NONE = 0>
class AVLBST {
    struct Node {
        T       element;
        Node* left;
        Node* right;
        int     height;

        Node(T element)
            : element(element), height(0),
            left(nullptr), right(nullptr) {}
    };

    Node* root;
    function<R(T)>  key;
    int             len;
public:
    AVLBST(function<R(T)> key = [](T a) { return a; })
        : key(key), root(nullptr), len(0) {}
    ~AVLBST() { clear(root); }
    int height() { return height(root); }
    int size() { return len; }
    void clear() { clear(root); len = 0; }

    void add(T elem) { add(root, elem); }
    void remove(R val) { remove(root, val); }

    T find(R val) { return find(root, val); }
    T greaterThan(R val) { return greaterThan(root, val); }

    void inOrder(function<void(T)> proc) { inOrder(root, proc); }
    void inOrderRev(function<void(T)> proc) { inOrderRev(root,proc);}

private:
    void    clear(Node*& node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }
    int     height(Node* node) {
        return node == nullptr ? -1 : node->height;
    }
    void    add(Node*& node, T elem) {
        if (node == nullptr) {
            node = new Node(elem);
            ++len;
        }
        else {
            if (key(elem) < key(node->element)) {
                add(node->left, elem);
            }
            else {
                add(node->right, elem);
            }
            balance(node);
        }
    }
    T       max(Node*& node) {
        if (node->right == nullptr) {
            auto aux = node;
            node = node->left;
            auto auxElem = aux->element;
            delete aux;
            return auxElem;
        }
        else {
            auto auxElem = max(node->right);
            balance(node);
            return auxElem;
        }
    }
    void    removeAux(Node*& node) {
        if (node->left == nullptr) {
            auto aux = node;
            node = node->right;
            delete aux;
        }
        else {
            node->element = max(node->left);
        }
    }
    void    remove(Node*& node, R val) {
        if (node != nullptr) {
            if (val == key(node->element)) {
                removeAux(node);
            }
            else {
                if (val < key(node->element)) {
                    remove(node->left, val);
                }
                else {
                    remove(node->right, val);
                }
                balance(node);
            }
        }
    }
    T       find(Node* node, R val) {
        if (node == nullptr) {
            return NONE;
        }
        else if (val == key(node->element)) {
            return node->element;
        }
        else if (val < key(node->element)) {
            return find(node->left, val);
        }
        else {
            return find(node->right, val);
        }
    }
    T       greaterThan(Node* node, R val) {
        if (node == nullptr) {
            return NONE;
        }
        else if (val < key(node->element)) {
            return node->element;
        }
        return greaterThan(node->right, val);
    }
    void    inOrder(Node* node, function<void(T)> proc) {
        if (node != nullptr) {
            inOrder(node->left, proc);
            proc(node->element);
            inOrder(node->right, proc);
        }
    }
    //******************************
    void inOrderRev(Node* node, function<void(T)> proc){
        if (node != nullptr) {
            inOrderRev(node->right, proc);
            proc(node->element);
            inOrderRev(node->left, proc);
        }
    }

    void    updateHeight(Node* node) {
        if (node != nullptr) {
            int hl = height(node->left);
            int hr = height(node->right);

            node->height = (hl>hr?hl:hr) + 1;
        }
    }
    void    rotateLeft(Node*& node) {
        Node* aux = node->right;
        node->right = aux->left;
        updateHeight(node);
        aux->left = node;
        updateHeight(aux);
        node = aux;
    }
    void    rotateRight(Node*& node) {
        Node* aux = node->left;
        node->left = aux->right;
        updateHeight(node);
        aux->right = node;
        updateHeight(aux);
        node = aux;
    }
    void    balance(Node*& node) {
        int hl = height(node->left);
        int hr = height(node->right);

        if (hr - hl < -1) {
            hl = height(node->left->left);
            hr = height(node->left->right);
            if (hr > hl) {
                rotateLeft(node->left);
            }
            rotateRight(node);
        }
        else if (hr - hl > 1) {
            hl = height(node->right->left);
            hr = height(node->right->right);
            if (hl > hr) {
                rotateRight(node->right);
            }
            rotateLeft(node);
        }
        else {
            updateHeight(node);
        }
    }
};
#endif // AVL_H
