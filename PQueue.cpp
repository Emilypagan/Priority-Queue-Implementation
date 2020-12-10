/** CS515 lab 6
 * File: PQueue.cpp
 * Name: mily pagan
 * Section: 02
 * Date: 10/18/20
 * Collaboration Declaration: piazza help
*/
//default constructor
template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(){
    _size = 0;
    for (int i = 0; i < 101; i++) {
        _array[i] = 0;
    }
}
//construct heap constructor
template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T* items, int size) {
    for (int i = 0; i < size; i++) { // 0   1   2   3   4  ...
        insert(*(items+i));    //[0, 24, 55, 22, 31, ...]
    }
    _size = size;
}
//insert
template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::insert(T value) {
    _size++;
    _array[_size] = value;
    if (_size > 1) {
        this->buildHeap();
    }
}
//return min
template<class T, int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin() {

 return _array[1];
}
//delete min
template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin() {
    for (int i = 1; i < _size; i++) {
        _array[i] = _array[i+1];
    }
    _array[_size] = 0;
    _size = _size - 1;
    this->buildHeap();
}
//empty
template<class T, int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty() {
    if (_size == 0) {
        return true;
    }
    return false;
}
//size
template<class T, int MAX_SIZE>
int PQueue<T, MAX_SIZE>::size() {
 return _size;
}
//build heap
template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap() {
    int firstchildindex = _size;
    int parentindex = _size/2;
    int potentialswitch;
    if (_size % 2 == 0) {
        potentialswitch = firstchildindex;
    } else {
        firstchildindex = firstchildindex - 1;
        if (_array[firstchildindex] <= _array[firstchildindex + 1]) {
            potentialswitch = firstchildindex;
        } else {
            potentialswitch = firstchildindex + 1;
        }
    }
    if (_array[parentindex] > _array[potentialswitch] ) { //55 > 31 - true
        moveDown(potentialswitch);
    }

    int n = firstchildindex - 2;
    while (n > 1) {
        int childindex = n;
        int parentindex = n / 2;
        int potentialswitch;
        if (_array[childindex] <= _array[childindex + 1]) {  //find which child is smallest
            potentialswitch = childindex;
        } else {
            potentialswitch = childindex + 1;
        }
        if (_array[parentindex] > _array[potentialswitch]) { //swap if true
            moveDown(potentialswitch);
            n = firstchildindex - 2;
        } else {
            n = n - 2;
        }

    }

}
//move down
template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int childindex) {
    int parentindex = childindex/2;
    T hold = _array[parentindex];
    _array[parentindex] = _array[childindex];
    _array[childindex] = hold;
}
//move up
template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp() {

}