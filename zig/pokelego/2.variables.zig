//!
//!  PROJECT : EXERCISES
//!  FILE    : 2.variables.zig
//!  AUTHOR  : bitofux
//!  DATE    : 2026-06-02
//!  BRIEF   : 变量与常量

const std = @import("std");

pub fn main() void {
    // 定义常量 const
    const const_var_integer = 12000_000; // 默认编译时类型是comptime_int
    const const_var_float = 3.14; // 默认编译时类型是comptime_float
    const const_var_char = 'a'; // 默认编译时类型也是comptime_int
    const const_var_bool = true; // 默认编译时类型是bool
    const const_var_string = "bitofux"; // 默认编译时类型是*const [7:0]u8

    std.debug.print("const_var_integer type is {}\n", .{@TypeOf(const_var_integer)});
    std.debug.print("const_var_float type is {}\n", .{@TypeOf(const_var_float)});
    std.debug.print("const_var_char type is {}\n", .{@TypeOf(const_var_char)});
    std.debug.print("const_var_bool type is {}\n", .{@TypeOf(const_var_bool)});
    std.debug.print("const_var_string type is {}\n", .{@TypeOf(const_var_string)});

    // 定义变量 var must provide explicit fixed-size number type and must modify it after defining
    var var_integer: u8 = 12;
    var_integer = 20;

    var var_float: f16 = 3.14;
    var_float = 20.2;

    var var_char: u8 = 'a';
    var_char = 'b';

    var var_bool: bool = false;
    var_bool = true;

    var var_string: *const [7:0]u8 = "bitofux";
    var_string = "wangshu";

    std.debug.print("var_integer: {}\n", .{var_integer});

    // 编译时计算
    comptime var sum = 0; // 推断类型 comptime_int

    comptime {
        var i: u8 = 0;
        while (i <= 10) : (i += 1) {
            sum += i;
        }
    }

    std.debug.print("sum: {d}", .{sum});
}
