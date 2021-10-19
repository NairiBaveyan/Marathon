#include "MyBinaryTree.h"


BinaryTree::BinaryTree()
{
}

BinaryTree::BinaryTree(const TreeItemType &root_item)
{
    m_root = new TreeNode(root_item,nullptr,nullptr);
}

BinaryTree::BinaryTree(const TreeItemType &root_item,
                       BinaryTree &right_tree,
                       BinaryTree &left_tree)
{
    m_root = new TreeNode(root_item,nullptr,nullptr);
    attacheLeftSubtree(left_tree);
    attacheRigthSubtree(right_tree);
}


BinaryTree::BinaryTree(const BinaryTree &tree )
{
    copyTree(tree.m_root,m_root);
}

BinaryTree::BinaryTree(const TreeNode* node_ptr)
: m_root{node_ptr}
{}          //This is the protected Ctor

BinaryTree::~BinaryTree()
{
    destroyTree(m_root);
}
//Dtor;

bool BinaryTree::IsEmpty()const
{
    return (m_root == nullptr);
}

TreeItemType BinaryTree::getRootData()const
{
    if(IsEmpty())
    {
        throw TreeExeption("TreeExeption  your Tree is empty");
    }
    return m_root->nodes_data;
}

void BinaryTree::setRootData(const TreeItemType &new_nodes_data)
{
    if(IsEmpty())
    {
        m_root->nodes_data = new_nodes_data;
    }
    else
    {
        m_root = new TreeNode(new_nodes_data,nullptr,nullptr);
        if(m_root == nullptr)
        throw TreeExeption("Can not allocate the memory");
    }
}

void BinaryTree::attachLeft(const TreeItemType &new_nodes_data)
{
    if(IsEmpty())
    {
        throw TreeExeption("Your tree is empty");
    }
    else if(m_root->leftChildPtr == nullptr)
    {
        throw TreeExeption("can not override the left subtree ");
    }
    else
    {
        m_root->leftChildPtr =new TreeNode(new_nodes_data,nullptr,nullptr);
        if(m_root->leftChildPtr ==nullptr)
        throw TreeExeption("can not allocate the memory");
    }        
}


void BinaryTree::attachRigth(const TreeItemType &new_nodes_data)
{
    if(IsEmpty())
    throw TreeExeption("Your tree is empty");
    else if (m_root->rigthChildPtr == nullptr)
    {
        throw TreeExeption("can nott override The rigth subtree");//chenq karox verasahmanel aj entacary
                                                                    //qani vor aj hanguycy bacakayum e  
    }
    else
    {
        m_root->rigthChildPtr = new TreeNode(new_nodes_data,nullptr,nullptr);
        if(m_root->rigthChildPtr == nullptr)
        throw TreeExeption("can't allocate new memory block's");
    }
}

void BinaryTree::attacheLeftSubtree( BinaryTree & left_tree) // const petq chi verjum NULL petqa trvi
{
    if(isEmpty())
    throw TreeExeption("Your tree is empty");
    else if(m_root->leftChildPtr != nullptr)
    {
        throw TreeExeption("Can't override the left subtree");
    }
    else
    {
        m_root->leftChildPtr = left_tree.m_root;
        left_tree.m_root = nullptr;
    }
}  



void BinaryTree::attacheRigthSubtree( BinaryTree & rigth_tree) // const eli petq chi
{
    if(isEmpty())
    throw TreeExeption("Your tree is empty");
    else if(m_root->rigthChildPtr != nullptr)
    {
        throw TreeExeption("Can't override the rigth subtree");
    }
    else
    {
        m_root->rigthChildPtr = rigth_tree.m_root;
        rigth_tree.m_root = nullptr;
    }
}


void BinaryTree::detachLeftSubtree(BinaryTree & left_tree)
{
    if(IsEmpty())
    throw "tree is empty";
    else
    {
        left_tree = BinaryTree(m_root->leftChildPtr);
        m_root->leftChildPtr = nullptr;
    }
}


