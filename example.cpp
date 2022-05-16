#include<iostream>
#include "cpptree.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;

void cls();

#ifdef _WIN32
void cls() {system("cls");}
#else
void cls() {system("clear");}
#endif

void NodeAdd ();
void NodeRemove ();
void NodeAssign ();
void NodeNodes ();
void NodeAllNodes ();

void NodeAdd(vector_tree<string>* my_tree) {
    cout << "\nWhich node do you want to add to?\n";
    int select;
    int newNode;
    cin >> select;
    if (my_tree->inRange(select)) {
        newNode = my_tree->addNode(select);
        cout << "\nNew node '" << newNode << "' added to node '" << select << "'.\n";
    }
    else {
        cout << "\nNode '" << select << "' doesn't exist.\n";
    }
    getchar();
    cin.ignore();
}

void NodeRemove(vector_tree<string>* my_tree) {
    cout << "\nWhich node do you want to remove?\n";
    int select;
    cin >> select;
    if (my_tree->inRange(select) && select) {
        my_tree->removeNode(select);
        cout << "\nNode '" << select << "' removed.\n";
    }
    else if (select) {
        cout << "\nNode '" << select << "' doesn't exist.\n";
    }
    else {
        cout << "\nNode '0' can't be removed.\n";
    }
    getchar();
    cin.ignore();
}

void NodeAssign(vector_tree<string>* my_tree) {
    cout << "\nWhich node do you want to set value of?\n";
    int select;
    cin >> select;
    if (my_tree->inRange(select)) {
        cout << "\nWhat value do you want to set? (enter any string)\n";
        while (getchar() != '\n');
        string myVal;
        getline(cin, myVal);
        my_tree->setName(select, myVal);
        cout << "\nValue assigned to node.\n";
    }
    else {
        cout << "\nNode '" << select << "' doesn't exist.\n";
    }
    cin.ignore();
}

void NodeNodes(vector_tree<string>* my_tree) {
    cout << "\nWhich node do you want list?\n";
    int select;
    cin >> select;
    if (my_tree->inRange(select)) {
        vector<int> allNodes;
        allNodes = my_tree->getChildren(select);
        cout << "\nNodes under '" << select << "' are";
        for (int i = 0; i < allNodes.size(); i++) {
            cout << " " << allNodes.at(i);
        }
        cout << "\n";
    }
    else {
        cout << "\nNode '" << select << "' doesn't exist.\n";
    }
    getchar();
    cin.ignore();
}

void NodeAllNodes(vector_tree<string>* my_tree) {
    cout << "\nWhich node do you want list?\n";
    int select;
    cin >> select;
    if (my_tree->inRange(select)) {
        vector<int> allNodes;
        allNodes = my_tree->getAllChildren(select);
        cout << "\nAll nodes under '" << select << "' are";
        for (int i = 0; i < allNodes.size(); i++) {
            cout << " " << allNodes.at(i);
        }
        cout << "\n";
    }
    else {
        cout << "\nNode '" << select << "' doesn't exist.\n";
    }
    getchar();
    cin.ignore();
}

int main() {
    vector_tree<string> mytree;
    int cnode;
    mytree.setName(0, "/");
    cnode = mytree.addNode(0);
    mytree.setName(1, "/astos");
    mytree.addNode(0);
    mytree.setName(2, "/usr/share/ast symlink to /astos/usr/share/ast");
    mytree.addNode(0);
    mytree.setName(3, "/var/lib/ast symlink to /astos/var/lib/ast");
    mytree.addNode(0);
    mytree.setName(4, "/etc/ast symlink to /astos/etc/ast");
    cnode = mytree.addNode(1);
    mytree.setName(cnode, "/.snapshots");
    cnode = mytree.addNode(5);
    mytree.setName(cnode, "/rootfs");
    cnode = mytree.addNode(5);
    mytree.setName(cnode, "/etc");
    cnode = mytree.addNode(5);
    mytree.setName(cnode, "/var");
    cnode = mytree.addNode(5);
    mytree.setName(cnode, "/boot");
    cnode = mytree.addNode(6);
    mytree.setName(cnode, "root file system snapshots (/)");
    cnode = mytree.addNode(7);
    mytree.setName(cnode, "etc snapshots (/etc)");
    cnode = mytree.addNode(8);
    mytree.setName(cnode, "var snapshot specific files (/var/lib/some_stuff)");
    cnode = mytree.addNode(9);
    mytree.setName(cnode, "boot snapshots (/boot)");
    
    cnode = mytree.addNode(1);
    mytree.setName(cnode, "/usr");
    cnode = mytree.addNode(14);
    mytree.setName(cnode, "/share");
    cnode = mytree.addNode(15);
    mytree.setName(cnode, "/ast");
    cnode = mytree.addNode(16);
    mytree.setName(cnode, "/db");
    cnode = mytree.addNode(16);
    mytree.setName(cnode, "/ast.d");
    cnode = mytree.addNode(17);
    mytree.setName(cnode, "/package database");
    cnode = mytree.addNode(18);
    mytree.setName(cnode, "/astos files specific to snapshot");

    cnode = mytree.addNode(1);
    mytree.setName(cnode, "/var");
    cnode = mytree.addNode(21);
    mytree.setName(cnode, "/lib");
    cnode = mytree.addNode(22);
    mytree.setName(cnode, "/ast");
    cnode = mytree.addNode(23);
    mytree.setName(cnode, "astos specific files");

    cnode = mytree.addNode(1);
    mytree.setName(cnode, "/etc");
    cnode = mytree.addNode(25);
    mytree.setName(cnode, "/ast");
    cnode = mytree.addNode(26);
    mytree.setName(cnode, " astos configuration options");

	mytree.printTree();
}
