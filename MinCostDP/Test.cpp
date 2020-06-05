#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 5//每种商品的最大数量
#define B 5//最大商品种类数
#define S 99//最大的优惠组合数
#define C 999//最大的编号 

//*B 0-5种商品
//*K 0-5每种商品数量
//*C 1-999商品编号
//*P 1-999商品正常单价
//*S 0-99 优惠组合
//*定义五维数组 cost(a,b,c,d,e)表示购买商品 a b c d e 组合的最少花费

int cost[N + 1][N + 1][N + 1][N + 1][N + 1] = { 0 };//cost(a,b,c,d,e)表示购买商品 a b c d e 组合的最少花费.从1开始
int offer[S][B + 1];//优惠组合信息
//offer[Si][Bj]  Si组合中的Bj(从1开始)类商品的数量 offer[1..S][0]存储这种组合的花费

struct Purch
{
    int code;//编号
    int quatity;//要购买的数量
    int price;//单价
}purch[B]; //定义购买物品信息数组

int product[B] = { 0  };//存储当前已购买的商品数量
int num[C] = { -1  };//code编号的商品对应的在purch数组中的index
int b;//实际购买的商品种类
int s;//实际的优惠组合数

//初始化数据
void init()
{
    //置0初始化
    for (int i = 0; i < N; ++i)
    {
        purch[i].code = -1;
        purch[i].price = 0;
        purch[i].quatity = 0;
    }
    for (int i = 0; i < S; ++i)
        for (int j = 1; j <= B; ++j)
        {
            offer[i][j] = 0;
        }

    cout << "输入购买商品种类、商品编码、购买数量、商品单价：" << endl;
    cin >> b;//实际商品种类
    for (int i = 0; i < b; ++i)
    {
        cin >> purch[i].code >> purch[i].quatity >> purch[i].price;//商品编码 数量 单价
        num[purch[i].code] = i;
    }

    cout << "输入优惠组合数、优惠组合中所购商品种类数、商品编码、购买商品数量、优惠组合价格：" << endl;
    cin >> s;//实际组合数
    for (int i = 0; i < s; ++i)
    {
        int pairs;//组合中的商品数
        cin >> pairs;
        for (int j = 0; j < pairs; ++j)
        {
            int c;//商品编号
            int n;//组合i中c编号商品的数量
            cin >> c >> n;
            offer[i][num[c] + 1] = n;
        }
        // offer[0][1] = 3;
        // offer[1][1] = 1 , offer[1][2] = 2;
        cin >> offer[i][0];//组合的花费
        // offer[0][0] = 5;
        // offer[1][0] = 10;
    }
}

//输出结果
void printResult()
{
    int mincost = cost[purch[0].quatity][purch[1].quatity][purch[2].quatity]
        [purch[3].quatity][purch[4].quatity];
    cout << "MinCost=" << mincost << endl;
}

//最小花费子问题求解
void minCost()
{
    int mincost = 0;

    int quatity1;//已经购买的第一种商品的数量
    int quatity2;//已经购买的第二种商品的数量
    int quatity3;//已经购买的第三种商品的数量
    int quatity4;//已经购买的第四种商品的数量
    int quatity5;//已经购买的第五种商品的数量

    for (int i = 0; i < b; ++i)
    {
        mincost += product[i] * purch[i].price;//将最小花费初始为没有优惠策略的花费
    }

    //对s种优惠政策依次讨论
    for (int j = 0; j < s; ++j)
    {
        quatity1 = product[0] - offer[j][1];//第一种商品扣除当前优惠组合下的购买量的其它购买量
        quatity2 = product[1] - offer[j][2];//第二种商品扣除当前优惠组合下的购买量的其它购买量
        quatity3 = product[2] - offer[j][3];//第三种商品扣除当前优惠组合下的购买量的其它购买量
        quatity4 = product[3] - offer[j][4];//第四种商品扣除当前优惠组合下的购买量的其它购买量
        quatity5 = product[4] - offer[j][5];//第五种商品扣除当前优惠组合下的购买量的其它购买量

        //在当前优惠组合下，购买的商品的总花费比没有优惠政策的少
        if (quatity1 >= 0 && quatity2 >= 0 && quatity3 >= 0 && quatity4 >= 0 && quatity5 >= 0
                && cost[quatity1][quatity2][quatity3][quatity4][quatity5] + offer[j][0] < mincost)
            //购买组合前的总花费，加上这种组合的花费
            mincost = cost[quatity1][quatity2][quatity3][quatity4][quatity5] + offer[j][0];
    }

    cost[product[0]][product[1]][product[2]][product[3]][product[4]] = mincost;//子问题最优组合花费
}

void combination(int i)//i类商品
{
    //确定一个子问题，计算一次当前最小花费
    if (i >= b)
    { 
        minCost();
        return; 
    }

    for (int j = 0; j <= purch[i].quatity; ++j)// 0 0， 0 1， 1 0， 1 1， 1 2 ，2 0 ，2 1，2 2;
    {
        product[i] = j;
        combination(i + 1);
    }
    // product[0] = 0, product[1] = 0, mincost = 0
    // product[1] = 1, mincost = 5
    // product[1] = 2, mincost = 10

    // product[0] = 1, product[1] = 0, mincost = 2
    // product[1] = 1, mincost = 5 + 2 = 7
    // product[1] = 2, mincost = 10(优惠价格 2个花瓶 + 1个花)-> cost = 12

    // product[0] = 2, product[1] = 0, mincost = 4
    // product[1] = 1, mincost = 9
    // product[1] = 2, mincost = 12(优惠价格 2个花瓶 + 2个花)-> cost = 14

    // product[0] = 3, product[1] = 0, mincost = 5(优惠价格 3个花)-> cost = 6
    // product[1] = 1, mincost = 10(优惠价格 1个花瓶 + 3个花)-> cost = 11
    // product[1] = 2, mincost = 14(优惠价格 2个花瓶 + 3个花)-> cost = 16
    
    //第一类商品需要购买数量为3，第二类商品需要购买数量为2，这段代码将会从最小的组合开始分析子问题的最优解，
    //  //递归的过程依次为（0，0）—>（0，1）—>（0，2）—>（1，0）—>（1，1）—>（1，2）—>（2，0）—>（2，1）—>
    //      //              （2，2）—>（3，0）—>（3，1）—>（3，2)，这就是上面提到的自底向上求解问题
}

//步骤一
//设cost（a, b, c, d, e）表示购买商品组合（a, b, c, d, e）需要的最少费用，A[k], B[k], C[k], D[k], E[k]
//表示第k种优惠方案的商品组合。offer(m)是第m种优惠方案的价格。如果cost(a, b, c, d, e)使用了第m种优惠方案，则
//找出最优子问题的递归表达式： 
//cost(a, b, c, d, e) = cost(a - A[m], b - B[m], c - C[m], d - D[m], e - E[m]) + offer(m)

//combination函数用来递归调用minCost函数
//步骤二
//实现从最小规模的子问题逐步扩大到原问题（自底向上）
//步骤三
//利用子问题的最优值来得到问题的最优解。

//测试用例
// 编号7代表花，编号8代表花瓶
//购买商品数据
// 种类:2
// 编号:7 数量:3 单价:2
// 编号:8 数量:2 单价:5
//优惠组合
// 组合数:2
// 组合中商品种类:1 编号:7 数量:3 优惠价:5
// 组合中商品种类:2 编号:7 数量:1 编号:8 数量:2 优惠价:10
int main()
{
    init();
    combination(0);//从第0种商品开始
    printResult();
    return 0;
}
