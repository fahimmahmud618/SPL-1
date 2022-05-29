#ifndef BPLUSTREE_H_INCLUDED
#define BPLUSTREE_H_INCLUDED

using namespace std;
int ORDER = 3;

class Node {
    bool CHECK_LEAF;
    int *key, size;
    Node** ptr;
    friend class BPTree;

public:
    Node();
};

class BPTree {
    Node* root;

    void insert_in_Internal_node(int value, Node* cursor,Node* child)
    {

        // no overflow
        if (cursor->size < ORDER) {
            int i = 0;

            while (value > cursor->key[i]&& i < cursor->size)
            {
                i++;
            }
            for (int j = cursor->size;j > i; j--)
            {

                cursor->key[j] = cursor->key[j - 1];
            }

            for (int j = cursor->size + 1;j > i + 1; j--)
            {
                cursor->ptr[j]= cursor->ptr[j - 1];
            }

            cursor->key[i] = value;
            cursor->size++;
            cursor->ptr[i + 1] = child;
        }

        else {

            Node* newInternal = new Node;
            int virtualKey[ORDER + 1];
            Node* virtualPtr[ORDER + 2];


            for (int i = 0; i < ORDER; i++) {
                virtualKey[i] = cursor->key[i];
            }

            for (int i = 0; i < ORDER + 1; i++) {
                virtualPtr[i] = cursor->ptr[i];
            }

            int i = 0, j;

            while (value > virtualKey[i]&& i < ORDER) {
                i++;
            }


            for (int j = ORDER + 1;j > i; j--)
            {
                virtualKey[j]= virtualKey[j - 1];
            }

            virtualKey[i] = value;

            for (int j = ORDER + 2;j > i + 1; j--)
            {
                virtualPtr[j]= virtualPtr[j - 1];
            }

            virtualPtr[i + 1] = child;
            newInternal->CHECK_LEAF = false;

            cursor->size = (ORDER + 1) / 2;

            newInternal->size= ORDER - (ORDER + 1) / 2;

            for (i = 0, j = cursor->size + 1;i < newInternal->size;i++, j++)
            {
                newInternal->key[i] = virtualKey[j];
            }

            for (i = 0, j = cursor->size + 1;i < newInternal->size + 1;i++, j++)
            {

                newInternal->ptr[i]= virtualPtr[j];
            }

            if (cursor == root) {

                Node* newRoot = new Node;

                newRoot->key[0]
                    = cursor->key[cursor->size];

                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newInternal;
                newRoot->CHECK_LEAF = false;
                newRoot->size = 1;
                root = newRoot;
            }

            else {

                insert_in_Internal_node(cursor->key[cursor->size],findParent(root,cursor),newInternal);
            }
        }
    }


    Node* findParent(Node*, Node*);

public:
    BPTree();
    bool search(int);
    void insert(int);
    Node* getRoot();
};

Node::Node()
{
    key = new int[ORDER];
    ptr = new Node*[ORDER + 1];
}

BPTree::BPTree()
{
    root = NULL;
}

bool BPTree::search(int insert_value)
{

    bool flag = false;
    if (root == NULL) {
        cout << "Tree is empty\n";
    }
    else {

        Node* cursor = root;

        while (cursor->CHECK_LEAF == false) {

            for (int i = 0;
                 i < cursor->size; i++) {

                if (insert_value < cursor->key[i]) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }

        for (int i = 0;
             i < cursor->size; i++) {

            if (cursor->key[i] == insert_value) {
                flag = true;
            }
        }

    }
    return flag;
}


void BPTree::insert(int value_to_be_insert)
{

    if (root == NULL) {
        root = new Node;
        root->key[0] = value_to_be_insert;
        root->CHECK_LEAF = true;
        root->size = 1;
    }

    else {
        Node* cursor = root;
        Node* parent;

        while (cursor->CHECK_LEAF== false)
        {
            parent = cursor;

            for (int i = 0;i < cursor->size;i++)
            {

                if (value_to_be_insert < cursor->key[i])
                {
                    cursor = cursor->ptr[i];
                    break;
                }

                if (i == cursor->size - 1)
                {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }

        if (cursor->size < ORDER)
        {
            int i = 0;
            while (value_to_be_insert > cursor->key[i]&& i < cursor->size)
            {
                i++;
            }

            for (int j = cursor->size;j > i; j--)
            {
                cursor->key[j]= cursor->key[j - 1];
            }

            cursor->key[i] = value_to_be_insert;
            cursor->size++;

            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        }

        else {

            // newLeaf
            Node* newLeaf = new Node;

            int virtualNode[ORDER + 1];

            for (int i = 0; i < ORDER; i++)
            {
                virtualNode[i]= cursor->key[i];
            }
            int i = 0, j;

            while (value_to_be_insert > virtualNode[i]&& i < ORDER)
            {
                i++;
            }

            for (int j = ORDER + 1;j > i; j--) {
                virtualNode[j]= virtualNode[j - 1];
            }

            virtualNode[i] = value_to_be_insert;
            newLeaf->CHECK_LEAF = true;

            cursor->size = (ORDER + 1) / 2;
            newLeaf->size= ORDER + 1 - (ORDER + 1) / 2;

            cursor->ptr[cursor->size]= newLeaf;

            newLeaf->ptr[newLeaf->size] = cursor->ptr[ORDER];

            cursor->ptr[ORDER] = NULL;

            for (i = 0;i < cursor->size; i++)
            {
                cursor->key[i]= virtualNode[i];
            }


            for (i = 0, j = cursor->size;i < newLeaf->size;i++, j++)
            {
                newLeaf->key[i]= virtualNode[j];
            }

            if (cursor == root) {

                Node* newRoot = new Node;

                newRoot->key[0] = newLeaf->key[0];
                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newLeaf;
                newRoot->CHECK_LEAF = false;
                newRoot->size = 1;
                root = newRoot;
            }
            else {


                insert_in_Internal_node(newLeaf->key[0],parent,newLeaf);
            }
        }
    }
}





Node* BPTree::findParent(Node* cursor, Node* child)
{
    Node* parent;

    if (cursor->CHECK_LEAF || (cursor->ptr[0])->CHECK_LEAF) {
        return NULL;
    }

    for (int i = 0;i < cursor->size + 1; i++) {

        if (cursor->ptr[i] == child) {
            parent = cursor;
            return parent;
        }
        else {
            parent= findParent(cursor->ptr[i],child);

            if (parent != NULL)
                return parent;
        }
    }
    return parent;
}

Node* BPTree::getRoot()
{
    return root;
}


#endif // BPLUSTREE_H_INCLUDED
