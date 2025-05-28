const std = @import("std");

pub fn main() !void{
    //一维数组
    const a:[4]u8 = .{1,2,3,4};
    std.debug.print("a: {any}\n",.{a});
    const b:[4]u8 = .{0} ** 4;
    std.debug.print("b: {any}\n",.{b});
    const c = a ++ b;
    std.debug.print("c: {any}\n",.{c});
    //二维数组
    const d:[2][4]u8 = .{.{1,2,3,4},.{5,6,7,8}};
    std.debug.print("d: {any}\n",.{d});
    const e:[2][3]u32 = .{.{0} ** 3} ** 2;
    std.debug.print("e: {any}\n",.{e});
}