void BinaryTree::detachLeftSubtree(BinaryTree & rigth_tree)
{
    if(IsEmpty())
    throw "tree is empty";
    else
    {
        rigth_tree = BinaryTree(m_root->rigthChildPtr);
        m_root->rigthChildPtr = nullptr;
    }
}


BinaryTree BinaryTree::getLeftSubtree()const
{
    TreeNode* left_subtree_ptr;
    if(IsEmpty())
        return BinaryTree();
    else
    {
        copyTree(m_root->leftChildPtr,left_subtree_ptr);
        return BinaryTree(left_subtree_ptr);
    }
}
// 2 Funkcianern el veradarcnum en Binary Tree qani vor subtree-n nuynpes tree e
BinaryTree BinaryTree::getRigthSubtree()const
{
    TreeNode* rigth_subtree_ptr;
    if(IsEmpty())
        return BinaryTree();
    else
    {
        copyTree(m_root->rigthChildPtr,rigth_subtree_ptr);
        return BinaryTree(rigth_subtree_ptr);
    }
}

void BinaryTree::preorderTraverse(FunctionType visit)
{
    preorder(m_root,visit);
}

void BinaryTree::postorderTravese(FunctionType visit)
{
    postorder(m_root,visit);
}

void BinaryTree::inorderTravese(FunctionType visit)
{
    inorder(m_root,visit);
}

BinaryTree BinaryTree::operator =(const BinaryTree & rhs)
{
    if(this != &rhs)
    {
        destroyTree(m_root);
        copyTree(rhs.m_root,m_root);
    }
    return *(this);
}


void BinaryTree::copyTree(TreeNode &node_ptr,
                           TreeNode & new_tree_ptr)
                           {
                                if(node_ptr! = nullptr)
                                {
                                    new_tree_ptr =  new TreeNode(node_ptr->nodes_data,nullptr,nullptr )
                                    if(new_tree_ptr == nullptr)
                                        throw TreeExeption("Can't allocate new memory block");
                                        copyTree(node_ptr->leftChildPtr,new_tree_ptr->leftChildPtr);
                                        copyTree(node_ptr->rigthChildPtr,new_tree_ptr->rigthChildPtr);
                                    
                                }
                                else
                                {                                
                                    new_tree_ptr = nullptr;
                                }
                           }


void BinaryTree::destroyTree(TreeNode & tree_ptr)
{
    if(tree_ptr == nullptr)
    {
        destroyTree(tree_ptr->leftChildPtr);
        destroyTree(tree_ptr->rigthChildPtr);
        delete tree_ptr;
        tree_ptr = nullptr;
    }
}

TreeNode* BinaryTree::getRootPtr()const
{
    return m_root;
}

void BinaryTree::setRootPtr(TreeNode & new_root)
{
    m_root = new_root;
}

void BinaryTree::setChildPtrs(TreeNode & node_ptr,
                              TreeNode &left_tree_ptr,
                              TreeNode &rigth_tree_ptr)
                              {
                                  node_ptr->leftChildPtr = left_tree_ptr;
                                  node_ptr->rigthChildPtr = rigth_tree_ptr;
                              }


void BianryTree::preorder(TreeNode & tree_ptr,
                          FunctionType visit)
                          {
                              if(tree_ptr != nullptr)
                              {
                                preorder(tree_ptr->leftChildPtr,visit);
                                preorder(tree_ptr->rigthchildPtr,visit);
                              }
                          }


void BinaryTree::inorder(TreeNode & tree_ptr,
                         FunctionType visit)
                         {
                             if(tree_ptr != nullptr)
                             {
                                 inorder(tree_ptr->leftChildPtr,FunctionType visit)
                                 visit(tree_ptr->nodes_data);
                                 inorder(tree_ptr->rigthChildPtr,FunctionType visit); 
                             }
                         }

void BinaryTree::postorder(TreeNode & tree_ptr
                           FunctionType visit)
                           {
                               if(tree_ptr != nullptr)
                               {
                                   postorder(tree_ptr->leftChildPtr,visit);
                                   postorder(tree_ptr->rigthChildPtr,visit);
                                   visit(tree_ptr->nodes_data);
                               }
                           }