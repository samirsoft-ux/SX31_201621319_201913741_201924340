#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>


// define default capacity of the queue
#define SIZE 10
template<typename T>
class queue
{
    int *arr;   	// array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;  	// front points to front element in the queue (if any)
    int rear;   	// rear points to last element in the queue
    int count;  	// current size of the queue

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
