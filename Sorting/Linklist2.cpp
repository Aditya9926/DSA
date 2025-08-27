#include <iostream>  
  
template <typename T>  
class Node {  
public:  
  T data;  
  Node *next;  
  
  Node(T data) {  
    this->data = data;  
    this->next = nullptr;  
  }  
};  
  
template <typename T>  
class LinkedList {  
private:  
  Node<T> *head;  
  
public:  
  LinkedList() {  
    this->head = nullptr;  
  }  
  
  void insertAtBeginning(T data) {  
    Node<T> *newNode = new Node<T>(data);  
    newNode->next = head;  
    head = newNode;  
  }  
  
  void insertAtEnd(T data) {  
    Node<T> *newNode = new Node<T>(data);  
    if (head == nullptr) {  
      head = newNode;  
      return;  
    }  
    Node<T> *temp = head;  
    while (temp->next != nullptr) {  
      temp = temp->next;  
    }  
    temp->next = newNode;  
  }  
  
  void deleteAtBeginning() {  
    if (head == nullptr) {  
      return;  
    }  
    Node<T> *temp = head;  
    head = head->next;  
    delete temp;  
  }  
  
  void deleteAtEnd() {  
    if (head == nullptr) {  
      return;  
    }  
    if (head->next == nullptr) {  
      delete head;  
      head = nullptr;  
      return;  
    }  
    Node<T> *temp = head;  
    while (temp->next->next != nullptr) {  
      temp = temp->next;  
    }  
    delete temp->next;  
    temp->next = nullptr;  
  }  
  
  void printList() {  
    Node<T> *temp = head;  
    while (temp != nullptr) {  
      std::cout << temp->data << " ";  
      temp = temp->next;  
    }  
    std::cout << std::endl;  
  }  
};  
  
int main() {  
  // Create a linked list  
  LinkedList<int> list;  
  
  // Insert some nodes at the beginning of the list  
  list.insertAtBeginning(3);  
  list.insertAtBeginning(2);  
  list.insertAtBeginning(1);  
  
  // Insert some nodes at the end of the list  
  list.insertAtEnd(4);  
  list.insertAtEnd(5);  
  list.insertAtEnd(6);  
  
  // Print the list  
  std::cout << "Original list: ";  
  list.printList();  
  
  // Delete a node at the beginning  
  // Delete a node at the beginning of the list  
  list.deleteAtBeginning();  
  
  // Print the List again  
  std::cout << "List after deleting a node at the beginning: ";  
  list.printList();  
  
  // Delete a node at the end of the list  
  list.deleteAtEnd();  
  
  // Print the List again  
  std::cout << "List after deleting a node at the end: ";  
  list.printList();  
  
  return 0;  
}  