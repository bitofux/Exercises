const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const zero: u8 = 0;
    const one: u8 = 1;
    const two: u8 = 2;
    const two_fifty: u8 = 250;

    //加减乘除模
    var result: u8 = zero + two - one * two / one % 2;
    print("result: {}\n,{any}", .{ result, @TypeOf(result) });

    //加减乘可能会导致溢出
    result = two_fifty + two; //没问题 252

    // result = two_fifty * two;// 500是超过255的 数据溢出

}
