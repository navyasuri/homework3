//
//  BinaryTree2.hpp
//  BinaryTree
//
//  Created by Maria Jaramillo on 4/6/18.
//  Copyright © 2018 Maria Jaramillo. All rights reserved.
//

// #ifndef BinaryTree2_hpp
// #define BinaryTree2_hpp
// #include "binaryTree1.hpp"
#include <stdio.h>
#include <list>

using namespace std;

class BinaryTree
{
  protected:
    template <typename E>
    struct Node
    {
        E elem;
        Node *parent;
        Node *left;
        Node *right;

        Node() : elem(), parent(NULL), left(NULL), right(NULL){};
    };

  public:
    class Position
    {
      private:
        template <typename E>
        Node<E> *v;

      public:
        template <typename E>
        Position(Node<E> *u = nullptr)
        {
            v = u;
        }

        template <typename E>
        E &operator*()
        {
            return v->elem;
        }

        template <typename E>
        Position left() const
        {
            return Position(v->left);
        }

        template <typename E>
        Position right() const
        {
            return Position(v->right);
        }

        template <typename E>
        Position parent() const
        {
            return Position(v->parent);
        }

        template <typename E>
        bool isRoot() const
        {
            return (v->parent == nullptr);
        }

        template <typename E>
        bool isExternal() const
        {
            return (v->left == nullptr && v->right == nullptr);
        }

        template <typename E>
        bool operator==(Position &a)
        {
            return v->elem == *a;
        }

        friend class BinaryTree;
    };
    typedef std::list<Position> PositionList;

  public:
    template <typename E>
    BinaryTree()
    {
        _root = nullptr;
        n = 0;
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return (n == 0);
    }

    template <typename E>
    Position root() const
    {
        return Position(_root);
    }

    template <typename E>
    PositionList positions() const
    {
        PositionList pl;
        BinaryTree::preorder(_root, pl);
        return PositionList(pl);
    }

    template <typename E>
    void addRoot(int e)
    {
        _root = new Node<E>;
        _root->elem = e;
        n = 1;
    }

    template <typename E>
    void expandExteral(const Position &e, int a, int b)
    {
        Node<E> *parent = e.v;
        Node<E> *left = new Node<E>;
        left->elem = a;
        Node<E> *right = new Node<E>;
        right->elem = b;
        left->parent = parent;
        right->parent = parent;
        parent->left = left;
        parent->right = right;
        left->left = nullptr;
        left->right = nullptr;
        right->left = nullptr;
        right->right = nullptr;
        n += 2;
    }

    template <typename E>
    Position removeAboveExternal(const Position &p)
    {
        Node<E> *currentNode = p.v;
        Node<E> *parentofCurrent = currentNode->parent;

        Node<E> *sibling = (currentNode == parentofCurrent->left ? parentofCurrent->right : parentofCurrent->left);

        if (parentofCurrent == _root)
        {
            _root = sibling;
            sibling->parent = nullptr;
        }

        else
        {
            Node<E> *grandpa = parentofCurrent->parent;

            if (parentofCurrent == grandpa->left)
            {
                grandpa->left = sibling; //replace the two
            }
            else if (parentofCurrent == grandpa->right)
            {
                grandpa->right = sibling;
            }
            sibling->parent = grandpa; //connect it to the new parent
        }
        delete currentNode;
        delete parentofCurrent;
        n -= 2;
        return Position(sibling);
    }

    template <typename E>
    void display(PositionList &a)
    {
        for (list<Position>::iterator p = a.begin(); p != a.end(); ++p)
        {
            cout << **p << " ";
        }
    }

    template <typename E>
    void printPreOrder(const Position &a)
    {
        Node<E> *current = a.v;

        cout << current->elem;
        if (current->left != nullptr)
        {
            printPreOrder(a.left());
        }

        if (current->right != nullptr)
        {
            printPreOrder(a.right());
        }
    }

    template <typename E>
    int maxDepth(const Position &a, int currentDepth)
    {
        int depthLeft = 0;
        int depthRight = 0;

        if (a.isExternal())
        {
            return currentDepth;
        }
        if (a.v->left != nullptr)
        {
            depthLeft = maxDepth(a.left(), currentDepth + 1);
        }
        if (a.v->right != nullptr)
        {
            depthRight = maxDepth(a.right(), currentDepth + 1);
        }

        if (depthLeft > depthRight)
        {
            cout << "depth left is more" << endl;
            return depthLeft;
        }
        else
        {
            cout << "depth right is more" << endl;
            return depthRight;
        }
    }

    template <typename E>
    int maxValue(PositionList &a)
    {
        int maxValue = *a.front();
        for (list<Position>::iterator p = a.begin(); p != a.end(); ++p)
        {
            if (**p > maxValue)
            {
                maxValue = **p;
            }
        }
        return maxValue;
    }

