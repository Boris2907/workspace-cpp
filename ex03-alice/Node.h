#include <vector>

namespace ds_course {
    struct Node {
    private:
        int val;
    public:
        std::vector<Node> children;
        Node(int vv);
        void addChild(Node nn);
        void reflect();
        void printPreorder();
        int getVal();
        std::vector<int> getChildren();
        bool isInList = false;
    };
}