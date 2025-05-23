const std = @import("std");

pub fn main() !void {
    const num:i32 = 35;
    var num2:u8 = undefined;
    num2 = 20;
    std.debug.print("num = {},num2 = {}\n",.{num,num2});
}
