#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            
            entry->name;
            int pos = 0;
            while (pos < index && !entry->compare(&array[pos])) {
                pos++;
            }
        
            if (index == SIZE && pos == SIZE) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }
        
            int last;
            if (index < SIZE) {
                last = index;
            } else {
                last = SIZE - 1;
            }
 
            for (int i = last; i > pos; i--) {
                array[i] = array[i - 1];
            }
            
            array[pos] = *entry;
        
            if (index < SIZE) index++;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};