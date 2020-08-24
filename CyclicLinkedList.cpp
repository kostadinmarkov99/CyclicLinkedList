#include <iostream>

struct node
{
    const char* info;
    node* next;
};

class circular_llist
{
private:
    node* last;
public:
    circular_llist()
    {
        last = NULL;
    }

    node* getLast() {
        return this->last;
    }

    void create_node(const char* value){
        node* temp;
        temp = new node;
        temp->info = value;
        if (last == NULL)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void add_begin(const char* value) {
        if (last == NULL)
        {
            create_node(value);
            return;
        }

        node* temp;
        temp = new node;
        temp->info = value;
        temp->next = last->next;
        last->next = temp;
    }

   void add_end(const char* value) {
        if (last == NULL) {
            create_node(value);
            return;
        }

        node* temp, * s;
        s = last->next;

        int position = this->getElemetsCount();

        for (int i = 0; i < position - 1; i++)
        {
            s = s->next;
            if (s == last->next)
            {
                std::cout << "There are less than ";
                std::cout << position << " in the list" << std::endl;
                return;
            }

        }

        temp = new node;
        temp->next = s->next;
        temp->info = value;
        s->next = temp;

        /*Element inserted at the end*/

        if (s == last)
        {
            last = temp;
        }
         
    }

    void add_after(const char* value, int position) {
        if (last == NULL)
        {
            std::cout << "The list is empty!" << std::endl;
            return;
        }

        node* temp, *s;
        s = last->next;

        for (int i = 0; i < position - 1; i++)
        {
            s = s->next;
            if (s == last->next)
            {
                std::cout << "There are less than";
                std::cout << position << " in the list" << std::endl;
                return;
            }

        }

        temp = new node;
        temp->next = s->next;
        temp->info = value;
        s->next = temp;

        /*Element inserted at the end*/

        if (s == last)
        {
            last = temp;
        }
    }

    void delete_element(const char* value) {
        node* temp, * s;
        s = last->next;

        /* If List has only one element*/
        if (last->next == last && last->info == value)
        {
            temp = last;
            last = NULL;
            free(temp);
            return;
        }

        if (s->info == value)  /*First Element Deletion*/
        {
            temp = s;
            last->next = s->next;
            free(temp);
            return;
        }
        while (s->next != last)
        {
            /*Deletion of Element in between*/
            if (s->next->info == value)
            {
                temp = s->next;
                s->next = temp->next;
                free(temp);
                std::cout << "Element " << value;
                std::cout << " deleted from the list" << std::endl;
                return;
            }
            s = s->next;
        }

        /*Deletion of last element*/
        if (s->next->info == value)
        {
            temp = s->next;
            s->next = last->next;
            free(temp);
            last = s;
            return;
        }

        std::cout << "Element " << value << " not found in the list" << std::endl;
    }

    void search_element(const char* value) {
        node* s;
        int counter = 0;
        s = last->next;

        while (s != last)
        {
            counter++;
            if (s->info == value)
            {
                std::cout << "Element " << value;
                std::cout << " found at position " << counter << std::endl;
                return;
            }
            s = s->next;
        }
        if (s->info == value)
        {
            counter++;
            std::cout << "Element " << value;
            std::cout << " found at position " << counter << std::endl;
            return;
        }

        std::cout << "Element " << value << " not found in the list" << std::endl;
    }

    void display_list() {
        node* s;

        if (last == NULL)
        {
            std::cout << "List is empty, nothing to display" << std::endl;
            return;
        }

        s = last->next;

        std::cout << "Circular Link List: " << std::endl;

        while (s != last)
        {
            std::cout << s->info << "->";
            s = s->next;
        }
        std::cout << s->info << std::endl;
    }

    void update() {
        char* value;
        int pos, i;

        if (last == NULL)
        {
            std::cout << "List is empty, nothing to update" << std::endl;
            return;
        }

        std::cout << "Enter the node position to be updated: ";
        std::cin >> pos;
        std::cout << "Enter the new value: ";
        std::cin >> value;

        node* s;
        s = last->next;

        for (i = 0; i < pos - 1; i++)
        {
            if (s == last)
            {
                std::cout << "There are less than " << pos << " elements.";
                std::cout << std::endl;
                return;
            }
            s = s->next;
        }
        s->info = value; 
        std::cout << "Node Updated" << std::endl;
    }

    void sort() {
        node* s, * ptr;

        const char* temp;

        if (last == NULL)
        {
            std::cout << "List is empty, nothing to sort" << std::endl;
            return;
        }

        s = last->next;

        while (s != last)
        {
            ptr = s->next;
            while (ptr != last->next)
            {
                if (ptr != last->next)
                {
                    if (s->info > ptr->info)
                    {
                        temp = s->info;
                        s->info = ptr->info;
                        ptr->info = temp;
                    }
                }
                else
                {
                    break;
                }

                ptr = ptr->next;
            }

            s = s->next;

        }
    }

    int getElemetsCount() {
        struct node* s, * ptr;

        int temp;
        int count = 0;

        if (last == NULL)
        {
            std::cout << "List is empty, nothing to sort" << std::endl;
            return 0;
        }

        s = last->next;

        while (s != last) {
            count++;
            s = s->next;
        }

        return count + 1;
    }
   
    void node_iteration() {

    }
};

int main()
{
    circular_llist cl;
    circular_llist cd;

    cl.add_end("Hello");
    cl.add_end("World");
    cl.add_end("How");
    cl.add_end("Are");
    cl.add_end("You");
    cl.add_end("?");
    cl.display_list();

    cd.add_begin("!");
    cd.add_begin("You");
    cd.add_begin("Thank");
    cd.add_begin("Fine");
    cd.add_begin("I Am");
    cd.display_list();
    
    return 0;
}