//binary search tree to create and search for past temperatures
//saves time in searching because the date is sorted in a way that we can cut out search space
#include <iostream>

using namespace std;

//tell the program what my struct is set up
struct myNode{
    int temperature;
    myNode *rightNode,*leftNode;
};

//traverse the BInary search tree node by node until the key is found
struct myNode* search_For_key(struct myNode* rootNode, int temperature){
    //if the root node has the value we need then don;t waste time searching, return the root node
    if(rootNode == NULL || rootNode->temperature == temperature){
        return rootNode;
    }

    //if the nodes key is smaller than what were looking for, return the node to the right and continue
    else if(rootNode->temperature < temperature){
        return search_For_key(rootNode->rightNode, temperature);
    }

        //if the nodes key is greater than what were looking for, return the node to the left
    else if(rootNode->temperature > temperature){
        return search_For_key(rootNode->leftNode,temperature);
    }

};
//add create node and make the previously last node point to this node and make this new node point to null or the end of the list
struct myNode *create_Node(int input){
    //make temporary node the size of a general node 
    struct myNode *temp = (struct myNode*)malloc(sizeof(struct myNode));
    //this nodes temperature will be the temperature passed to the function
    temp->temperature = input;
    //the make this node point back to what used to be the right node
    temp->leftNode = temp->rightNode;
    //this new node will be the last node now so it points to null
    temp->rightNode = NULL;
};

struct myNode *insert_Node(struct myNode *newNode, int newTemperature){
    //if the tree has no populated nodes,make one
    if(newNode == NULL){
        return create_Node(newTemperature);
    }
    //if the new temperatire is smaller than the current node, insert to the left and conitnue that logic until we cannot continue
    if (newNode->temperature > newTemperature){
        newNode->leftNode  = insert_Node(newNode->leftNode, newTemperature);
    }
    
    // if it is greater, go down the right
    else if (newTemperature > newNode->temperature){
        newNode->rightNode = insert_Node(newNode->rightNode, newTemperature);
    }

    return newNode;
};

//traverse tree print tree starting at the roots...lol
void move_and_Print(struct myNode *root){
    //if the tree is not empty, print
    if(root != NULL){
        //move to left child node, print, then move right
        move_and_Print(root->leftNode); 
        cout<< "\n"<<root->temperature <<endl;; 
        move_and_Print(root->rightNode); 
    }

};



int main(){
    //MAKE sure rootNode point to null so the front and end are connected
    struct myNode *rootNode = NULL;
    int input,numOfEntries;

    cout << "How many numbers are in our tree?"<<endl;
    cin >> numOfEntries;

    //populate tree
    for (int i = 0; i < numOfEntries; i++){
        cout << "Enter a number into the Binary Search Tree." << endl;
        cin >> input;
        rootNode = insert_Node(rootNode,input);
    }

    move_and_Print(rootNode);


    return 0;
}