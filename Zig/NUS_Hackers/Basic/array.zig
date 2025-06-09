const std = @import("std")  ;
const print = std.debug.print;

pub fn main () !void {
    
    //固定大小的数组
    var my_int_array = [5]i32{1,2,3,4,5};
    //使用[]访问数组元素并修改数组元素的值
    my_int_array[0] = 2;
    print("my_int_array[0]: {any}\n",.{my_int_array[0]});
    print("my_int_array: {any}\n",.{my_int_array});

    //可以使用_字符让编译器推断数组的大小
    const my_other_array = [_]u32{1,2,3,4,5};
    //len是数组的唯一字段
    print("len of my_other_array: {}\n",.{my_other_array.len});

    //数组可以有哨兵值:好比C中的字符串中有一个'\0'字符结尾
    const my_int_sentinel_array  = [5:2]u32{1,2,3,4,5};
    //上述的数组以数字2为结尾数字
    print("my_int_sentinel_array: {any}\n",.{my_int_sentinel_array});
    print("my_int_sentinel_array.len: {}\n",.{my_int_sentinel_array.len});
    //@bitCast忘记这是什么类型,只看原始的位 就像是一副x光眼镜，让我们能够透过高级数据类型的表象，直接看到底层的位模式，然后用不同的眼镜来重新解释这些位。
    //@as把这块内存重新解释为特定类型
    //1. @bitCast = 拆掉包装盒的标签 类型擦除
    //   有一个标着"哨兵数组"的盒子
    //   @bitCast撕掉标签,现在只是无标签的盒子
    //   盒子里的东西是不变的,只是失去了身份
    //2. @as = 贴上新标签 类型赋予
    //   @as给他贴上普通数组的新标签
    //   现在可以按照新标签的方式使用盒子里的东西
    print("my_int_sentinel_array (with sentinel): {any}\n",.{@as([6]u32,@bitCast(my_int_sentinel_array))});
}
