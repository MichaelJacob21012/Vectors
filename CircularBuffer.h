#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {
	private:
		int maxSize = 0;
		SimpleVector<char> vector {maxSize};
		int addPos = 0;
		int remPos = 0;
	public:
		CircularBuffer (int capacity)
			:maxSize(capacity){
		}
		int count (){
		    int contents = 0;
			for (int i = 0; i < vector.size(); i++){
				if (vector[i] != 0){
					contents++;
				}
			}
			return contents;
		}
		bool full (){
			if (count() == vector.size()){
			    return true;
			}
			return false;
		}
		void add (char c){
		    vector[addPos] = c;
		    addPos++;
		    if(addPos == vector.size()){
		        for (int i = 0; i < vector.size(); i++){
		            if (vector[i] == 0){
		                addPos = i;
		                return;
		            }
		        }
		        addPos = remPos;
		    }
		}
		char remove(){
		    char temp = 0;
		    temp = vector[remPos];
		    vector[remPos] = 0;
		    remPos ++;
		    if(remPos == vector.size()){
		        for (int i = 0; i < vector.size(); i++){
		            if (vector[i] != 0){
		                remPos = i;
		                return temp;
		            }
		        }
		        remPos = addPos;
		    }
		    return temp;
		}
};

// don't write any code below this line

#endif
