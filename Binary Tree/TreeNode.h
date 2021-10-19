#ifndef BINARYTREE_H
#define BINARYTREE_H
typedef std::string TreeItemType;

class TreeNode  //the Node of Tree
{
    private:

    TreeNode();
    TreeNode(const TreeItemType & node_item,
            TreeNode* left = nullptr,
            TreeNode* rigth = nullptr)
            : nodes_data{node_item},leftChildPtr{left},rigthChildPtr{rigth}
            {}

    TreeItemType nodes_data ;  //data
    TreeNode* leftChildPtr;
    TreeNode* rigthChildPtr;
    friend class BinaryTree;

};//End of class Node

#endif 
