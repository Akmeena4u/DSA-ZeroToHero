  //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
       // your code goes here
        unordered_map<int, bool> map;
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            // If the data already exists in the map, remove the duplicate node
            if (map.find(current->data) != map.end()) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                map[current->data] = true;
                prev = current;
                current = current->next;
            }
            
            
        }
        
                return head; // Return the new head after removing duplicates

    
    }
