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
            int count = 0;
            while (count < index && entry->compare(&array[count]))
                count++;
            if (index == SIZE && count == SIZE) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }
            if (index < SIZE)
                index++;
            else
                count = SIZE - 1;
            for (int i = index - 1; i > count; i--) {
                array[i] = array[i - 1];
            }
            array[count] = *entry;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};