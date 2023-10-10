/**
 * @brief 顺序存储只适合用来存完全二叉树
 * 其他的二叉树不可以使用顺序存储
 *
 */
#define MaxSize 100
struct TreeNode
{
    int value;    // 节点中的数据元素
    bool isEmpty; // 结点是否为空
};
// 这是一个长度为MaxSize的数组t,
// 按照从上到下从左到右的顺序依次存储完全二叉树中的各个节点
TreeNode t[MaxSize];
void test(TreeNode t[]);
/**
 * @brief 几个重要常考基本操作
 * i的左孩子--------2i
 * i的右孩子--------2i+1
 * i的父亲节点-------[i/2]向下取整
 * i所在的层次-------[log(n+1)]或[logn]+1
 * 判断i是否有左孩子--2i<=n
 * 判断i是否有右孩子--2i+1<=n
 * 判断i是否是叶子/分支结点？-i>[n/2]
 */
