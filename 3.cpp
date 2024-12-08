#include <iostream>
#include <cstring>

class Document {
private:
    char* content;

public:
    Document(const char* initialContent) {
        content = new char[strlen(initialContent) + 1];
        strcpy(content, initialContent);
    }

    ~Document() {
        delete[] content;
    }

    Document(const Document& other) {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }

    Document& operator=(const Document& other) {
        if (this != &other) {
            delete[] content;
            content = new char[strlen(other.content) + 1];
            strcpy(content, other.content);
        }
        return *this;
    }

    void setContent(const char* newContent) {
        delete[] content;
        content = new char[strlen(newContent) + 1];
        strcpy(content, newContent);
    }

    void display() const {
        std::cout << "Document Content: " << content << std::endl;
    }
};

int main() {
    Document doc1("Original Document Content");
    std::cout << "Before Copying:" << std::endl;
    doc1.display();

    Document doc2 = doc1;
    std::cout << "After Copy Constructor:" << std::endl;
    doc2.display();

    doc1.setContent("Modified Original Document Content");
    std::cout << "After Modifying Original Document:" << std::endl;
    doc1.display();
    doc2.display();

    Document doc3("Another Document");
    doc3 = doc1;
    std::cout << "After Copy Assignment Operator:" << std::endl;
    doc3.display();

    return 0;
}