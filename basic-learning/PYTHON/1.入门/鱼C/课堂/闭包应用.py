origin = (0, 0)  # 原点
legal_x = [-100, 100]  # x轴的移动范围
legal_y = [-100, 100]  # y轴的移动范围


def create(pos_x=0, pos_y=0):
    # 初始化位于原点为主
    def moving(direction, step):
        # direction参数设置方向，1为向右（向上），-1为向左（向下），0为不移动
        # step参数设置移动的距离
        nonlocal pos_x, pos_y
        new_x = pos_x + direction[0] * step
        new_y = pos_y + direction[1] * step
        # 检查移动后是否超出x轴边界
        if new_x < legal_x[0]:
            pos_x = legal_x[0] - (new_x - legal_x[0])
        elif new_x > legal_x[1]:
            pos_x = legal_x[1] - (new_x - legal_x[1])
        else:
            pos_x = new_x
        # 检查移动后是否超出y轴边界
        if new_y < legal_y[0]:
            pos_y = legal_y[0] - (new_y - legal_y[0])
        elif new_y > legal_y[1]:
            pos_y = legal_y[1] - (new_y - legal_y[1])
        else:
            pos_y = new_y
        return pos_x, pos_y

    return moving


move = create()
print('向右移动10步后，位置是：', move([1, 0], 10))
print('向上移动130步后，位置是：', move([0, 1], 130))
print('向左移动10步后，位置是：', move([-1, 0], 10))