    template <typename E>
    void addNode(int a)
    {
        BinaryTree::Position p = root();
        cout << "The current size of the tree is " << size() << " and our tree looks like " << endl;
        PositionList tree = positions();
        display(tree);
        cout << endl;
        while (!p.isExternal())
        {
            if (a > *p)
            {
                if (p.v->right != nullptr)
                {
                    p = p.right();
                }
                else
                {
                    addRightChild(p, a);
                    return;
                }
            }
            else if (a < *p)
            {
                if (p.v->left != nullptr)
                {
                    p = p.left();
                }
                else
                {
                    addLeftChild(p, a);
                    return;
                }
            }
        }

        if (a > *p)
        {
            cout << a << " is greater than " << *p << endl;
            addRightChild(p, a);
        }
        else
        {
            cout << a << " is less  than " << *p << endl;
            addLeftChild(p, a);
        }
    }

    template <typename E>
    bool hasTwoChildren(Position &p)
    {
        if (p.v->left != nullptr && p.v->right != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename E>
    void printPostOrder(const Position &p)
    {
        Node<E> *current = p.v;
        BinaryTree::Position left = p.left();
        BinaryTree::Position right = p.right();
        if (current->left != nullptr)
        {
            printPostOrder(left);
        }
        if (current->right != nullptr)
        {
            printPostOrder(right);
        }

        cout << current->elem;
    }

    template <typename E>
    int minValue(const Position &x) // use the fact that its a binary search tree
    {
        BinaryTree::Position p = root();
        while (p.v->left != nullptr)
        {
            p = p.left();
        }
        return p.v->elem;
    }

    template <typename E>
    void printInOrder(const Position &p)
    {
        Node<E> *current = p.v;
        BinaryTree::Position left = p.left();
        BinaryTree::Position right = p.right();

        if (current->left != nullptr)
        {
            printInOrder(left);
        }
        cout << current->elem;

        if (current->right != nullptr)
        {
            printInOrder(right);
        }
    }

    template <typename E>
    int height(const Position &p)
    {
        int heightLeft = 0;
        int heightRight = 0;
        if (p.isExternal())
        {
            return 0;
        }
        if (p.v->left != nullptr)
        {
            heightLeft = height(p.left()) + 1;
        }
        if (p.v->right != nullptr)
        {
            heightRight = height(p.right()) + 1;
        }

        if (heightLeft > heightRight)
        {
            return heightLeft;
        }

        else
        {
            return heightRight;
        }
    }

    template <typename E>
    void EulerWalk(const Position &p)
    {
        if (p.isExternal())
        {
            cout << p.v->elem;
        }
        else
        {
            cout << "(";
            if (p.v->left != nullptr)
            {
                EulerWalk(p.left());
                cout << p.v->elem;
            }
            if (p.v->right != nullptr)
            {
                EulerWalk(p.right());
                cout << p.v->elem;
            }
            cout << ")";
        }
    }

    template <typename E>
    void EulerWalk2(const Position &p)
    {
        cout << p.v->elem;
        if (!p.isExternal())
        {
            EulerWalk2(p.left());
        }
        if (!p.isExternal())
        {
            cout << p.v->elem;
        }

        if (!p.isExternal())
        {
            EulerWalk2(p.right());
        }

        if (!p.isExternal())
        {
            cout << p.v->elem;
        }
    }

  protected:
    template <typename E>
    void preorder(Node<E> *v, PositionList &pl) const
    {
        pl.push_back(Position(v)); // why cant i just push back v

        if (v->left != nullptr)
        {
            preorder(v->left, pl);
        }

        if (v->right != nullptr)
        {
            preorder(v->right, pl);
        }

        else
        {
            return;
        }
    }

    template <typename E>
    void addRightChild(Position &p, int a)
    {
        Node<E> *parent = p.v;
        Node<E> *rightChild = new Node<E>;
        rightChild->elem = a;
        rightChild->parent = parent;
        parent->right = rightChild;
        n++;
    }

    template <typename E>
    void addLeftChild(Position &p, int a)
    {
        Node<E> *parent = p.v;
        Node<E> *leftChild = new Node<E>;
        leftChild->elem = a;
        leftChild->parent = parent;
        parent->left = leftChild;
        n++;
    }

    bool isValid(Position &p) const;

  private:
    template <typename E>
    Node<E> *_root;

    int n;
};

// #endif

/* BinaryTree2_hpp */

//
//  BinaryTree2.cpp
//  BinaryTree
//
//  Created by Maria Jaramillo on 4/6/18.
//  Copyright © 2018 Maria Jaramillo. All rights reserved.
//

/////////////////////////////////////////////////////////
// ------------DUPLICATES BELOW-----------------/////////
/////////////////////////////////////////////////////////

// #include "BinaryTree2.hpp"
// #include <iostream>

// using namespace std;

// BinaryTree::Position::Position(Node *u)
// {
//     v = u;
// }

// int &BinaryTree::Position::operator*()
// {
//     return v->elem;
// }

// BinaryTree::Position BinaryTree::Position::left() const
// {
//     return Position(v->left);
// }

// BinaryTree::Position BinaryTree::Position::right() const
// {
//     return Position(v->right);
// }

// BinaryTree::Position BinaryTree::Position::parent() const
// {
//     return Position(v->parent);
// }

// bool BinaryTree::Position::isRoot() const
// {
//     return (v->parent == nullptr);
// }

// bool BinaryTree::Position::isExternal() const
// {
//     return (v->left == nullptr && v->right == nullptr);
// }

// bool BinaryTree::Position::operator==(Position &a)
// {
//     return v->elem == *a;
// }

// BinaryTree::BinaryTree()
// {
//     _root = nullptr;
//     n = 0;
// }

// int BinaryTree::size() const
// {
//     return n;
// }

// bool BinaryTree::empty() const
// {
//     return (n == 0);
// }

// BinaryTree::Position BinaryTree::root() const
// {
//     return Position(_root);
// }

// void BinaryTree::preorder(Node *v, PositionList &pl) const
// {

//     pl.push_back(Position(v)); // why cant i just push back v

//     if (v->left != nullptr)
//     {
//         preorder(v->left, pl);
//     }

//     if (v->right != nullptr)
//     {
//         preorder(v->right, pl);
//     }

//     else
//     {
//         return;
//     }
// }

// BinaryTree::PositionList BinaryTree::positions() const
// {
//     PositionList pl;
//     BinaryTree::preorder(_root, pl);
//     return PositionList(pl);
// }

// void BinaryTree::addRoot(int e)
// {
//     _root = new Node;
//     _root->elem = e;
//     n = 1;
// }

// void BinaryTree::expandExteral(const BinaryTree::Position &e, int a, int b)
// {
//     Node *parent = e.v;
//     Node *left = new Node;
//     left->elem = a;
//     Node *right = new Node;
//     right->elem = b;
//     left->parent = parent;
//     right->parent = parent;
//     parent->left = left;
//     parent->right = right;
//     left->left = nullptr;
//     left->right = nullptr;
//     right->left = nullptr;
//     right->right = nullptr;
//     n += 2;
// }

// BinaryTree::Position BinaryTree::removeAboveExternal(const Position &p)
// {
//     Node *currentNode = p.v;
//     Node *parentofCurrent = currentNode->parent;

//     Node *sibling = (currentNode == parentofCurrent->left ? parentofCurrent->right : parentofCurrent->left);

//     if (parentofCurrent == _root)
//     {
//         _root = sibling;
//         sibling->parent = nullptr;
//     }

//     else
//     {
//         Node *grandpa = parentofCurrent->parent;

//         if (parentofCurrent == grandpa->left)
//         {
//             grandpa->left = sibling; //replace the two
//         }
//         else if (parentofCurrent == grandpa->right)
//         {
//             grandpa->right = sibling;
//         }
//         sibling->parent = grandpa; //connect it to the new parent
//     }
//     delete currentNode;
//     delete parentofCurrent;
//     n -= 2;
//     return Position(sibling);
// }

// void BinaryTree::display(PositionList &a)
// {
//     for (list<Position>::iterator p = a.begin(); p != a.end(); ++p)
//     {
//         cout << **p << " ";
//     }
// }

// void BinaryTree::printPreOrder(const BinaryTree::Position &a)
// {
//     Node *current = a.v;

//     cout << current->elem;
//     if (current->left != nullptr)
//     {
//         printPreOrder(a.left());
//     }

//     if (current->right != nullptr)
//     {
//         printPreOrder(a.right());
//     }
// }

// int BinaryTree::maxValue(PositionList &a)
// {
//     int maxValue = *a.front();
//     for (list<Position>::iterator p = a.begin(); p != a.end(); ++p)
//     {
//         if (**p > maxValue)
//         {
//             maxValue = **p;
//         }
//     }
//     return maxValue;
// }

// void BinaryTree::addNode(int a)
// {
//     BinaryTree::Position p = root();
//     cout << "The current size of the tree is " << size() << " and our tree looks like " << endl;
//     PositionList tree = positions();
//     display(tree);
//     cout << endl;
//     while (!p.isExternal())
//     {
//         if (a > *p)
//         {
//             if (p.v->right != nullptr)
//             {
//                 p = p.right();
//             }
//             else
//             {
//                 addRightChild(p, a);
//                 return;
//             }
//         }
//         else if (a < *p)
//         {
//             if (p.v->left != nullptr)
//             {
//                 p = p.left();
//             }
//             else
//             {
//                 addLeftChild(p, a);
//                 return;
//             }
//         }
//     }

//     if (a > *p)
//     {
//         cout << a << " is greater than " << *p << endl;
//         addRightChild(p, a);
//     }
//     else
//     {
//         cout << a << " is less  than " << *p << endl;
//         addLeftChild(p, a);
//     }
// }

// bool BinaryTree::hasTwoChildren(BinaryTree::Position &p)
// {
//     if (p.v->left != nullptr && p.v->right != nullptr)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void BinaryTree::addRightChild(BinaryTree::Position &p, int a)
// {
//     Node *parent = p.v;
//     Node *rightChild = new Node;
//     rightChild->elem = a;
//     rightChild->parent = parent;
//     parent->right = rightChild;
//     n++;
// }

// void BinaryTree::addLeftChild(BinaryTree::Position &p, int a)
// {
//     Node *parent = p.v;
//     Node *leftChild = new Node;
//     leftChild->elem = a;
//     leftChild->parent = parent;
//     parent->left = leftChild;
//     n++;
// }

// void BinaryTree::printPostOrder(const BinaryTree::Position &p)
// {
//     Node *current = p.v;
//     BinaryTree::Position left = p.left();
//     BinaryTree::Position right = p.right();
//     if (current->left != nullptr)
//     {
//         printPostOrder(left);
//     }
//     if (current->right != nullptr)
//     {
//         printPostOrder(right);
//     }

//     cout << current->elem;
// }

// int BinaryTree::minValue(const BinaryTree::Position &x)
// {
//     BinaryTree::Position p = root();
//     while (p.v->left != nullptr)
//     {
//         p = p.left();
//     }
//     return p.v->elem;
// }

// void BinaryTree::printInOrder(const BinaryTree::Position &p)
// {
//     Node *current = p.v;
//     BinaryTree::Position left = p.left();
//     BinaryTree::Position right = p.right();

//     if (current->left != nullptr)
//     {
//         printInOrder(left);
//     }
//     cout << current->elem;

//     if (current->right != nullptr)
//     {
//         printInOrder(right);
//     }
// }
// int BinaryTree::maxDepth(const BinaryTree::Position &a, int currentDepth)
// {
//     int depthLeft = 0;
//     int depthRight = 0;

//     if (a.isExternal())
//     {
//         return currentDepth;
//     }
//     if (a.v->left != nullptr)
//     {
//         depthLeft = maxDepth(a.left(), currentDepth + 1);
//     }
//     if (a.v->right != nullptr)
//     {
//         depthRight = maxDepth(a.right(), currentDepth + 1);
//     }

//     if (depthLeft > depthRight)
//     {
//         cout << "depth left is more" << endl;
//         return depthLeft;
//     }
//     else
//     {
//         cout << "depth right is more" << endl;
//         return depthRight;
//     }
// }

// int BinaryTree::height(const BinaryTree::Position &p)
// {
//     int heightLeft = 0;
//     int heightRight = 0;
//     if (p.isExternal())
//     {
//         return 0;
//     }
//     if (p.v->left != nullptr)
//     {
//         heightLeft = height(p.left()) + 1;
//     }
//     if (p.v->right != nullptr)
//     {
//         heightRight = height(p.right()) + 1;
//     }

//     if (heightLeft > heightRight)
//     {
//         return heightLeft;
//     }

//     else
//     {
//         return heightRight;
//     }
// }

// void BinaryTree::EulerWalk(const BinaryTree::Position &p)
// {
//     if (p.isExternal())
//     {
//         cout << p.v->elem;
//     }
//     else
//     {
//         cout << "(";
//         if (p.v->left != nullptr)
//         {
//             EulerWalk(p.left());
//             cout << p.v->elem;
//         }
//         if (p.v->right != nullptr)
//         {
//             EulerWalk(p.right());
//             cout << p.v->elem;
//         }
//         cout << ")";
//     }
// }

// void BinaryTree::EulerWalk2(const BinaryTree::Position &p)
// {
//     cout << p.v->elem;
//     if (!p.isExternal())
//     {
//         EulerWalk2(p.left());
//     }
//     if (!p.isExternal())
//     {
//         cout << p.v->elem;
//     }

//     if (!p.isExternal())
//     {
//         EulerWalk2(p.right());
//     }

//     if (!p.isExternal())
//     {
//         cout << p.v->elem;
//     }
// }
