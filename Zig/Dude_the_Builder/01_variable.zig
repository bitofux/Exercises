const std = @import("std");

// 全局常量
const global_const: u32 = 26;

// 全局变量
var global_var: u32 = 26;

fn printInfo(name: []const u8, x: anytype) void {
    std.debug.print("{s:>10} {any:^10}\t{}\n", .{ name, x, @TypeOf(x) });
}

pub fn main() !void {
    //输出的一些标签
    std.debug.print("{s:>10} {s:^10}\t{s}\n", .{ "name", "value", "type" });
    std.debug.print("{s:>10} {s:^10}\t{s}\n", .{ "----", "-----", "----" });

    //const定义了一个不可以修改的变量
    //对const定义的变量进行初始化,初始化表达式必须是编译时已知的
    //且const定义的变量本身也是编译时已知,如果没有给类型那么会在
    //编译时推断这个类型,如果初始化表达式的值为整数,那么这个类型
    //为comptime_int
    const a_const = 1;
    // a_const += 1; 不可以修改
    printInfo("a_const", a_const);

    //使用var定义的变量必须拥有一个类型或者是被comptime修饰
    // var a_var = 23;//error
    // 被comptime修饰,那么b_var的类型可以根据初始化表达式的值进行推断
    // 在这里b_var的类型是comptime_int
    comptime var b_var = 23;
    b_var += 1;
    printInfo("b_var", b_var);
    var c_var: u8 = 26;
    c_var = 3;
    printInfo("c_var", c_var);

    //使用const和var定义的变量都必须拥有一个初始化值
    //以下两个行为是错误的
    // const b_const;
    // var d_var: u8;

    //如果你想定义一个变量且想在后面的代码中再使用
    //你可以使用undefined对变量进行初始化
    var e_var: u8 = undefined;
    printInfo("e_var", e_var);
    e_var = 3;
    printInfo("e_var", e_var);

    //值得注意的是,zig是很忌讳定义的局部变量而不去使用它
    //使用const定义的变量不着急使用它的话,可以将其赋值给_
    const c_const = 26;
    // printInfo("c_const", c_const);
    _ = c_const;

    //而使用var定义的变量在zig中,如果你在定义它之后不去修改
    //它的值的话,那么编译器认为这也是一种错误,要么你使用const去定义它
    //这比不去使用它严重的多.因为当你去修改它了就代表已经使用它了
    var f_var: u8 = 26;
    f_var += 1;
    // printInfo("f_var", f_var);
}
