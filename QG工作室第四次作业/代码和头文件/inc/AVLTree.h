#ifndef AVLTREE_H
#define AVLTREE_H

#define SUCCESS 1
#define FALSE   0
typedef int BiTElemType;
#define Status int
typedef struct BiTNode
{
    BiTElemType value;//�ڵ�����
    int bf;////�ڵ�ƽ������
    struct BiTNode* left, * right;
}BiTNode, *BiTree;


/**
 * @brief ��pΪ��������������
 *
 * @param p
 */
void R_Rotate(BiTree* p);

/**
 * @brief ��pΪ��������������
 *
 * @param p
 */
void L_Rotate(BiTree* p);

/**
 * @brief ��p�ڵ�Ϊ���Ķ���������ƽ����ת
 *
 * @param p
 */
void LeftBalance(BiTree* p);

/**
 * @brief ��p�ڵ�Ϊ���Ķ��������Һ���ת
 *
 * @param p
 */
void RightBalance(BiTree* p);


/**
 * @brief �����½ڵ�, ͬʱƽ����
 *
 * @param p
 * @param data
 * @param taller
 * @return is SUCCESS or FALSE
 */
Status InsertAVL(BiTree* p, BiTElemType data, int* taller);

/**
 * @brief ɾ���ڵ�, ͬʱƽ����
 *
 * @param p  ���ڵ�
 * @param data ɾ������
 * @param flag �ж��Ƿ�䰫  1��䰫1��  0��δ����
 */
Status deleteAVL(BiTree* bt, BiTElemType data, int* flag);


Status AVL_preorderR(BiTree* bt);//�������
Status AVL_inorderR(BiTree* bt);//�������
Status AVL_postorderR(BiTree* bt);//�������


void AVLdelete(BiTree* bt);//ɾ��

void AVLinsert(BiTree* bt);//����

















#endif
