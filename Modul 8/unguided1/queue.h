#ifndef QUEUE_H
#define QUEUE_H

typedef int infotipe;

struct Queue {
    infotipe info[5]; 
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotipe x);
infotipe dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
