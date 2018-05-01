class SearchTree {
public:
class Iterator;
public: 
SearchTree();
int size() const; 
bool empty() const; 
Iterator find(const int& k);
Iterator insert(const int& k, const string& x);
void erase(const int& k) throw(NonexistentElement);
void erase(const Iterator& p);
Iterator begin(); 
Iterator end(); 
protected:
typedef BinaryTree<int, string> BinaryTree;
typedef typename BinaryTree::Position TPos; 
TPos root() const; 
TPos finder(const int& k, const TPos& v);
TPos inserter(const int& k, const string& x);
TPos eraser(TPos& v); 
TPos restructure(const TPos& v) 
throw(BoundaryViolation);
private: 
BinaryTree T; 
int n;
public:
// . . .insert Iterator class declaration here
// I made a change
};
