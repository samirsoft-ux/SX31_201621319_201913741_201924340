#ifndef LIST_H
#define LIST_H
template<typename T>
class Lista {
    struct Node {
        T elem;
        Node* next;

        Node(float elem, Node* next=nullptr): elem(elem), next(next) {}
    };

    Node*   head;
    int     len;

public:
    Lista(): head(nullptr), len(0) {}
    ~Lista(){
        while (head != nullptr) {
                Node* aux = head;
                head = head->next;
                delete aux;
            }
    }

    int     size        (){
        return len;
    }
    /*bool    empty       (){
        return len == 0;
    }*/

    void    addFirst    (T elem){
        head = new Node(elem, head);
        len++;
    }
    /*void    addPos      (T elem, int pos){
        if (pos < 0 || pos > len) return;
            if (pos == 0) {
                addFirst(elem);
            } else {
                Node* aux = head;
                for (int i = 1; i < pos; ++i) {
                    aux = aux->next;
                }
                aux->next = new Node(elem, aux->next);
                ++len;
            }
    }*/
    /*void    addLast     (T elem){
        addPos(elem, len);
    }*/

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

    /*void    editFirst   (T elem){
        if (len > 0) {
                head->elem = elem;
            }
    }
    void    editPos     (T elem, int pos){
        if (pos < 0 || pos >= len) return;
            Node* aux = head;
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
            aux->elem = elem;
    }
    void    editLast    (T elem){
        editPos(elem, len-1);
    }

    float   getFirst    (){
        if (len > 0) {
                return head->elem;
            } else {
                -.0;
            }
    }
    float   get         (int pos){
        if (pos < 0 || pos >= len) -.0;
            Node* aux = head;
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
            return aux->elem;
    }
    float   getLast     (){
        return get(len-1);
    }

    int     find        (T elem){
        Node* aux = head;
            for (int i = 0; i < len; ++i) {
                if (aux->elem == elem) {
                    return i;
                }
                aux = aux->next;
            }
            return -1;
    }
    int*    findAll     (T elem){}*/
};

#endif // LIST_H
