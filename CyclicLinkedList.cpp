#include <iostream>

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

void ToLowerCase(std::string& sen)
{
    for (size_t i = 0; i < sen.size(); i++)
    {
        sen[i] = asciitolower(sen[i]);
    }
}

struct node
{
    std::string info;
    node* next;
};

class circular_list
{
private:
    node* last;
public:
    circular_list()
    {
        last = NULL;
    }

    node* getLast() {
        return this->last;
    }

    void create_node(std::string& value){
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

    void add_begin(std::string& value) {
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

   void add_end(std::string& value) {
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

    void add_after(std::string& value, int position) {
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

    void delete_element(std::string& value) {
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
    }

    int search_possition(std::string& value) {
        node* s;
        int counter = -1;
        s = last->next;

        while (s != last)
        {
            counter++;
            if (s->info == value)
            {
                return counter;
            }
            s = s->next;
        }
        if (s->info == value)
        {
            counter++;
            
            return counter;
        }
        return counter;
    }

    void search_element(std::string& value) {
        node* s;
        int counter = 0;
        s = last->next;

        while (s != last)
        {
            counter++;
            if (s->info == value)
            {
                return;
            }
            s = s->next;
        }
        if (s->info == value)
        {
            counter++;
            return;
        }
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

    void update(int posOne, std::string valueOne) {
        std::string value = valueOne;
        int pos = posOne;
        int i;

        if (last == NULL)
        {
            std::cout << "List is empty, nothing to update" << std::endl;
            return;
        }

        node* s;
        s = last->next;

        for (i = 0; i < pos - 1; i++)
        {
            if (s == last)
            {
                return;
            }
            s = s->next;
        }
        s->info = value; 
    }

    void sort() {
        node* s, * ptr;

        circular_list resultList;

        std::string temp;

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
                    if (s->info[0] > ptr->info[0])
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
   
    void node_iteration(circular_list& list) {

        circular_list* circular_llistResult = new circular_list();
        
        if (last == NULL) {
            return;
        }

        node* temp, * s;
        s = list.last->next;

        node* listNode = list.last->next;
        int position = list.getElemetsCount();
        //int position = this->getElemetsCount();        

        bool flag = false;

        int currentPoss = -1;

        for (int i = 0; i < position - 1; i++)
        {
            temp = s->next;
            std::string currentNode = "";

            for (int j = search_possition(listNode->info); j < position ; j++) {
                std::string& pointer = s->info;
                size_t sInfoLength = pointer.length();

                char sInfoLastLetter = s->info[sInfoLength - 1];
                char tempInfoFirstLetter = temp->info[0];
                    
                sInfoLastLetter = asciitolower(sInfoLastLetter);
                tempInfoFirstLetter = asciitolower(tempInfoFirstLetter);

                if (sInfoLastLetter == tempInfoFirstLetter)
                {
                    int searchElement = search_possition(s->info);
                    if (searchElement != -1) currentPoss = searchElement;
                    std::string update = s->info + "-" + temp->info;
                    list.update(currentPoss + 1, update);
                    currentNode = temp->info;
                    list.delete_element(temp->info);

                    temp = s->next;
                }
                else {
                    temp = temp->next;
                    flag = true;
                }
                if (!flag)
                    temp = s->next;
            }

            
            s = s->next;

            i = search_possition(temp->info);
            if (i <= 0) break;
        }
    }

    void longest_node() {
        node* s, * temp;

        s = last->next;
        int position = this->getElemetsCount();

        int maxCounter = 0;
        std::string maxCountNode = "";

        for (int i = 0; i < position - 1; i++) {
            std::string currentNode = s->info;
            int currentNodeLength = currentNode.length();
            
            int currMaxCounter = 0;
            //int currMaxPos = -1;

            for (int j = 0; j < currentNodeLength; j++) {
                char currentChar = currentNode[j];

                if (currentChar == '-') currMaxCounter++;
            }
            
            if (currMaxCounter > maxCounter) {
                maxCounter = currMaxCounter;
                maxCountNode = currentNode;
            }

            s = s->next;
        }

        if (maxCounter == 0) maxCountNode == last->next->info;

        std::cout << "Longest: " + maxCountNode;
    }
};

int main()
{
    circular_list real_test;

    std::string value = "";
    
    for (int i = 0; i < 8; i++) {
        std::cin >> value;
        real_test.add_end(value);
    }

    /*std::string Street = "Street";
    std::string Taxi = "Taxi";
    std::string Ink = "Ink";
    std::string Dog = "Dog";
    std::string Smile = "Smile";
    std::string Eat = "Eat";
    std::string Tall = "Tall";
    std::string Pass = "Pass";

    real_test.add_end(Street);
    real_test.add_end(Taxi);
    real_test.add_end(Ink);
    real_test.add_end(Dog);
    real_test.add_end(Smile);
    real_test.add_end(Eat);
    real_test.add_end(Tall);
    real_test.add_end(Pass);*/

    real_test.node_iteration(real_test);

    real_test.sort();

    real_test.display_list();

    real_test.longest_node();

    std::string as = "Hello World";
    
    return 0;
}