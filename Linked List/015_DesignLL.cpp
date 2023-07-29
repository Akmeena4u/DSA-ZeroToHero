class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int val) : val(val), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;

        return current->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
            tail = head;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;

        if (index <= 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* prev = head;
        for (int i = 0; i < index - 1; i++)
            prev = prev->next;
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++)
                prev = prev->next;
            temp = prev->next;
            prev->next = temp->next;
            if (index == size - 1)
                tail = prev;
        }

        delete temp;
        size--;
    }
};
