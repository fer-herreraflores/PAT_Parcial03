#include "Ejercicio02.h"
#include <unordered_map>

static std::string getDnaSequence(Node<char>* current) {
    std::string sequence;
    for (int i = 0; i < 10 && current != nullptr; ++i) {
        sequence += current->value;
        current = current->next;
    }
    return sequence;
}
vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    std::vector<std::string>* result = new std::vector<std::string>();
    std::unordered_map<std::string, int> sequenceCount;

    Node<char>* current = head;

    while (current != nullptr) {
        std::string sequence = getDnaSequence(current);
        sequenceCount[sequence]++;

        if (sequenceCount[sequence] == 2) {
            result->push_back(sequence);
        }

        current = current->next;
    }

    return result;
}
