#ifndef AVLTREE_H
#define AVLTREE_H

#define SUCCESS 1
#define FALSE   0
typedef int BiTElemType;
#define Status int
typedef struct BiTNode
{
    BiTElemType value;//节点数据
    int bf;////节点平衡因子
    struct BiTNode* left, * right;
}BiTNode, *BiTree;


/**
 * @brief 以p为根进行右旋操作
 *
 * @param p
 */
void R_Rotate(BiTree* p);

/**
 * @brief 以p为根进行左旋操作
 *
 * @param p
 */
void L_Rotate(BiTree* p);

/**
 * @brief 对p节点为根的二叉树作左平衡旋转
 *
 * @param p
 */
void LeftBalance(BiTree* p);

/**
 * @brief 对p节点为根的二叉树作右衡旋转
 *
 * @param p
 */
void RightBalance(BiTree* p);


/**
 * @brief 插入新节点, 同时平衡树
 *
 * @param p
 * @param data
 * @param taller
 * @return is SUCCESS or FALSE
 */
Status InsertAVL(BiTree* p, BiTElemType data, int* taller);

/**
 * @brief 删除节点, 同时平衡树
 *
 * @param p  根节点
 * @param data 删除数据
 * @param flag 判断是否变矮  1表变矮1层  0表未层数
 */
Status deleteAVL(BiTree* bt, BiTElemType data, int* flag);


Status AVL_preorderR(BiTree* bt);//先序遍历
Status AVL_inorderR(BiTree* bt);//中序遍历
Status AVL_postorderR(BiTree* bt);//后序遍历


void AVLdelete(BiTree* bt);//删除

void AVLinsert(BiTree* bt);//增加

















#endif
