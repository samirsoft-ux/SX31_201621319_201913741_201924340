#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>

#define SIZE 10
template<typename T>
class queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue(int size = SIZE){
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    ~queue(){
        delete[] arr;
    }

    void dequeue(){
        front = (front + 1) % capacity;
        count--;
    }
    void enqueue(T item){
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
    //para el tamaño
    int size(){
        return count;
    }
    bool isEmpty(){
        return (size() == 0);
    }
    bool isFull(){
        return (size() == capacity);
    }
};
#endif // QUEUE_H
