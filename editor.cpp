#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    string data;
    node* next;
};

class linkedList
{
    private:
    node* head = nullptr;
    public:
    void insertEnd(string text);
    void insert(int index, string text);
    void edit(int index, string text);
    void deleteLine(int index);
    void print();
    void search(string text);
};

// inserts the string at the end of the linked list
void linkedList::insertEnd(string text)
{
    node* end = new node;
    node* holder = head;
    end->data = text;
    end->next = nullptr;

    if(head == nullptr)
    {
        head = end;
        head->next = nullptr;
        return;
    }

    while (holder->next != nullptr)
    {
        holder = holder->next;
    }
    holder->next = end;
}

// inserts a node at a given index
void linkedList::insert(int index, string text)
{
    node* curr = head;
    node* holder = new node();
    holder->data = text;
    node* place = head;
    int size = 1;
    int pos = 0;

    while (place->next != nullptr)
    {
        size++;
        place = place->next;
    }

    if ((index - 1) == size)
    {
        insertEnd(text);
    }

    if (index < 1 || index > size)
    {
        return;
    }

    if((index - 1) == 0)
    {
        head = holder;
        holder->next = curr;
        return;
    }
        
    node* holder2 = new node();
    holder2 = curr -> next;
    while(pos != (index - 2))
    {
        curr = curr->next;
        pos++;
    }
    holder->next = curr->next;
    curr->next = holder;

}

//edits the given line with the given text
void linkedList::edit(int index, string text)
{
    node* curr = head;
    node* holder;
    int pos = 0;

    if ((index - 1) == 0)
    {
        curr->data = text;
        return;
    }

    while (pos != (index - 1))
    {
        curr = curr->next;
        pos++;
    }

    if (pos == (index - 1))
    {
        curr->data = text;
        return;
    }
    else
    {
        return;
    }
}

//removes a node at a given index
void linkedList::deleteLine(int index)
{
    node* curr;
    node* holder;
    int pos = 0;
    bool match = false;
    node* place = head;
    int size = 1;

    while (place->next != nullptr)
    {
        size++;
        place = place->next;
    }

    if (index < 1 || index > size)
    {
        return;
    }

    if (pos == (index - 1) && head->next == nullptr)
    {
        curr = head;
        head = nullptr;
        delete(curr);
    }
    else if (head->next == nullptr)
    {
        return;
    }
    else
    {
        curr = head;
        while(pos != (index - 1))
        {
            holder = curr;
            curr = curr->next;
            pos++;
        }
        
        if (pos == (index - 1))
        {
            holder->next = curr->next;
            delete(curr);
        }
        else 
        {
            return;
        }    
    }
    
}

// displays all the data in each node
void linkedList::print()
{
    node* curr = head;
    int i = 0;

    while(curr != nullptr)
    {
        i++;
        cout << i << " " << curr->data << "\n";
        curr = curr->next;
    } 
}

// searches for the given text
// will print the line number and line
// or will print not found if the text does not exist
void linkedList::search(string text)
{
    int index = 0;
    bool match = false;
    node* curr = head;
    node* holder;

    while (curr != nullptr)
    {
        string sentence = curr->data;
        index++;

        if(sentence.find(text) != string::npos)
        {
            cout << index << " " << sentence << "\n";
            match = true;
        }
        curr = curr->next;
    }

    if (!match)
    {
        cout << "not found" << "\n";
    } 
}

int main(void)
{
    linkedList* list = new linkedList;
    node* curr = new node;
    string userInput;
    string command;
    string text;
    int index;
    int posOf1 = 0;
    
    while (true)
    {
        cin >> command;
        getline(cin, userInput);

        if(command == "insertEnd")
        {
            text = userInput.substr(2, userInput.length()-3);
            list->insertEnd(text);
            cin.clear();
        }
        else if(command == "insert")
        {
            int index = (int)userInput[1]-'0';
            text = userInput.substr(4, userInput.length()-5);
            list->insert(index, text);
            cin.clear();
        }
        else if(command == "delete")
        {
            int index = (int)userInput[1]-'0';
            list->deleteLine(index);
            cin.clear();
        }
        else if(command == "edit")
        {
            int index = (int)userInput[1]-'0';
            text = userInput.substr(4, userInput.length()-5);
            list->edit(index, text);
            cin.clear();
        }
        else if(command == "print")
        {
            list->print();
            cin.clear();
        }
        else if(command == "search")
        {
            text = userInput.substr(2, userInput.length()-3);
            list->search(text);
            cin.clear();
        }
        else if(command == "quit")
        {
            return 0;
        }
        else
        {
            cout << "This is an unknown command" << "\n";
            cin.clear();
        }
    }

    return 0;
}