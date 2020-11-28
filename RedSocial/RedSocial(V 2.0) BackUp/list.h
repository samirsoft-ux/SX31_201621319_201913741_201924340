#ifndef LIST_H
#define LIST_H
template<typename T>
class List {
    struct Node {
        T elem;
        Node* next;

        Node(float elem, Node* next=nullptr): elem(elem), next(next) {}
    };

    Node*   head;
    int     len;

public:
    List(): head(nullptr), len(0) {}
    ~List(){
        while (head != nullptr) {
                Node* aux = head;
                head = head->next;
                delete aux;
            }
    }

    int     size        (){
        return len;
    }

    void    addFirst    (T elem){
        head = new Node(elem, head);
        len++;
    }

    void    removeFirst (){
        if (len > 0) {
                Node* aux = head;
                head = head->next;
                delete aux;
                --len;
            }
    }
    void    removePos   (int pos){
        if (pos < 0 || pos >= len) return;
            if (pos == 0) {
                removeFirst();
            }
            else {
                Node* aux = head;
                for (int i = 1; i < pos; ++i) {
                    aux = aux->next;
                }
                Node* aux2 = aux->next;
                aux->next = aux2->next;
                delete aux2;
                --len;
            }
    }
    void    removeLast  (){
        removePos(len-1);
    }
};

#endif // LIST_H
